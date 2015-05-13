<?php
/**
 * @file
 * article_feed_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function article_feed_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'article_entity_importer';
  $feeds_importer->config = array(
    'name' => 'Article entity importer',
    'description' => 'import article field collections',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'news_article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['article_entity_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'article_importer';
  $feeds_importer->config = array(
    'name' => 'Article importer',
    'description' => 'for article importing',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '3',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Tags',
            'target' => 'field_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          2 => array(
            'source' => 'Images',
            'target' => 'field_article_images',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Video',
            'target' => 'field_article_video:video_url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Published date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Body',
            'target' => 'field_article_body',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'news_article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['article_importer'] = $feeds_importer;

  return $export;
}
