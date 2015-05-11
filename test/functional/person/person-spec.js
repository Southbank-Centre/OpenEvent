'use strict';
/**
 * Person Spec
 */

var url = require('url');
var path = require('path');

describe('The Person features of the CMS', function() {

	beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('is alive', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(element(by.css('.page-title')).getText()).toContain('Create Person');
  });

  // it('allows persons to be views by anyone')

  // it('can create a person', function() {})

  // it('can edit an existing person', function() {})

  // it('can delete an existing person', function() {})

  // it('can publish an unpublished person', function() {})

  // it('can not save person without all required fields', function() {})

  // it('can not save person with invalid fields', function() {})

  // it('get JSON', function() {})

  // it('set relationship to Event', function() {})
});
