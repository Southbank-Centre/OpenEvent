<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function openevent_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['admin_account']['account']['name']['#default_value'] = 'root';
  $form['update_notifications']['update_status_module']['#default_value'] = array(0,0);
}

/**
 * Implements hook_requirements().
 */
function openevent_requirements($phase) {
  $requirements = array();

  if ($phase === 'runtime') {
    // Check if clean urls are enabled by peering into Drupal variables.
    // It is insufficient but very light and will be accurate if Drupal is
    // configured correctly.
    if (variable_get('clean_url', 0)) {
      $value = t('Enabled');
      $severity = REQUIREMENT_OK;
      $description = NULL;
    } else {
      $value = t('Disabled');
      $severity = REQUIREMENT_ERROR;
      $description = t('Clean URLs must be enabled for the JSON API filtering to work.');
    }


    $requirements ['openevent'] = array(
      'title' => t('Clean URLs required for Open Event JSON API'),
      'value' => $value,
      'description' => $description,
      'severity' => $severity,
    );
  }

  return $requirements;
}