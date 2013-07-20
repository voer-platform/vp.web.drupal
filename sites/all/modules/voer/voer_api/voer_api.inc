<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/http.php');
require_once('voer_api.lib.php');
require_once('voer_transformer.lib.php');

define('VOER_API_COMMAND_MATERIAL', '' . VOER_API_VERSION . '/materials/');
define('VOER_API_COMMAND_CATEGORY', '' . VOER_API_VERSION . '/categories/');
define('VOER_API_COMMAND_AUTHOR', '' . VOER_API_VERSION . '/persons/');
define('VOER_API_COMMAND_EDITOR', '' . VOER_API_VERSION . '/editors/');
define('VOER_API_COMMAND_FILES', '' . VOER_API_VERSION . '/mfiles/');
define('VOER_API_COMMAND_SEARCH', '' . VOER_API_VERSION . '/search/');

define('VOER_API_RESULT_NOT_FOUND', 'Not found');

/*** BEGIN: MATERIAL ***/
/**
 * Get all materials
 * @return [type] [description]
 */
function voer_api_get_all_materials(){
  // $client = voer_api_client();
  // $client->setAuthenticate('vpweb', 'b079d6f6f0eaa03e40c086d525bdaa8b');
  $voer = new VoerApi();
  // $voer->refresh_token();
  $url = VOER_API_COMMAND_MATERIAL;
  $response = $voer->auth_request($url);
  // $response = $client->doGet(VOER_API_COMMAND_MATERIAL);
  return json_decode($response);
}

/**
 * Create a material
 *
 * @param  Object $material [description]
 * @return [type]           [description]
 */
function voer_api_create_material($params){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL;
  $response = $voer->auth_request($url, "POST", $params);

  return json_decode($response);
}

/**
 * [voer_api_checkin_material description]
 *
 * @param  array $material [description]
 * @return array           [description]
 */
function voer_api_checkin_material($material){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL .$material['material_id'] . '/';
  $response = $voer->auth_request($url, "PUT", $material);
  return json_decode($response);
}

/**
 * Get list version of material by id
 *
 * @param  int $id [description]
 * @return object     [description]
 */
function voer_api_get_materials_by_id($id) {
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL . $id . '/all/';
  $response = $voer->auth_request($url);

  return json_decode($response);
}

function voer_api_get_detail_material($material_id, $version = NULL){
  $voer = new VoerApi();
  if ($version == NULL){
    $url = VOER_API_COMMAND_MATERIAL . $material_id . "/";
  }else{
    $url = VOER_API_COMMAND_MATERIAL . $material_id . "/" . $version . "/";
  }
  $response = $voer->auth_request($url);
  return json_decode($response);
}

/**
 * Get list of materials by categories
 *
 * @param  array  $cagetories contains list of ids category
 * @return [type]             [description]
 */
function voer_api_get_materials_by_categories($cagetories = array(), $page = 1){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL; // . "?categories=" . implode(",", $cagetories);
  $params = array('categories' => implode(',', $cagetories), 'page' => $page, 'sort_on' => '-modified');
  $response = $voer->auth_request($url, "GET", $params);
  return json_decode($response);
}

/**
 * Get list of materials by authors
 *
 * @param  array  $authors [description]
 * @return [type]          [description]
 */
function voer_api_get_materials_by_authors($authors = array()){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL;
  $params = array('authors' => implode(',', $authors));
  $response = $voer->auth_request($url, "GET", $params);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_MATERIAL, array('authors' => implode(',', $authors)));
  return json_decode($response);
}

/**
 * Get list of materials by editors
 *
 * @param  array  $editors [description]
 * @return [type]          [description]
 */
function voer_api_get_materials_by_editors($editors = array()){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL . "?editors=" . implode(",", $editors);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?editors=" . implode(",", $editors));
  return json_decode($response);
}

/**
 * Get list of materials by types
 *
 * @param  array  $types [description]
 * @return [type]        [description]
 */
function voer_api_get_materials_by_types($types = array()){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_MATERIAL . "?material_type=" . implode(",", $types);
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?material_type=" . implode(",", $types));
  return json_decode($response);
}

/**
 * [voer_api_get_metadata description]
 * @param  [type] $id      [description]
 * @param  string $version [description]
 * @return [type]          [description]
 */
// function voer_api_get_metadata($id, $version = ""){
//   $client = voer_api_client();
//   if ($version === ""){
//     $response = $client->doGet(VOER_API_COMMAND_MATERIAL  . $id . "/");
//   }else if ($version === "ALL"){
//     $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "{$id}/?all=1");
//   }else{
//     $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "{$id}/{$version}/");
//   }
//   return json_decode($response);
// }

/**
 * [voer_api_get_content description]
 * @param  [type] $id      [description]
 * @param  string $version [description]
 * @return [type]          [description]
 */
// function voer_api_get_content($id, $version = ""){
//   $client = voer_api_client();
//   if ($version === ""){
//     $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "{$id}/");
//   } else {
//     $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "{$id}/{$version}/");
//   }

//   return drupal_json_decode($response);
// }



/**
 * [voer_api_search description]
 * @param  array  $params [description]
 * @return [type]         [description]
 */
function voer_api_search_on_material($keyword = NULL, $page = 1){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_SEARCH;
  $params = array('kw' => $keyword, 'on' => 'm', 'page' => $page);
  $response = $voer->auth_request($url, "GET", $params);
  return json_decode($response);
}

/*** BEGIN::CATEGORY ***/
/**
 * Get all categories
 * @return Object [description]
 */
function voer_api_get_all_categories(){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_CATEGORY;
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_CATEGORY);
  return json_decode($response);
}

/**
 * Create a category with name, parent id and description
 * @param  Object $category [description]
 * @return [type]           [description]
 */
function voer_api_create_category($category){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_CATEGORY;
  $params = array(
      'name' => $category->name,
      'parent' => $category->parent,
      'description' => $category->description
    );
  $response = $voer->auth_request($url, "POST", $params);
  // $client = voer_api_client();
  // $response = $client->doPost(VOER_API_COMMAND_CATEGORY,
  //   array(
  //     'name' => $category->name,
  //     'parent' => $category->parent,
  //     'description' => $category->description
  //   )
  // );
  return json_decode($response);
}

/**
 * Retrieve category information
 * @param  Number $id [description]
 * @return Object     [description]
 */
function voer_api_get_category($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_CATEGORY . $id . "/";
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_CATEGORY . $id . "/");

  if (!isset($response->detail)) {
    return json_decode($response);
  }

  return NULL;
}

/**
 * [voer_api_update_category description]
 * @param  [type] $category [description]
 * @return [type]           [description]
 */
function voer_api_update_category($category){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_CATEGORY . $category->id . "/";
  $params = array(
    'name' => $category->name,
    'parent' => $category->parent,
    'description' => $category->description
  );
  $response = $voer->auth_request($url, "PUT", $params);
  // $client = voer_api_client();
  // $response = $client->doPut(VOER_API_COMMAND_CATEGORY . $category->id . "/", array(
  //   'name' => $category->name,
  //   'parent' => $category->parent,
  //   'description' => $category->description
  // ));
  return json_decode($response);
}

/**
 * Delete a category
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_category($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_CATEGORY . $id;
  $response = $voer->auth_request($url, "DELETE");
  // $client = voer_api_client();
  // $response = $client->doDelete(VOER_API_COMMAND_CATEGORY . $id);
  return json_decode($response);
}
/*** END::CATEGORY ***/


/*** BEGIN: AUTHOR ***/

/**
 * Get all authors
 * @return Object List of authors
 */
function voer_api_get_all_authors(){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_AUTHOR;
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_AUTHOR);
  return json_decode($response);
}

/**
 * Create new an author
 * @param  Object $author [description]
 * @return [type]         [description]
 */
function voer_api_create_author($author){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_AUTHOR;
  $params = array(
    "fullname" => $author->fulname,
    "bio" => $author->bio
  );
  $response = $voer->auth_request($url, "POST", $params);
  // $client = voer_api_client();
  // $response = $client->doPost(VOER_API_COMMAND_AUTHOR, array(
  //   "fullname" => $author->fulname,
  //   "bio" => $author->bio
  // ));
  return json_decode($response);
}

/**
 * Retrieve an author information
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_get_author($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_AUTHOR . $id . "/";
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_AUTHOR . $id . "/");
  return json_decode($response);
}

/**
 * [voer_api_update_author description]
 * @param  [type] $author [description]
 * @return [type]         [description]
 */
function voer_api_update_author($author){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_AUTHOR . $author->id . "/";
  $params = array(
    'fullname' => $author->fullname,
    'bio' => $author->bio
  );
  $response = $voer->auth_request($url, "PUT", $params);
  // $client = voer_api_client();
  // $response = $client->doPut(VOER_API_COMMAND_AUTHOR . $author->id . "/", array(
  //   'fullname' => $author->fullname,
  //   'bio' => $author->bio
  // ));
  return json_decode($response);
}

/**
 * Delete an author
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_author($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_AUTHOR . $id . "/";
  $response = $voer->auth_request($url, "DELETE");
  // $client = voer_api_client();
  // $response = $client->doDelete(VOER_API_COMMAND_AUTHOR . $id);
  return json_decode($response);
}

/*** END: AUTHOR ***/

/*** BEGIN: EDITOR ***/
/**
 * Get all editors
 * @return Object [description]
 */
function voer_api_get_all_editors(){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_EDITOR;
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_EDITOR);
  return json_decode($response);
}

/**
 * Create an editor
 * @param  [type] $editor [description]
 * @return [type]         [description]
 */
function voer_api_create_editor($editor){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_EDITOR;
  $params = array(
    "fullname" => $editor->fulname,
    "user_id" => $editor->user_id,
    "client_id" => $editor->client_id
  );
  $response = $voer->auth_request($url, "POST", $params);
  // $client = voer_api_client();
  // $response = $client->doPost(VOER_API_COMMAND_EDITOR, array(
  //   "fullname" => $editor->fulname,
  //   "user_id" => $editor->user_id,
  //   "client_id" => $editor->client_id
  // ));
  return json_decode($response);
}

/**
 * Retrieve an editor information
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_get_editor($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_EDITOR . $id . "/";
  $response = $voer->auth_request($url);
  // $client = voer_api_client();
  // $response = $client->doGet(VOER_API_COMMAND_EDITOR . $id . "/");
  return json_decode($response);
}

/**
 * [voer_api_update_editor description]
 * @param  [type] $editor [description]
 * @return [type]         [description]
 */
function voer_api_update_editor($editor){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_EDITOR . $editor->id . "/";
  $params = array(
    'fullname' => $editor->fullname,
    'user_id' => $editor->user_id,
    'client_id' => $editor->client_id
  );
  $response = $voer->auth_request($url, "PUT", $params);
  // $client = voer_api_client();
  // $response = $client->doPut(VOER_API_COMMAND_EDITOR . $editor->id . "/", array(
  //   'fullname' => $editor->fullname,
  //   'user_id' => $editor->user_id,
  //   'client_id' => $editor->client_id
  // ));
  return json_decode($response);
}

/**
 * Delete an editor
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_editor($id){
  $voer = new VoerApi();
  $url = VOER_API_COMMAND_EDITOR . $id . "/";
  $response = $voer->auth_request($url, "DELETE");
  // $client = voer_api_client();
  // $response = $client->doDelete(VOER_API_COMMAND_EDITOR . $id);
  return json_decode($response);
}
/*** END: EDITOR ***/

/**
 * This function is used refresh token when it's about to expired
 *
 * @param  string $clientId The client id which is registered with VOER core.
 * @param  string $token    The old value of token
 * @return string           The return status
 */
function voer_api_refresh_token(){
  $voer = new VoerApi();
  $voer->refresh_token();
}

function voer_api_delete(){

}

function voer_api_import($file){
  $voer_transformer = new VoerTransformer();
  return $voer_transformer->transform_import($file);
}

function voer_api_get_images($material_id){
  $voer = new VoerApi();
  $result = array();
  $imgUrl = "http://" . VOER_API_URL . ":" . VOER_API_PORT . "/" . VOER_API_VERSION . "/mfiles/";

  $url = VOER_API_COMMAND_MATERIAL . $material_id . '/mfiles/';
  $response = $voer->auth_request($url);
  $ids = json_decode($response);
  if (isset($ids)){
    foreach ($ids as $imgId) {
      $url = VOER_API_COMMAND_FILES . $imgId . "/";
      $response = $voer->auth_request($url);
      $imgInfo = json_decode($response);
      $result[$imgInfo->name] = $imgUrl . $imgInfo->id . "/get";
      // dpm($result);
    }
  }
  return $result;
}
