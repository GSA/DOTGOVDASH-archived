<?php
include_once("../scripts/commonScanFunctions.php");
$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.status='1'", array(':bundle' => 'website'));
foreach ($query as $result) {

  $query1 = db_query("select * from  custom_pulse_https_data where domain=:domain", array(':domain' => $result->title));
if($query1->rowCount() > 0){
foreach ($query1 as $result1) {
  if ($result1->Compliant_mbod == 'Yes') {
    $tags[] = 'Compliant with M-15-13 and BOD 18-01';
    $m15_score = '100';
  } elseif ($result1->Compliant_mbod == 'No') {
    $m15_score = '0';
  } else {
    $m15_score = NULL;
  }
  if ($result1->freeofunsecure == 'Yes') {
    $tags[] = 'Free of RC4/3DES and SSLv2/SSLv3';
    $rc4_score = '100';
  } elseif ($result1->freeofunsecure == 'No') {
    $rc4_score = '0';
  } else {
    $rc4_score = NULL;
  }

 // print $result->entity_id . "-" . $result->title . " $result1->Compliant_mbod - $result1->Compliant_mbod - $m15_score -- $rc4_score \n";

//  $wnode = node_load($result->entity_id);
//  $wnode->field_m15_13_compliance_score['und'][0]['value'] = $m15_score;
//  $wnode->field_free_of_insecr_prot_score['und'][0]['value'] = $rc4_score;
//  node_object_prepare($wnode);
//  if ($wnode = node_submit($wnode)) {
//    node_save($wnode);
//  }
}
}
else{
    $httpsid = db_query("select entity_id from field_data_field_website_id where field_website_id_nid=:domain and bundle ='https_dap_scan_information'", array(':domain' => $result->entity_id))->fetchField();
 print $result->entity_id . "-" . $result->title." -- $httpsid\n";
    $wnode = node_load($httpsid);
    $wnode->field_compl_m_15_13_bod['und'][0]['value'] = NULL;
    $wnode->field_free_of_rc4_3des_and_sslv2['und'][0]['value'] = NULL;
    node_object_prepare($wnode);
      if ($wnode = node_submit($wnode)) {
        node_save($wnode);
      }
//  $awnode = node_load($result->entity_id);
//    $awnode->field_m15_13_compliance_score['und'][0]['value'] = NULL;
//    $awnode->field_free_of_insecr_prot_score['und'][0]['value'] = NULL;
//  node_object_prepare($awnode);
//  if ($wnode = node_submit($awnode)) {
//    node_save($awnode);
//  }
}
}
?>

