<?php
/**
 * @file
 * banner_support.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function banner_support_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rotating_banner_images';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rotating Banner Images';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_banner_link']['id'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['table'] = 'field_data_field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['field'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['label'] = '';
  $handler->display->display_options['fields']['field_banner_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_banner_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_banner_link']['type'] = 'link_absolute';
  /* Field: Content: Banner Image */
  $handler->display->display_options['fields']['field_banner_image']['id'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['table'] = 'field_data_field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['field'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['label'] = '';
  $handler->display->display_options['fields']['field_banner_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_banner_image']['alter']['path'] = '[field_banner_link] ';
  $handler->display->display_options['fields']['field_banner_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_banner_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_banner_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'banner' => 'banner',
  );

  /* Display: Rotating Banner Images Block */
  $handler = $view->new_display('block', 'Rotating Banner Images Block', 'block');
  $handler->display->display_options['block_description'] = 'Rotating Banner Block';

  $export['rotating_banner_images'] = $view;

  return $export;
}
