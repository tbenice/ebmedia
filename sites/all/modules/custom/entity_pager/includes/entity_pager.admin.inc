<?php
/**
 * @file entity_pager.admin.inc
 * Admin form code for the entity pager module.
 */

/**
 * System settings form for the entity_pager,
 *
 * @param array $form_state
 */
function entity_pager_config_form($form, &$form_state) {
  $form['entity_pager_num_blocks'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Blocks'),
    '#description' => t('Enter the number of entity pager blocks to create. NOTE: If you decrease the number you will lose some blocks!'),
    '#default_value' => isset($form_state['values']['entity_pager_num_blocks']) ? $form_state['values']['entity_pager_num_blocks'] : variable_get('entity_pager_num_blocks', 1),
  );
  return system_settings_form($form);
}
