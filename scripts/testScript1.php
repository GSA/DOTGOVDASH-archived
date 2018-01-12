<?php
include_once("../scripts/commonScanFunctions.php");
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id", array(':bundle' => 'domain_scan_information'));
$query = db_query("select a.entity_id,a.body_value,b.title,c.field_website_id_nid from field_data_body a , node b, field_data_field_website_id c where a.bundle=:bundle and b.nid=a.entity_id and a.entity_id=c.entity_id and a.entity_id > 4014 ", array(':bundle' => 'domain_scan_information'));
foreach ($query as $result) {
  $dnode = node_load($result->entity_id);

  print $result->entity_id."\n";
  $spRawOut = json_decode($dnode->field_site_inspector_raw_out['und'][0]['value'],true);
  $dnsssec = $spRawOut['canonical_endpoint']['dns']['dnssec'];
  $ipv6 = $spRawOut['canonical_endpoint']['dns']['ipv6'];
  if($dnsssec == '')
    $dnsscore = "0";
  else
    $dnsscore = "100";
  if($ipv6 == '')
    $ipv6score = "0";
  else
    $ipv6score = "100";

  print "$dnsssec - $ipv6 \n";
  $wnode = node_load($result->field_website_id_nid);
  $wnode->field_ipv6_score['und'][0]['value'] = $ipv6score;
  $wnode->field_dnssec_score['und'][0]['value'] = $dnsscore;
  node_object_prepare($wnode);
  if ($wnode = node_submit($wnode)) {
    node_save($wnode);
  }
}
?>
