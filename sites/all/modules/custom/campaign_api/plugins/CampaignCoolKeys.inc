<?php
/**
 * @file CampaignCoolKeys.inc
 * Abstract campaign class for coolKeys campaigns.
 */

abstract class CampaignCoolKeys extends CampaignDefault {

  /**
   * @see CampaignDefault::getConfigForm()
   */
  public function getConfigForm($form=array(), $form_state=array(), $plugin_data=array()) {
    $form['key_code_prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Prefix'),
      '#description' => t('Enter the prefix that this campaigns codes will use.'),
      '#default_value' => 'key_to_role',
      '#disabled' => (isset($plugin_data['num_keys'])),
    );
    // Disable num_keys if set.
    $form['num_keys'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of Keys'),
      '#description' => t('The number of CoolKeys codes to use in this campaign.'),
      '#element_validate' => array('campaign_api_numeric_element_validate'),
      '#default_value' => 50,
      '#disabled' => (isset($plugin_data['num_keys'])),
    );
    $form['unlimited_uses'] = array(
      '#type' => 'checkbox',
      '#title' => t('Unlimited uses?'),
      '#description' => t('Can the campaign keys be used unlimited number of times?'),
      '#default_value' => 0,
    );
    $form['max_uses'] = array(
      '#type' => 'textfield',
      '#title' => t('Max Uses'),
      '#description' => t('The max number of times a key can be used.'),
      '#element_validate' => array('campaign_api_numeric_element_validate'),
      '#states' => array(
        'invisible' => array(
          ':input[name="unlimited_uses"]' => array('checked' => TRUE),
        ),
      ),
      '#default_value' => 1,
    );
    return parent::getConfigForm($form, $form_state, $plugin_data);
  }
  /**
   * Update coolKey.
   * Need to set activation/expiration and max uses data on
   * the coolKey.
   * @see CampaignDefault::update()
   */
  function update($campaign=NULL) {
    $group = $campaign->data['plugin_data']['entities']['cool_keys_key_group'][0];
    $group->campaign_updated = TRUE;
    $group->set_unlimited_uses = $this->config['configData']['unlimited_uses'];
    $group->max_uses = $this->config['configData']['max_uses'];
    $group->active = $this->campaign->active;
    //@todo coolkeys should use a serialized blob for dates. then these serialize(s) isn't needed.
    $group->activates = serialize($this->campaign->activates);
    $group->set_expire = $this->campaign->set_expire;
    $group->expires = serialize($this->campaign->expires);
    $campaign->data['plugin_data']['entities']['cool_keys_key_group'][0] = $group;
    return parent::update($campaign);
  }
}
