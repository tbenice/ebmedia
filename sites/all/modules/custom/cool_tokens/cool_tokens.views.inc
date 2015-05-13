<?php
/**
 * @file
 * cool_tokens.views.inc
 */

/**
 * Implementation of hook_views_data()
 */
function cool_tokens_views_data() {

  $data['cool_tokens_owner']['table']['group'] = t('FT Tokens Owner');
 
  $data['cool_tokens_owner']['table']['base'] = array(
    'field' => 'tkid',
    'title' => t('FT Tokens Owners'),
    'help' => t("Displays owner info for FT Tokens."),
    'weight' => -10,
  );
  $data['cool_tokens_owner']['tkid'] = array(
  'title' => t('Tkid'),
  'help' => t('The ID of the token.'),
  // Information for displaying the tkid
  'field' => array(
    'handler' => 'views_handler_numeric',
    'click sortable' => TRUE,
  ),
  // Information for accepting a tkid as an argument
  'argument' => array(
    'name field' => 'tkid', 
    'numeric' => TRUE,
  ),
  // Information for relating the tkid to the cool_tokens table
  'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('FT Token ID'),
      'base' => 'cool_tokens',
      'base field' => 'tkid',
      'skip base' => array(),
    ),
  // Information for sorting on a tkid.
  'sort' => array(
    'handler' => 'views_handler_sort',
    ),
  );
  $data['cool_tokens_owner']['uid'] = array(
  'title' => t('Uid'),
  'help' => t('The uid of the token owner.'), 
  // Information for displaying the uid
  'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
  ),
  // Information for accepting a uid as an argument
  'argument' => array(
    'name field' => 'uid', // the field to display in the summary.
    'numeric' => TRUE,
  ),
  'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('FT Token UID'),
      'base' => 'users',
      'base field' => 'uid',
      'skip base' => array(),
    ),
  // Information for sorting on a uid.
  'sort' => array(
    'handler' => 'views_handler_sort',
    ),
  );
  $data['cool_tokens_owner']['num_used'] = array(
  'title' => t('Number of Uses'),
  'help' => t('The number of times a token has been used.'), 
  // Information for displaying num_used
  'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
  ),
  // Information for sorting on num_used
  'sort' => array(
    'handler' => 'views_handler_sort',
    ),
  );
  $data['cool_tokens_owner']['assigned'] = array(
  'title' => t('Assigned'),
  'help' => t('The date a token was assigned to the user.'), 
  // Information for displaying num_used
  'field' => array(
    'handler' => 'views_handler_field_date',
    'click sortable' => TRUE,
  ),
  // Information for sorting on num_used
  'sort' => array(
    'handler' => 'views_handler_sort',
    ),
  );
  $data['cool_tokens_owner']['table']['join']['cool_tokens'] = array(
    'left_field' => 'tkid',
    'field' => 'tkid',
  );
  $data['cool_tokens_owner']['table']['join']['users'] = array(
  'left_field' => 'uid',
  'field' => 'uid',
  );

  return $data;
}
