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
projects[auto_entitylabel][version] = 1.3
projects[ctools][version] = 1.7
projects[date][version] = 2.8
projects[email][version] = 1.3
projects[entity][version] = 1.6
projects[features][version] = 2.6
projects[field_group][version] = 1.4
projects[field_validation][version] = 2.6
projects[filefield_sources][version] = 1.9
projects[geolocation][version] = 1.6
projects[link][version] = 1.3
; Fix URL validation
projects[link][patch][2498983] = "https://www.drupal.org/files/issues/link-urls_not_validate-2498983-1.patch"
projects[office_hours][version] = 1.4
projects[relation_add][version] = 1.4
; When adding a new Relation Add field to a Content Type, after clicking the initial Save Field Settings button, we are taken to the Settings page and there is a warning
projects[relation_add][patch][2460131] = "https://www.drupal.org/files/issues/relation_add-php-warning-add-relation-2460131-1.patch"
projects[restws][version] = 2.4
projects[strongarm][version] = 2.0
projects[taxonomy_access_fix][version] = 2.2
projects[token][version] = 1.6

; Contrib modules with non-stable releases
projects[better_formats][version] = 1.0-beta1
projects[relation][version] = 1.0-rc7
projects[schemaorg][version] = 1.0-rc1
; Preserve field mappings that aren't defined by a feature when revertin that feature, rather than removing them
projects[schemaorg][patch][2533906] = "https://www.drupal.org/files/issues/schemaorg-features-capture-certain-mappings-2533906-1.patch"
projects[table_element][version] = 1.0-beta1

; Defaults
defaults[projects][subdir] = contrib

; Open bugs
;
; 2484657 - Breaking behaviour when a filefield source field is used within a paragraph bundle.
;
