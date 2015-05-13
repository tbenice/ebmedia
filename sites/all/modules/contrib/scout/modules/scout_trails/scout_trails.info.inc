<?php

/**
 * @file
 * Provides metadata for the line item entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function scout_trails_entity_property_info() {
  $info = array();

  // Add meta-data about the basic scout trail properties.
  $properties = &$info['scout_trail']['properties'];

  $properties['trail_id'] = array(
    'label' => t('Trail ID'),
    'description' => t('The internal numeric ID of the trail.'),
    'type' => 'integer',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'trail_id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The human readable name of the scout trail type.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['language'] = array(
    'label' => t('Language'),
    'type' => 'token',
    'description' => t("The language the node is written in."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'options list' => 'entity_metadata_language_list',
    'schema field' => 'language',
    'setter permission' => 'admin scout trails',
  );
  $properties['title'] = array(
    'label' => t('Trail Name'),
    'description' => t('The trail name displayed for this trail.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'title',
  );
  $properties['description'] = array(
    'label' => t('Trail Description'),
    'description' => t('A decription of this scout trail, for admin purposes.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'description',
  );
  $properties['uid'] = array(
    'label' => t('Scout (author)'),
    'type' => 'integer',
    'description' => t('The author of this trail'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'uid',
  );
  $properties['tag'] = array(
    'label' => t("Tag"),
    'description' => t("An optional tag used to group/sort scout trails in the admin interface."),
    // Although the status is expected to be boolean, its schema suggests
    // it is an integer, so we follow the schema definition.
     'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'schema field' => 'tag',
  );
  $properties['created'] = array(
    'label' => t("Date created"),
    'type' => 'date',
    'description' => t("The date the scout trail was posted."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t("Date changed"),
    'type' => 'date',
    'schema field' => 'changed',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'description' => t("The date the scout trail was most recently updated."),
  );
  $properties['status'] = array(
    'label' => t("Export Status"),
    'description' => t("Whether the scout trail has been exported."),
    'type' => 'integer',
    'schema field' => 'status',
  );

  // Add meta-data about the basic scout tip properties.
  $properties = &$info['scout_tip']['properties'];

  $properties['tip_id'] = array(
    'label' => t('scout tip ID'),
    'description' => t('The internal numeric ID of the scout tip.'),
    'type' => 'integer',
    'required' => TRUE,
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'schema field' => 'tip_id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The human readable name of the scout tip type.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['language'] = array(
    'label' => t('Language'),
    'type' => 'token',
    'description' => t("The language the scout tip is written in."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'options list' => 'entity_metadata_language_list',
    'schema field' => 'language',
  );
  $properties['title'] = array(
    'label' => t('scout tip Title'),
    'description' => t('The title displayed for this scout tip.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => TRUE,
    'schema field' => 'title',
  );
  $properties['uid'] = array(
    'label' => t('Scout (author)'),
    'type' => 'integer',
    'description' => t('The author of this scout tip'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'required' => true,
    'schema field' => 'uid',
  );
  $properties['tag'] = array(
    'label' => t("Tag"),
    'description' => t("An optional tag used to group/sort scout tips in the admin interface."),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'schema field' => 'tag',
  );
  $properties['created'] = array(
    'label' => t("Date created"),
    'type' => 'date',
    'description' => t("The date the scout tip was posted."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t("Date changed"),
    'type' => 'date',
    'schema field' => 'changed',
    'description' => t("The date the scout tip was most recently updated."),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'admin scout trails',
  );
  $properties['status'] = array(
    'label' => t("Export Status"),
    'description' => t("Whether the scout tip has been exported."),
    'type' => 'integer',
    'schema field' => 'status',
  );

//  dsm($info, '$info');
  return $info;
}

/**
 * Implements hook_entity_property_info_alter() on top of the Line Item module.
 */
/*
function scout_entity_property_info_alter(&$info) {
}
*/
