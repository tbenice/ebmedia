<?php

/**
 * Implements hook_rules_condition_info().
 */
function commerce_shipment_rules_condition_info() {
  $conditions = array();

  $conditions['commerce_shipment_has_all_shipped'] = array(
    'label' => t('All shipments associated with this order have shipped'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
        'description' => t('The order to check the shipments of.'),
      ),
    ),
    'help' => t('Evaluates to TRUE, if all items have shipped.'),
    'group' => 'Commerce Shipment',
    'callbacks' => array(
      'execute' => 'commerce_shipment_rules_has_all_shipped',
    ),
  );

  return $conditions;
}


/**
 * Determine whether all shipments associated with the order have shipped
 *
 * @return bool
 *   TRUE if the shipments have all shipped
 */
function commerce_shipment_rules_has_all_shipped($order)
{
  $shipments = array();
  foreach ($order->commerce_shipments[LANGUAGE_NONE] as $shipment_ref) {
    $shipment = commerce_shipment_load($shipment_ref['target_id']);
    if ($shipment->commerce_shipment_status[LANGUAGE_NONE][0]['value'] != 'shipped')
    {
      return false;
    }
  }
  return true;
}
