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
function oe_person_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: person
  $schemaorg['node']['person'] = array(
    'rdftype' => array(
      0 => 'schema:Person',
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
    'field_person_events' => array(
      'predicates' => array(
        0 => 'schema:performerIn',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_person_name_prefix' => array(
      'predicates' => array(
        0 => 'schema:honorificPrefix',
      ),
      'type' => 'rel',
    ),
    'field_person_name_given' => array(
      'predicates' => array(
        0 => 'schema:givenName',
      ),
    ),
    'field_person_name_middle' => array(
      'predicates' => array(
        0 => 'schema:additionalName',
      ),
    ),
    'field_person_name_family' => array(
      'predicates' => array(
        0 => 'schema:familyName',
      ),
    ),
    'field_person_name_suffix' => array(
      'predicates' => array(
        0 => 'schema:honorificSuffix',
      ),
    ),
    'field_person_name_alias' => array(
      'predicates' => array(
        0 => 'schema:alternateName',
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
    'field_person_job' => array(
      'predicates' => array(
        0 => 'schema:jobTitle',
      ),
    ),
    'field_person_awards' => array(
      'predicates' => array(
        0 => 'schema:award',
      ),
    ),
    'field_person_urls' => array(
      'predicates' => array(
        0 => 'schema:sameAs',
      ),
    ),
  );

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
