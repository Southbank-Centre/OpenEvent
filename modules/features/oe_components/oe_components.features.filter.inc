<?php
/**
 * @file
 * oe_components.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function oe_components_filter_default_formats() {
  $formats = array();

  // Exported format: Iframe HTML.
  $formats['iframe_html'] = array(
    'format' => 'iframe_html',
    'name' => 'Iframe HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<iframe>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
