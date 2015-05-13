<?php
/**
 * @file entity_pager.forms.inc
 * Form related code for the entity pager module.
 */

/**
 * Defines form elements for any node pager block config
 * form
 * @param array $form_state
 *   Form State array Passed from the form alter function
 * @param string $delta
 *   the delta of the block to add elements to
 */
function entity_pager_block_config_elements($form_state, $delta = 'entity_pager_1') {
  //capture the ajax-ified values either from form_state if set (ajax call) or from the variable setting
  $use_js = (isset($form_state['values'][$delta . '_use_js'])) ?  $form_state['values'][$delta . '_use_js'] : variable_get($delta . '_use_js', 0);

  $form['entity_pager_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node Pager Settings'),
    '#weight' => -100,
    '#prefix' => '<div id=entity-pager-settings>',
    '#suffix' => '</div>',
  );
  $views_list = views_get_all_views();
  foreach($views_list as $name => $obj) {
    $views_options[$name] = $name;
  }
  $form['entity_pager_settings'][$delta . '_entity_pager_view'] = array(
    '#type' => 'select',
    '#options' => $views_options,
    '#title' => t('View'),
    '#description' => t('Choose the view that will supply the entities for the pager.'),
    '#default_value' => variable_get($delta . '_entity_pager_view'),
  );

  $entities = entity_get_info();

  foreach($entities as $name => $info) {
    $entity_options[$name] = $name;
  }
  $form['entity_pager_settings'][$delta . '_entity_pager_entity_type'] = array(
    '#type' => 'select',
    '#options' => $entity_options,
    '#title' => t('Entity Type'),
    '#description' => t('Select the type of entity that will be paged by this pager.'),
    '#options' => $entity_options,
    '#default_value' => variable_get($delta . '_entity_pager_entity_type'),
  );
  $form['entity_pager_settings'][$delta . '_entity_id_arg'] = array(
    '#type' => 'textfield',
    '#title' => t('Entity ID Arg'),
    '#description' => t('Provide the drupal url arguement that supplies the id for each entity.'),
    '#default_value' => variable_get($delta . '_entity_id_arg', 1),
  );
  $form['entity_pager_settings'][$delta . '_pager_text_custom'] = array(
    '#type' => 'checkbox',
    '#title' => t('Custom Pager Text'),
    '#description' => t('If checked, you can specify the text that will be used for previous and next pager links. Otherwise the first field in the view will be used.'),
    '#default_value' => variable_get($delta . '_pager_text_custom', 0),
  );
  $form['entity_pager_settings'][$delta . '_pager_text_previous'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous link text'),
    '#description' => t('Enter the text that will be used for the "previous" pager link text'),
    '#default_value' => variable_get($delta . '_pager_text_previous', ''),
    '#states' => array(
      'invisible' => array(
        'input:[name="' . $delta . '_pager_text_custom"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['entity_pager_settings'][$delta . '_pager_text_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous link text'),
    '#description' => t('Enter the text that will be used for the "next" pager link text'),
    '#default_value' => variable_get($delta . '_pager_text_next', ''),
    '#states' => array(
      'invisible' => array(
        'input:[name="' . $delta . '_pager_text_custom"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['entity_pager_settings'][$delta . '_use_js'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Javascript'),
    '#description' => t('Check this box checked to use the scroll function javascript to show/hide the pager'),
    '#default_value' => $use_js,
  );
  $form['entity_pager_settings'][$delta . '_scroll_percent'] = array(
    '#type' => 'select',
    '#title' => t('Scroll %'),
    '#description' => t('Percent of page at which scroll triggers the pager to appear'),
    '#field_suffix' => '%',
    '#options' => array(0=>'0', 10=>'10', 20=>'20', 30=>'30', 40=>'40', 50=>'50', 60=>'60', 70=>'70', 80=>'80', 90=>'90', 100=>'100'),
    '#default_value' => variable_get($delta . '_scroll_percent', 50),
    '#states' => array(
      'invisible' => array(
        ':input[name="' . $delta . '_use_js"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['entity_pager_settings'][$delta . '_use_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use link'),
    '#description' => t('If checked the pager will include a back to river link'),
    '#default_value' => variable_get($delta . '_use_link', 0),
  );
  $form['entity_pager_settings'][$delta . '_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#description' => t('Enter the text that will be shown for the back to river link'),
    '#default_value' => variable_get($delta . '_link_text', ''),
    '#states' => array(
      'invisible' => array(
        ':input[name="' . $delta . '_use_link"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['entity_pager_settings'][$delta . '_link_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Link path'),
    '#description' => t('Enter the path that will be used for the back to river link'),
    '#default_value' => variable_get($delta . '_link_path', ''),
    '#states' => array(
      'invisible' => array(
        ':input[name="' . $delta . '_use_link"]' => array('checked' => FALSE),
      ),
    ),
  );
  return $form;
}
