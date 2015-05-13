<?php
/**
 * @file contextual_messages.theme.inc
 * Theme related code for the contextual messages module.
 */

/**
 * Theme a contextual message.
 *
 * @param array $vars
 */
function theme_contextual_message($vars) {
  $content = '';
  if(isset($vars['message']) && isset($vars['id'])) {
    $content = '<div class="contextual-message-target-wrapper"><div id="contextual-message-target-id-' . $vars['id'] .
      '" class="contextual-message-target contextual-message-target-event-' . $vars['event'] . '">'
      . $vars['markup'] . '</div><!--contextual-message-target -->';
    $content .= '<div id="contextual-message-id-' . $vars['id'] . '" class="contextual-message-container contextual-message-container-event-'
      . $vars['event'] . ' contextual-message-hide">';
    $content .= l(t('close'), current_path(), array('attributes' => array('class' => array('contextual-message-close'))));
    $content .= '&nbsp';
    $content .= l(t('dismiss permanently'), current_path(), array('attributes' => array('class' => array('contextual-message-dismiss'))));
    $content .= $vars['message'];
    $content .= '</div><!--contextual-message-container -->';
    $content .= '</div><!-- contextual-messages-target-wrapper -->';
  }
  return $content;
}
