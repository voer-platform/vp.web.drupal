<?php
/**
 * @file
 * voer_features.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function voer_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-mnu-management.
  $menus['menu-mnu-management'] = array(
    'menu_name' => 'menu-mnu-management',
    'title' => 'Management',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Management');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
