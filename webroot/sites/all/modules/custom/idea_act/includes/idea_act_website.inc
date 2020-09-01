<?php

function ideaact_get_website_data($websiteid){
  $websitedata = array();
  $websitedata['websiteid'] = $websiteid;

#uswds code results
  $scanids = dotgov_common_siteAsocScanids(arg(3));
  $scanpath = drupal_get_path_alias("node/" . $scanids['uswds_scan']);
  $wnode = node_load(arg(3));

  $websitedata['uswdsscore'] = db_query("select a.field_uswds_score_value from field_data_field_uswds_score a , field_data_field_uswds_status b,field_data_field_website_id c where a.entity_id=c.field_website_id_nid and b.entity_id=c.entity_id and a.entity_id=:nid", array(":nid" => $websiteid))->fetchField();
  if(!is_redirect($websiteid)) {
    if ($websitedata['uswdsscore'] == NULL || $websitedata['uswdsscore'] == '') {
      $websitedata['uswdsstatus'] = "Not Available";
      $websitedata['uswdstext'] = 'Data Not Available for this website.';
    } elseif ($websitedata['uswdsscore'] == '0') {
      $websitedata['uswdsstatus'] = "Not Detected";
      $websitedata['uswdstext'] = 'This website does not have USWDS code present.';
    } elseif ($websitedata['uswdsscore'] == '100') {
      $websitedata['uswdsstatus'] = "Detected";
      $websitedata['uswdstext'] = 'This website has USWDS code present. This does not mean it is fully compliant, but it is on the right track.';
    } else {
      $websitedata['uswdsstatus'] = "Detected";
    }
  }
  else{
    $websitedata['uswdsstatus'] = 'Website Redirect - Metric Not Applicable';
    $websitedata['uswdstext'] = 'The Metric is not applicable for this website (This website is a redirect).';

  }

  #Onsite Search
  if(!is_redirect($websiteid)) {
    if ($wnode ->field_search_status['und'][0]['value'] > 0){
      $websitedata['onsitestatus'] = 'Available';
      $websitedata['onsiteengine'] = $wnode -> field_search_engine_name['und'][0]['value'];
      $websitedata['onsitetext'] = 'This website has an on-site search.';
    }
    else{
      $websitedata['onsitestatus'] = 'Not Available';
      $websitedata['onsiteengine'] = 'Not Available';
      $websitedata['onsitetext'] = 'This website has an no on-site search.';
    }
  }
  else{
    $websitedata['onsitestatus'] = 'Website Redirect - Metric Not Applicable';
    $websitedata['onsiteengine']='Not Applicabale';
    $websitedata['onsitetext'] = 'The Metric is not applicable for this website (This website is a redirect).';
  }


  return $websitedata;
}

