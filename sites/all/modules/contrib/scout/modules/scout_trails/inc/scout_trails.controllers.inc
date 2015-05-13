<?php

/**
* Scout Trails Controllers.
*/

/**
* Scout Trails class.
*/
class ScoutTrail extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'scout_trail');
  }

  protected function defaultLabel() {
    return $this->title;
  }

  // This entity is not intended to generally viewed anywhere other
  // than as content presented by Joyride Jquery or in an admin interface,
  // so we'll start with the default being the same as the admin uri.
  protected function defaultUri() {
    return array('path' => 'admin/content/scout-trails/' . $this->identifier());
  }
  public function save() {
    parent::save();
  }
  public function delete() {
    parent::delete();
  }
}

/**
* Scout Trail Type class.
*/
class ScoutTrailType extends Entity {
  public $type;
  public $label;
  public $weight = 0;
  public function __construct($values = array()) {
    parent::__construct($values, 'scout_trail_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

/**
* Scout Tips class.
*/
class ScoutTip extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'scout_tip');
  }

  protected function defaultLabel() {
    return $this->title;
  }

  // This entity is not intended to generally viewed anywhere other
  // than as content presented by Joyride Jquery or in an admin interface,
  // so we'll start with the default being the same as the admin uri.
  // Also, this entity is always associated with (a component of) the ScoutTrail entity above.
  // So here we also start with the admin uri for those trails.
  protected function defaultUri() {
    return array('path' => 'admin/content/scout-trails/scout-tips/' . $this->identifier());
  }

  public function save() {
    parent::save();
  }
  public function delete() {
    parent::delete();
  }

}

/**
* Scout Tip Type class.
*/
class ScoutTipType extends Entity {
  public $type;
  public $label;
  public $weight = 0;
  public function __construct($values = array()) {
    parent::__construct($values, 'scout_tip_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }
}

/**
* Scout Trail Type Controller.
*/
class ScoutTrailTypeController extends EntityAPIControllerExportable {
   public function create(array $values = array()) {
    $values += array(
      'label' => '',
      'description' => '',
    );
    return parent::create($values);
  }

  /**
   * Save Scout Trail Type.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    // Rebuild menu registry. We do not call menu_rebuild directly, but set
    // variable that indicates rebuild in the end.
    // @see _http://drupal.org/node/1399618
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
* Scout Tip Type Controller.
*/
class ScoutTipTypeController extends EntityAPIControllerExportable {
   public function create(array $values = array()) {
    $values += array(
      'label' => '',
      'description' => '',
    );
    return parent::create($values);
  }

  /**
   * Save Scout Tip Type.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    // Rebuild menu registry. We do not call menu_rebuild directly, but set
    // variable that indicates rebuild in the end.
    // @see _http://drupal.org/node/1399618
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
* Scout Trails Controller.
*/
class ScoutTrailController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'title' => '',
      'description' => '',
      'tag' => '(default)',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
      'is_new' => TRUE,
      'status' => 1,
      'language' => LANGUAGE_NONE,
      'module' => 'scout_trails',
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('scout_trail', $entity);

    // Make Description, last updated and author
    // themed like default fields.
    $content['description'] = array(
      '#theme' => 'field',
      '#weight' => 0,
      '#title' =>t('Description'),
      '#access' => TRUE,
      '#label_display' => 'hidden',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#entity_type' => 'scout_trail',
      '#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->description)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->description))
    );

     $content['updated'] = array(
       '#markup' => t('<div class-"scout-trail-plain-entity-updated">Updated: !update </div>', array('!update' => format_date($entity->changed, 'short')))
     );

     $content['author'] = array(
       '#markup' => t('<div class-"scout-trail-plain-entity-scout">Scout: !author </div>', array('!author' => $wrapper->uid->name->value(array('sanitize' => TRUE))))
     );

     // Set Breadcrumbs
    scout_trails_set_breadcrumb();
    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}

/**
 * UI controller for Scout Trails.
 */
class ScoutTrailUIController extends EntityBundleableUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $scout_trail_uri_argument_position = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    // This plugs Scout Trails into the Content menu as a tab
    $items[$this->path] = array(
      'title' => 'Scout Trails',
      'description' => 'Add edit and update scout trails.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the add page default access callback
    // to a function that skips having to select type when there is only one.
    // (See scout_trails.pages.inc)
    $items[$this->path . '/add']['page callback'] = 'scout_trail_add_page';

    // Pass add links through to a form factory.
    $types = scout_trail_types();
    foreach ($types as $type => $info) {
      $items[$this->path . '/add/' . $type] = array(
        'title' => 'Add Scout Trail of type ' . $type,
        'page callback' => 'scout_trails_forms_wrapper',
        'page arguments' => array($type, NULL, 'add'),
        'access callback' => 'entity_access',
        'access arguments' => array('create', 'scout_trail', $type),
        'file' => 'inc/scout_trails.trails.admin.inc',
        'file path' => drupal_get_path('module', 'scout_trails'),
      );
    }

    // EntityBundleableUIController handles loading and editing scout trail entities.
    // Deleting scout trail entities.
    $items[$this->path . '/' . $wildcard . '/delete'] = array(
	    'title' => t('Delete'),
	    'page callback' => 'drupal_get_form',
	    'page arguments' => array('scout_trail_delete_form', $scout_trail_uri_argument_position, 'delete'),
	    'access callback' => 'entity_access',
      'access arguments' => array('delete', 'scout_trail', $scout_trail_uri_argument_position),
	    'file' => 'inc/scout_trails.trails.admin.inc',
      'file path' => drupal_get_path('module', 'scout_trails'),
	  );
//    dsm($items,'overrride - ScoutTrailUIController');
    return $items;
  }

}

/**
 * UI controller for Scout Trails.
 */
class ScoutTipUIController extends EntityBundleableUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $scout_tip_uri_argument_position = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $defaults = array(
      'file' => $this->entityInfo['admin ui']['file'],
      'file path' =>  isset($this->entityInfo['admin ui']['file path']) ? $this->entityInfo['admin ui']['file path'] : drupal_get_path('module', $this->entityInfo['module']),
    );

    // Change the add page default access callback
    // to a function that skips having to select type when there is only one.
    // (See scout_trails.pages.inc)
    $items[$this->path . '/add']['page callback'] = 'scout_tip_admin_add_page';

    // Pass add links through to a form factory.
    // Override default titles and page callback.
    $types = scout_tip_types();
    foreach ($types as $type => $info) {
      $items[$this->path . '/add/' . $type]['title'] = t('Add Scout Tip of type ' . $type);
      $items[$this->path . '/add/' . $type]['page callback'] = 'scout_tips_forms_wrapper';
      $items[$this->path . '/add/' . $type]['page arguments'] = array($type, NULL, 'add');
      $items[$this->path . '/add/' . $type]['access callback'] = 'entity_access';
      $items[$this->path . '/add/' . $type]['access arguments'] = array('create', 'scout_tip', $type);
      $items[$this->path . '/add/' . $type]['file'] = 'inc/scout_trails.tips.admin.inc';
      $items[$this->path . '/add/' . $type]['file path'] = drupal_get_path('module', 'scout_trails');
   }

    // EntityBundleableUIController handles loading and editing scout tip entities.

    // Add delete menu items.
    $items[$this->path . '/' . $wildcard . '/delete']['page callback'] = 'drupal_get_form';
    $items[$this->path . '/' . $wildcard . '/delete']['page arguments'] = array('scout_tip_delete_form', $this->id_count);
    $items[$this->path . '/' . $wildcard . '/delete']['file'] = 'inc/scout_trails.tips.admin.inc';
    $items[$this->path . '/' . $wildcard . '/delete']['file path'] = drupal_get_path('module', 'scout_trails');

//    dsm($items,'overrride - ScoutTipUIController');
//    dsm($this,'$entity($this) - ScoutTipUIController');

    return $items;
  }
}

/**
 * UI controller for Scout Trail Types.
 */
class ScoutTrailTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
/*
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage types of Scout Trails.');
    $items[$this->path]['title'] = t('Scout Trail types');
//    $items[$this->path]['type'] = MENU_LOCAL_TASK;
//    $items[$this->path]['type'] = MENU_DEFAULT_LOCAL_TASK;

    return $items;
  }
*/
}

/**
 * UI controller for Scout Tip Types.
 */
class ScoutTipTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
/*
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage types of Scout Tips.');
    $items[$this->path]['title'] = t('Scout Tip types');
//    $items[$this->path]['type'] = MENU_LOCAL_TASK;
//    $items[$this->path]['type'] = MENU_DEFAULT_LOCAL_TASK;
    return $items;
  }
*/
}

/**
* Scout Tip Controller.
*/
class ScoutTipController extends EntityAPIController {
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'title' => '',
      'tag' => '(default)',
      'description' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
      'is_new' => TRUE,
      'status' => 1,
      'language' => LANGUAGE_NONE,
      'module' => 'scout_trails',
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('scout_tip', $entity);
//    $content['author'] = array('#markup' => t('Created by: !author', array('!author' => $wrapper->uid->name->value(array('sanitize' => TRUE)))));

    // Make Description and Status themed like default fields.
    $content['description'] = array(
      '#theme' => 'field',
      '#weight' => 0,
      '#title' =>t('Scout Tip Title'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_label' => 'in-line',
      '#field_type' => 'text',
      '#entity_type' => 'scout_tip',
      '#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->title)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->title))
    );
    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}
