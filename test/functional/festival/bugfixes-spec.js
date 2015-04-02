'use strict';
/**
 * WOW Homepage Spec
 */

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('doesn\'t have the Social Twitter field (https://www.pivotaltracker.com/story/show/91023354)', function(){
    browser.get(browser.params.url + '/node/add/festival');
    expect(element(by.xpath('//div[@id="edit-field-social-twitter"]//input')).isPresent()).toBe(false);
  });

});
