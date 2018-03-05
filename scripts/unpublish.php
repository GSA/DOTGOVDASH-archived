<?php

/*
 * Unpublish all website nodes and related scan nodes which are not in pulse.
 */
include_once("../scripts/commonScanFunctions.php");

//Find all websites and their child scan nodes to be unpublished
$query = db_query("select a.nid as websiteid,b.entity_id as scanids from node a , field_data_field_website_id  b where a.type='website' and a.title not in (select domain from custom_pulse_https_data) and a.nid=b.field_website_id_nid");
foreach ($query as $result) {
    $parent_websites[] = $result->websiteid;
    $child_scans[] = $result->scanids;
}
$unpublish_nodes = array_merge(array_unique($parent_websites),$child_scans);
foreach($unpublish_nodes as $key=>$nid){
        // Load a node
        $node = node_load($nid);
        // set status property to 0
        $node->status = 0;
        // re-save the node
        node_save($node);
        print "unpublished ".$node->title." ".$node->nid." of type".$node->type."\n";

}
;?>

