<?php
/**
 * @file contextual_messages.admin.inc
 * Admin form code for contextual messages module.
 */

/**
 * Main administration form for the module.
 *
 * @param array $form
 * @param array $form_state
 * @param string $op
 */
function contextual_messages_admin_form($form, &$form_state, $op = 'nodes', $object = null) {
  $object_form = (is_object($object));
  switch($op) {
    case 'nodes':
      if ($object_form) {
        $elements[$object->type] = array(
          'name' => $object->type,
          'title' => $object->name . ' Nodes',
        );
        $elements[$object->type]['children'][$object->type] = array(
          'name' => $object->type,
          'title' => $object->name . ' Nodes',
        );
      }
      else {
        $types = node_type_get_names();
        foreach($types as $type => $name) {
          $elements[$type] = array('name' => $type, 'title' => $name . ' Nodes', 'children' => array());
        }
      }
      break;
    case 'views':
      if ($object_form) {
        $elements[$object->name] = array(
          'name' => $object->name,
          'title' => $object->human_name,
        );
        foreach($object->display as $display_id => $display) {
          $elements[$object->name]['children'][$display_id] = array(
            'name' => $display_id,
            'title' => $display->display_title
          );
        }
      }
      else {
        $views = views_get_all_views();
        foreach($views as $id=>$view) {
          $elements[$id] = array(
            'name' => $id,
            'title' => $view->human_name,
          );
        }
      }
      $type = 'views';
      break;
    case 'blocks':
      if ($object_form) {
        $elements[$object->delta] = array(
          'name' => $object->delta,
          'title' => $object->info,
        );
        $elements[$object->delta]['children'][$object->delta] = array(
          'name' => $object->delta,
          'title' => $object->info
        );
      }
      else {
        $blocks = _contextual_messages_block_info_get();
        foreach($blocks as $delta => $info) {
          /**
           * for some reason, some block deltas
           * have array infos, which we will avoid.
           * Maybe we can support these blocks after
           * we understand why they are like that.
           */
          if(!(is_array($info['info']))) {
            $elements[$delta] = array('name' => $delta, 'title' => $info['info']);
          }
        }
      }
      $type = 'Blocks';
      break;
    case 'fields':
      if ($object_form) {
        $elements[$object->entity_type . '_' . $object->bundle_name] = array(
          'name' => $object->entity_type . '_' . $object->bundle_name,
          'title' => $object->entity_type . ':' . $object->bundle_name,
        );
        $instances = field_info_instances($object->entity_type, $object->bundle_name);
        foreach($instances as $name => $info) {
          $elements[$object->entity_type . '_' . $object->bundle_name]['children'][$info['field_name']] =
            array('name' => $name, 'title' => $info['label']);
        }
      }
      else {
        $entities = field_info_instances();
        foreach($entities as $entity => $bundle) {
          foreach($bundle as $bundle_name => $instances) {
            $elements[$entity . '_' . $bundle_name] = array(
              'name' => $entity . '_' . $bundle_name,
              'title' => $entity . ':' . $bundle_name,
              'children' => array());
          }
        }
      }
      break;
  }
  //}
  // Get array of saved values
  $saved_values = variable_get('contextual_messages', array());
  // Operate on the object.
  if ($object_form) {
    // Get the element from the array of elements.
    $element = array_values($elements);
    $element = $element[0];
    foreach($element['children'] as $display_id => $child_element) {
      // Set the element name based on whether the child and parent
      // elements have the same name.
      $element_name = ($element['name'] == $child_element['name']) ?
        $child_element['name'] :
        $element['name'] . '_' . $child_element['name'];

      if(isset($form_state['values'])) {
        $element_collapsed = (!($form_state['values'][$op . '__' . $element_name . '__use_message'] == 1));
      }
      elseif(isset($saved_values[$op][$element_name])) {
        $element_collapsed = (!($saved_values[$op][$element_name]['use_message'] == 1));
      }
      else {
        $element_collapsed = true;
      }
      $form['contextual_messages_' . $op . '_' . $element['name']]['sub_element_' . $child_element['name']] = array(
        '#type' => 'fieldset',
        '#collapsible' => true,
        '#collapsed' => $element_collapsed,
        '#title' => t($child_element['title']),
      );
      $saved_value = (isset($saved_values[$op][$element_name])) ?
        $saved_values[$op][$element_name] :
        array('use_message' => 0, 'event' => 'click', 'message' => '');
      $form['contextual_messages_' . $op . '_' . $element['name']]['sub_element_' . $child_element['name']] +=
        contextual_messages_admin_form_element($form, $form_state, $op, $element_name, $saved_value);
    }
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
    );
  }
  // Select an object.
  else {
    foreach($elements as $id => $element) {
      $form['contextual_messages_' . $op . '_' . $element['name']] = array(
        '#type' => 'item',
        '#markup' => l($element['title'], 'admin/config/content/contextual-messages/' . $op . '/' . $element['name'],
          array('attributes' => array('title' => 'Manage contextual messages for the ' . $op . ' item : ' . $element['name']))),
        '#prefix' => '<div class="contextual-messages-admin-item">',
        '#suffix' => '</div>',
      );
    }
  }
  //dsm($form);
  return $form;
}

/**
 * Provides a form part.
 * Returns a form part comprising a text field for
 * entering the message to be shown and some options.
 *
 * @param array $form
 * @param array $form_state
 * @param string $op
 * @param string $element
 * @param unknown_type $saved_value
 */
function contextual_messages_admin_form_element($form, $form_state, $op, $element, $saved_value) {

  $use_message = isset($form_state['values'][$op . '__' . $element . '__use_message']) ?
    $form_state['values'][$op . '__' . $element . '__use_message'] :
    $saved_value['use_message'];

  $event = ($use_message == 1) ? (isset($form_state['values'][$op . '__' . $element . '__event']) ?
    $form_state['values'][$op . '__' . $element . '__event'] :
    (isset($saved_value['event']) ?
      $saved_value['event'] :
      'click')) :
    'click';

  $message = ($use_message == 1) ?
    (isset($form_state['values'][$op . '__' . $element . '__message']) ?
      $form_state['values'][$op . '__' . $element . '__message'] :
      (isset($saved_value['message']) ?
        $saved_value['message'] :
        '')) :
    '';

  $form_element[$op . '__' . $element . '__use_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add a contextual message to this block'),
    '#default_value' => $use_message,
  );

  $form_element[$op . '__' . $element . '__wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Values'),
    '#states' => array(
      'visible' => array(
        ':input[name="' . $op . '__' . $element . '__use_message"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form_element[$op . '__' . $element . '__wrapper'][$op . '__' . $element . '__event'] = array(
    '#type' => 'radios',
    '#title' => t('Message Trigger'),
    '#description' => t('Select which event will trigger the message to appear: "Click"=when the block container is clicked, "Hover"= when the mouse hovers over the block container, "Page-Load"=on loading a page that includes this block, when the block is in view'),
    '#options' => array('click' => 'Click', 'hover' => 'Hover', 'page-load' => 'Page Load'),
    '#default_value' => $event,
  );
  $form_element[$op . '__' . $element . '__wrapper'][$op . '__' . $element . '__message'] = array(
    '#type' => 'text_format',
    '#title' => t('Message'),
    '#description' => t('Write a message that will appear corresponding to this block'),
    '#format' => null,
    '#base_type' => 'textarea',
    '#default_value' => (!$message == '') ? $message['value'] : '',
    '#format' => (!$message == '') ? $message['format'] : null,
  );

  return $form_element;
}

function contextual_messages_admin_form_submit($form, $form_state) {
  $allowed = array('use_message', 'event', 'message');
  foreach($form_state['values'] as $name => $value) {
    $parts = explode('__', $name);
    $op = array_pop($parts);//the part of the element's data: use_message, event, message
    if(in_array($op, $allowed)) {
      $type = array_shift($parts);//the type of element: node, block, view, field
      $values[implode($parts)][$op] = $value;
    }
  }
  $messages = variable_get('contextual_messages', array());
  $messages[$type] = $values;
  variable_set('contextual_messages', $messages);
}
