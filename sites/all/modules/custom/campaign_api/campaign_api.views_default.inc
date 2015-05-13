<?php
/**
 * @file
 * cool_keys.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function campaign_api_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = '_cool-keys-groups_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cool_keys_key_groups';
  $view->human_name = ' CoolKeys Groups Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CoolKeys Groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer coolkeys';
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
    'kgid' => 'kgid',
    'title' => 'title',
    'description' => 'description',
    'uid' => 'uid',
    'activates' => 'activates',
    'expires' => 'expires',
    'num_keys' => 'num_keys',
    'max_uses' => 'max_uses',
    'edit_link' => 'edit_link',
    'delete_link' => 'edit_link',
    'key_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'kgid' => array(
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
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'num_keys' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'max_uses' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'key_link' => array(
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
  /* Field:  CoolKeys Group: KGID */
  $handler->display->display_options['fields']['kgid']['id'] = 'kgid';
  $handler->display->display_options['fields']['kgid']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['kgid']['field'] = 'kgid';
  $handler->display->display_options['fields']['kgid']['label'] = '';
  $handler->display->display_options['fields']['kgid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['kgid']['element_label_colon'] = FALSE;
  /* Field:  CoolKeys Group: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  /* Field:  CoolKeys Group: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field:  CoolKeys Group: Author */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field:  CoolKeys Group: Group Activation Date */
  $handler->display->display_options['fields']['activates']['id'] = 'activates';
  $handler->display->display_options['fields']['activates']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['activates']['field'] = 'activates';
  $handler->display->display_options['fields']['activates']['label'] = 'Activation Date';
  $handler->display->display_options['fields']['activates']['date_format'] = 'gallery';
  /* Field:  CoolKeys Group: Group Expires Date */
  $handler->display->display_options['fields']['expires']['id'] = 'expires';
  $handler->display->display_options['fields']['expires']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['expires']['field'] = 'expires';
  $handler->display->display_options['fields']['expires']['label'] = 'Expires On';
  $handler->display->display_options['fields']['expires']['date_format'] = 'gallery';
  /* Field:  CoolKeys Group: Number of Keys */
  $handler->display->display_options['fields']['num_keys']['id'] = 'num_keys';
  $handler->display->display_options['fields']['num_keys']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['num_keys']['field'] = 'num_keys';
  $handler->display->display_options['fields']['num_keys']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['num_keys']['separator'] = '';
  /* Field:  CoolKeys Group: Max Uses */
  $handler->display->display_options['fields']['max_uses']['id'] = 'max_uses';
  $handler->display->display_options['fields']['max_uses']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['max_uses']['field'] = 'max_uses';
  /* Field:  CoolKeys Group: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  /* Field:  CoolKeys Group: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  /* Field:  CoolKeys Group: Keys link */
  $handler->display->display_options['fields']['key_link']['id'] = 'key_link';
  $handler->display->display_options['fields']['key_link']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['fields']['key_link']['field'] = 'key_link';
  $handler->display->display_options['fields']['key_link']['label'] = '';
  $handler->display->display_options['fields']['key_link']['element_label_colon'] = FALSE;
  /* Filter criterion:  CoolKeys Group: Description */
  $handler->display->display_options['filters']['description']['id'] = 'description';
  $handler->display->display_options['filters']['description']['table'] = 'cool_keys_key_groups';
  $handler->display->display_options['filters']['description']['field'] = 'description';
  $handler->display->display_options['filters']['description']['operator'] = 'contains';
  $handler->display->display_options['filters']['description']['exposed'] = TRUE;
  $handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['label'] = 'Description';
  $handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
  $handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/cool-keys-groups';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'CoolKeys';
  $handler->display->display_options['menu']['description'] = 'Administer  CoolKeys Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['_cool-keys-groups_admin'] = $view;

  $view = new view();
  $view->name = 'cool_keys_key_codes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cool_keys_key_codes';
  $view->human_name = ' CoolKeys Key Codes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CoolKeys Codes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer coolkeys';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'search';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'description' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'kgid' => 'kgid',
    'key_code' => 'key_code',
    'max_uses' => 'max_uses',
    'num_used' => 'num_used',
    'issued' => 'issued',
    'issue_link' => 'issue_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'kgid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'key_code' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'max_uses' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'num_used' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'issued' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'issue_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Field:  CoolKeys Group: Key Group */
  $handler->display->display_options['fields']['kgid']['id'] = 'kgid';
  $handler->display->display_options['fields']['kgid']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['kgid']['field'] = 'kgid';
  /* Field:  CoolKeys Group: Key Code */
  $handler->display->display_options['fields']['key_code']['id'] = 'key_code';
  $handler->display->display_options['fields']['key_code']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['key_code']['field'] = 'key_code';
  /* Field:  CoolKeys Group: Max Uses */
  $handler->display->display_options['fields']['max_uses']['id'] = 'max_uses';
  $handler->display->display_options['fields']['max_uses']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['max_uses']['field'] = 'max_uses';
  /* Field:  CoolKeys Group: Current Uses */
  $handler->display->display_options['fields']['num_used']['id'] = 'num_used';
  $handler->display->display_options['fields']['num_used']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['num_used']['field'] = 'num_used';
  /* Field:  CoolKeys Group: Issued */
  $handler->display->display_options['fields']['issued']['id'] = 'issued';
  $handler->display->display_options['fields']['issued']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['issued']['field'] = 'issued';
  /* Field: Action Link */
  $handler->display->display_options['fields']['issue_link']['id'] = 'issue_link';
  $handler->display->display_options['fields']['issue_link']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['issue_link']['field'] = 'issue_link';
  $handler->display->display_options['fields']['issue_link']['relationship'] = 'kgid';
  $handler->display->display_options['fields']['issue_link']['ui_name'] = 'Action Link';
  /* Contextual filter:  CoolKeys Group: Group ID */
  $handler->display->display_options['arguments']['kgid']['id'] = 'kgid';
  $handler->display->display_options['arguments']['kgid']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['arguments']['kgid']['field'] = 'kgid';
  $handler->display->display_options['arguments']['kgid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['kgid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['kgid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['kgid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/cool-keys-groups/%/keys';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Key Codes';
  $handler->display->display_options['menu']['description'] = 'View  CoolKeys';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'keys_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field:  CoolKeys Group: Key Code */
  $handler->display->display_options['fields']['key_code']['id'] = 'key_code';
  $handler->display->display_options['fields']['key_code']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['key_code']['field'] = 'key_code';
  /* Field:  CoolKeys Group: Max Uses */
  $handler->display->display_options['fields']['max_uses']['id'] = 'max_uses';
  $handler->display->display_options['fields']['max_uses']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['max_uses']['field'] = 'max_uses';
  /* Field:  CoolKeys Group: Current Uses */
  $handler->display->display_options['fields']['num_used']['id'] = 'num_used';
  $handler->display->display_options['fields']['num_used']['table'] = 'cool_keys_key_codes';
  $handler->display->display_options['fields']['num_used']['field'] = 'num_used';
  $handler->display->display_options['path'] = 'admin/structure/cool-keys-groups/%/keys/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['cool_keys_key_codes'] = $view;

  return $export;
}
