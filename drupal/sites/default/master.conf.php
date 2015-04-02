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

