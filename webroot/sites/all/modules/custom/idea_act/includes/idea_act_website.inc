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
  $websitedata['agency_header_info'] = '';
  $httpsid = $wnode -> field_https_scan_node['und'][0]['target_id'];
  $httpsnode = node_load($httpsid );
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
  if($agencynode->field_agency_logo['und'][0]['uri'] != '') {
    $websitedata['agency_header_info'] = "<div class='col-sm-3'>".$websitedata['agencylogo']."</div>
    <div class='col-sm-9'>
        <p class='fs-1-5 agency-overview-title'><b>".$websitedata['agencyname']."</b></p>
    </div>";
  } else {
    $websitedata['agency_header_info'] = "<div class='col-sm-12'>
        <p class='fs-1-5 agency-overview-title'><b>".$websitedata['agencyname']."</b></p>
    </div>";
  }

#uswds code results
  $scanids = dotgov_common_siteAsocScanids(arg(3));
  $scanpath = drupal_get_path_alias("node/" . $scanids['uswds_scan']);

  $websitedata['uswdsscore'] = db_query("select a.field_uswds_score_value from field_data_field_uswds_score a , field_data_field_uswds_status b,field_data_field_website_id c where a.entity_id=c.field_website_id_nid and b.entity_id=c.entity_id and a.entity_id=:nid", array(":nid" => $websiteid))->fetchField();
  if(!is_redirect($websiteid)) {
    if ($websitedata['uswdsscore'] == NULL || $websitedata['uswdsscore'] == '') {
      $websitedata['uswdsstatus'] = "Data Not Available";
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
    $websitedata['uswdstext'] = 'The metric is not applicable for this website (This website is a redirect).';

  }

  #Onsite Search
  if(!is_redirect($websiteid)) {
    if ($wnode ->field_search_status['und'][0]['value'] > 0){
      $websitedata['onsitestatus'] = 'Detected';
      $websitedata['onsiteengine'] = $wnode -> field_search_engine_name['und'][0]['value'];
      $websitedata['onsitetext'] = 'On-site Search detected for this website.';
      if($wnode -> field_search_engine_name['und'][0]['value'] == NULL || ''){
        $websitedata['onsiteengine'] = 'Data Not Available';
      }
    }
    else{
      $websitedata['onsitestatus'] = 'Not Detected';
      $websitedata['onsiteengine'] = 'Data Not Available';
      $websitedata['onsitetext'] = 'On-site Search not detected for this website.';
    }
  }
  else{
    $websitedata['onsitestatus'] = 'Website Redirect - Metric Not Applicable';
    $websitedata['onsiteengine']='Not Applicable';
    $websitedata['onsitetext'] = 'The metric is not applicable for this website (This website is a redirect).';
  }

  #Security Information

    if ($wnode ->field_m15_13_compliance_score['und'][0]['value'] == 0){
      $websitedata['m1513status'] = 'Non Compliant';
    }
    if($wnode ->field_m15_13_compliance_score['und'][0]['value'] == 100){
      $websitedata['m1513status'] = 'Compliant';
    }
    if($wnode ->field_m15_13_compliance_score['und'][0]['value'] == NULL || $wnode ->field_m15_13_compliance_score['und'][0]['value'] ==  ''){
      $websitedata['m1513status'] = 'Data Not Available';
    }

  #free secure protocols

    if ($wnode ->field_free_of_insecr_prot_score['und'][0]['value'] == 0){
      $websitedata['Freestatus'] = 'No';
    }
    if ($wnode ->field_free_of_insecr_prot_score['und'][0]['value'] == 100){
      $websitedata['Freestatus'] = 'Yes';
    }
    if($wnode ->field_free_of_insecr_prot_score['und'][0]['value'] == NULL || $wnode ->field_free_of_insecr_prot_score['und'][0]['value'] ==  ''){
      $websitedata['Freestatus'] = 'Data Not Available';
    }

  $websitedata['EnforceHttps'] =$httpsnode -> field_enforce_https['und'][0]['value'];

  if ($httpsnode -> field_enforce_https['und'][0]['value']== NULL || $httpsnode -> field_enforce_https['und'][0]['value']== ''){
    $websitedata['EnforceHttps'] = 'Data Not Available';
  }

  if ($httpsnode -> field_https_status['und'][0]['value'] =='Yes'){
    $websitedata['HttpsStatus'] = 'Enabled';
  }
  elseif ($httpsnode -> field_https_status['und'][0]['value'] =='No') {
    $websitedata['HttpsStatus'] = 'Not Enabled';
  }
  else{
    $websitedata['HttpsStatus'] = 'Data Not Available';

  }

  if ( $websitedata['HttpsStatus'] == 'Enabled' && $websitedata['EnforceHttps'] == 'Yes'){
    $websitedata['Securitytext'] = 'This website meets the security requirements. Data on the left shows the evaluation criteria.';
  }

  else{
    $websitedata['Securitytext'] = 'Data on the left shows the evaluation criteria.';
  }
  # Mobile Information
  if(!is_redirect($websiteid)) {
    if ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Poor') {
      $websitedata['mobileperf'] = 'Poor';
    } elseif ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Good') {
      $websitedata['mobileperf'] = 'Good';
    } elseif ($wnode->field_mobile_performance_status['und'][0]['safe_value'] == 'Needs Improvement') {
      $websitedata['mobileperf'] = 'Needs Improvement';
    } else {
      $websitedata['mobileperf'] = 'Data Not Available';
    }
  }
  else{
    $websitedata['mobileperf'] = 'Website Redirect - Metric Not Applicable';
  }


  # Mobile Usability Information
  if(!is_redirect($websiteid)) {
    if ($wnode->field_mobile_usability_status['und'][0]['safe_value'] == 'Not Mobile Friendly') {
      $websitedata['mobileusab'] = 'Not Mobile Friendly';
    } elseif ($wnode->field_mobile_usability_status['und'][0]['safe_value'] == 'Mobile Friendly') {
      $websitedata['mobileusab'] = 'Mobile Friendly';
    } else {
      $websitedata['mobileusab'] = 'Data Not Available';
    }
  }
  else{
    $websitedata['mobileusab'] = 'Website Redirect - Metric Not Applicable';
  }

  if($websitedata['mobileperf'] == 'Good' || $websitedata['mobileperf'] == 'Needs Improvement'){
    if($websitedata['mobileusab'] == 'Not Mobile Friendly'){
      $websitedata['mobtext']= 'This website is responsive but not mobile friendly.';
    }
    if($websitedata['mobileusab'] == 'Data Not Available'){
      $websitedata['mobtext']= 'This website is responsive but does not have available data for the mobile usability.';
    }
    if($websitedata['mobileusab'] == 'Mobile Friendly') {
      $websitedata['mobtext'] = 'This website is responsive and mobile friendly.';
    }
  }
  if($websitedata['mobileperf'] == 'Poor'){
    if($websitedata['mobileusab'] == 'Not Mobile Friendly'){
      $websitedata['mobtext']= 'This website is not responsive and not mobile friendly.';
    }
    if($websitedata['mobileusab'] == 'Data Not Available'){
      $websitedata['mobtext']= 'This website is not responsive and does not have available data for the mobile usability.';
    }
    if($websitedata['mobileusab'] == 'Mobile Friendly') {
      $websitedata['mobtext'] = 'This website is not responsive but it is mobile friendly.';
    }
  }
  if($websitedata['mobileperf'] == 'Data Not Available'){
    if($websitedata['mobileusab'] == 'Not Mobile Friendly'){
      $websitedata['mobtext']= 'This website does not have available data for responsiveness, and not mobile friendly.' ;
    }
    if($websitedata['mobileusab'] == 'Data Not Available'){
      $websitedata['mobtext']= 'This website does not have available data for responsiveness and does not have available data for mobile usability.';
    }
    if($websitedata['mobileusab'] == 'Mobile Friendly') {
      $websitedata['mobtext'] = 'This website does not have available data for responsiveness, but it is mobile friendly.';
    }
  }
  if($websitedata['mobileperf'] == 'Website Redirect - Metric Not Applicable' && $websitedata['mobileusab'] == "Website Redirect - Metric Not Applicable") {
    $websitedata['mobtext'] = 'The metric is not applicable for this website (This website is a redirect).';
  }
#Accessibility issues
    $acessresults = db_query("select c.field_accessible_group_colorcont_value,d.field_accessible_group_missingim_value,e.field_accessible_group_htmlattri_value from node a , field_data_field_website_id b , field_data_field_accessible_group_colorcont c,field_data_field_accessible_group_missingim d,field_data_field_accessible_group_htmlattri e  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and b.entity_id=d.entity_id and b.entity_id=e.entity_id and b.field_website_id_nid=:websiteid", array(':websiteid' => $websiteid));
    #Accessibility
    foreach ($acessresults as $acesssresult) {

      $websitedata['colorcont']  = $acesssresult->field_accessible_group_colorcont_value;
      $websitedata['htmlattri'] = $acesssresult->field_accessible_group_htmlattri_value;
      $websitedata['missingim'] = $acesssresult ->field_accessible_group_missingim_value;
      $websitedata['Accestext'] = 'This website' .  $websitedata['missingim'] . 'issues with missing image descriptions,' . $websitedata['htmlattri'] . 'issues with HTML attributes and' . $websitedata['colorcont'].'issues with color contrast.' ;
      $websitedata['web-access-chart']  = "<div class='chart-container' id ='chart-11-ref'><canvas id='chart-webhome' width='250' height='300' aria-label='Charts' role='img'></canvas></div><div class='legend-container'><div id='chart-1-legend'></div></div>";
    }
    if(!is_redirect($websiteid) && !empty($acesssresult)) {
      if ($websitedata['colorcont'] == NULL || $websitedata['colorcont'] == '') {
        $websitedata['colorcont'] = 0;

      }
      if ($websitedata['htmlattri'] == NULL || $websitedata['htmlattri'] == '') {
        $websitedata['htmlattri'] = 0;

      }
      if ($websitedata['missingim'] == NULL || $websitedata['missingim'] == '') {
        $websitedata['missingim'] = 0;

      }
      if ( $websitedata['colorcont'] == 0 && $websitedata['htmlattri'] == 0 &&   $websitedata['missingim'] == 0) {
        $websitedata['web-access-chart'] = "<div class='text-center'>
        <img src='/sites/all/modules/custom/idea_act/images/zero-percent-chart.png' width='250' height='250' class='alternate-chart-responsive'>
   </div>";
      }
      $websitedata['Accestext'] = 'This website has ' . $websitedata['missingim'] . ' issues with missing image descriptions, ' . $websitedata['htmlattri'] . ' issues with HTML attributes and ' . $websitedata['colorcont'] . ' issues with color contrast.';

    }
    elseif(empty($acesssresult)){
        $websitedata['web-access-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/not-available-chart.png' width='250' height='250' class='alternate-chart-responsive'>
 </div>";
        $websitedata['Accestext'] = "Data is Not Available for this website.";
    }
    else {
      $websitedata['Accestext'] = 'The metric is not applicable for this website (This website is a redirect).';
      $websitedata['web-access-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/not-available-chart.png' width='250' height='250' class='alternate-chart-responsive'>
 </div>";
    }
  return $websitedata;
}

