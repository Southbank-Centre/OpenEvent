'use strict';
/**
 * OE Components Spec
 */

var url = require('url');
var path = require('path');

describe('OE Components', function() {
  var contentTypeName = 'Component test';
  var contentTypeMachineName = 'component_test'; // Lowercase and underscore
  var contentTypePathName = 'component-test'; // Lowercase and hyphened

  // Drupal message area.
  var messages = element(by.css('.messages'));

  // Standard node elements.
  var titleField = element(by.id('edit-title')); // title field
  var nodeSubmit = element(by.id('edit-submit')); // submit button

  // Standard paragraph elements.
  var paragraphAddButton = element(by.id('edit-field-components-und-add-more-add-more')) // add paragraph type button
  var paragraphTypeDiv = by.id('field-components-values'); // paragraph type container
  var paragraphTitleDiv = element(by.id('edit-field-components-und-0-paragraph-bundle-title')); // paragraph type title container


  // Expected conditions
  // @see http://angular.github.io/protractor/#/api?view=ExpectedConditions
  var EC = protractor.ExpectedConditions;

  beforeEach(function(){
    isAngularSite(false);
  });

  // it('includes a Heading component', function(){
  //   browser.get(browser.params.url + '/admin/structure/paragraphs');
  //   //expect(element(by.xpath("//table/tbody/tr/td[contains(text(),'Heading')]")).isPresent()).toBe(true);
  //   expect(element(by.xpath("//table/tbody/tr[td='Heading (heading)']")).isPresent()).toBe(true);
  // });

  // it('includes a Long text component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Long text (long_text)']")).isPresent()).toBe(true);
  // });

  // it('includes a HTML component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='HTML (html)']")).isPresent()).toBe(true);
  // });

  // it('includes a Link component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Link (link)']")).isPresent()).toBe(true);
  // });

  // it('includes an Image component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Image (image)']")).isPresent()).toBe(true);
  // });

  // it('includes a Quote component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Quote (quote)']")).isPresent()).toBe(true);
  // });

  // it('includes a Youtube embed component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='YouTube embed (youtube_embed)']")).isPresent()).toBe(true);
  // });

  // it('includes a Flickr embed component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Flickr embed (flickr_embed)']")).isPresent()).toBe(true);
  // });

  // it('includes a SoundCloud embed component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='SoundCloud embed (soundcloud_embed)']")).isPresent()).toBe(true);
  // });

  // it('includes a Storify embed component', function(){
  //   expect(element(by.xpath("//table/tbody/tr[td='Storify embed (storify_embed)']")).isPresent()).toBe(true);
  // });

  // it('creates a new content type', function(){
  //   // Creates content type
  //   browser.get(browser.params.url + '/admin/structure/types/add');
  //   // Add name
  //   element(by.id('edit-name')).sendKeys(contentTypeName);
  //   // Disable revisions (this assumes diff module is enabled)
  //   element(by.cssContainingText('ul.vertical-tabs-list > li > a', 'Compare revisions')).click();
  //   element(by.id('edit-diff-enable-revisions-page-node')).isSelected().then(function(selected) {
  //     if (selected) {
  //         element(by.id('edit-diff-enable-revisions-page-node')).click();
  //     }
  //   });
  //   // All other settings as default
  //   // Save content type
  //   element(by.id('edit-submit')).click();

  //   // Check that the content type is listed (rather than looking for success message from Drupal)
  //   browser.get(browser.params.url + '/admin/structure/types');
  //   expect(element(by.id('content')).getText()).toContain(contentTypeName);
  // });

  // it('adds components fields to content type', function() {
  //   // Enable Field UI module
  //   browser.get(browser.params.url + '/admin/modules');
  //   global.fieldUiStatus = element(by.id('edit-modules-core-field-ui-enable')).isSelected();
  //   element(by.id('edit-modules-core-field-ui-enable')).isSelected().then(function(selected) {
  //     if (!selected) {
  //       element(by.id('edit-modules-core-field-ui-enable')).click();
  //     }
  //   });
  //   element(by.id('edit-submit')).click();

  //   // Add components field
  //   browser.get(browser.params.url + '/admin/structure/types/manage/' + contentTypePathName + '/fields');
  //   // Add new field
  //   element(by.id('edit-fields-add-existing-field-label')).sendKeys('Components');
  //   element(by.cssContainingText('#edit-fields-add-existing-field-field-name > option', 'Paragraphs: field_components (Components)')).click();
  //   element(by.cssContainingText('#edit-fields-add-existing-field-widget-type > option', 'Embedded')).click();
  //   element(by.id('edit-submit')).click();
  //   // Configure field
  //   browser.get(browser.params.url + '/admin/structure/types/manage/' + contentTypePathName + '/fields/field_components');
  //   // Todo: select all checkboxes automatically
  //   element(by.id('edit-instance-settings-allowed-bundles-table-flickr-embed-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-heading-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-html-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-image-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-link-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-long-text-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-page-element-spec-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-quote-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-soundcloud-embed-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-storify-embed-enabled')).click();
  //   element(by.id('edit-instance-settings-allowed-bundles-table-youtube-embed-enabled')).click();
  //   element(by.cssContainingText('#edit-instance-settings-add-mode > option', 'Select List')).click();
  //   element(by.id('edit-submit')).click();
  // });

  // it('tests Heading component: creates a new node of the content type and add a paragraph to it', function() {
  //   // Todo: Limit the element creation to editor role
  //   browser.get(browser.params.url + '/node/add/' + contentTypePathName);
  //   expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create ' + contentTypeName);

  //   // Heading paragraph
  //   element(by.cssContainingText('#edit-field-components-und-add-more-type > option', 'Heading')).click();
  //   element(by.id('edit-field-components-und-add-more-add-more')).click();
  //   browser.wait(function() {
  //     return browser.isElementPresent(by.id('field-components-values'));
  //   }, 5000);
  //   expect(element(by.id('edit-field-components-und-0-paragraph-bundle-title')).getText()).toContain('Paragraph type: Heading');
  //   browser.wait(function() {
  //     return browser.isElementPresent(by.id('edit-field-components-und-0-field-heading-level-und'));
  //   }, 5000);

  //   // Submit without required fields
  //   element(by.id('edit-submit')).click();
  //   expect(element(by.css('.messages')).getText()).toContain('Title field is required.');
  //   expect(element(by.css('.messages')).getText()).toContain('Heading field is required.');

  //   // Fill in required fields
  //   element(by.id('edit-title')).sendKeys('Test content');
  //   element(by.css('#edit-field-components-und-0-field-heading-level-und > .form-item-field-components-und-0-field-heading-level-und:nth-of-type(4) > input')).click();
  //   element(by.id('edit-field-components-und-0-field-heading-und-0-value')).sendKeys('This is a heading');
  //   // Submit the node and check for successful creation message
  //   element(by.id('edit-submit')).click();
  //   expect(element(by.css('.messages')).getText()).toContain(contentTypeName + ' Test content has been created.');
  // });

  it('tests Flickr embed component: creates a new node of the content type and add a paragraph to it', function() {
    browser.get(browser.params.url + '/node/add/' + contentTypePathName);
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create ' + contentTypeName);

    // Paragraph elements
    var paragraphTypeFlickr = element(by.cssContainingText('#edit-field-components-und-add-more-type > option', 'Flickr embed'));
    var paragraphFlickrEmbedDiv = by.id('edit-field-components-und-0-field-embed-code');
    var paragraphCaptionDiv = by.id('edit-field-components-und-0-field-caption');
    
    // Node elements
    var nodeTitle = 'Test Flicker Embed';
    var flickrEmbedCodeField = element(by.id('edit-field-components-und-0-field-embed-code-und-0-value'));
    var flickrCaptionField = element(by.id('edit-field-components-und-0-field-caption-und-0-value'));;


    // Add a flickr paragraph type
    paragraphTypeFlickr.click();
    paragraphAddButton.click();
    browser.wait(function() {
      return browser.isElementPresent(paragraphTypeDiv);
    }, 5000);

    // Check paragraph type title and fields
    expect(paragraphTitleDiv.getText()).toContain('Paragraph type: Flickr embed');
    // code field
    browser.wait(function(){
      return browser.isElementPresent(paragraphFlickrEmbedDiv);
    }, 5000);
    // caprion field
    browser.wait(function(){
      return browser.isElementPresent(paragraphCaptionDiv);
    }, 5000);

    // Submit without required fields
    nodeSubmit.click();
    expect(messages.getText()).toContain('Title field is required.');
    expect(messages.getText()).toContain('Flickr embed code field is required.');

    // Submit required fields with not allowed values.
    titleField.sendKeys(nodeTitle);
    flickrEmbedCodeField.sendKeys('<a href="wwww.google.com">Not allowed</a>');
    nodeSubmit.click();
    expect(messages.getText()).toContain('The code pasted is not a valid Flickr embed fragment.');

    // Cleanup field for next assertion.
    titleField.clear();
    flickrEmbedCodeField.clear();

    // Submit fields with allowed values.
    titleField.sendKeys(nodeTitle);
    flickrEmbedCodeField.sendKeys('<iframe src="https://www.flickr.com/photos/jarnasen/17119952858/in/explore-2015-04-29/player/" width="75" height="75" frameborder="0" allowfullscreen webkitallowfullscreen mozallowfullscreen oallowfullscreen msallowfullscreen></iframe>');
    flickrCaptionField.sendKeys('This is test content.');
    nodeSubmit.click();
    expect(messages.getText()).toContain(contentTypeName + ' ' + nodeTitle + ' has been created.');
  });

  // it('tests HTML component: creates a new node of the content type and add a paragraph to it', function() {

  // browser.get(browser.params.url + '/node/add/' + contentTypePathName);
  //   expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create ' + contentTypeName);

  //   // Paragraph elements
  //   var paragraphTypeHTML = element(by.cssContainingText('#edit-field-components-und-add-more-type > option', 'HTML'));
  //   var paragraphHTMLHeadingDiv = by.id('edit-field-components-und-0-field-heading');
  //   var paragraphHTMLContentDiv = by.id('edit-field-components-und-0-field-html');
    
  //   // Node elements
  //   var nodeTitle = 'Test HTML component';
  //   var htmlHeadingField = element(by.id('edit-field-components-und-0-field-heading-und-0-value'));
  //   var htmlContentField = element(by.id('edit-field-components-und-0-field-html-und-0-value'));;

  //   // Submit without required fields.
  //   nodeSubmit.click();
  //   expect(messages.getText()).toContain('Title field is required.');
  //   expect(messages.getText()).toContain('HTML field is required.');

  // });

  //it('tests Image component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests Link component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests Long text component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests Quote component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests SoundCloud embed component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests Storify embed component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('tests YouTube embed component: creates a new node of the content type and add a paragraph to it', function() {});

  //it('deletes content created for the test', function() {});

  //it('deletes the content type created for the test', function() {
  // // Clean up actions (part of another test):
  // - Disable Field UI module (use fieldUiStatus)
  // - Delete content
  // - Delete content type

  //function CleanUp() {
  //  describe('Clean up', function () {
  //    it('can revert changes made in this spec', function () {
  //      // Delete content (fields deleted automatically)
  //      // <tbd>
  //      // Delete content type
  //      browser.get(browser.params.url + '/admin/structure/types/manage/contentTypePathName/delete');
  //      element(by.id('edit-submit')).click();
  //    });
  //  });
  //}
  // });

});
