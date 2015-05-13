<?php
/**
 * @file mailchimp_extras.admin.inc
 * Admin related functions for the mailchimp_extras feature.
 */

/**
 * Admin form for mailing list
 */
function mailchimp_extras_settings($mcapi = NULL) {
  //load lists defined for the site into an option-able array
  $lists = mailchimp_lists_load_multiple();
  $options = array();
  foreach ($lists as $list) {
    $options[$list->id] = $list->label;
  }

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General mailing list settings'),
  );
  $form['general']['mailchimp_extras_main_list'] = array(
    '#type' => 'select',
    '#title' => t('Site Main Mailing List'),
    '#description' => t('Select the main mailing list for the site. This is the list that users will
      automatically be subscribed to on registration, store purchase, or opt in through the
      form supplied by the mailing list feature (not the mailchimp form.</br><strong>NOTE:Only freeform lists
      can be set as the Site Main Mailing List!</strong>'),
    '#options' => $options,
    '#default_value' => (isset($form_state['values'])) ? $form_state['values']['mailchimp_extras_main_list'] : variable_get('mailchimp_extras_main_list', ''),
  );
  return system_settings_form($form);
}

/**
 * Admin form for mailing list groups
 */
function mailchimp_extras_group_settings_form($form, &$form_state) {
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Default MailChimp Groups'),
  );
  $groups = mailchimp_extras_group_names();
  $default = variable_get('mailchimp_extras_defaultgroups');
  //only show group creation field once the main list has been selected
  $list = mailchimp_lists_load(variable_get('mailchimp_extras_main_list', ''));
  if (isset($list)) {
    $form['add_group'] = array(
      '#type' => 'fieldset',
      '#title' => t('Create New Interest Grouping'),
    );
    $form['general']['mailchimp_extras_defaultgroups'] = array(
      '#title' => t('Add default groups'),
      '#description' => t('You must select this the first time you set up groups.  It automatically creates the groupings: registered, purchased, and subscribed.'),
      '#type' => 'checkbox',
      '#default_value' => variable_get('mailchimp_extras_defaultgroups', 1),
    );
    $form['add_group']['use_existing'] = array(
      '#title' => t('Use Existing Grouping?'),
      '#description' => t('If unchecked, then you may create a new grouping and group.'),
      '#type' => 'checkbox',
      '#default_value' => 1,
    );
    $form['add_group']['mailchimp_extras_newgroupid'] = array(
      '#type' => 'textfield',
      '#title' => t('New Interest Grouping'),
      '#description' => t('Enter a new MailChimp interest grouping name. This is the general grouping name. Enter the specific group name below.'),
      '#states' => array(
        'invisible' => array(
          ':input[name="use_existing"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['add_group']['mailchimp_extras_existinggroupid'] = array(
      '#type' => 'select',
      '#title' => t('Existing Interest Grouping'),
      '#description' => t('Select an Existing Interest Grouping. Enter the specific group name below.'),
      '#options' => $groups,
      '#states' => array(
        'invisible' => array(
          ':input[name="use_existing"]' => array('checked' => FALSE),
        ),
      ),
    );
    $form['add_group']['mailchimp_extras_newgroupname'] = array(
      '#type' => 'textfield',
      '#title' => t('New Interest Group Name'),
      '#description' => t('Enter the name of the group you are creating. If there is no group name, the grouping name and group name will be the same.'),
    );
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save group'),
    );
  } else {
    drupal_set_message(t('A mailing list must first be selected.'), 'error');
  }
  if (empty($default)) {
    unset($form['add_group']);
  }
  if ($default == 1) {
    unset($form['general']);
  }
  return $form;
}

/**
 * Form for the mailing list settings.
 */
function mailchimp_extras_group_settings_form_submit(&$form, &$form_state, $mcapi = NULL) {
  $new_group = FALSE;
  if ($mcapi || $mcapi = mailchimp_get_api_object()) {
    $api = variable_get('mailchimp_api_key', '');
    $list = mailchimp_lists_load(variable_get('mailchimp_extras_main_list', ''));
    if(isset($form_state['values']['mailchimp_extras_defaultgroups'])) {
      variable_set('mailchimp_extras_defaultgroups', $form_state['values']['mailchimp_extras_defaultgroups']);
    }
    $default = $form_state['values']['mailchimp_extras_defaultgroups'];
    if(isset($form_state['values']['mailchimp_extras_newgroupid'])) {
      $new_group_id = $form_state['values']['mailchimp_extras_newgroupid'];
    }
    if(isset($form_state['values']['mailchimp_extras_existinggroupid'])){
      $existing_group_id = $form_state['values']['mailchimp_extras_existinggroupid'];
    }
    $group_name = $form_state['values']['mailchimp_extras_newgroupname'];
    if (!empty($new_group_id)) {
      if(empty($group_name)) {
        $group_name = $new_group_id;
        drupal_set_message(t("The group name was empty.  It has been set to ". $new_group_id."."), 'warning');
      }
      $new_group = $mcapi->listInterestGroupingAdd($list->mc_list_id, $new_group_id, 'checkboxes', array($group_name));
      watchdog('mailchimp_extras', '@new_group_id grouping was created successfully on @list list.',
        array('@group_name' => $group_name, '@new_group_id' => $new_group_id, '@list' => $list->label), WATCHDOG_NOTICE
      );
      return $new_group;
      drupal_set_message(t("The group was created successfully."), 'status');
    }
    elseif(!empty($existing_group_id)){
      if(empty($group_name)) {
        drupal_set_message(t("The group name can not be empty for an existing grouping. Please enter a group name."), 'error');
      }
      $new_group = $mcapi->listInterestGroupAdd($list->mc_list_id, $group_name, $existing_group_id);
      watchdog('mailchimp_extras', '@group_name was created successfully on the @list list.',
        array('@group_name' => $group_name, '@list' => $list->label), WATCHDOG_NOTICE
      );
      return $new_group;
      drupal_set_message(t("The group was created successfully."), 'status');
    }
    else {
      watchdog('mailchimp_extras', 'A problem occurred creating the grouping on @list list. Message: @msg', array(
        '@list' => $list->label,
        '@msg' => $mcapi->errorMessage,
      ), WATCHDOG_WARNING);
    }
    if($default == 1 ) {
      $default_groups = $mcapi->listInterestGroupingAdd($list->mc_list_id, 'Default', 'checkboxes', array('Registered','Purchased','Subscribed'));
      if ($default_groups) {
        watchdog('mailchimp_extras', 'Default grouping was created successfully on @list list.',
          array('@list' => $list->label), WATCHDOG_NOTICE
        );
      }
      else {
        watchdog('mailchimp_extras', 'A problem occurred creating default grouping on @list list. Message: @msg', array(
          '@list' => $list->label,
          '@msg' => $mcapi->errorMessage,
        ), WATCHDOG_WARNING);
      }
      return $default_groups;
    }
  }
}

/**
 * Function to handle Mailchimp group deletion
 */
function mailchimp_extras_delete_group_form() {
  return confirm_form(array(), t('Are you sure you want to delete this group?'), 'admin/config/services/mailchimp/groups');
}

/**
 * Submit handler for deleting groups.
 */
function mailchimp_extras_delete_group_form_submit($form, $form_state) {
  $mcapi = mailchimp_get_api_object();
  $mlid = variable_get('mailchimp_extras_main_list', '');
  $list = mailchimp_lists_load($mlid);
  $mc_group_id = filter_xss($_GET['group_id']);
  $mc_group_name = filter_xss($_GET['group_name']);
  $path = 'admin/config/services/mailchimp/groups';
  if(isset($mc_group_id)) {
    $mcapi->listInterestGroupDel($list->mc_list_id, $mc_group_name, $mc_group_id);
  }
  drupal_set_message(t("The group ". $mc_group_name ." was deleted successfully."));
  drupal_goto($path);
}
