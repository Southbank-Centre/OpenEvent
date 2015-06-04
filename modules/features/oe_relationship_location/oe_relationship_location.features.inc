<?php
/**
 * @file
 * oe_relationship_location.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_relationship_location_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}
