<?php
/**
 * @file colorbox_content.pages.inc
 * Page code for colorbox_content module.
 */


/**
 * Callback to load content into a colorbox.
 */
function colorbox_content_load() {
  $type = filter_xss($_GET['type']);
  if (!isset($type)) {
    return FALSE;
  }
  $return = array();
  switch($type) {
    case 'block' :
      $module = filter_xss($_GET['module']);
      $delta = filter_xss($_GET['delta']);
      if ((!isset($module)) || (!isset($delta))) {
        return FALSE;
      }
      $return['markup'] = render(_block_get_renderable_array(_block_render_blocks(array(block_load($module, $delta)))));
      break;

    case 'node':
      $node = node_load(filter_xss($_GET['node']));
      $view_mode = filter_xss($_GET['view_mode']);
      $langcode = (!isset($_GET['langcode'])) ? 'en' : $_GET['langcode'];
      if ((!isset($node)) || (!isset($view_mode)) || (!isset($langcode))) {
        return FALSE;
      }
      $return['markup'] = drupal_render(node_view($node, $view_mode, $langcode));
      break;

    case 'view':
      $view = filter_xss($_GET['view']);
      $display = filter_xss($_GET['display']);
      $args = filter_xss($_GET);
      unset($args['q'], $args['type'], $args['view'], $args['display']);
      $newargs = array();
      foreach($args as $arg) {
        $newargs[] = $arg;
      }
      $view = views_get_view($view);
      $return['markup'] = $view->preview($display, $newargs);
      break;

  }
  echo $return['markup'];
}
