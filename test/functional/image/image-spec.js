'use strict';
/**
 * OE Components Spec
 */

var url = require('url');
var path = require('path');

describe('Image', function() {

  var parentNid;
  var parentPathAlias;
  var nid;
  var pathAlias;

  // Page elements
  var optionsPublished = element(by.id('edit-status'));

  // Other tabs
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

  beforeEach(function(){
    isAngularSite(false);
  });

  it('can be added to an Event page', function(){
    var deferment = protractor.promise.defer();

    // Create minimal Event page

    browser.get(browser.params.url + '/node/add/event');

    // fill out content on 'Main' tab
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    element(by.id('edit-title')).sendKeys('Test event page');

    // upload 'Image'
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Images']")).click();
    var fileToUpload = 'test-img.jpg';
    var absolutePath = path.resolve(__dirname, fileToUpload);

    // workaround for current inability to upload images through SauceLabs from Protractor:
    // provide the path of an image which should always exist on a SauceLabs instance
    if (browser.params.isSauceLabs) {
      absolutePath = '/home/chef/job_assets/shot_0.png';
    }

    element(by.id('edit-field-image-und-0-upload')).sendKeys(absolutePath);
    element(by.id('edit-field-image-und-0-upload-button')).click();

    // wait until image has uploaded
    browser.wait(function() {
     return browser.isElementPresent($('#edit-field-image-und-0-alt'));
    }, 5000);

    $('#edit-field-image-und-0-alt').sendKeys('Test image ALT');
    $('#edit-field-image-und-0-title').sendKeys('Test image TITLE');

    // fill out content on 'Date and time' tab
    browser.executeScript('window.scrollTo(0,0);').then(function () {

      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

      // start date/time
      element(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
      dvr.findElement(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

      // end date/time
      element(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
      element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
      element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

      // duration
      element(by.id('edit-field-event-duration-und-0-value')).clear();


      // set the item to published
      tabOptions.click();
      optionsPublished.isSelected().then(function(selected) {
        if (!selected) {
          optionsPublished.click();
        }
      });

      // submit
      element(by.id('edit-submit')).click();

      // test uploaded image exists
      expect($('.field-name-field-image img').isPresent()).toBe(true);
      expect($('.field-name-field-image img').getAttribute('alt')).toEqual('Test image ALT');
      expect($('.field-name-field-image img').getAttribute('title')).toEqual('Test image TITLE');


      // go back to edit page
      element(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();

      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
      element(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

        pathAlias = alias;

        // store node ID of event just created
        browser.getCurrentUrl().then(function(currentUrl) {
          var currentUrlObj = url.parse(currentUrl);
          var currentUrlPath = currentUrlObj.pathname.split(path.sep);
          nid = currentUrlPath[currentUrlPath.length-2];
          deferment.fulfill('ok');
        });

      });

    });

    expect(deferment).toBe('ok');

  });

  /* API output tests */

  it('outputs the Image data with the Event node JSON in Schema.org format', function () {
    // set correct filename for checking image upload
    var imageName = 'test-img.jpg';
    if (browser.params.isSauceLabs) {
      imageName = 'shot_0.png';
    }

    // get Event JSON from API and parse it for the image field
    browser.get(browser.params.url + '/api/event/' + nid + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);

       // image uploaded & fields filled out as expected
       expect(json.image[0].contentUrl).toContain(browser.params.url);
       expect(json.image[0].contentUrl).toContain(imageName.split(".")[0]);
       expect(json.image[0].alternateName).toBe("Test image ALT");
       expect(json.image[0].caption).toBe("Test image TITLE");
    });
  });

  /* End of API output tests */


  /* API input tests */

  /* End of API input tests */

  it('will take place after all tests have passed', function() {

    // CLEAN UP
    // remove content
    browser.get(browser.params.url + '/admin/content');
    element(by.css('#node-admin-content > div > table:nth-of-type(2) > thead:first-of-type > tr:first-of-type > th:first-of-type input')).click();
    element(by.cssContainingText('#edit-operation > option', 'Delete selected content')).click();
    element(by.id('edit-submit--2')).click();
    element(by.id('edit-submit')).click();
    expect(element(by.css('#node-admin-content > div > table:nth-of-type(2) > tbody > tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No content available.');

  });

});
