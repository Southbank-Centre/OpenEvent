<?php
/**
 * @file
 * oe_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_event_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_date_time|node|event|form';
  $field_group->group_name = 'group_event_date_time';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and time',
    'weight' => '2',
    'children' => array(
      0 => 'field_event_start_time',
      1 => 'field_event_end_time',
      2 => 'field_event_door_time',
      3 => 'field_event_duration',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-date-time field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_event_date_time|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_main|node|event|form';
  $field_group->group_name = 'group_event_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_teaser',
      1 => 'field_description',
      2 => 'field_event_age_range',
      3 => 'field_event_class',
      4 => 'field_event_type',
      5 => 'field_event_parents',
      6 => 'field_event_children',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Main',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-event-main field-group-tab',
        'description' => 'The main pieces of information about an event.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_event_main|node|event|form'] = $field_group;

  return $export;
}