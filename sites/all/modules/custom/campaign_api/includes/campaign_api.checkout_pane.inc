<?php
/**
 * @file
 * Supplies the checkout pane functionality.
 */

/**
 * Implements base_checkout_form().
 */
function campaign_api_checkout_pane_checkout_form($form, $form_state, $checkout_pane, $order) {
  // Allow to replace pane content with ajax calls.
  $pane_form = array(
    '#prefix' => '<div id="commerce-checkout-promo-codes-ajax-wrapper">',
    '#suffix' => '</div>',
  );
  $pane_form['key_code'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Enter Your Code'),
  );
  return $pane_form;
}

/**
 * Form validation for the promo code pane form.
 */
function campaign_api_checkout_pane_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  $ck_key = $form_state['values']['promo_code']['key_code'];
  if (empty($ck_key)) {
    $form_state['#ckcode'] = FALSE;
    return TRUE;
  }
  // If we're using the shortened code name then grab the
  // key code from variable and use that.
  $key_code = variable_get("promo_code_$ck_key", null);
  $key_code = (isset($key_code)) ? $key_code : $ck_key;
  $form_state['values']['promo_code']['key_code'] = $key_code;

  // Perform the key code check.
  $key_query = db_select('cool_keys_key_codes');
  $key_query->fields('cool_keys_key_codes', array('kgid', 'key_code','max_uses','num_used'));
  $key_query->condition('key_code', $key_code);

  $key_result = $key_query->execute()->fetchAssoc();

  $ck_group = $key_result['kgid'];

  $ck_group_query = db_select('cool_keys_key_groups');
  $ck_group_query->fields('cool_keys_key_groups', array('kgid', 'active','set_unlimited_keys','set_unlimited_uses'));
  $ck_group_query->condition('kgid', $ck_group);

  $ck_group_result = $ck_group_query->execute()->fetchAssoc();

  if($ck_group_result['active'] != 1) {
    form_set_error('campaign_api][key_code','Your key code is not active.');
    return FALSE;
  }
  if($key_code != $key_result['key_code']) {
    form_set_error('campaign_api][key_code','You did not enter a valid code.');
    return FALSE;
  }
  if($ck_group_result['set_unlimited_uses'] != 1) {
    if($key_result['num_used'] >= $key_result['max_uses']) {
      form_set_error('campaign_api][key_code','Your key code has already been used.');
      return FALSE;
    }
  }
  $form_state['#ckcode'] = TRUE;
  return TRUE;
}

/**
 * Form submit callback for the promo codes pane form.
 */
function campaign_api_checkout_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  if (!$form_state['#ckcode']) {
    return;
  }

  $ck_code = $form_state['values']['promo_code']['key_code'];
  
  $key_query = db_select('cool_keys_key_codes');
  $key_query->fields('cool_keys_key_codes', array('kgid', 'num_used', 'max_uses'));
  $key_query->condition('key_code', $ck_code);
  $key_result = $key_query->execute()->fetchAssoc();
  
  $ck_group = $key_result['kgid'];
  $ck_used = $key_result['num_used'];
  
  db_update('cool_keys_key_codes')
    ->expression('num_used', 'num_used+1')
    ->condition('key_code', $ck_code)
    ->execute();
    
  $ck_group_query = db_select('cool_keys_key_groups');
  $ck_group_query->fields('cool_keys_key_groups', array('kgid', 'num_keys', 'max_uses', 'active','set_unlimited_keys','set_unlimited_uses'));
  $ck_group_query->condition('kgid', $ck_group);
  $ck_group_result = $ck_group_query->execute()->fetchAssoc();
  
  $ck_group_id = $ck_group_result['kgid'];
  $ck_group_keys = $ck_group_result['num_keys'];
  $ck_group_uses = $ck_group_result['max_uses'];
  
  $key_use_query = db_select('cool_keys_key_codes');
  $key_use_query->fields('cool_keys_key_codes', array('kcid','kgid', 'num_used', 'max_uses'));
  $key_use_query->condition('kgid', $ck_group_id);
  $key_use_query->condition('max_uses', 0 , '>');
  // Add the COUNT expression
 
  $key_use_result = $key_use_query->execute()->fetchAssoc();
  
  $use_count = count($key_use_result);

  rules_invoke_event('ckcode_apply_code_' . $ck_group, $ck_group, array());
}
