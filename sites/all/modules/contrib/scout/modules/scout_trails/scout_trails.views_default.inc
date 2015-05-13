<?php
/**
 * @file
 * scout_trails.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scout_trails_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'scout_tips';
  $view->description = '';
  $view->tag = 'Scout Trails';
  $view->base_table = 'scout_tip';
  $view->human_name = 'Scout Tips';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scout Tips';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin scout tours';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'tag',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'tip_id' => 'tip_id',
    'title' => 'title',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing',
    'created' => 'created',
    'changed' => 'created',
    'name' => 'name',
    'status' => 'status',
    'tag' => 'tag',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tip_id' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => ' / ',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' / ',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '(Exported) Status<br />
1 = Custom, 2 = Default, 3 = Overridden';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Notice:';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no available Scout Tips at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Scout Tip: User that created this Scout Tip */
  $handler->display->display_options['relationships']['Tip Scout']['id'] = 'Tip Scout';
  $handler->display->display_options['relationships']['Tip Scout']['table'] = 'scout_tip';
  $handler->display->display_options['relationships']['Tip Scout']['field'] = 'Tip Scout';
  /* Field: Scout Tip: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Scout Tip Type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Scout Tip: scout tip ID */
  $handler->display->display_options['fields']['tip_id']['id'] = 'tip_id';
  $handler->display->display_options['fields']['tip_id']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['tip_id']['field'] = 'tip_id';
  $handler->display->display_options['fields']['tip_id']['label'] = 'Tip ID';
  $handler->display->display_options['fields']['tip_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tip_id']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/edit';
  $handler->display->display_options['fields']['tip_id']['separator'] = '';
  /* Field: Scout Tip: scout tip Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/edit';
  /* Field: Edit Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit Link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Manage';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/edit';
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[tip_id]/delete';
  /* Field: Scout Tip: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created / Updated';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Scout Tip: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'Tip Scout';
  $handler->display->display_options['fields']['name']['label'] = 'Scout';
  /* Field: Scout Tip: Export Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['separator'] = '';
  /* Field: Scout Tip: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['exclude'] = TRUE;
  /* Sort criterion: Scout Tip: Tag */
  $handler->display->display_options['sorts']['tag']['id'] = 'tag';
  $handler->display->display_options['sorts']['tag']['table'] = 'scout_tip';
  $handler->display->display_options['sorts']['tag']['field'] = 'tag';
  /* Sort criterion: Scout Tip: scout tip ID */
  $handler->display->display_options['sorts']['tip_id']['id'] = 'tip_id';
  $handler->display->display_options['sorts']['tip_id']['table'] = 'scout_tip';
  $handler->display->display_options['sorts']['tip_id']['field'] = 'tip_id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Scout Tip: Tag */
  $handler->display->display_options['filters']['tag']['id'] = 'tag';
  $handler->display->display_options['filters']['tag']['table'] = 'scout_tip';
  $handler->display->display_options['filters']['tag']['field'] = 'tag';
  $handler->display->display_options['filters']['tag']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tag']['expose']['operator_id'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['label'] = 'Tag';
  $handler->display->display_options['filters']['tag']['expose']['operator'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['identifier'] = 'tag';
  $handler->display->display_options['filters']['tag']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Scout Tip: Export Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'scout_tip';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Export Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'admin/content/scout-trails/scout-tips';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scout Tips';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Tags */
  $handler = $view->new_display('entityreference', 'Tags', 'tags');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Searches Tips by tags and displays tags';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'tag' => 'tag',
    'type' => 0,
    'tip_id' => 0,
    'title' => 0,
    'nothing' => 0,
    'nothing_1' => 0,
    'created' => 0,
    'changed' => 0,
    'name' => 0,
    'status' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Scout Tip: User that created this Scout Tip */
  $handler->display->display_options['relationships']['Tip Scout']['id'] = 'Tip Scout';
  $handler->display->display_options['relationships']['Tip Scout']['table'] = 'scout_tip';
  $handler->display->display_options['relationships']['Tip Scout']['field'] = 'Tip Scout';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Scout Tip: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'scout_tip';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['label'] = '';
  $handler->display->display_options['fields']['tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Scout Tip: Tag */
  $handler->display->display_options['arguments']['tag']['id'] = 'tag';
  $handler->display->display_options['arguments']['tag']['table'] = 'scout_tip';
  $handler->display->display_options['arguments']['tag']['field'] = 'tag';
  $handler->display->display_options['arguments']['tag']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tag']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tag']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tag']['limit'] = '0';
  $export['scout_tips'] = $view;

  $view = new view();
  $view->name = 'scout_trails';
  $view->description = '';
  $view->tag = 'Scout Trails';
  $view->base_table = 'scout_trail';
  $view->human_name = 'Scout Trails';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scout Trails';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin scout tours';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'tag',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'trail_id' => 'trail_id',
    'title' => 'title',
    'description' => 'description',
    'nothing' => 'nothing',
    'nothing_2' => 'nothing',
    'nothing_1' => 'nothing',
    'created' => 'created',
    'changed' => 'changed',
    'name' => 'name',
    'field_scout_trail_tips' => 'field_scout_trail_tips',
    'status' => 'status',
    'tag' => 'tag',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'trail_id' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => ' / ',
      'empty_column' => 0,
    ),
    'nothing_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scout_trail_tips' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '(Exported) Status
1 = Custom, 2 = Default, 3 = Overridden
<a href="<?php print url(\'scout_trail/add\'); ?>>Add Task</a>
<br />
<br />
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Notice:';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no available Scout Trails at this time.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Referenced Scout Tips */
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['id'] = 'field_scout_trail_tips_target_id';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['table'] = 'field_data_field_scout_trail_tips';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['field'] = 'field_scout_trail_tips_target_id';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['ui_name'] = 'Referenced Scout Tips';
  $handler->display->display_options['relationships']['field_scout_trail_tips_target_id']['label'] = 'Referenced Scout Tips';
  /* Relationship: Scout Trail: User that created this Scout Trail */
  $handler->display->display_options['relationships']['Trail Scout']['id'] = 'Trail Scout';
  $handler->display->display_options['relationships']['Trail Scout']['table'] = 'scout_trail';
  $handler->display->display_options['relationships']['Trail Scout']['field'] = 'Trail Scout';
  /* Field: Scout Trail: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Trail Type  ';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Scout Trail: Trail ID */
  $handler->display->display_options['fields']['trail_id']['id'] = 'trail_id';
  $handler->display->display_options['fields']['trail_id']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['trail_id']['field'] = 'trail_id';
  $handler->display->display_options['fields']['trail_id']['separator'] = '';
  /* Field: Scout Trail: Trail Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/edit';
  /* Field: Scout Trail: Trail Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Edit Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit Link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Manage';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/edit';
  /* Field: Clone Link */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Clone Link';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Clone';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Clone';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/clone';
  /* Field: Delete Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Delete Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/content/scout-trails/[trail_id]/delete';
  /* Field: Scout Trail: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Scout Trail: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'Trail Scout';
  $handler->display->display_options['fields']['name']['label'] = 'Scout';
  /* Field: Scout Trail: Scout Tips */
  $handler->display->display_options['fields']['field_scout_trail_tips']['id'] = 'field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['table'] = 'field_data_field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['field'] = 'field_scout_trail_tips';
  $handler->display->display_options['fields']['field_scout_trail_tips']['group_type'] = 'stddev_pop';
  $handler->display->display_options['fields']['field_scout_trail_tips']['label'] = 'Scout Tips on trail';
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['text'] = '[field_scout_trail_tips]-[field_scout_trail_tips-target_id]';
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['alter']['path'] = 'admin/content/scout-trails/scout-tips/[field_scout_trail_tips-target_id]/edit';
  $handler->display->display_options['fields']['field_scout_trail_tips']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scout_trail_tips']['empty'] = '(None)';
  $handler->display->display_options['fields']['field_scout_trail_tips']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_scout_trail_tips']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_scout_trail_tips']['delta_limit'] = '0';
  $handler->display->display_options['fields']['field_scout_trail_tips']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_scout_trail_tips']['multi_type'] = 'ol';
  /* Field: Scout Trail: Export Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['separator'] = '';
  /* Field: Scout Trail: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['exclude'] = TRUE;
  /* Filter criterion: Scout Trail: Tag */
  $handler->display->display_options['filters']['tag']['id'] = 'tag';
  $handler->display->display_options['filters']['tag']['table'] = 'scout_trail';
  $handler->display->display_options['filters']['tag']['field'] = 'tag';
  $handler->display->display_options['filters']['tag']['group'] = 1;
  $handler->display->display_options['filters']['tag']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tag']['expose']['operator_id'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['label'] = 'Tag';
  $handler->display->display_options['filters']['tag']['expose']['operator'] = 'tag_op';
  $handler->display->display_options['filters']['tag']['expose']['identifier'] = 'tag';
  $handler->display->display_options['filters']['tag']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Scout Trail: Export Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'scout_trail';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Scout Trail: Tag */
  $handler->display->display_options['sorts']['tag']['id'] = 'tag';
  $handler->display->display_options['sorts']['tag']['table'] = 'scout_trail';
  $handler->display->display_options['sorts']['tag']['field'] = 'tag';
  /* Sort criterion: Scout Trail: Trail ID */
  $handler->display->display_options['sorts']['trail_id']['id'] = 'trail_id';
  $handler->display->display_options['sorts']['trail_id']['table'] = 'scout_trail';
  $handler->display->display_options['sorts']['trail_id']['field'] = 'trail_id';
  $handler->display->display_options['path'] = 'admin/content/scout-trails/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Scout Trails';
  $handler->display->display_options['menu']['description'] = 'Create scout trails for page navigation aids.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Scout Trails';
  $handler->display->display_options['tab_options']['description'] = 'Manage scout trails';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Tags */
  $handler = $view->new_display('entityreference', 'Tags', 'tags');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Searches trails by tags and displays tags';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'admin scout tours';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'tag' => 'tag',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Scout Trail: User that created this Scout Trail */
  $handler->display->display_options['relationships']['Trail Scout']['id'] = 'Trail Scout';
  $handler->display->display_options['relationships']['Trail Scout']['table'] = 'scout_trail';
  $handler->display->display_options['relationships']['Trail Scout']['field'] = 'Trail Scout';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Scout Trail: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'scout_trail';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['label'] = '';
  $handler->display->display_options['fields']['tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tag']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['tag']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Scout Trail: Tag */
  $handler->display->display_options['arguments']['tag']['id'] = 'tag';
  $handler->display->display_options['arguments']['tag']['table'] = 'scout_trail';
  $handler->display->display_options['arguments']['tag']['field'] = 'tag';
  $handler->display->display_options['arguments']['tag']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tag']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tag']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tag']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['tag']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $export['scout_trails'] = $view;

  return $export;
}
