<?php
/**
 * @file
 * campaign_api.rules.inc
 */

/**
 * Rules integration access callback.
 */
function campaign_api_rules_access($type, $name) {
  $access = TRUE;
  // Code here will determine if $access == TRUE/FALSE;

  if ($type == 'event' || $type == 'condition') {
    return campaign_api_key_group_access('view');
  }

  return $access;
}

/**
 * Implements hook_rules_event_info().
 */
function campaign_api_rules_event_info() {
  $events = array();

  $result = db_query('SELECT kgid,title FROM cool_keys_key_groups');
  if ($result) {
    while ($row = $result->fetchAssoc()) {
      $events['ckcode_apply_code_'.$row['kgid']] = array(
        'label' => t('FT CoolKeys group -' . $row['title'] . '- code has been applied'),
        'group' => t(' - CoolKeys'),
        'variables' => array(
          'ck_group' => array(
            'label' => t('CoolKeys Group', array(), array('context' => 'a ft coolkeys group')),
            'type' => 'cool_keys_key_group',
          ),
          'args' => array(
            'label' => t('Arguments passed to the Cool Keys usage event'),
            'type' => 'object',
          ),
        ),
        'access callback' => 'campaign_api_key_group_access',
      );
    }
  }
  $events['cool_keys_reached_max_uses'] = array(
    'label' => t('User applied a CoolKey that has reached max uses'),
    'group' => t(' - CoolKeys'),
    'variables' => array(
      'ck_group' => array(
        'label' => t('CoolKeys Group', array(), array('context' => 'a ft coolkeys group')),
        'type' => 'cool_keys_key_group',
      ),
      'args' => array(
        'label' => t('Passed URL Get arguments as an object'),
        'type' => 'unknown',
      ),
    ),
  );
  // General rule event for any ckcode applied.
  $events['ckcode_applied'] = array(
    'label' => t('FT CoolKeys code has been applied'),
    'group' => t(' - CoolKeys'),
    'variables' => array(
      'ck_group' => array(
        'label' => t('CoolKeys Group', array(), array('context' => 'a ft coolkeys group')),
        'type' => 'cool_keys_key_group',
      ),
      'args' => array(
        'label' => t('Arguments passed to the Cool Keys usage event'),
        'type' => 'object',
      ),
    ),
    'access callback' => 'campaign_api_key_group_access',
  );
  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function campaign_api_rules_action_info() {
  $actions['ckcode_apply_code_extract_value'] = array(
    'label' => t('Extract value'),
    'group' => t(' - CoolKeys'),
    'parameter' => array(
      'args' => array(
        'label' => t('Args'),
        'type' => 'object',
      ),
      'key' => array(
        'label' => t('Key'),
        'type' => 'text',
      ),
    ),
    'provides' => array(
      'value' => array(
        'label' => t('Value'),
        'type' => 'text',
      ),
    ),
    'callbacks' => array(
      'execute' => 'ckcode_apply_code_extract_value',
    ),
  );

  return $actions;
}

function ckcode_apply_code_extract_value($args, $key) {
  $return = array();
  $return['value'] = !empty($args[$key]) ? $args[$key] : NULL;
  return $return;
}
