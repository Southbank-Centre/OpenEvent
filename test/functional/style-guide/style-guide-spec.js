'use strict';
/**
 * Style guide Spec
 */

var url = require('url');
var path = require('path');

describe('The Style Guide features of the CMS', function() {

  var nid;
  var pathAlias;

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('can set up a user with the "designer" role', function() {
    browser.get(browser.params.url + '/admin/people/create');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('People');

    element(by.id('edit-name')).sendKeys('Elliot Hunter');
    element(by.id('edit-mail')).sendKeys('ehunter@example.com');
    element(by.id('edit-pass-pass1')).sendKeys('password');
    element(by.id('edit-pass-pass2')).sendKeys('password');
    element(by.cssContainingText('#edit-roles label', 'designer')).click();
    element(by.id('edit-submit')).click();

    // test successful save
    expect(element(by.id('console')).getText()).toContain('Created a new user account for Elliot Hunter.');

  });

  it('can allow content to be viewed by anyone', function() {
    browser.get(browser.params.url + '/admin/people/permissions');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('People');

    // Allow published content to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-content')).click();
    dvr.findElement(by.id('edit-2-access-content')).click();

    // Allow node API endpoints to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-resource-node')).click();
    dvr.findElement(by.id('edit-2-access-resource-node')).click();

    // Allow paragraphs_item API endpoints to be viewed by anyone
    dvr.findElement(by.id('edit-1-access-resource-paragraphs-item')).click();
    dvr.findElement(by.id('edit-2-access-resource-paragraphs-item')).click();

    dvr.findElement(by.id('edit-submit')).click();

  });

  it('can create a piece of Style Guide Page content as designer', function() {
    // admin logout
    browser.get(browser.params.url + '/user/logout');
    dvr.get(browser.params.url + '/user/login');

    // log in as designer
    dvr.findElement(by.id('edit-name')).sendKeys('Elliot Hunter');
    dvr.findElement(by.id('edit-pass')).sendKeys('password');
    dvr.findElement(by.id('edit-submit')).click();
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });

    expect(element(by.id('toolbar')).isPresent()).toBe(true);

    browser.get(browser.params.url + '/node/add/style-guide-page');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Style guide page');

    // add title
    element(by.id('edit-title')).sendKeys('Typography');

    // check paragraph types
    var paragraphTypes = element(by.id('edit-field-components-und-add-more-type')).all(by.tagName('option')).getAttribute('value');
    expect(paragraphTypes).toEqual(['heading', 'html', 'image', 'long_text', 'page_element_spec']);

    // add heading paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type > option', 'Heading')).click();
    element(by.id('edit-field-components-und-add-more-add-more')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('field-components-values'));
    }, 5000);
    expect(element(by.id('edit-field-components-und-0-paragraph-bundle-title')).getText()).toContain('Paragraph type: Heading');
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-0-field-heading-level-und'));
    }, 5000);

    // fill in heading paragraph
    element(by.css('#edit-field-components-und-0-field-heading-level-und > .form-item-field-components-und-0-field-heading-level-und:nth-of-type(4) > input')).click();
    element(by.id('edit-field-components-und-0-field-heading-und-0-value')).sendKeys('This is a heading');

    // add HTML paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--2 > option', 'HTML')).click();
    element(by.id('edit-field-components-und-add-more-add-more--2')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-1-field-html-und-0-value'));
    }, 5000);

    // fill in HTML paragraph
    element(by.id('edit-field-components-und-1-field-html-und-0-value')).sendKeys('<div><h1><strong>Various HTML</strong> elements <em>can be added here.</em></h1><script>ButNotJavaScript("sorry!");</script></div>');

    // add Image paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--3 > option', 'Image')).click();
    element(by.id('edit-field-components-und-add-more-add-more--3')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-2-field-image-und-0-upload'));
    }, 5000);

    // fill in Image paragraph
    // upload 'Image'
    var fileToUpload = 'test-img.jpg';
    var absolutePath = path.resolve(__dirname, fileToUpload);
    // workaround for current inability to upload images through SauceLabs from Protractor:
    // provide the path of an image which should always exist on a SauceLabs instance
    if (browser.params.isSauceLabs) {
      absolutePath = '/home/chef/job_assets/shot_0.png';
    }
    dvr.findElement(by.id('edit-field-components-und-2-field-image-und-0-upload')).sendKeys(absolutePath);
    dvr.findElement(by.id('edit-field-components-und-2-field-image-und-0-upload-button')).click();
    // wait until image has uploaded
    browser.wait(function() {
     return browser.isElementPresent($('#edit-field-components-und-2-field-image-und-0-alt'));
    }, 5000);
    $('#edit-field-components-und-2-field-image-und-0-alt').sendKeys('Test image ALT');
    $('#edit-field-components-und-2-field-image-und-0-title').sendKeys('Test image TITLE');

    // add Long text paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--4 > option', 'Long text')).click();
    element(by.id('edit-field-components-und-add-more-add-more--4')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-3-field-text-und-0-value'));
    }, 5000);

    // fill in Long text paragraph
    element(by.id('edit-field-components-und-3-field-text-und-0-value')).sendKeys('Here is some long text <em>where some</em> HTML tags are allowed <div>but others are not</div> <script>EspeciallyNotScriptTags("sorry!");</script>');

    // add Page element spec paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--5 > option', 'Page element spec')).click();
    element(by.id('edit-field-components-und-add-more-add-more--5')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-4-field-description-und-0-value'));
    }, 5000);

    // fill in Page element spec paragraph
    element(by.id('edit-field-components-und-4-field-description-und-0-value')).sendKeys('There should only ever be one page title.');
    element(by.id('edit-field-components-und-4-field-html-und-0-value')).sendKeys('<h1>Page title</h1>');
    element(by.id('edit-field-components-und-4-field-css-properties-und-0-first')).sendKeys('font-family');
    element(by.id('edit-field-components-und-4-field-css-properties-und-0-second')).sendKeys('SC Akkurat');
    element(by.id('edit-field-components-und-4-field-css-properties-und-add-more')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-4-field-css-properties-und-1-first'));
    }, 5000);
    element(by.id('edit-field-components-und-4-field-css-properties-und-1-first')).sendKeys('font-size');
    element(by.id('edit-field-components-und-4-field-css-properties-und-1-second')).sendKeys('Mobile: 40px/40px; Desktop: 60px/60px');
    element(by.id('edit-field-components-und-4-field-css-properties-und-add-more--2')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-4-field-css-properties-und-2-first'));
    }, 5000);
    element(by.id('edit-field-components-und-4-field-css-properties-und-2-first')).sendKeys('text-spacing');
    element(by.id('edit-field-components-und-4-field-css-properties-und-2-second')).sendKeys('- 0.2');

    // publish
    dvr.executeScript('window.scrollTo(0,0);').then(function () {
      element(by.cssContainingText('ul.vertical-tabs-list > li > a', 'Publishing options')).click();
      dvr.findElement(by.id('edit-status')).click();

      // add to style guide menu
      element(by.cssContainingText('ul.vertical-tabs-list > li > a', 'Menu settings')).click();
      element(by.id('edit-menu-enabled')).click();

      // save
      element(by.id('edit-submit')).click();

      expect(element(by.id('console')).getText()).toContain('Style guide page Typography has been created.');

      // go back to edit page
      element(by.xpath("//ul[@class='tabs primary']/li/a[text()='Edit']")).click();
      element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='URL path settings']")).click();
      element(by.id('edit-path-alias')).getAttribute('value').then(function(alias) {

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

  it('can edit a piece of Style Guide Page content as designer', function() {

    browser.get(browser.params.url + '/node/add/style-guide-page');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Style guide page');

    // add title
    element(by.id('edit-title')).sendKeys('Editable');

    // save
    element(by.id('edit-submit')).click();

    expect(element(by.id('console')).getText()).toContain('Style guide page Editable has been created.');

    // edit
    element(by.cssContainingText('.tabs.primary > li > a', 'Edit')).click();
    element(by.id('edit-title')).sendKeys(' edited');

    // save
    element(by.id('edit-submit')).click();

    expect(element(by.id('console')).getText()).toContain('Style guide page Editable edited has been updated.');

  });

  it('can delete a piece of Style Guide Page content as designer', function() {

    // edit
    element(by.cssContainingText('.tabs.primary > li > a', 'Edit')).click();

    // delete
    element(by.id('edit-delete')).click();
    element(by.id('edit-submit')).click();

    expect(element(by.id('console')).getText()).toContain('Style guide page Editable edited has been deleted.');
  });

  it('outputs Style Guide Page node JSON and Page Element Spec paragraph item JSON in the expected format', function () {

    frisby.create('Get JSON for Style Guide Page created in previous test')
      .get(browser.params.url + '/node.json?nid=' + nid)
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      .expectJSON('list.0', {
        "field_components": [
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/paragraphs_item/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "paragraphs_item"
          },
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/paragraphs_item/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "paragraphs_item"
          },
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/paragraphs_item/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "paragraphs_item"
          },
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/paragraphs_item/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "paragraphs_item"
          },
          {
            "uri": function(val) { expect(val).toContain(browser.params.url + "/paragraphs_item/"); },
            "id": function(val) {
              expect(val).toBeDefined();
              expect(isNaN(parseInt(val, 10))).toBe(false);
            },
            "resource": "paragraphs_item"
          }
        ],
        "cer": {
          "lineage": "node:style_guide_page:",
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
        "type": "style_guide_page",
        "title": "Typography",
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
      }).afterJSON(function(styleGuidePage) {

        // id of Page Element Spec paragraph item
        var itemId = styleGuidePage.list[0].field_components[4].id;

        // get Page Element Spec paragraph item JSON
        frisby.create('Get JSON for Page Element Spec created in Style Guide Page previous test')
          .get(browser.params.url + '/paragraphs_item.json?item_id=' + itemId)
          .expectStatus(200)
          .expectHeaderContains('content-type', 'application/json')
          .expectJSON('list.0', {
            "field_description": {
              "value": "<p>There should only ever be one page title.</p>\n",
              "format": "filtered_html"
            },
            "field_html": {
              "value": "<h1>Page title</h1>\n",
              "format": "full_html"
            },
            "field_css_properties": [
              {
                "first": "font-family",
                "second": "SC Akkurat"
              },
              {
                "first": "font-size",
                "second": "Mobile: 40px/40px; Desktop: 60px/60px"
              },
              {
                "first": "text-spacing",
                "second": "- 0.2"
              }
            ],
            "cer": {
              "lineage": "paragraphs_item:page_element_spec:",
              "depth": 0,
              "owner": {
                "uri": browser.params.url + "/paragraphs_item/" + itemId,
                "id": itemId,
                "resource": "paragraphs_item"
              },
              "original": {
                "uri": browser.params.url + "/paragraphs_item/" + itemId,
                "id": itemId,
                "resource": "paragraphs_item"
              }
            },
            "item_id": itemId,
            "revision_id": itemId,
            "bundle": "page_element_spec",
            "field_name": "field_components",
            "archived": "0",
            "url": browser.params.url + "/"
          })
          .after(CleanUp)
          .toss();

      })
      .toss();

      function CleanUp() {

        describe('Clean up', function() {

          it('can revert changes made in this spec', function () {
            // designer logout
            browser.get(browser.params.url + '/user/logout');

            // log in as admin
            dvr.get(browser.params.url + '/user/login');
            dvr.findElement(by.id('edit-name')).sendKeys(browser.params.user);
            dvr.findElement(by.id('edit-pass')).sendKeys(browser.params.pass);
            dvr.findElement(by.id('edit-submit')).click();
            dvr.wait(function() {
              return dvr.getCurrentUrl().then(function(url) {
                return /user/.test(url);
              });
            });
          
            // remove designer and their content
            browser.get(browser.params.url + '/admin/people');
            element(by.cssContainingText('#user-admin-account > div > table:nth-of-type(2) td > a', 'Elliot Hunter')).click();
            element(by.cssContainingText('.tabs.primary > li > a', 'Edit')).click();
            element(by.id('edit-cancel')).click();
            element(by.css('#edit-user-cancel-method > .form-item-user-cancel-method:nth-of-type(4) > input')).click();
            element(by.id('edit-submit')).click();
            browser.wait(function() {
              return browser.isElementPresent(by.id('console'));
            }, 5000);
            expect(element(by.id('console')).getText()).toContain('Elliot Hunter has been deleted.');

            // reset permissions
            browser.get(browser.params.url + '/admin/people/permissions');
            dvr.findElement(by.id('edit-1-access-content')).click();
            dvr.findElement(by.id('edit-2-access-content')).click();
            dvr.findElement(by.id('edit-1-access-resource-node')).click();
            dvr.findElement(by.id('edit-2-access-resource-node')).click();
            dvr.findElement(by.id('edit-1-access-resource-paragraphs-item')).click();
            dvr.findElement(by.id('edit-2-access-resource-paragraphs-item')).click();
            dvr.findElement(by.id('edit-submit')).click();

          });

        });

      }

  });

});
