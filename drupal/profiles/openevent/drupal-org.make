; Define required attributes
core = 7.x
api = 2

; Define required modules
;
; To define a specific module version (eg ctools 1.4) and place it in a
; specific directory use the following notation:
;   projects[ctools][version] = 1.4
;   projects[ctools][subdir] = contrib
;
; Versions can be:
;   - 1.4 for a module with 1.4 version number
;   - 2.0-beta3 for a beta release
;   - 1.x-dev for a development version (be careful as it results in different code each time
;     it runs)
;
; Add patches with the following:
;   projects[ctools][patch][1023606] = "http://drupal.org/files/issues/1023606-qid-to-name-6.patch"

; Contrib modules
projects[addressfield][version] = 1.1
projects[ctools][version] = 1.7
projects[date][version] = 2.8
projects[diff][version] = 3.2
projects[double_field][version] = 2.4
projects[entity][version] = 1.6
projects[entityreference][version] = 1.1
projects[features][version] = 2.5
projects[field_group][version] = 1.4
projects[field_validation][version] = 2.4
projects[filefield_sources][version] = 1.9
projects[geolocation][version] = 1.6
projects[libraries][version] = 2.2
projects[link][version] = 1.3
projects[menu_firstchild][version] = 1.1
projects[migrate][version] = 2.7
projects[office_hours][version] = 1.4
projects[pathauto][version] = 1.2
projects[relation_add][version] = 1.4
projects[restws][version] = 2.4
projects[shs][version] = 1.6
; Adds a check when updating parent terms. shs does not give warning any more when terms are updated.
projects[shs][patch][1960182] = "http://www.drupal.org/files/issues/checkifparentset-1960182-08-D7.patch"
projects[strongarm][version] = 2.0
projects[taxonomy_access_fix][version] = 2.1
projects[token][version] = 1.6
projects[transliteration][version] = 3.2
projects[view_unpublished][version] = 1.2
projects[views][version] = 3.10

; Contrib modules with non-stable releases
projects[better_formats][version] = 1.0-beta1
projects[cer][version] = 3.0-alpha7
projects[master][version] = 2.0-beta4
projects[paragraphs][version] = 1.0-beta6
projects[relation][version] = 1.0-rc7
projects[table_element][version] = 1.0-beta1
projects[varnish][version] = 1.0-beta3
; The module gave undefined notices after installation in theme_varnish_status().
projects[varnish][patch][2371907] = "http://www.drupal.org/files/issues/varnish-2371907-24.patch"
projects[views_data_export][version] = 3.0-beta8

; Defaults
defaults[projects][subdir] = contrib
