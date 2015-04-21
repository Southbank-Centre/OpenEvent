<?php
/**
 * @file
 * sc_style_guide.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sc_style_guide_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|style_guide_page|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'style_guide_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'field_components',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main|node|style_guide_page|form'] = $field_group;

  return $export;
}
