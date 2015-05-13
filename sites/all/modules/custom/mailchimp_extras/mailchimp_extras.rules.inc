<?php
/**
 * @file
 * mailchimp_extras.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function mailchimp_extras_rules_action_info() {
  
  $actions = array();
   
  $actions['mailchimp_extras_mc_group_subscribe'] = array(
    'label' => t('Subscribe user to a mailchimp group'),
    'base' => 'mailchimp_extras_mc_group_subscribe',
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user that will be subscribed to/unsubscribed from.'),
      ),
      'mc_group' => array(
        'type' => 'text',
        'label' => t('Group'),
        'description' => t('Mailchimp group that will be subscribed to/unsubscribed from.'),
        'options list' => 'mailchimp_extras_options_list',
      ),
    ),
    'group' => t('FanTorrent - Mailchimp'),
  );
  $actions['mailchimp_extras_mc_group_unsubscribe'] = array(
    'label' => t('Unsubscribe user from a mailchimp group'),
    'base' => 'mailchimp_extras_mc_group_unsubscribe',
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user that will be subscribed to/unsubscribed from.'),
      ),
      'mc_group' => array(
        'type' => 'text',
        'label' => t('Group'),
        'description' => t('Mailchimp group that will be subscribed to/unsubscribed from.'),
        'options list' => 'mailchimp_extras_options_list',
      ),
    ),
    'group' => t('FanTorrent - Mailchimp'),
  );
  $actions['mailchimp_extrasemail_subscribe'] = array(
    'label' => t('Subscribe email to a mailchimp group'),
    'base' => 'mailchimp_extras_mc_group_subscribe',
    'parameter' => array(
      'email' => array(
          'label' => t('Email to subscribe to mailchimp'),
          'type' => 'text', 
        ),
      'mc_group' => array(
        'type' => 'text',
        'label' => t('Group'),
        'description' => t('Mailchimp group that will be subscribed to/unsubscribed from.'),
        'options list' => 'mailchimp_extras_options_list',
      ),
    ),
    'group' => t('FanTorrent - Mailchimp'),
    'callbacks' => array(
        'execute' => 'mailchimp_extras_mc_group_email_subscribe',
      ),
  );
  $actions['mailchimp_extrasemail_unsubscribe'] = array(
    'label' => t('Unsubscribe email from a mailchimp group'),
    'base' => 'mailchimp_extras_mc_group_unsubscribe',
    'parameter' => array(
      'email' => array(
          'label' => t('Email to unsubscribe from mailchimp'),
          'type' => 'text',
        ),
      'mc_group' => array(
        'type' => 'text',
        'label' => t('Group'),
        'description' => t('Mailchimp group that will be subscribed to/unsubscribed from.'),
        'options list' => 'mailchimp_extras_options_list',
      ),
    ),
    'group' => t('FanTorrent - Mailchimp'),
    'callbacks' => array(
        'execute' => 'mailchimp_extras_mc_group_email_unsubscribe',
      ),
  );
  return $actions;
    
}

/**
 * Action: Subscribe user to MailChimp group.
 */
function mailchimp_extras_mc_group_subscribe($account, $mc_group, $mcapi = NULL) {
  $lid = variable_get('mailchimp_extras_main_list', '');
  $list = mailchimp_lists_load($lid);
  $email = $account->mail;
  //Somewhere $mc_group needs to also include the grouping # that the group belongs to. Without this, a user can not be subscribed.
  //$merge_variables = mailchimp_lists_load_user_mergevars($account, $list);
  _mailchimp_extras_user_subscribe($list, $mc_group, $email, FALSE);
}

/**
 * Action: Unsubscribe user from a Mailchimp group.
 */
function mailchimp_extras_mc_group_unsubscribe($account, $mc_group) {
  $lid = variable_get('mailchimp_extras_main_list', '');
  $list = mailchimp_lists_load($lid);
  $email = $account->mail;
  _mailchimp_extras_user_unsubscribe($list, $mc_group, $email, FALSE);
}

function mailchimp_extras_mc_group_email_subscribe($email, $mc_group) {
  $lid = variable_get('mailchimp_extras_main_list', '');
  $list = mailchimp_lists_load($lid);
  //Somewhere $mc_group needs to also include the grouping # that the group belongs to. Without this, a user can not be subscribed.
  //$merge_variables = mailchimp_lists_load_user_mergevars($account, $list);
  _mailchimp_extras_user_subscribe($list, $mc_group, $email, FALSE);
}

function mailchimp_extras_mc_group_email_unsubscribe($email, $mc_group) {
  $lid = variable_get('mailchimp_extras_main_list', '');
  $list = mailchimp_lists_load($lid);
  _mailchimp_extras_user_unsubscribe($list, $mc_group, $email, FALSE);
}
