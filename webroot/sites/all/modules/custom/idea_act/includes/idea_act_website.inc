<?php

function ideaact_get_website_data($websiteid){
  $websitedata = array();
  $websitedata['websiteid'] = $websiteid;

  $wnode = node_load(arg(3));

  #website header info
  $websitedata['websitename'] = $wnode->body['und'][0]['value'];
  $websitedata['agencyname'] = $wnode->field_parent_agency_name['und'][0]['value'];
  $websitedata['agencyid'] = $wnode->field_web_agency_id['und'][0]['nid'];
  $websitedata['agencylogo'] = '';
  $websitedata['agencyacr'] = '';
  $agencynode = node_load($websitedata['agencyid'] );
  if ($agencynode->field_agency_logo['und'][0]['uri'] != '') {
    $logo_url = file_create_url($agencynode->field_agency_logo['und'][0]['uri']);
    $websitedata['agencylogo'] = "<img src='". $logo_url ."' alt='".$websitedata['agencyname']."' width='100'>";
  } 
  if ($agencynode->field_agency_code['und'][0]['value'] != '') {
    $acronym_name = $agencynode->field_agency_code['und'][0]['value'];
    // $websitedata['agencyacr'] = $agencynode->field_agency_code['und'][0]['value'];
    $websitedata['agencyacr'] = "<p class='acr-wrap'>".$acronym_name."</p>";

  } 
  
#uswds code results
  $scanids = dotgov_common_siteAsocScanids(arg(3));
  $scanpath = drupal_get_path_alias("node/" . $scanids['uswds_scan']);

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
    $websitedata['onsiteengine']='Not Applicable';
    $websitedata['onsitetext'] = 'The Metric is not applicable for this website (This website is a redirect).';
  }

  #Security Information
  if(!is_redirect($websiteid)) {
    if ($wnode ->field_m15_13_compliance_score['und'][0]['value'] == 0){
      $websitedata['m1513status'] = 'Non Complaint';
      $websitedata['HttpsStatus'] = $wnode -> field_m15_13_compliance_score['und'][0]['value'];
      $websitedata['EnforceHttps'] = 'This website has an on-site search.';
    }
    elseif($wnode ->field_m15_13_compliance_score['und'][0]['value'] == 100){
      $websitedata['m1513status'] = 'Complaint';
      $websitedata['HttpsStatus'] = $wnode -> field_m15_13_compliance_score['und'][0]['value'];
      $websitedata['EnforceHttps'] = 'This website has an on-site search.';
    }
    else{
      $websitedata['m1513status'] = 'Data Not Available';
      $websitedata['HttpsStatus'] = 'Not Available';
      $websitedata['EnforceHttps'] = 'This website has an no on-site search.';
    }
  }
  else{
    $websitedata['m1513status'] = 'Website Redirect - Metric Not Applicable';
    $websitedata['HttpsStatus']='Not Applicable';
    $websitedata['EnforceHttps'] = 'The Metric is not applicable for this website (This website is a redirect).';

  }

  #free secure protocols
  if(!is_redirect($websiteid)) {
    if ($wnode ->field_free_of_insecr_prot_score['und'][0]['value'] == 0){
      $websitedata['Freestatus'] = 'No';
    }
    elseif ($wnode ->field_free_of_insecr_prot_score['und'][0]['value'] == 100){
      $websitedata['Freestatus'] = 'Yes';
    }
    else{
      $websitedata['Freestatus'] = 'Data Not Available';
    }
  }
  else{
    $websitedata['Freestatus']  = 'Website Redirect - Metric Not Applicable';
//    $websitedata['onsiteengine']='Not Applicabale';
//    $websitedata['Freestatus']  = 'The Metric is not applicable for this website (This website is a redirect).';
  }



  # Mobile Information
  if(!is_redirect($websiteid)) {
    if ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Poor') {
      $websitedata['mobileperf'] = 'Poor';
      $websitedata['mobileperftext'] = 'This website is not responsive';
    } elseif ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Good') {
      $websitedata['mobileperf'] = 'Good';
      $websitedata['mobileperftext'] = 'This website is very responsive';
    } elseif ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Needs Improvement') {
      $websitedata['mobileperf'] = 'Needs Improvement';
      $websitedata['mobileperftext'] = 'This website is responsive';
    } else {
      $websitedata['mobileperf'] = 'Not Available';
      $websitedata['mobileperftext'] = 'Mobile Performance Data is not Available';
    }
  }
  else{
    $websitedata['mobileperf'] = 'Website Redirect - Metric Not Applicable';
    $websitedata['mobileperftext'] = 'The Metric is not applicable for this website (This website is a redirect).';
  }


  # Mobile Usability Information
  if(!is_redirect($websiteid)) {
    if ($wnode->field_mobile_usability_status['und'][0]['safe_value'] == 'Not Mobile Friendly') {
      $websitedata['mobileusab'] = 'Not Mobile Friendly';
      $websitedata['mobileusabtext'] = 'Not Mobile Friendly';
    } elseif ($wnode->field_mobile_usability_status['und'][0]['safe_value'] == 'Mobile Friendly') {
      $websitedata['mobileusab'] = 'Mobile Friendly';
      $websitedata['mobileusabtext'] = 'Mobile Friendly';
    } else {
      $websitedata['mobileusab'] = 'Not Available';
      $websitedata['mobileusabtext'] = 'Mobile Usablity data is not Available';
    }
  }
  else{
//    $websitedata['mobileusab'] = 'Website Redirect - Metric Not Applicable';
//    $websitedata['mobileusabtext'] = 'The Metric is not applicable for this website (This website is a redirect).';
  }

  return $websitedata;
}

