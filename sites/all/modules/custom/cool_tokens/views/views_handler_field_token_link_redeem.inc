<?php
/**
 * Field handler to present a link to the usage of the token.
 *
 * @ingroup views_field_handlers
 */

class views_handler_field_token_link_redeem extends views_handler_field_token_link_usage {

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    $options['redirect_path'] = array('default' => '', 'translatable' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    $form['redirect_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Redirect Path'),
      '#description' => t('Enter a Drupal Path to which the link will redirect'),
      '#default_value' => $this->options['redirect_path'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity, $values);
    }
  }

  function render_link($ft_token, $values) {
    $redirect_path = ($this->options['redirect_path'] == '') ? current_path() : $this->options['redirect_path'];
    $this->options['alter']['make_link'] = TRUE;
    /**
     * Modules have the option of killing a token link via 
     * hook_cool_tokens_redeem_uri_alter().
     *
     * In this case the getUri method returns false. Here
     * we just return '' when the method returns false.
     */
    $path = $ft_token->getUri($redirect_path);
    if ($path) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $path;
      $text = !empty($this->options['text']) ? $this->options['text'] : t('redeem');
      return $text;
    }
    return '';
  }
}
