<?php
/**
 * @file
 * cool_tokens.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cool_tokens_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cool_tokens_token_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cool_tokens';
  $view->human_name = 'Cool Tokens Token Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cool Tokens';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer cool tokens';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'search';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'description' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'tkid' => 'tkid',
    'title' => 'title',
    'description' => 'description',
    'max_uses' => 'max_uses',
    'active' => 'active',
    'used' => 'used',
    'activates' => 'activates',
    'expires' => 'expires',
    'edit_link' => 'edit_link',
    'delete_link' => 'delete_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'tkid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'max_uses' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'active' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'used' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'activates' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expires' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  /* Field: Cool Token: Token ID */
  $handler->display->display_options['fields']['tkid']['id'] = 'tkid';
  $handler->display->display_options['fields']['tkid']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['tkid']['field'] = 'tkid';
  $handler->display->display_options['fields']['tkid']['label'] = '';
  $handler->display->display_options['fields']['tkid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tkid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tkid']['separator'] = '';
  /* Field: Cool Token: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  /* Field: Cool Token: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Cool Token: Max Uses */
  $handler->display->display_options['fields']['max_uses']['id'] = 'max_uses';
  $handler->display->display_options['fields']['max_uses']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['max_uses']['field'] = 'max_uses';
  /* Field: Cool Token: Active */
  $handler->display->display_options['fields']['active']['id'] = 'active';
  $handler->display->display_options['fields']['active']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['active']['field'] = 'active';
  /* Field: Cool Token: Token Activation Date */
  $handler->display->display_options['fields']['activates']['id'] = 'activates';
  $handler->display->display_options['fields']['activates']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['activates']['field'] = 'activates';
  $handler->display->display_options['fields']['activates']['label'] = 'Activation Date';
  $handler->display->display_options['fields']['activates']['date_format'] = 'gallery';
  /* Field: Cool Token: Token Expires Date */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['label'] = 'Expires On';
  $handler->display->display_options['fields']['expires']['date_format'] = 'gallery';
  /* Field: Cool Token: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Field: Cool Token: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Filter criterion: Cool Token: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'cool_tokens';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['operator'] = 'contains';
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/ft_tokens';
  $handler->display->display_options['menu']['title'] = 'Cool Tokens';
  $handler->display->display_options['menu']['description'] = 'Administer Cool Tokens';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['cool_tokens_token_admin'] = $view;

  $view = new view();
  $view->name = 'user_ft_tokens';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cool_tokens';
  $view->human_name = 'User FT Tokens';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Tokens';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: FT Tokens Owner: Tkid */
  $handler->display->display_options['relationships']['tkid']['id'] = 'tkid';
  $handler->display->display_options['relationships']['tkid']['table'] = 'cool_tokens_owner';
  $handler->display->display_options['relationships']['tkid']['field'] = 'tkid';
  $handler->display->display_options['relationships']['tkid']['required'] = TRUE;
  /* Relationship: FT Tokens Owner: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'cool_tokens_owner';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Cool Token: Token ID */
  $handler->display->display_options['fields']['tkid_1']['id'] = 'tkid_1';
  $handler->display->display_options['fields']['tkid_1']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['tkid_1']['field'] = 'tkid';
  $handler->display->display_options['fields']['tkid_1']['relationship'] = 'tkid';
  $handler->display->display_options['fields']['tkid_1']['label'] = '';
  $handler->display->display_options['fields']['tkid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tkid_1']['element_label_colon'] = FALSE;
  /* Field: Cool Token: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Cool Token: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Cool Token: Token Expires Date */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'cool_tokens';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['label'] = 'Expires';
  $handler->display->display_options['fields']['expires']['date_format'] = 'gallery';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Use Token';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '/tokens/redeemcodeurl/?fttoken=[tkid_1]&?ftpath=/admin/structure/ft_tokens';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: User FT Tokens Block */
  $handler = $view->new_display('block', 'User FT Tokens Block', 'user_ft_tokens');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: FT Tokens Owner: Tkid */
  $handler->display->display_options['relationships']['tkid']['id'] = 'tkid';
  $handler->display->display_options['relationships']['tkid']['table'] = 'cool_tokens_owner';
  $handler->display->display_options['relationships']['tkid']['field'] = 'tkid';
  $handler->display->display_options['relationships']['tkid']['required'] = TRUE;
  /* Relationship: FT Tokens Owner: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'cool_tokens_owner';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile UID';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $export['user_ft_tokens'] = $view;

  return $export;
}
