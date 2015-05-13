<?php
/**
 * @file entity_pager.theme.inc
 * Theme related code for the entity pager module.
 */

/**
 *
 * preprocess function for theme_entity_pager
 * @param array $vars
 */
function template_preprocess_entity_pager(&$vars) {
  // Load configurations.
  $view_name = variable_get($vars['delta'] . '_entity_pager_view', '');
  $entity_id_arg = variable_get($vars['delta'] . '_entity_id_arg', 1);
  $entity_type = variable_get($vars['delta'] . '_entity_pager_entity_type', 'node');
  $entity_info = entity_get_info($entity_type);

  // Load current entity.
  $entity = entity_load_single($entity_type, arg($entity_id_arg));
  entity_get_all_property_info(variable_get($vars['delta'] . '_entity_pager_entity_type'));

  // Get the view to use for the pager list.
  $view = views_get_view($view_name);

  $view->display['default']->display_options['pager'] = array(
    'type' => 'some',
    'options' => array(
      'items_per_page' => 1,
      'offset' => 0,
    ),
  );

  // Figure out what the filter should be.
  // If there are sorts, use the last one as the base filter.
  $sorts = $view->display['default']->display_options['sorts'];

  if (!empty($sorts)) {
    $sorts = array_keys($sorts);
    $last_sort_key = array_shift($sorts);
    $filter = $view->display['default']->display_options['sorts'][$last_sort_key];
  }
  // Otherwise use the base info as the filter.
  else {
    $filter = array(
      'id' => $entity_info['entity keys']['id'],
      'table' => $entity_info['base table'],
      'field' => $entity_info['entity keys']['id'],
      'relationship' => 'none',
      'group_type' => 'group',
      'ui_name' => '',
      'exposed' => FALSE,
    );
  }
  // Get the field alias for the sorted field. Need it later.
  $filter_alias = (strlen($filter['table'] . '_' . $filter['field']) > 60) ?
    substr($filter['table'] . '_' . $filter['field'], 0, 60):
    $filter['table'] . '_' . $filter['field'];

  // Have to use the selectquery obj that is handed to us, views won't utilize the added where...(WHY NOT!)
  //dsm($view);
  if (!method_exists($view, 'build')) {
    drupal_set_message('ENTITY PAGER ERROR: The Entity pager on this page is misconfigured. Perhaps you have selected the wrong view?', 'error');
    return;
  }
  $view->build();
  $select = $view->query->query();
  $this_query = clone $select;
  $prev_query = clone $select;
  $next_query = clone $select;

  // Load a result row from the view for the current node.
  // This is what we'll use to populate the conditions for prev/next queries.
  $this_query->condition($entity_info['base table'] . '.' .$entity_info['entity keys']['id'], $entity->{$entity_info['entity keys']['id']}, '=');

  try {
    if($result = $this_query->execute()) {
      $_this = $result->fetchAssoc();
    }
  }
  catch(Exception $e) {
    watchdog('entity_pager', t('Configuration error: incorrect views display in ' . $vars['delta'] . ' pager block, using Views display for ' . $view_name .'.'),array(),WATCHDOG_WARNING);
    drupal_set_message(t('Configuration error: incorrect views display in ' . $vars['delta'] . ' pager block, using Views display for ' . $view_name .'.'), 'warning');
    return FALSE;
  }

  // *****Execute on the previous query.
  // Figure out what the order and op should be for the prev query.
  if (!empty($view->display['default']->display_options['sorts'])) {
    $sort_order = (isset($view->display['default']->display_options['sorts'][$last_sort_key]['order'])) ?
      $view->display['default']->display_options['sorts'][$last_sort_key]['order'] :
      'ASC';
    $order = ($sort_order == 'ASC') ? 'DESC' : 'ASC';
    $op = ($sort_order == 'ASC') ? '<' : '>';
    $orderby =& $prev_query->getOrderBy();
    $key_orderby = array_keys($orderby);
    $key = array_shift($key_orderby);
    $orderby[$key] = $order;
  }
  // Set default sort.
  else {
    $order = 'DESC';
    $op = '<';
  }
  // Set the condition, execute, and retrieve results (if any).
  $prev_query->condition($filter['table'] . '.' . $filter['field'], $_this[$filter_alias], $op);
  $next_query->range(0, 1);
  if ($result = $prev_query->execute()) {
    if ($prev = $result->fetchAssoc()) {
      $prev_id = (isset($prev[$entity_info['entity keys']['id']])) ? $prev[$entity_info['entity keys']['id']] : null;
      if (variable_get($vars['delta'] . '_pager_text_custom') == 0) {
        $key_prev = array_keys($prev);
        $key = array_shift($key_prev);
        $prev_text = t($prev[$key]);
      }
      // Using the custom text.
      else {
        $prev_text = t(variable_get($vars['delta'] . '_pager_text_previous', 'Previous'));
      }
    }
  }

  // *****Execute on the next query.
  // Figure out what the order and op should be for next query.
  if (!empty($view->display['default']->display_options['sorts'])) {
    $sort_order = (isset($view->display['default']->display_options['sorts'][$last_sort_key]['order'])) ?
      $view->display['default']->display_options['sorts'][$last_sort_key]['order'] :
      'ASC';
    $order = ($sort_order == 'ASC') ? 'ASC' : 'DESC';
    $op = ($sort_order == 'ASC') ? '>' : '<';
    $orderby =& $next_query->getOrderBy();
    $key_orderby = array_keys($orderby);
    $key = array_shift($key_orderby);
    $orderby[$key] = $order;
  }

  // Set default sort.
  else {
    $order = 'ASC';
    $op = '>';
  }
  // Set the condition, execute, and retrieve results (if any).
  $next_query->condition($filter['table'] . '.' . $filter['field'], $_this[$filter_alias], $op);
  $next_query->range(0, 1);
  if ($result = $next_query->execute()) {
    if ($next = $result->fetchAssoc()) {
      $next_id = (isset($next[$entity_info['entity keys']['id']])) ? $next[$entity_info['entity keys']['id']] : null;
      // Determine the next text.
      // If using the view...
      if (variable_get($vars['delta'] . '_pager_text_custom') == 0) {
        $key_next = array_keys($next);
        $key = array_shift($key_next);
        $next_text = t($next[$key]);
      }
      // Using the custom text.
      else {
        $next_text = t(variable_get($vars['delta'] . '_pager_text_next', 'Next'));
      }
    }
  }

  // Set links.
  if (isset($prev_id)) {
    $prev_uri = call_user_func($entity_info['uri callback'], entity_load_single($entity_type, $prev_id));
    $vars['content']['previous_link'] = array(
      '#theme' => 'link',
      '#text' => $prev_text,
      '#path' => $prev_uri['path'],
      '#options' => array(
        'html' => FALSE,
        'attributes' => array(
          'title' => t('View the previous item: ' . $prev_text),
          'class' => array('entity-pager-link'),
          'id' => 'entity-pager-previous-link',
        ),
      ),
    );
  }
  if (isset($next_id)) {
    $next_uri = call_user_func($entity_info['uri callback'], entity_load_single($entity_type, $next_id));
    $vars['content']['next_link'] = array(
      '#theme' => 'link',
      '#text' => $next_text,
      '#path' => $next_uri['path'],
      '#options' => array(
        'html' => FALSE,
        'attributes' => array(
          'title' => t('View the next item: ' . $next_text),
          'class' => array('entity-pager-link'),
          'id' => 'entity-pager-next-link',
        ),
      ),
    );
  }
  // Set the back to river link if using it.
  if (variable_get($vars['delta'] . '_use_link') == 1) {
    $vars['content']['link'] = array(
      '#theme' => 'link',
      '#text' => variable_get($vars['delta'] . '_link_text', 'Back to river'),
      '#path' => variable_get($vars['delta'] . '_link_path', current_path()),
      '#options' => array(
        'html' => FALSE,
        'attributes' => array(
          'title' => variable_get($vars['delta'] . '_link_text', 'Back to river'),
          'class' => array('back-to-river-link'),
          'id' => 'entity-pager-back-to-river-link',
        ),
      ),
    );
  }
}
