# Protractor tests

The tests in this directory ensure that the Drupal CMS is correctly set up to allow content creation.

These tests do not create content for use by front-end tests.

## Installation
To install protractor globally use:

    sudo npm install -g protractor

Verify it works:

    protractor --version

To run test locally webdriver-manager is used:

    sudo webdriver-manager update
    webdriver-manager start

Verify it works by visiting http://localhost:4444/wd/hub/static/resource/hub.html.

## Run protractor tests

To run protractor test two things are needed. A configuration file for protractor to use `conf.js` and a test specification. Tests are run with:

    protractor conf.js

### Command line arguments

The `conf.js` file used accepts a URL command line parameter. This is used to direct the test to different environments. Run the tests against a particular environment with:

	protractor conf.js --params.url 'http://example.org'

Do not use a trailing slash.

### Directory structure

A top level directory named `test` contains all tests.

The `conf.js` file is placed within the `functional` directory. All specs are placed within `functional` too grouped together in functional labeled directories (eg an `event` directory to group all tests for the Event content type.)

### SauceLabs

[SauceLabs](https://saucelabs.com/) is used to run automated tests against different browsers. The `conf.js` file already contains code to read login credentials for SauceLabs from the environment you are running the tests from. To add SauceLabs locally to a development machine you'll need to set up some environment variables in your bash profile:

	echo "export SAUCE_USERNAME=sauceUsername
	export SAUCE_ACCESS_KEY=sauceAccessKey" >> ~/.bash_profile &&
	source ~/.bash_profile

Substitute *sauceUsername* and *sauceAccessKey* with the correct values.

`SAUCE_USERNAME` - the username of the sauce labs account
`SAUCE_ACCESS_KEY` - the access key for the sauce labs account
`SAUCE_TUNNEL_ID` - a unique ID for your tunnel. E.g. "super-tunnel"

Some tests require code conditional on whether they are being run through SauceLabs. To specify that this should be used, specify `--params.isSauceLabs 1` in the invocation.

You can then connect to saucelabs using [Sauce Connect](https://docs.saucelabs.com/reference/sauce-connect/), specifying your username, access key and tunnel id when you run the command by passing in the `-i` flag. For example:

`sc -u $SAUCE_USERNAME -k $SAUCE_ACCESS_KEY -i $SAUCE_TUNNEL_ID -f ~/sc_ready`
