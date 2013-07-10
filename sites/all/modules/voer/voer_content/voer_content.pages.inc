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

function voer_category_title($category){
  return $category->name;
}

function show_materials_by_category($category){
  module_load_include('inc', 'voer_api');
  try {
    $page = isset($_GET['page']) ? $_GET['page'] : 0;
    $materials = voer_api_get_materials_by_categories(array($category->id), $page + 1);
    if ($materials->count == 0){
      return t("Materials not found!");
    }else{
      $nodes = array();
      pager_default_initialize($materials->count, 10);
      // dpm($materials);
      // return "";
      foreach ($materials->results as $key => $material) {
        $node = new stdClass();
        $node->type = 'voer_module';
        node_object_prepare($node);
        $node->title = $material->title;
        $node->material_id = $material->material_id;
        $node->nid = $key;
        $node->comment = 0;
        $node->field_voer_description[LANGUAGE_NONE][0]['value'] = $material->description;
        // $node->path = "module/" . $material->material_id;
        $nodes[] = $node;
      }
      $output = node_view_multiple($nodes);
      $output['pager'] = array('#markup' => theme('pager'));
      return $output;// . theme('pager');
    }
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    return "";
  }
}


/**
 *  Menu callback: prompt the user to confirm the operation
 */
function voer_content_clone($node) {

  $method = variable_get('clone_method', 'prepopulate');

  switch ($method) {
    case 'save-edit':
      if (variable_get('clone_nodes_without_confirm', FALSE)) {
        $new_nid = clone_node_save($node->nid);
        drupal_goto('node/'. $new_nid .'/edit');
      }
      else {
        return drupal_get_form('clone_node_confirm', $node);
      }
      break;
    case 'prepopulate':
    default:
      return clone_node_prepopulate($node);
      break;
  }
}

