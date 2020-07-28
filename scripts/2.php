<?php
include_once("../scripts/commonScanFunctions.php");
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id  and b.status='1'", array(':bundle' => 'mobile_scan_information'));
//foreach ($query as $result) {
//    $node = node_load($result->entity_id);
//    $parentwebsite = $node->field_website_id['und'][0]['nid'];
//    $wnode = node_load($parentwebsite);
//    $field_mobile_performance_score =$node->field_mobile_performance_score['und'][0]['value'];
//    $field_mobile_usability_score = $node->field_mobile_usability_score['und'][0]['value'];
//
//    if($field_mobile_performance_score == NULL)
//        $field_mobile_perf_status = NULL;
//    elseif(($field_mobile_performance_score >= "0") && ($field_mobile_performance_score <50)){
//        $field_mobile_perf_status = "Poor";
//    }
//    elseif(($field_mobile_performance_score >= "50") && ($field_mobile_performance_score <90)){
//        $field_mobile_perf_status = "Needs Improvement";
//    }
//    elseif(($field_mobile_performance_score >= "90") && ($field_mobile_performance_score <100)){
//        $field_mobile_perf_status = "Good";
//    }
//    if($field_mobile_usability_score == NULL)
//        $field_mobile_usab_status = NULL;
//    elseif($field_mobile_usability_score == "0"){
//        $field_mobile_usab_status = "Not Mobile Friendly";
//    }
//    elseif($field_mobile_usability_score == "100"){
//        $field_mobile_usab_status = "Mobile Friendly";
//        //Add tag if the site is mobile friendly
//        $tags[] = "MOBILE";
//    }
//    $node->field_mobile_performance_status['und'][0]['value'] = $field_mobile_perf_status;
//    $node->field_mobile_usability_status['und'][0]['value'] = $field_mobile_usab_status;
//    node_object_prepare($node);
//    if ($node = node_submit($node)) {
//        node_save($node);
//    }
//    $wnode->field_mobile_performance_status['und'][0]['value'] = $field_mobile_perf_status;
//    $wnode->field_mobile_usability_status['und'][0]['value'] = $field_mobile_usab_status;
//    if ($wnode = node_submit($wnode)) {
//        node_save($wnode);
//    }
//    print $result->title."--".$result->entity_id."-- $parentwebsite -- $field_mobile_performance_score - $field_mobile_perf_status -- $field_mobile_usability_score - $field_mobile_usab_status \n";
//}
archiveGovwideTrendData();
archiveAgencywideTrendData();
?>
