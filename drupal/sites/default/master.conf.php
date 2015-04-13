<?php
$conf['master_version'] = 2;
$conf['master_modules'] = array(
  'base' => array(
    // Core modules
    'contextual',
    'file',
    'help',
    'image',
    'list',
    'menu',
    'node',
    'number',
    'options',
    'path',
    'shortcut',
    'syslog',
    'system',
    'taxonomy',
    'text',
    'toolbar',
    'user',

    // Contributed modules
    'ctools',
    'cer',
    'date',
    'date_all_day',
    'date_api',
    'date_popup',
    'auto_entitylabel',
    'better_formats',
    'color_field',
    'entity',
    'entityreference',
    'features',
    'field_group',
    'field_validation',
    'filefield_sources',
    'libraries',
    'link',
    'pathauto',
    'restws',
    'shs',
    'strongarm',
    'taxonomy_access_fix',
    'token',
    'transliteration',
    'view_unpublished',
    'views',
    'views_data_export',
    'table_element',
    'migrate',
    'paragraphs',

    // OE related
      'oe_shared_field_bases',
      'oe_content_components',
      'oe_event',

  ),
  'dev' => array(
    'field_ui',
    'field_validation_ui',
    'views_ui',
    'migrate_ui',
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
