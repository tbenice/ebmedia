<?php
/**
 * @file
 * scout_trails.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function scout_trails_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_animation'
  $field_instances['scout_tip-scout_tip-field_scout_tip_animation'] = array(
    'bundle' => 'scout_tip',
    'default_value' => array(
      0 => array(
        'value' => 'pop',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_animation',
    'label' => 'Animation',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_button_text'
  $field_instances['scout_tip-scout_tip-field_scout_tip_button_text'] = array(
    'bundle' => 'scout_tip',
    'default_value' => array(
      0 => array(
        'value' => 'Next',
      ),
    ),
    'deleted' => 0,
    'description' => 'This text will appear on the "Next" button.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_button_text',
    'label' => '"Next" Button Text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 24,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_class'
  $field_instances['scout_tip-scout_tip-field_scout_tip_class'] = array(
    'bundle' => 'scout_tip',
    'default_value' => array(
      0 => array(
        'value' => 'custom-scout-tip',
      ),
    ),
    'deleted' => 0,
    'description' => '(optional) Add a custom CSS class for styling this scout tip.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_class',
    'label' => 'Custom Style Class',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_orientation'
  $field_instances['scout_tip-scout_tip-field_scout_tip_orientation'] = array(
    'bundle' => 'scout_tip',
    'default_value' => array(
      0 => array(
        'value' => 'bottom',
      ),
    ),
    'deleted' => 0,
    'description' => 'Where / How this tip is oriented relative to your selectors.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_orientation',
    'label' => 'Orientation',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_selector_class'
  $field_instances['scout_tip-scout_tip-field_scout_tip_selector_class'] = array(
    'bundle' => 'scout_tip',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_selector_class',
    'label' => 'Class ID (.)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_selector_id'
  $field_instances['scout_tip-scout_tip-field_scout_tip_selector_id'] = array(
    'bundle' => 'scout_tip',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_selector_id',
    'label' => 'Data ID (#)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_selector_type'
  $field_instances['scout_tip-scout_tip-field_scout_tip_selector_type'] = array(
    'bundle' => 'scout_tip',
    'default_value' => array(
      0 => array(
        'value' => 'Class ID',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_selector_type',
    'label' => 'Location Selector Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'scout_tip-scout_tip-field_scout_tip_text'
  $field_instances['scout_tip-scout_tip-field_scout_tip_text'] = array(
    'bundle' => 'scout_tip',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the main text displayed for this scout tip.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'scout_tip',
    'field_name' => 'field_scout_tip_text',
    'label' => 'Scout Tip Text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'scout_trail-scout_trail-field_scout_trail_tips'
  $field_instances['scout_trail-scout_trail-field_scout_trail_tips'] = array(
    'bundle' => 'scout_trail',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add Scout Tips for this trail.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'scout_trail',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_scout_trail_tips',
    'label' => 'Scout Tips',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'test_instance_behavior' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 1,
          'delete_references' => 0,
          'label_plural' => 'entities',
          'label_singular' => 'entity',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('"Next" Button Text');
  t('(optional) Add a custom CSS class for styling this scout tip.');
  t('Add Scout Tips for this trail.');
  t('Animation');
  t('Class ID (.)');
  t('Custom Style Class');
  t('Data ID (#)');
  t('Location Selector Type');
  t('Orientation');
  t('Scout Tip Text');
  t('Scout Tips');
  t('This is the main text displayed for this scout tip.');
  t('This text will appear on the "Next" button.');
  t('Where / How this tip is oriented relative to your selectors.');

  return $field_instances;
}
