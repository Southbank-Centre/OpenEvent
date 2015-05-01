'use strict';
/**
 * Place Spec
 */

var url = require('url');
var path = require('path');

describe('The Place features of the CMS', function() {

  var parentNid;
  var parentPathAlias;
  var nid;
  var pathAlias;

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    isAngularSite(false);
  });

  it('can allow places to be viewed by anyone', function() {
    browser.get(browser.params.url + '/admin/people/permissions');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('People');

    // Allow published content to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-content')).click();
    dvr.findElement(by.id('edit-2-access-content')).click();

    // Allow node API endpoints to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-resource-node')).click();
    dvr.findElement(by.id('edit-2-access-resource-node')).click();

    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create a minimal place page', function(){
    browser.get(browser.params.url + '/node/add/place');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Place');

    // submit the form
    dvr.findElement(by.id('edit-submit')).click();

    // check for the error message explaining that required fields haven't been populated
    expect(dvr.findElement(by.id('console')).getText()).toContain('Title field is required');

    // fill out content on 'Main' tab
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Parent place');

    // submit
    dvr.findElement(by.id('edit-submit')).click();

    // test successful save
    expect(element(by.id('console')).getText()).toContain('Place Parent place has been created.');

    // go back to edit page
    dvr.findElement(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
    dvr.findElement(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

      parentPathAlias = alias;

      // store node ID of place just created
      dvr.getCurrentUrl().then(function(currentUrl) {
        var currentUrlObj = url.parse(currentUrl);
        var currentUrlPath = currentUrlObj.pathname.split(path.sep);
        parentNid = currentUrlPath[currentUrlPath.length-2];

      });

    });

  });

  it('can create a full place page', function(){
    browser.get(browser.params.url + '/node/add/place');

    // fill out content on 'Main' tab
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Protractor place');
    dvr.findElement(by.id('edit-field-description-und-0-value')).sendKeys('Here is some content in the description field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');
    // upload 'Image'
    var fileToUpload = 'test-img.jpg';
    var absolutePath = path.resolve(__dirname, fileToUpload);
    // workaround for current inability to upload images through SauceLabs from Protractor:
    // provide the path of an image which should always exist on a SauceLabs instance
    if (browser.params.isSauceLabs) {
      absolutePath = '/home/chef/job_assets/shot_0.png';
    }
    dvr.findElement(by.id('edit-field-image-und-0-upload')).sendKeys(absolutePath);
    dvr.findElement(by.id('edit-field-image-und-0-upload-button')).click();
    // wait until image has uploaded
    browser.wait(function() {
     return browser.isElementPresent($('#edit-field-image-und-0-alt'));
    }, 5000);
    $('#edit-field-image-und-0-alt').sendKeys('Test image ALT');
    $('#edit-field-image-und-0-title').sendKeys('Test image TITLE');

    // type in the title of the page created in the above test and wait for the autocomplete list to load
    dvr.findElement(by.css('#edit-field-place-parents tr:last-of-type input[type="text"]')).sendKeys('Parent place');
    dvr.wait(function () {
        return dvr.isElementPresent(by.css('#autocomplete li:first-of-type .field-content'));
    }, 5000);

    // check that there's at least one item in the list, and that it doesn't contain a link
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']/a")).isPresent()).toBe(false);
    element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).click();

    // fill out content on 'Location' tab
    dvr.executeScript('window.scrollTo(0,0);').then(function () {

      dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Location']")).click();

      // select country
      element(by.cssContainingText('#edit-field-place-address-und-0-country > option', 'United Kingdom')).click();

      // add address details
      element(by.id('edit-field-place-address-und-0-thoroughfare')).sendKeys('Southbank Centre');
      element(by.id('edit-field-place-address-und-0-premise')).sendKeys('Belvedere Road');
      element(by.id('edit-field-place-address-und-0-locality')).sendKeys('London');
      element(by.id('edit-field-place-address-und-0-administrative-area')).sendKeys('London (county)');
      element(by.id('edit-field-place-address-und-0-postal-code')).sendKeys('SE1 8XX');

      // add geolocation
      element(by.id('edit-field-place-geolocation-und-0-address-field')).sendKeys('Southbank Centre London');
      element(by.id('geolocation-address-geocode-44-0')).click();

      // wait for Google Maps
      browser.sleep(5000);
      expect(element(by.css('#edit-field-place-geolocation-und-0-latitem .geolocation-lat-item-value')).getText()).not.toEqual('');
      expect(element(by.css('#edit-field-place-geolocation-und-0-lngitem .geolocation-lat-item-value')).getText()).not.toEqual('');

      // fill out content on 'Opening hours' tab
      dvr.executeScript('window.scrollTo(0,0);').then(function () {

        dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Opening hours']")).click();

        // fill out Opening Hours field
        // Monday
        element(by.cssContainingText('#edit-field-opening-hours-und-2-starthours-hours > option', '07')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-2-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-2-endhours-hours > option', '15')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-2-endhours-minutes > option', '00')).click();
        // Tuesday
        element(by.cssContainingText('#edit-field-opening-hours-und-4-starthours-hours > option', '08')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-4-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-4-endhours-hours > option', '16')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-4-endhours-minutes > option', '00')).click();
        // Wednesday
        element(by.cssContainingText('#edit-field-opening-hours-und-6-starthours-hours > option', '09')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-6-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-6-endhours-hours > option', '17')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-6-endhours-minutes > option', '00')).click();
        // Thursday
        element(by.cssContainingText('#edit-field-opening-hours-und-8-starthours-hours > option', '10')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-8-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-8-endhours-hours > option', '18')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-8-endhours-minutes > option', '00')).click();
        // Friday (overnight)
        element(by.cssContainingText('#edit-field-opening-hours-und-10-starthours-hours > option', '11')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-10-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-10-endhours-hours > option', '02')).click();
        element(by.cssContainingText('#edit-field-opening-hours-und-10-endhours-minutes > option', '00')).click();

        // fill out content on 'Publishing options' tab
        dvr.executeScript('window.scrollTo(0,0);').then(function () {

          // set the item to published
          dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
          dvr.findElement(by.id('edit-status')).click();

          // submit
          dvr.findElement(by.id('edit-submit')).click();

          // test successful save
          expect(element(by.id('console')).getText()).toContain('Place Protractor place has been created.');

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

    });

  });

  it('does not allow a Place to have one of its child Places assigned as a parent', function() {

    // create an Place that should appear be allowed to be selected as a parent
    browser.get(browser.params.url + '/node/add/place');

    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    dvr.findElement(by.id('edit-title')).sendKeys('Can be parent');

    // set the item to published
    dvr.findElement(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
    dvr.findElement(by.id('edit-status')).click();

    // submit
    dvr.findElement(by.id('edit-submit')).click();

    // test successful save
    expect(element(by.id('console')).getText()).toContain('Place Can be parent has been created.');

    // edit 'Parent place' to run test
    browser.get(browser.params.url + '/node/' + parentNid + '/edit');

    // type in the title of the place that is a child of this place and wait for the autocomplete list to load
    dvr.findElement(by.css('#edit-field-place-parents tr:last-of-type input[type="text"]')).sendKeys('Protractor place');
    dvr.sleep(5000);

    // check that there are no items in the autocomplete list
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(false);

    // type in the title of the place that was created earlier in this test and wait for the autocomplete list to load
    dvr.findElement(by.css('#edit-field-place-parents tr:last-of-type input[type="text"]')).clear();
    dvr.findElement(by.css('#edit-field-place-parents tr:last-of-type input[type="text"]')).sendKeys('Can be parent');
    dvr.wait(function () {
        return dvr.isElementPresent(by.css('#autocomplete li:first-of-type .field-content'));
    }, 5000);

    // check that there are items in the autocomplete list and select the first one
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']/a")).isPresent()).toBe(false);
    element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).click();

    // submit
    dvr.findElement(by.id('edit-submit')).click();

  });

  it('outputs Event node JSON in the expected format', function () {

    frisby.create('Get JSON for Event page created in previous test')
      .get(browser.params.url + '/node/' + nid + '.json')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      .expectJSON({
        "field_teaser": {
          "value": "<p>Here is some content in the teaser field <em>that contains emphasis</em> but doesNotContainJavascript();</p>\n",
          "format": "filtered_html"
        },
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
        "field_event_parents": [
          {
            "uri": browser.params.url + "/node/" + parentNid,
            "id": parentNid,
            "resource": "node"
          }
        ],
        "field_event_children": [],
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
        "cer": {
          "lineage": "node:event:",
          "depth": 0,
          "owner": {
            "uri": browser.params.url + "/node/" + nid,
            "id": nid,
            "resource": "node"
          },
          "original": {
            "uri": browser.params.url + "/node/" + nid,
            "id": nid,
            "resource": "node"
          }
        },
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

        frisby.create('Get JSON for Event page created in previous test')
          .get(browser.params.url + '/node.json?nid=' + parentNid)
          .expectStatus(200)
          .expectHeaderContains('content-type', 'application/json')
          .expectJSON('list.0.field_event_children', [
            {
              "uri": browser.params.url + "/node/" + nid,
              "id": nid,
              "resource": "node"
            }
          ])
          .after(CleanUp)
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
          dvr.findElement(by.id('edit-submit')).click();

        });

      });
      
    }

  });

});