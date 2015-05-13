<?php

/**
 * @file
 * Contextual View Modes Administrative Screens
 */

/**
 * [contextual_view_modes_settings description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function contextual_view_modes_settings_form($form, &$form_state) {

  $entity_info = entity_get_info();
  unset($entity_info['taxonomy_vocabulary']);
  unset($entity_info['comment']);

  $context_options = contextual_view_modes_get_context_options();
  $settings = variable_get('contextual_view_modes_global', array());

  $form['#attached']['css'][] = drupal_get_path('module', 'contextual_view_modes') . "/css/contextual_view_modes.admin.css";
  $form['description']['#markup'] = "";
  $d = &$form['description']['#markup'];

  $d .= "<h3>" . t("Site wide entity contextual view modes") . "</h3>";
  $d .= "<p>" . t("This form allows you to configure contextual view modes for each entity and bundle on your website. These settings are applied across all instances of the entity type.") . "</p>";
  $d .= "<p>" . t("For more information please see the !help.", array('!help' => l("help page", 'admin/help'))) . "</p>";

  foreach ($entity_info as $entity_type => $info) {

    // Define some vars.
    $delta = 0;
    $view_mode_options = contextual_view_modes_get_view_mode_options($entity_type);
    $bundles = array_keys($info['bundles']);
    $bundle_options = array('none' => '- Select a bundle -');
    $settings[$entity_type] = isset($settings[$entity_type]) ? $settings[$entity_type] : array();
    $form_state[$entity_type]['num_contexts'] = isset($form_state[$entity_type]['num_contexts']) ? $form_state[$entity_type]['num_contexts'] : count($settings[$entity_type]);

    // Create the fieldset.
    $form['entity_fieldset_' . $entity_type] = array(
      '#type' => 'fieldset',
      '#title' => $info['label'],
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
    );

    $form['entity_fieldset_' . $entity_type]['container'] = array(
      '#type' => 'container',
      '#id' => "entity-wrapper-" . $entity_type,
    );

    // Create the labels.
    foreach ($bundles as $bundle_name) {
      $bundle_options[$bundle_name] = $info['bundles'][$bundle_name]['label'];
    }

    // loop through the stuff and things. Man im lazy tonight.
    for ($delta = 0; $delta <= $form_state[$entity_type]['num_contexts']; $delta++) {

      $form['entity_fieldset_' . $entity_type]['container'][$delta]['group'] = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('inline-fields')),
      );

      $form['entity_fieldset_' . $entity_type]['container'][$delta]["group"]['bundle'] = array(
        '#type' => 'select',
        '#title' => 'Type of content',
        '#options' => $bundle_options,
        '#default_value' => isset($settings[$entity_type][$delta]['bundle']) ? $settings[$entity_type][$delta]['bundle'] : 'none',
      );

      $form['entity_fieldset_' . $entity_type]['container'][$delta]["group"]['context'] = array(
        '#type' => 'select',
        '#title' => 'Context to evaluate',
        '#options' => $context_options,
        '#default_value' => isset($settings[$entity_type][$delta]['context']) ? $settings[$entity_type][$delta]['context'] : 'none',
      );

      $form['entity_fieldset_' . $entity_type]['container'][$delta]["group"]['view_mode'] = array(
        '#type' => 'select',
        '#title' => 'View mode to display',
        '#options' => $view_mode_options,
        '#default_value' => isset($settings[$entity_type][$delta]['view_mode']) ? $settings[$entity_type][$delta]['view_mode'] : 'none',
      );

      $form['entity_fieldset_' . $entity_type]['add_nuther'] = array(
        '#type' => 'submit',
        '#value' => t('Add another'),
        '#name' => 'add-nuther-' . $entity_type,
        '#submit' => array('contextual_view_modes_settings_add_nuther'),
        '#ajax' => array(
          'callback' => 'contextual_view_modes_settings_add_nuther_callback',
          'wrapper' => "entity-wrapper-" . $entity_type,
        ),
      );
    }

  }


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * [contextual_view_modes_add_nuther_callback description]
 * @return [type] [description]
 */
function contextual_view_modes_settings_add_nuther_callback($form, $form_state) {
  $type = substr($form_state['triggering_element']['#name'], 11);
  return $form['entity_fieldset_' . $type]['container'];
}

/**
 * Submit handler for the "add-one-more" button.
 *
 * Increments the max counter and causes a rebuild.
 */
function contextual_view_modes_settings_add_nuther($form, &$form_state) {
  $type = substr($form_state['triggering_element']['#name'], 11);
  $form_state[$type]['num_contexts']++;
  $form_state['rebuild'] = TRUE;
}


/**
 * [contextual_view_modes_settings_form_submit description]
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function contextual_view_modes_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $entity_info = entity_get_info();
  $settings = array();

  foreach ($entity_info as $entity_type => $info) {

    if (!isset($values['entity_fieldset_' . $entity_type])) {
      continue;
    }

    // Lets store the values.
    foreach ($values['entity_fieldset_' . $entity_type]['container'] as $index => $group) {

      $entries = array_values($group['group']);
      $uniq = array_diff($entries, array_diff_assoc($entries, array_unique($entries)));

      // We need all three.
      if (count($uniq) !== 3) {
        continue;
      }

      // All three values available. Add to good pile.
      $settings[$entity_type][] = $group['group'];
    }

  }

  variable_set('contextual_view_modes_global', $settings);
}












