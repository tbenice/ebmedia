<?php
/**
* @file campaign_api.controller.inc
*  Campaigns Entity Controller.
*/

class CampaignController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'campaign_id' => '',
      'title' => '',
      'description' => '',
      'active' => '',
      'activates' => '',
      'set_expire' => '',
      'expires' => '',
      'data' => '',
    );
    return parent::create($values);
  }
  public function save($entity) {
    parent::save($entity);
    campaign_api_update_jobs($entity);
    return $this;
  }
  public function delete($ids) {
    $entities = entity_load('campaign', $ids);
    foreach($entities as $entity) {
      // Delete Component Entities.
      foreach($entity->data['plugin_data']['entities'] as $type => $attached_entities) {
        foreach($attached_entities as $attached_entity) {
          $id = entity_id($type, $attached_entity);
          entity_delete($type, $id);
        }
      }
      // Remove any jobs.
      campaign_api_remove_jobs($entity);
      parent::delete(array($entity->campaign_id));
      // Don't need to delete rules. They will delete via hook_default_rules_configuration().
      campaign_api_rebuild_default_entities($entity);
    }
  }
}

/**
 * UI controller for Campaigns.
 */
class CampaignUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage Campaigns');
    $items[$this->path]['title'] = t(' - Campaigns');
    // Set the add path to use the list function.
    $items[$this->path . '/add']['page callback'] = 'campaign_type_table';
    $items[$this->path . '/add']['access callback'] = 'user_access';
    $items[$this->path . '/add']['access arguments'] = array('administer  campaigns');
    // Pass add links through to a form factory.
    $types = campaign_types();
    foreach ($types as $type => $info) {
      $items[$this->path . '/add/' . $type] = array(
        'title' => 'Add ' . $type . '  - Campaign',
        'page callback' => 'campaign_api_forms_wrapper',
        'page arguments' => array($type, NULL, 'add'),
        'access callback' => 'entity_access',
        'access arguments' => array('create', 'campaign', $type),
        'file' => 'includes/campaign_api.admin.inc',
        'file path' => drupal_get_path('module', 'campaign_api'),
      );
    }
    // Pass manage (edit) calls through to the form factory.
    $items[$this->path . '/manage/%campaign']['page callback'] = 'campaign_api_forms_wrapper';
    $items[$this->path . '/manage/%campaign']['page arguments'] = array(NULL, 4, 'edit');
    $items[$this->path . '/manage/%campaign']['file path'] = drupal_get_path('module', 'campaign_api');
    $items[$this->path . '/manage/%campaign']['file'] = 'includes/campaign_api.admin.inc';
    return $items;
  }
}

/**
*  Campaign Entity class.
*/
class Campaign extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'campaign');
  }
  protected function defaultLabel() {
    return $this->title;
  }
  protected function defaultUri() {
    return array('path' => '-campaigns/' . $this->identifier());
  }
  // Return whether campaign is active.
  public function isActive() {
    return $this->active;
  }
  // Activate the campaign.
  public function activate() {
    $this->active = 1;
    $this->save();
  }
  // Expire the campaign.
  public function expire() {
    $this->active = 0;
    $this->save();
  }
  // Return timestamp campaign activation date or null if none.
  public function activeDate() {
    $activates_date = $this->activates;
    $activates_string = strtotime("{$activates_date['month']}/{$activates_date['day']}/{$activates_date['year']}");
    return (isset($activates_date)) ? $activates_string: NULL;
  }
  // Return timestamp campaign expiration date or null if none
  public function expireDate() {
    $expires_date = $this->expires;
    $expires_string = strtotime("{$expires_date['month']}/{$expires_date['day']}/{$expires_date['year']}");
    return (isset($expires_date)) ? $expires_string: NULL;
  }

}

/**
*  Campaigns Type class.
*/
class CampaignType extends Entity {
  public $type;
  public $label;
  public $weight = 0;
  public $class = 'CampaignDefault';

  public function __construct($values = array()) {
    parent::__construct($values, 'campaign_type');
  }

  protected function defaultLabel() {
    return $this->title;
  }
  protected function defaultUri() {
    return array('path' => 'admin/structure/-campaigns/types/' . $this->identifier());
  }
}

/**
 * UI controller for Campaign Types.
 */
class CampaignTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage  Campaign Types');
    $items[$this->path]['title'] = t(' Campaign Types');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    return $items;
  }
}

/**
*  Campaign Type Controller.
*/
class CampaignTypeController extends EntityAPIController {
  public function create(array $values = array()) {
    $values += array(
      'type' => '',
      'label' => '',
      'description' => '',
      'class' => 'CampaignDefault',
    );
    return parent::create($values);
  }
}

/**
 *  CoolKeys Group Controller.
 */
class CoolKeysGroupController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'kgid' => '',
      'weight' => '',
      'title' => '',
      'description' => '',
      'set_unlimited_keys' => '',
      'num_keys' => '',
      'max_uses' => '',
      'set_unlimited_uses' => '',
      'uid' => $user->uid,
      'active' => '',
      'activates' => '',
      'set_expire' => '',
      'expires' => '',
      'data' => '',
    );
    return parent::create($values);
  }
  public function save($entity) {
    campaign_api_cool_keys_update_jobs($entity);
    campaign_api_cool_keys_fix_prefix($entity);
    // Set the kgid if it is not already set and set to is_new.
    if (empty($entity->kgid)) {
      $kgid_base = strtolower(preg_replace('/[\s|-]+/', '_', $entity->title));
      // Find a kgid that is not used.
      module_load_include('admin.inc', 'campaign_api', 'includes/campaign_api');
      $i = 0;
      $kgid = $kgid_base;
      while(campaign_api_key_group_name_exists($kgid)) {
        $kgid = $kgid_base . '_' . $i++;
      }
      $entity->kgid = $kgid;
      $entity->is_new = TRUE;
    }
    // Add the key codes.
    $entity->addKeyCodes();
    parent::save($entity);
  }
  public function delete($ids) {
    $entities = entity_load('cool_keys_key_group', $ids);
    foreach($entities as $id => $entity) {
      campaign_api_cool_keys_remove_jobs($entity);
    }
    parent::delete($ids);
  }
}

/**
 * UI controller for Groups.
 */
class CoolKeysGroupUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage CoolKeys Groups.');
    $items[$this->path]['title'] = t('CoolKeys');
    return $items;
  }
}

/**
 *  CoolKeys Group Entity class.
 */
class CoolKeysGroup extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'cool_keys_key_group');
  }

  protected function defaultLabel() {
    return $this->title;
  }
  protected function defaultUri() {
    return array('path' => 'cool-keys-groups/' . $this->identifier());
  }
  public function save() {
    parent::save();
  }
  public function delete() {
    parent::delete();
    // Delete any key codes.
    $query = db_delete('cool_keys_key_codes')
      ->condition('kgid', $this->kgid)
      ->execute();
  }
  /**
   * Creates key codes for the key group.
   * @param integer $num_keys
   *   Optional- the number of keys to generate.
   *   If not supplied then keys will be generated
   *   up to the number specified in the group settings.
   *
   * Uses recursion to complete the requested # of
   * keys in case there are duplicates.
   */
  private function makeKeyCodes($num_keys = NULL) {
    // Get the number of keys available within this group.
    // Must be positive integer or 0.
    if (!isset($num_keys)) {
      // Check for existing key codes.
      $result = db_select('cool_keys_key_codes', 'fkc')
        ->fields('fkc')
        ->condition('kgid', $this->kgid, '=')
        ->execute()
        ->fetchAllAssoc('kcid');
      $available = $this->num_keys - count($result);
      $num_keys = ($available > 0) ? $available : 0;
    }

    // Create the key codes.
    $i=1;
    $e=1;
    $keys = array();
    while ($i++ <= $num_keys) {
      // Suffix the key code prefix with '_' if it is set.
      $prefix = (isset($this->data['key_code_prefix'])) ? ((!($this->data['key_code_prefix'] == '')) ? $this->data['key_code_prefix'] . '_' : '') : '';
      $keys[] = uniqid($prefix, TRUE);
    }
    $filtered_keys = array_unique($keys);
    $needed = $num_keys - count($filtered_keys);
    $more_keys = array();
    if ($needed) {
      $more_keys = $this->makeKeyCodes($needed);
    }
    return array_merge($keys, $more_keys);
  }
  /**
   * Adds key codes to this group.
   * @param integer $num_keys
   *   The number of keys to add. If null then
   *   adds a number of keys up to the number
   *   specified in the group settings.
   */
  public function addKeyCodes($num_keys = NULL) {
    $keys = $this->makeKeyCodes($num_keys);
    foreach($keys as $key_code) {
      $query = db_insert('cool_keys_key_codes')->fields(array('key_code', 'kgid', 'max_uses', 'issued'));
      $query->values(array($key_code,$this->kgid,$this->max_uses,0));
      $query->execute();
    }
    return $keys;
  }
  /**
   * Returns whether the key group is active.
   */
  public function isActive() {
    return $this->active;
  }
  /**
   * Activates the key group.
   */
  public function activate() {
    $this->active = 1;
    $this->save();
  }
  /**
   * Expires the key group.
   */
  public function expire() {
    $this->active = 0;
    $this->save();
  }
  /**
   * Returns whether the key group is set
   * to produce unlimited number of keys.
   */
  public function isUnlimited() {
    return $this->set_unlimited_keys;
  }
  // Return timestamp discount activation date or null if none.
  public function activeDate() {
    $activates_date = unserialize($this->activates);
    $activates_string = strtotime("{$activates_date['month']}/{$activates_date['day']}/{$activates_date['year']}");
    return (isset($activates_date)) ? $activates_string: NULL;
  }
  // Return timestamp disount expiration date or null if none
  public function expireDate() {
    $expires_date = unserialize($this->expires);
    $expires_string = strtotime("{$expires_date['month']}/{$expires_date['day']}/{$expires_date['year']}");
    return (isset($expires_date)) ? $expires_string: NULL;
  }
  public function getKey() {
    $kgid = $this->kgid;
    $key_query = db_select('cool_keys_key_codes');
    $key_query->fields('cool_keys_key_codes', array('kcid', 'kgid', 'key_code', 'issued'));
    $key_query->condition('kgid', $kgid);
    $key_query->condition('issued', 0);
    $key_query->range(NULL, 1);
    $key_result = $key_query->execute()->fetchAssoc();
    // Grab the key code if exists, otherwise set to null.
    $key_code = isset($key_result['key_code']) ? $key_result['key_code'] : null;

    // If no keys available, add one if group is unlimited.
    if((!isset($key_code)) && ($this->isUnlimited())) {
      $new_keys = $this->addKeyCodes(1);
      $key_code = $new_keys[0];
    }

    if($key_code) {
      $this->issueKey($key_code);
      return $key_code;
    }
    return FALSE;
  }
  /**
   * Set a key code to issued.
   * An issued key can not be re-issued.
   * @param integer $ck_code
   */
  public function issueKey($ck_code) {
    $kgid = $this->kgid;
    $key_query = db_select('cool_keys_key_codes');
    $key_query->fields('cool_keys_key_codes', array('kcid', 'kgid', 'key_code', 'issued'));
    $key_query->condition('key_code', $ck_code);
    $key_query->condition('kgid', $kgid);
    $key_result = $key_query->execute()->fetchAssoc();

    if($key_result) {

      $ck_code = $key_result['key_code'];

      db_update('cool_keys_key_codes')
        ->expression('issued', 1)
        ->condition('key_code', $ck_code)
        ->execute();

      return TRUE;
    }
    return FALSE;
  }
  /**
   * Sets a key code to not issued.
   * @param integer $ck_code
   */
  public function reclaimKey($ck_code) {
    $kgid = $this->kgid;
    $key_query = db_select('cool_keys_key_codes');
    $key_query->fields('cool_keys_key_codes', array('kcid', 'kgid','key_code','issued'));
    $key_query->condition('key_code', $ck_code);
    $key_query->condition('kgid', $kgid);
    $key_result = $key_query->execute()->fetchAssoc();

    if($key_result) {

      $ck_code = $key_result['key_code'];

      db_update('cool_keys_key_codes')
        ->expression('issued', 0)
        ->condition('key_code', $ck_code)
        ->execute();
    }
  }
  /**
   * Returns a link that will redeem a key code when followed.
   * @param string $text
   *   Optional- The text to use in the link. Can contain HTML.
   *   Defaults to 'Redeem Code'.
   * @param string $redirectPath
   *   The path to redirect the user to when the key is redeemed
   *   by following the generated link. It can be relative or
   *   absolute.
   * @param array $args
   *   Additional arguments to pass into the get query for the
   *   generated link. The query will be generated as:
   *   key=>value == ?key=value in the query string.
   */
  public function getUri($text = 'Redeem Code', $redirectPath = '/', $args = array()) {
    $ck_code = $this->getKey();
    if ($ck_code) {
      // Set the default uri.
      $query = array_merge(array('ckkey' => $ck_code, 'ckpath' => $redirectPath), $args);
      $uri = array(
        'path' => 'cool-keys/redeemcodeurl',
        'text' => $text,
        'options' => array(
          'html' => TRUE,
          'absolute' => TRUE,
          'query' => $query,
        ),
      );
      // Let modules change the uri.
      drupal_alter('cool_keys_uri', $uri, $this);
      return l($uri['text'], $uri['path'], $uri['options']);
    }
    return FALSE;
  }
}
