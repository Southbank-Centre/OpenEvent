<?php
/**
 * @file
 * sc_style_guide.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function sc_style_guide_filter_default_formats() {
  $formats = array();

  // Exported format: Style guide HTML.
  $formats['style_guide_html'] = array(
    'format' => 'style_guide_html',
    'name' => 'Style guide HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'htmltidy' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'htmltidy_filter_style_guide_html' => array(
            'paths' => array(
              'app' => '/usr/bin/tidy',
              'config' => 'profiles/openevent/modules/features/sc_style_guide/htmltidy.conf',
            ),
            'format' => array(
              'process_input' => 1,
              'indent' => 1,
              'wordwrap' => 80,
              'wrapphp' => 1,
              'tidymark' => 0,
              'clean' => 1,
              'xhtml' => 1,
              'doctype' => 'auto',
              'enclosetext' => 0,
              'encloseblocktext' => 0,
              'wordcleanup' => 1,
            ),
            'debug' => array(
              'warnings' => 0,
              'verbose' => 0,
              'runtwice' => 1,
            ),
          ),
        ),
      ),
    ),
  );

  return $formats;
}
