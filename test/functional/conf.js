
/**
 * Protractor connfiguration file.
 *
 * This file contain basic options to setup protractor testing with
 * SauceLabs integration.
 *
 * To explore all condfiguration options visit:
 * https://github.com/angular/protractor/blob/master/docs/referenceConf.js
 */

exports.config = {

  // Saucelabs credentials.
  sauceUser: process.env.SAUCE_USERNAME,
  sauceKey: process.env.SAUCE_ACCESS_KEY,

  // Tests to run
  specs: ['**/*.js'],

  suites: {
    base: ['base/*.js'],
    content_components: ['content-components/*.js']
  },

  // Single Browser
  // capability: [
  //   browserName: 'chrome',
  //   name: 'Testing with chrome',
  //   specs: [],
  // ]

  // Multiple Browsers
  multiCapabilities: [
    {
      browserName: 'chrome',
      name: 'Testing with chrome'
    },
  //  {
  //    browserName: 'firefox',
  //    name: 'Testing with firefox'
  //  }
  ],

  params: {
    url: ''
  },

  // Options to be passed to jasmine-node.
  jasmineNodeOpts: {
    // If true, print colors to the terminal.
    showColors: true,
    // Default time to wait in ms before a test fails.
    defaultTimeoutInterval: 30000
  },

  // function to run before the tests - logs the browser into the CMS
  onPrepare: function() {
    global.dvr = browser.driver;

    dvr.get(browser.params.url + '/user/login');

    dvr.findElement(by.id('edit-name')).sendKeys('admin');
    dvr.findElement(by.id('edit-pass')).sendKeys('admin');
    dvr.findElement(by.id('edit-submit')).click();

    // Login takes some time, so wait until it's done.
    dvr.wait(function() {
      return dvr.getCurrentUrl().then(function(url) {
        return /user/.test(url);
      });
    });

    // Testing on Angular site or not
    global.isAngularSite = function(flag){
      browser.ignoreSynchronization = !flag;
    };
  },

};
