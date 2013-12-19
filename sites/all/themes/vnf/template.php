<?php

/**
 * @file
 * template.php
 */
function vnf_theme() {
  $items = array();
  // create custom user-login.tpl.php
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'vnf') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
      'vnf_preprocess_user_login'
    ),
  );

  $items['user_register_form'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'vnf') . '/templates',
    'template' => 'user-register-form',
    'preprocess functions' => array(
      'vnf_preprocess_user_register_form'
    ),
  );

  return $items;
}

function vnf_preprocess_user_login(&$vars) {
  $vars['form']['name']['#attributes']['placeholder'] = $vars['form']['name']['#title'];
  $vars['form']['pass']['#attributes']['placeholder'] = $vars['form']['pass']['#title'];
  $vars['form']['actions']['submit']['#attributes']['class'] = array('btn', 'btn-primary');
  $vars['form']['#action'] = '/user/login';

  unset($vars['form']['name']['#title']);
  unset($vars['form']['name']['#description']);
  unset($vars['form']['pass']['#title']);
  unset($vars['form']['pass']['#description']);
}

function vnf_preprocess_user_register_form(&$vars) {
  unset($vars['form']['account']['name']['#title']);
  unset($vars['form']['account']['name']['#description']);
  unset($vars['form']['account']['mail']['#title']);

  $vars['form']['account']['name']['#attributes']['placeholder'] = t('Your username');
  $vars['form']['account']['mail']['#attributes']['placeholder'] = t('Your email address');

  $vars['form']['actions']['submit']['#value'] = t('Get started');
  $vars['form']['actions']['submit']['#attributes']['class'] = array('btn', 'btn-sign-up', 'left', 'clear');
}

function vnf_form_alter(&$form, &$form_state, $form_id)
{
  if ($form_id == 'user_login') {
    $form['#action'] = '/user/login';
  }
}