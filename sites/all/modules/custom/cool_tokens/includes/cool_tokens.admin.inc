<?php
/**
 * @file
 * cool_tokens.admin.inc
 */

/**
 * Token delete form.
 *
function cool_token_form_delete_confirm($form, &$form_state, $ft_token) {
  $form_state['cool_token'] = $ft_token;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['cool_token_id'] = array('#type' => 'value', '#value' => entity_id('cool_token' ,$ft_token));
  $token = entity_get_info('cool_token');
  return confirm_form($form,
    t('Are you sure you want to delete the tokenzzz %title?', array('%title' => entity_label('cool_token', $ft_token))),
    $token['admin ui']['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

**
 * Token delete form submit handler.
 *
function cool_token_form_delete_confirm_submit($form, &$form_state) {
  $ft_token = $form_state['cool_token'];
  cool_tokens_token_delete($ft_token);

  watchdog('cool_token', '@ft_token: deleted %title.', array('@ft_token' => $ft_token->token, '%title' => $ft_token->label));
  drupal_set_message(t('@ft_token %title has been deleted.', array('@ft_token' => $ft_token->token, '%title' => $ft_token->label)));

  $token = entity_get_info('cool_token');
  $form_state['redirect'] = $token['admin ui']['path'];
}*/

/**
 * Token Type Form.
 */
function cool_tokens_type_form($form, &$form_state, $ft_token_type = NULL) {
  $fid = variable_get('token_type_image_fid','');
  
  $form['type'] = array(
    '#type' => 'machine_name',
    '#required' => TRUE,
    '#title' => t('Type:'),
    '#default_value' => $ft_token_type->type,
    '#maxlength' => 32,
    '#disabled' => !empty($ft_token_type->type),
    '#machine_name' => array(
      'exists' => 'cool_tokens_token_name_exists',
      'source' => array('title'),
  ),
  );
  
  $form['label'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Label'),
    '#default_value' => $ft_token_type->label,
  );
  
  $form['token_type_image'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('Upload a default token type image.'),
    '#default_value' => variable_get('token_type_image_fid',''),
    '#upload_location' => 'public://ft_token_type_images/',
    '#upload_validators' => array(
        'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
  );
  
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#required' => FALSE,
    '#default_value' => $ft_token_type->description,
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Token Type'),
  );
  
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('cool_token_form_cancel'),
  );
  
  return $form;
}

/**
 * Token Type submit handler.
 */
function cool_tokens_type_form_submit(&$form, &$form_state) {

  $ft_token_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $ft_token_type->save();
  
  if(!empty($form_state['values']['token_type_image'])) {
  
    $ft_token_type_id = entity_id('cool_tokens_type', $ft_token_type);
    // Load the file via file.fid.
    $file = file_load($form_state['values']['token_type_image']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module is using the file. 
    //file_usage_add($file, 'cool_tokens', 'cool_token', $ft_token_id);
  
  }
  
  $token = entity_get_info('cool_tokens_type');
  $form_state['redirect'] = $token['admin ui']['path'];
}

/**
 * Token Form.
 */
function cool_token_form($form, &$form_state, $ft_token = NULL) {

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable name of the token'),
    '#default_value' => $ft_token->title,
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#required' => TRUE,
    '#default_value' => $ft_token->description,
  );
  $form['set_unlimited'] = array(
    '#title' => t('Is the number of uses unlimited?'),
    '#description' => t('Check if this token has no set number of uses.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($ft_token->set_unlimited)) ? $ft_token->set_unlimited : FALSE,
  );
  $form['max_uses'] = array(
    '#type' => 'textfield',
    '#element_validate' => array('cool_token_numeric_validate', 'cool_token_not_zero_validate'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_unlimited"]' => array('checked' => TRUE),
      ),
    ),
    '#title' => t('Number of uses for this token.'),
    '#default_value' => (!empty($ft_token->max_uses)) ? $ft_token->max_uses : 1,
  );
    if (!empty($ft_token->max_uses)) {
      $form['max_uses']['#disabled'] = TRUE;
  }
  $form['active'] = array(
    '#title' => t('Is the token active?'),
    '#description' => t('Check if this group is active.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($ft_token->active)) ? $ft_token->active : FALSE,
  );
  $form['activates'] = array(
    '#title' => t('Activation Date'),
    '#description' => t('Enter the date on which this token will activate.'),
    '#type' => 'date',
    '#default_value' => (!empty($ft_token->activates)) ? unserialize($ft_token->activates) : '',
    '#required' => TRUE,
    '#after_build' => array("cool_token_format_year"),
  );
  $form['set_expire'] = array(
    '#title' => t('Token Expires?'),
    '#description' => t('If checked, then you may select a date for this token to expire on'),
    '#type' => 'checkbox',
    '#default_value' => (!empty($ft_token->set_expire)) ? $ft_token->set_expire : FALSE,
  );
  $form['expires'] = array(
    '#type' => 'date', 
    '#title' => t('Expires On'),
    '#description' => t('Enter the date on which this token will expire.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_expire"]' => array('checked' => FALSE),
      ),
    ),
    '#default_value' => (!empty($ft_token->expires)) ? unserialize($ft_token->expires) : '',
    '#after_build' => array("cool_token_format_year"),
  );
  $form['actions'] = array(
    '#weight' => 100,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Token'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('cool_token_form_cancel'),
  );
  $form_state['token'] = $ft_token;
  field_attach_form('cool_token', $ft_token, $form, $form_state);
  // Show Delete button if we edit token.
  $ft_token_id = entity_id('cool_token', $ft_token);
  if (!empty($ft_token_id) && cool_tokens_token_access('edit', $ft_token)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cool_token_delete_form'),
    );
  }

  return $form;
}

/**
 * Validation callback for cool_token_form().
 */
function cool_token_form_validate($form, &$form_state) {
  $ft_token = $form_state['token'];
  field_attach_form_validate('cool_token', $ft_token, $form, $form_state);
}

function cool_tokens_token_name_exists($name) {
  $query = "SELECT type from {cool_tokens_type} fttk WHERE (type=:name);";
  $result = db_query($query, array(':name' => $name))->fetchField();
  return (!($result == FALSE));
}

/**
 * Validate numeric fields.
 */
function cool_token_numeric_validate($element, &$form_state, $form) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('Must be a numeric value'));
  }
}

/**
 * Validate max_uses field > 0.
 */
function cool_token_not_zero_validate($element, &$form_state, $form) {
  if (intval($element['#value']) <= 0) {
    form_error($element, t('This value must be 1 or greater'));
  }
}

/**
 * Function to limit year options to +10. 
 * This is instead of Drupal's 1900 - 2050 default year options.
 **/
function cool_token_format_year($form_element){
    // We unset the current values
    unset($form_element['year']['#options']);

    // Now we set the range we want
    $max_year = date('Y') - 0; // 100 years ago
    $min_year = date('Y') + 10; // 7 years ago
    
    // Now we populate the array
    $form_element['year']['#options'] = array();
    foreach (range($max_year, $min_year) as $year){
        $form_element['year']['#options'][$year] = $year;
    }
    
    // We return our modified element
    return $form_element;
}

/**
 * Token submit handler.
 */
function cool_token_form_submit(&$form, &$form_state) {
  $entity = $form_state['token'];
  $entity->title = $form_state['values']['title'];
  //$entity->tkid = (!isset($entity->tkid)) ? $form_state['values']['tkid'] : $entity->tkid;
  $entity->description = $form_state['values']['description'];
  $entity->set_unlimited = $form_state['values']['set_unlimited'];
  $entity->max_uses = $form_state['values']['max_uses'];
  $entity->active = $form_state['values']['active'];
  $entity->activates = $form_state['values']['activates'];
  $entity->set_expire = $form_state['values']['set_expire'];
  $entity->expires = $form_state['values']['expires'];
  $entity->status = 1;
  $entity->module = 'cool_tokens';
  if($entity->set_unlimited == 1) {
    $entity->max_uses = 0;
  }
  else {
    $entity->max_uses = $entity->max_uses;
  }
  $entity->activates = serialize($entity->activates);
  if($entity->set_expire == 0) {
    $entity->expires = NULL;
  }
  else {
    $entity->expires = serialize($entity->expires);
  }
  cool_tokens_token_process_date_fields($entity);
  //field_attach_submit($type, $entity, $form, &$form_state, $options = array());
  cool_tokens_token_save($entity);
  // Now refresh the rules_config entities to build the new one based on new/updated group.
  $token = entity_get_info('cool_token');
  $form_state['redirect'] = $token['admin ui']['path'];
}

/**
 * Builds token for save.
 * @param array $form
 * @param array $form_state
 */
function cool_tokens_submit_build_token($form, $form_state) {
  //create consolidated 'data' value in form_state
  $ft_token = entity_ui_form_submit_build_entity($form, $form_state);
  cool_tokens_token_process_date_fields($ft_token);
  return $ft_token;
}


/**
 * Callback for the cancel link on token forms.
 */
function cool_token_form_cancel() {
  $token = entity_get_info('cool_token');
  $form_state['redirect'] = $token['admin ui']['path'];
}

/**
 * Form to delete a token.
 * @param array $form
 * @param array $form_state
 * @param stdClass$ft_token
 *
function cool_token_delete_form($form, &$form_state,$ft_token) {
  $form['#tkid'] = $ft_token->tkid;
  $token = entity_get_info('cool_token');
  return confirm_form($form, t('Really delete token (cannot be undone)?'), $token['admin ui']['path'], null, t('Delete'), t('Cancel'));
}

**
 * Submit callback for deleting a token.
 * @param array $form
 * @param array $form_state
 *
function cool_token_delete_form_submit(&$form, &$form_state) {
 $ft_token = cool_tokens_token_load($form['#tkid']);
  // Delete any jobs associated with this instance.
  $job = array(
    'id' =>$ft_token->tkid,
    'type' => 'ft_token_activate',
  );
  $scheduler = JobScheduler::get('ft_token_activate');
  $scheduler->remove($job);
  $job = array(
    'id' =>$ft_token->tkid,
    'type' => 'ft_token_expire',
  );
  $scheduler = JobScheduler::get('ft_token_expire');
  $scheduler->remove($job); 
  
  // Delete discount instance.
  cool_tokens_token_delete($ft_token);

  // Redirect
  $token = entity_get_info('cool_token');
  $form_state['redirect'] = $token['admin ui']['path'];
}*/

/**
 * Helper function adds string format dates to tokens.
 * Need to save string format dates in addition for date
 * array format.
 * @param stdClass $ft_token
 */
function cool_tokens_token_process_date_fields(&$ft_token) {
  $expire_date = (isset($ft_token->expires)) ? $ft_token->expires : NULL;
  $activate_date = $ft_token->activates;
  $ft_token->ft_token['expires_date_string'] = date('Y-m-d', strtotime("{$expire_date['month']}/{$expire_date['day']}/{$expire_date['year']}"));
  $ft_token->ft_token['activates_date_string'] = date('Y-m-d', strtotime("{$activate_date['month']}/{$activate_date['day']}/{$activate_date['year']}"));
}