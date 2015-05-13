<?php
/**
 * @file
 * cool_tokens.rules.inc
 */

/**
 *Implements hook_rules_event_info().
*/
function cool_tokens_rules_event_info() {
  $events = array();
  $result = db_query('SELECT tkid, title FROM cool_tokens');
  if ($result) {
    while ($row = $result->fetchAssoc()) { 
      $events['ft_tokens_apply_token_'.$row['tkid']] = array(
        'label' => t('FT Token -' . $row['title'] . '- has been applied'), 
        'group' => t('Cool - Tokens'),
        'variables' => array(
          'ft_token' => array(
            'label' => t('Cool Token'),
            'type' => 'cool_token',
          ),
          'args' => array(
            'label' => t('Arguments passed to the token apply event'),
            'type' => 'array',
          ),
        ),
        'access callback' => 'cool_tokens_token_access',
      );
    }
  }
  // General event for any token.
  $events['ft_token_applied'] = array(
    'label' => t('An FT Token was applied'),
    'group' => t('Cool - Tokens'),
    'variables' => array(
      'ft_token' => array(
        'label' => t('Cool Token'),
        'type' => 'cool_token',
      ),
      'args' => array(
        'label' => t('Arguments passed to the token apply event'),
        'type' => 'array',
      ),
    ),
    'access callback' => 'cool_tokens_token_access',
  );
  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function cool_tokens_rules_action_info() {

  $defaults = array(
   'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user who is assigned to or removed from a token.'),
        'save' => TRUE,
      ),
      'ft_token' => array(
        'type' => 'cool_token',
        'label' => t('FT Tokens'),
        'options list' => 'cool_tokens_options_list',
      ),
      'data' => array(
        'type' => 'text',
        'label' => t('Owner data'),
        'description' => t('Data to be saved with the token ownership. Must be serialized array with an explanitory key.'),
        'optional' => TRUE,
      ),
    ),
    'group' => t('Cool - Tokens'),
    'access callback' => 'cool_tokens_token_access',
  );

  $actions = array();

  $actions['ft_token_assign_user'] = $defaults + array(
    'label' => t('Assign user a token'),
    'base' => 'ft_add_user_to_token',
    'provides' => array(
      'ownership' => array(
        'label' => t('New Ownership Object'),
      	'type' => 'entity',
      ),
    ),
  );
  $actions['ft_token_unassign_user'] = $defaults + array(
    'label' => t('Remove user from a token'),
    'base' => 'ft_remove_user_from_token',
  );
  $actions['ft_token_add_data_to_owner'] = $defaults + array(
    'label' => t('Add data to a token ownership'),
    'provides' => array(
      'ownership' => array(
        'label' => t('Changed Ownership Object'),
      	'type' => 'entity',
      ),
    ),
  );
  $actions['ft_token_add_data_to_token'] = array(
   'label' => t('Add data to a token'),
   'parameter' => array(
      'ft_token' => array(
        'type' => 'cool_token',
        'label' => t('FT Tokens'),
        'options list' => 'cool_tokens_options_list',
      ),
      'data' => array(
        'type' => 'text',
        'label' => t('Owner data'),
        'description' => t('Data to be saved with the token ownership. Must be serialized array with an explanitory key.'),
        'optional' => TRUE,
      ),
    ),
    'provides' => array(
      'ft_token' => array(
        'label' => t('Changed cool_token entity'),
      	'type' => 'cool_token',
      ),
    ),
    'group' => t('Cool - Tokens'),
    'access callback' => 'cool_tokens_token_access',
  );
  return $actions;
}

/**
 * Implements hook_rules_condition_info().
 */
function cool_tokens_rules_condition_info() {
    $conditions = array();

    $conditions['ft_user_has_token'] = array(
    'label' => t('User has FT Token'),
    'group' => t('Cool - Tokens'),
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
      'ft_token' => array(
        'type' => 'cool_token',
        'label' => t('Cool Token'),
        'description' => t('The token to be checked.'),
      ),
    ),
    'base' => 'ft_tokens_condition_user_has_token',
    'access callback' => 'cool_tokens_token_access',
  );

  $conditions['ft_token_is_of_type'] = array(
    'label' => t('Token is of type'),
    'group' => t('Cool - Tokens'),
    'parameter' => array(
  	  'ft_token' => array(
        'type' => 'cool_token',
        'label' => t('Cool Token'),
        'description' => t('The token to be checked.'),
      ),
      'token_type' => array(
        'type' => 'text',
        'label' => t('Token Type'),
        'description' => t('The token type to check.'),
        'options list' => 'cool_tokens_types_available_list',
      ),
    ),
    'base' => 'ft_tokens_condition_token_is_of_type',
    'access callback' => 'cool_tokens_token_access',
  );
  return $conditions;
}

/**
 * Condition: User has token.
 */
function ft_tokens_condition_user_has_token($account, $ft_token) {
  return $ft_token->userHasToken($user);
}

/**
 * Condition: Token is of type.
 */
function ft_tokens_condition_token_is_of_type($ft_token, $token_type) {
  return ($ft_token->type == $token_type);
}

/**
 * Action: Assign a token to a user.
 */
function ft_add_user_to_token($account, $ft_token, $data) {
  $ownership = $ft_token->assignToken($account, $data);
  if ($ownership) {
    return array('ownership' => $ownership);
  }
  return FALSE;
}

/**
 * Action: Remove user from token.
 */
function ft_remove_user_from_token($account, $ft_token, $data) {

  $uid = $account->uid;
  $tkid = $ft_token->tkid;

  $query = db_delete('cool_tokens_owner');
  $query->condition('uid', $uid);
  $query->condition('tkid', $tkid);
  $query->execute();
}

/**
 * Action: add data to a token ownership.
 * NOTE: existing data key-values will be overwritten.
 * @return
 *   Returns the resulting ownership object.
 */
function ft_token_add_data_to_owner($user, $ft_token, $data) {
  // Return if there is no ownership
  if (!($ownership = $ft_token->getOwnership($user))) {
    return FALSE;
  }
  // Merge the old data with the new data.
  $ownership->data = array_merge($ownership->data, $data);
  // Save the new data.
  $ft_token->saveOwnership();
  // Try assigning the token to user.
  $ownership = $ft_token->assignUser($user, $data);
  if ($ownership) {
    return array('ownership' => $ownership);
  }
  return FALSE;
}

/**
 * Action: add data to a token ownership.
 * NOTE: existing data key-values will be overwritten.
 */
function ft_token_add_data_to_token($ft_token, $data) {
  $ft_token->data = array_merge($ft_token->data, $data);
  cool_tokens_token_save($ft_token);
  return array('ft_token' => $ft_token);
}
