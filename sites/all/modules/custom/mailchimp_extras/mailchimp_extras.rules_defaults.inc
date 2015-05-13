<?php
/**
 * @file
 * mailchimp_extras.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function mailchimp_extras_default_rules_configuration() {
  $items = array();
  $items['rules_unsubscribe_mailchimp_on_user_delete'] = entity_import('rules_config', '{ "rules_unsubscribe_mailchimp_on_user_delete" : {
      "LABEL" : "Unsubscribe Mailchimp on user delete",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "mailchimp_lists", "rules" ],
      "ON" : [ "user_delete" ],
      "DO" : [
        { "mailchimp_lists_unsubscribe_list" : { "mail" : [ "account:mail" ], "list" : "newsletter_sign_up" } }
      ]
    }
  }');
  return $items;
}
