'use strict';
/**
 * Style guide Spec
 */

describe('The Style Guide features of the CMS', function() {

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
    expect(paragraphTypes).toEqual(['heading', 'html', 'long_text', 'page_element_spec']);

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

    // add Long text paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--3 > option', 'Long text')).click();
    element(by.id('edit-field-components-und-add-more-add-more--3')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-2-field-text-und-0-value'));
    }, 5000);

    // fill in Long text paragraph
    element(by.id('edit-field-components-und-2-field-text-und-0-value')).sendKeys('Here is some long text <em>where some</em> HTML tags are allowed <div>but others are not</div> <script>EspeciallyNotScriptTags("sorry!");</script>');

    // add Page element spec paragraph
    element(by.cssContainingText('#edit-field-components-und-add-more-type--4 > option', 'Page element spec')).click();
    element(by.id('edit-field-components-und-add-more-add-more--4')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-3-field-description-und-0-value'));
    }, 5000);

    // fill in Page element spec paragraph
    element(by.id('edit-field-components-und-3-field-description-und-0-value')).sendKeys('There should only ever be one page title.');
    element(by.id('edit-field-components-und-3-field-html-und-0-value')).sendKeys('<h1>Page title</h1>');
    element(by.id('edit-field-components-und-3-field-css-properties-und-0-first')).sendKeys('font-family');
    element(by.id('edit-field-components-und-3-field-css-properties-und-0-second')).sendKeys('SC Akkurat');
    element(by.id('edit-field-components-und-3-field-css-properties-und-add-more')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-3-field-css-properties-und-1-first'));
    }, 5000);
    element(by.id('edit-field-components-und-3-field-css-properties-und-1-first')).sendKeys('font-size');
    element(by.id('edit-field-components-und-3-field-css-properties-und-1-second')).sendKeys('Mobile: 40px/40px; Desktop: 60px/60px');
    element(by.id('edit-field-components-und-3-field-css-properties-und-add-more--2')).click();
    browser.wait(function() {
      return browser.isElementPresent(by.id('edit-field-components-und-3-field-css-properties-und-2-first'));
    }, 5000);
    element(by.id('edit-field-components-und-3-field-css-properties-und-2-first')).sendKeys('text-spacing');
    element(by.id('edit-field-components-und-3-field-css-properties-und-2-second')).sendKeys('- 0.2');

    // publish
    dvr.executeScript('window.scrollTo(0,0);').then(function () {
      element(by.cssContainingText('ul.vertical-tabs-list > li > a', 'Publishing options')).click();
      dvr.findElement(by.id('edit-status')).click();

      // save
      element(by.id('edit-submit')).click();

      expect(element(by.id('messages')).getText()).toContain('Style guide page Typography has been created.');
    });

  });

  it('can edit a piece of Style Guide Page content as designer', function() {

    browser.get(browser.params.url + '/node/add/style-guide-page');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Style guide page');

    // add title
    element(by.id('edit-title')).sendKeys('Editable');

    // save
    element(by.id('edit-submit')).click();

    expect(element(by.id('messages')).getText()).toContain('Style guide page Editable has been created.');

    // edit
    element(by.cssContainingText('.tabs.primary > li > a', 'Edit')).click();
    element(by.id('edit-title')).sendKeys(' edited');

    // save
    element(by.id('edit-submit')).click();

    expect(element(by.id('messages')).getText()).toContain('Style guide page Editable edited has been updated.');

  });

  it('can delete a piece of Style Guide Page content as designer', function() {

    // edit
    element(by.cssContainingText('.tabs.primary > li > a', 'Edit')).click();

    // delete
    element(by.id('edit-delete')).click();
    element(by.id('edit-submit')).click();

    expect(element(by.id('messages')).getText()).toContain('Style guide page Editable edited has been deleted.');
  });

  it('can create a piece of Style Guide Chapter content as designer', function() {

    browser.get(browser.params.url + '/node/add/style-guide-chapter');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Create Style guide chapter');
    
  });

  it('can edit a piece of Style Guide Chapter content as designer', function() {
    
  });

  it('can delete a piece of Style Guide Chapter content as designer', function() {
    
  });

  it('outputs Style Guide Page node JSON in the expected format', function () {

  });

  it('outputs Style Guide Chapter node JSON in the expected format', function () {

  });

  it('can revert changes made in this spec', function () {
    // designer logout
    browser.get(browser.params.url + '/user/logout');
    dvr.get(browser.params.url + '/user/login');

    // log in as admin
    dvr.findElement(by.id('edit-name')).sendKeys('admin');
    dvr.findElement(by.id('edit-pass')).sendKeys('admin');
    dvr.findElement(by.id('edit-submit')).click();
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });
  
    // remove designer
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

  });

});