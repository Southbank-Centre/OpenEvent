'use strict';
/**
 * Menu API Spec
 */

var url = require('url');
var path = require('path');

describe('The Menu API features of the CMS', function() {

  var parentMlid;
  var childMlid;

  beforeEach(function(){
    isAngularSite(false);
  });

  it('should allow a menu to be created with a "firstchild" item', function() {

    browser.get(browser.params.url + '/admin/structure/menu/add');
    expect(element(by.css('.page-title')).getText()).toContain('Menus');

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

    expect(element(by.id('console')).getText()).toContain('Your configuration has been saved.');

    // go back and edit link so we can get mlid
    element(by.cssContainingText("#menu-overview > tbody > tr:first-of-type > .menu-operations > a", "edit")).click();

    // store mlid of event just created
    browser.getCurrentUrl().then(function(currentUrl) {
      var currentUrlObj = url.parse(currentUrl);
      var currentUrlPath = currentUrlObj.pathname.split(path.sep);
      parentMlid = currentUrlPath[currentUrlPath.length-2];

      // add child link
      browser.get(browser.params.url + '/admin/structure/menu/manage/menu-a-test-menu/add');
      element(by.id('edit-link-title')).sendKeys('A child menu link');
      element(by.id('edit-link-path')).sendKeys('http://www.google.com');
      element(by.id('edit-description')).sendKeys('Child menu link description');
      element(by.cssContainingText('#edit-parent > option', 'A parent menu link')).click();
      element(by.xpath('//select[@id="edit-weight"]/option[@value="0"]')).click();
      element(by.id('edit-submit')).click();

      expect(element(by.id('console')).getText()).toContain('Your configuration has been saved.');

      // go back and edit link so we can get mlid
      element(by.cssContainingText("#menu-overview > tbody > tr:nth-of-type(2) > .menu-operations > a", "edit")).click();

      // store mlid of event just created
      browser.getCurrentUrl().then(function(currentUrl) {
        var currentUrlObj = url.parse(currentUrl);
        var currentUrlPath = currentUrlObj.pathname.split(path.sep);
        childMlid = currentUrlPath[currentUrlPath.length-2];
      });
    });

  });

  it('should allow any menu to be accessed by anyone as JSON through an endpoint', function() {

    var parentPropertyName = "50000 A parent menu link " + parentMlid;
    var childPropertyName = "50000 A child menu link " + childMlid;

    var childItemJSON = {};
    childItemJSON[childPropertyName] = {
      "link": {
        "menu_name": 'menu-a-test-menu',
        "mlid": childMlid,
        "plid": parentMlid,
        "link_path": 'http://www.google.com',
        "router_path": '',
        "link_title": 'A child menu link',
        "options": {
          "attributes": {
            "title": 'Child menu link description'
          }
        },
        "module": 'menu',
        "hidden": '0',
        "external": '1',
        "has_children": '0',
        "weight": '0',
        "depth": '2',
        "title": 'A child menu link',
        "access": 1,
        "href": 'http://www.google.com'
      },
      "below": []
    };

    var parentItemJSON = {};
    parentItemJSON[parentPropertyName] = {
      "link": {
        "menu_name": 'menu-a-test-menu',
        "mlid": parentMlid,
        "plid": '0',
        "link_path": '<firstchild>',
        "router_path": '<firstchild>',
        "link_title": 'A parent menu link',
        "options": {
          "attributes": {
            "title": 'Parent menu link description'
          }
        },
        "has_children": '1',
        "hidden": '0',
        "external": '0',
        "weight": '0',
        "depth": '1',
        "title": 'A parent menu link',
        "href": 'http://www.google.com',
        "access": true
      },
      "below": childItemJSON
    };

    // get JSON from menu API
    frisby.create('Get JSON for menu created in the previous test')
      .get(browser.params.url + '/api/menu/menu-a-test-menu')
      .expectStatus(200)
      .expectHeaderContains('content-type', 'application/json')
      .expectJSON(parentItemJSON)
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