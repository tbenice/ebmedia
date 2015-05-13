<?php
/**
 * @file
 * banner_support.node.inc
 */

/**
 * Implements hook_default_node_types_assets().
 */
function banner_support_default_node_type_assets() {
  $items = array(
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('Linked image advertising an interior page on the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}