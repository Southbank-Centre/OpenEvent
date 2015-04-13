Patches policy

The patches for the Drupal code will be stored in this folder.
They will have the following name convention:

#<pivotal_issue>_patch-name.patch

The information about why the patch was applied will be found on the corresponding pivotal task.

The patches will be applied form the root folder providing the directory where they must be applied (this depends on where the patch was created from):

$:> git apply --directory=drupal patches/#84843756_string-offset-cast.patch
