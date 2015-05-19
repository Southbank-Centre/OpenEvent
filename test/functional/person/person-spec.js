'use strict';
/**
 * Person Spec
 */

var url = require('url');
var path = require('path');
var eid;
var nid;

describe('The Person features of the CMS', function() {

  // Permissions
  var permViewPublishedContentAnon = element(by.id('edit-1-access-content'));
  var permViewPublishedContentAuth = element(by.id('edit-2-access-content'));
  var permAccessResourceNodeAnon = element(by.id('edit-1-access-resource-node'));
  var permAccessResourceNodeAuth = element(by.id('edit-2-access-resource-node'));
  var permViewRelationsAnon = element(by.id('edit-1-access-relations'));
  var permViewRelationsAuth = element(by.id('edit-2-access-relations'));

  // Page elements
  var pageTitle = element(by.css('.page-title'));
  var save = element(by.id('edit-submit'));
  var optionsPublished = element(by.id('edit-status'));
  var del = element(by.id('edit-delete'));
  var messages = element(by.css('.messages')); // How do we distinguish multiple messages?

  // Tab Main
  var tabMain = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']"));

  // Main fields
  // @TODO add a rand to get one of these
  var personNamePrefix = element(by.id('edit-field-person-name-prefix-und'));
  var personGivenName = element(by.id('edit-field-person-name-given-und-0-value'));
  var personMiddleName = element(by.id('edit-field-person-name-middle-und-0-value'));
  var personFamilyName = element(by.id('edit-field-person-name-family-und-0-value'));
  var personNameSuffix = element(by.id('edit-field-person-name-suffix-und-0-value'));
  var personAlias = element(by.id('edit-field-person-name-alias-und-0-value'));

  // Tab Biography and images
  var tabBio = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Biography and images']"));

  // Biography and images fields
  var bioDescription = element(by.id('edit-field-description-und-0-value'));
  var bioImage = element(by.id('edit-field-image-und-0-upload'));
  var bioImageUpload   = element(by.id('edit-field-image-und-0-upload-button'));

  // Other tabs
  var tabExtra = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Extra details']"));
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

  // Extra details fields
  var extraJobTitle = element(by.id('edit-field-person-job-und-0-value'));
  var extraAwards = element(by.id('edit-field-person-awards-und-0-value'));
  var extraAwardsAdd = element(by.id('edit-field-person-awards-und-add-more'));
  var extraLinkTitle = element(by.id('edit-field-person-urls-und-0-title'));
  var extraLinkUrl = element(by.id('edit-field-person-urls-und-0-url'));
  var extraLinkAdd = element(by.id('edit-field-person-urls-und-add-more'));

  // Tab Events
  var tabEvents = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Events']"));

  // Event fields
  var eventRelation = element(by.id('edit-field-person-events-und-0-relation-options-targets-target-2'));
  var eventRelationAdd = element(by.id('edit-field-person-events-und-add-more'));


	beforeEach(function(){
    isAngularSite(false);
  });

  it('allows persons to be viewed by anyone', function(){
    browser.get(browser.params.url + '/admin/people/permissions');
    expect(pageTitle.getText()).toContain('People');

    // Allow published content to be viewed by anyone
    permViewPublishedContentAnon.isSelected().then(function(selected) {
      if (!selected) {
        permViewPublishedContentAnon.click();
      }
    });

    permViewPublishedContentAuth.isSelected().then(function(selected) {
      if (!selected) {
        permViewPublishedContentAuth.click();
      }
    });

    // Allow node API endpoints to be viewed by anyone
    permAccessResourceNodeAnon.isSelected().then(function(selected) {
      if (!selected) {
        permAccessResourceNodeAnon.click();
      }
    });

    permAccessResourceNodeAuth.isSelected().then(function(selected) {
      if (!selected) {
        permAccessResourceNodeAuth.click();
      }
    });

    // Allow relations to be viewed by anyone
    permViewRelationsAnon.isSelected().then(function(selected) {
      if (!selected) {
        permViewRelationsAnon.click();
      }
    });

    permViewRelationsAuth.isSelected().then(function(selected) {
      if (!selected) {
        permViewRelationsAuth.click();
      }
    });

    // Save permissions
    save.click();
  });

  it('can create, edit and delete a person', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personGivenName.sendKeys('Jon');
    personFamilyName.sendKeys('Snow');
    personNameSuffix.sendKeys('Commander');
    personAlias.sendKeys('Lord Commander of the night\'s watch');

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person Jon Snow has been created.');

    // Check if it can edit the node.
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    // Clear the contents of Alias field.
    personNameSuffix.clear();
    save.click();

    // The fields that were deleted.
    var aliasFieldLabel = element(by.css('.field-name-field-person-name-alias field-label'));
    var aliasFieldItem = element(by.css('field-name-field-person-name-alias field-items'));

    // Expect deleted fields not to be there.
    expect(aliasFieldLabel.isPresent()).not.toBe(true);
    expect(aliasFieldItem.isPresent()).not.toBe(true);

    // Delete the node (edit first, click delete and then confirm deletion)
    edit.click();
    del.click();
    save.click();
    expect(messages.getText()).toContain('Person Jon Snow has been deleted.');

  });

  // What are invalid fields? The fields are limited in length and will not accept longer strings.
  it('can not save person with invalid fields', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personGivenName.sendKeys('Tyrion');
    personFamilyName.sendKeys('Lannister');

    // Test link without URL
    tabExtra.click();
    extraLinkTitle.sendKeys('Tywin');
    save.click();
    expect(messages.getText()).toContain('You cannot enter a title without a link url.');

    // Test link with malformed URL
    tabExtra.click();
    var wrongUrl = [
      'htt://en.wikipedia.org/wiki/Tyrion_Lannister',
      'http:/en.wikipedia.org/wiki/Tyrion_Lannister',
      // Check bug #94383178 on Pivotal Tracker
      // 'http//en.wikipedia.org/wiki/Tyrion_Lannister',
      'http://en.wikipedia/wiki/Tyrion_Lannister'
    ];
    extraLinkTitle.sendKeys('Wikipedia (wrong)');
    var i = 0;
    while (wrongUrl[i]) {
      extraLinkUrl.clear();
      extraLinkUrl.sendKeys(wrongUrl[i]);
      save.click();
      expect(messages.getText()).toContain('The value ' + wrongUrl[i] + ' provided for Person urls is not a valid URL.');
      i++;
    }

    // Add good URL
    extraLinkTitle.clear();
    extraLinkTitle.sendKeys('Wikipedia');
    extraLinkUrl.clear();
    extraLinkUrl.sendKeys('http://en.wikipedia.org/wiki/Tyrion_Lannister');

    // Publish it
    tabOptions.click();
    optionsPublished.isSelected().then(function(selected) {
      if (!selected) {
        optionsPublished.click();
      }
    });

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person Tyrion Lannister has been created.');

  });

  it('sets relationship to Event', function() {
    // Person
    var name = 'Daenerys';
    var surname = 'Targaryen';

    // Get timestamp.
    var time = new Date().getTime();

    // Add event
    var eventName = 'Get to Kings Landing (' + time + ')';
    addEvent(eventName);

    // Add person
    dvr.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');
    personGivenName.sendKeys(name);
    personFamilyName.sendKeys(surname);

    // Add a relation between person and event
    var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
    tabEvents.click();
    eventRelation.sendKeys(eventName);
    dvr.wait(function() {
      return dvr.isElementPresent(by.css('#autocomplete li div'));
    }, 5000);
    autocomplete.click();

    // Publish it
    tabOptions.click();
    optionsPublished.isSelected().then(function(selected) {
      if (!selected) {
        optionsPublished.click();
      }
    });

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain(name + ' ' + surname + ' has been created.');

    // Get the nid for the next test
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    browser.getCurrentUrl().then(function(Url){
      var parts = Url.split('/');
      var size = parts.length;
      nid = parts[size-2];
    });

  });

  it('outputs JSON to the specified format', function() {
    frisby.create('Get JSON for Event page created in previous test')
      .get(browser.params.url + '/node/' + nid + '.json')
        .expectStatus(200)
        .expectHeaderContains('content-type', 'application/json')
        .expectJSON({
          "field_description": [],
          "field_image": [],
          "field_person_awards": [],
          "field_person_job": function(val) { expect(val).toBe(null); },
          "field_person_name_alias": function(val) { expect(val).toBe(null); },
          "field_person_name_family": "Targaryen",
          "field_person_name_given": "Daenerys",
          "field_person_name_middle": function(val) { expect(val).toBe(null); },
          "field_person_name_suffix": function(val) { expect(val).toBe(null); },
          "field_person_urls": [],
          "nid": nid,
          "vid": nid,
          "relation_performs_in_node_reverse": [
            {
              "uri": browser.params.url + "/node/" + nid,
              "id": nid,
              "resource": "node"
            },
            {
              "uri": browser.params.url + "/node/" + eid,
              "id": eid,
              "resource": "node"
            }
          ],
          "relation_performs_in_node": [
            {
              "uri": browser.params.url + "/node/" + nid,
              "id": nid,
              "resource": "node"
            },
            {
              "uri": browser.params.url + "/node/" + eid,
              "id": eid,
              "resource": "node"
            }
          ]
        })
      .after(cleanUp)
      .toss();

    // We run cleanUp after the last frisby test because they are asynchronous
    // and could run after the cleanUp otherwise (this is something to improve on)
    function cleanUp () {
      // These tests are destructive and can only be performed on clean/empty sites [!]
      // This cleanup function assumes that all content available is created by this test suite

      // CleanUp taxonomy terms
      // It assumes there is only ONE term created for the tests
      browser.get(browser.params.url + '/admin/structure/taxonomy/event_class');
      dvr.findElement(by.linkText('Test event class')).click();
      element(by.xpath("//ul[@class='tabs primary']/li[2]")).click(); // Assumes no more tabs are present
      //dvr.findElement(by.linkText('Edit')).click();
      dvr.findElement(by.id('edit-delete')).click();
      dvr.findElement(by.id('edit-submit')).click();

      // CleanUp content
      // It deletes ALL content in the site
      browser.get(browser.params.url + '/admin/content');
      dvr.findElement(by.css('#node-admin-content > div > table.sticky-enabled.table-select-processed.tableheader-processed.sticky-table > thead > tr > th.select-all > input')).click();
      element(by.cssContainingText('#edit-operation > option', 'Delete selected content')).click();
      element(by.id('edit-submit--2')).click();
      element(by.id('edit-submit')).click();
      //expect(dvr.findElement(by.css('#node-admin-content > div > table:nth-of-type(2) > tbody > tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No content available.');

      // CleanUp permissions
      browser.get(browser.params.url + '/admin/people/permissions');

      permViewPublishedContentAnon.isSelected().then(function(selected) {
        if (selected) {
          permViewPublishedContentAnon.click();
        }
      });

      permViewPublishedContentAuth.isSelected().then(function(selected) {
        if (selected) {
          permViewPublishedContentAuth.click();
        }
      });

      permAccessResourceNodeAnon.isSelected().then(function(selected) {
        if (selected) {
          permAccessResourceNodeAnon.click();
        }
      });

      permAccessResourceNodeAuth.isSelected().then(function(selected) {
        if (selected) {
          permAccessResourceNodeAuth.click();
        }
      });

      permViewRelationsAnon.isSelected().then(function(selected) {
        if (selected) {
          permViewRelationsAnon.click();
        }
      });

      permViewRelationsAuth.isSelected().then(function(selected) {
        if (selected) {
          permViewRelationsAuth.click();
        }
      });

      save.click();
    }
  });

});

function addEvent(eventName) {

  // Create class supporting term
  browser.get(browser.params.url + '/admin/structure/taxonomy/event_class/add');
  expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
  dvr.findElement(by.id('edit-name')).sendKeys('Test event class');
  dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class description');
  dvr.findElement(by.id('edit-submit')).click();

  // Create a supporting event
  browser.get(browser.params.url + '/node/add/event');
  expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Event');

  dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
  dvr.findElement(by.id('edit-title')).sendKeys(eventName);

  // Date and time
  dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

  // start date/time
  dvr.findElement(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
  dvr.findElement(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
  dvr.findElement(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

  // end date/time
  dvr.findElement(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
  dvr.findElement(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
  dvr.findElement(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

  // duration
  dvr.findElement(by.id('edit-field-event-duration-und-0-value')).clear();

  // Change to
  element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Details']")).click()

  browser.wait(function() {
    return browser.isElementPresent(element(by.xpath("//div[@id='edit-field-event-class-und']/div[1]/label")));
  }, 5000);
  // class
  expect(element(by.xpath("//div[@id='edit-field-event-class-und']/div[1]/label")).getText()).toContain('Test event class');
  element(by.xpath("//div[@id='edit-field-event-class-und']/div[1]/label")).click();

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
  dvr.findElement(by.id('edit-submit')).click();

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
