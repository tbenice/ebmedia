<?php
/**
 * @file common_support_importers.inc
 */

define('COMMON_SUPPORT_EXPORT_MALFORMED', 0);
define('COMMON_SUPPORT_IMPORT_SAVE_ERROR', 1);
define('COMMON_SUPPORT_IMPORT_ASSET_EXISTS', 2);
define('COMMON_SUPPORT_IMPORT_SUCCESS', 3);

/**
 * Imports various non-ctools exportables.
 * This function is called by common_support_modules_installed().
 * You shouldn't ever need to use it.
 * @param $module
 *   The module that needs imports on install.
 * @param $assets
 *
 */
function common_support_import($module, $assets) {
  // Allow modules to alter the $assets or $module.
  drupal_alter('common_support_import_assets', $assets, $module);
  // Allow modules to act before deleting $assets from $module.
  module_invoke_all('common_support_pre_import_assets', $assets, $module);
  $errors = array();
  foreach($assets as $asset) {
    // Only proceed if there is a valid import file.
    $success = module_load_include('inc', $module, "$module.$asset");
    if (!$success) {
      watchdog("$module $asset import", t("No valid include file."));
      $errors[$module] = $asset;
      continue;
    }
    // Try getting the import array.
    try {
      $import = call_user_func("{$module}_default_{$asset}_assets");
    }
    catch(Exception $e) {
      watchdog("{$module}_default_{$asset}_assets", t("Could not find a valid import function for $module:$asset."));
      $errors[$module] = $asset;
      continue;
    }
    // Try importing and respond if there are errors.
    switch(call_user_func("common_support_import_$asset", $import, $module)) {
      case COMMON_SUPPORT_EXPORT_MALFORMED:
        watchdog("$module $asset import", t("Could not import $asset -- import array is malformed."), array(), WATCHDOG_ERROR);
        $errors[$module] = $asset;
        break;
      case COMMON_SUPPORT_IMPORT_SAVE_ERROR:
        watchdog("$module $asset import", t("Could not import $asset -- error during save."), array(), WATCHDOG_ERROR);
        $errors[$module] = $asset;
        break;
      case COMMON_SUPPORT_IMPORT_ASSET_EXISTS:
        watchdog("$module $asset import", t("$asset not imported, already exists."), array(), WATCHDOG_ERROR);
        break;
      case COMMON_SUPPORT_IMPORT_SUCCESS:
        watchdog("$module $asset import", t("$asset imported successfully."));
        break;
    }
  }
  // Message if there were any errors.
  if (!empty($errors)) {
    $error_list = implode("\n", $errors);
    $message = "There were errors importing some assets: $error_list";
    drupal_set_message($message, 'error');
  }
  // Allow modules to act after deleting $assets from $module.
  module_invoke_all('common_support_post_import_assets', $assets, $module);
}

/**
 * Deletes various non-ctools exportables.
 * This function is called by common_support_modules_uninstalled().
 * You shouldn't ever need to use it.
 * @param $module
 *   The module that needs imports on install.
 * @param $assets
 *
 */
function common_support_delete_import($module, $assets) {
  // Allow modules to alter the $assets or $module.
  $assets = drupal_alter('common_support_import_assets', $assets, $module);
  // Allow modules to act before deleting $assets from $module.
  module_invoke_all('common_support_pre_delete_assets', $assets, $module);
  $errors = array();
  foreach($assets as $asset) {
    // Only proceed if there is a valid import file.
    $success = module_load_include($module, "$module.$asset");
    if (!$success) {
      watchdog("$module $asset import", t("No valid include file."));
      $errors[$module] = $asset;
      continue;
    }
    // Try getting the import array.
    try {
      $import = call_user_func("{$module}_default_{$asset}_assets");
    }
    catch(Exception $e) {
      watchdog("{$module}_default_{$asset}_assets", t("Could not find a valid import function for $module:$asset."));
      $errors[$module] = $asset;
      continue;
    }
    // Try deleting and respond if there are errors.
    switch(call_user_func("common_support_delete_$asset", $import, $module)) {
      case COMMON_SUPPORT_EXPORT_MALFORMED:
        watchdog("common_support_delete_$asset", t("Could not delete $asset -- import array is malformed."));
        $errors[$module] = $asset;
        break;
      case COMMON_SUPPORT_IMPORT_SAVE_ERROR:
        watchdog("common_support_delete_$asset", t("Could not delete $asset -- error during save."));
        $errors[$module] = $asset;
        break;
      case COMMON_SUPPORT_IMPORT_ASSET_EXISTS:
        watchdog("common_support_delete_$asset", t("$asset not deleted, does not exist."));
        break;
    }
  }
  // Message if there were any errors.
  if (!empty($errors)) {
    $error_list = implode("\n", $errors);
    $message = "There were errors deleting some assets: $error_list";
    drupal_set_message($message, 'error');
  }
  // Allow modules to act after deleting $assets from $module.
  module_invoke_all('common_support_post_delete_assets', $assets, $module);
}

/**
 * Imports nodes from a features-style export.
 * @param array $export
 *   Array of nodes.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_node_type($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $type_name => $type) {
    // Look for existing node type.
    if (!node_type_load($type_name)) {
      $new_type = (object)$type;
      $new_type = node_type_set_defaults($new_type);
      $new_type->module = $module;
      $new_type->type = $type_name;
      // Needed for https://www.drupal.org/node/2465159.
      $new_type->custom = 1;
      $new_type->locked = 0;
      if (node_type_save($new_type)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports commerce_product_type from a features-style export.
 * @param array $export
 *   Array of commerce products.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_commerce_product($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $type_name => $type) {
    // Look for existing commerce_product type.
    if (!commerce_product_type_load($type_name)) {
      if (commerce_product_ui_product_type_save($type)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports field_bases from a features-style export.
 * @param array $export
 *   Array of field_bases.
 * @return bool
 *   Returns TRUE on success, FALSE on failure.
 */
function common_support_import_field_base($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $field_name => $field_base) {
    // Look for existing field base.
    if (!field_info_field($field_name)) {
      if (field_create_field($field_base)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports field_instances from a features-style export.
 * @param array $export
 *   Array of field_instances.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_field_instance($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $field_instance) {
    // Look for existing field instances.
    if (!field_info_instance($field_instance['entity_type'], $field_instance['field_name'], $field_instance['bundle'])) {
      if (field_create_instance($field_instance)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports taxonomy vocabularies from a features-style export.
 * @param array $export
 *   Array of taxonomy vocabularies.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_vocabulary($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $vocabulary) {
    // Look for existing vocabulary.
    if (!taxonomy_vocabulary_machine_name_load($vocabulary['machine_name'])) {
      if (taxonomy_vocabulary_save($vocabulary)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports user roles from a features-style export.
 * @param array $export
 *   Array of user roles.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_user_role($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $user_role) {
    // Look for existing role.
    if (!user_role_load_by_name($user_role['name'])) {
      $role = (object)$user_role;
      $role->is_new = TRUE;
      if (user_role_save($role)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports user_permissions from a features-style import.
 * @param array $export
 *   Array of user permissions.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_user_permission($export = array(), $module = 'common_support') {
  if ((empty($export)) || (!is_array($export))) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  // @todo could probably do this more elegantly with some array manipulations.
  foreach($export as $user_permission) {
    foreach($user_permission['roles'] as $role_name) {
      $role = user_role_load_by_name($role_name);
      $permission = array(
        $user_permission['name'] => TRUE,
      );
      if(user_role_change_permissions($role->rid, $permission)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    return COMMON_SUPPORT_IMPORT_SUCCESS;
  }
}

/**
 * Imports variables from a strongarm (features)-style import.
 * @param array $export
 *   Array of variables.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_variable($export = array(), $module = 'common_support') {
  if (empty($export)) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $variable) {
    if (!variable_get($variable->name, FALSE)) {
      try {
        variable_set($variable->name, $variable->value);
      }
      catch(Exception $e) {
        watchdog('common_support_import_variables', $e->getMessage());
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports image styles from a (features)-style import.
 * @param array $export
 *   Array of image styles.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_image_style($export = array(), $module = 'common_support') {
  if (empty($export)) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $style) {
    // Look for existing image style.
    $current_style = image_style_load($style['name']);
    if (!isset($current_style['isid'])) {
      if(image_default_style_save($style)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

/**
 * Imports nodequeues from a (features)-style import.
 * @param array $export
 *   Array of nodequeues.
 * @return bool
 *   TRUE on success, FALSE on failure.
 */
function common_support_import_nodequeue($export = array(), $module = 'common_support') {
  if (empty($export)) {
    return COMMON_SUPPORT_EXPORT_MALFORMED;
  }
  foreach($export as $nodequeue) {
    // Look for existing nodequeue.
    if (!nodequeue_load_queue_by_name($nodequeue['name'])) {
      // Assign the existing qid if a nodequeue with the same name already exists.
      $map = common_support_nodequeue_get_qid_map();
      if (isset($map[$nodequeue['name']])) {
        $nodequeue['qid'] = $map[$nodequeue['name']];
      }
      // Clear the qid if it is a new nodequeue.
      else {
        unset($nodequeue['qid']);
      }
      if(common_support_nodequeue_save_queue((array) $nodequeue)) {
        continue;
      }
      else {
        return COMMON_SUPPORT_IMPORT_SAVE_ERROR;
      }
    }
    else {
      return COMMON_SUPPORT_IMPORT_ASSET_EXISTS;
    }
  }
  return COMMON_SUPPORT_IMPORT_SUCCESS;
}

//@todo add delete functions.