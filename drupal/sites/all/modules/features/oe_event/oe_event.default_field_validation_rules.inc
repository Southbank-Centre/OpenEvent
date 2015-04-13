<?php
/**
 * @file
 * oe_event.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function oe_event_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Age range';
  $rule->name = 'age_range';
  $rule->field_name = 'field_event_age_range';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'event';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '(\\d+)-(\\d+)?',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'An age range should be one of the following two formats: Either "5-" (no end range) or "11-18" (start and end range)';
  $export['age_range'] = $rule;

  return $export;
}
