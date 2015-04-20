<?php
$conf['master_version'] = 2;
$conf['master_modules'] = array(
  'base' => array(
    // Core
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

    // Contrib
    'better_formats',
    'cer',
    'ctools',
    'date',
    'date_all_day',
    'date_api',
    'date_popup',
    'diff',
    'entity',
    'entityreference',
    'features',
    'field_group',
    'field_validation',
    'filefield_sources',
    'libraries',
    'link',
    'master',
    'migrate',
    'paragraphs',
    'pathauto',
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
    'oe_content_components',
    'oe_event',
    'oe_shared_field_bases',
  ),
  'dev' => array(
    'field_ui',
    'field_validation_ui',
    'views_ui',
    'migrate_ui',
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
