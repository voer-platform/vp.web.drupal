<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/http.php');

define('VOER_API_URL', variable_get('voer_api_server', 'dev.voer.vn')); //api.voer.edu.vn
define('VOER_API_PORT', variable_get('voer_api_port', '2013')); //80
define('VOER_API_PROTOCOL', Http::HTTP);
define('VOER_API_VERSION', '0.1');
define('VOER_API_AUTH', VOER_API_VERSION . '/auth/');


class VoerApiException extends Exception {}

class VoerApi{
  private $client = null;
  private $clientId = null;
  private $clientKey = null;
  private $token = null;


  private function get_http(){
    $this->client = Http::connect(VOER_API_URL, VOER_API_PORT, VOER_API_PROTOCOL);
  }

  public function __construct(){
    $this->client = Http::connect(VOER_API_URL, VOER_API_PORT, VOER_API_PROTOCOL);
    $this->clientId = variable_get('voer_api_client_id', '');
    $this->clientKey = variable_get('voer_api_key', '');
    $this->token = variable_get('voer_api_token', '');
    if ($this->token == ''){
      $this->refresh_token();
    }
  }

  /**
   * Use refresh token of current client
   * @return [type] [description]
   */
  public function refresh_token(){
    $sugar = 'voer';
    $response = $this->client->doGet(VOER_API_AUTH . $this->clientId . "/", array(
      'sugar' => $sugar,
      'comb' => md5($this->clientKey . $sugar)
    ));
    $result = json_decode($response);
    if (isset($result) && $result->client_id != ''){
      $this->token = $result->token;
      variable_set('voer_api_token', $this->token);
    }
  }

  /**
   * [auth_request description]
   * @param  [type] $url    [description]
   * @param  string $method [description]
   * @param  array  $params [description]
   * @return [type]         [description]
   */
  public function auth_request($url, $method ="GET", $params = array()){
    $_client = $this->client;
    $_client->setAuthenticate($this->clientId, $this->token);
    switch ($method) {
      case 'GET':
        return $_client->doGet($url, $params);
      case 'POST':
        return $_client->doPost($url, $params);
      case 'DELTE':
        return $_client->doDelete($url, $params);
      case 'PUT':
        return $_client->doPut($url, $params);
    }
  }
}
