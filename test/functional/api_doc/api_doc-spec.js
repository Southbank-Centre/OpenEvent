'use strict';
/**
 * OE API Documentation Spec
 */

describe('OE API documentation', function() {

  var numContentTypes = 0;
  var schemaTypes = [];
  var schemaPropertyMappings = {};

  beforeEach(function() {
    isAngularSite(false);
  });

  it('exists at the expected path and redirects to JSON data type', function() {
    browser.get(browser.params.url + '/api/doc');

    // should be automatically redirected to the JSON documentation
    expect(browser.getCurrentUrl()).toBe(browser.params.url + '/api/doc/json');

    // JSON data type should not be a link but others should be
    expect(element(by.cssContainingText('#content > p:first-of-type > a','JSON')).isPresent()).toBe(false);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','XML')).isPresent()).toBe(true);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','RDF')).isPresent()).toBe(true);
  });

  it('documents the correct data types', function() {
    browser.get(browser.params.url + '/api/doc');

    // should be automatically redirected to the JSON documentation
    expect(element(by.css('#content > p:first-of-type')).getText()).toContain('Data types: JSON | XML | RDF');
  });

  it('documents the correct content types whose schema types are listed in the documentation contents', function() {

    browser.get(browser.params.url + '/admin/structure/types');

    // store the schema.org mapping for each content type
    element.all(by.css('#content > table:nth-of-type(2) > tbody > tr')).count().then(function(count) {

      numContentTypes = count;
      var i = 0;
      var getSchemaTypes = function() {

        browser.get(browser.params.url + '/admin/structure/types');

        // go to content type edit form
        element(by.css('#content > table:nth-of-type(2) > tbody > tr:nth-of-type(' + (i + 1) + ') > td:nth-of-type(2) > a')).click();

        // click on Schema.org settings tab
        element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Schema.org settings']")).click();

        // get schema.org type
        element(by.id('edit-schemaorg-ui-type')).getAttribute('value').then(function(type) {
          // push to array
          schemaTypes.push(type);

          // run this function again if not the last content type
          i = i + 1;
          if (i < numContentTypes) {
            getSchemaTypes();
          }

        });

      }
      getSchemaTypes();

      browser.get(browser.params.url + '/api/doc');
      // compare the contents of the documentation to the schema types defined in the CMS
      element.all(by.css('#content > nav > ul > li')).each(function(element, index) {
        element.getText().then(function(elementText) {
          expect(elementText).toBe(schemaTypes[index]);
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

        var resourceName = schemaTypes[i-1];
        schemaPropertyMappings[resourceName] = [];
        var numFields = count;
        var j = 0;
        var getSchemaPropertyMappings = function() {
          j = j + 1;

          // go to content type edit form
          element(by.xpath("(//table[@id='field-overview']//td/a[text()='edit'])[" + j + "]")).click();
          
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

        }
        getSchemaPropertyMappings();

      });

    }
    viewContentTypeFields();

    browser.get(browser.params.url + '/api/doc');

    element.all(by.css('.api-doc-resource')).each(function(item, index) {

      var resourceName = schemaTypes[index];
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(1) > h3 > code')).getText()).toBe('/api/' + resourceName + '/<ID>.json');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(1)')).getText()).toBe('Returns a single ' + resourceName + ' item based on the <ID> passed in.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > h4:nth-of-type(1)')).getText()).toBe('Example call');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(2)')).getText()).toBe('This call will return the ' + resourceName + ' item whose ID is 12.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '/12.json');

      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(2) > h3 > code')).getText()).toBe('/api/' + resourceName + '.json');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(1)')).getText()).toBe('Returns a list of ' + resourceName + ' items.');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(1)')).getText()).toBe('Filtering');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(2)')).getText()).toBe('You can filter on any of properties listed below, in the following way:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '.json?<propertyName>=<propertyValue>');
      element.all(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > table:nth-of-type(2) > tbody > tr')).count(function(count) {
        // test that the number of properties displayed is the same as the number of
        // fields that have a schema.org mapping
        expect(count).toBe(Object.keys(schemaPropertyMappings[resourceName]).length);
      });
      element.all(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > table:nth-of-type(2) > tbody > tr')).each(function(tableRow) {
        tableRow.element(by.css('td:nth-of-type(1)')).getText().then(function(propertyName) {
          // test the property name is correct
          expect(schemaPropertyMappings[resourceName].hasOwnProperty(propertyName)).toBe(true);
          tableRow.element(by.css('td:nth-of-type(2)')).getAttribute('innerHTML').then(function(propertyDescription) {
            // test the property description is correct (stripping HTML tags because they won't always match)
            expect(propertyDescription.replace(/(<([^>]+)>)/ig,"")).toContain(schemaPropertyMappings[resourceName][propertyName].description.replace(/(<([^>]+)>)/ig,""));
          });
        });
      });
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(2)')).getText()).toBe('Sorting');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(4)')).getText()).toBe('You can sort by passing the sort parameter:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(5) > code')).getText()).toBe('/api/' + resourceName + '.json?sort=<propertyName>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(6)')).getText()).toBe('You can also specify the sort direction (ASC | DES):');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(7) > code')).getText()).toBe('/api/' + resourceName + '.json?sort=<propertyName>&direction=DES');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > h4:nth-of-type(3)')).getText()).toBe('Pagination');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(8)')).getText()).toBe('You can specify an offset to exclude the first N results:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(9) > code')).getText()).toBe('/api/' + resourceName + '.json?offset=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(10)')).getText()).toBe('You can also specify a limit to the number of results returned by the call:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(11) > code')).getText()).toBe('/api/' + resourceName + '.json?limit=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(12)')).getText()).toContain('There is a hard limit of');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(12)')).getText()).toContain('items per API call, which cannot be exceeded.');


      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(3) > h3')).getText()).toBe('Permissions');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(3) > p:nth-of-type(1)')).getText()).toContain('The following roles have permission to access the ' + resourceName + ' resource:');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(3) > ul')).getText()).toContain('administrator');

    });
  });

  it('documents the correct endpoint suffixes for each data type', function() {

    // XML
    browser.get(browser.params.url + '/api/doc/xml');
    // XML data type should not be a link but others should be
    expect(element(by.cssContainingText('#content > p:first-of-type > a','XML')).isPresent()).toBe(false);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','JSON')).isPresent()).toBe(true);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','RDF')).isPresent()).toBe(true);
    element.all(by.css('.api-doc-resource')).each(function(item, index) {

      var resourceName = schemaTypes[index];
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(1) > h3 > code')).getText()).toBe('/api/' + resourceName + '/<ID>.xml');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '/12.xml');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(2) > h3 > code')).getText()).toBe('/api/' + resourceName + '.xml');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '.xml?<propertyName>=<propertyValue>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(5) > code')).getText()).toBe('/api/' + resourceName + '.xml?sort=<propertyName>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(7) > code')).getText()).toBe('/api/' + resourceName + '.xml?sort=<propertyName>&direction=DES');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(9) > code')).getText()).toBe('/api/' + resourceName + '.xml?offset=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(11) > code')).getText()).toBe('/api/' + resourceName + '.xml?limit=<N>');

    });

    // RDF
    browser.get(browser.params.url + '/api/doc/rdf');
    // RDF data type should not be a link but others should be
    expect(element(by.cssContainingText('#content > p:first-of-type > a','RDF')).isPresent()).toBe(false);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','JSON')).isPresent()).toBe(true);
    expect(element(by.cssContainingText('#content > p:first-of-type > a','XML')).isPresent()).toBe(true);
    element.all(by.css('.api-doc-resource')).each(function(item, index) {

      var resourceName = schemaTypes[index];
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(1) > h3 > code')).getText()).toBe('/api/' + resourceName + '/<ID>.rdf');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(1) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '/12.rdf');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dt:nth-of-type(2) > h3 > code')).getText()).toBe('/api/' + resourceName + '.rdf');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(3) > code')).getText()).toBe('/api/' + resourceName + '.rdf?<propertyName>=<propertyValue>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(5) > code')).getText()).toBe('/api/' + resourceName + '.rdf?sort=<propertyName>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(7) > code')).getText()).toBe('/api/' + resourceName + '.rdf?sort=<propertyName>&direction=DES');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(9) > code')).getText()).toBe('/api/' + resourceName + '.rdf?offset=<N>');
      expect(element(by.css('.api-doc-resource:nth-of-type(' + (index + 1) + ') + dl dd:nth-of-type(2) > p:nth-of-type(11) > code')).getText()).toBe('/api/' + resourceName + '.rdf?limit=<N>');

    });

  });

});
