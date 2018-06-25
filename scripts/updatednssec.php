<?php
include_once("../scripts/commonScanFunctions.php");
$query = db_query("select entity_id from field_data_field_dnssec_score where field_dnssec_score_value='0'");
foreach ($query as $result) {
#  $dnode = node_load($result->entity_id);
print $result->entity_id." \n"; 
  #$dnode->field_dnssec_compliance['und'][0]['value'] = ($dnsssec == '')?0:1;
  #node_object_prepare($dnode);
  #if ($dnode = node_submit($dnode)) {
  #  node_save($dnode);
  #}
}
?>
