<?php
/**
 * @file
 * oe_relationship_performer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_relationship_performer_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oe_relationship_performer_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: person_performs_in_event
  $schemaorg['relation']['person_performs_in_event'] = array(
    'source_bundles' => array(
      'predicates' => array(
        0 => 'schema:performerIn',
      ),
    ),
    'target_bundles' => array(
      'predicates' => array(
        0 => 'schema:performers',
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
