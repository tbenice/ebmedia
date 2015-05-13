<?php
/**
 * Field handler to present a link group delete.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_token_link_delete extends views_handler_field_token_link_usage {

  /**
   * Renders the link.
   */
  function render_link($ft_token, $values) {
    // Ensure user has access to edit this node.
    if (!cool_tokens_token_access('delete', $ft_token)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/structure/ft-tokens/$ft_token->tkid/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Delete');
    return $text;
  }
}
