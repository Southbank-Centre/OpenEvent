'use strict';
/**
 * Person Spec
 */

var url = require('url');
var path = require('path');

describe('The Person features of the CMS', function() {

  // Permissions
  var permViewPublishedContentAnon = element(by.id('edit-1-access-content'));
  var permViewPublishedContentAuth = element(by.id('edit-2-access-content'));
  var permAccessResourceNodeAnon = element(by.id('edit-1-access-resource-node'));
  var permAccessResourceNodeAuth = element(by.id('edit-2-access-resource-node'));

  // Page elements
  var pageTitle = element(by.css('.page-title'));
  var save = element(by.id('edit-submit'));
  var messages = element(by.css('.messages'));

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

  // Tab Extra details
  var tabExtra = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Extra details']"));

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

  it('allows persons to be views by anyone', function(){
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

    // Save permissions
    save.click();
  });

  it('can create a person', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personGivenName.sendKeys('Jon');
    personFamilyName.sendKeys('Snow');
    personNameSuffix.sendKeys('Commander');
    personAlias.sendKeys('Ned Stark\'s bastard son');

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person Jon Snow has been created.');

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

  });

  it('set relationship to Event', function() {

    // Person
    var name = 'Daenerys';
    var surname = 'Targaryen';

    // Add event
    var eventName = 'Get to Kings Landing';
    addEvent(eventName);

    // Add person
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');
    personGivenName.sendKeys(name);
    personFamilyName.sendKeys(surname);

    // Add a relation betweeb person and event
    var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
    tabEvents.click();
    eventRelation.sendKeys(eventName);
    browser.wait(function() {
      return browser.isElementPresent(autocomplete);
    }, 5000);
    autocomplete.click();

    // Save the node
    // Needs to be done twice to get focus first and then actually click.
    save.click();
    save.click();

    browser.wait(function() {
      return browser.isElementPresent(messages);
    }, 5000);

    // Expectations
    expect(messages.getText()).toContain(name + ' ' + surname + ' has been created.');


  });

  // it('set relationship to Event', function() {})
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
  dvr.findElement(by.id('edit-field-event-date-time-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
  dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).click();
  dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

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

  // save
  dvr.findElement(by.id('edit-submit')).click();

  // test successful save
  expect(element(by.id('console')).getText()).toContain('Event '+ eventName + ' has been created.');
}
