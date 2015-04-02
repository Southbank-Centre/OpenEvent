southbankcentre.org
===================

## Drupal

### Quickstart

To set up a local development site using this code, do the following:

* define a *[your-name].settings.php* file containing database settings, base URL, and (optionally) Master settings overrides (as per the samples below)
* symlink *local.settings.php* to this file
* run the Drupal installer
* enable the Master module
* run `drush master-execute`

### Settings

The *settings.php* file should not contain any configuration which is specific to a particular environment (e.g. database settings). Instead, these should be placed into an environment-specific settings file, e.g. *staging.settings.php*.

**NB: These files should not be committed to the main git repository as they contain sensitive information.**

The correct environment-specific settings file will be selected by the deployment script, and a symlink created pointing to this file from *local.settings.php*. This path is included at the end of *settings.php*, so will be automatically pulled in by Drupal.

An example environment-specific settings file would look like this:

    <?php

        $databases = array (
          'default' =>
          array (
            'default' =>
            array (
              'database' => 'sc_drupal',
              'username' => 'sc_drupal_user',
              'password' => 'insert_password_here',
              'host' => 'localhost',
              'port' => '',
              'driver' => 'mysql',
              'prefix' => '',
            ),
          ),
        );

        $base_url = 'http://sc.fnord';

    ?>

### Master

This site uses the [Master](https://www.drupal.org/project/master) module to manage which modules are enabled/disabled in different environments.

The *settings.php* file contains an include for *master.conf.php*: this holds the Master settings for the different environments (*scopes*, in Master's terminology).

Settings from *master.conf.php* can also be overridden in individual environment-specific settings files (as described above).

    <?php

        ...

        // Master settings overrides

        $conf['master_current_scope'] = 'local';

        $conf['master_modules']['local'] = array(
          'field_ui',
        );

        $conf['master_uninstall_blacklist']['local'] = array();

    ?>


## Continuous Integration

See CI.md in the *Southbank-Centre/southbankcentre-front-end* repository for more details.
