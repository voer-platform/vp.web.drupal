<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/http.php');

define('VOER_API_URL', 'dev.voer.vn'); //api.voer.edu.vn
define('VOER_API_VERSION', '0.1');
define('VOER_API_COMMAND_MODULE', '' . VOER_API_VERSION . '/modules/');
define('VOER_API_COMMAND_CATEGORY', '' . VOER_API_VERSION . '/categories/');
define('VOER_API_COMMAND_AUTHOR', '' . VOER_API_VERSION . '/authors/');
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

/**
 * For create a new module. Check-in activity of existing module is quite the
 * same but will have little difference in URL and parameters.
 *
 * Content of new module stays inside posted requests. It could be VDP, HTML
 * (rich-text), or other media files.
 *
 * @param  array $params The array (key, value) which is POST data
 * @return string        The json format
 * @example
 * Request: POST  $URL/modules/
 * title=Hello there&author=Someone&vdp=...
 *
 * Response:
 * 200 OK
 * {
 *   "module":{
 *       "id":"123123123",
 *       "title":"Hello there",
 *       "author":"Someone",
 *       …
 *       }
 * }
 */
function voer_api_add($params = array()){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_MODULE, $params);
  $data = $response;
  return json_decode($data);
}

/**
 * [voer_api_get_modules description]
 * @return [type] [description]
 */
function voer_api_get_modules(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_MODULE);
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
 * [voer_api_checkin description]
 * @param  [type] $id      [description]
 * @param  [type] $version [description]
 * @param  array  $params  [description]
 * @return [type]          [description]
 */
function voer_api_checkin($id, $version, $params = array()){
  $client = voer_api_client();
  $response = $client->doPost(VOER_API_COMMAND_MODULE . "/{$id}/{$version}", $params);
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
 * [voer_api_get_all_categories description]
 * @return [type] [description]
 */
function voer_api_get_all_categories(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_CATEGORY);
  return json_decode($response);
}

/**
 * [voer_api_create_category description]
 * @param  [type] $category [description]
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
 * [voer_api_get_category description]
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_get_category($id){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_CATEGORY . $id . "/");
  return json_decode($response);
}

function voer_api_update_category(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_CATEGORY . $id);
  return json_decode($response);
}

/**
 * [voer_api_delete_category description]
 * @param  [type] $id [description]
 * @return [type]     [description]
 */
function voer_api_delete_category($id){
  $client = voer_api_client();
  $response = $client->doDelete(VOER_API_COMMAND_CATEGORY . $id);
  return json_decode($response);
}
/*** END::CATEGORY ***/

/**
 * [voer_api_get_all_authors description]
 * @return [type] [description]
 */
function voer_api_get_all_authors(){
  $client = voer_api_client();
  $response = $client->doGet(VOER_API_COMMAND_AUTHOR);
  return json_decode($response);
}

/**
 * [voer_api_create_author description]
 * @param  [type] $author [description]
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
