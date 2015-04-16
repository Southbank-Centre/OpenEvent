; Define required attributes
core = 7.x
api = 2

; Define required modules
;
; To define a specific module version (eg ctool 1.4) and place it in a
; specific directory use the following notation:
;   projects[ctools][version] = 1.4
;   projects[ctools][subdir] = contrib
;
; Versions can be:
;   - 1.4 for a module with 1.4 version number
;   - 2.0-beta3 for a beta release
;   - 1.x-dev for a development version (be carefull as it results in different code each time
;     it runs)
;
; Add patches with the following:
;   projects[ctools][patch][] = "http://drupal.org/files/issues/1023606-qid-to-name-6.patch"

; Contrib modules
projects[ctools][version] = 1.7
projects[date][version] = 2.8
projects[features][version] = 2.5
projects[color_field][version] = 1.7
projects[entityreference][version] = 1.1
projects[field_group][version] = 1.4
projects[field_validation][version] = 2.4
projects[filefield_sources][version] = 1.9
projects[link][version] = 1.3
projects[auto_entitylabel][version] = 1.3
projects[diff][version] = 3.2
projects[entity][version] = 1.6
projects[libraries][version] = 2.2
projects[pathauto][version] = 1.2
projects[restws][version] = 2.3
projects[shs][version] = 1.6
projects[strongarm][version] = 2.0
projects[token][version] = 1.6
projects[transliteration][version] = 3.2
projects[view_unpublished][version] = 1.2
projects[taxonomy_access_fix][version] = 2.1
projects[views][version] = 3.10
projects[migrate][version] = 2.7

; Contrib modules with beta releases
projects[master][version] = 2.0-beta4
projects[varnish][version] = 1.0-beta3
projects[better_formats][version] = 1.0-beta1
projects[paragraphs][version] = 1.0-beta6
projects[views_data_export][version] = 3.0-beta8
projects[cer][version] = 3.0-alpha7
projects[table_element][version] = 1.0-beta1

; Defaults
defaults[projects][subdir] = contrib

; Patches
projects[shs][patch][1960182] = "http://www.drupal.org/files/issues/checkifparentset-1960182-08-D7.patch"
projects[varnish][patch][2371907] = http://www.drupal.org/files/issues/varnish-2371907-24.patch

; Patches no more relevant
;projects[entity][patch][2013473] = http://www.drupal.org/files/2013473_0.patch
;projects[paragraphs][patch][] = "profiles/openevent/patches/#87714818_#87714922_f3a4504f7ca462e86f12f2501c83a3d753583fc3.patch"