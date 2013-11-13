<?php

$module_path = drupal_get_path('module', 'voer_api');
require_once($module_path . '/lib/http.php');

define('VOER_TRANSFORMER_URL', 'dev.voer.edu.vn'); //api.voer.edu.vn
define('VOER_TRANSFORMER_PORT', 6543); //80
define('VOER_TRANSFORMER_PROTOCOL', Http::HTTP);
define('VOER_TRANSFORMER_IMPORT', 'import/');

class VoerTransformerException extends Exception {}

class VoerTransformer{
  private $client = null;
  private $clientId = null;
  private $token = null;

  public function __construct(){
    $this->client = Http::connect(VOER_TRANSFORMER_URL, VOER_TRANSFORMER_PORT, VOER_TRANSFORMER_PROTOCOL);
    $this->clientId = variable_get('voer_api_client_id', '');
    $this->token = variable_get('voer_api_token', '');
  }

  /**
   * [transform description]
   * POST $URL/import
   * token = <your given token>
   * cid = <your client id>
   * file = <... binary data of your file here ...>
   * @param  [type] $url    [description]
   * @param  array  $params [description]
   * @return [type]         [description]
   */
  public function transform_import($file){
    // print $this->token;
    // exit;
    // print $this->clientId;
    if (file_exists($file)){
      $fileinfo = pathinfo($file);
      $fileform = '@' . $file . ';filename=' . md5($fileinfo['filename']);
      $_client = $this->client;

      return $_client->doPost(VOER_TRANSFORMER_IMPORT, array(
          'token' => $this->token,
          'cid' => $this->clientId,
          'file' => $fileform
        ));
    }else{
      return null;
    }
  }
}
