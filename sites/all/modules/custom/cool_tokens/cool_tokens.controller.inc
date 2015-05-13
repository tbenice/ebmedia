<?php

/**
* Cool Token Controller.
*/
class CoolTokenController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'tkid' => '',
      'title' => '',
      'description' => '',
      'set_unlimited' => '',
      'max_uses' => '',
      'active' => '',
      'activates' => '',
      'set_expire' => '',
      'expires' => '',
      'data' => '',
    );
    return parent::create($values);
  }
  public function save($entity) {
    cool_tokens_update_jobs($entity);
    parent::save($entity);
  }
  public function delete($ids) {
    $entities = entity_load('cool_token', $ids);
    foreach($entities as $id => $entity) {
      cool_tokens_remove_jobs($entity);
    }
    parent::delete($ids);
  }
}

/**
 * UI controller for Tokens.
 */
class CoolTokenUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $ft_token_uri_argument_position = 3;
    $items[$this->path]['description'] = t('Manage Cool Tokens');
    $items[$this->path]['title'] = t('Cool - Tokens');
    // Set the add path to use the list function.
    $items[$this->path . '/add']['page callback'] = 'cool_tokens_type_table';
    $items[$this->path . '/add']['access callback'] = 'user_access';
    $items[$this->path . '/add']['access arguments'] = array('administer Cool tokens');
    // Pass add links through to a form factory.
    $types = cool_tokens_types();
    foreach ($types as $type => $info) {
      $items[$this->path . '/add/' . $type] = array(
        'title' => 'Add ' . $type . ' FT Token',
        'page callback' => 'cool_tokens_forms_wrapper',
        'page arguments' => array($type, NULL, 'add'),
        'access callback' => 'entity_access',
        'access arguments' => array('create', 'cool_token', $type),
        'file' => 'includes/cool_tokens.admin.inc',
        'file path' => drupal_get_path('module', 'cool_tokens'),
      );
    }
    // Pass manage (edit) calls through to the form factory.
    $items[$this->path . '/manage/%cool_tokens_token']['page callback'] = 'cool_tokens_forms_wrapper';
    $items[$this->path . '/manage/%cool_tokens_token']['page arguments'] = array(NULL, 4, 'edit');
    $items[$this->path . '/manage/%cool_tokens_token']['file path'] = drupal_get_path('module', 'cool_tokens');
    $items[$this->path . '/manage/%cool_tokens_token']['file'] = 'includes/cool_tokens.admin.inc';
    return $items;
  }
}

/**
* Cool Token Entity class.
*/
class CoolToken extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'cool_token');
  }
  protected function defaultLabel() {
    return $this->title;
  }
  protected function defaultUri() {
    return array('path' => 'ft-token/' . $this->identifier());
  }
  public function save() {
    parent::save();
    // Set activation and expiration jobs as appropriate.
    if (!($this->isActive()) && ($this->activeDate() > time())) {
      $job = array(
        'id' => $this->tkid,
        'type' => 'ft_token_activate',
        'period' => $this->activeDate() - time(),
        'periodic' => false,
      );
      $scheduler = JobScheduler::get('ft_token_activate');
      if (!($scheduler->check($job))) {
        $scheduler->set($job);
      }
    }
    if ($this->expireDate() && $this->set_expire == 1){
       $job = array(
        'id' => $this->tkid,
        'type' => 'ft_token_expire',
        'period' => (($this->expireDate() - time()) < 0) ? NULL : $this->expireDate() - time(),
        'periodic' => false,
      );
      $scheduler = JobScheduler::get('ft_token_expire');
      if (!($scheduler->check($job))) {
        $scheduler->set($job);
      }
    }
    return $this;
  }
  public function delete() {
    parent::delete();
  }
  // Return whether token is active.
  public function isActive() {
    return $this->active;
  }
  // Activate the token.
  public function activate() {
    $this->active = 1;
    $this->save();
  }
  // Expire the token.
  public function expire() {
    $this->active = 0;
    $this->save();
  }
  // Return timestamp token activation date or null if none.
  public function activeDate() {
    $activates_date = unserialize($this->activates);
    $activates_string = strtotime("{$activates_date['month']}/{$activates_date['day']}/{$activates_date['year']}");
    return (isset($activates_date)) ? $activates_string: NULL;
  }
  // Return timestamp token expiration date or null if none
  public function expireDate() {
    $expires_date = unserialize($this->expires);
    $expires_string = strtotime("{$expires_date['month']}/{$expires_date['day']}/{$expires_date['year']}");
    return (isset($expires_date)) ? $expires_string: NULL;
  }
  /**
   * Assigns a token to a user.
   * @param stdClass $user
   *   User obj of the user to assign this token to.
   *   Default = current user.
   * @param array $data
   *   Additional data to attach to the ownership.
   * @return
   *   Returns the saved ownership object, or FALSE if an
   *   ownership already exists.
   */
  public function assignToken($user=null, $data=array()) {
    if (!isset($user)) {
      global $user;
    }
    // Don't re-assign if user already owns token.
    if ($this->userHasToken($user)) {
      return FALSE;
    }
    $tkid = $this->tkid;
    $max_uses = $this->max_uses;
    $uid = $user->uid;
    $assigned = date('c', time());
    $ownership = new stdClass();
    $ownership->tkid = $this->tkid;
    $ownership->uid = $user->uid;
    $ownership->max_uses = $this->max_uses;
    $ownership->assigned = date('c', time());
    $ownership->data = $data;
    drupal_alter('cool_token_preassign_ownership', $ownership, $this);
    module_invoke_all('cool_token_preassign', $ownership, $this);
    drupal_write_record('cool_tokens_owner', $ownership);
    module_invoke_all('cool_token_assigned', $ownership, $this);
    return $ownership;
  }
  /**
   * Returns an object with db data for this token's ownership.
   * @param stdClass $user
   *   User obj of the user to return an ownership obj for.
   *   Default = current user.
   * @return stdClass $obj
   *   Object containing the ownership.
   */
  public function getOwnership($user) {
    if (!isset($user)) {
      global $user;
    }
    $uid = $user->uid;
    $tkid = $this->tkid;
    $query = db_select('cool_tokens_owner', 'fto');
    $query->fields('fto')
          ->condition('uid', $uid, '=')
          ->condition('tkid', $this->tkid, '=');
    $result = $query->execute();
    $obj = $result->fetchAssoc();
    $obj['data'] = unserialize($obj['data']);
    return (object)$obj;
  }
  /**
   * Saves an existing ownership.
   * @param stdClass $user
   *   The user who owns this token. Defaults to current user.
   * @param stdClass $ownership
   *   Ownership object to save.
   */
  public function saveOwnership($ownership) {
    drupal_alter('cool_token_ownership_update', $ownership);
    drupal_write_record('cool_tokens_owner', $ownership, array('tkid', 'uid'));
    return $ownership;
  }
  // Remove token from user
  public function unassignToken($user) {
    if (!isset($user)) {
      global $user;
    }
    $uid = $user->uid;
    $tkid = $this->tkid;
    module_invoke_all('cool_token_preunassign', $user, $this);
    $query = db_delete('cool_tokens_owner');
    $query->condition('uid', $uid);
    $query->condition('tkid', $tkid);
    $query->execute();
    module_invoke_all('cool_token_unassigned', $user, $this);
  }
  // Fire event related to token
  public function fireTokenEvent($args=array()) {
    rules_invoke_event('ft_tokens_apply_token_' . $this->tkid, $this, $args);
    rules_invoke_event('ft_token_applied', $this, $args);
  }
  /** 
   * Use token, mark its use in database, and fire its related event.
   * @param stdClass $user
   *   The user who owns the token.
   * @param array $args
   *   Array of arguments to pass through to the token rule event(s).
   */
  public function useToken($user=NULL, $args=array()) {
    // Check that the token is active
    if (!($this->isActive())) {
      form_set_error('title','The token is not active.');
      return FALSE;
    }
    if (!isset($user)) {
      global $user;
    }
    // Grab the ownership for this token.
    $ownership = $this->getOwnership($user);
    // Check that the token has not reached max uses.
    if(!$this->tokenHasUses($user)) {
      $message = (isset($ownership->data['token_overuse_error_message'])) ? t($ownership->data['token_overuse_error_message']) : t('Your token has reached its maximum uses.');
      form_set_error('title', $message);
      return FALSE;
    }
    // Update the ownership with additional use.
    $ownership->num_used += 1;
    drupal_alter('cool_token_preuse_args', $args, $ownership, $this);
    module_invoke_all('cool_token_preuse', $ownership, $this, $args);
    // Save the ownership.
    $ownership = $this->saveOwnership($ownership);
    // Fire rule event(s).
    $this->fireTokenEvent($args);
    module_invoke_all('cool_token_used', $ownership, $this, $args);
  }
  // Check to see if user actually has the specified token
  public function userHasToken($user = NULL) {
    if (!isset($user)) {
      global $user;
    }

    $tkid = $this->tkid;
    $uid = $user->uid;

    $result = db_query("SELECT tkid, uid FROM {cool_tokens_owner} WHERE tkid = $tkid && uid = $uid")->fetchObject();

    if($result) {
      return TRUE;
    }
    else{
      return FALSE;
    }
  }
  /**
   * Checks to see if the token has uses for a given user ownership.
   * @param stdClass $user
   *   The user who owns the token. Defaults to the current user.
   * @return
   *   Returns true if the token ownership has uses available, or false
   *   if either the user does not own the token or there are no
   *   available uses.
   */
  public function tokenHasUses($user=NULL) {
    if (!isset($user)) {
      global $user;
    }
    // Return false if user does not own the token.
    if (!($ownership = $this->getOwnership($user))) {
      return FALSE;
    }
    // Return true if the token has unlimited uses.
    if ($ownership->max_uses == 0) {
      return TRUE;
    }
    // Return false if there are no available uses.
    if ($ownership->num_used >= $ownership->max_uses) {
      return FALSE;
    }
    return TRUE;
  }
  // Gets URL to enable token to be redeemed
  public function getUri($redirectPath='/', $args=array()) {
    $ft_token = $this->tkid;
    if ($ft_token) {
      // Set the default uri.
      $query = array_merge(array('fttoken' => $ft_token, 'ftpath' => $redirectPath), $args);
      $uri = array(
        'path' => 'tokens/redeemcodeurl',
        'options' => array(
          'html' => TRUE,
          'absolute' => TRUE,
          'query' => $query,
        ),
      );
      // Let modules change the uri.
      drupal_alter('cool_tokens_redeem_uri', $uri, $this);
      // Modules have the option to kill a token redeem link
      // by unsetting the uri variable.
      if (!empty($uri)) {
        return url($uri['path'], $uri['options']);
      }
    }
    return FALSE; 
  }
  // Returns a link with a token uri.
  public function getLink($text='Redeem Token', $redirectPath='/', $args=array(), $classes=array()) {
    $link = l($text, $this->getUri($redirectPath, $args));
    module_invoke_all('cool_tokens_redeem_link_alter', $link, $this);
    return $link;
  }
}

/**
* Cool Tokens Type class.
*/
class CoolTokensType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  public function __construct($values = array()) {
    parent::__construct($values, 'cool_tokens_type');
  }

  protected function defaultLabel() {
    return $this->title;
  }
  protected function defaultUri() {
    return array('path' => 'ft-token-type/' . $this->identifier());
  }
  public function save() {
    parent::save();
  }
  public function delete() {
    parent::delete();
  }
}

/**
 * UI controller for Token Types.
 */
class CoolTokensTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage Cool Tokens Types');
    $items[$this->path]['title'] = t('Cool Tokens Types');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    
    return $items;
  }
}

/**
* Cool Token Type Controller.
*/
class CoolTokensTypeController extends EntityAPIController {
  public function create(array $values = array()) {
    $values += array(
      'type' => '',
      'label' => '',
      'description' => '',
    );
    return parent::create($values);
  }
}
