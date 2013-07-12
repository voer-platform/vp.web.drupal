<?php
/**
 * @file
 * voer_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function voer_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:node/1
  $menu_links['main-menu:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Contribute',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: main-menu:node/2
  $menu_links['main-menu:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: main-menu:node/9
  $menu_links['main-menu:node/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Learn',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-mnu-management:node/add/voer-collection
  $menu_links['menu-mnu-management:node/add/voer-collection'] = array(
    'menu_name' => 'menu-mnu-management',
    'link_path' => 'node/add/voer-collection',
    'router_path' => 'node/add/voer-collection',
    'link_title' => 'Create collection',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-mnu-management:node/add/voer-module
  $menu_links['menu-mnu-management:node/add/voer-module'] = array(
    'menu_name' => 'menu-mnu-management',
    'link_path' => 'node/add/voer-module',
    'router_path' => 'node/add/voer-module',
    'link_title' => 'Create module',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About us');
  t('Contribute');
  t('Create collection');
  t('Create module');
  t('Learn');


  return $menu_links;
}
