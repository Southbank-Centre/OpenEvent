; Define required attributes
api = 2
core = 7.35

; Define required modules
;
; To define a specific module version (eg ctool 7.x-1.4) and place it in a
; specific directory use the following notation:
;   projects[ctools][version] = 1.4
;   projects[ctools][subdir] = contrib
;
; Versions can be:
;   - 1.4 for a module with 7.x-1.4 version number
;   - 2.0-beta3 for a beta release
;   - 1.x-dev for a development version (be carefull as it results in different code each time
;     it runs.
;
; Add patches with the following:
;   projects[ctools][patch][] = "http://drupal.org/files/issues/1023606-qid-to-name-6.patch"

; Contrib modules
projects[ctools][version] = 7.x-1.4
projects[ctools][subdir] = contrib
projects[date][version] = 7.x-2.8
projects[date][subdir] = contrib
projects[date_all_day][version] = 7.x-2.8
projects[date_all_day][subdir] = contrib
projects[date_api][version] = 7.x-2.8
projects[date_api][subdir] = contrib
projects[date_popup][version] = 7.x-2.8
projects[date_popup][subdir] = contrib
projects[features][version] = 7.x-2.3
projects[features][subdir] = contrib
projects[master][version] = 7.x-2.0-beta3
projects[master][subdir] = contrib
projects[color_field][version] = 7.x-1.6
projects[color_field][subdir] = contrib
projects[entityreference][version] = 7.x-1.1
projects[entityreference][subdir] = contrib
projects[field_group][version] = 7.x-1.4
projects[field_group][subdir] = contrib
projects[field_validation][version] = 7.x-2.4
projects[field_validation][subdir] = contrib
projects[field_validation_ui][version] = 7.x-2.4
projects[field_validation_ui][subdir] = contrib
projects[filefield_sources][version] = 7.x-1.9
projects[filefield_sources][subdir] = contrib
projects[link][version] = 7.x-1.3
projects[link][subdir] = contrib
projects[auto_entitylabel][version] = 7.x-1.2
projects[auto_entitylabel][subdir] = contrib
projects[better_formats][version] = 7.x-1.0-beta1
projects[better_formats][subdir] = contrib
projects[diff][version] = 7.x-3.2
projects[diff][subdir] = contrib
projects[entity][version] = 7.x-1.5
projects[entity][subdir] = contrib
projects[libraries][version] = 7.x-2.2
projects[libraries][subdir] = contrib
projects[pathauto][version] = 7.x-1.2
projects[pathauto][subdir] = contrib
projects[restws][version] = 7.x-2.2
projects[restws][subdir] = contrib
projects[shs][version] = 7.x-1.6
projects[shs][subdir] = contrib
projects[strongarm][version] = 7.x-2.0
projects[strongarm][subdir] = contrib
projects[token][version] = 7.x-1.5
projects[token][subdir] = contrib
projects[transliteration][version] = 7.x-3.2
projects[transliteration][subdir] = contrib
projects[paragraphs][version] = 7.x-1.0-beta5
projects[paragraphs][subdir] = contrib
projects[view_unpublished][version] = 7.x-1.2
projects[view_unpublished][subdir] = contrib
projects[taxonomy_access_fix][version] = 7.x-2.1
projects[taxonomy_access_fix][subdir] = contrib
projects[views][version] = 7.x-3.10
projects[views][subdir] = contrib
projects[views_data_export][version] = 7.x-3.0-beta8
projects[views_data_export][subdir] = contrib
projects[views_ui][version] = 7.x-3.10
projects[views_ui][subdir] = contrib
;projects[migrate][version] = 7.x-2.7
;projects[migrate][subdir] = contrib
;projects[migrate_ui][version] = 7.x-2.7
;projects[migrate_ui][subdir] = contrib

; Patches
projects[][patch][] = ;CREATE patches with file atribute