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

/**
 * Implements hook_rdf_default_mappings().
 */
function oe_place_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: event_is_located_in_place
  $schemaorg['relation']['event_is_located_in_place'] = array(
    'source_bundles' => array(
      'predicates' => array(
        0 => 'schema:location',
      ),
    ),
    'target_bundles' => array(
      'predicates' => array(
        0 => 'schema:event',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
  );

  return $schemaorg;
}