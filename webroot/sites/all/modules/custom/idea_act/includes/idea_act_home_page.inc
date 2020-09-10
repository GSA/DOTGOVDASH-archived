<?php 
function idea_act_home_AgencyData() {
    $agencies_db_res = db_query("select node.nid as nid, node.title as node_title, field_data_field_agency_logo.field_agency_logo_fid as fid, type as field_data_field_agency_logo_node_entity_type FROM node LEFT JOIN field_data_field_agency_logo ON node.nid = field_data_field_agency_logo.entity_id WHERE (( (node.status = '1') AND (node.type IN ('agency')) AND (field_data_field_agency_logo.field_agency_logo_alt NOT LIKE 'null') ))")->fetchAll();
    $agencies = [];
    foreach ($agencies_db_res as $agency){
      $agency_data['nid'] =  $agency->nid;
      $agency_data['title'] =  $agency->node_title;
      $agency_data['url'] =  idea_act_agency_logo($agency->fid);
      $agency_data['websitenos'] = idea_act_websitenos($agency->nid);
      $agencies['agency_data'][] = $agency_data;
    }
     $count = idea_act_websites_agency_info();
     $agencies['total_websites_count']['total_agencies'] = $count[0]->type_count;
     $agencies['total_websites_count']['total_websites'] = $count[1]->type_count;
     //print "<pre>";  print_r($agencies); print "</pre>"; exit;
    return $agencies;
  }


function idea_act_agency_logo($fileid) {
    $file = file_load($fileid);
    $uri = $file->uri;
    return $url = file_create_url($uri);
}

function idea_act_websitenos($agencyid) {
    $websitenos = db_query("SELECT num_of_websites FROM custom_agencywide_archive where date = (select max(date) from custom_agencywide_archive) and agency_id = :agencyid",array(':agencyid' => $agencyid))->fetchField();
    return $websitenos;
}

function idea_act_websites_agency_info() {
    $total_webistes_agencies = db_query("SELECT node.type AS type, COUNT(node.type) AS type_count FROM node LEFT JOIN field_data_field_agency_branch ON node.nid = field_data_field_agency_branch.entity_id AND (field_data_field_agency_branch.entity_type = 'node' AND field_data_field_agency_branch.deleted = '0') WHERE (( (node.status = '1') AND (node.type IN  ('agency', 'website')) AND (field_data_field_agency_branch.field_agency_branch_value LIKE 'executive') )) GROUP BY node.type LIMIT 10 OFFSET 0")->fetchAll();
    return $total_webistes_agencies;
}
