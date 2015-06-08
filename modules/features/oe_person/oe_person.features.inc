<?php
/**
 * @file
 * oe_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_person_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function oe_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Open Event content type for a person (alive, dead, undead, or fictional).<br/>
Designed in accordance with the <a href="http://schema.org/Person" target="_blank">Schema.org Person type</a>.'),
      'has_title' => '1',
      'title_label' => t('Person name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
