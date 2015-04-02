'use strict';
/**
 * WOW Homepage Spec
 */

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('can create a content page', function(){
    browser.get(browser.params.url + '/node/add/content-page');

    // identify vertical tabs
    var publishing = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

    // fill out content on main tab
    dvr.findElement(by.id('edit-title')).sendKeys('Protractor test content page');

    // set the item to published
    publishing.click();
    dvr.findElement(by.id('edit-status')).click();

    // submit the form
    dvr.findElement(by.id('edit-submit')).click();

    // check for the message indicating the item was created
    expect(dvr.findElement(by.id('content')).getText()).toContain('has been created');
  });

});
