# OPEN EVENT DISTRIBUTION
v1.0

## CONTENTS OF THIS FILE
   
 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Open Event API
 * Testing
 * Troubleshooting
 * FAQ
 * Maintainers



## Introduction
Open Event is a Drupal distribution that has been created by Southbank Centre for use by other arts and events organisations. It's been built with an open approach and with a open data architecture that will allow for collaboration and community activity. The data output maps to [Schema.org](http://schema.org) entities which allows for greater exposure and discovery across the wider internet.

This distribution serves as a starting point for an events-based Content Management System which you are free to build upon for your individual needs.

Equally this distribution is intended to evolve and this can be greatly helped by community support, so if you develop any additional functionality or modules that could benefit this Open Event platform please contact us or issue a pull request.



## Requirements
Open Event requires Drupal 7 and version 7.36 is packaged with this distribution. Detailed system requirements can be found here: [https://www.drupal.org/requirements](https://www.drupal.org/requirements) 
	
*Please note if you intend to use the API to access data (rather than a standard Drupal theme) then do not update to Drupal 7.37 until the following bug with RESTWS has been addressed: [https://www.drupal.org/node/2484829](https://www.drupal.org/node/2484829)*

### Modules
The following modules are required. They are packaged and automatically enabled with this  distribution:

* Address Field [https://www.drupal.org/project/addressfield](https://www.drupal.org/project/addressfield)
* Auto Entity Label [https://www.drupal.org/project/auto_entitylabel](https://www.drupal.org/project/auto_entitylabel)
* Better Formats [https://www.drupal.org/project/better_formats](https://www.drupal.org/project/better_formats)
* Ctools [https://www.drupal.org/project/ctools](https://www.drupal.org/project/ctools)
* Date [https://www.drupal.org/project/date](https://www.drupal.org/project/date)
* Entity [https://www.drupal.org/project/entity](https://www.drupal.org/project/entity)
* Entity Reference [https://www.drupal.org/project/entityreference](https://www.drupal.org/project/entityreference)
* Features [https://www.drupal.org/project/features](https://www.drupal.org/project/features)
* Field Group [https://www.drupal.org/project/field_group](https://www.drupal.org/project/field_group)
* Field Validation [https://www.drupal.org/project/field_validation](https://www.drupal.org/project/field_validation)
* FileField Sources [https://www.drupal.org/project/filefield_sources](https://www.drupal.org/project/filefield_sources)
* Geolocation Field [https://www.drupal.org/project/geolocation](https://www.drupal.org/project/geolocation)
* Link [https://www.drupal.org/project/link](https://www.drupal.org/project/link)
* Office Hours [https://www.drupal.org/project/office_hours](https://www.drupal.org/project/office_hours)
* <del>Paragraphs [https://www.drupal.org/project/paragraphs](https://www.drupal.org/project/paragraphs)</del> **NOT REQUIRED FOR OE??**
* Pathauto [https://www.drupal.org/project/pathauto](https://www.drupal.org/project/pathauto)
* Relation [https://www.drupal.org/project/relation](https://www.drupal.org/project/relation)
* Relation Add [https://www.drupal.org/project/relation_add](https://www.drupal.org/project/relation_add)
* RESTful Web Services [https://www.drupal.org/project/restws](https://www.drupal.org/project/restws)
* Strongarm [https://www.drupal.org/project/strongarm](https://www.drupal.org/project/strongarm)
* Table Element [https://www.drupal.org/project/table_element](https://www.drupal.org/project/table_element)
* Taxonomy Access Fix [https://www.drupal.org/project/taxonomy_access_fix](https://www.drupal.org/project/taxonomy_access_fix)
* Token [https://www.drupal.org/project/token](https://www.drupal.org/project/token)
* <del>Varnish [https://www.drupal.org/project/varnish](https://www.drupal.org/project/varnish)</del> **NOT REQUIRED FOR OE??**
* <del>View Unpublished [https://www.drupal.org/project/view_unpublished](https://www.drupal.org/project/view_unpublished)</del> **NOT REQUIRED FOR OE??**
* <del>Views [https://www.drupal.org/project/views](https://www.drupal.org/project/views)</del> **NOT REQUIRED FOR OE??**
* <del>Views Data Export [https://www.drupal.org/project/views_data_export](https://www.drupal.org/project/views_data_export)</del> **NOT REQUIRED FOR OE??**



## Installation

To set up a website using this distribution, do one of the following:

A. Download the distribution from [https://www.drupal.org/project/openevent](https://www.drupal.org/project/openevent) and follow the Drupal installation guide: [https://www.drupal.org/documentation/install](https://www.drupal.org/documentation/install), or;

B. Assuming you have Git and Drush installed run the following commands from a console/terminal window:

1. Clone the Open Event distribution branch from GitHub: 
 
		git clone -b 92518920_OE_split git@github.com:Southbank-Centre/southbankcentre.org-CMS.git DRUPAL-DIRECTORY/profiles/openevent
	
	Where DRUPAL DIRECTORY is the directory name of your site root.
 	
2. Change to the Drupal folder: 
		
		cd DRUPAL-DIRECTORY
		
3. Download Drupal core and Open Event modules and dependencies: 

		drush make local-openevent.make -y
    
4. Copy the Open Event Make file to the Drupal folder (where it needs to be run from):

		cp profiles/openevent/local-openevent.make .

5. Install Drupal to a MySQL database: 

		drush si openevent --account-name="USER" --account-pass="PASS" --db-url="mysql://DB-USER:DB-PASS@DB-HOST/DB-NAME"

	Where USER and PASS should be changed to your preferred Drupal login details for the Administrator account.
	DB-USER, DB-PASS, DB-HOST and DB-NAME should be changed to match your database settings. If the database specified doesn't exist it will be created. The ``--db-url`` parameter will add your database settings automatically to your sites/default/settings.php file. If you would prefer to define separate setting files for different environments (e.g. local.settings.php) then please omit the ``--db-url`` parameter from the command above and define your database settings manually.
	*Please note if an existing database exists it will be overwritten.*

6. Change the permissions of the files directory
		
		chmod 777 sites/default/files
		


## Configuration

Open Event is pre-configured with the following:

### Content types

* **Event** @TODO description 
* **Person** @TODO description
* **Place** @TODO description

### Taxonomies:

* **EventType** The following event types are pre-defined: @TODO to be confirmed next sprint!!  
* **Person title** Popular titles are predefined.

### Relation types

* **Event is contained in Event**
* **Performs in**
* **Event is located in Place**
* **Place is contained in Place**



## Open Event API
Open Event by default exposes all it's content data as JSON via an API. This is based upon the RESTWS module but has been extended to map to Schema.org entities. The benefits of using JSON data are so that you can be more flexible with how you use the data - front-end apps can be built independently of Drupal and you don't have to use the (soon to be end of life) Drupal 7 theme layer. Below is a list of available endpoints:

* List of events: **<root>/api/v1/events.json**
* Single event: **<root>/api/v1/events/12.json**
* Persons in an event: **<root>/api/v1/events/12/persons.json**
* Filtering: **<root>/api/v1/events.json?status=ready&place=london**
* Sorting: **<root>/api/v1/events.json?sort=startDate** 
* Searching **<root>/api/v1/events.json?q=wonderbra&offset=10&limit=20**
* Optional fields **<root>/api/v1/events.json?fields=title,performers,startDate**

More detailed documentation can be found on the API here: **<link to API docs>**


 
## Testing
There are a full set of tests included with this distribution. Please refer to **TEST.md** for documentation.

@TODO rewrite tests as SimpleTest



## Troubleshooting 
Optional section - should we include??



## FAQ
Optional section - should we include??



## Maintainers
Current maintainers:

* Jorge Lopez-Lago - [https://www.drupal.org/u/kurkuma](https://www.drupal.org/u/kurkuma)
* please add...

 
