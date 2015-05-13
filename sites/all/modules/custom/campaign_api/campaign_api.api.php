<?php
/**
 * @file
 * Hooks provided by this module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Provide a list of config plugins for the campaign.
 */
function hook_campaign_api_config_plugin_info() {
  $plugins = array();
  $plugins['Default'] = array(
    'label' => t('Default Campaign'),
    'description' => t('Default campaign. Creates a cool keys entry page that shows a message upon key entry'),
    'class' => 'CampaignDefault',
    'file' => array(
      'type' => 'inc',
      'module' => 'campaign_api',
      'file' => 'CampaignDefault',
    ),
  );
  return $plugins;
}

/**
 * Allows modules to alter the coolKeys redeem uri.
 *
 * The redeem uri is returned as a link by the getUri()
 * method of the cool_keys_keys_group entity.
 * This hook allows modules to alter the uri before the
 * link is returned by that method.
 *
 * @param array $uri
 *   An array containing the parts of l() that consitute
 *   a link. This array is used by cool_keys_keys_group->getUri()
 *   to construct the returned redeem link.
 * @param unknown_type $ck_group
 */
function hook_cool_keys_uri_alter(&$uri, $ck_group) {
  $uri = array(
    'path' => 'cool-keys/redeemcodeurl',
    'text' => t('Redeem key code'),
    'options' => array(
      'html' => TRUE,
      'absolute' => TRUE,
      'query' => array(
        'ckkey' => $ck_code,
        'ckpath' => $redirectPath,
      ),
    ),
  );
}