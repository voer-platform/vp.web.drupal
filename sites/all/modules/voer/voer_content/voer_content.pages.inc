<?php

function voer_content_publish($object){
  return drupal_get_form("voer_content_publish_form", $object);
}

function voer_content_publish_form($form, &$form_state, $entity){
  $form['entity'] = array(
    '#type' => 'value',
    '#value' => $entity,
  );

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => t('Comment for publish'),
  );

  $form['publish'] = array(
    '#type' => 'submit',
    '#value' => t('Publish'),
    '#weight' => 100,
  );

  return $form;
}

function voer_content_publish_form_submit($form, &$form_state){
  // dpm($form_state['values']['entity']);
  $entity = $form_state['values']['entity'];
  $mod_data = array();
  $mod_data['title'] = $entity->title;
  $mod_data['text'] = $entity->body[LANGUAGE_NONE][0]['value'];
  $mod_data['language'] = $form_state['values']['field_language'][LANGUAGE_NONE][0]['value'];
  $mod_data['description'] = $entity->field_voer_description[LANGUAGE_NONE][0]['value'];
  $mod_data['categories'] = $form_state['values']['field_category'][LANGUAGE_NONE][0]['value'];
  $mod_data['authors'] = $user->uid;
  $mod_data['editor_id'] = 1;
  $mod_data['keywords'] = $form_state['values']['field_keyword'][LANGUAGE_NONE][0]['value'];
  $mod_data['license_id'] = '3';
  $mod_data['material_type'] = VOER_MATERIAL_TYPE_TEXT;
  $mod_data['file'] = '';
  $mod_data['file_type'] = '';
  $mod_data['derived_from'] = 1;

  module_load_include('inc', 'voer_api');

  if (isset($node->nid) && $form_state['values']['field_id'][LANGUAGE_NONE][0]['value']) {
    $mod_data['material_id'] = $form_state['values']['field_id'][LANGUAGE_NONE][0]['value'];
    $result = voer_api_checkin_material($mod_data);
    unset($node->nid);
    unset($node->vid);

  } else {
    $result = voer_api_create_material((object)$mod_data);
  }
}
