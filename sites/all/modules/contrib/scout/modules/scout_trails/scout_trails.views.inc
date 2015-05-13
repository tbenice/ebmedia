<?php

/**
 * Implements hook_views_data_alter().
 */
function scout_trails_views_data_alter(&$data) {

/*
$data['scout_trail']['table']['group'] = t('Scout Trails');
$data['scout_trail']['table']['base'] = array(
  'field' => 'trail_id', // This is the identifier field for the view.
  'title' => t('Scout Trails'),
  'help' => t('Scout Trails table contains trails.'),
  'weight' => -10,
  );

$data['scout_tip']['table']['group'] = t('Scout Tips');
$data['scout_tip']['table']['base'] = array(
  'field' => 'tip_id', // This is the identifier field for the view.
  'title' => t('Scout Tips'),
  'help' => t('Scout Tips table contains collections of tips related to trails.'),
  'weight' => -10,
  );
*/

  $data['scout_tip']['table']['join'] = array(

    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'scout_trail' => array(
      'left_field' => 'trail_id',
      'field' => 'trail_id',
    ),
  );

  // This example adds a relationship to table {foo}, so that 'foo' views can
  // add this table using a relationship. Because we don't want to write over
  // the primary key field definition for the {foo}.fid field, we use a dummy
  // field name as the key.
  $data['scout_trail']['parent_trail'] = array(
    'title' => t('Scout Trails relationship'),
    'help' => t('Scout Tips help'),
    'relationship' => array(
      'base' => 'scout_trail', // Table we're joining to.
      'base field' => 'trail_id', // Field on the joined table.
      'field' => 'trail_id', // Real field name on the 'foo' table.
      'handler' => 'views_handler_relationship',
      'label' => t('Trail ID'),
      'title' => t('Parent Trail ID'),
      'help' => t('A link to a Scout Tip\'s parent Scout Trail'),
    ),
  );

  $data['scout_trail']['Trail Scout'] = array(
    'title' => t('Scout Trails user relationship'),
    'help' => t('Scout Trail help'),
    'relationship' => array(
      'base' => 'users', // Table we're joining to.
      'base field' => 'uid', // Field on the joined table.
      'field' => 'uid', // Real field name on the 'foo' table.
      'handler' => 'views_handler_relationship',
      'label' => t('Trail Scout'),
      'title' => t('User that created this Scout Trail'),
      'help' => t('A link to the user that created a Scout Trail.'),
    ),
  );

  $data['scout_tip']['Tip Scout'] = array(
    'title' => t('Scout Tips user relationship'),
    'help' => t('Scout Tips help'),
    'relationship' => array(
      'base' => 'users', // Table we're joining to.
      'base field' => 'uid', // Field on the joined table.
      'field' => 'uid', // Real field name on the 'foo' table.
      'handler' => 'views_handler_relationship',
      'label' => t('Scout Tip Scout'),
      'title' => t('User that created this Scout Tip'),
      'help' => t('A link to the user that created a Scout Tip.'),
    ),
  );
}

