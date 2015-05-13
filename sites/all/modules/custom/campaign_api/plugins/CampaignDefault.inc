<?php
/**
 * @file CampaignDefault.inc
 * Default campaign class.
 */

/**
 * Campaign config plugin interface.
 *
 */
interface CampaignInterface {
  // Re-constitute plug-in from stored data.
  public function initialize($data = array());
  // Create necessary entities and rules for the campaign.
  public function create($campaign=NULL);
  // Create entity objects.
  public function createEntities($entities=array());
  // Create rule objects.
  public function createRules($rules=array());
  // Set configuration.
  public function setConfigData($data=array());
  // Update all objects.
  public function update($campaign=NULL);
  // Get entity objects.
  public function getEntities();
  // Get rule objects.
  public function getRules();
  // Get config data.
  public function getConfig();
  // Get all settings.
  public function getdata();
  // Create campaign settings form elements.
  public function getConfigForm($form=array(), $form_state=array(), $plugin_data=array());
  // Save config data from a campaign form.
  public function setFormConfigData($form, $form_state);
  //  Create and return table array for the config page.
  public function configTable();
}

/**
 * Default campaign config plugin class.
 */
abstract class CampaignDefault implements CampaignInterface {
  // List of campaign entities.
  protected $entities = array();
  // List of campaign rules.
  protected $rules = array();
  // Other items.
  protected $other = array();
  // Config info.
  protected $config = array();
  // Campaign.
  protected $campaign = NULL;
  // Campaign machine name.
  protected $campaignMachineName = '';
  // Config table array.
  protected $table = array();

  /**
   * Class Constructor.
   * @param array $data
   *   Data to initialize from if available.
   */
  public function __construct($campaign = NULL) {
    if (isset($campaign)) {
      $this->initialize($campaign);
    }
  }

  /**
   * Initialize the plug-in from stored data.
   * @param Campaign $campaign
   *   The campaign object from which to initialize the plugin data.
   */
  public function initialize($campaign = NULL) {
    if (!isset($campaign)) {
      return FALSE;
    }
    $this->campaign = $campaign;
    $this->campaignMachineName = campaign_api_get_campaign_machine_name($campaign);
    $this->entities = (!empty($campaign->data['plugin_data']['entities'])) ? $campaign->data['plugin_data']['entities'] : $this->entities;
    $this->rules = (!empty($campaign->data['plugin_data']['rules'])) ? $campaign->data['plugin_data']['rules'] : $this->rules;
    $this->other = (!empty($campaign->data['plugin_data']['other'])) ? $campaign->data['plugin_data']['other'] : $this->other;
    $this->config = (!empty($campaign->data['plugin_data']['config'])) ? $campaign->data['plugin_data']['config'] : $this->config;

    return $this;
  }

  /**
   * Create the campaign.
   * @param Campaign $campaign
   *   The campaign object containing data from which to create all
   *   campaign components.
   */
  public function create($campaign = NULL) {
    if (isset($campaign)) {
      $this->initialize($campaign);
    }
    $this->createEntities();
    $this->createRules();
    return $this->getData();
  }

  /**
   * Update the campaign.
   * @param $campaign.
   *   This is the updated campaign from which we will update
   *   all campaign componenets.
   *   To do this, just alter the componenets within the campaign
   *   parameter and return parent::update($campaign). The updated
   *   plugin data including the components will be returned.
   *   
   *   Also, you MUST set the $entity->campaign_updated property to TRUE
   *   otherwise the entity will not update.
   */
  public function update($campaign = NULL) {
    if (isset($campaign)) {
      $this->initialize($campaign);
    }
    return $this->getData();
  }

  /**
   * Create the entity objects.
   * @param array $entities
   *   An array of entities to set in the plugin data.
   * Override this method to create the entities your campaign
   * needs.
   */
  public function createEntities($entities = array()) {
    $this->entities = $entities;
    return $entities;
  }

  /**
   * Create the rule objects.
   * Override this method to create your default rules. You 
   * should consult hook_default_rules_configuration() for info
   * on how to create these default rules_config entities.
   * @param array rules
   *   Array of rules config entities that will be
   *   used to create default rules.
   */
  public function createRules($rules = array()) {
    foreach($rules as $rule) {
      $rule->label = $this->campaign->title . '-' . $rule->label;
    }
    $this->rules = $rules;
    return $rules;
  }

  /**
   * Helper method to create prepended ids.
   * @param string $id
   *   The id string to prepend.
   */
  protected function prependId($id) {
    return $this->campaign->campaign_id . '_' . $id;
  }

  /**
   * Method to set the plugin config data externally.
   * @param array $data
   *   The config data to set.
   */
  public function setConfigData($data=array()) {
    $this->config = $data;
  }
  /**
   * Returns an array of edit paths since they are hard to come by otherwise.
   * If your plugin uses other entities (or other) then override
   * this method to supply paths. The wildcard % will be replaced by the id
   * of the entity (or other);
   * @param string $type
   */
  protected function editPaths() {
    return array(
      'node' => 'node/%/edit',
      'cool_keys_key_group' => 'admin/structure/cool-keys-groups/%/edit',
      '_token' => 'admin/structure/-tokens/manage/%',
    );
  }
  /**
   * Return the config content.
   */
  public function configTable() {
    $table = array();
    // Add headers.
    $table['header'] = array(
      'type',
      'title',
      'edit-link',
    );
    // Add rules.
    foreach($this->rules as $name => $rule) {
      $table['rows'][$name]['data'][] = 'Rule';
      $table['rows'][$name]['data'][] = t($rule->label);
      $table['rows'][$name]['data'][] = l('edit', RulesPluginUI::path($rule->name));
    }
    // Add entities.
    foreach($this->entities as $type => $entities) {
      foreach($entities as $key => $entity) {
        $info = entity_get_info($type);
        $id = entity_id($type, $entity);
        $paths = $this->editPaths();
        $path = str_replace('%', $id, $paths[$type]);
        $table['rows'][$type.$key]['data'][] = $type;
        $table['rows'][$type.$key]['data'][] = t($entity->title);
        $table['rows'][$type.$key]['data'][] = l('edit', $path);
      }
    }
    $this->table = $table;
    $content = theme('table', $this->table);
    return $content;
  }

  /**
   * Get the entity objects.
   */
  public function getEntities() {
    return $this->entities;
  }

  /**
   * Get the rule objects.
   */
  public function getRules() {
    return $this->rules;
  }

  /**
   * Return any other objects defined by the campaign.
   */
  public function getOther() {
    return $this->other;
  }

  /**
   * Get the plugin config data.
   */
  public function getConfig() {
    return $this->config;
  }

  /**
   * Get all plugin data.
   */
  public function getdata() {
    $data = array(
      'entities' => $this->getEntities(),
      'rules' => $this->getRules(),
      'config' => $this->getConfig(),
    );
    return $data;
  }

/**
   * Create campaign config form elements.
   * Override this method to provide config elements that
   * will be displayed on the campaign edit form. Just create
   * the form elements in and array and pass that array back to
   * the parent method. The values will be automatically saved
   * into the plugin data, and also into the campaign.
   * @param array $form
   *   The campaign-type form being created using this plugin.
   * @param array $form_state
   *   The campaign-type form form_state.
   * @param array $plugin_data
   *   The current stored plugin data.
   */
  public function getConfigForm($form=array(), $form_state=array(), $plugin_data=array()) {
    // Add the default values to the plugin form elements if supplied.
    if (!empty($plugin_data)) {
      foreach($form as $name => &$element) {
        $element['#default_value'] = $plugin_data[$name];
      }
    }
    $this->config['configFormElements'] = $form;
    return $form;
  }

  /**
   * Save config form data.
   * @param $form
   *   The form array of the campaign form being saved.
   * @param $form_state
   *   The form_state array of the campaign edit form
   *   being saved.
   */
  public function setFormConfigData($form, $form_state) {
    foreach($this->getConfigForm() as $name => $element) {
      $this->config['configData'][$name] = $form_state['values'][$name];
    }
  }
}
