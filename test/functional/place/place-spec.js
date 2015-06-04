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
    isAngularSite(false);
  });


  it('can create a minimal place page', function(){
    browser.get(browser.params.url + '/node/add/place');
    expect(element(by.css('.page-title')).getText()).toContain('Create Place');

    // submit the form
    element(by.id('edit-submit')).click();

    // check for the error message explaining that required fields haven't been populated
    expect(element(by.id('console')).getText()).toContain('Name field is required');

    // fill out content on 'Main' tab
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    element(by.id('edit-title')).sendKeys('Parent place');

    // set the item to published
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
    element(by.id('edit-status')).click();

    // submit
    element(by.id('edit-submit')).click();

    // test successful save
    expect(element(by.id('console')).getText()).toContain('Place Parent place has been created.');

    // go back to edit page
    element(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
    element(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

      parentPathAlias = alias;

      // store node ID of place just created
      browser.getCurrentUrl().then(function(currentUrl) {
        var currentUrlObj = url.parse(currentUrl);
        var currentUrlPath = currentUrlObj.pathname.split(path.sep);
        parentNid = currentUrlPath[currentUrlPath.length-2];

      });

    });

  });

  it('can create a full place page', function(){
    browser.get(browser.params.url + '/node/add/place');

    // fill out content on 'Main' tab
    element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
    element(by.id('edit-title')).sendKeys('Protractor place');
    element(by.id('edit-field-description-und-0-value')).sendKeys('Here is some content in the description field <em>that contains emphasis</em> but <script>doesNotContainJavascript();</script>');
    // upload 'Image'
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

    // type in the title of the page created in the above test and wait for the autocomplete list to load
    element(by.css('#edit-field-place-parents tr:last-of-type input[type="text"]')).sendKeys('Parent place');
    browser.wait(function () {
        return browser.isElementPresent(by.css('#autocomplete li:first-of-type div'));
    }, 5000);

    // check that there's at least one item in the list, and that it doesn't contain a link
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//div/a")).isPresent()).toBe(false);
    element(by.xpath("//div[@id='autocomplete']//li[1]//div")).click();

    // check that more parents can be added
    expect(element(by.id('edit-field-place-parents-und-add-more')).isPresent()).toBe(true);

    // fill out content on 'Location' tab
    browser.executeScript('window.scrollTo(0,0);').then(function () {

      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Location']")).click();

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
      element(by.css('.geolocation-address-geocode')).click();

      // wait for Google Maps
      browser.sleep(5000);
      expect(element(by.css('#edit-field-place-geolocation-und-0-latitem .geolocation-lat-item-value')).getText()).not.toEqual('');
      expect(element(by.css('#edit-field-place-geolocation-und-0-lngitem .geolocation-lat-item-value')).getText()).not.toEqual('');

      // fill out content on 'Opening hours' tab
      browser.executeScript('window.scrollTo(0,0);').then(function () {

        element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Opening hours']")).click();

        // fill out Opening Hours field
        // Monday
        element(by.cssContainingText('#edit-field-place-opening-hours-und-2-starthours-hours > option', '07')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-2-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-2-endhours-hours > option', '15')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-2-endhours-minutes > option', '00')).click();
        // Tuesday
        element(by.cssContainingText('#edit-field-place-opening-hours-und-4-starthours-hours > option', '08')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-4-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-4-endhours-hours > option', '16')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-4-endhours-minutes > option', '00')).click();
        // Wednesday
        element(by.cssContainingText('#edit-field-place-opening-hours-und-6-starthours-hours > option', '09')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-6-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-6-endhours-hours > option', '17')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-6-endhours-minutes > option', '00')).click();
        // Thursday
        element(by.cssContainingText('#edit-field-place-opening-hours-und-8-starthours-hours > option', '10')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-8-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-8-endhours-hours > option', '18')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-8-endhours-minutes > option', '00')).click();
        // Friday (overnight)
        element(by.cssContainingText('#edit-field-place-opening-hours-und-10-starthours-hours > option', '11')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-10-starthours-minutes > option', '00')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-10-endhours-hours > option', '02')).click();
        element(by.cssContainingText('#edit-field-place-opening-hours-und-10-endhours-minutes > option', '00')).click();

        // fill out content on 'Publishing options' tab
        browser.executeScript('window.scrollTo(0,0);').then(function () {

          // set the item to published
          element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']")).click();
          element(by.id('edit-status')).click();

          // submit
          element(by.id('edit-submit')).click();

          // test successful save
          expect(element(by.id('console')).getText()).toContain('Place Protractor place has been created.');

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

    });

  });

  it('outputs Place node JSON in Schema.org format', function () {
    // set correct filename for checking image upload
    var imageName = 'test-img.jpg';
    if (browser.params.isSauceLabs) {
      imageName = 'shot_0.png';
    }

    // get Place JSON from API and parse it
    browser.get(browser.params.url + '/api/place/' + nid + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);

      // string fields as input
      expect(json.name).toBe("Protractor place");
      expect(json.description).toBe("<p>Here is some content in the description field <em>that contains emphasis</em> but doesNotContainJavascript();</p>\n");

      // image uploaded & fields filled out as expected
      expect(json.image.contentUrl).toContain(browser.params.url);
      expect(json.image.contentUrl).toContain(imageName.split(".")[0]);
      expect(json.image.alternateName).toBe("Test image ALT");
      expect(json.image.caption).toBe("Test image TITLE");

      // address fields as input
      expect(json.address.addressCountry).toBe("GB");
      expect(json.address.addressRegion).toBe("London (county)");
      expect(json.address.addressLocality).toBe("London");
      expect(json.address.postalCode).toBe("SE1 8XX");
      expect(json.address.streetAddress).toBe("Southbank Centre, Belvedere Road");

      // geolocation & map link as expected for the address input
      expect(json.geo.latitude).toBe("51.5066566");
      expect(json.geo.longitude).toBe("-0.11511270000005425");
      expect(json.hasMap).toBe("http://www.openstreetmap.org/?mlat=51.5066566&mlon=-0.11511270000005425#map=15/51.5066566/-0.11511270000005425");

      // opening hours as input
      expect(json.openingHoursSpecification[0].dayOfWeek).toBe("http://purl.org/goodrelations/v1#Monday");
      expect(json.openingHoursSpecification[0].opens).toBe("07:00:00");
      expect(json.openingHoursSpecification[0].closes).toBe("15:00:00");
      expect(json.openingHoursSpecification[1].dayOfWeek).toBe("http://purl.org/goodrelations/v1#Tuesday");
      expect(json.openingHoursSpecification[1].opens).toBe("08:00:00");
      expect(json.openingHoursSpecification[1].closes).toBe("16:00:00");
      expect(json.openingHoursSpecification[2].dayOfWeek).toBe("http://purl.org/goodrelations/v1#Wednesday");
      expect(json.openingHoursSpecification[2].opens).toBe("09:00:00");
      expect(json.openingHoursSpecification[2].closes).toBe("17:00:00");
      expect(json.openingHoursSpecification[3].dayOfWeek).toBe("http://purl.org/goodrelations/v1#Thursday");
      expect(json.openingHoursSpecification[3].opens).toBe("10:00:00");
      expect(json.openingHoursSpecification[3].closes).toBe("18:00:00");
      expect(json.openingHoursSpecification[4].dayOfWeek).toBe("http://purl.org/goodrelations/v1#Friday");
      expect(json.openingHoursSpecification[4].opens).toBe("11:00:00");
      expect(json.openingHoursSpecification[4].closes).toBe("02:00:00");

      // URL of this item should be predictable based on NID
      expect(json.url).toBe(browser.params.url + '/api/place/' + nid);

      // Relation to parent place item set up correctly
      expect(json.containedIn.length).toEqual(1);
      expect(json.containedIn[0]).toEqual(browser.params.url + "/api/place/" + parentNid);

      // No related event specified
      expect(json.event.length).toEqual(0);
    });
  });

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
