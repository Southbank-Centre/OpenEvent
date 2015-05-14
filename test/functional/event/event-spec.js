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

  it('can create an event class terms', function(){
    browser.get(browser.params.url + '/admin/structure/taxonomy/event_class/add');

    // Test term 1
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event class 1');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 1 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 2
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event class 2');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 2 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 3
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event class');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event class 3');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event class 3 description');
    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create an event type terms', function(){

    browser.get(browser.params.url + '/admin/structure/taxonomy/event_type/add');

    // Test term 1
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event type 1');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 1 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 2
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event type 2');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 2 description');
    dvr.findElement(by.id('edit-submit')).click();

    // Test term 3
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Event type');
    dvr.findElement(by.id('edit-name')).sendKeys('Test event type 3');
    dvr.findElement(by.id('edit-description-value')).sendKeys('Test event type 3 description');
    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can allow events to be viewed by anyone', function() {
    browser.get(browser.params.url + '/admin/people/permissions');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('People');

    // Allow published content to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-content')).click();
    dvr.findElement(by.id('edit-2-access-content')).click();

    // Allow node API endpoints to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-resource-node')).click();
    dvr.findElement(by.id('edit-2-access-resource-node')).click();
    dvr.findElement(by.id('edit-1-access-resource-relation')).click();
    dvr.findElement(by.id('edit-2-access-resource-relation')).click();

    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create a minimal event page', function(){
    browser.get(browser.params.url + '/node/add/event');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Event');

    // add a bad age range
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-field-event-age-range-und-0-value')).sendKeys('+12');

    // add bad duration
    dvr.executeScript('window.scrollTo(0,0);').then(function () {

      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();
      dvr.findElement(by.id('edit-field-event-duration-und-0-value')).sendKeys('1.20');

      // submit the form
      dvr.findElement(by.id('edit-submit')).click();

      // check for the error message explaining that required fields haven't been populated
      expect(dvr.findElement(by.id('console')).getText()).toContain('Title field is required');
      expect(dvr.findElement(by.id('console')).getText()).toContain('Class field is required');
      expect(dvr.findElement(by.id('console')).getText()).toContain('A valid date is required for Date/time Start date');
      expect(dvr.findElement(by.id('console')).getText()).toContain('An age range should be one of the following three formats: Either "5+" (ages 5 and above), "0-12" (ages 0 to 12), or "16" (age 16 only).');
      expect(dvr.findElement(by.id('console')).getText()).toContain('Only numbers are allowed in Duration');

      // fill out content on 'Main' tab
      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
      dvr.findElement(by.id('edit-title')).sendKeys('Parent event page');
      dvr.findElement(by.id('edit-field-event-age-range-und-0-value')).clear();
      expect(dvr.findElement(by.css('#edit-field-event-class-und > .form-item-field-event-class-und:nth-of-type(1) > label')).getText()).toContain('Test event class 1');
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

        // test successful save
        expect(element(by.id('console')).getText()).toContain('Event Parent event page has been created.');

        // go back to edit page
        dvr.findElement(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
        dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
        dvr.findElement(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

          parentPathAlias = alias;

          // store node ID of event just created
          dvr.getCurrentUrl().then(function(currentUrl) {
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
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Protractor event page');
    dvr.findElement(by.id('edit-field-description-und-0-value')).sendKeys('Here is some content in the description field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');
    dvr.findElement(by.id('edit-field-event-age-range-und-0-value')).sendKeys('4+');
    expect(dvr.findElement(by.css('#edit-field-event-class-und > .form-item-field-event-class-und:nth-of-type(1) > label')).getText()).toContain('Test event class 1');
    dvr.findElement(by.css('#edit-field-event-class-und > .form-item-field-event-class-und:nth-of-type(1) > input')).click();
    expect(dvr.findElement(by.css('#edit-field-event-type-und > .form-type-checkbox:nth-of-type(1) > label')).getText()).toContain('Test event type 1');
    dvr.findElement(by.css('#edit-field-event-type-und > .form-type-checkbox:nth-of-type(1) > input')).click();
    expect(dvr.findElement(by.css('#edit-field-event-type-und > .form-type-checkbox:nth-of-type(3) > label')).getText()).toContain('Test event type 3');
    dvr.findElement(by.css('#edit-field-event-type-und > .form-type-checkbox:nth-of-type(3) > input')).click();

    // type in the title of the page created in the above test and wait for the autocomplete list to load
    dvr.findElement(by.css('#edit-field-event-parents tr:last-of-type input[type="text"]')).sendKeys('Parent event page');
    dvr.wait(function () {
        return dvr.isElementPresent(by.css('#autocomplete li:first-of-type div'));
    }, 5000);

    // check that there's at least one item in the list, and that it doesn't contain a link
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div/a")).isPresent()).toBe(false);
    element(by.xpath("//div[@id='autocomplete']//li[1]//div")).click();

    // check that more parents can be added
    expect(element(by.id('edit-field-event-parents-und-add-more')).isPresent()).toBe(true);

    // fill out content on 'Date and time' tab
    dvr.executeScript('window.scrollTo(0,0);').then(function () {

      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

      // start date/time
      expect(element(by.id('edit-field-event-date-time-und-0-all-day')).isPresent()).toBe(true);
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).click();
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

      // end date/time
      dvr.findElement(by.id('edit-field-event-date-time-und-0-show-todate')).click();
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value2-datepicker-popup-0')).sendKeys('15/04/2015');
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value2-timeEntry-popup-1')).click();
      dvr.findElement(by.id('edit-field-event-date-time-und-0-value2-timeEntry-popup-1')).sendKeys('22:00');

      // duration
      dvr.findElement(by.id('edit-field-event-duration-und-0-value')).clear();
      dvr.findElement(by.id('edit-field-event-duration-und-0-value')).sendKeys('150');

      // door time
      dvr.findElement(by.id('edit-field-event-door-time-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
      dvr.findElement(by.id('edit-field-event-door-time-und-0-value-timeEntry-popup-1')).click();
      dvr.findElement(by.id('edit-field-event-door-time-und-0-value-timeEntry-popup-1')).sendKeys('19:00');

      // set the item to published
      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
      dvr.findElement(by.id('edit-status')).click();

      // submit
      dvr.findElement(by.id('edit-submit')).click();

      // test successful save
      expect(element(by.id('console')).getText()).toContain('Event Protractor event page has been created.');

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

  it('can have venues assigned to an Event', function() {

    // create a Place
    browser.get(browser.params.url + '/node/add/place');
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Place that has an event');
    // set the item to published
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
    dvr.findElement(by.id('edit-status')).click();
    dvr.findElement(by.id('edit-submit')).click();
    expect(element(by.id('console')).getText()).toContain('Place Place that has an event has been created.');

    // go back to edit page
    dvr.findElement(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
    dvr.findElement(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

      placePathAlias = alias;

      // store node ID of event just created
      dvr.getCurrentUrl().then(function(currentUrl) {
        var currentUrlObj = url.parse(currentUrl);
        var currentUrlPath = currentUrlObj.pathname.split(path.sep);
        placeNid = currentUrlPath[currentUrlPath.length-2];

      });

      // edit node with id stored in 'nid'
      browser.get(browser.params.url + '/node/' + nid + '/edit');

      // try to select an event - shouldn't be possible
      // type in the title of the event and wait for the autocomplete list to load
      dvr.findElement(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).sendKeys('Parent event page');
      dvr.sleep(5000);
      // check that there are no items in the autocomplete list
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(false);

      // select place made earlier in test
      dvr.findElement(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).clear();
      dvr.findElement(by.css('#edit-field-event-places tr:last-of-type input[type="text"]')).sendKeys('Place that has an event');
      dvr.wait(function () {
          return dvr.isElementPresent(by.css('#autocomplete li:first-of-type div'));
      }, 5000);

      // check that there are items in the autocomplete list and select the first one
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div")).isPresent()).toBe(true);
      expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div/a")).isPresent()).toBe(false);
      element(by.xpath("//div[@id='autocomplete']//li[1]//div")).click();

      // see that you can add more venues
      expect(element(by.id('edit-field-event-places-und-add-more')).isPresent()).toBe(true);

      // re-focus
      dvr.executeScript('window.scrollTo(0,0);').then(function () {
        
        element(by.css('h1')).click();
        // save
        dvr.findElement(by.id('edit-submit')).click().then(function() {
          dvr.wait(function () {
            return dvr.isElementPresent(by.id('console'));
          }, 5000);
          // verify save
          expect(element(by.id('console')).getText()).toContain('Event Protractor event page has been updated.');

        });

      });

    });

  });

  it('outputs Event node JSON in the expected format', function () {

    frisby.create('Get JSON for Event page created in previous test')
      .get(browser.params.url + '/node/' + nid + '.json')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      .expectJSON({
        "field_description": {
          "value": "<p>Here is some content in the description field <em>that contains emphasis</em> but doesNotContainJavascript();</p>\n",
          "format": "filtered_html"
        },
        "field_event_age_range": "4+",
        "field_event_class": {
          "uri": function(val) { expect(val).toContain(browser.params.url + "/taxonomy_term/"); },
          "id": function(val) {
            expect(val).toBeDefined();
            expect(isNaN(parseInt(val, 10))).toBe(false);
          },
          "resource": "taxonomy_term"
        },
        "field_event_type": [
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/taxonomy_term/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "taxonomy_term"
          },
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/taxonomy_term/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "taxonomy_term"
          }
        ],
        "field_image": [],
        "field_event_date_time": {
          "value": function(val) { 
            expect(val.length).toEqual(10); 
            expect(isNaN(parseInt(val, 10))).toBe(false);
          },
          "value2": function(val) { 
            expect(val.length).toEqual(10); 
            expect(isNaN(parseInt(val, 10))).toBe(false);
          },
          "duration": function(val) { expect(typeof val).toEqual("number"); },
        },
        "field_event_door_time": function(val) {
          expect(val.length).toEqual(10);
          expect(isNaN(parseInt(val, 10))).toBe(false);
        },
        "field_event_duration": "150",
        "nid": nid,
        "vid": nid,
        "is_new": function(val) { expect(typeof val).toEqual("boolean"); },
        "type": "event",
        "title": "Protractor event page",
        "language": "und",
        "url": browser.params.url + '/' + pathAlias,
        "edit_url": browser.params.url + "/node/" + nid + "/edit",
        "status": "1",
        "promote": "0",
        "sticky": "0",
        "created": function(val) {
          expect(val.length).toEqual(10);
          expect(isNaN(parseInt(val, 10))).toBe(false); 
        },
        "changed": function(val) {
          expect(val.length).toEqual(10);
          expect(isNaN(parseInt(val, 10))).toBe(false);
        },
        "body": {
          "value": "",
          "summary": "",
          "format": null
        }
      })
      .after(function() {

        // Get the list of all relations of this type, because we don't yet have
        // a way to filter by an item in the endpoints array
        frisby.create('Get JSON for "event is located in place" relation')
          .get(browser.params.url + '/relation.json?relation_type=event_is_located_in_place')
          .expectStatus(200)
          .expectHeaderContains('content-type', 'application/json')
          .expectJSON('list.0', {
            "endpoints": [
              {
                "uri": browser.params.url + "/node/" + nid,
                "id": nid,
                "resource": "node"
              },
              {
                "uri": browser.params.url + "/node/" + placeNid,
                "id": placeNid,
                "resource": "node"
              }
            ]
          })
          .after(function () {

            // Get the list of all relations of this type, because we don't yet have
            // a way to filter by an item in the endpoints array
            frisby.create('Get JSON for "event is contained in event" relation')
              .get(browser.params.url + '/relation.json?relation_type=event_is_contained_in_event')
              .expectStatus(200)
              .expectHeaderContains('content-type', 'application/json')
              .expectJSON('list.0', {
                "endpoints": [
                  {
                    "uri": browser.params.url + "/node/" + nid,
                    "id": nid,
                    "resource": "node"
                  },
                  {
                    "uri": browser.params.url + "/node/" + parentNid,
                    "id": parentNid,
                    "resource": "node"
                  }
                ]
              })
              .after(CleanUp)
              .toss();

          })
          .toss();

      })
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
          dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(3) a')).click();
          dvr.findElement(by.id('edit-delete')).click();
          dvr.findElement(by.id('edit-submit')).click();
          dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(3) a')).click();
          dvr.findElement(by.id('edit-delete')).click();
          dvr.findElement(by.id('edit-submit')).click();
          expect(dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(1)')).getText()).toContain('No terms available.');

          // remove event type terms
          browser.get(browser.params.url + '/admin/structure/taxonomy/event_type');
          dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(3) a')).click();
          dvr.findElement(by.id('edit-delete')).click();
          dvr.findElement(by.id('edit-submit')).click();
          dvr.findElement(by.css('#taxonomy tr:first-of-type td:nth-of-type(3) a')).click();
          dvr.findElement(by.id('edit-delete')).click();
          dvr.findElement(by.id('edit-submit')).click();
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
          dvr.findElement(by.id('edit-1-access-resource-relation')).click();
          dvr.findElement(by.id('edit-2-access-resource-relation')).click();
          dvr.findElement(by.id('edit-submit')).click();

        });

      });
      
    }

  });

});