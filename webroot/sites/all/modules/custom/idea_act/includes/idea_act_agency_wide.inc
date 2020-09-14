<?php

function ideaact_get_agencywide_data($agencyid){
  $agency_data = array();
  $agency_data['agencyid'] = $agencyid;

  $agency_data['no_of_websites']=  db_query("SELECT num_of_websites FROM custom_agencywide_archive where date = (select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  //Query to get USWDS for Agency
  $uswdsresults = db_query("select field_uswds_score_value,count(field_uswds_score_value)  as complnum from field_data_field_uswds_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid group by field_uswds_score_value", array(':agencyid' => $agencyid));
  foreach ($uswdsresults as $uswdsresult) {
    if($uswdsresult->field_uswds_score_value == '100')
      $agency_data['uswds_compliant'] += $uswdsresult->complnum;
    if($uswdsresult->field_uswds_score_value == '0')
      $agency_data['uswds_noncompliant'] += $uswdsresult->complnum;
    $agency_data['uswds_tottracked'] += $uswdsresult->complnum;
  }

  $agency_data['uswds_na']= $agency_data['no_of_websites'] -  $agency_data['uswds_tottracked'];

  if($agency_data['uswds_na'] != 0) {
    $agency_data['uswds_na_label'] = 'Data Not Available';
    $agency_data['uswds_na_color'] = '#8168B3';
  } else {
    $agency_data['uswds_na_label'] = '';
    $agency_data['uswds_na_color'] = '';
  }

  #zero case graph
  $agency_data['uswds-chart'] = '';
  if($agency_data['uswds_compliant'] == 0 &&
    $agency_data['uswds_noncompliant'] == 0 &&
    $agency_data['uswds_na'] == 0) {
    $agency_data['uswds-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-percent-chart.png' width='250' height='300' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['uswds-chart'] = "<div class='chart-container' id='chart-2-ref'>
    <canvas id='chart-gov2' width='250' height='300' aria-label='Charts' role='img'></canvas>
</div>
<div id='chart-2-legend-mobile'></div>";
  }


  //Query to get HTTPS status  data
  $httpsresults = db_query("select field_https_status_value,count(field_https_status_value)  as complnum from node a , field_data_field_https_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='https_dap_scan_information'  group by field_https_status_value
", array(':agencyid' => $agencyid));
  foreach ($httpsresults as $httpsresult) {
    if($httpsresult->field_https_status_value == 'Yes')
      $agency_data['https_support'] += $httpsresult->complnum;
    else
      $agency_data['https_nosupport'] += $httpsresult->complnum;
  }

  $agency_data['https_na']= $agency_data['no_of_websites'] - ( $agency_data['https_support']+$agency_data['https_nosupport']);
  if($agency_data['https_na'] != 0) {
    $agency_data['https_na_color'] = '#8168B3';
    $agency_data['https_na_label'] = 'Data Not Available';
  } else {
    $agency_data['https_na_color'] = '';
    $agency_data['https_na_label'] = '';
  }
  #zero case graph
  $agency_data['https-chart'] = '';
  if($agency_data['https_support'] == 0 &&
    $agency_data['https_nosupport'] == 0 &&
    $agency_data['https_na'] == 0) {
    $agency_data['httpss-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-chart.png' width='250' height='300' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['https-chart'] = "<div class='chart-container' id='chart-3-ref'>
    <canvas id='chart-gov3' width='250' height='300' aria-label='Charts' role='img'></canvas>
</div>
<div id='chart-3-legend-mobile'></div>";

  }

//  #Accessbility spot checks
  $ag_avrg_color_cont =  round(db_query("select sum(c.field_accessible_group_colorcont_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_colorcont c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => $agencyid))->fetchField());
  $ag_avrg_miss_image =  round(db_query("select sum(c.field_accessible_group_missingim_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_missingim c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => $agencyid))->fetchField());
  $ag_avrg_html_attr =  round(db_query("select sum(c.field_accessible_group_htmlattri_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_htmlattri c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => $agencyid))->fetchField());
  $agency_data['ag_col_contrast'] = $ag_avrg_color_cont;
  $agency_data['ag_miss_image'] = $ag_avrg_miss_image;
  $agency_data['ag_html_attrib'] = $ag_avrg_html_attr;

  $agency_data['access-spot-checks-chart'] = '';
  if($agency_data['ag_col_contrast'] == 0 &&
    $agency_data['ag_miss_image'] == 0 &&
    $agency_data['ag_html_attrib'] == 0) {
      $agency_data['access-spot-checks-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-chart.png' width='250' height='300' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['access-spot-checks-chart'] = "<div class='chart-container' id='chart-1-ref'>
    <canvas id='chart-gov1' width='250' height='300' aria-label='Charts' role='img'></canvas>
</div>
<div id='chart-1-legend-mobile'></div>";
  }

//  Mobile information
  $agency_data['mob_perf_good_nos'] = db_query("SELECT mob_perf_good FROM custom_agencywide_archive where date = (select max(date) from custom_agencywide_archive) and agency_id = :agencyid limit 1",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['mob_perf_improve_nos'] = db_query("SELECT mob_perf_improve FROM custom_agencywide_archive where date =(select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['mob_perf_poor_nos'] = db_query("SELECT mob_perf_poor FROM custom_agencywide_archive where date = (select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['mob_usab_friendly_nos'] = db_query("SELECT mob_usab_friendly FROM custom_agencywide_archive where date =(select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['mob_usab_notfriendly_nos'] = db_query("SELECT mob_usab_nonfriendly FROM custom_agencywide_archive where date=(select max(date) from custom_agencywide_archive)and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['total_websites'] = db_query("SELECT sum(num_of_websites) FROM custom_agencywide_archive where date = (select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
  $agency_data['total_non_na_websites'] = $agency_data['no_of_websites']-($agency_data['mob_perf_good_nos']+ $agency_data['mob_perf_improve_nos']+ $agency_data['mob_perf_poor_nos']);

  if($agency_data['total_non_na_websites'] != 0) {
    $agency_data['total_non_na_websites_label'] ='Data Not Available';
    $agency_data['total_non_na_websites_color'] ='#8168B3';
  } else {
    $agency_data['total_non_na_websites_label'] ='';
    $agency_data['total_non_na_websites_color'] ='';
  }

  $agency_data['usab_null'] = $agency_data['no_of_websites'] - ($agency_data['mob_usab_friendly_nos']+ $agency_data['mob_usab_notfriendly_nos']);

  if($agency_data['usab_null'] !=0) {
    $agency_data['usab_na_label'] ='Data Not Available';
    $agency_data['usab_na_color'] ='#8168B3';
  } else {
    $agency_data['usab_na_label'] ='';
    $agency_data['usab_na_color'] ='';
  }

  $agency_data['mob-perf-chart'] = '';
  if($agency_data['mob_perf_good_nos'] == 0 &&
    $agency_data['mob_perf_improve_nos'] == 0 &&
    $agency_data['total_non_na_websites'] == 0 &&
    $agency_data['mob_perf_poor_nos'] == 0) {
    $agency_data['mob-perf-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-chart.png' width='250' height='250' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['mob-perf-chart'] = "<div class='chart-container' id='chart-5-ref'> <canvas id='chart-6' width='250' height='300' aria-label='Charts role='img'></canvas></div><div class='legend-container'><div id='chart-5-legend'></div></div>
    ";


  }

  $agency_data['mob-usab-chart'] = '';
  if($agency_data['mob_usab_friendly_nos'] == 0 &&
    $agency_data['mob_usab_notfriendly_nos'] == 0 &&
    $agency_data['usab_null'] == 0) {
    $agency_data['mob-usab-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-chart.png' width='250' height='250' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['mob-usab-chart'] = "<div class='chart-container' id='chart-6-ref'>
        <canvas id='chart-5' width='250' height='300' aria-label='Charts' role='img'></canvas>
    </div>
    <div class='legend-container'>
        <div id='chart-6-legend'></div>
    </div>";
  }

  //Query to get Search data for an agency
  $searchresults = db_query("select field_search_status_value,count(field_search_status_value) as complnum from node a , field_data_field_search_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='website' group by field_search_status_value", array(':agencyid' => $agencyid));
  $agency_search_status = array();
  foreach ($searchresults as $searchresult) {
    if($searchresult->field_search_status_value == '1')
      $agency_search_status['search_available'] += $searchresult->complnum;
    if($searchresult->field_search_status_value == '0')
      $agency_search_status['search_notavailable'] += $searchresult->complnum;
  }
  $agency_data['searchenginestatus'] = $agency_search_status;

  $search_status_graph_output = theme('agencywide_searchstatus_page', array('$agency_data' => $agency_search_status));
  $agency_data['searchenginestatus_graph'] = $search_status_graph_output;


  //Query to get Search Engine Name for an agency
  $searchengines = db_query("select field_search_engine_name_value,count(field_search_engine_name_value) as complnum from node a , field_data_field_search_engine_name b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='website' group by field_search_engine_name_value", array(':agencyid' => $agencyid));
  $search_engine_data_for_agencygraph = "";
  $searchenginename = "";
  $searchengine_nos = "";
  foreach ($searchengines as $searchengine) {

    if(($searchengine->field_search_engine_name_value == '') || ($searchengine->field_search_engine_name_value == NULL)) {
      $searchenginename = "None";
      $searchengine_nos +=  $searchengine->complnum;
    }
    else{
      $searchenginename = $searchengine->field_search_engine_name_value;
      $searchengine_nos =  $searchengine->complnum;
      $search_engine_data[$searchenginename] = $searchengine_nos;

    }
  }
  arsort($search_engine_data);
  foreach($search_engine_data as $skey=>$sval){
    $search_engine_data_for_agencygraph .= "['$skey' , $sval],";
  }
  $agency_data['searchenginedata'] = $search_engine_data;
  $search_engine_graph_output = theme('agencywide_searchengines_page', array('search_engine_data_for_agencygraph' => $search_engine_data_for_agencygraph));
  $agency_data['searchengines_graph'] = $search_engine_graph_output;


  //Query to get Search data for an agency
  $searchresults = db_query("select field_search_status_value,count(field_search_status_value) as complnum from node a , field_data_field_search_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='website' group by field_search_status_value", array(':agencyid' => $agencyid));
  $agency_search_status = array();
  foreach ($searchresults as $searchresult) {
    if($searchresult->field_search_status_value == '1')
      $agency_search_status['search_available'] += $searchresult->complnum;
    if($searchresult->field_search_status_value == '0')
      $agency_search_status['search_notavailable'] += $searchresult->complnum;
  }
  $agency_data['searchenginestatus'] = $agency_search_status;

  $search_status_graph_output = theme('agencywide_searchstatus_page', array('$agency_data' => $agency_search_status));
  $agencydata['searchenginestatus_graph'] = $search_status_graph_output;

  //Query to get DAP data
  $dapresults = db_query("select field_dap_score_value,count(field_dap_score_value)  as complnum from field_data_field_dap_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid group by field_dap_score_value", array(':agencyid' => $agencyid));
  foreach ($dapresults as $dapresult) {
    if($dapresult->field_dap_score_value == '100')
      $agency_data['dap_compliant'] += $dapresult->complnum;
    if($dapresult->field_dap_score_value == '0')
      $agency_data['dap_noncompliant'] += $dapresult->complnum;
    $agency_data['dap_tottracked'] += $dapresult->complnum;
  }
  $agency_data['dap_na']= $agency_data['no_of_websites'] -  $agency_data['dap_tottracked'];
  if($agency_data['dap_na'] !=0) {
    $agency_data['dap_label'] = 'Data Not Available';
    $agency_data['dap_color'] = '#8168B3';
  } else {
    $agency_data['dap_label'] = '';
    $agency_data['dap_color'] = '';

  }

  #zero case graph
  $agency_data['dap-chart'] = '';
  if($agency_data['dap_compliant'] == 0 &&
    $agency_data['dap_noncompliant'] == 0 &&
    $agency_data['dap_na'] == 0) {
    $agency_data['dap-chart'] = "<div class='text-center'>
      <img src='/sites/all/modules/custom/idea_act/images/zero-percent-chart.png' width='250' height='300' class='alternate-chart-responsive'>
 </div>";
  } else {
    $agency_data['dap-chart'] = "<div class='chart-container' id='chart-7-ref'>
    <canvas id='chart-gov7' width='250' height='300' aria-label='Charts' role='img'></canvas>
</div>
<div id='chart-7-legend-mobile'></div>";
  }
  return $agency_data;
}

























