<?php

require_once 'sslLabsApi.php';

//Return API response as JSON string
$api = new sslLabsApi();

//Return API response as JSON object
$api = new sslLabsApi(true);

//Set content-type header for JSON output
header('Content-Type: application/json');

$abc  = $api->fetchHostInformation('https://www.section508.gov');
#$cde  = $api->fetchEndpointData('https://www.pic.gov','159.142.191.113');

//get API information
var_dump($abc);
#var_dump($cde);
var_dump($api->fetchApiInfo());

?>
