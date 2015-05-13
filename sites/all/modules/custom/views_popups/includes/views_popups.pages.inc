<?php
/**
 * @file views_popups.pages.inc
 * Page code for the views_popups feature.
 */


/**
 *
 * Configuration form for vpop
 * @param array $form
 * @param array $form_state
 */
function vpop_configuration_form($form, &$form_state) {
  $outer_container = variable_get('vpop_outer_container', 'inner-wrapper');
  $inner_container = variable_get('vpop_inner_container', 'content');
  $left_nudge = variable_get('vpop_left_nudge', 0);
  $top_nudge = variable_get('vpop_top_nudge', 0);
  $form = array();
  $form['vpop_outer_container'] = array(
    '#type' => 'textfield',
    '#title' => t('Views Popup Outer Container'),
    '#description' => t('Enter the selector ID of a container in your theme that is the outermost with in page flow positioning
    										(relative or static). This is commonly the innermost container inside the \'body\' tag. You can usually
    										safely leave this set to inner-wrapper (default).'),
    '#default_value' => $outer_container,
    '#field_prefix' => '#',
  );
  $form['vpop_inner_container'] = array(
    '#type' => 'textfield',
    '#title' => t('Views Popup Inner Container'),
    '#description' => t('Enter the selector ID of a container in your theme that is the innermost to where you will add popups.
    										Usually, you can safely set this to content (default).'),
    '#default_value' => $inner_container,
    '#field_prefix' => '#',
  );
  $form['vpop_left_nudge'] = array(
    '#type' => 'weight',
    '#title' => t('Left Nudge'),
    '#description' => t('Add positive or negative nudge to the left value of all popups. The amount selected will move the popup to the left relative to the target link.'),
    '#delta' => 50,
    '#field_postfix' => 'px',
    '#default_value' => $left_nudge,
  );
  $form['vpop_top_nudge'] = array(
    '#type' => 'weight',
    '#title' => t('Top Nudge'),
    '#description' => t('Add positive or negative nudge to the top value of all popups. The amount selected will move the popup down the page relative to the target link.'),
    '#delta' => 50,
    '#field_postfix' => 'px',
    '#default_value' => $top_nudge,
  );
  $form['vpop_throbber_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Throbber Path'),
    '#description' => t('Enter a drupal path to the throbber image vpop will use throughout the site.'),
    '#default_value' => (isset($form_state['values']['vpop_throbber_path'])) ? $form_state['values']['vpop_throbber_path'] : variable_get('vpop_throbber_path', drupal_get_path('module', 'views_popups') . '/images/throbber.gif'),
  );
  return system_settings_form($form);
}


/**
 *
 * special ajax callback function to return
 * a view display
 */
function views_popups_callback() {

  //pull args from the path
  /*$args = explode('/', $_GET['q']);
  array_shift($args);
  $name = array_shift($args);*/
  if ((!isset($_GET['vid'])) || (!isset($_GET['did']))) {
    drupal_set_message("The views popups get parameters are not set correctly", 'error');
    return "";
  }
  $name = filter_xss($_GET['vid']);
  $display_id = filter_xss($_GET['did']);

  /*
   *code modified from views_embed_view
   *using this to allow passing arg to the
   *display as an array
   */
  //get the get params as needed for views args
  $new_args = array();
  // Filter_xss is meanted for stripping html strings, not get param arrays - this breaks local
  //$args = filter_xss($_GET);
  $args = $_GET;
  unset($args['vid'], $args['did'], $args['q'], $args['fade_id']);
  foreach($args as $arg){
    $arg = filter_xss($arg);
    if (!empty($arg)) {
      $new_args[] = $arg = filter_xss($arg);
    }
  }

  //load the view from vid
  $view = views_get_view($name);
  if (!$view || !$view->access($display_id)) {
    drupal_set_message("The view specified in the views popups vid does is faulty", 'error');
    return "";
  }

  $html = ($view->preview($display_id, $new_args));

  $javascript = drupal_add_js(NULL, NULL);
  $settings = FALSE;

  if (isset($javascript['settings']))
  {
    $settings = '<script type="text/javascript">jQuery.extend(Drupal.settings, ' .
      drupal_json_encode(call_user_func_array('array_merge_recursive', $javascript['settings']['data'])) .
      ');</script>';
  }

  //Add the settings to the form
  $html .= $settings;

  //return the view html
  echo $html;
}
