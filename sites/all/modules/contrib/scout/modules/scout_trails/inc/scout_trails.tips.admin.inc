<?php
/**
 * @file
 * scout_trails.tips.admin.inc
 */

/************************************************************************************
 *
 * Scout Tips  (tip types below)
 *
 ************************************************************************************
 */

function scout_tips_form_list($form, $form_state) {
	//dpm($form_state['values']['trailtip_edit'],'$form_state[values][trailtip_edit] - scout_tips_form_list()');
	return $form['trail']['trailtips']['hidden'];
}

/**
 * Callback for the cancel link on scout tip forms.
 */
function scout_tip_form_cancel() {
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;
}

/**
 * Scout Tip delete form.
 */
function scout_tip_delete_form($form, &$form_state, $scout_tip) {
  $form_state['scout_tip'] = $scout_tip;
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' .  $scout_tip->tip_id . '/edit';

  return confirm_form($form,
    t('Are you sure you want to delete the scout tip %title?', array('%title' => entity_label('scout_tip', $scout_tip))),
    $form_state['redirect'],
    t('This action cannot be undone.'),
    t('Confirm Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for scout_tip_delete_form
 */
function scout_tip_delete_form_submit($form, &$form_state) {
  $scout_tip = $form_state['scout_tip'];
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  scout_tip_delete($scout_tip);

  drupal_set_message(t('The scout tip %name has been deleted.', array('%name' => $scout_tip->title)));
  watchdog('scout_trails', 'Deleted scout tip %name.', array('%name' =>$scout_tip->title));
}

/**
 * Add new Scout Tip page callback.
 */
function scout_tip_form_add($type) {
  $tip_type = scout_tip_types($type);

  $scout_tip = entity_create('scout_tip', array('type' => $type));
  drupal_set_title(t('Create @name', array('@name' => entity_label('scout_tip_type', $tip_type))));
  $output = drupal_get_form('scout_trail_form', $scout_tip);

  return $output;
}

/**
 * The Scout Tip Form.
 */
function scout_tip_form($form, &$form_state, $scout_tip = NULL) {
  //dpm($scout_tip,'$scout_tip scout_tip_form ');
  global $user;

  $form['scout_tip'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scout - Create a Scout Tip'),
    '#description' => t('Scout tips consist of text content, page location and theming info.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['scout_tip']['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Scout Tip Label'),
    '#description' => t('Displays as title in a Scout Tip.'),
    '#default_value' => $scout_tip->title,
  );

  $form['scout_tip']['tag'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Tag'),
    '#description' => t('Optional tag for organizing / grouping tips in admin view.'),
    '#default_value' => $scout_tip->tag,
    '#autocomplete_path' => 'admin/content/scout-trails/scout-tips/ajax/tag',
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit']['scout_tip'] = array(
    '#type' => 'submit',
    '#value' => t('Save Scout Tip'),
  );

  $form['actions']['cancel'] = array(
  '#type' => 'submit',
  '#value' => t('Cancel'),
  '#submit' => array('scout_tip_form_cancel'),
  );

  // Attach this Entity type's fields to the Form
  $form_state['scout_tip'] = $scout_tip;
  field_attach_form('scout_tip', $scout_tip, $form, $form_state);

  // Show Delete button if we edit group.
  $tip_id = entity_id('scout_tip', $scout_tip);
  if (!empty($tip_id) && scout_trails_access('edit', $scout_tip)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('scout_tip_form_submit_delete'),
    );
  }
//  dsm($form);
  return $form;
}

/**
 * Submit handler for creating/editing scout_tip.
 */
function scout_tip_form_submit(&$form, &$form_state) {
  $scout_tip = $form_state['scout_tip'];
  $scout_tip->title = $form_state['values']['title'];
  $scout_tip->tag = $form_state['values']['tag'];
  $scout_tip->changed = REQUEST_TIME;
  //dpm($scout_tip, '$scout_tip scout_tip_form_submit');

  // Determine if new tip or update
  $update = TRUE ? (isset($scout_tip->tip_id)) : FALSE;

  // Save and go back.
  field_attach_submit('scout_tip', $scout_tip, $form, $form_state);
  scout_tip_save($scout_tip);

  // Redirect user back to list of Scout Tips.
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect;

  // Log and message
  If (!$update) {
	  watchdog('scout_tip', 'Created new scout tip "%title".', array('%title' => $scout_tip->title));
	  drupal_set_message(t('Scout Tip "%title" has been created.', array('%title' => $scout_tip->title)));
  }
  else {
    watchdog('scout_tip', 'Updated scout tip "%title" (%id).', array('%title' => $scout_tip->title,'%id' => $scout_tip->tip_id));
    drupal_set_message(t('Scout Tip "%title" (%id) has been updated.', array('%title' => $scout_tip->title,'%id' => $scout_tip->tip_id)));
  }
}

/**
 * Submit handler for deleting scout_tip.
 */

function scout_tip_form_submit_delete(&$form, &$form_state) {
  $scout_tip = $form_state['scout_tip']->tip_id;
  $redirect = entity_get_info('scout_tip');
  $redirect = $redirect['admin ui']['path'];
  $form_state['redirect'] = $redirect . '/' . $scout_tip . '/delete';
}

/**
 * Submit handler for Scout Trails & Scout Tips.
 */
// IMPORTANT!  This is located in scout_trails.trails.admin.inc


/************************************************************************************
 *
 * Scout Tip Types
 *
 ************************************************************************************
 */


/**
 * Generates the scout tip type editing form.
 */
function scout_tip_type_form($form, &$form_state, $tip_type, $op = 'edit') {
  // insert module info
  $tip_type->module = 'scout_trails';

  //build default type name if this type is cloned
  if ($op == 'clone') {
    $tip_type->label .= ' (cloned)';
    $tip_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $tip_type->label,
    '#description' => t('The human-readable name of this tip type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($tip_type->type) ? $tip_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $tip_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'scout_tip_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this scout tip type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($tip_type->description) ? $tip_type->description : '',
    '#description' => t('Description about the scout tip type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save tip type'),
    '#weight' => 40,
  );

  if (!$tip_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete tip type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('scout_tip_type_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing scout_tip_type.
 */
function scout_tip_type_form_submit(&$form, &$form_state) {
  $tip_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  scout_tip_type_save($tip_type);

  // Redirect user back to list of task types.
  $form_state['redirect'] = 'admin/structure/scout/scout-tip-types/';
}

function scout_tip_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/scout/scout-tip-types/' . $form_state['scout_tip_type']->type . '/delete';
}

/**
 * Scout Tip type delete form.
 */
function scout_tip_type_form_delete_confirm($form, &$form_state, $tip_type) {
  $form_state['scout_tip_type'] = $tip_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['scout_tip_type_id'] = array('#type' => 'value', '#value' => entity_id('scout_tip_type' ,$tip_type));
  return confirm_form($form,
    t('Are you sure you want to delete scout tip type %title?', array('%title' => entity_label('scout_tip_type', $tip_type))),
    'scout_tip/' . entity_id('scout_tip_type' ,$tip_type),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Scout Tip type delete form submit handler.
 */
function scout_tip_type_form_delete_confirm_submit($form, &$form_state) {
  $tip_type = $form_state['scout_tip_type'];
  scout_tip_type_delete($tip_type);

  watchdog('scout_tip_type', '@type: deleted %title.', array('@type' => $tip_type->type, '%title' => $tip_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $tip_type->type, '%title' => $tip_type->label)));

  $form_state['redirect'] = 'admin/structure/scout/scout-tip-types/';
}

/**
 * Page callback for views tag autocomplete
 */
function scout_tips_ui_autocomplete_tag($string = '') {
  $matches = array();
  $views = views_get_view_result('scout_tips','tags','all');
  foreach ($views as $key=>$value) {
    if (!empty($value->scout_tip_tag) && strpos($value->scout_tip_tag, $string) === 0) {
      $matches[$value->scout_tip_tag] = check_plain($value->scout_tip_tag);
      if (count($matches) >= 10) {
        break;
      }
    }
  }
  drupal_json_output($matches);
}
