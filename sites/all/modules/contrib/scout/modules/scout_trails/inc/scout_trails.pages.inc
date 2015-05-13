<?php

/**
 * Scout view callback.
 */
function scout_trail_view($scout_trail) {
  drupal_set_title(entity_label('scout_trail', $scout_trail));
  return entity_view('scout_trail', array(entity_id('scout_trail', $scout_trail) => $scout_trail), 'full');
}

/**
 * Page to select Scout Trail Type to add new scout trail.
 */
function scout_trail_add_page() {
  $trails = array();
  foreach (scout_trail_types() as $scout_trail_type_key => $scout_trail_type) {
    $trails[] = l(entity_label('scout_trail_type', $scout_trail_type), 'admin/content/scout-trails/add/' . $scout_trail_type_key);
  }
  if (count($trails) == 1) {
    drupal_goto('admin/content/scout-trails/add/' . $scout_trail_type_key);
  }

  if ($trails) {
    return array('list' => array('#theme' => 'item_list', '#items' => $trails, '#title' => t('Select a type of scout trail to create.')));
  }
  else {
    return array('list' => array('#theme' => 'item_list', '#items' => $trails, '#title' => t('You must first <a href="@create-content">define a scout trail type.</a>', array('@create-content' => url('admin/structure/scout/scout-trail-types/add')))));
  }
}

/**
 * Page to select Scout Tip Type to add new scout tip.
 */
function scout_tip_admin_add_page() {
//  $scout_trails_uri = 'admin/config/user-interface/scout-tours/';
  $items = array();
  foreach (scout_tip_types() as $scout_tip_type_key => $scout_tip_type) {
    $items[] = l(entity_label('scout_tip_type', $scout_tip_type), 'admin/content/scout-trails/scout-tips/add/' . $scout_tip_type_key);
  }
  if (count($items) == 1) {
    drupal_goto('admin/content/scout-trails/scout-tips/add/' . $scout_tip_type_key);
  }

  if ($items) {
    return array('list' => array('#theme' => 'item_list', '#items' => $items, '#title' => t('Select a type of scout tip to create.')));
  }
  else {
    return array('list' => array('#theme' => 'item_list', '#items' => $items, '#title' => t('You must first <a href="@create-content">define a scout tip type.</a>', array('@create-content' => url('admin/structure/scout/scout-tip-types/add')))));
  }

}
