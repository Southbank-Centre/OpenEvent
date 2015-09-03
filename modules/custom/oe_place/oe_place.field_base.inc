<?php
/**
 * @file
 * oe_place.field_base.inc
 */

function oe_place_field_bases() {

  // field base: field_place_address
  if (!field_info_field('field_place_address')) {

    $field_place_address = array(
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

    field_create_field($field_place_address);

  };

  // field base: field_place_geolocation
  if (!field_info_field('field_place_geolocation')) {

    $field_place_geolocation = array(
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

    field_create_field($field_place_geolocation);

  };

  // field base: field_place_opening_hours
  if (!field_info_field('field_place_opening_hours')) {

    $field_place_opening_hours = array(
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

    field_create_field($field_place_opening_hours);

  };

  // field base: field_place_parents
  if (!field_info_field('field_place_parents')) {

    $field_place_parents = array(
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
    
    field_create_field($field_place_parents);

  };

}
