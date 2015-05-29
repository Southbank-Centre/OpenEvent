<?php
/**
 * @file
 * oe_event.features.inc
 */

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
      'description' => t('Open Event content type for an event happening at a certain time and location, such as a concert, lecture, or festival. Repeated events may be structured as separate Event objects.<br/>
Designed in accordance with the <a href="https://schema.org/Event" target="_blank">schema.org Event type</a>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function oe_event_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: event
  $schemaorg['node']['event'] = array(
    'rdftype' => array(
      0 => 'schema:Event',
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
    'field_event_performers' => array(
      'predicates' => array(
        0 => 'schema:performer',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_event_date_start' => array(
      'predicates' => array(
        0 => 'schema:startDate',
      ),
    ),
    'field_event_date_end' => array(
      'predicates' => array(
        0 => 'schema:endDate',
      ),
    ),
    'field_description' => array(
      'predicates' => array(
        0 => 'schema:description',
      ),
    ),
    'field_image' => array(
      'predicates' => array(
        0 => 'schema:image',
      ),
      'type' => 'rel',
    ),
    'field_event_parents' => array(
      'predicates' => array(
        0 => 'schema:superEvent',
      ),
    ),
    'field_event_duration' => array(
      'predicates' => array(
        0 => 'schema:duration',
      ),
    ),
    'field_event_door_time' => array(
      'predicates' => array(
        0 => 'schema:doorTime',
      ),
    ),
    'field_event_age_range' => array(
      'predicates' => array(
        0 => 'schema:typicalAgeRange',
      ),
    ),
  );

  return $schemaorg;
}
