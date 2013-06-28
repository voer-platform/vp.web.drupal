<?php

require_once("../lib/http.php");

echo Http::connect('voer.local')->doGet('/', array('a' => "a a a"));

?>
