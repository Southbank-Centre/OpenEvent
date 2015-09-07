# OPEN EVENT DISTRIBUTION

License: GPL 2.0+

## CONTENTS OF THIS FILE

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Open Event API
 * Testing
 * Troubleshooting
 * Maintainers



## Introduction
Open Event is a Drupal distribution that has been created by Southbank Centre for use by other arts and events organisations. It's been built with an open approach and data architecture that will allow for collaboration and community activity. The data output maps to [Schema.org](http://schema.org) entities which allows for greater exposure and discovery across the wider Internet.

This distribution serves as a starting point for an events-based Content Management System which you are free to build upon for your individual needs.

Equally this distribution is intended to evolve and this can be greatly helped by community support, so if you develop any additional functionality or modules that could benefit this Open Event platform please contact us or issue a pull request.



## Requirements
1) Open Event requires Drupal 7. Version 7.36 is packaged with this distribution. Detailed system requirements can be found here: [https://www.drupal.org/requirements](https://www.drupal.org/requirements)

*Please note: if you intend to use the API to access data (rather than a standard Drupal theme) then do not update to Drupal 7.37 until the following bug with RestWS has been addressed: [https://www.drupal.org/node/2484829](https://www.drupal.org/node/2484829)*

2) Clean URLS must be enabled, otherwise the API filtering will not work.

### Modules
The following modules are required. They are packaged and automatically enabled with this  distribution:

* Address Field [https://www.drupal.org/project/addressfield](https://www.drupal.org/project/addressfield)
* Auto Entity Label [https://www.drupal.org/project/auto_entitylabel](https://www.drupal.org/project/auto_entitylabel)
* Better Formats [https://www.drupal.org/project/better_formats](https://www.drupal.org/project/better_formats)
* Ctools [https://www.drupal.org/project/ctools](https://www.drupal.org/project/ctools)
* Date [https://www.drupal.org/project/date](https://www.drupal.org/project/date)
* Email [https://www.drupal.org/project/email](https://www.drupal.org/project/email)
* Entity [https://www.drupal.org/project/entity](https://www.drupal.org/project/entity)
* Field Group [https://www.drupal.org/project/field_group](https://www.drupal.org/project/field_group)
* Field Validation [https://www.drupal.org/project/field_validation](https://www.drupal.org/project/field_validation)
* FileField Sources [https://www.drupal.org/project/filefield_sources](https://www.drupal.org/project/filefield_sources)
* Geolocation [https://www.drupal.org/project/geolocation](https://www.drupal.org/project/geolocation)
* Link [https://www.drupal.org/project/link](https://www.drupal.org/project/link)
* Office Hours [https://www.drupal.org/project/office_hours](https://www.drupal.org/project/office_hours)
* Relation [https://www.drupal.org/project/relation](https://www.drupal.org/project/relation)
* Relation Add [https://www.drupal.org/project/relation_add](https://www.drupal.org/project/relation_add)
* RESTful Web Services [https://www.drupal.org/project/restws](https://www.drupal.org/project/restws)
* Taxonomy Access Fix [https://www.drupal.org/project/taxonomy_access_fix](https://www.drupal.org/project/taxonomy_access_fix)
* Token [https://www.drupal.org/project/token](https://www.drupal.org/project/token)



## Installation

To set up a website using this distribution, do one of the following:

A. Download the distribution from [https://www.drupal.org/project/openevent](https://www.drupal.org/project/openevent) and follow the Drupal installation guide: [https://www.drupal.org/documentation/install](https://www.drupal.org/documentation/install), or;

B. Run the following commands from a console/terminal window *(assuming you have Git and Drush installed)*:

1. Clone the Open Event distribution branch from GitHub:

		git clone -b master git@github.com:Southbank-Centre/OpenEvent.git DRUPAL-DIRECTORY/profiles/openevent

	Where DRUPAL-DIRECTORY is the directory name of your site root.

2. Change to the Drupal folder:

		cd DRUPAL-DIRECTORY

4. Copy the Open Event Makefile to the Drupal folder (where it needs to be run from):

		cp profiles/openevent/local-openevent.make .

4. Download Drupal core and Open Event modules and dependencies:

		drush make local-openevent.make -y

5. Create the database: https://www.drupal.org/documentation/install/create-database

6. Install Drupal, e.g. for a MySQL database:

		drush si openevent --account-name="USER" --account-pass="PASS" --db-url="mysql://DB-USER:DB-PASS@DB-HOST/DB-NAME"

	USER and PASS should be changed to your preferred Drupal login details for the Administrator account.

	DB-USER, DB-PASS, DB-HOST and DB-NAME should be changed to match your database settings.

  If the database specified doesn't exist it will be created. The ``--db-url`` parameter will add your database settings automatically to your sites/default/settings.php file. If you would prefer to define separate setting files for different environments (e.g. local.settings.php) then please omit the ``--db-url`` parameter from the command above and define your database settings manually.
	*Please note if an existing database exists it will be overwritten.*

7. Change the permissions of the files directory and the settings file

		chgrp -R WWW-GROUP sites/default/files
		chmod 2775 sites/default/files
		chmod -R g+w sites/default/files
		chmod 444 sites/default/settings.php

	WWW-GROUP should be the group which your web server process belongs to, e.g. *www-data*.


## Configuration

Open Event is pre-configured with the following:

### Content types

* **Event** - An event happening at a certain time and location, such as a concert, lecture, or festival. Repeated events may be structured as separate Event objects. Events can be linked to other events in a hierarchical structure, and also have Persons and Places associated to them (see Relation types below). Designed in accordance with the [schema.org Event type](https://schema.org/Event).
* **Person** - A person (alive, dead, undead, or fictional). Persons can be associated to Events. Designed in accordance with the [schema.org Person type](http://schema.org/Person).
* **Place** - A place has a fixed, physical extension. Places can be linked with other places in a hierarchical structure. Designed in accordance with the [schema.org Place type](https://schema.org/Place).
* **Organization** - Open Event content type for an organization, such as a school, NGO, corporation, club, etc. Designed in accordance with the [schema.org Organization type](https://schema.org/Organization).

### Taxonomies:

* **Person title** - Popular name titles are predefined.

### Relation types

* **Event is contained in Event**
* **Performer Performs in Event**
* **Event is located in Place**
* **Place is contained in Place**

### Roles
Open Event includes the same roles as a standard Drupal installation, and they provide the following access (more details in Permissions below):

* **Administrator** - full access to all permissions (as provided by the standard install profile)
* **Authenticated User** - access to edit all content types
* **Anonymous User** - access to view published content and JSON resources

### Permissions

#### Anonymous users

* Node - View published content
* RestWS - Access the resource node
* RestWS - Access the resource relation
* RestWS - Access the resource file
* Relation - View Relations

#### Authenticated users

* Better formats - Show format tips
* Contextual links - Use contextual links
* Filter - Use the Filtered HTML text format
* Filter - Use the Full HTML text format
* Node - Access the content overview page
* Node - View own unpublished content
* Node - View/Revert/Delete content revisions
* Node - Event: Create/Edit/Delete any content
* Node - Person: Create/Edit/Delete any content
* Node - Place: Create/Edit/Delete any content
* Node - Organization: Create/Edit/Delete any content
* System - View the administration theme
* Toolbar - Use the administration toolbar

*Please note: currently only the administrator role has access to create or edit taxonomies*

### Administration theme

* **Seven** - this theme is set for both the administration theme and the front end theme layer.



## Open Event API
Open Event by default exposes all it's content data as JSON via an API provided by the RestWS module. It is currently a Read-Only API. In the future, it may be extended to provide a Create Once Publish Everywhere experience out of the box.

The API allows you to use an independent web application as a front-end for the site or consume data from a mobile app.

The API is also self-documenting. It's documentation can be found at **/api/doc**.

Any new content types (node bundles) mapped to schema.org types and properties will be available as a JSON endpoint and will appear automatically in the API documentation.


## Testing
There are a full set of tests included with this distribution. Please refer to **TEST.md** for documentation.
@TODO implement unit tests in SimpleTest.




## Troubleshooting
* **Drupal 404 Page not found response for API resources**: This happens due to a fix with Drupal core that broke the capacity of RestWS to deliver API resources  [https://www.drupal.org/node/2484829](https://www.drupal.org/node/2484829).




# Entity Relationship Diagram
An entity relationship diagram can be found in [https://github.com/Southbank-Centre/OpenEvent/blob/master/openevent-ERD.png](openevent-ERD.png).




## Maintainers
Current maintainers:

* Jorge Lopez-Lago - [https://www.drupal.org/u/kurkuma](https://www.drupal.org/u/kurkuma)
* Alex Bridge - [https://www.drupal.org/u/alxbridge](https://www.drupal.org/u/alxbridge)
* Tassos Koutlas - [https://www.drupal.org/u/tassos](https://www.drupal.org/u/tassos)
* Dave Vernon - [https://www.drupal.org/u/djvern](https://www.drupal.org/u/djvern)
* Sam Murray - [https://www.drupal.org/u/samueljmurray](https://www.drupal.org/u/samueljmurray)
