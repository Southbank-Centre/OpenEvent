<?php
/**
 * @file
 * sc_style_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sc_style_guide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sc_style_guide_node_info() {
  $items = array(
    'style_guide_page' => array(
      'name' => t('Style guide page'),
      'base' => 'node_content',
      'description' => t('A page that will appear in the style guide, once it has been assigned to a Style guide chapter.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
