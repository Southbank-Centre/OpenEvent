'use strict';
/**
 * WOW 'content page list' bugfixes spec
 */

describe('WOW CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('doesn\'t output links in the Content Page field (https://www.pivotaltracker.com/story/show/91024434)', function(){
    browser.get(browser.params.url + '/node/add/list-content-page');

    // click the 'Add another Promoted content page' button and wait for the new element to load
    element(by.name('field_content_page_list_add_more_add_more')).click();
    dvr.wait(function () {
        return dvr.isElementPresent(by.id("edit-field-content-page-list"));
    }, 5000);

    // type in the title of the page created in the content_page-spec.js test and wait for the autocomplete list to load
    dvr.findElement(by.xpath('//div[contains(@class, "field-name-field-content-page ")]//input[@type="text"]')).sendKeys('Protractor test content page');
    dvr.wait(function () {
        return dvr.isElementPresent(by.xpath("//div[@id=\"autocomplete\"]//li[1]//span[@class='field-content']"));
    }, 5000);

    // check that there's at least one item in the list, and that it doesn't contain a link
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']")).isPresent()).toBe(true);
    expect(element(by.xpath("//div[@id='autocomplete']//li[1]//span[@class='field-content']/a")).isPresent()).toBe(false);
  });

});
