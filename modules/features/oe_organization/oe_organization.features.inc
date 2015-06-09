<?php
/**
 * @file
 * oe_organization.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_organization_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oe_organization_node_info() {
  $items = array(
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => t('Open Event content type for an organization, such as a school, NGO, corporation, club, etc.<br/>
Designed in accordance with the <a href="http://schema.org/Organization" target="_blank">Schema.org organization type</a>.'),
      'has_title' => '1',
      'title_label' => t('Organization name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function oe_organization_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: organization
  $schemaorg['node']['organization'] = array(
    'rdftype' => array(
      0 => 'schema:Organization',
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
    'field_organization_logo' => array(
      'predicates' => array(
        0 => 'schema:logo',
      ),
      'type' => 'rel',
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_description' => array(
      'predicates' => array(
        0 => 'schema:description',
      ),
    ),
    'field_organization_legal_name' => array(
      'predicates' => array(
        0 => 'schema:legalName',
      ),
    ),
    'field_organization_email' => array(
      'predicates' => array(
        0 => 'schema:email',
      ),
    ),
    'field_organization_address' => array(
      'predicates' => array(
        0 => 'schema:address',
      ),
    ),
    'field_organization_same_as' => array(
      'predicates' => array(
        0 => 'schema:sameAs',
      ),
    ),
    'field_image' => array(
      'predicates' => array(
        0 => 'schema:image',
      ),
      'type' => 'rel',
    ),
  );

  return $schemaorg;
}
