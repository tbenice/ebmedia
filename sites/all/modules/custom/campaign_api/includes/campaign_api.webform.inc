<?php
/**
 * @file campaign_api.webform.inc
 * Provides webform elements for cool keys.
 */

/**
 * Webform component defaults.
 */
function _webform_defaults_coolkeyentry() {
  $defaults = array(
    'name' => '',
    'form_key' => NULL,
    'mandatory' => 1,
    'pid' => 0,
    'weight' => 0,
    'extra' => array(),
  );
}

/**
 * Webform component edit form.
 */
function _webform_edit_coolkeyentry($component) {
  $form = array();
  return $form;
}

/**
 * Webform component form element.
 */
function _webform_render_coolkeyentry($component, $value, $filter=TRUE) {
  $form = array();
  $form['coolkeyentry'] = array(
    '#type' => 'textfield',
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#required' => $component['mandatory'],
    '#weight' => $component['weight'],
    '#description'   => (isset($component['extra']['description'])) ? ($filter ? _webform_filter_descriptions($component['extra']['description']) : $component['extra']['description']) : '',
    '#default_value' => $filter ? _webform_filter_values($component['value']) : $component['value'],
    '#prefix' => '<div class="webform-component-coolkeyentry" id="webform-component-' . $component['form_key'] . '">',
    '#suffix' => '</div>',
    '#element_validate' => array('coolkeyentry_validate'),
    '#elevate' => $component['form_key'],
  );
  return $form;
}

/**
 * Element validate for component
 */
function coolkeyentry_validate($element, &$form_state, $form) {
  $ck_key = $form_state['values']['submitted'][$element['#elevate']]['coolkeyentry'];
  $key_query = db_select('cool_keys_key_codes');
  $key_query->fields('cool_keys_key_codes', array('kgid', 'key_code','max_uses','num_used'));
  $key_query->condition('key_code', $ck_key);

  $key_result = $key_query->execute()->fetchAssoc();
  
  $ck_group = $key_result['kgid'];
  
  $ck_group_query = db_select('cool_keys_key_groups');
  $ck_group_query->fields('cool_keys_key_groups', array('kgid', 'active','set_unlimited_keys','set_unlimited_uses'));
  $ck_group_query->condition('kgid', $ck_group);
  
  $ck_group_result = $ck_group_query->execute()->fetchAssoc();
  
  if($ck_group_result['active'] != 1) {
    form_error($element, t('Your key code is not active.'));
    return FALSE;
  }
  
  if($ck_key != $key_result['key_code']) {
    form_error($element, t('You did not enter a valid code.'));
    return FALSE;
  }
  
  if(($ck_group_result['set_unlimited_uses'] != 1) && ($key_result['num_used'] >= $key_result['max_uses'])) {
    form_error($element, t('Your key code has already been used.'));
    return FALSE;
  }
}

/**
 * Implements hook_webform_submission_presave().
 */
function campaign_api_webform_submission_insert($node, $submission) {
  // Find all coolkeyentry values and fire off rule events.
  foreach($submission->data as $key => $value) {
    if (isset($value['value']['coolkeyentry'])) {
      campaign_api_redeem_key($value['value']['coolkeyentry'], $submission);
    }
  }
}