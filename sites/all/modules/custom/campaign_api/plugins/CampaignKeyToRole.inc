<?php
/**
 * @file CampaignKeyToRole.inc
 * Campaign config plugin for the Key to Role campaign.
 */

class CampaignKeyToRole extends CampaignCoolKeys {

  /**
   * Create the entity objects.
   * @see CampaignDefault::createEntities()
   */
  public function createEntities($entities = array()) {
    $settings = variable_get('campaign_key_to_role_settings', array());

    // Prepare node.
    $node = new stdClass();
    $node->type = 'webform';
    $node->uid = 1;
    $node->language = LANGUAGE_NONE;
    $node->title = 'Campaign - Key to Role: ' . ((isset($this->campaign)) ? $this->campaign->title : 'New Campaign');
    $node->webform['confirmation'] = t('Thanks for upgrading your account!');
  
    $node->webform['redirect_url'] = 'home';
    // Set roles.
    $roles = user_roles(false);
    $wf_roles = array();
    foreach($roles as $id=>$role) {
      if (in_array($role, array('authenticated user', 'anonymous user'))) {
        $wf_roles[] = $id;
      }
    }
    $node->webform['roles'] = $wf_roles;
    $node->webform['block'] = 1;
    $node->comment = 0;
    $node->promote = 0;
    //  Webform components
    //  Email.
    $node->webform['components'][0]['name'] = 'Email';
    $node->webform['components'][0]['form_key'] = 'email';
    $node->webform['components'][0]['type'] = 'email';
    $node->webform['components'][0]['value'] = '%get[email]';
    $node->webform['components'][0]['mandatory'] = 1;
    $node->webform['components'][0]['pid'] = 0;
    $node->webform['components'][0]['weight'] = 0;
    $node->webform['components'][0]['page_num'] = 1;
    $node->webform['components'][0]['nid'] = (isset($node->nid)) ? $node->nid : NULL;
    // Cook Key Code Entry.
    $node->webform['components'][1]['name'] = 'Enter your Code';
    $node->webform['components'][1]['form_key'] = 'key_to_role_keyentry';
    $node->webform['components'][1]['type'] = 'coolkeyentry';
    $node->webform['components'][1]['mandatory'] = 1;
    $node->webform['components'][1]['pid'] = 0;
    $node->webform['components'][1]['weight'] = 10;
    $node->webform['components'][1]['page_num'] = 1;
    // Hidden field for role to add.
    $node->webform['components'][2]['name'] = 'Role';
    $node->webform['components'][2]['form_key'] = 'Role';
    $node->webform['components'][2]['type'] = 'hidden';
    $node->webform['components'][2]['mandatory'] = 1;
    $node->webform['components'][2]['pid'] = 0;
    $node->webform['components'][2]['weight'] = 10;
    $node->webform['components'][2]['page_num'] = 1;
    $node->webform['components'][2]['value'] = $this->config['configData']['role'];
    $entities['node'][] = $node;
  
    // Create cool key group.
    $group = new CoolKeysGroup();
    $group->is_new = TRUE;
    $group->kgid = $this->campaign->campaign_id . '_' . 'keytorole';
    $group->data['key_code_prefix'] = $this->config['configData']['key_code_prefix'];
    $group->title = t('Campaign - Key to Role Keys: ' . $this->campaign->title);
    $group->description = t('Cool Keys Codes for the Key to Role Campaign');
    $group->set_unlimited_keys = 0;
    $group->num_keys = $this->config['configData']['num_keys'];
    $group->set_unlimited_uses = $this->config['configData']['unlimited_uses'];
    $group->max_uses = $this->config['configData']['max_uses'];
    $group->uid = 1;
    $group->active = $this->campaign->active;
    //@todo coolkeys should use a serialized blob for dates. then these serialize(s) isn't needed.
    $group->activates = serialize($this->campaign->activates);
    $group->set_expire = $this->campaign->set_expire;
    $group->expires = serialize($this->campaign->expires);
    $group->weight = 0;
    $group->module = 'campaigns_key_to_role';
    $entities['cool_keys_key_group'][] = $group;

    parent::createEntities($entities);
  }

  /**
   * Create the rule objects.
   * @see CampaignDefault::createRules()
   */
  public function createRules($items = array()) {
    // Create ids here for ease of use later.
    $ids = array();
    $ids[] = $this->prependId('rules_add_new_role_if_user_exists');
    $ids[] = $this->config['configData']['role'];
    $ids[] = $this->prependId('rules_register_new_user_if_null');
    $ids[] = $this->prependId('rules_campaign_key_to_role');
    $ids[] = 'ckcode_apply_code_' . $this->entities['cool_keys_key_group'][0]->kgid;
    $items = array();
    $items[$ids[0]] = entity_import('rules_config', '{ "' . $ids[0] . '" : {
        "LABEL" : "Add new role if user exists",
        "PLUGIN" : "rule",
        "TAGS" : [ "Campaigns" ],
        "REQUIRES" : [ "rules", "commont_support" ],
        "USES VARIABLES" : { "email_address" : { "label" : "email address", "type" : "text" } },
        "IF" : [
          { "entity_exists" : {
              "type" : "user",
              "property" : "mail",
              "value" : "[email-address:value]"
            }
          }
        ],
        "DO" : [
          { "entity_query" : {
              "USING" : {
                "type" : "user",
                "property" : "mail",
                "value" : [ "email-address" ],
                "limit" : "1"
              },
              "PROVIDE" : { "entity_fetched" : { "fetched_user" : "Fetched User" } }
            }
          },
          { "user_add_role_by_name" : {
              "account" : [ "fetched-user:0" ],
              "roles" : { "value" : { "'. $ids[1] .'" : "' . $ids[1] .'" } }
            }
          },
          { "entity_save" : { "data" : [ "fetched-user:0" ], "immediate" : 1 } },
          { "drupal_message" : { "message" : "Congratulations! User [email-address:value] has been granted upgraded access!" } }
        ]
      }
    }');
    $items[$ids[2]] = entity_import('rules_config', '{ "' . $ids[2] . '" : {
        "LABEL" : "Register new user if null",
        "PLUGIN" : "rule",
        "TAGS" : [ " - Campaigns" ],
        "REQUIRES" : [ "rules", "common_support" ],
        "USES VARIABLES" : { "email_address" : { "label" : "email address", "type" : "text" } },
        "IF" : [
          { "AND" : [
              { "NOT entity_exists" : {
                  "type" : "user",
                  "property" : "mail",
                  "value" : "[email-address:value]"
                }
              },
              { "user_has_role_by_name" : {
                  "account" : [ "site:current-user" ],
                  "roles" : { "value" : { "anonymous user" : "anonymous user" } }
                }
              }
            ]
          }
        ],
        "DO" : [
          { "entity_create" : {
              "USING" : {
                "type" : "user",
                "param_name" : "[email-address:value]",
                "param_mail" : "[email-address:value]"
              },
              "PROVIDE" : { "entity_created" : { "new_user" : "Created User" } }
            }
          },
          { "data_set" : { "data" : [ "new-user:status" ], "value" : "1" } },
          { "btw_user_add_role_by_name" : {
              "account" : [ "new-user" ],
              "roles" : { "value" : { "'. $ids[1] .'" : "' . $ids[1] .'" } }
            }
          },
          { "btw_user_add_role_by_name" : {
              "account" : [ "new-user" ],
              "roles" : { "value" : { "Full Role" : "Full Role" } }
            }
          },
          { "entity_save" : { "data" : [ "new-user" ], "immediate" : 1 } },
          { "btw_user_remove_role_by_name" : {
              "account" : [ "new-user" ],
              "roles" : { "value" : { "Limited Role" : "Limited Role" } }
            }
          },
          { "btw_account_email" : { "account" : [ "new-user" ] } },
          { "drupal_message" : { "message" : "A new user [email-address:value] has been created with upgraded access!" } }
        ]
      }
    }');
    $items[$ids[3]] = entity_import('rules_config', '{ "' . $ids[3] . '" : {
        "LABEL" : "Key to Role Campaign Rule",
        "PLUGIN" : "reaction rule",
        "TAGS" : [ "Campaigns" ],
        "REQUIRES" : [ "php", "rules", "campaign_api" ],
        "ON" : [ "' . $ids[4] . '" ],
        "DO" : [
          { "variable_add" : {
              "USING" : {
                "type" : "text",
                "value" : "\u003C?php echo $args-\u003Edata[1][\u0027value\u0027][0]; ?\u003E"
              },
              "PROVIDE" : { "variable_added" : { "email_address" : "email address" } }
            }
          },
          { "component_' . $ids[0] . '" : { "email_address" : "[email-address:value]" } },
          { "component_' . $ids[2] . '" : { "email_address" : "[email-address:value]" } }
        ]
      }
    }');
    parent::createRules($items);
  }

  /**
   * @see CampaignDefault::getConfigForm()
   */
  public function getConfigForm($form=array(), $form_state=array(), $plugin_data=array()) {
    module_load_include('rules.inc', 'btw');
    $form['role'] = array(
      '#type' => 'select',
      '#title' => t('Role'),
      '#description' => t('The role to give to a user upon CoolKey entry'),
      '#options' => btw_user_roles_options_list(),
    );
    return parent::getConfigForm($form, $form_state, $plugin_data);
  }
  /**
   * Update rule.
   * @see CoolKeys::update()
   */
  public function update($campaign=NULL) {
    $campaign->createRules;
    return parent::update($campaign);
  }
}
