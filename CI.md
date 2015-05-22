# Continuous Integration

This code contains configuration for continuous integration using CircleCI.

## Overview

CircleCI is connected to this GitHub repository. When commits are made, CircleCI will check out the code, build it, and run any specified tests.

The exact process followed is specified in the root file *circle.yml*. This document deliberately does not describe it in detail, as the yml file is itself the best description of the process.

## Process details

### 1. Set up build environment

This is specified under the ***machine*** heading in *circle.yml*. Particular versions of software packages (e.g. PHP, Ruby) can be specified here, as well as setting up entries in the build server's hosts file.

### 2. Check out code

CircleCI will automatically check out the code from the GitHub repository that its project is connected to - in this case, *Southbank-Centre/OpenEvent.git*.

By default, CircleCI will watch for commits to any branch. However, it's possible to limit it to only watch for commits to branches with particular names (or matching particular patterns). To see which - if any - branches are being watched, look for the heading ***general***, subheading ***branches*** in *circle.yml*.

### 3. Set up software

This is specified under the ***dependencies*** heading in *circle.yml*. This is split into three subsections:

* **pre**: set up software dependencies necessary to build the system
* **override**: build the system (overriding CircleCI's default inferred build)
* **post**: any other setup actions necessary after the system is built

### 4. Run tests

Tests for the system will be written using [Protractor](http://angular.github.io/protractor/#/). Some API also require [Frisby.js](http://frisbyjs.com/) to test JSON responses. See */test/functional/README.md* in this repository for more details.

In order to run these tests against a CircleCI build server, it's necessary to connect to a service capable of providing WebDriverJS browser interaction. In this case, the project is using [SauceLabs](https://saucelabs.com]).

Connecting to SauceLabs (as specified under the ***test*** heading) creates a tunnel from SauceLabs' servers back to the CircleCI build server. Any web address that the build server is able to resolve is then accessible to SauceLabs (and hence the Protractor tests run through it): this is why the build configuration needs entries to the server's *hosts* file for the two Apache vhosts that it sets up.

## Requirements

### Required files

* **ci/api.vhost**: Apache vhost configuration for serving the API/back-end site
* **test/functional/conf.js**: Configuration file for Protractor tests on the API/back-end site

### Required environment variables

These are defined through CircleCI's control panel and referenced in *circle.yml*.

Credentials for connecting to SauceLabs for running Protractor tests:

* SAUCE_USERNAME
* SAUCE_ACCESS_KEY

## Overriding the settings

When working in a branch, you may wish to override the build settings (e.g. to add your branch to the list of those that CircleCI watches). To do this, simply edit *circle.yml* and push the changes to GitHub.

Be careful not to merge any branch-specific changes to the mainline code.
