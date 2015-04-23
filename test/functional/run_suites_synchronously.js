/**
 * run_suites_synchronously
 *
 * This script helps get round a problem with using protractor and frisby.js
 * If you run all tests in one go using protractor, there isn't a way for protractor
 * to wait for the frisby responses before starting the next test.
 * Therefore we need to run each test synchronously if we want to run them all.
 * This script loops through all of the suites defined in the protractor config
 * and runs them one by one.
 *
 * The script takes any arguments passed in and applies them to each protractor call.
 * This makes it possible to define protractor config (such as params.url) when calling this script.
 *
 * Usage:
 * $ node run_suites_synchronously [--protractor-param-name] ['protractor-param-value']
 */

var protractorConfig = require('./conf');
var child = require('child_process');

// get command line args
var args = process.argv;

// remove 1st and 2nd items
args.shift();
args.shift();

// join remaining args
argsString = args.join(' ');
 
// loop through the suites defined in protractor config
Object.keys(protractorConfig.config.suites).forEach(function(suite) {

  // run protractor against the current suite with the args passed in
  var testResult = child.execSync("protractor conf.js " + argsString + " --suite " + suite);

  // output the child process to stdout once complete
  process.stdout.write(testResult);

});
