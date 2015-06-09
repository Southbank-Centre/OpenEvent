'use strict';
/**
 * OE Permissions Spec
 */

var url = require('url');
var path = require('path');

describe('The default permissions of the OE CMS', function() {

  beforeEach(function(){
    isAngularSite(false);
  });


  // ANONYMOUS USER //

  // View unpublished content
  var permViewPublishedContentAnon = element(by.id('edit-1-access-content'));

  // Access RESTws endpoints
  var permAccessResourceNodeAnon = element(by.id('edit-1-access-resource-node'));
  var permAccessResourceRelationAnon = element(by.id('edit-1-access-resource-relation'));
  var permAccessResourceFileAnon = element(by.id('edit-1-access-resource-file'));
  var permAccessResourceTaxTermAnon = element(by.id('edit-1-access-resource-taxonomy-term'));
  var permAccessResourceTaxVocabAnon = element(by.id('edit-1-access-resource-taxonomy-vocabulary'));

  // Relations
  var permViewRelationsAnon = element(by.id('edit-1-access-relations'));

  var permRelationAddEndpointAccessAnon = element(by.id('edit-1-relation-add-endpoint-autocomplete-access'));


  // AUTHENTICATED USER //

  // View unpublished content
  var permViewPublishedContentAuth = element(by.id('edit-2-access-content'));

  // Access RESTws endpoints
  var permAccessResourceNodeAuth = element(by.id('edit-2-access-resource-node'));
  var permAccessResourceRelationAuth = element(by.id('edit-2-access-resource-relation'));
  var permAccessResourceFileAuth = element(by.id('edit-2-access-resource-file'));
  var permAccessResourceTaxTermAuth = element(by.id('edit-2-access-resource-taxonomy-term'));
  var permAccessResourceTaxVocabAuth = element(by.id('edit-2-access-resource-taxonomy-vocabulary'));

  // Relations
  var permViewRelationsAuth = element(by.id('edit-2-access-relations'));
  var permRelationAddEndpointAccessAuth = element(by.id('edit-2-relation-add-endpoint-autocomplete-access'));

  // Show text format tips
  var permShowFormatTipsAuth = element(by.id('edit-2-show-format-tips'));

  // Text formats
  var permFormatFilteredHtmlAuth = element(by.id('edit-2-use-text-format-filtered-html'));
  var permFormatFullHtmlAuth = element(by.id('edit-2-use-text-format-full-html'));

  // Content overview (backend)
  var permAccessContentOverviewAuth = element(by.id('edit-2-access-content-overview'));

  // View own unpublished content
  var permViewOwnUnpublishedContentAuth = element(by.id('edit-2-view-own-unpublished-content'));

  // Revisions
  var permViewRevisionsAuth = element(by.id('edit-2-view-revisions'));
  var permRevertRevisionsAuth = element(by.id('edit-2-revert-revisions'));
  var permDeleteRevisionsAuth = element(by.id('edit-2-delete-revisions'));

  // Admin
  var permViewAdminThemeAuth = element(by.id('edit-2-view-the-administration-theme'));
  var permAccessToolbarAuth = element(by.id('edit-2-access-toolbar'));

  
  // TESTS //

  it('should allow anonymous user to access the site', function() {

    browser.get(browser.params.url + '/admin/people/permissions');
    
    expect(permViewPublishedContentAnon.isSelected()).toBe(true);
    expect(permAccessResourceNodeAnon.isSelected()).toBe(true);
    expect(permAccessResourceRelationAnon.isSelected()).toBe(true);
    expect(permAccessResourceFileAnon.isSelected()).toBe(true);
    expect(permAccessResourceTaxTermAnon.isSelected()).toBe(true);
    expect(permAccessResourceTaxVocabAnon.isSelected()).toBe(true);

    expect(permViewRelationsAnon.isSelected()).toBe(true);
    expect(permRelationAddEndpointAccessAnon.isSelected()).toBe(true);

  });

  it('should allow authenticated users to edit and add content to the site', function() {
    
    expect(permShowFormatTipsAuth.isSelected()).toBe(true);
    expect(permFormatFilteredHtmlAuth.isSelected()).toBe(true);
    expect(permFormatFullHtmlAuth.isSelected()).toBe(true);
    expect(permAccessContentOverviewAuth.isSelected()).toBe(true);
    expect(permViewPublishedContentAuth.isSelected()).toBe(true);

    expect(permAccessResourceNodeAuth.isSelected()).toBe(true);
    expect(permAccessResourceRelationAuth.isSelected()).toBe(true);
    expect(permAccessResourceFileAuth.isSelected()).toBe(true);
    expect(permAccessResourceTaxTermAuth.isSelected()).toBe(true);
    expect(permAccessResourceTaxVocabAuth.isSelected()).toBe(true);

    expect(permViewRelationsAuth.isSelected()).toBe(true);
    expect(permRelationAddEndpointAccessAuth.isSelected()).toBe(true);

    expect(permViewOwnUnpublishedContentAuth.isSelected()).toBe(true);

    expect(permViewRevisionsAuth.isSelected()).toBe(true);
    expect(permRevertRevisionsAuth.isSelected()).toBe(true);
    expect(permDeleteRevisionsAuth.isSelected()).toBe(true);

    expect(permViewAdminThemeAuth.isSelected()).toBe(true);
    expect(permAccessToolbarAuth.isSelected()).toBe(true);

  });

});
