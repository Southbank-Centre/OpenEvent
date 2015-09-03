'use strict';
/**
 * OE API Documentation Spec
 */

describe('OE API documentation', function() {

  var numContentTypes = 0;
  var contentTypes = [];
  var schemaPropertyMappings = {};
  var resourcesAnonCanAccess = [];

  beforeEach(function() {
    isAngularSite(false);
  });

  it('exists at the expected path and redirects to JSON data type', function() {
    browser.get(browser.params.url + '/api/doc');

    // should be automatically redirected to the JSON documentation
    expect(browser.getCurrentUrl()).toBe(browser.params.url + '/api/doc/json');

    // JSON data type should not be a link
    expect(element(by.cssContainingText('#content > p:first-of-type > a','JSON')).isPresent()).toBe(false);
  });

  it('documents the correct data types', function() {
    browser.get(browser.params.url + '/api/doc');

    // should be automatically redirected to the JSON documentation
    expect(element(by.css('#content > p:first-of-type')).getText()).toContain('Data types: JSON');
  });

  it('documents the correct content types whose schema types are listed in the documentation contents', function() {

    browser.get(browser.params.url + '/admin/structure/types');

    // store the schema.org mapping for each content type
    element.all(by.css('#content > table:nth-of-type(2) > tbody > tr')).count().then(function(count) {

      numContentTypes = count;
      var i = 0;
      var getContentTypes = function() {

        browser.get(browser.params.url + '/admin/structure/types');

        // go to content type edit form
        element(by.css('#content > table:nth-of-type(2) > tbody > tr:nth-of-type(' + (i + 1) + ') > td:nth-of-type(2) > a')).click();

        // click on Schema.org settings tab
        //element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Schema.org settings']")).click();

        // get schema.org type
        //element(by.id('edit-schemaorg-ui-type')).getAttribute('value').then(function(type) {
        //element(by.css('#edit-name-machine-name-suffix > span.machine-name-value')).getText().toUpperCase().then(function(type) {
        element(by.id('edit-name')).getAttribute('value').then(function(type) {
          // push to array
          contentTypes.push(type);

          // run this function again if not the last content type
          i = i + 1;
          if (i < numContentTypes) {
            getContentTypes();
          }

        });

      }
      getContentTypes();

      browser.get(browser.params.url + '/api/doc');
      // compare the contents of the documentation to the schema types defined in the CMS
      element.all(by.css('#content > nav > ul > li')).each(function(element, index) {
        element.getText().then(function(elementText) {
          expect(elementText).toBe(contentTypes[index]);
        });
      });

    });

  });

  it('displays the correct content for each resource', function() {

    // store the schema.org mappings for each field in each content type
    var i = 0;
    var viewContentTypeFields = function() {
      i = i + 1;

      browser.get(browser.params.url + '/admin/structure/types');

      // go to content type edit form
      element(by.css('#content > table:nth-of-type(2) > tbody > tr:nth-of-type(' + i + ') > td:nth-of-type(3) > a')).click();

      // get the number of editable fields
      element.all(by.cssContainingText('#field-overview tr > td:nth-of-type(7) > a', 'edit')).count().then(function(count) {

        var resourceName = contentTypes[i-1];
        schemaPropertyMappings[resourceName] = [];
        schemaPropertyMappings[resourceName]['name'] = {"description": ""};
        schemaPropertyMappings[resourceName]['url'] = {"description": ""};
        var numFields = count;
        var j = 0;
        var getSchemaPropertyMappings = function() {
          j = j + 1;

          // go to content type edit form
          browser.executeScript('window.scrollTo(0,0);').then(function () {
            
            element(by.xpath("(//table[@id='field-overview']//td/a[text()='edit'])[" + j + "]")).click();

            browser.wait(function () {
              return browser.isElementPresent(by.id('edit-schemaorg-ui-field-property'));
            }, 5000);
            // get schema.org property mapping
            element(by.id('edit-schemaorg-ui-field-property')).getAttribute('value').then(function(property) {

              // add property name to array
              schemaPropertyMappings[resourceName][property] = {};

              element(by.id('edit-instance-description')).getText().then(function(description) {

                // add field description to array
                schemaPropertyMappings[resourceName][property]["description"] = description;

                // run getSchemaPropertyMappings() again if not the last field
                if (j < numFields) {
                  browser.get(browser.params.url + '/admin/structure/types');

                  // go to content type edit form
                  element(by.css('#content > table:nth-of-type(2) > tbody > tr:nth-of-type(' + i + ') > td:nth-of-type(3) > a')).click();
                  getSchemaPropertyMappings();
                }
                // run viewContentTypeFields() again if not the last content type
                else if (i < numContentTypes) {
                  viewContentTypeFields();
                }

              });

            });

          });

        }
        getSchemaPropertyMappings();

      });

    }
    viewContentTypeFields();

    browser.get(browser.params.url + '/api/doc');
    // test that all the endpoints are displayed
    expect(element.all(by.css('.api-doc-resource')).count()).toBe(numContentTypes);
    element.all(by.css('.api-doc-resource')).each(function(item, index) {

      var resourceName = contentTypes[index];
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(1) > h3 > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '/<ID>.json');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(1)')).getText()).toBe('Returns a single ' + resourceName.toLowerCase() + ' item based on the <ID> passed in.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > h4:nth-of-type(1)')).getText()).toBe('Example call');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(2)')).getText()).toBe('This call will return the ' + resourceName.toLowerCase() + ' item whose ID is 12.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '/12.json');

      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(2) > h3 > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(1)')).getText()).toBe('Returns a list of ' + resourceName.toLowerCase() + ' items.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(1)')).getText()).toBe('Filtering');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(2)')).getText()).toBe('You can filter in the following way:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json?<propertyName>=<propertyValue>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(4) > em')).getText()).toBe('Note: Not all properties are available for filtering.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(2)')).getText()).toBe('Sorting');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(5)')).getText()).toBe('You can sort by passing the sort parameter:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(6) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json?sort=<propertyName>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(7)')).getText()).toBe('You can also specify the sort direction (ASC | DES):');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(8) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json?sort=<propertyName>&direction=DES');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(3)')).getText()).toBe('Pagination');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(9)')).getText()).toBe('You can specify an offset to exclude the first N results:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(10) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json?offset=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(11)')).getText()).toBe('You can also specify a limit to the number of results returned by the call:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(12) > code')).getText()).toBe('/api/' + resourceName.toLowerCase() + '.json?limit=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(13)')).getText()).toContain('There is a hard limit of');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(13)')).getText()).toContain('items per API call, which cannot be exceeded.');

      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(3) > h3')).getText()).toBe('Properties');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(3) > p:nth-of-type(1)')).getText()).toContain(resourceName.toLowerCase() + ' items contain some or all of the following properties:');
      element.all(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(3) > table:nth-of-type(2) > tbody > tr')).count(function(count) {
        // test that the number of properties displayed is the same as the number of
        // fields that have a schema.org mapping
        expect(count).toBe(Object.keys(schemaPropertyMappings[resourceName]).length);
      });
      element.all(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(3) > table:nth-of-type(2) > tbody > tr')).each(function(tableRow) {
        tableRow.element(by.css('td:nth-of-type(1)')).getText().then(function(propertyName) {
          // test the property name is correct
          expect(schemaPropertyMappings[resourceName].hasOwnProperty(propertyName)).toBe(true);
          tableRow.element(by.css('td:nth-of-type(2)')).getAttribute('innerHTML').then(function(propertyDescription) {
            // test the property description is correct (stripping HTML tags because they won't always match)
            expect(propertyDescription.replace(/(<([^>]+)>)/ig,"")).toContain(schemaPropertyMappings[resourceName][propertyName].description.replace(/(<([^>]+)>)/ig,""));
          });
        });
      });

    });
  });

  it('allows anonymous users to access to documentation and allows them access to see resources they have access to', function() {

    // logout and visit docs
    browser.get(browser.params.url + '/user/logout');
    browser.get(browser.params.url + '/api/doc');

    expect(element(by.css('h1.page-title')).getText()).toBe('API Documentation');

    // log back in
    dvr.get(browser.params.url + '/user/login');
    dvr.findElement(by.id('edit-name')).sendKeys(browser.params.user);
    dvr.findElement(by.id('edit-pass')).sendKeys(browser.params.pass);
    dvr.findElement(by.id('edit-submit')).click();
    // Login takes some time, so wait until it's done.
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });

    // if anon user doesn't have access to resources, grant them the permissions
    // save the default permissions so they can be reset
    dvr.get(browser.params.url + '/admin/people/permissions');
    var i = 0;
    var grantAnonResourcePermissions = function() {

      var resourceName = contentTypes[i];
      element(by.id('edit-1-access-resource-' + resourceName.toLowerCase())).isSelected().then(function(selected) {
        if (!selected) {
          element(by.id('edit-1-access-resource-' + resourceName.toLowerCase())).click();
        } else {
          resourcesAnonCanAccess.push(resourceName);
        }
        i = i + 1;
        if (i < contentTypes.length) {
          grantAnonResourcePermissions();
        }
      });

    };
    grantAnonResourcePermissions();

    // save permissions changes
    element(by.id('edit-submit')).click();

    // logout and visit docs
    browser.get(browser.params.url + '/user/logout');
    browser.get(browser.params.url + '/api/doc');

    // test that all the endpoints are displayed
    expect(element.all(by.css('.api-doc-resource')).count()).toBe(numContentTypes);

    // log back in
    dvr.get(browser.params.url + '/user/login');
    dvr.findElement(by.id('edit-name')).sendKeys(browser.params.user);
    dvr.findElement(by.id('edit-pass')).sendKeys(browser.params.pass);
    dvr.findElement(by.id('edit-submit')).click();
    // Login takes some time, so wait until it's done.
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });

  });

  it('doesn\'t allow anonymous users to access resources they don\'t have access to', function() {

    // if anon user has access to resources, revoke their permissions
    dvr.get(browser.params.url + '/admin/people/permissions');
    var j = 0;
    var revokeAnonResourcePermissions = function() {

      var resourceName = contentTypes[j];
      element(by.id('edit-1-access-resource-' + resourceName.toLowerCase())).isSelected().then(function(selected) {
        if (selected) {
          element(by.id('edit-1-access-resource-' + resourceName.toLowerCase())).click();
        }
        j = j + 1;
        if (j < contentTypes.length) {
          revokeAnonResourcePermissions();
        }
      });

    };
    revokeAnonResourcePermissions();

    // save permissions changes
    element(by.id('edit-submit')).click();

    // logout and visit docs
    browser.get(browser.params.url + '/user/logout');
    browser.get(browser.params.url + '/api/doc');

    // test that none of the endpoints are displayed
    expect(element.all(by.css('.api-doc-resource')).count()).toBe(0);

    // log back in
    dvr.get(browser.params.url + '/user/login');
    dvr.findElement(by.id('edit-name')).sendKeys(browser.params.user);
    dvr.findElement(by.id('edit-pass')).sendKeys(browser.params.pass);
    dvr.findElement(by.id('edit-submit')).click();
    // Login takes some time, so wait until it's done.
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });

  });

  it('resets anonymous users permissions', function() {

    // reset anon user's resource permissions to how they are by default
    dvr.get(browser.params.url + '/admin/people/permissions');
    var k = 0;
    var resetAnonResourcePermissions = function() {

      var resourceName = contentTypes[k];
      // if the resource name is in list of resources that anon user
      // can access, grant their permission to access that resource
      if (resourcesAnonCanAccess.indexOf(resourceName) > -1) {
        element(by.id('edit-1-access-resource-' + resourceName.toLowerCase())).click();
      }
      k = k + 1;
      if (k < contentTypes.length) {
        resetAnonResourcePermissions();
      }

    };
    resetAnonResourcePermissions();

    // save permissions changes
    element(by.id('edit-submit')).click();

  });

});
