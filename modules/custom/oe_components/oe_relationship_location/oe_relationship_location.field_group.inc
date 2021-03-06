<?php
/**
 * @file
 * oe_relationship_location.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_relationship_location_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_location|node|event|default';
  $field_group->group_name = 'group_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '3',
    'children' => array(
      0 => 'field_event_places',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-location field-group-fieldset',
      ),
    ),
  );
  $export['group_event_location|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_location|node|event|form';
  $field_group->group_name = 'group_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_event_places',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_event_location|node|event|form'] = $field_group;

  return $export;
}
