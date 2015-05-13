<?php

/**
 * Form callback for the settings page.
 */
function commerce_store_info() {
  $form['store-info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Store_info'),
    '#description' => t('Specify the patterns used for the generation of SKUs and titles during bulk creation.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#access' => user_access('configure store'),
    '#tree' => FALSE,
  );

  $form['store-info']['store_info_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => variable_get('store_info_name', NULL),
  );

  $form['store-info']['store_info_owner'] = array(
    '#type' => 'textfield',
    '#title' => t('Owner'),
    '#default_value' => variable_get('store_info_owner', NULL),
  );

  $form['store-info']['store_info_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#default_value' => variable_get('store_info_email', NULL),
  );

  $form['store-info']['store_info_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#default_value' => variable_get('store_info_phone', NULL),
  );

  $form['store-info']['store_info_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax'),
    '#default_value' => variable_get('store_info_fax', NULL),
  );

  $form['store-info']['store_info_street1'] = array(
    '#type' => 'textfield',
    '#title' => t('Street #1'),
    '#default_value' => variable_get('store_info_street1', NULL),
  );

  $form['store-info']['store_info_street2'] = array(
    '#type' => 'textfield',
    '#title' => t('Street #2'),
    '#default_value' => variable_get('store_info_street2', NULL),
  );

  $form['store-info']['store_info_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => variable_get('store_info_city', NULL),
  );

  $form['store-info']['store_info_zone'] = array(
    '#type' => 'textfield',
    '#title' => t('State/Province'),
    '#default_value' => variable_get('store_info_zone', NULL),
  );

  $form['store-info']['store_info_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Code'),
    '#default_value' => variable_get('store_info_postal_code', NULL),
  );

  $form['store-info']['store_info_country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#default_value' => variable_get('store_info_country', NULL),
  );

  return system_settings_form($form);
}

