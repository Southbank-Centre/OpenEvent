<?php
/**
 * @file
 * oe_components.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function oe_components_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Flickr validator';
  $rule->name = 'flickr_validator';
  $rule->field_name = 'field_embed_code';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'flickr_embed';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '(^<iframe).*(src=".*www\\.flickr\\.com).*(<\\/iframe>$)',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = 'The code pasted is not a valid Flickr embed fragment.';
  $export['flickr_validator'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Soundcloud validator';
  $rule->name = 'soundcloud_validator';
  $rule->field_name = 'field_embed_code';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'soundcloud_embed';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '(^<iframe).*(src=".*w\\.soundcloud\\.com).*(<\\/iframe>$)',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = 'The code pasted is not a valid Soundcloud embed fragment.';
  $export['soundcloud_validator'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Storify validator';
  $rule->name = 'storify_validator';
  $rule->field_name = 'field_embed_code';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'storify_embed';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '(^<iframe).*(src=".*storify\\.com).*(<\\/iframe>$)',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = 'The code pasted is not a valid Storify embed fragment.';
  $export['storify_validator'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Youtube validator';
  $rule->name = 'youtube_validator';
  $rule->field_name = 'field_embed_code';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'youtube_embed';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '(^<iframe).*(src=".*www\\.youtube\\.com).*(<\\/iframe>$)',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 1,
  );
  $rule->error_message = 'The code pasted is not a valid Youtube embed fragment.';
  $export['youtube_validator'] = $rule;

  return $export;
}
