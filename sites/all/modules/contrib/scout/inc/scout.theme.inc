<?php

function scout_preprocess_scout_trailhead(&$vars) {
  if(empty($vars['options'])) $vars['options'] = array();

  if(!isset($vars['options']['attributes']['class'])) $vars['options']['attributes']['class'] = array();
  $vars['options']['attributes']['class'][] = 'scout_trailhead';

  $vars['options']['external'] = TRUE;

  if(empty($vars['link_title'])) $vars['link_title'] = t('Tour this page.');

  drupal_add_js(drupal_get_path('module', 'scout') . '/inc/js/scout_trailhead.js');
  
//  dsm($vars, '$vars OUT');

}