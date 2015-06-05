<?php
/**
 * @file
 * oe_organization.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oe_organization_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_image|node|organization|default';
  $field_group->group_name = 'group_organization_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-image field-group-fieldset',
      ),
    ),
  );
  $export['group_organization_image|node|organization|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_image|node|organization|form';
  $field_group->group_name = 'group_organization_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-image field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_organization_image|node|organization|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_main|node|organization|default';
  $field_group->group_name = 'group_organization_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_organization_address',
      2 => 'field_organization_legal_name',
      3 => 'field_organization_logo',
      4 => 'field_organization_same_as',
      5 => 'field_organization_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-main field-group-fieldset',
      ),
    ),
  );
  $export['group_organization_main|node|organization|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_main|node|organization|form';
  $field_group->group_name = 'group_organization_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_organization_address',
      2 => 'field_organization_legal_name',
      3 => 'field_organization_logo',
      4 => 'field_organization_same_as',
      5 => 'title',
      6 => 'field_organization_email',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-organization-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_organization_main|node|organization|form'] = $field_group;

  return $export;
}
