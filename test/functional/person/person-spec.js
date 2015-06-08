'use strict';
/**
 * Person Spec
 */

var url = require('url');
var path = require('path');
var eid;
var nid;

describe('The Person features of the CMS', function() {

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
  var personDescription = element(by.id('edit-field-description-und-0-value'));
  var personEmail = element(by.id('edit-field-person-email-und-0-email'));

  // Tab Images
  var tabImages = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Images']"));
  var bioImage = element(by.id('edit-field-image-und-0-upload'));
  var bioImageUpload   = element(by.id('edit-field-image-und-0-upload-button'));

  // Other tabs
  var tabExtra = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Extra details']"));
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

  // Extra details fields
  var extraJobTitle = element(by.id('edit-field-person-job-und-0-value'));
  var extraAwards = element(by.id('edit-field-person-awards-und-0-value'));
  var extraAwardsAdd = element(by.id('edit-field-person-awards-und-add-more'));
  var extraLinkTitle = element(by.id('edit-field-person-same-as-und-0-title'));
  var extraLinkUrl = element(by.id('edit-field-person-same-as-und-0-url'));
  var extraLinkAdd = element(by.id('edit-field-person-same-as-und-add-more'));

  // Tab Events
  var tabEvents = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Events']"));

  // Event fields
  var eventRelation = element(by.id('edit-field-person-events-und-0-relation-options-targets-target-2'));
  var eventRelationAdd = element(by.id('edit-field-person-events-und-add-more'));

	beforeEach(function(){
    isAngularSite(false);
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

    browser.executeScript('window.scrollTo(0,0);').then(function () {

      // Test link without URL
      tabExtra.click();
      extraLinkTitle.sendKeys('Tywin');
      save.click();
      expect(messages.getText()).toContain('You cannot enter a title without a link url.');

      // Test link with malformed URL
      var wrongUrl = [
        'htt://en.wikipedia.org/wiki/Tyrion_Lannister',
        'http:/en.wikipedia.org/wiki/Tyrion_Lannister',
        'http//en.wikipedia.org/wiki/Tyrion_Lannister',
        'http://en.wikipedia/wiki/Tyrion_Lannister'
      ];
      extraLinkTitle.sendKeys('Wikipedia (wrong)');
      var i = 0;
      while (wrongUrl[i]) {
        extraLinkUrl.clear();
        extraLinkUrl.sendKeys(wrongUrl[i]);
        save.click();
        expect(messages.getText()).toContain('The value ' + wrongUrl[i] + ' provided for Person links is not a valid URL.');
        i++;
      }

      // Add good URL
      extraLinkTitle.clear();
      extraLinkTitle.sendKeys('Wikipedia');
      extraLinkUrl.clear();
      extraLinkUrl.sendKeys('http://en.wikipedia.org/wiki/Tyrion_Lannister');

    });

    browser.executeScript('window.scrollTo(0,0);').then(function () {

      // Publish it
      tabOptions.click();
      optionsPublished.isSelected().then(function(selected) {
        if (!selected) {
          optionsPublished.click();
        }
      });

      // Save the node
      save.click();

    });

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
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');
    personGivenName.sendKeys(name);
    personFamilyName.sendKeys(surname);

    browser.executeScript('window.scrollTo(0,0);').then(function () {

      tabExtra.click();
      personEmail.sendKeys("tywinrulezok@lannister.gov.rk");

      // Add a relation between person and event
      var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
      tabEvents.click();
      eventRelation.sendKeys(eventName);
      browser.wait(function() {
        return browser.isElementPresent(by.css('#autocomplete li div'));
      }, 5000);
      autocomplete.click();

      // Publish it
      tabOptions.click();
      optionsPublished.isSelected().then(function(selected) {
        if (!selected) {
          optionsPublished.click();
        }
      });

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
          "field_person_same_as": [],
          "field_person_email": "tywinrulezok@lannister.gov.rk",
          "nid": nid,
          "vid": nid,
          "relation_performer_performs_in_event_node_reverse": [
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
          "relation_performer_performs_in_event_node": [
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

  // end date/time
  element(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
  element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
  element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

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
