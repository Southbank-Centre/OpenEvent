<?php
/**
 * @file
 * oe_place.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_place_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_image|node|place|default';
  $field_group->group_name = 'group_place_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-image field-group-fieldset',
      ),
    ),
  );
  $export['group_place_image|node|place|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_image|node|place|form';
  $field_group->group_name = 'group_place_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-image field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_place_image|node|place|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_location|node|place|default';
  $field_group->group_name = 'group_place_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_place_address',
      1 => 'field_place_geolocation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-location field-group-fieldset',
      ),
    ),
  );
  $export['group_place_location|node|place|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_location|node|place|form';
  $field_group->group_name = 'group_place_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_place_address',
      1 => 'field_place_geolocation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_place_location|node|place|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_main|node|place|default';
  $field_group->group_name = 'group_place_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-main field-group-fieldset',
      ),
    ),
  );
  $export['group_place_main|node|place|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_main|node|place|form';
  $field_group->group_name = 'group_place_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_place_main|node|place|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_opening_hours|node|place|default';
  $field_group->group_name = 'group_place_opening_hours';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opening Hours',
    'weight' => '3',
    'children' => array(
      0 => 'field_place_opening_hours',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-opening-hours field-group-fieldset',
      ),
    ),
  );
  $export['group_place_opening_hours|node|place|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_opening_hours|node|place|form';
  $field_group->group_name = 'group_place_opening_hours';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opening hours',
    'weight' => '3',
    'children' => array(
      0 => 'field_place_opening_hours',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-opening-hours field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_place_opening_hours|node|place|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_parents|node|place|default';
  $field_group->group_name = 'group_place_parents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Parents',
    'weight' => '4',
    'children' => array(
      0 => 'field_place_parents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-parents field-group-fieldset',
      ),
    ),
  );
  $export['group_place_parents|node|place|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_place_parents|node|place|form';
  $field_group->group_name = 'group_place_parents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'place';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Place parents',
    'weight' => '4',
    'children' => array(
      0 => 'field_place_parents',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-place-parents field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_place_parents|node|place|form'] = $field_group;

  return $export;
}
