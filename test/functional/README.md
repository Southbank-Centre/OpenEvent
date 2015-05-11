# Protractor tests

The tests in this directory ensure that the Drupal CMS is correctly set up to allow content creation.

These tests do not create content for use by front-end tests. The front-end tests create their own content.

See the README.md in the *Southbank-Centre/SC-app/test/functional* directory for more information on using Protractor and running the tests.

## Running all tests

If you want to run all tests at once without defining a suite to run, they will probably fail. This is because of a slight incompatibility between Frisby and Protractor. This isn't a (known) way to get protractor to wait for frisby tests to complete before continuing with the next set of tests.

Rather than calling `protractor` directly on the command line to run all tests, you should use the `run_tests_synchronously.js` script. This will loop through each of the suites defined in `conf.js` and execute a protractor command against each of them in turn.

See the comments at the top of [`run_tests_synchronously.js`](https://github.com/Southbank-Centre/southbankcentre.org-CMS/blob/master/test/functional/run_suites_synchronously.js) for more information.

## Running in SauceLabs

Some tests require code conditional on whether they are being run through SauceLabs. To specify that this should be used, specify `--params.isSauceLabs 1` in the invocation.

You'll also need to set up some environment variables in your bash profile:

`SAUCE_USERNAME` - the username of the sauce labs account
`SAUCE_ACCESS_KEY` - the access key for the sauce labs account
`SAUCE_TUNNEL_ID` - a unique ID for your tunnel. E.g. "sams-super-tunnel"

You can then connect to saucelabs using [Sauce Connect](https://docs.saucelabs.com/reference/sauce-connect/), specifying your username, access key and tunnel id when you run the command by passing in the `-i` flag. For example:

`sc -u $SAUCE_USERNAME -k $SAUCE_ACCESS_KEY -i $SAUCE_TUNNEL_ID -f ~/sc_ready`