<?php
/**
 * @file
 * voer_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function voer_features_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
