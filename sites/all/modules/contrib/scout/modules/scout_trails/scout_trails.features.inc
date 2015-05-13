<?php
/**
 * @file
 * scout_trails.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scout_trails_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scout_trails_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_scout_tip_type().
 */
function scout_trails_default_scout_tip_type() {
  $items = array();
  $items['scout_tip'] = entity_import('scout_tip_type', '{
    "type" : "scout_tip",
    "label" : "Scout Tip",
    "weight" : 0,
    "description" : "The default Scout Tip type."
  }');
  return $items;
}

/**
 * Implements hook_default_scout_trail_type().
 */
function scout_trails_default_scout_trail_type() {
  $items = array();
  $items['scout_trail'] = entity_import('scout_trail_type', '{
    "type" : "scout_trail",
    "label" : "Scout Trail",
    "weight" : 0,
    "description" : "The default Scout Trail type."
  }');
  return $items;
}
