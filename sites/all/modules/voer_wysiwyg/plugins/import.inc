<?php

/**
 * Specially named implementation of hook_wysiwyg_plugin().
 *
 * Should be named {$module}_{$plugin}_plugin().
 */
function voer_wysiwyg_import_plugin() {
  $plugins['import'] = array(
    'title' => t('Import plugin'),
    // The 'icon file' is the icon that appears in the Wysiwyg toolbar.
    'icon file' => 'foo.toolbar_icon.gif',
    'icon title' => t('A import document plugin'),
    'settings' => array(),
  );
  return $plugins;
}
