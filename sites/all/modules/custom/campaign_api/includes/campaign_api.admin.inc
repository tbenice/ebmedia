<?php
/**
 * @file
 * campaign_api.admin.inc
 */

/**
 * Campaign Form.
 */
function campaign_form($form, &$form_state, $campaign = NULL) {
  $defaults = (isset($form_state['values'])) ? $form_state['values'] : (!$campaign->is_new) ? (array)$campaign : array('title'=>'', 'label'=>'', 'description'=> '', 'class'=>'');
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable name of the campaign'),
    '#default_value' => $defaults['title'],
    '#required' => TRUE,
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $defaults['description'],
  );
  $form['active'] = array(
    '#title' => t('Is the campaign active?'),
    '#description' => t('Check if this group is active.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($defaults['active'])) ? $defaults['active'] : FALSE,
  );
  $form['activates'] = array(
    '#title' => t('Activation Date'),
    '#description' => t('Enter the date on which this campaign will activate.'),
    '#type' => 'date',
    '#default_value' => (!empty($defaults['activates'])) ? $defaults['activates'] : '',
    '#required' => TRUE,
    '#after_build' => array("campaign_api_format_year"),
  );
  $form['set_expire'] = array(
    '#title' => t('Campaign Expires?'),
    '#description' => t('If checked, then you may select a date for this campaign to expire on'),
    '#type' => 'checkbox',
    '#default_value' => (!empty($defaults['set_expire'])) ? $defaults['set_expire'] : FALSE,
  );
  $form['expires'] = array(
    '#type' => 'date', 
    '#title' => t('Expires On'),
    '#description' => t('Enter the date on which this campaign will expire.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_expire"]' => array('checked' => FALSE),
      ),
    ),
    '#default_value' => (!empty($defaults['expires'])) ? $defaults['expires'] : '',
    '#after_build' => array("campaign_api_format_year"),
  );
  // Add the plugin config elements.
  $plugin = campaign_api_get_campaign_plugin($campaign);
  $campaign_type = campaign_type_load($campaign->type);
  $form['plugin_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('@type plug-in settings', array('@type' => $campaign_type->label)),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $plugin_data = (!empty($campaign->data['plugin_data'])) ? $campaign->data['plugin_data']['config']['configData'] : array();
  $plugin_form = $plugin->getConfigForm(array(), $form_state, $plugin_data);
  $elements = array();
  foreach($plugin_form as $key => $element) {
    $elements['plugin_form'][$key] = $element;
  }
  // Merge the forms.
  $form['plugin_form'] += $elements;
  $form['actions'] = array(
    '#weight' => 100,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Campaign'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('campaign_form_cancel'),
  );
  $form_state['campaign'] = $campaign;
  field_attach_form('campaign', $campaign, $form, $form_state);
  return $form;
}

/**
 * Function to limit year options to +10. 
 * This is instead of Drupal's 1900 - 2050 default year options.
 **/
function campaign_api_format_year($form_element){
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
 * Campaign entity form submit handler.
 */
function campaign_form_submit(&$form, &$form_state) {
  $campaign = $form_state['campaign'];
  // Flag is_new if this is a new campaign.
  $campaign->is_new = (!isset($campaign->campaign_id));
  $new_campaign = $campaign->is_new;
  $campaign->title = $form_state['values']['title'];
  $campaign->description = $form_state['values']['description'];
  $campaign->active = $form_state['values']['active'];
  $campaign->activates = $form_state['values']['activates'];
  $campaign->set_expire = $form_state['values']['set_expire'];
  $campaign->expires = $form_state['values']['expires'];
  $campaign->status = 1;
  $campaign->module = 'campaign_api';
  $campaign->activates = $campaign->activates;
  if($campaign->set_expire == 0) {
    $campaign->expires = NULL;
  }
  else {
    $campaign->expires = $campaign->expires;
  }
  campaign_api_process_date_fields($campaign);
  // Save the plugin config data.
  $plugin = campaign_api_get_campaign_plugin($campaign);
  $plugin->setFormConfigData($form, $form_state);
  $plugin_data = $plugin->getData();
  $campaign->data['plugin_data']['config']['configData'] = $plugin_data['config']['configData'];

  // Save.
  campaign_save($campaign);

  if ($new_campaign) {
    // Run plugin create() method and save the data.
    $campaign = campaign_api_create_campaign_components($campaign);
  }
  else {
    // Update the componenets.
    $campaign = campaign_api_update_campaign_components($campaign);
  }
  campaign_save($campaign);

  // Rebuild default Rules.
  campaign_api_rebuild_default_entities($campaign);

  $campaign_info = entity_get_info('campaign');
  $form_state['redirect'] = $campaign_info['admin ui']['path'];
}

/**
 * Callback for the cancel link on campaign entity forms.
 */
function campaign_form_cancel($form, $form_state) {
  $campaign_info = ($form['#form_id'] == 'campaign_type_form') ? entity_get_info('campaign_type') : entity_get_info('campaign');
  drupal_goto($campaign_info['admin ui']['path']);
}

/**
 * Helper function adds string format dates to campaigns.
 * Need to save string format dates in addition for date
 * array format.
 * @param stdClass $campaign
 */
function campaign_api_process_date_fields(&$campaign) {
  $expire_date = (isset($campaign->expires)) ? $campaign->expires : NULL;
  $activate_date = $campaign->activates;
  $campaign->campaign['expires_date_string'] = date('Y-m-d', strtotime("{$expire_date['month']}/{$expire_date['day']}/{$expire_date['year']}"));
  $campaign->campaign['activates_date_string'] = date('Y-m-d', strtotime("{$activate_date['month']}/{$activate_date['day']}/{$activate_date['year']}"));
}

/**
 * Returns an options list of available campaign config plugins.
 */
function campaign_api_class_options() {
  $options = array();
  $plugins = campaign_api_config_plugin_info_get();
  foreach($plugins as $name => $info) {
    $options[$info['class']] = $name;
  }
  return $options;
}

function campaign_api_config_plugin_info_get() {
  $plugins = drupal_static(__FUNCTION__);

  if (empty($plugins)) {
    $cid = "campaign_api_config_plugin_info";
    $cache = cache_get($cid);

    if (!isset($cache->data)) {
      $plugins = module_invoke_all('campaign_api_config_plugin_info');
      cache_set($cid, $plugins, CACHE_TEMPORARY);
    }
    else {
      $plugins = $cache->data;
    }
  }

  return $plugins;
}

/**
 * Callback for machine_name verification.
 */
function  campaign_name_exists($name) {
  $query = "SELECT type from {campaign_type} WHERE (type=:name);";
  $result = db_query($query, array(':name' => $name))->fetchField();
  return (!($result == FALSE));
}

/**
 * Returns elements of the base campaign type entity form.
 */
function campaign_type_form_elements(&$form_state, $defaults, $plugin_data) {
  $form['label'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Label'),
    '#default_value' => (!empty($defaults['label'])) ? $defaults['label'] : NULL,
  );
  $form['type'] = array(
    '#type' => 'machine_name',
    '#required' => TRUE,
    '#title' => t('Type:'),
    '#default_value' => (!empty($defaults['type'])) ? $defaults['type'] : NULL,
    '#maxlength' => 32,
    '#disabled' => !empty($defaults['type']),
    '#machine_name' => array(
      'exists' => 'campaign_name_exists',
      'source' => array('label'),
    ),
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#required' => FALSE,
    '#default_value' => (!empty($defaults['description'])) ? $defaults['description'] : NULL,
  );
  $form['class'] = array(
    '#type' => 'textfield',
    '#title' => t('Config Plugin'),
    '#disabled' => TRUE,
    '#description' => t('This is the campaign plugin that will be used for this campaign type.'),
    '#default_value' => (!empty($defaults['class'])) ? $defaults['class'] : NULL,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Campaign Type'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('campaign_form_cancel'),
  );
  return $form;
}

/**
 * Token Type Form.
 */
function campaign_type_form($form, &$form_state, $campaign_type = NULL) {
  $defaults = (!empty($campaign_type->type)) ? (array)$campaign_type : ((!empty($form_state['values'])) ? $form_state['values'] : array());
  // If first time with the form, show the class select.
  if (!isset($form_state['storage']['step']) && (empty($defaults))) {
    $form_state['storage']['step'] = 'class_form';
    // Select the plugin.
    $form['class'] = array(
      '#type' => 'select',
      '#title' => t('Campaign Plugin'),
      '#description' => t('Select a campaign config plugin to use for this campaign type.'),
      '#options' => campaign_api_class_options(),
      '#default_value' => $defaults['class'],
    );
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Continue'),
    );
    $form['actions']['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#submit' => array('campaign_form_cancel'),
    );
    return $form;
  }
  else {
    // Set the form step.
    $form_state['storage']['step'] = 'type_form';
    $plugin_data = (!empty($campaign_type->data['plugin_data'])) ? $campaign_type->data['plugin_data']['config']['configData'] : array();
    $form = campaign_type_form_elements($form_state, $defaults, $plugin_data);
    return $form;
  }
}

/**
 * Token Type submit handler.
 */
function campaign_type_form_submit(&$form, &$form_state) {
  // Save the class if on the class form step.
  if ($form_state['storage']['step'] == 'class_form') {
    $form_state['rebuild'] = TRUE;
  }
  elseif ($form_state['storage']['step'] == 'type_form') {
    $form_state['rebuild'] = FALSE;
    // Build the campaign type entity.
    $campaign_type = entity_ui_form_submit_build_entity($form, $form_state);
    $campaign_type->module = 'campaign_api';
    // Save the type.
    $campaign_type->save();
    // Set the redirect.
    $campaign_info = entity_get_info('campaign_type');
    $form_state['redirect'] = $campaign_info['admin ui']['path'];
  }
}

/**
 * Helper function returns an experiment subform.
 * Defines a subform in a wrapper to ease adding
 * additional experiments in the admin form. It also
 * adds subforms for existing defined experiments.
 * @param array $value
 *   Optional: The value of the experiment to fill the
 *   default values for the subform.
 */
function __experiments_subform($value = null) {
  $form['path'] = array(
    '#type' => 'textfield',
    '#description' => t('The Drupal path that this experiment should be active on'),
    '#element_validate' => array('campaign_api_experiment_path_validate'),
    '#default_value' => isset($value) ? $value['path'] : '',
    '#prefix' => '<div class="-experiment-subform">',
    '#attributes' => array('class' => array('experiment-path'), 'placeholder' => t('Drupal system path')),
  );
  $form['experiment_id'] = array(
    '#type' => 'textfield',
    '#description' => t('This is the unique ID for the Content Experiment.'),
    '#default_value' => isset($value) ? $value['experiment_id'] : '',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('experiment-id'), 'placeholder' => t('GA Experiment ID'))
  );
  return $form;
}

/**
 * The admin form to add experiment definitions.
 */
function campaign_api_experiments_admin_form($form, $form_state) {
  $values = (isset($form_state['values'])) ? $form_state['values'] : array();
  $experiments = variable_get('_experiments_experiments', array());

  // Calculate the number of experiment subforms.
  if (isset($form_state['subform_count'])) {
    $subform_count = $form_state['subform_count'];
  }
  else {
    $subform_count = max(1, empty($experiments) ? 1 : count($experiments));
  }

  $form['experiments_wrapper'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix experiments-wrapper">',
    '#suffix' => '</div>',
  );

  $form['experiments_wrapper']['experiments'] = array(
    '#prefix' => '<div id="experiment-definitions">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  $delta = count($experiments);
  foreach($experiments as $experiment) {
    $form['experiments_wrapper']['experiments'][] = __experiments_subform($experiment);
  }

  // Add initial or new experiments.
  $existing_delta = $delta;
  for ($delta; $delta < $subform_count; $delta++) {
    $key = 'new:' . ($delta-$existing_delta);
    $form['experiments_wrapper']['experiments'][$key] = __experiments_subform();
  }

  // We name our button 'experiments_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['experiments_wrapper']['experiments_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#limit_validation' => array('experiments'),
    '#attributes' => array(
      'title' => t("If you need another experiment, click here to add another!"),
    ),
    '#weight' => 1,
    '#submit' => array('campaign_api_more_experiments_submit'),
    '#ajax' => array(
      'callback' => 'campaign_api_js',
      'wrapper' => 'experiment-definitions',
      'effect' => 'fade',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Submit handler for the admin form add experiments button.
 */
function campaign_api_more_experiments_submit($form, &$form_state) {
  if ($form_state['values']['experiments_more']) {
    $form_state['subform_count'] = count($form_state['values']['experiments']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback for the admin form add experiments button.
 */
function campaign_api_js($form, $form_state) {
  return $form['experiments_wrapper']['experiments'];
}

/**
 * Submit handler for the admin form.
 */
function campaign_api_experiments_admin_form_submit($form, $form_state) {
  foreach($form_state['values']['experiments'] as $key => $experiment) {
    if (!is_array($experiment) || ($experiment['experiment_id'] == null)) { continue; }
    $experiments[] = $experiment;
  }
  variable_set('_experiments_experiments', $experiments);
}

/**
 * Administration form.
 */
function campaign_api_ga_events_ui_admin_subform($values=null) {
  $form['prefix'] = array(
    '#markup' => '<div class="ga-events-ui-subform">',
  );
  if (isset($values['title'])) {
    $form['title_markup'] = array(
      '#prefix' => '<h2 class="event-title">',
      '#markup' => "Event {$values['title']}",
      '#suffix' => '</h2>',
    );
    $form['title'] = array(
      '#type' => 'value',
      '#value' => $values['title'],
    );
  }
  else {
    $form['title'] = array(
      '#type' => 'textfield',
      '#description' => t('Enter a title that will represent this event in Drupal'),
      '#attributes' => array('placeholder' => t('Event Title')),
    );
  }
  $form['jquery_event'] = array(
    '#type' => 'textfield',
    '#description' => t('This can be any valid jQuery event. For a list see ' . l(t('jQuery Documentation'), 'http://api.jquery.com/')),
    '#default_value' => isset($values['jquery_event']) ? $values['jquery_event'] : '',
    '#attributes' => array('placeholder' => t('jQuery Event')),
    '#required' => TRUE,
  );
  $form['dom_selector'] = array(
    '#type' => 'textfield',
    '#description' => t('This is the DOM selector that we will track the event for'),
    '#default_value' => isset($values['dom_selector']) ? $values['dom_selector'] : '',
    '#attributes' => array('placeholder' => t('DOM Selector (e.g. #myelement)')),
    '#required' => TRUE,
  );
  $form['optional'] = array(
    '#type' => 'fieldset',
    '#title' => t('Optional Parameters'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['optional']['category'] = array(
    '#type' => 'textfield',
    '#description' => t('Category helps with organizing events in the GA UI'),
    '#default_value' => isset($values['optional']['category']) ? $values['optional']['category'] : '',
    '#attributes' => array('placeholder' => t('Category')),
  );
  $form['optional']['action'] = array(
    '#type' => 'textfield',
    '#description' => t('Action helps with organizing events in the GA UI'),
    '#default_value' => isset($values['optional']['action']) ? $values['optional']['action'] : '',
    '#attributes' => array('placeholder' => t('Action')),
  );
  $form['optional']['label'] = array(
    '#type' => 'textfield',
    '#description' => t('Label helps with organizing events in the GA UI'),
    '#default_value' => isset($values['optional']['label']) ? $values['optional']['label'] : '',
    '#attributes' => array('placeholder' => t('Label')),
  );
  $form['optional']['value'] = array(
    '#type' => 'textfield',
    '#description' => t('A value provides a weight for the event. This defaults to 1 in GA, so if you make it >1 the event will count more.'),
    '#default_value' => isset($values['optional']['value']) ? $values['optional']['value'] : '',
    '#attributes' => array('placeholder' => t('Value')),
  );
  $form['optional']['non_interaction'] = array(
    '#type' => 'checkbox',
    '#title' => t('Non-Interaction'),
    '#description' => t('If checked, this setting will exempt this event from GA Bounce-rate calculations. Only check if the event being tracked does not involve user interaction.'),
    '#default_value' => (isset($values['optional']['non_interaction'])) ? $values['optional']['non_interaction'] : 0,
  );
  $form['suffix'] = array(
    '#markup' => '</div>',
  );
  return $form;
}

/**
 * Element validate callback for path element fields in admin form.
 * Validates path text fields in the admin for to be
 * sure that no path is used twice, and that any path
 * exists as a drupal system path.
 */
function campaign_api_experiment_path_validate($element, &$form_state, $form) {
  if (!empty($element['#value'])) {
    if (!strpos($element['#id'], 'new') == FALSE) {
      // If this is a new value, throw validation error if the path
      // already exists in the list of paths.
      $experiments = variable_get('_experiments_experiments', array());
      // Only have to look if there are some saved experiments.
      if (_campaign_api_experiment_path_exists($element['#value'])) {
        form_error($element, t('This path is already being used.'));
      }
    }
    if (!drupal_valid_path($element['#value'])) {
      form_error($element, t('You must enter a valid Drupal system path.'));
    }
  }
}

function campaign_api_ga_events_ui_admin_form($form, $form_state) {
  $values = (isset($form_state['values'])) ? $form_state['values'] : array();
  $events = variable_get('ga_events_ui_events', array());

  // Calculate the number of experiment subforms.
  if (isset($form_state['subform_count'])) {
    $subform_count = $form_state['subform_count'];
  }
  else {
    $subform_count = max(1, empty($events) ? 1 : count($events));
  }

  $form['events_wrapper'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix events-wrapper">',
    '#suffix' => '</div>',
  );

  $form['events_wrapper']['events'] = array(
    '#prefix' => '<div id="event-definitions">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  $delta = count($events);
  foreach($events as $event) {
    $form['events_wrapper']['events'][] = campaign_api_ga_events_ui_admin_subform($event);
  }

  // Add initial or new experiments.
  $existing_delta = $delta;
  for ($delta; $delta < $subform_count; $delta++) {
    $key = 'new:' . ($delta-$existing_delta);
    $form['events_wrapper']['events'][$key] = campaign_api_ga_events_ui_admin_subform();
  }

  // We name our button 'experiments_more' to avoid conflicts with other modules using
  // Ajax-enabled buttons with the id 'more'.
  $form['events_wrapper']['events_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#limit_validation' => array('events'),
    '#attributes' => array(
      'title' => t("If you need another event, click here to add another!"),
    ),
    '#weight' => 1,
    '#submit' => array('campaign_api_ga_events_ui_more_events_submit'),
    '#ajax' => array(
      'callback' => 'campaign_api_ga_events_ui_js',
      'wrapper' => 'event-definitions',
      'effect' => 'fade',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Submit handler for the admin form add events button.
 */
function campaign_api_ga_events_ui_more_events_submit($form, &$form_state) {
  if ($form_state['values']['events_more']) {
    $form_state['subform_count'] = count($form_state['values']['events']) + 1;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback for the admin form add events button.
 */
function campaign_api_ga_events_ui_js($form, $form_state) {
  return $form['events_wrapper']['events'];
}

/**
 * Submit handler for the admin form.
 */
function campaign_api_ga_events_ui_admin_form_submit($form, $form_state) {
  foreach($form_state['values']['events'] as $key => $event) {
    if (!is_array($event) || ($event['jquery_event'] == null)) { continue; }
    $events[] = $event;
  }
  variable_set('ga_events_ui_events', $events);
}

/**
 * Callback for machine_name verification.
 */
function  campaign_api_key_group_name_exists($name) {
  $query = "SELECT ckgs.kgid from {cool_keys_key_groups} ckgs WHERE (ckgs.kgid=:name);";
  $result = db_query($query, array(':name' => $name))->fetchField();
  return (!($result == FALSE));
}

/**
 * Group delete form.
 */
function cool_keys_key_group_form_delete_confirm($form, &$form_state, $key_group) {
  $form_state['cool_keys_key_group'] = $key_group;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['cool_keys_key_group_id'] = array('#type' => 'value', '#value' => entity_id('cool_keys_key_group' ,$key_group));
  return confirm_form($form,
    t('Are you sure you want to delete the group %title?', array('%title' => entity_label('cool_keys_key_group', $key_group))),
    'cool_key_group/' . entity_id('cool_keys_key_group' ,$key_group),
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Group delete form submit handler.
 */
function cool_keys_key_group_form_delete_confirm_submit($form, &$form_state) {
  $key_group = $form_state['cool_keys_key_group'];
  cool_keys_key_group_delete($key_group);

  watchdog('cool_keys_key_group', '@group: deleted %title.', array('@group' => $key_group->group, '%title' => $key_group->label));
  drupal_set_message(t('@group %title has been deleted.', array('@group' => $key_group->group, '%title' => $key_group->label)));

  $form_state['redirect'] = 'admin/structure/cool-keys-groups';
}

/**
 * Group Form.
 */
function cool_keys_key_group_form($form, &$form_state, $ck_group = NULL) {

  global $user;

  $expires = (isset($ck_group->set_expire)) ? $ck_group->set_expire : false;

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Name'),
    '#default_value' => $ck_group->title,
  );

  $form['kgid'] = array(
    '#type' => 'machine_name',
    '#default_value' => $ck_group->kgid,
    '#maxlength' => 32,
    '#disabled' => !empty($ck_group->kgid),
    '#machine_name' => array(
      'exists' => 'campaign_api_key_group_name_exists',
      'source' => array('title'),
    ),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#required' => TRUE,
    '#default_value' => $ck_group->description,
  );

  $form['key_code_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Key Code Prefix'),
    '#description' => t('Optionally add a prefix that will be prepended onto all key codes in this group.'),
    '#default_value' => isset($ck_group->data['key_code_prefix']) ? $ck_group->data['key_code_prefix'] : '',
  );

  $form['set_unlimited_keys'] = array(
    '#title' => t('Is the number of keys unlimited?'),
    '#description' => t('Check if this group has no set number of keys.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($ck_group->set_unlimited_keys)) ? $ck_group->set_unlimited_keys : FALSE,
  );

  $form['num_keys'] = array(
    '#type' => 'textfield',
    '#element_validate' => array('cool_keys_numeric_validate', 'cool_keys_not_zero_validate'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_unlimited_keys"]' => array('checked' => TRUE),
      ),
    ),
    '#title' => t('Number of keys in this group.'),
    '#default_value' => (!empty($ck_group->num_keys)) ? $ck_group->num_keys : 1,
  );

  if (!empty($ck_group->num_keys)) {
    $form['num_keys']['#disabled'] = TRUE;
  }

  $form['set_unlimited_uses'] = array(
    '#title' => t('Is the number of uses unlimited?'),
    '#description' => t('Check if this group has no set number of max uses.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($ck_group->set_unlimited_uses)) ? $ck_group->set_unlimited_uses : FALSE,
  );

  $form['max_uses'] = array(
    '#type' => 'textfield',
    '#element_validate' => array('cool_keys_numeric_validate', 'cool_keys_not_zero_validate'),
    '#title' => t('Number of times a user may use a key.'),
    '#description' => t('Please enter only a number.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_unlimited_uses"]' => array('checked' => TRUE),
      ),
    ),
    '#default_value' => (!empty($ck_group->max_uses)) ? $ck_group->max_uses : 1,
  );

  $form['active'] = array(
    '#title' => t('Is the group active?'),
    '#description' => t('Check if this group is active.'),
    '#type' => 'checkbox',
    '#default_value' =>  (!empty($ck_group->active)) ? $ck_group->active : FALSE,
  );

  $form['activates'] = array(
    '#title' => t('Activation Date'),
    '#description' => t('Enter the date on which this discount will start.'),
    '#type' => 'date',
    '#default_value' => (!empty($ck_group->activates)) ? unserialize($ck_group->activates) : '',
    '#required' => TRUE,
    '#after_build' => array("campaign_api_format_year"),
  );

  $form['set_expire'] = array(
    '#title' => t('Group Expires?'),
    '#description' => t('If checked, then you may select a date for this discount to expire on'),
    '#type' => 'checkbox',
    '#default_value' => (!empty($ck_group->set_expire)) ? $ck_group->set_expire : FALSE,
  );

  $form['expires'] = array(
    '#type' => 'date',
    '#title' => t('Expires On'),
    '#description' => t('Enter the date on which this discount will expire.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="set_expire"]' => array('checked' => FALSE),
      ),
    ),
    '#default_value' => (!empty($ck_group->expires)) ? unserialize($ck_group->expires) : '',
    '#after_build' => array("campaign_api_format_year"),
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save group'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('cool_keys_key_group_form_cancel'),
  );

  // Show Delete button if we edit group.
  $ck_group_id = entity_id('cool_keys_key_group' ,$ck_group);
  if (!empty($ck_group_id) && campaign_api_key_group_access('edit', $ck_group)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cool_keys_key_group_delete_form'),
    );
  }

  return $form;
}

/**
 * Group submit handler.
 */
function cool_keys_key_group_form_submit(&$form, &$form_state) {
  $ck_group = cool_keys_key_group_submit_build_group($form, $form_state);
  $ck_group->module = 'cool_keys';
  $ck_group->data['key_code_prefix'] = $form_state['values']['key_code_prefix'];
  if($ck_group->set_unlimited_keys == 1) {
    $ck_group->num_keys = 1;
  } else {
    $ck_group->num_keys = $ck_group->num_keys;
  }
  if($ck_group->set_unlimited_uses == 1) {
    $ck_group->max_uses = 0;
  } else {
    $ck_group->max_uses = $ck_group->max_uses;
  }
  $ck_group->activates = serialize($ck_group->activates);
  if($ck_group->set_expire == 0) {
    $ck_group->expires = NULL;
  } else {
    $ck_group->expires = serialize($ck_group->expires);
  }

  cool_keys_key_group_save($ck_group);

  // Now refresh the rules_config entities to build the new one based on new/updated group.
  $form_state['redirect'] = 'admin/structure/cool-keys-groups';
}

/**
 * Builds group for save.
 * @param array $form
 * @param array $form_state
 */
function cool_keys_key_group_submit_build_group($form, $form_state) {
  //create consolidated 'data' value in form_state
  $ck_group = entity_ui_form_submit_build_entity($form, $form_state);
  cool_keys_key_group_process_date_fields($ck_group);
  return $ck_group;
}

/**
 * Callback for the cancel link on group forms.
 */
function cool_keys_key_group_form_cancel() {
  drupal_goto('admin/structurecool-keys-groups');
}

/**
 * Form to delete a discount.
 * @param array $form
 * @param array $form_state
 * @param stdClass$ck_group
 */
function cool_keys_key_group_delete_form($form, &$form_state,$ck_group) {
  $form['#kgid'] = $ck_group->kgid;
  return confirm_form($form, t('Really delete group (cannot be undone)?'), 'admin/structurecool-keys-groups', null, t('Delete'), t('Cancel'));
}

/**
 * Submit callback for deleting a discount.
 * @param array $form
 * @param array $form_state
 */
function cool_keys_key_group_delete_form_submit(&$form, &$form_state) {
  $ck_group = cool_keys_key_group_load($form['#kgid']);
  // Delete any jobs associated with this instance.
  $job = array(
    'id' =>$ck_group->kgid,
    'type' => 'ck_group_activate',
  );
  $scheduler = JobScheduler::get('ck_group_activate');
  $scheduler->remove($job);
  $job = array(
    'id' =>$ck_group->kgid,
    'type' => 'ck_group_expire',
  );
  $scheduler = JobScheduler::get('ck_group_expire');
  $scheduler->remove($job);

  // Delete discount instance.
  cool_keys_key_group_delete($ck_group);

  // Redirect
  $form_state['#redirect'] = 'admin/structure/cool-keys-groups';
}

/**
 * Validate numeric fields.
 */
function cool_keys_numeric_validate($element, &$form_state, $form) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('Must be a numeric value'));
  }
}

/**
 * Validate max_uses field > 0.
 */
function cool_keys_not_zero_validate($element, &$form_state, $form) {
  if (intval($element['#value']) <= 0) {
    form_error($element, t('This value must be 1 or greater'));
  }
}

/**
 * Helper function adds string format dates to groups.
 * Need to save string format dates in addition for date
 * array format.
 * @param stdClass $ck_group
 */
function cool_keys_key_group_process_date_fields(&$ck_group) {
  $expire_date = (isset($ck_group->expires)) ? $ck_group->expires : NULL;
  $activate_date = $ck_group->activates;
  $ck_group->expires_date_string = date('Y-m-d', strtotime("{$expire_date['month']}/{$expire_date['day']}/{$expire_date['year']}"));
  $ck_group->activates_date_string = date('Y-m-d', strtotime("{$activate_date['month']}/{$activate_date['day']}/{$activate_date['year']}"));
}