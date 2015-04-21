'use strict';
/**
 * Menu API Spec
 */

describe('The Menu API features of the CMS', function() {

  beforeEach(function(){
    // don't wait for (non-existent) Angular to load
    return browser.ignoreSynchronization = true;
  });

  it('should allow a menu to be created with a "firstchild" item', function() {

    browser.get(browser.params.url + '/admin/structure/menu/add');
    expect(dvr.findElement(by.css('.page-title')).getText()).toContain('Menus');

    // fill in new menu fields
    element(by.id('edit-title')).sendKeys('A Test Menu');
    expect(element(by.css('#edit-title-machine-name-suffix > .machine-name-value')).getText()).toEqual('a-test-menu');
    element(by.id('edit-description')).sendKeys('Description for the test menu');

    //save
    element(by.id('edit-submit')).click();

    // add parent link
    browser.get(browser.params.url + '/admin/structure/menu/manage/menu-a-test-menu/add');
    element(by.id('edit-link-title')).sendKeys('A parent menu link');
    element(by.id('edit-link-path')).sendKeys('<firstchild>');
    element(by.id('edit-description')).sendKeys('Parent menu link description');
    element(by.cssContainingText('#edit-parent > option', '<A Test Menu>')).click();
    element(by.xpath('//select[@id="edit-weight"]/option[@value="0"]')).click();
    element(by.id('edit-submit')).click();

    // add child link
    browser.get(browser.params.url + '/admin/structure/menu/manage/menu-a-test-menu/add');
    element(by.id('edit-link-title')).sendKeys('A child menu link');
    element(by.id('edit-link-path')).sendKeys('http://www.google.com');
    element(by.id('edit-description')).sendKeys('Child menu link description');
    element(by.cssContainingText('#edit-parent > option', 'A parent menu link')).click();
    element(by.xpath('//select[@id="edit-weight"]/option[@value="0"]')).click();
    element(by.id('edit-submit')).click();

  });

  it('should allow any menu to be accessed by anyone as JSON through an endpoint', function() {

    var parentMlid;
    var childMlid;

    // get JSON from menu API
    frisby.create('Get JSON for menu created in the previous test')
      .get(browser.params.url + '/api/menu/menu-a-test-menu')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      .expectJSON([
        {
          "menu_name": "menu-a-test-menu",
          "mlid": function(val) {
            expect(val).toBeDefined();
            expect(isNaN(parseInt(val, 10))).toBe(false);
            parentMlid = val;
          },
          "plid": "0",
          "link_path": "<firstchild>",
          "router_path": "<firstchild>",
          "link_title": "A parent menu link",
          "options": {
            "attributes": {
              "title": "Parent menu link description"
            },
            "alter": true,
            "unaltered_hidden": 0
          },
          "module": "menu",
          "hidden": "0",
          "external": "0",
          "has_children": "1",
          "expanded": "0",
          "weight": "0",
          "depth": "1",
          "customized": "1",
          "p1": parentMlid,
          "p2": "0",
          "p3": "0",
          "p4": "0",
          "p5": "0",
          "p6": "0",
          "p7": "0",
          "p8": "0",
          "p9": "0",
          "updated": "0"
        },
        {
          "menu_name": "menu-a-test-menu",
          "mlid": function(val) {
            expect(val).toBeDefined();
            expect(isNaN(parseInt(val, 10))).toBe(false);
            childMlid = val;
          },
          "plid": parentMlid,
          "link_path": "http://www.google.com",
          "router_path": "",
          "link_title": "A child menu link",
          "options": {
            "attributes": {
              "title": "Child menu link description"
            }
          },
          "module": "menu",
          "hidden": "0",
          "external": "1",
          "has_children": "0",
          "expanded": "0",
          "weight": "0",
          "depth": "2",
          "customized": "1",
          "p1": parentMlid,
          "p2": childMlid,
          "p3": "0",
          "p4": "0",
          "p5": "0",
          "p6": "0",
          "p7": "0",
          "p8": "0",
          "p9": "0",
          "updated": "0"
        }
      ])
      .after(CleanUp)
      .toss();

    function CleanUp() {

      describe('Clean up', function() {

        it('can revert changes made in this spec', function () {

          // delete test menu
          browser.get(browser.params.url + '/admin/structure/menu/manage/menu-a-test-menu/delete');
          element(by.id('edit-submit')).click();


        });

      });

    }

  });

});