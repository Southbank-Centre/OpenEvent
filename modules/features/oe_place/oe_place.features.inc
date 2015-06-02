<?php
/**
 * @file
 * oe_place.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_place_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_views_api().
 */
function oe_place_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oe_place_node_info() {
  $items = array(
    'place' => array(
      'name' => t('Place'),
      'base' => 'node_content',
      'description' => t('The Open Event \'Place\' content type, designed in accordance with the <a href="https://schema.org/Place" target="_blank">schema.org Place type</a>.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function oe_place_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: place
  $schemaorg['node']['place'] = array(
    'rdftype' => array(
      0 => 'schema:Place',
      1 => 'sioc:Item',
      2 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'schema:name',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'schema:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_place_address' => array(
      'predicates' => array(
        0 => 'schema:address',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_place_geolocation' => array(
      'predicates' => array(
        0 => 'schema:geo',
      ),
    ),
    'field_description' => array(
      'predicates' => array(
        0 => 'schema:description',
      ),
    ),
    'field_place_opening_hours' => array(
      'predicates' => array(
        0 => 'schema:openingHoursSpecification',
      ),
    ),
    'field_image' => array(
      'predicates' => array(
        0 => 'schema:image',
      ),
      'type' => 'rel',
    ),
    'field_place_parents' => array(
      'predicates' => array(
        0 => 'schema:containedIn',
      ),
    ),
  );

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

  // Exported RDF mapping: place_is_contained_in_place
  $schemaorg['relation']['place_is_contained_in_place'] = array(
    'source_bundles' => array(
      'predicates' => array(
        0 => 'schema:superEvent',
      ),
    ),
    'target_bundles' => array(
      'predicates' => array(
        0 => 'schema:subEvent',
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
