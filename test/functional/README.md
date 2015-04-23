# Protractor tests

The tests in this directory ensure that the Drupal CMS is correctly set up to allow content creation.

These tests do not create content for use by front-end tests. The front-end tests create their own content.

See the README.md in the *Southbank-Centre/SC-app/test/functional* directory for more information on using Protractor and running the tests.

## Running all tests

If you want to run all tests at once without defining a suite to run, they will probably fail. This is because of a slight incompatibility between Frisby and Protractor. This isn't a (known) way to get protractor to wait for frisby tests to complete before continuing with the next set of tests.

Rather than calling `protractor` directly on the command line to run all tests, you should use the `run_tests_synchronously.js` script. This will loop through each of the suites defined in `conf.js` and execute a protractor command against each of them in turn.

See the comments at the top of [`run_tests_synchronously.js`](https://github.com/Southbank-Centre/southbankcentre.org-CMS/blob/master/test/functional/run_suites_synchronously.js) for more information.