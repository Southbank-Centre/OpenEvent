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

});
