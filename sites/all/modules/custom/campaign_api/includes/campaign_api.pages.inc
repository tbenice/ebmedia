<?php
/**
 * @file campaign_api.pages.inc
 */



/**
 * Page callback for campaign config. pages.
 * @param Campaign $campaign
 */
function campaign_api_campaign_page($campaign) {
  return theme('campaign_api_campaign_page', array('campaign' => $campaign));
}

/**
 * Group view callback.
 */
function cool_keys_key_group_view($ck_group) {
  drupal_set_title(entity_label('cool_keys_key_group', $ck_group));
  return entity_view('cool_keys_key_group', array(entity_id('cool_keys_key_group', $ck_group) => $ck_group), 'full');
}

/**
 * Redeem key code callback.
 */
function campaign_api_cool_keys_redeem() {
  return drupal_get_form('campaign_api_key_redeem_form');
}


/**
 * Provides the CoolKeys Redeem Form.
 */
function campaign_api_key_redeem_form($form, &$form_state) {

  $form['coolkeyskey']['#tree'] = TRUE;
  $form['coolkeyskey']['key_code'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Enter Your Code'),
  );
  $form['actions'] = array(
    '#weight' => 100,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Redeem'),
  );

  $form['#validate'][] = 'campaign_api_key_redeem_form_validate';

  return $form;

}

/**
 * Validate cool_keys_key_redeem_form
 */
function campaign_api_key_redeem_form_validate($form, &$form_state){
  $ck_key = $form_state['values']['coolkeyskey']['key_code'];
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
    form_set_error('title','Your key code is not active.');
    return FALSE;
  }

  if($ck_key != $key_result['key_code']) {
    form_set_error('title','You did not enter a valid code.');
    return FALSE;
  }

  if($ck_group_result['set_unlimited_uses'] != 1) {
    if($key_result['num_used'] >= $key_result['max_uses']) {
      form_set_error('title','Your key code has already been used.');
      return FALSE;
    }
  }
}

/**
 * Handle cool_keys_key_redeem_form submit
 */
function campaign_api_key_redeem_form_submit($form, &$form_state) {
  $ck_code = $form_state['values']['coolkeyskey']['key_code'];
  cool_keys_redeem_key($ck_code);
}

/**
 * Key load function to handle keys passed via URL
 */
function campaign_api_cool_keys_url_redeem() {
  $args = array();
  $args = $_GET;
  foreach($args as &$arg) {
    filter_xss($arg);
  }
  unset($args['q'], $args['ckkey'], $args['ckpath']);
  foreach($args as &$arg) {
    filter_xss($arg);
  }
  $ck_key = filter_xss($_GET['ckkey']);
  $path = filter_xss($_GET['ckpath']);
  if(isset($ck_key)) {
    cool_keys_redeem_key($ck_key, $args);
  }
  drupal_goto($path);
}

/**
 * Issue key code callback.
 */
function campaign_api_issue_key_code_form($form, $form_state, $ck_key) {
  $form['ck_key'] = array(
    '#type' => 'hidden',
    '#value' => $ck_key,
  );
  return confirm_form($form, t('Are you sure you want to issue cool key: ' . $ck_key . '?'), 'admin/structure/cool-keys-groups', t('The key will be issued.'), t('Issue Key'));
}

/**
 * Submit handler for the cool_keys_issue_key_code_form.
 */
function campaign_api_issue_key_code_form_submit($form, $form_state) {
  $ck_key = $form_state['values']['ck_key'];
  if (!isset($ck_key)) {
    drupal_set_message(t('No Cool Key was found.'), 'error');
    return;
  }
  if ($ck_group = _get_coolkey_group_from_key($ck_key)) {
    $ck_group->issueKey($ck_key);
    return TRUE;
  }
  else {
    drupal_set_message(t('Could not issue the key.'), 'error');
    return FALSE;
  }
}

/**
 * Reclaim key code callback.
 */
function cool_keys_reclaim_key_code_form($form, $form_state, $ck_key) {
  $form['ck_key'] = array(
    '#type' => 'hidden',
    '#value' => $ck_key,
  );
  return confirm_form($form, t('Are you sure you want to reclaim cool key: ' . $ck_key . '?'), 'admin/structure/cool-keys-groups', t('The key will be reclaimed.'), t('Reclaim Key'));
}

/**
 * Submit handler for the cool_keys_reclaim_key_code_form
 */
function campaign_api_reclaim_key_code_form($form, $form_state) {
  $ck_key = $form_state['values']['ck_key'];
  if (!isset($ck_key)) {
    drupal_set_message(t('No Cool Key was found.'), 'error');
    return;
  }
  if ($ck_group = _get_coolkey_group_from_key($ck_key)) {
    $ck_group->reclaimKey($ck_key);
    return TRUE;
  }
  else {
    drupal_set_message(t('Could not reclaim the key.'), 'error');
    return FALSE;
  }

}