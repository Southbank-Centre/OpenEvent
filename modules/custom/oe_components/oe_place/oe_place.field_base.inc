<?php
/**
 * @file
 * oe_place.field_base.inc
 */

/**
 * Create field bases for use by the Place content type.
 */
function oe_place_field_bases() {

  $field_bases = array();

  // Exported field_base: 'field_place_address'
  $field_bases['field_place_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_place_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_place_geolocation'
  $field_bases['field_place_geolocation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_place_geolocation',
    'indexes' => array(
      'lat' => array(
        0 => 'lat',
      ),
      'lng' => array(
        0 => 'lng',
      ),
    ),
    'locked' => 0,
    'module' => 'geolocation',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'geolocation_latlng',
  );

  // Exported field_base: 'field_place_opening_hours'
  $field_bases['field_place_opening_hours'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_place_opening_hours',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'office_hours',
    'settings' => array(
      'cardinality' => 1,
      'granularity' => 5,
      'hoursformat' => 2,
      'limitend' => '',
      'limitstart' => '',
      'valhrs' => 0,
    ),
    'translatable' => 0,
    'type' => 'office_hours',
  );

  // Exported field_base: 'field_place_parents'
  $field_bases['field_place_parents'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_place_parents',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'relation_add',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'relation_add',
  );

  foreach ($field_bases as $field_base) {
    field_create_field($field_base);
  }

}
