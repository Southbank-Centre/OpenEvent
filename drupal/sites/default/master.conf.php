<?php
$conf['master_version'] = 2;
$conf['master_modules'] = array(
  'base' => array(
    // Core modules
    'contextual',
    'field',
    'file',
    'filter',
    'help',
    'image',
    'list',
    'menu',
    'node',
    'number',
    'options',
    'path',
    'shortcut',
    'system',
    'taxonomy',
    'text',
    'toolbar',
    'user',
    'varnish',

    // Contributed modules
    'addressfield',
    'better_formats',
    'cer',
    'ctools',
    'date',
    'date_all_day',
    'date_api',
    'date_popup',
    'diff',
    'double_field',
    'entity',
    'entityreference',
    'features',
    'field_group',
    'field_validation',
    'filefield_sources',
    'geolocation',
    'geolocation_googlemaps',
    'libraries',
    'link',
    'master',
    'menu_firstchild',
    'migrate',
    'menu_firstchild',
    'office_hours',
    'paragraphs',
    'pathauto',
    'relation',
    'relation_add',
    'relation_endpoint',
    'restws',
    'shs',
    'strongarm',
    'table_element',
    'taxonomy_access_fix',
    'token',
    'transliteration',
    'view_unpublished',
    'views',
    'views_data_export',

    // Open Event
    'oe_components',
    'oe_event',
    'oe_place',

    // Southbank Centre features
    'sc_style_guide',
    'sc_menu_api',

  ),
  'dev' => array(
    'field_ui',
    'field_validation_ui',
    'views_ui',
    'migrate_ui',
    'relation_ui',
    'dblog',
  ),
  'staging' => array(
    'syslog',
  ),
  'live' => array(
    'syslog',
  ),
);
$conf['master_uninstall_blacklist'] = array(
  'base' => array(),
  'dev' => array(),
  'staging' => array(),
  'live' => array(),
);
$conf['master_allow_base_scope'] = TRUE;
