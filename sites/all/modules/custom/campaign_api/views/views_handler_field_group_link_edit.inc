<?php
/**
 * Field handler to present a link for group edit.
 *
 * @ingroup views_field_handlers
 */

class views_handler_field_group_link_edit extends views_handler_field_group_link_operation {

  /**
   * Renders the link.
   */
  function render_link($ck_group, $values) {
    // Ensure user has access to edit this node.
    if (!campaign_api_key_group_access('update', $ck_group)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/structure/cool-keys-groups/$ck_group->kgid/edit";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');
    return $text;
  }
}