<?php

function commerce_store_info_token_info() {
  // Tokens for orders.
  $info = array();

  $info['store_info_name'] = array(
    'name' => t('Store name', array()),
    'description' => t('The name of your store'),
  );

  $info['store_info_owner'] = array(
    'name' => t('Store owner', array()),
    'description' => t('The owner of your store'),
  );

  $info['store_info_email'] = array(
    'name' => t('Store email', array()),
    'description' => t('The email address of your store'),
  );

  $info['store_info_phone'] = array(
    'name' => t('Store phone', array()),
    'description' => t('The phone number of your store'),
  );

  $info['store_info_fax'] = array(
    'name' => t('Store fax', array()),
    'description' => t('The fax number of your store'),
  );

  $info['store_info_street1'] = array(
    'name' => t('Store street1', array()),
    'description' => t('The first line of your store address'),
  );

  $info['store_info_street2'] = array(
    'name' => t('Store street2', array()),
    'description' => t('The second line of your store address'),
  );

  $info['store_info_city'] = array(
    'name' => t('Store city', array()),
    'description' => t('The city of your store'),
  );

  $info['store_info_zone'] = array(
    'name' => t('Store zone', array()),
    'description' => t('The state or province of your store'),
  );

  $info['store_info_postal_code'] = array(
    'name' => t('Store postal code', array()),
    'description' => t('The postal code of your store'),
  );

  $info['store_info_country'] = array(
    'name' => t('Store country', array()),
    'description' => t('The country of your store'),
  );

  return array(
    'tokens' => array('site' => $info),
  );
}


function commerce_store_info_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);

  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }

  $replacements = array();

  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'store_info_name':
          $replacements[$original] = variable_get('store_info_name', '');
          break;
        case 'store_info_owner':
          $replacements[$original] = variable_get('store_info_owner', '');
          break;
        case 'store_info_email':
          $replacements[$original] = variable_get('store_info_email', '');
          break;
        case 'store_info_phone':
          $replacements[$original] = variable_get('store_info_phone', '');
          break;
        case 'store_info_fax':
          $replacements[$original] = variable_get('store_info_fax', '');
          break;
        case 'store_info_street1':
          $replacements[$original] = variable_get('store_info_street1', '');
          break;
        case 'store_info_street2':
          $replacements[$original] = variable_get('store_info_street2', '');
          break;
        case 'store_info_city':
          $replacements[$original] = variable_get('store_info_city', '');
          break;
        case 'store_info_zone':
          $replacements[$original] = variable_get('store_info_zone', '');
          break;
        case 'store_info_postal_code':
          $replacements[$original] = variable_get('store_info_postal_code', '');
          break;
        case 'store_info_country':
          $replacements[$original] = variable_get('store_info_country', '');
          break;
      }
    }
  }

  return $replacements;
}

