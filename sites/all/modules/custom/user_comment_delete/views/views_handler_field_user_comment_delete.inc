<?php
/**
 * Field handler to present a link to delete a user's own comment.
 */
class views_handler_field_user_comment_delete extends views_handler_field_comment_link {
  function render_link($data, $values) {
    $cid =  $this->get_value($values, 'cid');
    if (user_comment_delete_comment_delete_access($cid)) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "comment/" . $cid . "/delete";
      $this->options['alter']['query'] = drupal_get_destination();
    }
    else {
      $text = '';
    }
    return $text;
  }
}
