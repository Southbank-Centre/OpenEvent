<?php

$databases = array (
  'default' => 
  array (
    'default' => 
    array (
      'database' => 'sc_drupal',
      'username' => 'root',
      'password' => '',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

$base_url = 'http://localhost/wow/back/drupal/';

$conf['master_current_scope'] = 'local';

$conf['master_modules']['local'] = array(
  'field_ui',
);

$conf['master_uninstall_blacklist']['local'] = array();

?>
