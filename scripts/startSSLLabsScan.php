<?php
/*
 * The Script to initiate scan. Pass through all url entities and and capture necessary data
 * 1.Snapshots needs to be created in webroot/sites/default/files/tmp/snapshots and then moved to webroot/sites/default/files/snapshots when they are saved in the node. Remove tmp files after processing is done.
 */
include_once("../scripts/commonScanFunctions.php");
$listWebsites = getSites();
writeToLogs("Start SSL labs Scan",$logFile);
$websiteListFile = "sites/default/files/websiteListFile.txt";
unlink($websiteListFile);
foreach($listWebsites as $key=>$val){
  if(file_exists($websiteListFile)) {
    file_put_contents($websiteListFile, $val['domain']."\n", FILE_APPEND | LOCK_EX);
  }
  else{
    file_put_contents($websiteListFile, $val['domain']."\n");
  }
}
exec("../tools/ssllabs-scan/ssllabs-scan --grade=true --usecache=true  --hostfile=sites/default/files/websiteListFile.txt");
print "Finished Processing SSL labs!\n";


