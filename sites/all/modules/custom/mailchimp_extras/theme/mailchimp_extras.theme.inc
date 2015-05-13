<?php
/**
 * @file mailchimp_extras.theme.inc
 * Theme related functions for the mailchimp_extras feature.
 */

/**
 * preprocess variables for id mailing list mailchimp templates
 * @param array $vars
 */
function template_preprocess_mailing_list_mc_group_display(&$vars){
  $groups_array = mailchimp_extras_groups();//dsm($groups_array, 'groups array');
  $mc_groups = array();
  foreach($groups_array as $group) {
    $query = array_merge(array('group_id' => $group['group_id'], 'group_name' => $group['group_name']));
    $mc_groups[] = array(
      'data' => $group['group_name'] . ' (' . $group['subscribers'] .' subscribers) ',
    );
  }
  $type = 'ul';
  $attributes = array('class' => 'item-list');

  $vars['content']['mc_groups'] = theme('item_list',(array('items' => $mc_groups, 'type' => $type, 'attributes' => $attributes)));
}

/**
 * theme function returns a link to open the subscription form.
 */
function theme_mailing_list_mc_subscribe_link() {
  $content = '<div class="mailing-list-subscribe-link">';
  $content .= l(t('Subscribe'), 'go', array('html'=>true, 'fragment' => 'go', 'attributes' => array('class' => array('mailchimp-extras-mailing-list-subscribe-link'))));
  $content .= '</div>';
  return $content;
}
