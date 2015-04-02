<?php

/**
 * @file
 * Callbacks for administration page.
 */

/**
 * Form callback for controlling master.
 */
function master_admin_list($form, &$form_state) {

  // Show a subtitle.
  $form['subtitle'] = array(
    '#markup' => '<h2>' . t('Master scopes') . '</h2>',
  );

  // If there is no master modules configuration set, we show a recommended
  // configuration to copy paste.
  if (!master_is_set(MASTER_BASE)) {
    drupal_set_message(t('No master configuration available.'), 'error');
    $form['recommendation'] = array(
      '#title' => t('Recommended configuration'),
      '#description' => t('Copy this or similar code to the settings.php to provide a master configuration.'),
      '#type' => 'textarea',
      '#value' => master_get_config_recommendation(array('local', 'live')),
      '#rows' => 20,
    );
    return $form;
  }

  // Provide form to select scope.
  $scopes = master_get_scopes();

  $form['master_current_scope'] = array(
    '#type' => 'select',
    '#title' => t('Current scope'),
    '#options' => $scopes,
    '#empty_option' => t('- No scope selected -'),
    '#default_value' => master_get_config('current_scope'),
    '#description' => t('Select the scope, that should be used as default, e.g. when executing drush commands.'),
  );

  $current_scope = master_get_current_scope();
  $rows = array();
  foreach ($scopes as $scope => $label) {
    $current_scope_text = ($scope === $current_scope) ? ' ' . t('(current scope)') : '';

    $rows[] = array(
      l($label, 'admin/modules/master/scopes/' . $scope) . $current_scope_text,
    );
  }

  $form['scope_list_title'] = array(
    '#markup' => '<h3>' . t('Defined scopes') . '</h3>',
  );
  $form['scope_list'] = array(
    '#theme' => 'table',
    '#header' => array(t('Scope')),
    '#rows' => $rows,
  );

  return system_settings_form($form);
}

/**
 * Render callback for displaying removable projects.
 */
function master_admin_removables() {

  $blacklist = master_get_removable_blacklist();
  $folders = master_get_project_folders();
  $removables = master_filter_removable_folders($folders, $blacklist);

  $return = array();

  // Show a subtitle.
  $return['subtitle'] = array(
    '#markup' => '<h2>' . t('Master removables') . '</h2>',
  );

  $return['description'] = array(
    '#markup' => t("The list shows module folders, that could be removed from the project, due to the master configuration and the current modules' state."),
  );

  // Print a table of removable folders information.
  $return['removables'] = array(
    '#theme' => 'table',
    '#header' => array(t('Folder'), t('Modules')),
    '#rows' => array(),
    '#empty' => t('- No removable folders -'),
  );

  foreach ($removables as $folder => $modules) {
    $return['removables']['#rows'][] = array(
      check_plain($folder),
      check_plain(implode(', ', $modules)),
    );
  }

  $return['blacklisted'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Blacklisted folders'),
    '#description' => t('These folders, should not be removed, as they are blacklisted by the <code>master_removable_blacklist</code> configuration.'),
  );

  // Build diff of removable with and without blacklist.
  $removables_without_blacklist = master_filter_removable_folders($folders, array());
  $blacklisted_removables = array_diff_key($removables_without_blacklist, $removables);

  // Print a table of removable folders information.
  $return['blacklisted']['removables'] = array(
    '#theme' => 'table',
    '#header' => array(t('Folder'), t('Modules')),
    '#rows' => array(),
    '#empty' => t('- No blacklisted removable folders -'),
  );
  foreach ($blacklisted_removables as $folder => $modules) {
    $return['blacklisted']['removables']['#rows'][] = array(
      check_plain($folder),
      check_plain(implode(', ', $modules)),
    );
  }

  $return['absent'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Absent modules'),
    '#description' => t('In some cases, modules are missing from the filesystem, that are either part of the master configuration, still marked enabled or were not uninstalled. This may lead to unforeseen behaviour and can cause significant performance problems.'),
  );

  $absent_modules = master_get_absent_modules();
  if (!count($absent_modules)) {
    $absent_modules[] = t('- No absent modules retrieved. -');
  }
  // Print a table of removable folders information.
  $return['absent']['modules'] = array(
    '#theme' => 'item_list',
    '#items' => $absent_modules,
    '#title' => t('Modules')
  );

  return $return;
}

/**
 * Form callback for the master settings.
 */
function master_admin_settings($form, &$form_state) {
  // Show a subtitle.
  $form['subtitle'] = array(
    '#markup' => '<h2>' . t('Master settings') . '</h2>',
  );

  $form['description'] = array(
    '#markup' => t('This page currently only displays the current settings. To change them, you have to alter your <code>settings.php</code>.'),
  );

  $form['current'] = array(
    '#theme' => 'table',
    '#header' => array(
      t('Label'),
      t('Key'),
      t('Scope'),
      t('Current value'),
      t('Description'),
    ),
    '#rows' => array(),
  );

  $form['current']['#rows'][] = array(
    t('Allow base scope'),
    'master_allow_base_scope',
    '',
    master_get_config('allow_base_scope') ? 'TRUE' : 'FALSE',
    '',
  );
  $form['current']['#rows'][] = array(
    t('Current scope'),
    'master_current_scope',
    '',
    !is_null(master_get_config('current_scope')) ? master_get_config('current_scope') : 'NULL',
    '',
  );
  $form['current']['#rows'][] = array(
    t('Master modules'),
    'master_modules',
    MASTER_BASE,
    implode(', ', master_get_config('modules', MASTER_BASE)),
    '',
  );
  foreach (master_get_scopes() as $scope => $label) {
    $form['current']['#rows'][] = array(
      t('- additional for %scope', array('%scope' => $label)),
      '',
      $scope,
      implode(', ', master_get_config('modules', $scope)),
      '',
    );
  }
  $form['current']['#rows'][] = array(
    t('Uninstall blacklist'),
    'master_uninstall_blacklist',
    MASTER_BASE,
    implode(', ', master_get_config('uninstall_blacklist', MASTER_BASE)),
    '',
  );
  foreach (master_get_scopes() as $scope => $label) {
    $form['current']['#rows'][] = array(
      t('- additional for %scope', array('%scope' => $label)),
      '',
      $scope,
      implode(', ', master_get_config('uninstall_blacklist', $scope)),
      '',
    );
  }

  $form['current']['#rows'][] = array(
    t('Removable folders blacklist'),
    'master_removable_blacklist',
    '',
    implode(', ', master_get_removable_blacklist()),
    '',
  );

  // @todo: extend if not master configuration is given
  $form['configurator'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Configurator'),
    '#description' => t('If you wanted to export the current module set as new master configuration you could use this recommended one. It holds all modules that are currently enabled.'),
    'recommendation' => array(
      '#title' => t('Current module set'),
      '#description' => t('Copy this or similar code to the settings.php to provide a master configuration.'),
      '#type' => 'textarea',
      '#value' => master_get_config_recommendation(array_keys(master_get_scopes())),
      '#rows' => 20,
    ),
  );

  return $form;
}

/**
 * Page title callback for the scope page.
 *
 * @param string $scope
 *
 * @return string
 */
function master_scope_page_title($scope) {
  return t('Master scope: @scope', array('@scope' => $scope));
}

/**
 * Form callback for a single scope overview page.
 *
 * @param array $form
 *   Form API form array
 * @param array $form_state
 *   Form API form_state
 * @param string $scope
 *   Machine name for the scope.
 *
 * @return array
 *   Form array representing the scope state
 */
function master_admin_scope_form($form, &$form_state, $scope) {

  $form['back'] = array(
    '#theme' => 'link',
    '#path' => 'admin/modules/master',
    '#text' => t('Back'),
    '#options' => array(
      'attributes' => array(
        'class' => array('backlink'),
      ),
      'html' => FALSE,
    ),
  );

  // Show a subtitle.
  $form['subtitle'] = array(
    '#markup' => '<h2>' . t('Configuration for %scope', array('%scope' => ($scope) ? $scope : t('- Empty scope -'))) . '</h2>',
  );

  $master_modules = master_get_master_modules($scope);

  $required = master_get_required_modules($master_modules);
  $status_modules = master_get_change_status_information($master_modules);

  // Add master and required to status, so we can reuse it in the loop in a
  // generic way.
  $status_modules[MASTER_STATUS_MASTER] = $master_modules;
  $status_modules[MASTER_STATUS_REQUIRED] = $required;

  // Provide the vertical tabs wrapper.
  $form['vt_modules'] = array(
    '#type' => 'vertical_tabs',
  );

  $status_labels = master_get_status_infos();

  // Build rows array to display a table.
  foreach ($status_labels as $status => $info) {
    $modules = $status_modules[$status];

    $form[$status] = array(
      '#type' => 'fieldset',
      '#title' => t('@status_label (@count)', array('@status_label' => $info['label'], '@count' => count($modules))),
      '#description' => $info['description'],
      '#collapsible' => TRUE,
      '#group' => 'vt_modules',
    );
    $form[$status]['modules'] = _master_admin_subform_modules($modules);
  }

  // @todo: add submit buttons to change state.
  return $form;
}

/**
 * Helper function to get master status from given modules.
 *
 * @param array $modules
 *  list of module machine names
 *
 * @return array
 *    Machine-name, module-name and module-status
 */
function _master_admin_subform_modules($modules) {
  $module_data = master_get_module_data_for_scope();

  $enabled = 0;
  $rows = array();
  $disable_checkboxes = array();
  foreach ($modules as $module) {
    if (!isset($module_data[$module])) {
      // No module data is available, so we mark it so.
      $rows[$module] = array(
        $module,
        t('n/a'),
        t('n/a'),
      );
      // If we got no info about the module, we cannot take action on it.
      $disable_checkboxes[] = $module;
    }
    else {
      // Get concrete status.
      if (!empty($module_data[$module]->status)) {
        $enabled++;
        $status = 'enabled';
      }
      elseif ($module_data[$module]->schema_version == -1) {
        $status = 'uninstalled';
      }
      else {
        $status = 'disabled';
      }

      $rows[$module] = array(
        $module,
        $module_data[$module]->info['name'],
        $status,
      );

      // If there is no action needed on that module, we disable the checkbox.
      if (!$module_data[$module]->master_status[MASTER_STATUS_REDUNDANT]
        && !$module_data[$module]->master_status[MASTER_STATUS_MISSING]
        && !$module_data[$module]->master_status[MASTER_STATUS_UNINSTALL]) {
        $disable_checkboxes[] = $module;
      }
    }
  }

  // Header for the module table.
  $header = array(
    t('Machine-name'),
    t('Modul'),
    t('Status'),
  );

  return array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#empty' => t('- No modules -'),
    '#process' => array(
      'form_process_tableselect',
      'master_form_process_tableselect',
    ),
    '#disable_options' => $disable_checkboxes,
  );
}

/**
 * Form submission callback for the "Select scope"-Button.
 */
function master_admin_submit_scope($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Process
 *
 * @param array $element
 *   A tableselect form element after beeing processed by default processor
 *   form_process_tableselect().
 *
 * @return array
 *   The altered form element.
 *
 * @see form_process_tableselect()
 */
function master_form_process_tableselect($element) {
  // Hide the checkbox for disabled options.
  if (!empty($element['#disable_options'])) {
    foreach ($element['#disable_options'] as $option) {
      if (isset($element[$option])) {
        $element[$option]['#access'] = FALSE;
      }
    }
  }
  return $element;
}
