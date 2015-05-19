southbankcentre.org-CMS
===================

## Drupal

### Quickstart

To set up a local development site using this code, do the following:

* define a `[your-name].settings.php` file containing database settings, base URL, and (optionally) Master settings overrides (as per the samples below)
* copy the file above to `local.settings.php`
* run the Drupal makefile

		drush make local-openevent.make -y

* install the openevent profile

		drush si openevent --account-name="USER" --account-pass="PASS" -y
	where USER and PASS are the preferred username/password combination

* set permissions

		chmod u+w sites/default

		chmod 777 sites/default/files

* enable master module

		drush en master -y

* ensure all required modules are activated

		drush master-execute -y

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

See CI.md for more details.
