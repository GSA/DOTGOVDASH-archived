<?php

include_once("../scripts/commonScanFunctions.php");

function readCSV($csvFile){
    $file_handle = fopen($csvFile, 'r');
    while (!feof($file_handle) ) {
        $line_of_text[] = fgetcsv($file_handle, 1024);
    }
    fclose($file_handle);
    return $line_of_text;
}


// Set path to CSV file
$csvFile = '../scripts/websiteListing.csv';

$csv = readCSV($csvFile);

$i =1;
foreach($csv as $csval){
    print "$csval[0] \n";
    if((($nodeId = findNode($csval[0],'website')) == FALSE) && ($csval[0] != '')){

    $node = new stdClass();  // Create a new node object
    $node->type = 'website';  // Content type
    $node->language = LANGUAGE_NONE;  // Or e.g. 'en' if locale is enabled

    $node->title = $csval[0];

    $node->body[$node->language][0]['value'] = $csval[1];
    //Check if the Agency exists if not create a new agency
    if(($agencyId = findNode($csval[3],'agency')) != FALSE){
        echo "found agency $agencyId";
        $node->field_web_parent_agency[$node->language][0]['nid'] = $agencyId;
    }
    else{
        //Create new agnecy
        $anode = new stdClass();  // Create a new node object
        $anode->type = 'agency';  // Content type
        $anode->language = LANGUAGE_NONE;  // Or e.g. 'en' if locale is enabled

        $anode->title = $csval[3];
        $anode->status = 1;   // (1 or 0): published or unpublished
        $anode->promote = 0;  // (1 or 0): promoted to front page or not
        $anode->sticky = 0;  // (1 or 0): sticky at top of lists or not
        $anode->comment = 0;  // 2 = comments open, 1 = comments closed, 0 = comments hidden
// Add author of the node
        $anode->uid = "1";
        $anode->name = "admin";
        node_object_prepare($anode);
        if($anode=node_submit($anode)){
            node_save($anode);
        }
        $node->field_web_parent_agency[$node->language][0]['nid'] = $anode->nid;
    }

    $node->field_parent_agency_name[$node->language][0]['value'] = $csval[3];

    $node->field_website_type[$node->language][0]['value'] = "full";

    $node->status = 1;   // (1 or 0): published or unpublished
    $node->promote = 0;  // (1 or 0): promoted to front page or not
    $node->sticky = 0;  // (1 or 0): sticky at top of lists or not
    $node->comment = 0;  // 2 = comments open, 1 = comments closed, 0 = comments hidden
// Add author of the node
    $node->uid = "1";
    $node->name = "admin";
    node_object_prepare($node);  //Set some default values

// Save the node
        if($node=node_submit($node)){
            node_save($node);
        }

    $i++;
}
}
