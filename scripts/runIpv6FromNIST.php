<?php
define('DRUPAL_ROOT', getcwd());

include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

ini_set('memory_limit', '-1');
include_once("../scripts/commonScanFunctions.php");

$query = db_query("select a.entity_id,a.field_website_id_nid,b.title from field_data_field_website_id a , node b where a.bundle=:bundle and b.nid=a.field_website_id_nid", array(':bundle' => 'domain_scan_information'));
//$query = db_query("select a.nid from node a where type=:bundle", array(':bundle' => 'https_dap_scan_information'));
foreach ($query as $result) {
  print "Updating Ipv6 records for domain ".$result->title." \n";
  $ipv6nistret = getIPv6StatfromNIST($result->title);

  $wnode = node_load($result->entity_id);

  if(($ipv6nistret == '') || ($ipv6nistret == '0'))
    $wnode->field_ipv6_compliance['und'][0]['value'] = 0;
  else
    $wnode->field_ipv6_compliance['und'][0]['value'] = 1;

  if($ipv6nistret == '1') {
    $tags[] = 'IPV6';
    $wnode->field_ipv6_score['und'][0]['value'] = '100';
  }
  else
    $wnode->field_ipv6_score['und'][0]['value'] = '0';

  node_object_prepare($wnode);
  if ($wnode = node_submit($wnode)) {
    node_save($wnode);
  }
  $pnode = node_load($result->field_website_id_nid);

  $pnode = node_load($result->field_website_id_nid);
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
    foreach (array_unique($tags) as $key => $tag) {
      if ($term = taxonomy_get_term_by_name($tag)) {
        $terms_array = array_keys($term);
        //Check if the term already assigned to the node
        if(!in_array($terms_array['0'],$currentTerms)){
          $pnode->field_website_tags['und'][$crnTermCnt+$i]['tid'] = $terms_array['0'];
        }
      } else {
        $term = new STDClass();
        $term->name = $tag;
        $term->vid = 3;
        if (!empty($term->name)) {
          taxonomy_term_save($term);
//                        $term = taxonomy_get_term_by_name($tag);
//                        foreach($term as $term_id){
//                            $node->product_tags[LANGUAGE_NONE][$key]['tid'] = $term_id->tid;
//                        }
          $pnode->field_website_tags['und'][$key]['tid'] = $term->tid;
        }
      }
      $i += 1;
    }

  }
  $pnode->field_dap_score['und'][0]['value'] = $dapscore;
  node_object_prepare($pnode);
  if ($pnode = node_submit($pnode)) {
    node_save($pnode);
  }

}
?>
