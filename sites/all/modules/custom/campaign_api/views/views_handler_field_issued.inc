<?php
/**
 * Field handler to present a link group delete.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_issued extends views_handler_field_numeric {
  function render($values) {
    $value = $this->get_value($values);
    $issued_value = array(
      0 => t('Not Issued'),
      1 => t('Issued'),
    );
 
    return $issued_value[$value];
  
  }
}