<?php
include_once("../scripts/commonScanFunctions.php");
//$query = db_query("select a.entity_id,b.title,c.field_website_id_nid from field_data_body a , node b, field_data_field_website_id c where a.bundle=:bundle and b.nid=a.entity_id and a.entity_id=c.entity_id and b.title='Domain Scan alzheimers.gov'", array(':bundle' => 'domain_scan_information'));
$query = db_query("select a.entity_id,b.title,c.field_website_id_nid from field_data_body a , node b, field_data_field_website_id c where a.bundle=:bundle and b.nid=a.entity_id and a.entity_id=c.entity_id", array(':bundle' => 'domain_scan_information'));
foreach ($query as $result) {
    $tags = array();
        $domname = explode("Domain Scan ",$result->title);
        $domname1 = $domname[1];
    $ipv6nistret = getIPv6StatfromNIST($domname1);
  $dnode = node_load($result->entity_id);
  $pnode = node_load($result->field_website_id_nid);
 if(($ipv6nistret == '') || ($ipv6nistret == '0'))
        $dnode->field_ipv6_compliance['und'][0]['value'] = 0;
    else
        $dnode->field_ipv6_compliance['und'][0]['value'] = 1;
 if($ipv6nistret == '1') {
        $tags[] = 'IPV6';
        $pnode->field_ipv6_score['und'][0]['value'] = '100';
    }
    else
        $pnode->field_ipv6_score['und'][0]['value'] = '0';
 //Save Tags to parent website
    if(!empty($tags)) {
        if(!empty($pnode->field_website_tags)){
            foreach($pnode->field_website_tags['und'] as $ctk  =>$ctval){
                $currentTerms[] = $ctval['tid'];
            }
            $crnTermCnt = count($currentTerms);
        }
        $i = 1;
                 if($ipv6nistret == '1') {
                    $pnode->field_website_tags['und'][$crnTermCnt+$i]['tid'] = '308';
                }
    }

//print_r($pnode->field_website_tags);
  print $result->title."-- $domname1 -- ".$result->entity_id."--".$result->field_website_id_nid." --   $ipv6nistret -- ".$dnode->field_ipv6_score['und'][0]['value']."--".  $pnode->field_ipv6_compliance['und'][0]['value']." \n";
  node_object_prepare($dnode);
  if ($dnode = node_submit($dnode)) {
    node_save($dnode);
  }
  node_object_prepare($pnode);
  if ($pnode = node_submit($pnode)) {
    node_save($pnode);
  }

}
archiveGovwideTrendData();
archiveAgencywideTrendData();

?>
