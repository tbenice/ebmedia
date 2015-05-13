<?php
/**
 * @file
 * theme.inc
 * Throw preprocess and theme function in this file.
 */

/**
 * Preprocess variables for the campaign page.
 */
function template_preprocess_campaign_api_campaign_page(&$vars) {
  $plugin = campaign_api_get_campaign_plugin($vars['campaign']);
  $info = entity_get_info('campaign');
  $vars['content']['name'] = array(
    '#markup' => $vars['campaign']->campaign_id,
  );
  $vars['content']['link'] = array(
    '#markup' => l('Back to Campaigns', $info['admin ui']['path']),
  );
  $vars['content']['table'] = array(
    '#markup' => $plugin->configTable(),
  );
}
