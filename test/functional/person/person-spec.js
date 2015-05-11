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
    permViewPublishedContentAnon.click();
    permViewPublishedContentAuth.click();

    // Allow node API endpoints to be viewed by anyone
    permAccessResourceNodeAnon.click();
    permAccessResourceNodeAuth.click();

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




  });

  // it('can edit an existing person', function() {})

  // it('can delete an existing person', function() {})

  // it('can publish an unpublished person', function() {})

  // it('can not save person without all required fields', function() {})

  // it('can not save person with invalid fields', function() {})

  // it('get JSON', function() {})

  // it('set relationship to Event', function() {})
});
