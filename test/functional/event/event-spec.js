'use strict';
/**
 * Event Spec
 */

var url = require('url');
var path = require('path');

describe('The Event features of the CMS', function() {

  var parentNid;
  var parentPathAlias;
  var nid;
  var pathAlias;
  var placeNid;
  var placePathAlias;

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('can create a minimal event page', function(){
    browser.get(browser.params.url + '/node/add/event');
    expect(element(by.css('.page-title')).getText()).toContain('Create Event');

    // add a bad age range
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Details']")).click();
    element(by.id('edit-field-event-age-range-und-0-value')).sendKeys('+12');

    // add bad duration
    browser.executeScript('window.scrollTo(0,0);').then(function () {

      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();
      element(by.id('edit-field-event-duration-und-0-value')).sendKeys('1.20');

      // submit the form
      element(by.id('edit-submit')).click();

      // check for the error message explaining that required fields haven't been populated
      expect(dvr.findElement(by.id('console')).getText()).toContain('A valid date is required for End date/time.');
      expect(dvr.findElement(by.id('console')).getText()).toContain('A valid date is required for Start date/time.');
      expect(dvr.findElement(by.id('console')).getText()).toContain('An age range should be one of the following three formats: Either "5+" (ages 5 and above), "0-12" (ages 0 to 12), or "16" (age 16 only).');
      expect(dvr.findElement(by.id('console')).getText()).toContain('Only numbers are allowed in Duration');

      // fill out content on 'Main' tab
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
      element(by.id('edit-title')).sendKeys('Parent event page');

      // fill out content on 'Details' tab
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Details']")).click();
      element(by.id('edit-field-event-age-range-und-0-value')).clear();

      // fill out content on 'Date and time' tab
      browser.executeScript('window.scrollTo(0,0);').then(function () {

        element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

        // start date/time
        element(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
        element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
        element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

        // end date/time
        element(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
        element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
        element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

        // duration
        element(by.id('edit-field-event-duration-und-0-value')).clear();

        // set the item to published
        element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
        element(by.id('edit-status')).click();

        // submit
        element(by.id('edit-submit')).click();

        // test successful save
        expect(element(by.id('console')).getText()).toContain('Event Parent event page has been created.');

        // go back to edit page
        element(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
        element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
        element(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

          parentPathAlias = alias;

          // store node ID of event just created
          browser.getCurrentUrl().then(function(currentUrl) {
            var currentUrlObj = url.parse(currentUrl);
            var currentUrlPath = currentUrlObj.pathname.split(path.sep);
            parentNid = currentUrlPath[currentUrlPath.length-2];

          });

        });

      });

    });

  });

  it('can create a full event page', function(){
    browser.get(browser.params.url + '/node/add/event');

    // fill out content on 'Main' tab
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    element(by.id('edit-title')).sendKeys('Protractor event page');
    element(by.id('edit-field-description-und-0-value')).sendKeys('Here is some content in the description field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');

    // type in the title of the page created in the above test and wait for the autocomplete list to load
    element(by.css('#edit-field-event-parents tr:last-of-type input[type="text"]')).sendKeys('Parent event page');
    browser.wait(function () {
        return browser.isElementPresent(by.css('#autocomplete li:first-of-type div'));
    }, 5000);

    // check that there's at least one item in the list, and that it doesn't contain a link
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div/a")).isPresent()).toBe(false);
    element(by.xpath("//div[@id='autocomplete']//li[1]//div")).click();

    // check that more parents can be added
    expect(element(by.id('edit-field-event-parents-und-add-more')).isPresent()).toBe(true);

    // fill out content on 'Details' tab
    browser.executeScript('window.scrollTo(0,0);').then(function () {
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Details']")).click();
      element(by.id('edit-field-event-age-range-und-0-value')).sendKeys('4+');
    });

    // fill out content on 'Date and time' tab
    browser.executeScript('window.scrollTo(0,0);').then(function () {

      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

      // start date/time
      expect(element(by.id('edit-field-event-date-start-und-0-all-day')).isPresent()).toBe(true);
      element(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
      element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

      // end date/time
      expect(element(by.id('edit-field-event-date-end-und-0-all-day')).isPresent()).toBe(true);
      element(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
      element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
      element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

      // duration
      element(by.id('edit-field-event-duration-und-0-value')).clear();
      element(by.id('edit-field-event-duration-und-0-value')).sendKeys('150');

      // door time
      element(by.id('edit-field-event-door-time-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      element(by.id('edit-field-event-door-time-und-0-value-timeEntry-popup-1')).click();
      element(by.id('edit-field-event-door-time-und-0-value-timeEntry-popup-1')).sendKeys('19:00');

      // set the item to published
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
      element(by.id('edit-status')).click();

      // submit
      element(by.id('edit-submit')).click();

      // test successful save
      expect(element(by.id('console')).getText()).toContain('Event Protractor event page has been created.');

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
        });

      });

    });

  });

  it('can have venues assigned to an Event', function() {

    // create a Place
    browser.get(browser.params.url + '/node/add/place');
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    element(by.id('edit-title')).sendKeys('Place that has an event');

    // set the item to published
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
    element(by.id('edit-status')).click();
    element(by.id('edit-submit')).click();
    expect(element(by.id('console')).getText()).toContain('Place Place that has an event has been created.');

    // go back to edit page
    element(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
    element(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

      placePathAlias = alias;

      // store node ID of event just created
      browser.getCurrentUrl().then(function(currentUrl) {
        var currentUrlObj = url.parse(currentUrl);
        var currentUrlPath = currentUrlObj.pathname.split(path.sep);
        placeNid = currentUrlPath[currentUrlPath.length-2];

      });

      // edit node with id stored in 'nid'
      browser.get(browser.params.url + '/node/' + nid + '/edit');

      // try to select an event - shouldn't be possible
      // type in the title of the event and wait for the autocomplete list to load
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Details']")).click();
      element(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).sendKeys('Parent event page');
      browser.sleep(5000);
      // check that there are no items in the autocomplete list
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(false);

      // select place made earlier in test
      element(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).clear();
      element(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).sendKeys('Place that has an event');
      browser.wait(function () {
          return browser.isElementPresent(by.css('#autocomplete li:first-of-type div'));
      }, 5000);

      // check that there are items in the autocomplete list and select the first one
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div")).isPresent()).toBe(true);
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div/a")).isPresent()).toBe(false);
      element(by.xpath("//div[@id='autocomplete']//li[1]//div")).click();

      // see that you can add more venues
      expect(element(by.id('edit-field-event-places-und-add-more')).isPresent()).toBe(true);

      // re-focus
      browser.executeScript('window.scrollTo(0,0);').then(function () {
        element(by.css('h1')).click();
        // save
        element(by.id('edit-submit')).click().then(function() {
          browser.wait(function () {
            return browser.isElementPresent(by.id('console'));
          }, 5000);
          // verify save
          expect(element(by.id('console')).getText()).toContain('Event Protractor event page has been updated.');

        });

      });

    });

  });

  /* API output tests */

  it('outputs Event node JSON in Schema.org format', function () {
    // get Event JSON from API and parse it
    browser.get(browser.params.url + '/api/event/' + nid + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);

       // string fields as input
       expect(json.name).toBe("Protractor event page");
       expect(json.description).toBe("<p>Here is some content in the description field <em>that contains emphasis</em> but doesNotContainJavascript();</p>\n");
       expect(json.typicalAgeRange).toBe("4+");

       // empty image
       expect(json.image.length).toEqual(0);

       // duration transformed into ISO8601 duration format
       expect(json.duration).toBe("P0Y0M0DT2H30M0S");

       // check date fields are all parseable as ISO8601 Dates
       var startParsed = Date.parse(json.startDate);
       expect(isNaN(parseInt(startParsed, 10))).toBe(false);

       var endParsed = Date.parse(json.endDate);
       expect(isNaN(parseInt(endParsed, 10))).toBe(false);

       var doorParsed = Date.parse(json.doorTime);
       expect(isNaN(parseInt(doorParsed, 10))).toBe(false);

       // URL of this item should be predictable based on NID
       expect(json.url).toBe(browser.params.url + '/api/event/' + nid);

       // Relations to other items set up correctly
       expect(json.superEvent.length).toEqual(1);
       expect(json.superEvent[0]).toEqual(browser.params.url + "/api/event/" + parentNid);
       expect(json.location.length).toEqual(1);
       expect(json.location[0]).toEqual(browser.params.url + "/api/place/" + placeNid)
       expect(json.subEvent.length).toEqual(0);
       expect(json.performers.length).toEqual(0);
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
