<?php
/**
 * @file
 * mailchimp_extras.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function mailchimp_extras_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mailchimp_extras_mailchimp_groups';
  $context->description = 'Context for MailChimp Groups admin display';
  $context->tag = 'Admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/config/services/mailchimp/groups' => 'admin/config/services/mailchimp/groups',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mailchimp_extras-mailing_list_mc_group_display' => array(
          'module' => 'mailchimp_extras',
          'delta' => 'mailing_list_mc_group_display',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin');
  t('Context for MailChimp Groups admin display');
  $export['mailchimp_extras_mailchimp_groups'] = $context;

  return $export;
}
