'use strict';
/**
 * Organization Spec
 */

var url = require('url');
var path = require('path');
var eid;
var nid;

describe('The Organization features of the CMS', function() {

  // Page elements
  var pageTitle = element(by.css('.page-title'));
  var save = element(by.id('edit-submit'));
  var optionsPublished = element(by.id('edit-status'));
  var del = element(by.id('edit-delete'));
  var messages = element(by.css('.messages')); // How do we distinguish multiple messages?

  // Tab Main
  var tabMain = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']"));

  var name = element(by.id('edit-title'));
  var logo = element(by.id('edit-field-organization-logo-und-0-upload'));
  var logoUpload   = element(by.id('edit-field-organization-logo-und-0-upload-button'));
  var description = element(by.id('edit-field-description-und-0-value'));
  var legalName = element(by.id('edit-field-organization-legal-name-und-0-value'));

  // Tab Contact
  var tabContact = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Contact']"));

  var email = element(by.id('edit-field-organization-email-und-0-email'));
  var addressOrganisationName = element(by.id('edit-field-organization-address-und-0-organisation-name'));
  var addressThoroughfare = element(by.id('edit-field-organization-address-und-0-thoroughfare'));
  var addressPremise = element(by.id('edit-field-organization-address-und-0-premise'));
  var addressLocality = element(by.id('edit-field-organization-address-und-0-locality'));
  var addressAdministrativeArea = element(by.id('edit-field-organization-address-und-0-administrative-area'));
  var addressPostalCode = element(by.id('edit-field-organization-address-und-0-postal-code'));
  var addressCountry = element(by.id('edit-field-organization-address-und-0-country'));
  var sameAsTitle = element(by.id('edit-field-organization-same-as-und-0-title'));
  var sameAsUrl = element(by.id('edit-field-organization-same-as-und-0-url'));

  // Tab Images
  var tabImages = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Images']"));

  var image = element(by.id('edit-field-image-und-0-upload'));
  var imageUpload   = element(by.id('edit-field-image-und-0-upload-button'));

  // Tab Events
  var tabEvents = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Events']"));

  var eventRelation = element(by.id('edit-field-organization-events-und-0-relation-options-targets-target-2'));
  var eventRelationAdd = element(by.id('edit-field-organization-events-und-add-more'));

  // Other tabs
  var tabExtra = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Extra details']"));
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

  beforeEach(function(){
    isAngularSite(false);
  });


  it('can create, edit and delete an organization', function() {
    browser.get(browser.params.url + '/node/add/organization');
    expect(pageTitle.getText()).toContain('Create Organization');

    // Fill in organization details
    name.sendKeys('House of Stark');

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Organization House of Stark has been created.');

    // Check if it can edit the node.
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    // Modify name
    name.clear();
    name.sendKeys('House of Targaryen');
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Organization House of Targaryen has been updated.');

    // Delete the node (edit first, click delete and then confirm deletion)
    edit.click();
    del.click();
    save.click();
    expect(messages.getText()).toContain('Organization House of Targaryen has been deleted.');

  });

  it('can create a fully-featured organization', function() {
    browser.get(browser.params.url + '/node/add/organization');

    // name
    name.sendKeys('Lannister');

    // logo
    var fileToUpload = 'test-img.jpg';
    var absolutePath = path.resolve(__dirname, fileToUpload);
    // workaround for current inability to upload images through SauceLabs from Protractor:
    // provide the path of an image which should always exist on a SauceLabs instance
    if (browser.params.isSauceLabs) {
      absolutePath = '/home/chef/job_assets/shot_0.png';
    }
    logo.sendKeys(absolutePath);
    logoUpload.click();
    // wait until image has uploaded
    browser.wait(function() {
     return browser.isElementPresent($('#edit-field-organization-logo-und-0-alt'));
    }, 5000);

    $('#edit-field-organization-logo-und-0-alt').sendKeys('Test logo ALT');
    $('#edit-field-organization-logo-und-0-title').sendKeys('Test logo TITLE');

    // description
    description.sendKeys("House Lannister of Casterly Rock is one of the Great Houses of Westeros, one of its richest and most powerful families and oldest dynasties. The major characters Jaime, Cersei, and Tyrion and the recurring characters Tywin, Kevan, and Lancel are members of the house. Tywin is the head of House Lannister and Lord of Casterly Rock.");

    // legal name
    legalName.sendKeys('some thing off some TV show or something');

    // contact
    browser.executeScript('window.scrollTo(0,0);').then(function () {
      
      tabContact.click();

      // email
      // Test email with invalid email address
      email.sendKeys("tywinrulezok$lannister.gov.rk");
      save.click();
      expect(messages.getText()).toContain('"tywinrulezok$lannister.gov.rk" is not a valid email address');

      // Add valid email address
      email.clear();
      email.sendKeys("tywinrulezok@lannister.gov.rk");

      // address
      // select country
      element(by.cssContainingText('#edit-field-organization-address-und-0-country > option', 'United Kingdom')).click();
      browser.wait(function () {
          return browser.isElementPresent(by.id('edit-field-organization-address-und-0-thoroughfare'));
      }, 5000);
      addressOrganisationName.sendKeys('Lannister HQ');
      addressThoroughfare.sendKeys('Southbank Centre');
      addressPremise.sendKeys('Belvedere Road');
      addressLocality.sendKeys('London');
      addressAdministrativeArea.sendKeys('London (county)');
      addressPostalCode.sendKeys('SE1 8XX');

      // same as
      sameAsTitle.sendKeys('Lannister Wiki Page');
      sameAsUrl.sendKeys('http://gameofthrones.wikia.com/wiki/House_Lannister');

    });

    // images
    browser.executeScript('window.scrollTo(0,0);').then(function () {

      tabImages.click();

      // image
      var fileToUpload = 'test-img.jpg';
      var absolutePath = path.resolve(__dirname, fileToUpload);
      // workaround for current inability to upload images through SauceLabs from Protractor:
      // provide the path of an image which should always exist on a SauceLabs instance
      if (browser.params.isSauceLabs) {
        absolutePath = '/home/chef/job_assets/shot_0.png';
      }
      image.sendKeys(absolutePath);
      imageUpload.click();
      // wait until image has uploaded
      browser.wait(function() {
       return browser.isElementPresent($('#edit-field-image-und-0-alt'));
      }, 5000);

      $('#edit-field-image-und-0-alt').sendKeys('Test image ALT');
      $('#edit-field-image-und-0-title').sendKeys('Test image TITLE');

      // Publish it
      tabOptions.click();
      optionsPublished.isSelected().then(function(selected) {
        if (!selected) {
          optionsPublished.click();
        }
      });

      save.click();

      // Get the nid for the next test
      var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
      edit.click();

      browser.getCurrentUrl().then(function(Url){
        var parts = Url.split('/');
        var size = parts.length;
        nid = parts[size-2];
      });


    });

  });

  // it('sets relationship to Event', function() {
  //   // Organization
  //   var orgName = 'Lannister';

  //   // Add event
  //   var eventName = 'Expunge (Targaryen)';
  //   addEvent(eventName);

  //   // Add organization
  //   browser.get(browser.params.url + '/node/add/organization');
  //   expect(pageTitle.getText()).toContain('Create Organization');
  //   name.sendKeys(orgName);

  //   // Add a relation between organzation and event
  //   var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
  //   tabEvents.click();
  //   eventRelation.sendKeys(eventName);
  //   browser.wait(function() {
  //     return browser.isElementPresent(by.css('#autocomplete li div'));
  //   }, 5000);
  //   autocomplete.click();

  //   // Publish it
  //   tabOptions.click();
  //   optionsPublished.isSelected().then(function(selected) {
  //     if (!selected) {
  //       optionsPublished.click();
  //     }
  //   });

  //   // Save the node
  //   save.click();

  //   // Expectations
  //   expect(messages.getText()).toContain(orgName + ' has been created.');

  //   // Get the nid for the next test
  //   var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
  //   edit.click();

  //   browser.getCurrentUrl().then(function(Url){
  //     var parts = Url.split('/');
  //     var size = parts.length;
  //     nid = parts[size-2];
  //   });

  // });

  it('outputs JSON to the specified format', function() {

    frisby.create('Get JSON for Event page created in previous test')
      .get(browser.params.url + '/node/' + nid + '.json')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      // .inspectJSON() // uncomment to output JSON in console
      .expectJSON({
        "field_description": {
          "value": "<p>House Lannister of Casterly Rock is one of the Great Houses of Westeros, one of its richest and most powerful families and oldest dynasties. The major characters Jaime, Cersei, and Tyrion and the recurring characters Tywin, Kevan, and Lancel are members of the house. Tywin is the head of House Lannister and Lord of Casterly Rock.</p>\n",
          "format": "filtered_html"
        },
        "field_image": [
          {
            "file": {
              "uri": function(val) {
                expect(val).toContain(browser.params.url + "/file/");
              },
              "id": function(val) {
                expect(val).toBeDefined();
                expect(isNaN(parseInt(val, 10))).toBe(false);
              },
              "resource": "file"
            },
            "alt": "Test image ALT",
            "title": "Test image TITLE"
          }
        ],
        "field_organization_logo": {
          "file": {
            "uri": function(val) {
              expect(val).toContain(browser.params.url + "/file/");
            },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "file"
          },
          "alt": "Test logo ALT",
          "title": "Test logo TITLE"
        },
        "title": "Lannister",
        "field_organization_legal_name": "some thing off some TV show or something",
        "field_organization_email": "tywinrulezok@lannister.gov.rk",
        "field_organization_same_as": [
          { 
            "title": 'Lannister Wiki Page',
            "url": 'http://gameofthrones.wikia.com/wiki/House_Lannister'
          }
        ],
        "field_organization_address": {
          "country": "GB",
          "organisation_name": "Lannister HQ",
          "administrative_area": "London (county)",
          "locality": "London",
          "postal_code": "SE1 8XX",
          "thoroughfare": "Southbank Centre",
          "premise": "Belvedere Road"
        },
        "nid": nid,
        "vid": nid
        // "relation_performer_performs_in_event_node_reverse": [
        //   {
        //     "uri": browser.params.url + "/node/" + nid,
        //     "id": nid,
        //     "resource": "node"
        //   },
        //   {
        //     "uri": browser.params.url + "/node/" + eid,
        //     "id": eid,
        //     "resource": "node"
        //   }
        // ],
        // "relation_performer_performs_in_event_node": [
        //   {
        //     "uri": browser.params.url + "/node/" + nid,
        //     "id": nid,
        //     "resource": "node"
        //   },
        //   {
        //     "uri": browser.params.url + "/node/" + eid,
        //     "id": eid,
        //     "resource": "node"
        //   }
        // ]
      })
    .after(cleanUp)
    .toss();

    // We run cleanUp after the last frisby test because they are asynchronous
    // and could run after the cleanUp otherwise (this is something to improve on)
    function cleanUp () {
      // These tests are destructive and can only be performed on clean/empty sites [!]
      // This cleanup function assumes that all content available is created by this test suite

      // CleanUp content
      // It deletes ALL content in the site
      browser.get(browser.params.url + '/admin/content');
      element(by.css('#node-admin-content > div > table.sticky-enabled.table-select-processed.tableheader-processed.sticky-table > thead > tr > th.select-all > input')).click();
      element(by.cssContainingText('#edit-operation > option', 'Delete selected content')).click();
      element(by.id('edit-submit--2')).click();
      element(by.id('edit-submit')).click();
      //expect(element(by.css('#node-admin-content > div > table:nth-of-type(2) > tbody > tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No content available.');

    }
  });

});

function addEvent(eventName) {

  // Create a supporting event
  browser.get(browser.params.url + '/node/add/event');
  expect(element(by.css('.page-title')).getText()).toContain('Create Event');

  element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
  element(by.id('edit-title')).sendKeys(eventName);

  // Date and time
  element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

  // start date/time
  element(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
  element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
  element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

  // duration
  element(by.id('edit-field-event-duration-und-0-value')).clear();

  // Publish it
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));
  var optionsPublished = element(by.id('edit-status'));
  tabOptions.click();
  optionsPublished.isSelected().then(function(selected) {
    if (!selected) {
      optionsPublished.click();
    }
  });

  // save
  element(by.id('edit-submit')).click();

  // test successful save
  expect(element(by.id('console')).getText()).toContain('Event '+ eventName + ' has been created.');

  // Get the nid for the next test.
  var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
  edit.click();

  browser.getCurrentUrl().then(function(Url){
    var parts = Url.split('/');
    var size = parts.length;
    eid = parts[size-2];
  });

}
