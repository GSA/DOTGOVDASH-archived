<?php
include_once("../scripts/commonScanFunctions.php");
//initiateSslLabsHostScan();
$sldat = collectSslLabsDomInfo("ncd.gov");
print_r($sldat);
?>
