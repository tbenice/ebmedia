<?php

/**
 * Token view callback.
 */
function cool_tokens_token_view($ft_token) {
  drupal_set_title(entity_label('cool_token', $ft_token));
  return entity_view('cool_token', array(entity_id('cool_token', $ft_token) => $ft_token), 'full');
}


/**
 * Callback to redeem a token.
 */
function cool_tokens_urlredeem() {
  global $user;

  // Get the GET params.
  $args = array();
  $args = $_GET;
  foreach($args as &$arg) {
    filter_xss($arg);
  }
  unset($args['q'], $args['ft_token'], $args['ftpath']);
  foreach($args as &$arg) {
    filter_xss($arg);
  }

  // If no valid token GET param then error out.
  if (!isset($_GET['fttoken'])) {
    drupal_set_message(t('No token ID was supplied. Token not applied'), 'error');
    watchdog('cool_tokens_urlredeem', t('No Token ID was supplied. User' . $user->uid . ' could not redeem a token'), WATCHDOG_ERROR);
    return '';
  }

  // Set the params sent via GET.
  $ft_tkid = filter_xss($_GET['fttoken']);
  $path = (isset($_GET['ftpath'])) ? filter_xss($_GET['ftpath']) : '';

  // Load the token and use it.
  $ft_token = cool_tokens_token_load($ft_tkid);
  // Check if the user has the token. If not error out.
  if ($ft_token->userHasToken()) {
    $ft_token->useToken($user, $args);
    drupal_goto($path);
  }
  else {
    drupal_set_message(t('User ' . $user->uid . ' tried to redeem a token that was not assigned to them. Token not applied'), 'error');
    watchdog('cool_tokens_urlredeem', t('User' . $user->uid . ' tried to redeem a token not assigned to them.'), WATCHDOG_ERROR);
    drupal_goto($path);
  }
  return '';
}
