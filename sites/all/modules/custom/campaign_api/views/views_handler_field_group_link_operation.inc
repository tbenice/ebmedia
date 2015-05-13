<?php
/**
 * Field handler to present a general link operation (that is further extended per each specific link)
 *
 * @ingroup views_field_handlers
 */

class views_handler_field_group_link_operation extends views_handler_field_entity {

  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity, $values);
    }
  }

  function render_link($ck_group, $values) {
    if (campaign_api_key_group_access('view', $ck_group)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/structure/cool-keys-groups/$ck_group->kgid/operation";
      $text = !empty($this->options['text']) ? $this->options['text'] : t('usage');
      return $text;
    }
  }
}
