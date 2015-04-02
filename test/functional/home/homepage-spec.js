'use strict';
/**
 * WOW Homepage Spec
 */

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('can create the WOW festival', function(){
    browser.get(browser.params.url + '/node/add/festival');

    // identify vertical tabs
    var dates = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Dates']"));
    var publishing = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

    // fill out content on main tab
    dvr.findElement(by.id('edit-title')).sendKeys('Women of the World Festival');
    dvr.findElement(by.id('edit-field-description-und-0-value')).sendKeys('Women of the World Festival description');

    // fill out content on dates tab
    dates.click();
    dvr.findElement(by.id('edit-field-date-start-und-0-value-datepicker-popup-0')).sendKeys('31/03/2016');
    dvr.findElement(by.id('edit-field-date-start-und-0-value-timeEntry-popup-1')).click();
    dvr.findElement(by.id('edit-field-date-start-und-0-value-timeEntry-popup-1')).sendKeys('10:00');
    dvr.findElement(by.id('edit-field-date-end-und-0-value-datepicker-popup-0')).sendKeys('30/04/2016');
    dvr.findElement(by.id('edit-field-date-end-und-0-value-timeEntry-popup-1')).click();
    dvr.findElement(by.id('edit-field-date-end-und-0-value-timeEntry-popup-1')).sendKeys('10:00');

    // set the item to published
    publishing.click();
    dvr.findElement(by.id('edit-status')).click();

    // submit the form
    dvr.findElement(by.id('edit-submit')).click();

    // check for the message indicating the item was created
    expect(dvr.findElement(by.id('content')).getText()).toContain('has been created');
  });


  it('can create the WOW festival homepage', function(){
    browser.get(browser.params.url + '/node/add/landing');

    // identify 'publishing' vertical tab
    var publishing = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

    // fill out content on main tab
    dvr.findElement(by.id('edit-title')).sendKeys('Women of the World Festival at Southbank Centre');
    dvr.findElement(by.xpath("//select[@id='edit-field-festival-und']/option[text()='Women of the World Festival']")).click();

    // set the item to published
    publishing.click();
    dvr.findElement(by.id('edit-status')).click();

    // submit the form
    dvr.findElement(by.id('edit-submit')).click();

    // check for the message indicating the item was created
    expect(dvr.findElement(by.id('content')).getText()).toContain('has been created');
  });

});
