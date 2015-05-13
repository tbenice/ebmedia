<?php
/**
 * common_support.api.inc
 */

/**
 * hook_common_support_import().
 *
 * This hook lets common_support know that your
 * module intends to import some non-ctools settings
 * during enablement.
 *
 * You must return an array of "assets" with valid values
 * (any key will do). The valid values correspond to
 * settings that import currently supports. See the code
 * below for the current list of supported settings.
 *
 * In order for anything to be imported you have to create
 * some export files. These are always in the form:
 *   mymodule.TYPE.inc
 * and the function to return exported settings should be
 * defined as:
 *   mymodule_default_TYPE_assets() {}
 * where TYPE is the type being returned in this hook.
 * E.G. node_type import would have function:
 * mymodule_default_node_type_assets() {} to be found in
 * file mymodule.node_type.inc.
 *
 * It is possible to use the features module to prototype
 * exports and then tweak them to meet the above requirements.
 * That is what I do! Or you can write your own code. Usually
 * I create my exports and then just adjust them in code as
 * needed.
 *
 * @return array $assets
 *   List of asset names that should be imported upon
 *   enabling the module.
 */
function hook_common_support_import() {
  return array(
    'node_type',
    'field_base',
    'field_instance',
    'commerce_product',
    'vocabulary',
    'user_role',
    'user_permission',
    'variable',
    'nodequeue',
  );
}

/**
 * hook_common_support_delete_import().
 *
 * This hook lets common_support know that your
 * module intends to delte some non-ctools settings
 * during uninstall.
 *
 * You must return an array of "assets" with valid values
 * (any key will do). The valid values correspond to
 * settings that import currently supports. See the code
 * below for the current list of supported settings.
 *
 * NOTE: Some assets may not delete cleanly or at all.
 * Field instances and bases for example may not delete
 * if there is currently data occupying the fields that
 * you are intending to delete.
 *
 * @return array $assets
 *   List of asset names that should be deleted upon
 *   uninstalling the module.
 */
function hook_common_support_delete_import() {
  return array(
    'node_type',
    'field_base',
    'field_instance',
    'commerce_product',
    'vocabulary',
    'user_role',
    'user_permission',
    'variable',
    'nodequeue',
  );
}

/**
 * Lets other modules alter the assets to be imported for a module.
 *
 * @param $assets
 *  The list of intended assets to be altered.
 * @param $module
 *  The module that intends to import the assets.
 */
function hook_common_support_import_assets_alter(&$assets, $module) {

}

/**
 * Lets modules react when assets are about to be imported.
 *
 * @param $assets
 *   The list of assets that will (attempt to) be imported.
 * @param $module
 *   The module that intends to import the assets.
 */
function hook_common_support_pre_import_assets($assets, $module) {

}

/**
 * Lets modules react after assets have been imported.
 *
 * @param $assets
 *   The list of assets that have been/attempted to be imported.
 * @param $module
 *   The module that intends to import the assets
 */
function hook_common_support_post_import_assets($assets, $module) {

}

/**
 * Lets modules react when assets are about to be deleted.
 *
 * @param $assets
 *   The list of assets that will (attempt to) be deleted.
 * @param $module
 *   The module that intends to delete the assets
 */
function hook_common_support_pre_delete_assets($assets, $module) {

}

/**
 * Lets modules react when assets have been deleted.
 *
 * @param $assets
 *   The list of assets that have been/attempted to be deleted.
 * @param $module
 *   The module that intended to delete the assets
 */
function hook_common_support_post_delete_assets($assets, $module) {

}
