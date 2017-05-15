<?php
/*
 * The Script to initiate scan. Pass through all url entities and and capture necessary data
 * 1.Snapshots needs to be created in webroot/sites/default/files/tmp/snapshots and then moved to webroot/sites/default/files/snapshots when they are saved in the node. Remove tmp files after processing is done.
 */
include_once("../scripts/commonScanFunctions.php");
$listWebsites = getSites();
foreach($listWebsites as $key=>$val){
    print $val."\n";
    print "Generating Snapshot for site $val \n";
    exec("pageres ". $val. " --format=jpg --filename=\"sites/default/files/tmp/snapshots/<%= url %>\"");
}
print "Finished Processing!\n";


