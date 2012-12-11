<?php

require_once(libraries_get_path('guzzle') . '/Http/Client.php');

define('VOER_API_URL', 'http://api.voer.edu.vn/');
define('VOER_API_VERSION', '0.1');
define('VOER_API_COMMAND', 'modules');

/**
 * [voer_api_client description]
 * @return [type] [description]
 */
function voer_api_client(){
  // Create a client to work with the Twitter API
  $client = new Client(VOER_API_URL . '{version}', array(
      'version' => VOER_API_VERSION
  ));
  return $client;
}

/**
 * [voer_api_add description]
 * @param  [type] $params [description]
 * @return [type]         [description]
 */
function voer_api_add($params){
  $client = voer_api_client();
  $strQuery = http_build_query($params);
  $request = $client->get(VOER_API_COMMAND . $strQuery);
  $response = $request->send();
  $data = $response->json();
  return $data;
}

function voer_api_get_metadata(){

}

/**
 *
 */
function voer_api_get_content(){

}

function voer_api_checkin(){

}

function voer_api_search(){

}

function voer_api_delete(){

}
