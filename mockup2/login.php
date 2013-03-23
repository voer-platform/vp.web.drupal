<?php
session_start();

$user = new stdClass();
$user->username = $_POST['username'];
$_SESSION['visitor'] = $user;

header('Location: index.php');