
# Overview

This module provides tools to take control over enabled and disabled modules.
Therefore it will provide drush commands that are configurable via settings.php
configuration.

The approach in the 7.x-2.x branch is a totally different than the 6.x-1.x, as
we will (for the moment) only provide drush commands.

Nevertheless there is a new admin interface, to show the status of your master
configuration, available on `admin/modules/master`.

# What is a master module?

A master module is a module, that holds the meta-data for the drupal application
or for a part of it by defining all dependencies for the desired functionality
(like module dependencies in the module's .info file).
Modules that are not dependent to the master module are not meant to be active,
as long it is not required by another master module.

You can have only one master module that will hold all dependencies and so
represents the functionality scope for the whole application. Or you can use
multiple master modules, where one module only handles some part of the project.

For the second approach it is a common way to use Features [1] for those
modules.

# Configuration in settings.php

In your settings.php you can define some keys in your $conf array that will
define the functionality of the module.

- "master_version": This has to be set to "2" as this is the newest config
  definition for the master module. If you got an old configuration, you should
  change the settings to fit the new layout.
- "master_modules": an array of module lists that are meant to be master
  modules for the specific scope. Each array is keyed by the name of the scope.
  The base configuration that will be shared in all scopes, is keyed by 'base'.
  See example below.
- "master_uninstall_blacklist": list of modules that shall not be uninstalled,
  again keyed by the specific scope.
  See example below.
- "master_allow_base_scope": Set to TRUE if the base scope may be used as real
  scope in your environment.
- "master_removable_blacklist": Provides an array of path patterns, that shall
  be ignored by the `drush master-removables` command. It defaults to the core
  module directory: `array('modules/*')`.

## Getting started

You can export the current state of the installation as initial configuration
array by using the `drush master-export` command. You can use that array as base
for changing the module list.

Meanwhile we are providing status pages on the Drupal backend. Simply navigate
to `admin/modules/master`.

## Example

<?php
$conf['master_version'] = 2;
$conf['master_modules'] = array(
  'base' => array(
    'mymasterfeature1',
    'mymasterfeature2',
  ),
  'local' => array(
    'devel',
    'views_ui',
    'field_ui',
  ),
  'live' => array(),
);
$conf['master_uninstall_blacklist'] = array(
  'base' => array(),
  'live' => array('migrate'),
);
$conf['master_allow_base_scope'] = TRUE; // Defaults to FALSE.
$conf['master_current_scope'] = 'local';
?>

# What is scope used for?

You can specify an additional master module list for a specific scope. A common
use case is, to use different scopes for different stages, like "local",
"testing" or "live". The 'base' scope is the parent scope to be used by every
defined scope.

By calling the drush command with a --scope you are able to add additional
modules to that master module set only for this specific scope.

Example:
- drush master-execute --scope=local
- drush master-execute --scope=live

You can set the default scope for your environment by setting the current scope
on the admin page or calling the command `drush master-set-current-scope`. Be
aware that configuration in the settings.php will allways override current scope
set in the database.

# More examples

By using `drush help` more examples are provided.

[1] http://drupal.org/project/features
