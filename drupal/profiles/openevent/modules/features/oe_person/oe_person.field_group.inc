<?php
/**
 * @file
 * oe_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_person_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_people|node|event|form';
  $field_group->group_name = 'group_event_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'People',
    'weight' => '3',
    'children' => array(
      0 => 'field_event_performers',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'People',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-event-people field-group-tab',
        'description' => 'Relationships with people and organizations for this event.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_event_people|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_biography|node|person|form';
  $field_group->group_name = 'group_person_biography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Biography and images',
    'weight' => '1',
    'children' => array(
      0 => 'field_description',
      1 => 'field_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-biography field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_person_biography|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_details|node|person|form';
  $field_group->group_name = 'group_person_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extra details',
    'weight' => '2',
    'children' => array(
      0 => 'field_person_awards',
      1 => 'field_person_job',
      2 => 'field_person_urls',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_person_details|node|person|form'] = $field_group;

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
    'weight' => '3',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_main|node|person|form';
  $field_group->group_name = 'group_person_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_name_middle',
      1 => 'field_person_name_alias',
      2 => 'field_person_name_family',
      3 => 'field_person_name_given',
      4 => 'field_person_name_prefix',
      5 => 'field_person_name_suffix',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-person-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_person_main|node|person|form'] = $field_group;

  return $export;
}