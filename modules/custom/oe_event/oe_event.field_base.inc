<?php
/**
 * @file
 * oe_event.field_base.inc
 */

function oe_event_field_bases() {

  // field base: field_event_age_range
  if (!field_info_field('field_event_age_range')) {

    $field_event_age_range = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_age_range',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    );
    field_create_field($field_event_age_range);

  };

  // field base: field_event_date_end
  if (!field_info_field('field_event_date_end')) {

    $field_event_date_end = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_date_end',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'date',
      'settings' => array(
        'cache_count' => 4,
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => '',
        'tz_handling' => 'site',
      ),
      'translatable' => 0,
      'type' => 'date',
    );
    field_create_field($field_event_date_end);

  };

  // field base: field_event_date_start
  if (!field_info_field('field_event_date_start')) {

    $field_event_date_start = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_date_start',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'date',
      'settings' => array(
        'cache_count' => 4,
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => '',
        'tz_handling' => 'site',
      ),
      'translatable' => 0,
      'type' => 'date',
    );
    field_create_field($field_event_date_start);

  };

  // field base: field_event_door_time
  if (!field_info_field('field_event_door_time')) {

    $field_event_door_time = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_door_time',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'date',
      'settings' => array(
        'cache_count' => 4,
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => 'UTC',
        'todate' => '',
        'tz_handling' => 'site',
      ),
      'translatable' => 0,
      'type' => 'date',
    );
    field_create_field($field_event_door_time);

  };

  // field base: field_event_duration
  if (!field_info_field('field_event_duration')) {

    $field_event_duration = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_duration',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'number',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'number_integer',
    );
    field_create_field($field_event_duration);

  };

  // field base: field_event_parents
  if (!field_info_field('field_event_parents')) {

    $field_event_parents = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_event_parents',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'relation_add',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'relation_add',
    );
    field_create_field($field_event_parents);

  };

}
