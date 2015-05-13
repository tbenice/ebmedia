<?php
/**
 * @file restricted_links.theme.inc
 * Theme related code for the restricted links module.
 */

/**
 * Themes the restricted links widget.
 */
function theme_restricted_widget($vars) {
  drupal_add_css(drupal_get_path('module', 'link') .'/link.css');

  $element = $vars['element'];
  // Prefix single value link fields with the name of the field.
  if (empty($element['#field']['multiple'])) {
    if (isset($element['url']) && !isset($element['title'])) {
      unset($element['url']['#title']);
    }
  }

  $output = '';
  $output .= '<div class="link-field-subrow clearfix">';
  if (isset($element['title'])) {
    $output .= '<div class="link-field-title link-field-column">'. drupal_render($element['title']) .'</div>';
  }
  $output .= '<div class="link-field-url'. (isset($element['title']) ? ' link-field-column' : '') .'">'. drupal_render($element['url']) .'</div>';
  $output .= '</div>';
  if (!empty($element['attributes']['target'])) {
    $output .= '<div class="link-attributes">'. drupal_render($element['attributes']['target']) .'</div>';
  }
  if (!empty($element['attributes']['title'])) {
    $output .= '<div class="link-attributes">'. drupal_render($element['attributes']['title']) .'</div>';
  }

  $output .= drupal_render($element['attributes']['restrictions']);
  return $output;
}

/**
 * Theme function for 'default' text field formatter.
 * Replaces theme_link_formatter_link_default() from link module.
 */
function theme_link_formatter_restricted_link_default($vars) {
  $link_options = $vars['element'];
  $field_options = $vars['field'];

  unset($link_options['attributes']['rid']);
  unset($link_options['attributes']['active_date']);
  unset($link_options['attributes']['expires']);
  unset($link_options['attributes']['expire_date']);
  // Issue #1199806 by ss81: Fixes fatal error when the link URl is equal to page URL
  if (isset($link_options['attributes']['class'])) {
    $link_options['attributes']['class'] = array($link_options['attributes']['class']);
  }
  // Display a normal link if both title and URL are available.
  if (!empty($link_options['title']) && !empty($link_options['url'])) {
    return l($link_options['title'], $link_options['url'], $link_options);
  }
  // If only a title, display the title.
  elseif (!empty($link_options['title'])) {
    return check_plain($link_options['title']);
  }
  elseif (!empty($link_options['url'])) {
    return l($link_options['title'], $link_options['url'], $link_options);
  }
}
