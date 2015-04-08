<?php

$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'sc_drupal_91354622',
          'username' => 'root',
          'password' => '',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
);

$base_url = 'http://sc.dev';

/**
 * Master settings overrides
 */
$conf['master_current_scope'] = 'dev';

$conf['master_modules']['dev'] = array(
  'field_ui',
  'diff',
  'views_ui',
  'field_validation_ui',
);

$conf['master_uninstall_blacklist']['dev'] = array();

/**
 * SMTP server settings.
 */
//$conf['smtp_host'] = 'smtp.emailsrvr.com';
//$conf['smtp_hostbackup'] = '';
//$conf['smtp_username'] = 'tassosk@cogapp.com';
//$conf['smtp_password'] = 'tkoutlas2204';
//$conf['smpt_fromname'] = 'TassosK Dev';
//$conf['smpt_from'] = 'tassosk@cogapp.com';

/**
 * STAGE_FILE_PROXY settings.
 */
//$conf['stage_file_proxy_origin']  = 'http://www.qm.org.qa';
//$conf['stage_file_proxy_hotlink'] = 1;

/**
 * Force error reporting for local dev.
 * 0 - No errors
 * 1 - Errors and warning
 * 2 - All messages
 */
$conf['error_level'] = 0;

/**
 * Main website
 */
$conf['site_mail'] = 'tassosk@cogapp.com';
$conf['site_name'] = 'SC backend development';

/**
 * CACHE settings
 */
$conf['cache'] = 1;
$conf['cache_lifetime'] = 0;
$conf['page_cache_maximum_age'] = 0;



?>
