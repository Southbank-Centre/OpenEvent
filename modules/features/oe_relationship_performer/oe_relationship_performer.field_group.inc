<?php
/**
 * @file
 * oe_relationship_performer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_relationship_performer_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_performers|node|event|default';
  $field_group->group_name = 'group_event_performers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Performers',
    'weight' => '5',
    'children' => array(
      0 => 'field_event_performers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Performers',
      'instance_settings' => array(
        'classes' => 'group-event-performers field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_event_performers|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_performers|node|event|form';
  $field_group->group_name = 'group_event_performers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Performers',
    'weight' => '4',
    'children' => array(
      0 => 'field_event_performers',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-performers field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_event_performers|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_events|node|organization|default';
  $field_group->group_name = 'group_organization_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '3',
    'children' => array(
      0 => 'field_organization_events',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-events field-group-fieldset',
      ),
    ),
  );
  $export['group_organization_events|node|organization|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_events|node|organization|form';
  $field_group->group_name = 'group_organization_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '3',
    'children' => array(
      0 => 'field_organization_events',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-events field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_organization_events|node|organization|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_events|node|person|default';
  $field_group->group_name = 'group_person_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '3',
    'children' => array(
      0 => 'field_person_events',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-events field-group-fieldset',
      ),
    ),
  );
  $export['group_person_events|node|person|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_events|node|person|form';
  $field_group->group_name = 'group_person_events';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Events',
    'weight' => '4',
    'children' => array(
      0 => 'field_person_events',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-events field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_person_events|node|person|form'] = $field_group;

  return $export;
}
