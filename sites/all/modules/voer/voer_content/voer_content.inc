<?php

function voer_material_load($material_id, $reload = FALSE){
  $version = 1;
  // Kiem tra tren db web da co hay chua
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
                    ->entityCondition('bundle', 'voer_module')
                    ->propertyCondition('status', 1)
                    ->fieldCondition('field_voer_material_id', 'value', $material_id, '=')
                    ->execute();

  if (count($entities) > 0){
    // Hien thi node trong web
    $nids = array_keys($entities['node']);
    foreach ($entities['node'] as $node){
      return $node;
    }
  }else{
    module_load_include('inc', 'voer_api');
    try{
      $m = voer_api_get_detail_material($material_id);
      return material_from_vpr($m);
    } catch (Exception $e) {
      drupal_set_message(t("There are network problems!. ") . $e->getMessage());
      return FALSE;
    }

  }

}


function voer_material_load_multiple($materials){
  $nodes = array();

  foreach ($materials as $material){
    // Kiem tra tren db web da co hay chua
    $material_id = $material->material_id;
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
                      ->entityCondition('bundle', 'voer_module')
                      ->propertyCondition('status', 1)
                      ->fieldCondition('field_voer_material_id', 'value', $material_id, '=')
                      ->execute();
    if (count($entities) > 0){
      // Hien thi node trong web
      $nids = array_keys($entities['node']);
      return $nids[0];
    }else{
    }
  }
}

/**
 * Save data from VPR to Web data
 * @param  [type] $material [description]
 * @return [type]           [description]
 */
function material_from_vpr($material){
  $node = new stdClass();
  $node->type = 'voer_module';
  node_object_prepare($node);
  $node->uid = 1;
  $node->promote = 0;
  $node->comment = 0;
  $node->title = $material->title;
  $node->language = LANGUAGE_NONE;
  $node->body[$node->language][0]['value'] = $material->text;
  $node->body[$node->language][0]['format'] = 'full_html';
  $node->field_voer_description[$node->language][0]['value'] = $material->description;
  $node->field_voer_categories[$node->language][0]['value'] = $material->categories;
  $node->field_voer_language[$node->language][0]['value'] = $material->language;
  $node->field_voer_material_id[$node->language][0]['value'] = $material->material_id;
  $node->field_voer_material_version[$node->language][0]['value'] = $material->version;
  $node->field_voer_material_type[$node->language][0]['value'] = $material->material_type;
  $node->field_voer_keywords[$node->language][0]['value'] = $material->keywords;

  node_save($node);

  if ($node->nid){
    return $node;
  }else{
    return FALSE;
  }
}
