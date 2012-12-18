<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/ttp.php');

define('VOER_API_URL', 'api.voer.edu.vn');
define('VOER_API_VERSION', '0.1');
define('VOER_API_COMMAND_MODULE', '/' . VOER_API_VERSION . '/modules');
define('VOER_API_AUTH', 'auth');
define('VOER_API_PORT', 80);
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
  return $data;
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
  return $response;
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
  return $response;
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
  $resonse = $client->doPost(VOER_API_COMMAND_MODULE . "/{$id}/{$version}", $params);
  return $response;
}

/**
 * [voer_api_search description]
 * @param  array  $params [description]
 * @return [type]         [description]
 */
function voer_api_search($params = array()){
  $client = voer_api_client();
  $resonse = $client->doGet(VOER_API_COMMAND_MODULE, $params);
  return $response;
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
