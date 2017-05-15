<?php


function readCSV($csvFile){
    $file_handle = fopen($csvFile, 'r');
    while (!feof($file_handle) ) {
        $line_of_text[] = fgetcsv($file_handle, 1024);
    }
    fclose($file_handle);
    return $line_of_text;
}


// Set path to CSV file
$csvFile = '../scripts/Agency_Source_new.csv';

$csv = readCSV($csvFile);

$i =1;
foreach($csv as $csval){
    print "$csval[1] \n";
    $node = new stdClass();  // Create a new node object
    $node->type = 'agency';  // Content type
    $node->language = LANGUAGE_NONE;  // Or e.g. 'en' if locale is enabled
    node_object_prepare($node);  //Set some default values

    $node->title = $csval[1];
    $node->body[$node->language][0]['value'] = $csval[1];
    $node->field_agency_website[$node->language][0]['value'] = $csval[2];
    $node->field_agency_code[$node->language][0]['value'] = $csval[0];

    $node->status = 1;   // (1 or 0): published or unpublished
    $node->promote = 0;  // (1 or 0): promoted to front page or not
    $node->sticky = 0;  // (1 or 0): sticky at top of lists or not
    $node->comment = 1;  // 2 = comments open, 1 = comments closed, 0 = comments hidden
// Add author of the node
    $node->uid = 1;

// Save the node
    node_save($node);

    $i++;
}
