<?php
/**
 * @file
 * scout_trails.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function scout_trails_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scout_tip_content|scout_tip|scout_tip|form';
  $field_group->group_name = 'group_scout_tip_content';
  $field_group->entity_type = 'scout_tip';
  $field_group->bundle = 'scout_tip';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scout_tip_vtab';
  $field_group->data = array(
    'label' => 'Scout Tip Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_scout_tip_button_text',
      1 => 'field_scout_tip_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_scout_tip_content|scout_tip|scout_tip|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scout_tip_location|scout_tip|scout_tip|form';
  $field_group->group_name = 'group_scout_tip_location';
  $field_group->entity_type = 'scout_tip';
  $field_group->bundle = 'scout_tip';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scout_tip_vtab';
  $field_group->data = array(
    'label' => 'Scout Tip Location Attribute',
    'weight' => '2',
    'children' => array(
      0 => 'field_scout_tip_selector_type',
      1 => 'group_scout_tip_selectors',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_scout_tip_location|scout_tip|scout_tip|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scout_tip_options|scout_tip|scout_tip|form';
  $field_group->group_name = 'group_scout_tip_options';
  $field_group->entity_type = 'scout_tip';
  $field_group->bundle = 'scout_tip';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scout_tip_vtab';
  $field_group->data = array(
    'label' => 'Scout Tip Options',
    'weight' => '3',
    'children' => array(
      0 => 'field_scout_tip_class',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_scout_tip_options|scout_tip|scout_tip|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scout_tip_selectors|scout_tip|scout_tip|form';
  $field_group->group_name = 'group_scout_tip_selectors';
  $field_group->entity_type = 'scout_tip';
  $field_group->bundle = 'scout_tip';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_scout_tip_location';
  $field_group->data = array(
    'label' => 'Scout Tip Selectors',
    'weight' => '21',
    'children' => array(
      0 => 'field_scout_tip_animation',
      1 => 'field_scout_tip_orientation',
      2 => 'field_scout_tip_selector_class',
      3 => 'field_scout_tip_selector_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Scout Tip Selectors',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Scout tips, unless modal, must be anchored to Data or Class ID selector on the page they are to appear on.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_scout_tip_selectors|scout_tip|scout_tip|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scout_tip_vtab|scout_tip|scout_tip|form';
  $field_group->group_name = 'group_scout_tip_vtab';
  $field_group->entity_type = 'scout_tip';
  $field_group->bundle = 'scout_tip';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scout Tip Vtab',
    'weight' => '0',
    'children' => array(
      0 => 'group_scout_tip_content',
      1 => 'group_scout_tip_location',
      2 => 'group_scout_tip_options',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_scout_tip_vtab|scout_tip|scout_tip|form'] = $field_group;

  return $export;
}
