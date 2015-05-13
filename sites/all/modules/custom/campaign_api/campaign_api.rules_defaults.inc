<?php
/**
 * @file campaign_api.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function campaign_api_default_rules_configuration() {
  $configs = array();

  $campaigns = campaign_load_multiple(FALSE, array(), TRUE);
  foreach($campaigns as $key => $campaign) {
    if (empty($campaign->data['plugin_data']['rules'])) {
      continue;
    }
    $configs += $campaign->data['plugin_data']['rules'];
  }

  // Load all discounts.
  $discounts = _discount_load_multiple(FALSE, array(), TRUE);
  foreach($discounts as $discount) {
    // Proceed if this is a promo code discount.
    if (strpos($discount->getCondition('condition_type'), 'promo_code') === 0) {
      $rules = $discount->getCondition('rule');
      if (!empty($rules)) {
        foreach($rules as $key=>$rule) {
          $configs[$discount->getCondition('promo_code_title') . '_' . $key] = $rule;
        }
      }
    }
  }

  $configs['rules_show_a_message_when_key_reaches_max_uses'] = entity_import('rules_config', '{ "rules_show_a_message_when_key_reaches_max_uses" : {
      "LABEL" : "Show a message when key reaches max uses",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "campaign_api" ],
      "ON" : [ "cool_keys_reached_max_uses" ],
      "DO" : [
        { "drupal_message" : {
            "message" : "Sorry, but your code has reached its maximum number of uses.\\r\\nIf you feel that this is in error please contact customer support.",
            "type" : "error"
          }
        }
      ]
    }
  }');

  return $configs;
}