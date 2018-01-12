<?php
include_once("../scripts/commonScanFunctions.php");
$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id", array(':bundle' => 'domain_scan_information'));
foreach ($query as $result) {
  $dnode = node_load($result->entity_id);

  print $result->entity_id."\n";
  $spRawOut = json_decode($dnode->field_site_inspector_raw_out['und'][0]['value'],true);
  $dnsssec = $spRawOut['canonical_endpoint']['dns']['dnssec'];
  $ipv6 = $spRawOut['canonical_endpoint']['dns']['ipv6'];
  print "$dnsssec - $ipv6 \n";
  $dnode->field_ipv6_compliance['und'][0]['value'] = ($ipv6 == '')?0:1;
  $dnode->field_dnssec_compliance['und'][0]['value'] = ($dnsssec == '')?0:1;
  node_object_prepare($dnode);
  if ($dnode = node_submit($dnode)) {
    node_save($dnode);
  }
}
?>
