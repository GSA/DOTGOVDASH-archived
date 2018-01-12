<?php
include_once("../scripts/commonScanFunctions.php");
$query = db_query("select a.entity_id,a.field_website_id_nid,b.title from field_data_field_website_id a , node b where a.bundle='https_dap_scan_information' and b.nid=a.field_website_id_nid", array(':bundle' => 'https_dap_scan_information'));
//$query = db_query("select a.nid from node a where type=:bundle", array(':bundle' => 'https_dap_scan_information'));
foreach ($query as $result) {
  //$dnode = node_load($result->entity_id);

  print $result->title."\n";
$query1 = db_query("select * from  custom_pulse_https_data where domain=:domain", array(':domain' => $result->title));
  $dapstats= "";
foreach ($query1 as $result1) {
  print $result->entity_id ."-".$result->title ."-". $result1->dap."\n";
  if($result1->dap == 'Yes') {
    $dapstatus = 1;
    $dapscore = '100';
  }
  elseif($result1->dap == 'No') {
    $dapstatus = 0;
    $dapscore = '0';
  }
  else{
    $dapstatus = NULL;
    $dapscore = NULL;
  }
}
  $wnode = node_load($result->entity_id);
  $wnode->field_dap_status['und'][0]['value'] = $dapstatus;
  $wnode->field_dap_score['und'][0]['value'] = $dapscore;
  node_object_prepare($wnode);
  if ($wnode = node_submit($wnode)) {
    node_save($wnode);
  }
  $pnode = node_load($result->field_website_id_nid);
  $pnode->field_dap_score['und'][0]['value'] = $dapscore;
  node_object_prepare($pnode);
  if ($pnode = node_submit($pnode)) {
    node_save($pnode);
  }

}
?>
