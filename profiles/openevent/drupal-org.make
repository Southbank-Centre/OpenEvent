; Define required attributes
core = 7.x
api = 2
projects[drupal][version] = "7.35"

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
;     it runs.
;
; Add patches with the following:
;   projects[ctools][patch][] = "http://drupal.org/files/issues/1023606-qid-to-name-6.patch"

; Contrib modules
projects[ctools][version] = 1.4
projects[ctools][subdir] = contrib
projects[date][version] = 2.8
projects[date][subdir] = contrib
projects[features][version] = 2.3
projects[features][subdir] = contrib
projects[master][version] = 2.0-beta3
projects[master][subdir] = contrib
projects[color_field][version] = 1.6
projects[color_field][subdir] = contrib
projects[entityreference][version] = 1.1
projects[entityreference][subdir] = contrib
projects[field_group][version] = 1.4
projects[field_group][subdir] = contrib
projects[field_validation][version] = 2.4
projects[field_validation][subdir] = contrib
projects[filefield_sources][version] = 1.9
projects[filefield_sources][subdir] = contrib
projects[link][version] = 1.3
projects[link][subdir] = contrib
projects[auto_entitylabel][version] = 1.2
projects[auto_entitylabel][subdir] = contrib
projects[better_formats][version] = 1.0-beta1
projects[better_formats][subdir] = contrib
projects[diff][version] = 3.2
projects[diff][subdir] = contrib
projects[entity][version] = 1.5
projects[entity][subdir] = contrib
projects[libraries][version] = 2.2
projects[libraries][subdir] = contrib
projects[pathauto][version] = 1.2
projects[pathauto][subdir] = contrib
projects[restws][version] = 2.2
projects[restws][subdir] = contrib
projects[shs][version] = 1.6
projects[shs][subdir] = contrib
projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib
projects[token][version] = 1.5
projects[token][subdir] = contrib
projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib
projects[paragraphs][version] = 1.0-beta5
projects[paragraphs][subdir] = contrib
projects[view_unpublished][version] = 1.2
projects[view_unpublished][subdir] = contrib
projects[taxonomy_access_fix][version] = 2.1
projects[taxonomy_access_fix][subdir] = contrib
projects[views][version] = 3.10
projects[views][subdir] = contrib
projects[views_data_export][version] = 3.0-beta8
projects[views_data_export][subdir] = contrib
projects[varnish][version] = 1.0-beta3
projects[varnish][subdir] = contrib
projects[migrate][version] = 2.7
projects[migrate][subdir] = contrib

; Patches
;projects[shs][patch][] = ./patches/#84775642_checkifparentset-1960182.patch
;projects[field][patch][] = ./patches/#84843756_string-offset-cast-1824820-2.patch