<?php
include_once("../scripts/commonScanFunctions.php");
$a = getSitePerformanceAPIdata("nccrc.gov");
print_r($a);
//updateSiteScanInfo("acquisition.gov");
//$cdn = findCDNProvider("whitehouse.gov");
//print_r($cdn);
?>
