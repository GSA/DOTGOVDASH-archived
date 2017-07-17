<?php

require_once 'sslLabsApi.php';

//Return API response as JSON string
$api = new sslLabsApi();

//Return API response as JSON object
//$api = new sslLabsApi(true);

//Set content-type header for JSON output
//header('Content-Type: application/json');

#$abc  = $api->fetchHostInformation('https://www.whitehouse.gov');
print_r($api->fetchApiInfo());
$abc  = $api->fetchHostInformation('bondpro.gov',false,false,true,24);
//$api->fetchHostInformation('pic.gov',true,false,true,1);
//$api->fetchHostInformation('whitehouse.gov',true,false,true,1);
//$api->fetchHostInformation('aapi.gov.gov',true,false,true,1);
//print_r($api->fetchApiInfo());

print_r($abc);
//$a1 = json_decode($abc, true);
  //  print_r($abc->endpoints);
//Consider results only if status is READY and not In Progress
if($abc->status == 'READY'){
    foreach($abc->endpoints as $ekey=>$eval){
        //ignore ipv6 address and consider only normal ip address as the results for ipv6 address are not detailed
        if(strpos($eval->ipAddress,'.') !== false) {
            print $eval->grade;
        }
    }
}

#$cde  = $api->fetchEndpointData('www.pic.gov','159.142.191.113',true);
#$cde  = $api->fetchEndpointData('https://www.whitehouse.gov','2600:1406:1a:39b:0:0:0:fc4',true);

//get API information
//var_dump($abc);
#var_dump($cde);
#var_dump($api->fetchApiInfo());

?>
