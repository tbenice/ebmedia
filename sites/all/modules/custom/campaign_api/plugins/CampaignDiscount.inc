<?php
/**
 * @file CampaignDiscount.inc
 * Abstract class for creating discount-based campaigns.
 */

abstract class CampaignDiscount extends CampaignDefault {

  /**
   * Create the entity objects.
   * Need some special handling for discount entities.
   * @see CampaignDefault::createEntities()
   */
  public function createEntities($entities = array()) {
    foreach ($entities['_discount'] as $key => &$discount) {
      // Initial save, inserts the discount entity into the db.
      _discount_save($discount);
      $discount = _discount_load($discount->fdid);
      $discount->is_new = FALSE;
    }
    parent::createEntities($entities);
  }
  /**
   * @see CampaignDefault::getConfigForm()
   */
  public function getConfigForm($form=array(), $form_state=array(), $plugin_data=array()) {
    $form['key_code_prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Prefix'),
      '#description' => t('Enter the prefix that this campaign\'s coolKeys codes will use.'),
      '#disabled' => (isset($plugin_data['num_keys'])),
    );
    // Disable num_keys if set.
    $form['num_keys'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of Keys'),
      '#description' => t('The number of CoolKeys codes to use in this campaign.'),
      '#element_validate' => array('_numeric_element_validate'),
      '#default_value' => 50,
      '#disabled' => (isset($plugin_data['num_keys'])),
    );
    $form['max_uses'] = array(
      '#type' => 'textfield',
      '#title' => t('Max Uses'),
      '#description' => t('The max number of times a coolKeys code can be used. Set to 0 for unlimited uses.'),
      '#element_validate' => array('_numeric_element_validate'),
      '#states' => array(
        'invisible' => array(
          ':input[name="unlimited_uses"]' => array('checked' => TRUE),
        ),
      ),
      '#default_value' => 1,
    );
    $form['max_applications'] = array(
      '#type' => 'textfield',
      '#title' => t('Applications'),
      '#description' => t('Number of times the discount can be applied, i.e. how many downloads can be gotten.'),
      '#element_validate' => array('_numeric_element_validate'),
      '#default_value' => 1,
    );
    $form['combinable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Combinable?'),
      '#description' => t('If checked then the campaign discount can be compbined with other discounts'),
      '#default_value' => 1,
    );
    return parent::getConfigForm($form, $form_state, $plugin_data);
  }
  /**
   * Update discount.
   * Need to set activation/expiration and max uses data,
   * and more the discount.
   * @see CampaignDefault::update()
   */
  function update($campaign=NULL) {
    $activates_string = date('c', strtotime(implode('/', $campaign->activates)));
    $expires_string = date('c', strtotime(implode('/', $campaign->expires)));    
    $discount = $this->campaign->data['plugin_data']['entities']['_discount'][0];
    $discount->data['descriptives']['active'] = $this->campaign->isActive();
    $discount->data['descriptives']['combinable'] = $this->config['configData']['combinable'];
    $discount->data['descriptives']['activates'] = $this->campaign->activates;
    $discount->data['descriptives']['expires_select'] = $this->campaign->set_expire;
    $discount->data['descriptives']['expires'] = $this->campaign->expires;
    $discount->data['descriptives']['expires_date_string'] = $expires_string;
    $discount->data['conditions']['promo_code_uses'] = $this->config['configData']['max_uses'];
    $discount->data['descriptives']['activates_date_string'] = $activates_string;
    $discount->data['actions']['max_applications'] = $this->config['configData']['max_applications'];
    $discount->campaign_updated = TRUE;
    $this->campaign->data['plugin_data']['entities']['_discount'][0] = $discount;
    return parent::update($campaign);
  }
}
