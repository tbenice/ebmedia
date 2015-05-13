<?php
/**
 * @file common_support.theme.inc
 */

/**
 * Get a block suitable for rendering.
 * Note: the block does not have to be enabled in $region.
 *
 * @return renderable array for a block
 *
 * @see includes/block.module/_block_render_blocks()
 * @see includes/block.module/_block_get_renderable_array()
 */
function _embed_block($module, $delta) {
  // Create block renderable array.
  return _block_get_renderable_array(_block_render_blocks(array(block_load($module, $delta))));
}

/**
 * theme function returns share links for
 * print, email, twitter, facebook, gplus
 * @param array $vars
 */
function theme_share_links($vars) {
  // See if there is a node to load.
  if (isset($vars['nid'])) {
    $node = node_load($vars['nid']);
    // If the node was created < 60sec ago, ask fb to scrape it.
    $post_time = time() - $node->created;
    if (($post_time <= 60) || ($vars['fb_scrape'])) {
      common_support_order_fb_scrape("node/$node->nid");
    }
  }
  $content = theme('common_support_addthis', array('url' => $vars['link_href']));
  return $content;
}

/**
 * Theme function to add the addthis wrapper.
 */
function theme_common_support_addthis($vars) {
  if (isset($vars['url'])) {
    $content = '<div class="addthis_sharing_toolbox" data-url="' . $vars['url'] . '"></div>';
  }
  else {
    $content = '<div class="addthis_sharing_toolbox"></div>';
  }
  return $content;
}

/**
 * theme funciton returns a 'more link' that will show/hide
 * it's parent with a 'item-hide' class
 * also the parent 'item-hide' element must have a height set
 * and overflow-hidden in css to work
 * @param array $vars
 */
function theme_show_hide_more_link($vars) {
  $content = '<div class="show-hide-link-wrapper">' . l(t($vars['more_text']), current_path(), array('query'=>array('moreText'=>t($vars['more_text']), 'lessText'=>t($vars['less_text']), 'height' => $vars['height']),
    'attributes'=>array('class'=>array('show-link', 'button')))) . '</div>';
  return $content;
}

/**
 * theme function formats a show-hide element + link
 * around a given element
 * @param array $vars
 *   $vars['element'] = the element to format
 *   $vars['height'] = the height that the element should be before
 *     show more. If not specified, no height will be put on the element.
 *     Format: integer, no 'px'...it will be added.
 *   $vars['link_text'] = the link html
 *     default = "Show More"
 *   $vars['more_text'] = the link html after show less has been activated
 *     default = "Show More"
 *   $vars['less_text'] = the link html after the show more has been activated
 *     default = "Show Less"
 */
function theme_show_hide($vars) {
  if (isset($vars['element'])) {
    $style = (isset($vars['height'])) ? 'style="height: ' . $vars['height'] . 'px;"' : '';
    return '<div class="item-hide" ' . $style . '><div style="height:auto; position:relative;">' . $vars['element'] . '</div></div>' . theme('show_hide_more_link', array('more_text' => $vars['more_text'],
      'less_text' => $vars['less_text'], 'height' => $vars['height']));
  }
}

/**
 * Theme function returns html wrapped in a title.
 * Enter description here ...
 * @param unknown_type $vars
 */
function theme_block_wrapper($vars) {
  if (!isset($vars['data'])) {
    return NULL;
  }
  if ((is_array($vars['data'])) && (empty($vars['data']))) {
    return NULL;
  }
  $title = (isset($vars['title'])) ? '<h2 class="block-title">' . $vars['title'] . '</h2>' : '';
  return $title . render($vars['data']);
}

/**
 * Theme function returns a view display html.
 *
 * @param array $vars
 *   Array of key value pairs in the format:
 *     'view' => the view machine id,
 *     'display' => the view display machine id
 *     'args' => an array of arguments to pass to the view.
 *
 * @return string
 *   The markup for the view if any including the title.
 */
function theme_view_embed($vars) {
  $result = null;
  if ($view = views_get_view($vars['view'])) {
    $view->set_display($vars['display']);
    global $user;
    if ($view->access($vars['display'], $user)) {
      $data = $view->preview($vars['display'], $vars['args']);
      $result = theme('block_wrapper', array('title' => $view->get_title(), 'data' => $data));
    }
  }
  return $result;
}

/**
 * Theme function to embed a block.
 *
 * @param array $vars
 */
function theme_embed_block($vars) {
  $result = '';
  if (isset($vars['module']) && isset($vars['delta'])) {
    $result = _embed_block($vars['module'], $vars['delta']); //@todo get embed block.
    return render($result);
  }
}

/**
 * Preprocess variables for the page not found page.
 */
function template_preprocess_common_support_404_page(&$vars) {
  $headline = variable_get('common_support_404_headline', array('value' => common_support_default_404_page_headline(), 'format' => 'filtered_html'));
  $vars['content']['headline'] = array(
    '#markup' => $headline['value'],
  );
  $body = variable_get('common_support_404_body', array('value' => common_support_default_404_page_body()));
  $vars['content']['body'] = array(
    '#markup' => $body['value'],
  );
}
