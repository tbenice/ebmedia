<?php
/**
 * @file
 * scout_pak.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function scout_pak_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fast_track_scout_tip_create';
  $context->description = 'Shows how to create Scout Tips (autostart)';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips/1/edit/fast-track*' => 'admin/content/scout-trails/scout-tips/1/edit/fast-track*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '1',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to create Scout Tips (autostart)');
  $export['fast_track_scout_tip_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fast_track_scout_trail_create';
  $context->description = 'Shows how to create Scout Trails (autostart)';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/add/scout_trail/fast-track' => 'admin/content/scout-trails/add/scout_trail/fast-track',
        'admin/content/scout-trails/6/edit/fast-track' => 'admin/content/scout-trails/6/edit/fast-track',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '6',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to create Scout Trails (autostart)');
  $export['fast_track_scout_trail_create'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'first_time_scout';
  $context->description = 'After new install, this points administrator to help info';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/*' => 'admin/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 1,
      'trail_content' => '8',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('After new install, this points administrator to help info');
  t('Scout Pak');
  $export['first_time_scout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_context_trick';
  $context->description = 'Shows how to auto start Scout Trails with Fake URLs';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/context-trick' => 'admin/content/context-trick',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '12',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to auto start Scout Trails with Fake URLs');
  $export['scout_context_trick'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_tip_create';
  $context->description = 'Shows how to create Scout Tips';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips/*/edit' => 'admin/content/scout-trails/scout-tips/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '1',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to create Scout Tips');
  $export['scout_tip_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_tips_list';
  $context->description = 'Navigation Scout Tip Admin';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/scout-tips' => 'admin/content/scout-trails/scout-tips',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '4',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation Scout Tip Admin');
  t('Scout Pak');
  $export['scout_tips_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trail_context';
  $context->description = 'Shows how to add Scout Trails to a page';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/structure/context/list/scout_trail_context/edit' => 'admin/structure/context/list/scout_trail_context/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '7',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to add Scout Trails to a page');
  $export['scout_trail_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trail_create';
  $context->description = 'Shows how to create Scout Trails';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails/add/scout_trail' => 'admin/content/scout-trails/add/scout_trail',
        'admin/content/scout-trails/*/edit' => 'admin/content/scout-trails/*/edit',
        '~admin/content/scout-trails/scout-tips/*/edit' => '~admin/content/scout-trails/scout-tips/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '6',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Scout Pak');
  t('Shows how to create Scout Trails');
  $export['scout_trail_create'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trails_help_page';
  $context->description = 'One stop scout trail on Scout Trails help page';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/help/scout' => 'admin/help/scout',
        'admin/help/scout_trails' => 'admin/help/scout_trails',
      ),
    ),
  );
  $context->reactions = array(
    'scout_trail' => array(
      'trail_auto_start' => 1,
      'trail_play_once' => 0,
      'trail_content' => '13',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('One stop scout trail on Scout Trails help page');
  t('Scout Pak');
  $export['scout_trails_help_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scout_trails_list';
  $context->description = 'Navigation Scout Trail Admin';
  $context->tag = 'Scout Pak';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/content/scout-trails' => 'admin/content/scout-trails',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'scout-scout_trailhead' => array(
          'module' => 'scout',
          'delta' => 'scout_trailhead',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
    'scout_trail' => array(
      'trail_auto_start' => 0,
      'trail_play_once' => FALSE,
      'trail_content' => '5',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation Scout Trail Admin');
  t('Scout Pak');
  $export['scout_trails_list'] = $context;

  return $export;
}
