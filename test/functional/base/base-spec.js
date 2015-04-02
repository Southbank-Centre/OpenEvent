'use strict';
/**
 * WOW Homepage Spec
 */

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('has been logged into successfully', function(){
    browser.get(browser.params.url + '/');

    // check for the user toolbar
    expect($('#toolbar-user').isPresent()).toBe(true);
  });

});
