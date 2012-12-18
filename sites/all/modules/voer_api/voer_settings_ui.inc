<?php
// $Id: gmap_settings_ui.inc,v 1.12.2.5 2010/06/08 20:49:13 bdragon Exp $

/**
 * @file
 * GMap settings form.
 */

function voer_admin_settings($form, &$form_state) {

  //note the name of the variable for center of the map is latlong although the format is actually longitude, latitude

  $form['initialization'] = array(
    '#type' => 'fieldset',
    '#title' => t('VOER Initialize'),
  );

  if (!module_exists('keys_api') && !module_exists('keys')) {
    $form['initialization']['voer_api_key'] = array(
      '#type' => 'textfield',
      '#default_value' => variable_get('voer_api_key', ''),
      '#size' => 50,
      '#maxlength' => 255,
    );
  }
  else {
    $form['initialization']['voer_api_key'] = array(
      '#type' => 'item',
      '#title' => t('VOER API Key'),
      '#value' => t('Managed by <a href="@url">Keys</a>.', array('@url' => url('admin/settings/keys'))),
    );
  }

  $form['initialization']['voer_api_key']['#title'] = t('VOER API Key');
  $form['initialization']['voer_api_key']['#description'] = t('Your personal VOER API key.  If you want to use an API key, you can get one at <a href="http://api.voer.edu.vn/signup.html">VOER API website</a>.');

  $form['initialization']['voer_api_interval'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('voer_api_interval', '900'),
    '#size' => 20,
    '#maxlength' => 15
  );
  $form['initialization']['voer_api_interval']['#title'] = t('Interval refresh');
  $form['initialization']['voer_api_interval']['#description'] = t('');

  // @@@ Convert to element level validation.
  //$form['#validate'][] = 'voer_admin_settings_validate';

  return system_settings_form($form);
}

function voer_admin_settings_validate($form, &$form_state) {

}


