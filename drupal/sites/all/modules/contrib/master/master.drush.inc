<?php

/**
 * @file
 * Drush implementation for the master module.
 */

/**
 * Implements hook_drush_command().
 */
function master_drush_command() {
  return array(
    'master' => array(
      'description' => 'Shows general information about master.',
      'examples' => array(
        'drush help master-set-current-scope' => 'More information about the master-set-current-scope command.',
        'drush help master-status' => 'More information about the drush master-status command.',
        'drush help master-execute' => 'More information about the drush master-execute command.',
        'drush help master-export' => 'More information about drush master-export.',
        'drush help master-removables' => 'More information about drush master-removables.',
        'drush help master-absent' => 'More information about drush master-absent.',
      ),
    ),
    'master-set-current-scope' => array(
      'description' => 'Set the current scope for the installation, unless it is hardcoded in the settings.php. That scope will be used as default for the other commands.',
      'examples' => array(
        'drush master-set-current-scope local' => 'Sets the current scope to "local".',
      ),
      'aliases' => array('master-set-scope', 'master-scope'),
    ),
    'master-execute' => array(
      'description' => 'Ensure (only) master modules are installed with all dependencies.',
      'options' => array(
        'scope' => 'Choose the scope to execute, defaults to "master_current_scope".',
        'skip-scope-validation' => 'Skip check on scope specific variable. By default scopes can only be used if there is at least an empty configuration set.',
        'no-disable' => 'Set if no modules shall be disabled.',
        'no-uninstall' => 'Set if no module shall be uninstalled.',
      ),
      'examples' => array(
        'drush master-execute --scope=local' => 'For the local scope, it enables all master modules and requirements. Disables and uninstalls all redundant modules.',
        'drush master-excute --scope=local --no-disable --no-uninstall' => 'Ensures master modules and requirements are enabled, but does not disable or uninstall redundant modules',
      ),
      'aliases' => array(
        'master-ensure-modules',
        'master-exec',
      ),
    ),
    'master-status' => array(
      'description' => 'Show list of modules with their master status for a specific scope.',
      'options' => array(
        'scope' => 'Choose the scope to show the status for, defaults to "master_current_scope".',
        'skip-scope-validation' => 'Skip check on scope specific variable. By default scopes can only be used if there is at least an empty configuration set.',
        'status' => 'Filter by modules status. Choices: master, required, missing, redundant and/or uninstall. You can use multiple comma separated values. (i.e. --status="master,required").',
        'pipe' => 'Returns a whitespace delimited list of the names of the modules without any additional information on the state.',
        'sort' => 'Sorts the module list by machine name',
      ),
      'examples' => array(
        'drush master-status --scope=local' => 'Show all information for master modules, requirements and redundant modules for the local scope.',
        'drush master-status --scope=local --status=redundant --pipe' => 'Show a pure whitespace delimited list of all redundant modules for the local scope.',
        'drush master-status --scope=local --status=master --sort' => 'Show a sorted list of master modules of the local scope.',
      ),
    ),
    'master-export' => array(
      'description' => 'Provides a configuration array for the current module state.',
      'options' => array(
        'no-profile' => 'Do not consider the profile to be a master',
        'pipe' => 'Returns a whitespace delimited list of the names of the modules without any additional information on the state.',
        'no-uninstall-blacklist' => 'When set, output will not contain the uninstall blacklist.',
        'sort' => 'Sorts the module list by machine name',
        'scopes' => 'Comma separated list of scope identifiers. For those empty scope configs are added to the output.',
      ),
      'examples' => array(
        'drush master-export --scopes=local,stage,live' => 'Returns a PHP array for the master-modules configuration you could paste to your settings.php. It also holds empty scope configuration for local, stage and live.',
        'drush master-export --pipe --sort --no-profile' => 'Returns a whitespace delimited list of master modules, sorted by machine name. The current profile will not be considered.',
      ),
    ),
    'master-removables' => array(
      'description' => 'Provides a list of module folders that can be removed from the project.',
      'options' => array(
        'absolute' => 'Returns absolute paths for the folders',
        'pipe' => 'Returns a whitespace delimited list of the folders without any additional information on the contained modules.',
      ),
      'examples' => array(
        'drush master-removables' => 'Returns a list of removable folders, showing the contained modules.',
        'drush master-removables --absolute --pipe' => 'Returns a whitespace delimited list of absolute directory paths for removable folders.',
        'rm -rf $(drush master-removables --absolute --pipe)' => 'Remove all removable folders from the disk. Be careful with that command and only use it, if all instances completely uninstalled the contained modules and you properly backed up your work.',
      ),
    ),
    'master-absent' => array(
      'description' => 'Provides a list of modules absent from the filesystem, but needed.',
      'options' => array(
        'pipe' => 'Returns a whitespace delimited list of the absent modules.',
      ),
      'examples' => array(
        'drush master-absent' => 'Returns a list of missing modules.',
        'drush master-absent --pipe' => 'Returns a pure whitespace delimited list of missing module machine names.',
        'drush dl $(drush master-absent --pipe)' => 'Tries to download missing modules from drupal.org - only works for module names matching the project name.',
      ),
    ),
  );
}

/**
 * Drush callback for general information.
 */
function drush_master() {

  drush_print('Use one of the given commands to work with your master configuration.');
  drush_print('');
  $rows = array(
    array(
      'Command',
      'Description',
    ),
    array(
      'drush master-set-current-scope',
      'Set the current scope for the given installation, that will serve as default (unless hardcoded in settings.php).',
    ),
    array(
      'drush master-status',
      'Shows the current module status',
    ),
    array(
      'drush master-execute',
      'Sets the intended module states. Enables, disables and uninstalls modules.',
    ),
    array(
      'drush master-export',
      'Get the configuration for the current module set.',
    ),
    array(
      'drush master-removables',
      'Get a list of removable folders of your installations module directories.',
    ),
    array(
      'drush master-absent',
      'Get a list of absent modules. Missing in general (system status) or because of master configuration.',
    ),
  );

  drush_print_table($rows, TRUE);
  drush_print('');
  drush_print('Use the drush help command to find out more about the specific command.');
}

/**
 * Ensures only master modules and requirements are set via drush command.
 */
function drush_master_execute() {

  // Retrieve the scope data, either from option, prompt or current value.
  $scope = drush_master_get_scope();
  if (empty($scope)) {
    drush_die();
    return;
  }

  $no_disable = drush_get_option('no-disable');
  $no_uninstall = drush_get_option('no-uninstall');

  $master_modules = master_get_master_modules($scope);

  // Check if master modules are set.
  if (!master_is_set($scope)) {
    drush_log('No master modules are set!', 'error');
    return;
  }

  // Get status information for the given master module set.
  $status = master_get_change_status_information($master_modules);

  // If no modules have to be enabled, we just show the status.
  if (empty($status['missing'])) {
    drush_log('All master modules and requirements are enabled.', 'ok');
  }
  // Else we invoke enabling of the other modules.
  else {
    drush_print(dt('The following modules will be enabled: !modules', array('!modules' => implode(', ', $status['missing']))));
    if (drush_confirm(dt('Do you really want to continue?'))) {
      foreach ($status['missing'] as $module) {
        drush_invoke_process(drush_sitealias_get_record('@self'), 'pm-enable', array($module));
      }
    }
    else {
      drush_die('Aborting.');
    }
  }

  $blacklist = master_get_uninstall_blacklist($scope);
  $uninstall = array_diff($status['uninstall'], $blacklist);
  $uninstall_skip = array_intersect($status['uninstall'], $blacklist);

  // Uninstall modules that are not enabled.
  if (empty($uninstall)) {
    drush_log('No modules have to be uninstalled.', 'ok');
  }
  elseif ($no_uninstall) {
    drush_log(dt('Uninstall of modules is skipped, but following modules should be uninstalled: !modules', array('!modules' => implode(', ', $uninstall))), 'notice');
  }
  else {
    drush_print(dt('The following modules will be uninstalled: !modules', array('!modules' => implode(', ', $uninstall))));

    if (drush_confirm(dt('Do you really want to continue?'))) {
      foreach ($uninstall as $module) {
        drush_invoke_process(drush_sitealias_get_record('@self'), 'pm-uninstall', array($module));
      }
    }
    else {
      drush_die('Aborting.');
    }
  }

  // Disable modules if there are some redundant ones.
  if (empty($status['redundant'])) {
    drush_log('No modules have to be disabled.', 'ok');
  }
  elseif ($no_disable) {
    drush_log(dt('Disabling of modules is skipped, but following modules should be disabled: !modules', array('!modules' => implode(', ', $status['redundant']))), 'notice');
  }
  else {
    if (empty($no_uninstall)) {
      drush_print(dt('The following modules will be disabled and uninstalled: !modules', array('!modules' => implode(', ', $status['redundant']))));
    }
    // The message for no uninstall mode has to be a little different.
    else {
      drush_print(dt('The following modules will be disabled : !modules', array('!modules' => implode(', ', $status['redundant']))));
    }

    if (drush_confirm(dt('Do you really want to continue?'))) {
      foreach ($status['redundant'] as $module) {
        // First we disable, then we uninstall.
        drush_invoke_process(drush_sitealias_get_record('@self'), 'pm-disable', array($module));

        // Uninstall directly to avoid uninstall to break if they need
        // another module for that to be enabled.
        // Skip uninstall if the module is on the blacklist.
        if (in_array($module, $blacklist)) {
          $uninstall_skip[] = $module;
        }
        elseif (empty($no_uninstall)) {
          drush_invoke_process(drush_sitealias_get_record('@self'), 'pm-uninstall', array($module));
        }
      }

      // Show notice if no uninstall is activated.
      if (!empty($no_uninstall)) {
        drush_log(dt('Uninstall of modules is skipped, so the disabled modules were not uninstalled.'), 'notice');
      }
    }
    else {
      drush_die('Aborting.');
    }
  }

  // Show notification for modules that are on the uninstall blacklist.
  if (!empty($uninstall_skip)) {
    drush_print(dt('The following modules are on the uninstall blacklist and have not been uninstalled: !modules', array('!modules' => implode(', ', $uninstall_skip))));
  }
}

/**
 * Drush callback to show master dependent module status.
 */
function drush_master_status() {

  // Retrieve the scope data, either from option, prompt or current value.
  $scope = drush_master_get_scope();
  if (empty($scope)) {
    drush_die();
    return;
  }

  // Show scope information.
  _drush_master_print_scope_table($scope);
  drush_print('');

  // Getting options from drush command.
  $status_modes = drush_get_option_list('status');
  $pipe = drush_get_option('pipe');
  $sort = drush_get_option('sort');

  $master_modules = master_get_master_modules($scope);

  // Check if master modules are set.
  if (!master_is_set($scope)) {
    drush_log('No master modules are set!', 'error');
    return;
  }

  $required = master_get_required_modules($master_modules);
  $status = master_get_change_status_information($master_modules);

  // Add master and required to status, so we can reuse it in the loop in a
  // generic way.
  $status[MASTER_STATUS_MASTER] = $master_modules;
  $status[MASTER_STATUS_REQUIRED] = $required;

  // Definition of available modes to use in the loop.
  $modes = master_get_status_infos();

  $pipe_modules = array();
  foreach ($modes as $mode => $info) {
    if (empty($status_modes) || in_array($mode, $status_modes)) {
      if (!empty($sort)) {
        sort($status[$mode]);
      }

      if (empty($pipe)) {
        _drush_master_print_module_table($status[$mode], $info['label']);
        drush_print('');
      }
      else {
        $pipe_modules = array_merge($pipe_modules, $status[$mode]);
      }
    }
  }

  // Print pipe if we are in pipe mode.
  if (!empty($pipe)) {
    if (!empty($sort)) {
      sort($pipe_modules);
    }
    drush_print_pipe(array_unique($pipe_modules));
  }
}

/**
 * Helper to print scope table.
 */
function _drush_master_print_scope_table($scope) {

  // Print information on scopes.
  drush_print('Scopes');
  drush_print(str_repeat('-', 60));

  $rows = array();

  $current_scope = master_get_config('current_scope');
  $rows[] = array(
    dt('Selected scope:'),
    $scope,
  );
  $rows[] = array(
    dt('Current scope:'),
    ($current_scope) ? $current_scope : dt('- none -'),
  );
  $rows[] = array(
    dt('Available scopes:'),
    implode(', ', master_get_scopes()),
  );
  drush_print_table($rows, FALSE);
}

/**
 * Helper to print a table for a given module list.
 *
 * @param $modules
 * @param string $title
 */
function _drush_master_print_module_table($modules, $title = 'Modules') {
  // Lists master modules.
  $enabled = 0;
  if (!empty($modules)) {
    $rows = array();
    $module_data = master_get_module_data();
    foreach ($modules as $module) {
      if (!isset($module_data[$module])) {
        // No module data is available, so we mark it so.
        $rows[] = array(
          $module,
          dt('n/a'),
          dt('n/a'),
        );
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

        $rows[] = array(
          $module,
          $module_data[$module]->info['name'],
          $status,
        );
      }
    }
  }
  drush_print(dt('@title (@enabled / @count)', array('@enabled' => $enabled, '@title' => $title, '@count' => count($modules))));
  drush_print(str_repeat('-', 60));
  if (!empty($rows)) {
    drush_print_table($rows, TRUE);
  }
  else {
    drush_print(dt('- No modules -'));
  }
}

/**
 * Drush callback to provide an export of the current module set.
 */
function drush_master_export() {

  $no_profile = drush_get_option('no-profile');
  $pipe = drush_get_option('pipe');
  $sort = drush_get_option('sort');

  // Default output is a PHP-Array.
  if (empty($pipe)) {
    $scopes = drush_get_option_list('scopes');
    $no_uninstall = drush_get_option('no-uninstall');
    // We got a wrapper function for the php output.
    $export = master_get_config_recommendation($scopes, $no_profile, $no_uninstall, $sort);

    drush_print($export);
  }
  else {
    $recommended_masters = master_get_master_modules_recommendation(!$no_profile);
    // Sort if we wanted to.
    if (!empty($sort)) {
      sort($recommended_masters);
    }

    drush_print_pipe(array_unique($recommended_masters));
  }
}

/**
 * Drush callback to provide removable folders.
 */
function drush_master_removables() {

  $absolute = drush_get_option('absolute');
  $pipe = drush_get_option('pipe');

  $blacklist = master_get_removable_blacklist();
  $folders = master_get_project_folders();
  $removables = master_filter_removable_folders($folders, $blacklist);

  // Build the
  if (!empty($absolute)) {
    $removables_temp = array();
    foreach ($removables as $folder => $modules) {
      $removables_temp[DRUPAL_ROOT . '/' . $folder] = $modules;
    }
    $removables = $removables_temp;
  }

  // Default output is a PHP-Array.
  if (empty($pipe)) {
    // Print a table if we got removable folders.
    if (count($removables)) {
      $rows = array();
      $rows[] = array(dt('Folder'), dt('Modules'));

      foreach ($removables as $folder => $modules) {
        $rows[] = array($folder, implode(', ', $modules));
      }

      drush_print_table($rows, TRUE);
    }
    else {
      drush_print(dt('- No removable folders -'));
    }
  }
  else {
    drush_print_pipe(array_keys($removables));
  }
}

/**
 * Drush callback to for listing missing modules.
 */
function drush_master_absent() {

  $pipe = drush_get_option('pipe');

  $absent = master_get_absent_modules();

  // Default output is a PHP-Array.
  if (empty($pipe)) {
    // Print a table if we got removable folders.
    if (count($absent)) {
      $rows = array();
      $rows[] = array(dt('Module'));

      foreach($absent as $module) {
        $rows[] = array($module);
      }

      drush_print_table($rows, TRUE);
    }
    else {
      drush_print(dt('- No absent modules -'));
    }
  }
  else {
    drush_print_pipe(array_keys($absent));
  }
}

/**
 * Helps to prompt or retrieve the scope to be used.
 *
 * @return string
 *   The scope to use as string. Empty string means no valid scope was
 *   retrieved.
 */
function  drush_master_get_scope() {
  // If no scopes are defined, we cannot proceed.
  $scopes = master_get_scopes();
  if (empty($scopes)) {
    drush_set_error('No scopes are available.');
    return '';
  }

  $scope = drush_get_option('scope');
  $current_scope = master_get_config('current_scope');
  $skip_scope_validation = drush_get_option('skip-scope-validation');

  // Validate scope.
  if (isset($scope) && !$skip_scope_validation && !master_validate_scope($scope)) {
    drush_set_error(dt('The given scope "@scope" is not valid!', array('@scope' => $scope)));
    return '';
  }

  // If no scope is given, but a current scope is set, simply use that.
  if (is_null($scope) && !is_null($current_scope)) {
    return $current_scope;
  }
  // If no scope and no current scope is set, we prompt for the scope selection.
  elseif (is_null($scope) && is_null($current_scope)) {
    $selection = drush_choice($scopes, 'Select the scope to use.');
    drush_print($selection);
    $scope = $selection;
  }

  // If scope is selected and no current scope is given, set current scope and
  // show message to permanently set the scope.
  if (is_null($current_scope) && $scope) {
    drush_print(dt("The current scope was set to '@scope' and will be used as default for all following calls.", array('@scope' => $scope)));
    drush_master_set_current_scope($scope);
    $current_scope = $scope;
  }

  // If the (selected) scope is not equal to the current scope, we prompt for
  // confirmation.
  if ($scope != $current_scope) {
    $confirmed = drush_confirm(dt("Are you sure you want to use '@scope' instead of current scope: @current_scope?", array('@scope' => $scope, '@current_scope' => $current_scope)));
    if (!$confirmed) {
      drush_user_abort();
      return '';
    }

    // Ask for setting as current scope.
    $set_as_current_scope = drush_confirm(dt("Do you want to set '@scope' as new current scope?", array('@scope' => $scope)));
    if ($set_as_current_scope) {
      drush_master_set_current_scope($scope);
    }
  }

  return $scope;
}

/**
 * Drush callback for setting the current scope.
 *
 * @param string $scope
 */
function drush_master_set_current_scope($scope) {
  if (!master_validate_scope($scope)) {
    drush_set_error(dt('The given scope "@scope" is not valid!', array('@scope' => $scope)));
    return FALSE;
  }

  variable_set('master_current_scope', $scope);
  drush_log(dt('Current scope was set to "@scope".', array('@scope' => $scope)), 'success');
}
