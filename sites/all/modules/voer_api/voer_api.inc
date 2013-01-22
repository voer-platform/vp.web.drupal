<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/http.php');

define('VOER_API_URL', 'dev.voer.vn'); //api.voer.edu.vn
define('VOER_API_VERSION', '0.1');
define('VOER_API_COMMAND_MATERIAL', '' . VOER_API_VERSION . '/materials/');
define('VOER_API_COMMAND_CATEGORY', '' . VOER_API_VERSION . '/categories/');
define('VOER_API_COMMAND_AUTHOR', '' . VOER_API_VERSION . '/authors/');
define('VOER_API_COMMAND_EDITOR', '' . VOER_API_VERSION . '/editors/');
define('VOER_API_AUTH', 'auth');
define('VOER_API_PORT', 2013); //80
define('VOER_API_PROTOCOL', Http::HTTP);

/**
 * [voer_api_client description]
 * @return [type] [description]
 */
function voer_api_client(){
  // Create a client to work with the Twitter API

  $client = Http::connect(VOER_API_URL, VOER_API_PORT, VOER_API_PROTOCOL);
  return $client;
}

/*** BEGIN: MATERIAL ***/
/**
 * Get all materials
 * @return [type] [description]
 */
function voer_api_get_all_materials(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MATERIAL);
  return json_decode($response);
}

/**
 * Create a material
 *
 * @param  Object $material [description]
 * @return [type]           [description]
 */
function voer_api_create_material($material){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_MATERIAL, array(
    "text" => $material->text,
    "version" => $material->version,
    "title" => $material->title,
    "description" => $material->description,
    "keywords" => $material->keywords,
    "categories" => $material->categories,
    "authors" => $material->authors,
    "editor_id" => $material->editor_id,
    "file" => $material->file,
    "file_type" => $material->file_type
  ));
  return json_decode($response);
}

function voer_api_checkin_material(){

}

/**
 * Get list of materials by categories
 *
 * @param  array  $cagetories contains list of ids category
 * @return [type]             [description]
 */
function voer_api_get_materials_by_categories($cagetories = array()){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?categories=" . implode(",", $cagetories));
  return json_decode($response);
}

/**
 * Get list of materials by authors
 *
 * @param  array  $authors [description]
 * @return [type]          [description]
 */
function voer_api_get_materials_by_authors($authors = array()){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?authors=" . implode(",", $authors));
  return json_decode($response);
}

/**
 * Get list of materials by editors
 *
 * @param  array  $editors [description]
 * @return [type]          [description]
 */
function voer_api_get_materials_by_editors($editors = array()){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?editors=" . implode(",", $editors));
  return json_decode($response);
}

/**
 * Get list of materials by types
 *
 * @param  array  $types [description]
 * @return [type]        [description]
 */
function voer_api_get_materials_by_types($types = array()){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MATERIAL . "?material_type=" . implode(",", $types));
  return json_decode($response);
}

/**
 * [voer_api_get_metadata description]
 * @param  [type] $id      [description]
 * @param  string $version [description]
 * @return [type]          [description]
 */
function voer_api_get_metadata($id, $version = ""){
  $client = voer_api_client();
  if ($version === ""){
    $response = $client->doGet(VOER_API_COMMAND_MODULE . "/" . $id);
  }else if ($version === "ALL"){
    $response = $client->doGet(VOER_API_COMMAND_MODULE . "/{$id}?all=1");
  }else{
    $response = $client->doGet(VOER_API_COMMAND_MODULE . "/{$id}/{$version}");
  }
  return json_decode($response);
}

/**
 * [voer_api_get_content description]
 * @param  [type] $id      [description]
 * @param  string $version [description]
 * @return [type]          [description]
 */
function voer_api_get_content($id, $version = ""){
  $client = voer_api_client();
  if ($version === ""){
    $response = $client->doGet(VOER_API_COMMAND_MODULE . "/{$id}?content=1");
  }else{
    $response = $client->doGet(VOER_API_COMMAND_MODULE . "/{$id}/{$version}?content=1");
  }
  return json_decode($response);
}



/**
 * [voer_api_search description]
 * @param  array  $params [description]
 * @return [type]         [description]
 */
function voer_api_search($params = array()){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MODULE, $params);
  return json_decode($response);
}

/*** BEGIN::CATEGORY ***/
/**
 * Get all categories
 * @return Object [description]
 */
function voer_api_get_all_categories(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_CATEGORY);
  return json_decode($response);
}

/**
 * Create a category with name, parent id and description
 * @param  Object $category [description]
 * @return [type]           [description]
 */
function voer_api_create_category($category){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_CATEGORY,
    array(
      'name' => $category->name,
      'parent' => $category->parent,
      'description' => $category->description
    )
  );
  return json_decode($response);
}

/**
 * Retrieve category information
 * @param  Number $id [description]
 * @return Object     [description]
 */
function voer_api_get_category($id){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_CATEGORY . $id . "/");
  return json_decode($response);
}

/**
 * [voer_api_update_category description]
 * @param  [type] $category [description]
 * @return [type]           [description]
 */
function voer_api_update_category($category){
  $client = voer_api_client();
  $response = $client->doPut(VOER_API_COMMAND_CATEGORY . $category->id . "/", array(
    'name' => $category->name,
    'parent' => $category->parent,
    'description' => $category->description
  ));
  return json_decode($response);
}

/**
 * Delete a category
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_category($id){
  $client = voer_api_client();
  $response = $client->doDelete(VOER_API_COMMAND_CATEGORY . $id);
  return json_decode($response);
}
/*** END::CATEGORY ***/


/*** BEGIN: AUTHOR ***/

/**
 * Get all authors
 * @return Object List of authors
 */
function voer_api_get_all_authors(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_AUTHOR);
  return json_decode($response);
}

/**
 * Create new an author
 * @param  Object $author [description]
 * @return [type]         [description]
 */
function voer_api_create_author($author){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_AUTHOR, array(
    "fullname" => $author->fulname,
    "bio" => $author->bio
  ));
  return json_decode($response);
}

/**
 * Retrieve an author information
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_get_author($id){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_AUTHOR . $id . "/");
  return json_decode($response);
}

/**
 * [voer_api_update_author description]
 * @param  [type] $author [description]
 * @return [type]         [description]
 */
function voer_api_update_author($author){
  $client = voer_api_client();
  $response = $client->doPut(VOER_API_COMMAND_AUTHOR . $author->id . "/", array(
    'fullname' => $author->fullname,
    'bio' => $author->bio
  ));
  return json_decode($response);
}

/**
 * Delete an author
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_author($id){
  $client = voer_api_client();
  $response = $client->doDelete(VOER_API_COMMAND_AUTHOR . $id);
  return json_decode($response);
}

/*** END: AUTHOR ***/

/*** BEGIN: EDITOR ***/
/**
 * Get all editors
 * @return Object [description]
 */
function voer_api_get_all_editors(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_EDITOR);
  return json_decode($response);
}

/**
 * Create an editor
 * @param  [type] $editor [description]
 * @return [type]         [description]
 */
function voer_api_create_editor($editor){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_EDITOR, array(
    "fullname" => $editor->fulname,
    "user_id" => $editor->user_id,
    "client_id" => $editor->client_id
  ));
  return json_decode($response);
}

/**
 * Retrieve an editor information
 * @param  Number $id [description]
 * @return [type]     [description]
 */
function voer_api_get_editor($id){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_EDITOR . $id . "/");
  return json_decode($response);
}

/**
 * [voer_api_update_editor description]
 * @param  [type] $editor [description]
 * @return [type]         [description]
 */
function voer_api_update_editor($editor){
  $client = voer_api_client();
  $response = $client->doPut(VOER_API_COMMAND_EDITOR . $author->id . "/", array(
    'fullname' => $editor->fullname,
    'user_id' => $editor->user_id,
    'client_id' => $editor->client_id
  ));
  return json_decode($response);
}

/**
 * Delete an editor
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_editor($id){
  $client = voer_api_client();
  $response = $client->doDelete(VOER_API_COMMAND_EDITOR . $id);
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
function voer_api_refresh_key($clientId, $token){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_AUTH . $clientId . "?refresh=1", array(
      'token' => $token
    ));
  return $response;
}

function voer_api_delete(){

}
