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

  beforeEach(function(){
    isAngularSite(false);
  });

  it('can be added to an Event page', function(){
    
    console.log("Image: staring spec\n");
    // Add test term (required to save an Event page)
    browser.get(browser.params.url + '/admin/structure/taxonomy/event_class/add');

    // Test term 1
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event class 1');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 1 description');
    dvr.findElement(by.id('edit-submit')).click();


    browser.get(browser.params.url + '/admin/people/permissions');
    //expect(dvr.findElement(by.css('.page-title')).getText()).toContain('People');

    
    // Allow published content to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-content')).click();
    dvr.findElement(by.id('edit-2-access-content')).click();

    // Allow node API endpoints to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-resource-node')).click();
    dvr.findElement(by.id('edit-2-access-resource-node')).click();
    dvr.findElement(by.id('edit-1-access-resource-file')).click();
    dvr.findElement(by.id('edit-2-access-resource-file')).click();

    dvr.findElement(by.id('edit-submit')).click();


    // Create minimal Event page

    browser.get(browser.params.url + '/node/add/event');

    // fill out content on 'Main' tab
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Test event page');

    // upload 'Image'
    var fileToUpload = 'test-img.jpg';
    var absolutePath = path.resolve(__dirname, fileToUpload);
    dvr.findElement(by.id('edit-field-image-und-0-upload')).sendKeys(absolutePath);
    dvr.findElement(by.id('edit-field-image-und-0-upload-button')).click();
    //$('#edit-field-image-und-0-upload').sendKeys(absolutePath);
    //$('#edit-field-image-und-0-upload-button').click();

    // wait until image has uploaded
    browser.wait(function() {
     return browser.isElementPresent($('#edit-field-image-und-0-alt'));
    }, 5000);

    $('#edit-field-image-und-0-alt').sendKeys('Test image ALT');
    $('#edit-field-image-und-0-title').sendKeys('Test image TITLE');

    // select event class
    dvr.findElement(by.css('#edit-field-event-class-und > .form-item-field-event-class-und:nth-of-type(1) > input')).click();


    // fill out content on 'Date and time' tab
    dvr.executeScript('window.scrollTo(0,0);').then(function () {

      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

       // start date/time
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).click();
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

      // duration
      dvr.findElement(by.id('edit-field-event-duration-und-0-value')).clear();

      
      // set the item to published
      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
      dvr.findElement(by.id('edit-status')).click();

      // submit
      dvr.findElement(by.id('edit-submit')).click();

      // test uploaded image exists
      expect($('.field-name-field-image img').isPresent()).toBe(true);
      expect($('.field-name-field-image img').getAttribute('alt')).toEqual('Test image ALT');
      expect($('.field-name-field-image img').getAttribute('title')).toEqual('Test image TITLE');


      // go back to edit page
      dvr.findElement(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();

      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
      dvr.findElement(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

        pathAlias = alias;

        // store node ID of event just created
        dvr.getCurrentUrl().then(function(currentUrl) {
          var currentUrlObj = url.parse(currentUrl);
          var currentUrlPath = currentUrlObj.pathname.split(path.sep);
          nid = currentUrlPath[currentUrlPath.length-2];
        });

      });

    });

  });


  it('outputs the Image data with the Event node JSON in the expected format', function () {

    frisby.create('Get JSON for Event page created in previous test')
      .get(browser.params.url + '/node/' + nid + '.json')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')

      .expectJSONTypes({
        "field_image": {
          "file": {
            "id": String
          },
          "alt": String,
          "title": String
        }
      })

      .expectJSON({
        "field_image": {
          "alt": "Test image ALT",
          "title": "Test image TITLE"
        }  
      })

      .afterJSON(function(imageJSON) {

        // Use data from previous result in next test
        
        frisby.create('Image JSON')

          .get(browser.params.url + '/file/' + imageJSON.field_image.file.id + '.json')
          .expectStatus(200)
          .expectHeaderContains('content-type', 'application/json')

          .expectJSON({
            "name": 'test-img.jpg'  
          })

        .toss();
      })

      .after(CleanUp)
      .toss();

      function CleanUp() {

        describe('Clean up', function() {

          it('will take place after all tests have passed', function() {

            // CLEAN UP
            
            // remove event class terms
            browser.get(browser.params.url + '/admin/structure/taxonomy/event_class');
            dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(3) a')).click();
            dvr.findElement(by.id('edit-delete')).click();
            dvr.findElement(by.id('edit-submit')).click();
            expect(dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No terms available.');

            // remove content
            browser.get(browser.params.url + '/admin/content');
            dvr.findElement(by.css('#node-admin-content > div > table:nth-of-type(2) > thead:first-of-type > tr:first-of-type > th:first-of-type input')).click();
            element(by.cssContainingText('#edit-operation > option', 'Delete selected content')).click();
            element(by.id('edit-submit--2')).click();
            element(by.id('edit-submit')).click();
            expect(dvr.findElement(by.css('#node-admin-content > div > table:nth-of-type(2) > tbody > tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No content available.');

            // reset permissions
            browser.get(browser.params.url + '/admin/people/permissions');
            dvr.findElement(by.id('edit-1-access-content')).click();
            dvr.findElement(by.id('edit-2-access-content')).click();
            dvr.findElement(by.id('edit-1-access-resource-node')).click();
            dvr.findElement(by.id('edit-2-access-resource-node')).click();
            dvr.findElement(by.id('edit-1-access-resource-file')).click();
            dvr.findElement(by.id('edit-2-access-resource-file')).click();
            dvr.findElement(by.id('edit-submit')).click();

          });

        });

      }

  });


});

