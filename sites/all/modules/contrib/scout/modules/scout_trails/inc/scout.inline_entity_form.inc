<?php

/**
 * @file
 * Defines the inline entity form controller for Scout Tips (in Scout Trails).
 */

class ScoutInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::tableFields().
   */
  public function tableFields($bundles) {
    $info = entity_get_info($this->entityType);
    $metadata = entity_get_property_info($this->entityType);

    $fields = array();
    $id_key = $info['entity keys']['id'];
    $fields[$id_key] = array(
      'type' => 'property',
      'label' => $metadata ? $metadata['properties'][$id_key]['label'] : t('ID'),
      'weight' => 1,
    );
    $label_key = $info['entity keys']['label'];
    $fields[$label_key] = array(
      'type' => 'property',
      'label' => $metadata ? $metadata['properties'][$label_key]['label'] : t('Label'),
      'weight' => 1,
    );
    if (count($bundles) > 1) {
      $bundle_key = $info['entity keys']['bundle'];
      $fields[$bundle_key] = array(
        'type' => 'property',
        'label' => $metadata ? $metadata['properties'][$bundle_key]['label'] : t('Type'),
        'weight' => 2,
      );
    }
    return $fields;
  }


  /**
   * Overrides EntityInlineEntityFormController::entityForm().
   */
  public function entityForm($entity_form, &$form_state) {
    $info = entity_get_info($this->entityType);
    $entity = $entity_form['#entity'];

    $entity_form['scout_tip'] = array(
      '#type' => 'fieldset',
      '#title' => t('Scout - Create a Scout Tip'),
      '#description' => t('Scout tips consist of text content, page location and theming info.'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $entity_form['scout_tip']['title'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Scout Tip Label'),
      '#description' => t('Displays as title in a Scout Tip.'),
      '#default_value' => $entity->title,
    );
    $entity_form['scout_tip']['tag'] = array(
      '#type' => 'textfield',
      '#required' => FALSE,
      '#title' => t('Tag'),
      '#description' => t('Optional tag for organizing / grouping tips in admin view.'),
      '#default_value' => $entity->tag,
      '#autocomplete_path' => 'admin/content/scout-trails/scout-tips/ajax/tag',
    );

//    $langcode = entity_language('scout_tip', $entity);
    if (!empty($info['fieldable'])) {
      $langcode = entity_language($this->entityType, $entity);
      field_attach_form($this->entityType, $entity, $entity_form, $form_state, $langcode);
    }

    return $entity_form;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityFormSubmit().
   */
  public function entityFormSubmit(&$entity_form, &$form_state) {
    parent::entityFormSubmit($entity_form, $form_state);

    $entity = $entity_form['#entity'];
    $entity_values = drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);
    $entity->title = $entity_values['scout_tip']['title'];
    $entity->tag = $entity_values['scout_tip']['tag'];
    $entity->changed = REQUEST_TIME;
    $parent = $form_state['trail'];
    $info = entity_get_info($this->entityType);

    if ($info['fieldable']) {
      field_attach_submit($this->entityType, $entity, $entity_form, $form_state);
    }
    // Determine if new trail or update
    $update_trail = TRUE ? (isset($parent->trail_id)) : FALSE;
    // Determine if new tip or update
    $update_tip = TRUE ? (isset($entity->tip_id)) : FALSE;

    if ((!$update_tip) && (!$update_trail)){
	    // New Tip in a New Trail
	    watchdog('scout_trail', 'Created new inline scout tip "%title" in a new trail.', array('%title' => $entity->title));
      drupal_set_message(t('Scout Tip "%title" has been created inline in a new trail.', array('%title' => $entity->title)));
    }
    elseif ((!$update_tip) && $update_trail) {
      // New Tip in Updated Trail
	    watchdog('scout_trail', 'Created new inline scout tip "%title" in trail "%trail".', array('%title' => $entity->title,'%trail' => $form_state['trail']->title));
      drupal_set_message(t('Scout Tip "%title" has been created inline in trail "%trail".', array('%title' => $entity->title,'%trail' => $form_state['trail']->title)));
    }
    elseif ($update_tip && (!$update_trail)){
      // Edited Tip in New Trail
	    watchdog('scout_trail', 'Updated inline scout tip "%title" in a new trail.', array('%title' => $entity->title));
      drupal_set_message(t('Scout Tip "%title" has been updated inline in a new trail.', array('%title' => $entity->title)));
    } else {
        // Edited Tip in Edited Trail
	      watchdog('scout_trail', 'Updated inline scout tip "%title" in trail "%trail".', array('%title' => $entity->title,'%trail' => $form_state['trail']->title));
        drupal_set_message(t('Scout Tip "%title" has been updated inline in trail "%trail".', array('%title' => $entity->title,'%trail' => $form_state['trail']->title)));
    }
  }
}
