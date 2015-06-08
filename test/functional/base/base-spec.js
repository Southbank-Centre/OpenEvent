'use strict';
/**
 * OE Base Spec
 */

describe('OE CMS', function() {

  beforeEach(function(){
    isAngularSite(false);
  });

  it('has been logged into successfully', function(){
    browser.get(browser.params.url + '/');

    // check for the user toolbar
    expect(element(by.id('toolbar-user')).isPresent()).toBe(true);
  });

  it('has a working API endpoint for event', function () {
    // get Event JSON from API and parse it
    browser.get(browser.params.url + '/api/event.json');
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      expect(json.self).toBeDefined();
      expect(json.first).toBeDefined();
      expect(json.last).toBeDefined();
      expect(json.list).toBeDefined();
    });
  });

  it('has a working API endpoint for person', function () {
    // get Person JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json');
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      expect(json.self).toBeDefined();
      expect(json.first).toBeDefined();
      expect(json.last).toBeDefined();
      expect(json.list).toBeDefined();
    });
  });

  it('has a working API endpoint for place', function () {
    // get Place JSON from API and parse it
    browser.get(browser.params.url + '/api/place.json');
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      expect(json.self).toBeDefined();
      expect(json.first).toBeDefined();
      expect(json.last).toBeDefined();
      expect(json.list).toBeDefined();
    });
  });

});
