<?php

class scout_context_reaction_trail extends context_reaction {
  function options_form($context) {

    //Populate existing trails options for trail content selection
    $query = db_select('scout_trail', 'r')->extend('PagerDefault');
    $query
      ->fields('r', array('trail_id'))
      ->condition('r.status', 0, '<>')
      ->orderBy('r.title', 'ASC');

    $trail_ids = $query
//      ->limit(100)
      ->execute()
      ->fetchCol();

    $type = array();
    $scout_trails = scout_trail_load_multiple($trail_ids, $type);

    $trail_options = array();
    foreach($scout_trails as $key) {
      // Need a better way to find field we are looking for based on type.
      // This need started when I made it possible to create new types on the fly.
      if ($key->type == 'scout_trail') $tips = count($key->field_scout_trail_tips['und']);

//      $trail_options[$key->trail_id] = t($key->title . ' (a ' . $key->type . ' trail with ' . format_plural($tips, '1 tip', '@count tips') . ')');
      $trail_options[$key->trail_id] = t($key->title . ' (a Scout trail with ' . format_plural($tips, '1 Scout tip', '@count Scout tips') . ')');
    }

    $context_values = $this->fetch_from_context($context, 'values');

    return array(
      'trail_auto_start' => array(
        '#type' => 'checkbox',
        '#title' => t('Start scout trail automatically'),
        '#description' => t('Starts a Scout Trail on page load. If you disable this be sure to add a <em>Scout: Trailhead</em> block on this page.'),
        '#default_value' => isset($context_values['trail_auto_start']) ? $context_values['trail_auto_start'] : FALSE,
      ),
      'trail_play_once' => array(
        '#type' => 'checkbox',
        '#title' => t('Play trail only once'),
        '#description' => t('Check this to play the trail only once'),
        '#default_value' => isset($context_values['trail_play_once']) ? $context_values['trail_play_once'] : FALSE,
        '#states' => array(
          'visible' => array(
            ':input[type="checkbox"]#edit-reactions-plugins-scout-add-trail-auto-start' => array(
              'checked' => TRUE,
            )
          ),
        ),
      ),
      'trail_content' => array(
        '#title' => t('Scout Trails'),
        '#description' => t('Select a Scout Trail to appear when matching above conditions.'),
        '#type' => 'select',
        '#options' => $trail_options,
        '#default_value' => isset($context_values['trail_content']) ? $context_values['trail_content'] : NULL,
      ),
    );
  }

  function options_form_submit($values) {
    if(!isset($values['trail_play_once'])) $values['trail_play_once'] = FALSE;
    $values['trail_play_once'] = empty($values['trail_auto_start']) ? FALSE : $values['trail_play_once'];
    return $values;
  }

  function execute(&$vars = NULL) {
    $contexts = $this->get_contexts();

    // We need the Zurb Joyride library for any of this to work
    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        $library = libraries_load('joyride');
        $library_loaded = $library && !empty($library['loaded']);

        drupal_add_library('system', 'jquery.cookie');

        $js_name = 'jquery.joyride.js';
        $base_path = 'sites/all/libraries/joyride';

        if (!$library_loaded) {
          drupal_set_message(t('Can\'t load Joyride library. Please download !url jQuery plugin and extract it to @path, so @js can be found at @full_path.', array(
            '!url' => l(t('Zurb Joyride'), 'https://github.com/zurb/joyride'),
            '@path' => $base_path,
            '@js' => $js_name,
            '@full_path' => $base_path . '/' . $js_name,
          )), 'error');
          return FALSE;
        }
        drupal_add_js(drupal_get_path('module', 'scout') . '/inc/js/scout_trail_context.js');
        $customCss = drupal_add_css(drupal_get_path('module', 'scout') . '/inc/css/scout-' . JOYRIDE_LIBRARY_VERSION . '.css');

        // Trail content consists of a scout_trail entity pointing to one or more scout_tip entities
        $trail_content = $context->reactions[$this->plugin]['trail_content'];
        if(empty($trail_content)) return FALSE;

        // Here we collect the scout_tip entities from the scout_trail entity,
        // to begin formatting the trail content.
        $scout_trail = scout_trail_load($trail_content,FALSE);

//        if ($scout_trail->type == 'scout_trail') $scout_tips = $scout_trail->field_scout_trail_tips['und'];
//        if ($scout_trail->type == 'cub_scout') $scout_tips = $scout_trail->field_scout_trail_tips['und'];
        $scout_tips = $scout_trail->field_scout_trail_tips['und'];
        //dpm($scout_tips,'$scout_tips');

        $scout_tip_content = array();

        // Get each scout tip tip_id and load it
        foreach ($scout_tips as $key) {
	        $scout_tip_content[] = scout_tip_load($key['target_id'], FALSE);
        }
        // Preprocess trail stops into (html) trail content for theming and Joyride library jquery
        $trail_content = scout_trails_markup_scout_trail($scout_tip_content);

        // Build the jquery settings with our completed content and context settings.
        $js_settings = array(
          'scoutContext' => array(
            'trail_content' => theme('scout_trail', array('trail_content' => $trail_content)),
            'auto_start' => (boolean)$context->reactions[$this->plugin]['trail_auto_start'],
            'play_once' => (boolean)$context->reactions[$this->plugin]['trail_play_once'],
          ),
        );
        //dpm($js_settings,'$js_settings - after set');
        drupal_add_js($js_settings, 'setting');
      }
    }
  }
}