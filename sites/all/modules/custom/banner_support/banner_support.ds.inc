<?php
/**
 * @file
 * banner_support.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function banner_support_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'linked_image' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|banner|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|banner|teaser2';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'banner';
  $ds_fieldsetting->view_mode = 'teaser2';
  $ds_fieldsetting->settings = array(
    'linked_banner_image' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|banner|teaser2'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function banner_support_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'linked_image';
  $ds_field->label = 'Linked Image';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'banner|*';
  $ds_field->properties = array();
  $export['linked_image'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function banner_support_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_banner_image',
        1 => 'field_banner_link',
        2 => 'field_banner_body',
      ),
    ),
    'fields' => array(
      'field_banner_image' => 'ds_content',
      'field_banner_link' => 'ds_content',
      'field_banner_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|banner|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'linked_image',
      ),
    ),
    'fields' => array(
      'linked_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|banner|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|banner|teaser2';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'banner';
  $ds_layout->view_mode = 'teaser2';
  $ds_layout->layout = 'banner_with_body1';
  $ds_layout->settings = array(
    'regions' => array(
      'row1' => array(
        0 => 'field_banner_image',
        1 => 'linked_banner_image',
      ),
      'row2' => array(
        2 => 'title',
        3 => 'field_banner_body',
        4 => 'field_banner_link',
      ),
    ),
    'fields' => array(
      'field_banner_image' => 'row1',
      'linked_banner_image' => 'row1',
      'title' => 'row2',
      'field_banner_body' => 'row2',
      'field_banner_link' => 'row2',
    ),
    'classes' => array(),
    'wrappers' => array(
      'row1' => 'div',
      'row2' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|banner|teaser2'] = $ds_layout;

  return $export;
}
