<?php
/**
 * Field handler to present a link to issue or reclaim key.
 *
 * @ingroup views_field_handlers
 */

class views_handler_field_issue_link_action extends views_handler_field {

  function render($values) {
    return $this->render_link($values);
  }

  /**
   * Renders the link.
   */

  function render_link($values) {
    // Ensure user has access to administer cool keys.
    if (!user_access('administer coolkeys')) {
      return;
    }
    // Ensure that there is a key code kcid field exposed.
    if (!isset($values->cool_keys_key_codes_key_code)) {
      return;
    }
    // Ensure that the key code has not been issued.
    if (_key_code_is_issued($values->cool_keys_key_codes_key_code)) {
      $op = 'reclaim';
    }
    else {
      $op = 'issue';
    }
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/structure/cool-keys-groups/keys/{$values->cool_keys_key_codes_key_code}/{$op}";
    $this->options['alter']['query'] = drupal_get_destination();
    $text = !empty($this->options['text']) ? $this->options['text'] : t($op);
    return $text;
  }

}
