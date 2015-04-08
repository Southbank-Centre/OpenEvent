<?php

$conf['master_version'] = 2;

$conf['master_modules'] = array(
  'base' => array(
    // Core modules
    //'block',
    //'color',
    //'comment',
    'contextual',
    //'dashboard',
    //'dblog',
    'file',
    'help',
    'image',
    'list',
    'menu',
    'number',
    'options',
    //'overlay',
    'path',
    //'rdf',
    //'search',
    'shortcut',
    'syslog',
    'toolbar',
    //'update',

    // START: Migrate to OE profile
    'better_formats',
    'cer',
    'ctools',
    'date',
    'date_popup',
    'diff', // Dev
    'entity',
    'entityreference',
    'features',
    'features_diff', // Dev
    'field_group',
    'field_validation',
    'field_validation_ui', // Dev
    'oe_event',
    'oe_shared_field_bases',
    'restws',
    'table_element',
    'views',
    'views_ui', // Dev
    // END: Migrate to OE profile
  ),

  'dev' => array(
    'field_ui',
    'varnish',
  ),
  'staging' => array(
    'varnish',
  ),
  'live' => array(
    'varnish',
  ),
);

$conf['master_uninstall_blacklist'] = array(
  'base' => array(),
  'dev' => array(),
  'staging' => array(),
  'live' => array(),
);

$conf['master_allow_base_scope'] = TRUE;

