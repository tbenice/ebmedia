<?php
/**
 * @file articles_support.node_type.inc
 */

/**
 * Implements hook_default_node_type_assets().
 */
function articles_support_default_node_type_assets() {
  $items = array(
    'news_article' => array(
      'name' => t('News Article'),
      'base' => 'node_content',
      'description' => t('A news item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
