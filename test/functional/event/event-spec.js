'use strict';
/**
 * WOW Homepage Spec
 */

var url = require('url');
var path = require('path');

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('can create an event class terms', function(){
    browser.get(browser.params.url + '/admin/structure/taxonomy/event_class/add');

    // Test term 1
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event class 1');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 1 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 2
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event class 2');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 2 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 3
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event class 3');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 3 description');
    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create an event type terms', function(){

    browser.get(browser.params.url + '/admin/structure/taxonomy/event_type/add');

    // Test term 1
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event type 1');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 1 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 2
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event type 2');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 2 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 3
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-title')).sendKeys('Test event type 3');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 3 description');
    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create a minimal event page', function(){

  });

  it('can create a full event page', function(){
    browser.get(browser.params.url + '/node/add/event');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Event');

    // identify vertical tabs
    var main = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']"));
    var dateTime = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']"));
    var publishing = dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

    // submit the form
    dvr.findElement(by.id('edit-submit')).click();

    // check for the error message explaining that required fields haven't been populated
    expect(dvr.findElement(by.id('console')).getText()).toContain('Title field is required');
    expect(dvr.findElement(by.id('console')).getText()).toContain('Class field is required');
    expect(dvr.findElement(by.id('console')).getText()).toContain('Start date/time field is required');

    // fill out content on 'Main' tab
    main.click();
    dvr.findElement(by.id('edit-title')).sendKeys('Protractor event page');
    dvr.findElement(by.id('edit-field-teaser-und')).sendKeys('Here is some content in the teaser field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');
    dvr.findElement(by.id('edit-field-description-und')).sendKeys('Here is some content in the description field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');
    dvr.findElement(by.id('edit-field-event-age-range-und')).sendKeys('Blah blah');
    expect(dvr.findElement(by.css('.form-item-field-event-class-und:nth-of-type(1) > label')).getText()).toContain('Test event class 1');
    dvr.findElement(by.id('edit-field-event-class-und-1')).click();
    expect(dvr.findElement(by.css('.form-item-field-event-type-und:nth-of-type(1) > label')).getText()).toContain('Test event type 1');
    dvr.findElement(by.id('edit-field-event-type-und-1')).click();
    expect(dvr.findElement(by.css('.form-item-field-event-type-und:nth-of-type(3) > label')).getText()).toContain('Test event type 3');
    dvr.findElement(by.id('edit-field-event-type-und-3')).click();

    // fill out content on 'Date and time' tab
    dateTime.click();
    dvr.findElement(by.id('edit-field-event-start-date-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
    dvr.findElement(by.id('edit-field-event-start-date-und-0-value-timeEntry-popup-1')).sendKeys('19:30');
    dvr.findElement(by.id('edit-field-event-end-date-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
    dvr.findElement(by.id('edit-field-event-end-date-und-0-value-timeEntry-popup-1')).sendKeys('22:00');
    dvr.findElement(by.id('edit-field-event-duration-und-0-value-timeEntry-popup-1')).sendKeys('2:30');
    dvr.findElement(by.id('edit-field-event-door-time-und-0-value-timeEntry-popup-1')).sendKeys('19:00');

    // set the item to published
    publishing.click();
    dvr.findElement(by.id('edit-status')).click();

    // submit
    dvr.findElement(by.id('edit-submit')).click();

    // get node ID of event just created
    dvr.getCurrentUrl().then(function(currentUrl) {
      var currentUrlObj = url.parse(currentUrl);
      var currentUrlPath = currentUrlObj.pathname.split(path.sep);
      var nid = currentUrlPath[currentUrlPath.length-1];

      nid = 1;

      browser.get(browser.params.url + '/node.json?nid=' + nid);
      dvr.findElement(by.tagName('body')).getText().then(function(json) {
        
        // Test JSON
        json = JSON.parse(json);
        var eventJson = json.list[0];

        expect(eventJson.hasOwnProperty('nid')).toBe(true);
        expect(eventJson.title === 'Protractor event page').toBe(true);

      });
    });

  });

});
