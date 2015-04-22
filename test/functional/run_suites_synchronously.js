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
