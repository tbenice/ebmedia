<?php
/**
 * @file
 * get_export.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function get_export_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__banner';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'teaser2' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'teaser3' => array(
        'custom_settings' => FALSE,
      ),
      'teaser4' => array(
        'custom_settings' => FALSE,
      ),
      'teaser5' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'share_links' => array(
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser2' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__banner'] = $strongarm;

  return $export;
}
