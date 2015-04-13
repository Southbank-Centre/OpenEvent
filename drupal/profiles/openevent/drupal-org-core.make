; This file can be used for more control on building core.
core = 7.x
api = 2
projects[drupal][type] = core
projects[drupal][version] = "7.36"

; Core patches

; Old patches no more relevant
;projects[drupal][patch][] = http://www.drupal.org/files/string-offset-cast-1824820-2.patch