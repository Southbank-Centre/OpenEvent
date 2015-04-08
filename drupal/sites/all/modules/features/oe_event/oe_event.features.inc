<?php
/**
 * @file
 * oe_event.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function oe_event_default_cer() {
  $items = array();
  $items['node:event:field_event_parents*node:event:field_event_children'] = entity_import('cer', '{
    "identifier" : "node:event:field_event_parents*node:event:field_event_children",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:event:field_event_parents" } ] },
    "cer_right" : { "und" : [ { "path" : "node:event:field_event_children" } ] }
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function oe_event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oe_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('The Open Event content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
