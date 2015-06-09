'use strict';
/**
 * Person Spec
 */

var url = require('url');
var path = require('path');
var eid = [];
var nid;
var completeNid;

describe('The Person features of the CMS', function() {

  // Page elements
  var pageTitle = element(by.css('.page-title'));
  var save = element(by.id('edit-submit'));
  var optionsPublished = element(by.id('edit-status'));
  var del = element(by.id('edit-delete'));
  var messages = element(by.css('.messages')); // How do we distinguish multiple messages?

  // Tab Main
  var tabMain = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']"));

  // Main fields
  // @TODO add a rand to get one of these
  var personNamePrefix = element(by.cssContainingText('#edit-field-person-name-prefix-und > option', 'Sir'));
  var personGivenName = element(by.id('edit-field-person-name-given-und-0-value'));
  var personMiddleName = element(by.id('edit-field-person-name-middle-und-0-value'));
  var personFamilyName = element(by.id('edit-field-person-name-family-und-0-value'));
  var personNameSuffix = element(by.id('edit-field-person-name-suffix-und-0-value'));
  var personAlias = element(by.id('edit-field-person-name-alias-und-0-value'));
  var bioDescription = element(by.id('edit-field-description-und-0-value'));

  // Tab Images
  var tabBio = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Images']"));
  var bioImage = element(by.id('edit-field-image-und-0-upload'));
  var bioImageUpload   = element(by.id('edit-field-image-und-0-upload-button'));

  // Other tabs
  var tabExtra = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Extra details']"));
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));

  // Extra details fields
  var extraJobTitle = element(by.id('edit-field-person-job-und-0-value'));
  var extraAwards = element(by.id('edit-field-person-awards-und-0-value'));
  var extraAwardsAdd = element(by.id('edit-field-person-awards-und-add-more'));
  var extraLinkTitle = element(by.id('edit-field-person-urls-und-0-title'));
  var extraLinkUrl = element(by.id('edit-field-person-urls-und-0-url'));
  var extraLinkAdd = element(by.id('edit-field-person-urls-und-add-more'));

  // Tab Events
  var tabEvents = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Events']"));

  // Event fields
  var eventRelation = element(by.id('edit-field-person-events-und-0-relation-options-targets-target-2'));
  var eventRelationAdd = element(by.id('edit-field-person-events-und-add-more'));

	beforeEach(function(){
    isAngularSite(false);
  });


  it('can create, edit and delete a person', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personNamePrefix.click();
    personGivenName.sendKeys('Jon');
    personFamilyName.sendKeys('Snow');
    personNameSuffix.sendKeys('Commander');
    personAlias.sendKeys('Lord Commander of the night\'s watch');

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person Jon Snow has been created.');

    // Check if it can edit the node.
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    // Clear the contents of Alias field.
    personNameSuffix.clear();
    save.click();

    // The fields that were deleted.
    var aliasFieldLabel = element(by.css('.field-name-field-person-name-alias field-label'));
    var aliasFieldItem = element(by.css('field-name-field-person-name-alias field-items'));

    // Expect deleted fields not to be there.
    expect(aliasFieldLabel.isPresent()).not.toBe(true);
    expect(aliasFieldItem.isPresent()).not.toBe(true);

    // Delete the node (edit first, click delete and then confirm deletion)
    edit.click();
    del.click();
    save.click();
    expect(messages.getText()).toContain('Person Jon Snow has been deleted.');

  });

  // What are invalid fields? The fields are limited in length and will not accept longer strings.
  it('can not save person with invalid fields', function() {
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personNamePrefix.click();
    personGivenName.sendKeys('Tyrion');
    personFamilyName.sendKeys('Lannister');

    // Test link without URL
    tabExtra.click();
    extraLinkTitle.sendKeys('Tywin');
    save.click();
    expect(messages.getText()).toContain('You cannot enter a title without a link url.');

    // Test link with malformed URL
    tabExtra.click();
    var wrongUrl = [
      'htt://en.wikipedia.org/wiki/Tyrion_Lannister',
      'http:/en.wikipedia.org/wiki/Tyrion_Lannister',
      'http//en.wikipedia.org/wiki/Tyrion_Lannister',
      'http://en.wikipedia/wiki/Tyrion_Lannister'
    ];
    extraLinkTitle.sendKeys('Wikipedia (wrong)');
    var i = 0;
    while (wrongUrl[i]) {
      extraLinkUrl.clear();
      extraLinkUrl.sendKeys(wrongUrl[i]);
      save.click();
      expect(messages.getText()).toContain('The value ' + wrongUrl[i] + ' provided for Person urls is not a valid URL.');
      i++;
    }

    // Add good URL
    extraLinkTitle.clear();
    extraLinkTitle.sendKeys('Wikipedia');
    extraLinkUrl.clear();
    extraLinkUrl.sendKeys('http://en.wikipedia.org/wiki/Tyrion_Lannister');

    // Publish it
    tabOptions.click();
    optionsPublished.isSelected().then(function(selected) {
      if (!selected) {
        optionsPublished.click();
      }
    });

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person Tyrion Lannister has been created.');

  });

  it('sets relationship to Event', function() {
    // Person
    var name = 'Daenerys';
    var surname = 'Targaryen';

    // Get timestamp.
    var time = new Date().getTime();

    // Add event
    var eventName = 'Get to Kings Landing (' + time + ')';
    addEvent(eventName);

    // Add person
    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');
    personGivenName.sendKeys(name);
    personFamilyName.sendKeys(surname);

    // Add a relation between person and event
    var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
    tabEvents.click();
    eventRelation.sendKeys(eventName);
    browser.wait(function() {
      return browser.isElementPresent(by.css('#autocomplete li div'));
    }, 5000);
    autocomplete.click();

    // Publish it
    tabOptions.click();
    optionsPublished.isSelected().then(function(selected) {
      if (!selected) {
        optionsPublished.click();
      }
    });

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain(name + ' ' + surname + ' has been created.');

    // Get the nid for the next test
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    browser.getCurrentUrl().then(function(Url){
      var parts = Url.split('/');
      var size = parts.length;
      nid = parts[size-2];
    });

  });

  it('can create a complete person node', function() {
    var eventName = 'Battle of Waterloo';
    addEvent(eventName);

    browser.get(browser.params.url + '/node/add/person');
    expect(pageTitle.getText()).toContain('Create Person');

    // Fill in person details
    personNamePrefix.click();
    personGivenName.sendKeys('William');
    personMiddleName.sendKeys('S');
    personFamilyName.sendKeys('Preston');
    personNameSuffix.sendKeys('Esq.');
    personAlias.sendKeys('Bill');
    bioDescription.sendKeys('Co-founder and guitarist of the rock-group Wyld Stallyns');

    browser.executeScript('window.scrollTo(0,0);').then(function () {
      // Tab Biography and images
      tabBio.click();

      // upload 'Image'
      var fileToUpload = '../image/test-img.jpg';
      var absolutePath = path.resolve(__dirname, fileToUpload);
      if (browser.params.isSauceLabs) {
        absolutePath = '/home/chef/job_assets/shot_0.png';
      }
      bioImage.sendKeys(absolutePath);
      bioImageUpload.click();
      // wait until image has uploaded
      browser.wait(function() {
       return browser.isElementPresent($('#edit-field-image-und-0-alt'));
      }, 5000);
      $('#edit-field-image-und-0-alt').sendKeys('Test image ALT');
      $('#edit-field-image-und-0-title').sendKeys('Test image TITLE');
    });

    browser.executeScript('window.scrollTo(0,0);').then(function () {
      tabExtra.click();
      extraJobTitle.sendKeys('Guitarist in Wyld Stallyns');
      extraAwards.sendKeys('High school history class');
      extraAwardsAdd.click();
      extraLinkTitle.sendKeys('Socrates');
      extraLinkUrl.sendKeys('https://en.wikipedia.org/wiki/Socrates');
      extraLinkAdd.click();
    });

    browser.executeScript('window.scrollTo(0,0);').then(function () {
      // Add a relation between person and event
      tabEvents.click();
      var autocomplete = element(by.xpath("//div[@id='autocomplete']//li[1]/div"));
      eventRelation.sendKeys(eventName);
      browser.wait(function() {
        return browser.isElementPresent(by.css('#autocomplete li div'));
      }, 5000);
      autocomplete.click();
      eventRelationAdd.click();
    });

    browser.executeScript('window.scrollTo(0,0);').then(function () {
      // Publish it
      tabOptions.click();
      optionsPublished.isSelected().then(function(selected) {
        if (!selected) {
          optionsPublished.click();
        }
      });
    });

    // Save the node
    save.click();

    // Expectations
    expect(messages.getText()).toContain('Person William Preston has been created.');

    // Get the nid for the next test
    var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
    edit.click();

    browser.getCurrentUrl().then(function(Url){
      var parts = Url.split('/');
      var size = parts.length;
      completeNid = parts[size-2];
    });
  });

  /* API output tests */

  it('outputs Person node JSON in Schema.org format', function () {
    // get Person JSON from API and parse it
    browser.get(browser.params.url + '/api/person/' + nid + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);

       // string fields as input
       expect(json.name).toBe("Daenerys Targaryen");
       expect(json.description.length).toEqual(0);
       expect(json.jobTitle).toEqual(null);
       expect(json.familyName).toBe("Targaryen");
       expect(json.givenName).toBe("Daenerys");
       expect(json.alternateName).toEqual(null);
       expect(json.additionalName).toEqual(null);
       expect(json.honorificSuffix).toEqual(null);
       expect(json.sameAs).toEqual(null);

       // empty image & award fields
       expect(json.image.length).toEqual(0);
       expect(json.award.length).toEqual(0);

       // URL of this item should be predictable based on NID
       expect(json.url).toBe(browser.params.url + '/api/person/' + nid);

       expect(json.performerIn.length).toEqual(1);
       expect(json.performerIn[0]).toEqual(browser.params.url + "/api/event/" + eid[0]);
    });

    // test that the performers relation has been correctly added to the event
    browser.get(browser.params.url + '/api/event/' + eid[0] + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);
       expect(json.performers.length).toEqual(1);
       expect(json.performers[0]).toEqual(browser.params.url + "/api/person/" + nid);
    });
  });

  it('outputs complete Person node JSON in Schema.org format', function () {
    // get Person JSON from API and parse it
    browser.get(browser.params.url + '/api/person/' + completeNid + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);

       // check the properties which differ between the minimal/maximal person nodes
       expect(json.jobTitle).toEqual('Guitarist in Wyld Stallyns');
       expect(json.alternateName).toEqual('Bill');
       expect(json.additionalName).toEqual('S');
       expect(json.honorificPrefix).toEqual('Sir');
       expect(json.honorificSuffix).toEqual('Esq.');
       expect(json.sameAs.length).toEqual(1);
       expect(json.sameAs[0]).toEqual('https://en.wikipedia.org/wiki/Socrates');
       expect(json.award.length).toEqual(1);
       expect(json.award[0]).toEqual('High school history class');

       // set correct filename for checking image upload
       var imageName = 'test-img.jpg';
       if (browser.params.isSauceLabs) {
         imageName = 'shot_0.png';
       }

       // image uploaded & fields filled out as expected
       expect(json.image[0].contentUrl).toContain(browser.params.url);
       expect(json.image[0].contentUrl).toContain(imageName.split(".")[0]);
       expect(json.image[0].alternateName).toBe("Test image ALT");
       expect(json.image[0].caption).toBe("Test image TITLE");
    });

    // test that the performers relation has been correctly added to the complete person's event
    browser.get(browser.params.url + '/api/event/' + eid[1] + '.json');
    element(by.css('html')).getText().then(function(bodyText) {
       var json = JSON.parse(bodyText);
       expect(json.performers.length).toEqual(1);
       expect(json.performers[0]).toEqual(browser.params.url + "/api/person/" + completeNid);
    });
  });

  /* End of API output tests */


  /* API input tests */

  it('outputs people listing JSON and sorts by different fields', function () {

    /* familyName, givenName, name */
    var familyNameAsc = '?sort=familyName&direction=ASC';
    var familyNameDesc = '?sort=familyName&direction=DESC';
    var givenNameAsc = '?sort=givenName&direction=ASC';
    var givenNameDesc = '?sort=givenName&direction=DESC';
    var nameAsc = '?sort=name&direction=ASC';
    var nameDesc = '?sort=name&direction=DESC';

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + familyNameAsc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].familyName;
      var nameSecond = json.list[1].familyName;
      var nameThird = json.list[2].familyName;
      expect(nameFirst).toBe("Lannister");
      expect(nameSecond).toBe("Preston");
      expect(nameThird).toBe("Targaryen");
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + familyNameDesc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].familyName;
      var nameSecond = json.list[1].familyName;
      var nameThird = json.list[2].familyName;
      expect(nameFirst).toBe("Targaryen");
      expect(nameSecond).toBe("Preston");
      expect(nameThird).toBe("Lannister");
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + givenNameAsc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].givenName;
      var nameSecond = json.list[1].givenName;
      var nameThird = json.list[2].givenName;
      expect(nameFirst).toBe("Daenerys");
      expect(nameSecond).toBe("Tyrion");
      expect(nameThird).toBe("William");
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + givenNameDesc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].givenName;
      var nameSecond = json.list[1].givenName;
      var nameThird = json.list[2].givenName;
      expect(nameFirst).toBe("William");
      expect(nameSecond).toBe("Tyrion");
      expect(nameThird).toBe("Daenerys");
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + nameAsc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].name;
      var nameSecond = json.list[1].name;
      expect(nameFirst).toBe("Daenerys Targaryen");
      expect(nameSecond).toBe("Tyrion Lannister");
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + nameDesc);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var nameFirst = json.list[0].name;
      var nameSecond = json.list[1].name;
      var nameThird = json.list[2].name;
      expect(nameFirst).toBe("William Preston");
      expect(nameSecond).toBe("Tyrion Lannister");
      expect(nameThird).toBe("Daenerys Targaryen");
     });

  });

  it('outputs people listing JSON and filters by different fields', function () {

    /* Taxonomy term name */
    var honorificPrefixQuery = '?honorificPrefix=Sir';

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + honorificPrefixQuery);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var name = json.list[0].name;
      var honorificPrefix = json.list[0].honorificPrefix;
      expect(name).toBe("Tyrion Lannister");
      expect(honorificPrefix).toBe("Sir");
      expect(json.list.length).toBe(2);
     });

    /* name, givenName, familyName */
    var nameQuery = '?name=Tyrion%20Lannister';
    var givenNameQuery = '?givenName=Tyrion';
    var familyNameQuery = '?familyName=Targaryen';

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + nameQuery);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var name = json.list[0].name;
      expect(name).toBe("Tyrion Lannister");
      expect(json.list.length).toBe(1);
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + givenNameQuery);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var name = json.list[0].name;
      expect(name).toBe("Tyrion Lannister");
      expect(json.list.length).toBe(1);
     });

    // get events listing JSON from API and parse it
    browser.get(browser.params.url + '/api/person.json' + familyNameQuery);
    element(by.css('html')).getText().then(function(bodyText) {
      var json = JSON.parse(bodyText);
      var name = json.list[0].name;
      expect(name).toBe("Daenerys Targaryen");
      expect(json.list.length).toBe(1);
     });

  });

  /* End of API input tests */

  it('will take place after all tests have passed', function() {
    // These tests are destructive and can only be performed on clean/empty sites [!]
    // This cleanup function assumes that all content available is created by this test suite

    // CleanUp content
    // It deletes ALL content in the site
    browser.get(browser.params.url + '/admin/content');
    element(by.css('#node-admin-content > div > table.sticky-enabled.table-select-processed.tableheader-processed.sticky-table > thead > tr > th.select-all > input')).click();
    element(by.cssContainingText('#edit-operation > option', 'Delete selected content')).click();
    element(by.id('edit-submit--2')).click();
    element(by.id('edit-submit')).click();
  });

});

function addEvent(eventName) {

  // Create a supporting event
  browser.get(browser.params.url + '/node/add/event');
  expect(element(by.css('.page-title')).getText()).toContain('Create Event');

  element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Main']")).click();
  element(by.id('edit-title')).sendKeys(eventName);

  // Date and time
  element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Date and time']")).click();

  // start date/time
  element(by.id('edit-field-event-date-start-und-0-value-datepicker-popup-0')).sendKeys('15/04/2015');
  element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).click();
  element(by.id('edit-field-event-date-start-und-0-value-timeEntry-popup-1')).sendKeys('19:30');

  // end date/time
  element(by.id('edit-field-event-date-end-und-0-value-datepicker-popup-0')).sendKeys('23/04/2015');
  element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).click();
  element(by.id('edit-field-event-date-end-und-0-value-timeEntry-popup-1')).sendKeys('22:30');

  // duration
  element(by.id('edit-field-event-duration-und-0-value')).clear();

  // Publish it
  var tabOptions = element(by.xpath("//ul[@class='vertical-tabs-list']/li/a[strong='Publishing options']"));
  var optionsPublished = element(by.id('edit-status'));
  tabOptions.click();
  optionsPublished.isSelected().then(function(selected) {
    if (!selected) {
      optionsPublished.click();
    }
  });

  // save
  element(by.id('edit-submit')).click();

  // test successful save
  expect(element(by.id('console')).getText()).toContain('Event '+ eventName + ' has been created.');

  // Get the nid for the next test.
  var edit = element(by.xpath("//ul[@class='tabs primary']/li[2]"));
  edit.click();

  browser.getCurrentUrl().then(function(Url){
    var parts = Url.split('/');
    var size = parts.length;
    eid.push(parts[size-2]);
  });
}
