<?php
/**
 * @file
 * mailchimp_extras.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mailchimp_extras_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mailchimp_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mailchimp Feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'feed_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'content',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_address' => 'field_address',
  );
  /* Relationship: Content: Event Location (field_location_ref) */
  $handler->display->display_options['relationships']['field_location_ref_nid']['id'] = 'field_location_ref_nid';
  $handler->display->display_options['relationships']['field_location_ref_nid']['table'] = 'field_data_field_location_ref';
  $handler->display->display_options['relationships']['field_location_ref_nid']['field'] = 'field_location_ref_nid';
  $handler->display->display_options['relationships']['field_location_ref_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Group */
  $handler->display->display_options['fields']['field_legacy_event_group']['id'] = 'field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['table'] = 'field_data_field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['field'] = 'field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_legacy_event_group']['delta_offset'] = '0';
  /* Field: Content: Release Date */
  $handler->display->display_options['fields']['field_date_hour']['id'] = 'field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['table'] = 'field_data_field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['field'] = 'field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['label'] = 'Start Date';
  $handler->display->display_options['fields']['field_date_hour']['settings'] = array(
    'format_type' => 'gallery',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_location_ref']['id'] = 'field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['table'] = 'field_data_field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['field'] = 'field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['label'] = 'Location';
  /* Field: Content: Map Link */
  $handler->display->display_options['fields']['field_links_2']['id'] = 'field_links_2';
  $handler->display->display_options['fields']['field_links_2']['table'] = 'field_data_field_links_2';
  $handler->display->display_options['fields']['field_links_2']['field'] = 'field_links_2';
  $handler->display->display_options['fields']['field_links_2']['label'] = 'Tickets';
  $handler->display->display_options['fields']['field_links_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links_2']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Venue';
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-locality], [field_address-administrative_area], [field_address-country]';
  $handler->display->display_options['fields']['field_address']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['rel'] = 'TEXT';
  $handler->display->display_options['fields']['field_address']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_links_1']['id'] = 'field_links_1';
  $handler->display->display_options['fields']['field_links_1']['table'] = 'field_data_field_links_1';
  $handler->display->display_options['fields']['field_links_1']['field'] = 'field_links_1';
  $handler->display->display_options['fields']['field_links_1']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['field_links_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_links_1']['alter']['text'] = '[field_links_1-url]';
  $handler->display->display_options['fields']['field_links_1']['empty'] = 'tour';
  $handler->display->display_options['fields']['field_links_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links_1']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_links_1']['settings'] = array(
    'base_formatter' => 'link_default',
  );
  $handler->display->display_options['fields']['field_links_1']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Release Date (field_date_hour) */
  $handler->display->display_options['filters']['field_date_hour_value']['id'] = 'field_date_hour_value';
  $handler->display->display_options['filters']['field_date_hour_value']['table'] = 'field_data_field_date_hour';
  $handler->display->display_options['filters']['field_date_hour_value']['field'] = 'field_date_hour_value';
  $handler->display->display_options['filters']['field_date_hour_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_date_hour_value']['default_date'] = 'now';

  /* Display: Events Feed */
  $handler = $view->new_display('feed', 'Events Feed', 'events');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'field_address';
  $handler->display->display_options['row_options']['link_field'] = 'field_links_1';
  $handler->display->display_options['row_options']['description_field'] = 'field_legacy_event_group';
  $handler->display->display_options['row_options']['creator_field'] = 'title_1';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'title',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Group */
  $handler->display->display_options['fields']['field_legacy_event_group']['id'] = 'field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['table'] = 'field_data_field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['field'] = 'field_legacy_event_group';
  $handler->display->display_options['fields']['field_legacy_event_group']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_legacy_event_group']['delta_offset'] = '0';
  /* Field: Content: Release Date */
  $handler->display->display_options['fields']['field_date_hour']['id'] = 'field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['table'] = 'field_data_field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['field'] = 'field_date_hour';
  $handler->display->display_options['fields']['field_date_hour']['label'] = 'Start Date';
  $handler->display->display_options['fields']['field_date_hour']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_hour']['settings'] = array(
    'format_type' => 'gallery',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event Location */
  $handler->display->display_options['fields']['field_location_ref']['id'] = 'field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['table'] = 'field_data_field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['field'] = 'field_location_ref';
  $handler->display->display_options['fields']['field_location_ref']['label'] = 'Location';
  /* Field: Content: Map Link */
  $handler->display->display_options['fields']['field_links_2']['id'] = 'field_links_2';
  $handler->display->display_options['fields']['field_links_2']['table'] = 'field_data_field_links_2';
  $handler->display->display_options['fields']['field_links_2']['field'] = 'field_links_2';
  $handler->display->display_options['fields']['field_links_2']['label'] = 'Tickets';
  $handler->display->display_options['fields']['field_links_2']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links_2']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Venue';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field: Location */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-locality], [field_address-administrative_area], [field_address-country]';
  $handler->display->display_options['fields']['field_address']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['rel'] = 'TEXT';
  $handler->display->display_options['fields']['field_address']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_links_1']['id'] = 'field_links_1';
  $handler->display->display_options['fields']['field_links_1']['table'] = 'field_data_field_links_1';
  $handler->display->display_options['fields']['field_links_1']['field'] = 'field_links_1';
  $handler->display->display_options['fields']['field_links_1']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['field_links_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_links_1']['alter']['text'] = '[field_links_1-url]';
  $handler->display->display_options['fields']['field_links_1']['empty'] = 'tour';
  $handler->display->display_options['fields']['field_links_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links_1']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_links_1']['settings'] = array(
    'base_formatter' => 'link_default',
  );
  $handler->display->display_options['fields']['field_links_1']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_links_1_1']['id'] = 'field_links_1_1';
  $handler->display->display_options['fields']['field_links_1_1']['table'] = 'field_data_field_links_1';
  $handler->display->display_options['fields']['field_links_1_1']['field'] = 'field_links_1';
  $handler->display->display_options['fields']['field_links_1_1']['relationship'] = 'field_location_ref_nid';
  $handler->display->display_options['fields']['field_links_1_1']['label'] = 'Venue';
  $handler->display->display_options['fields']['field_links_1_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_links_1_1']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_links_1_1']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'c';
  $handler->display->display_options['fields']['created']['timezone'] = 'America/Chicago';
  $handler->display->display_options['path'] = 'mailchimp-feeds/events';
  $export['mailchimp_feeds'] = $view;

  return $export;
}
