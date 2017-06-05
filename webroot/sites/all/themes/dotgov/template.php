<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
drupal_add_js('/sites/all/libraries/highcharts/highcharts.js');
drupal_add_js('https://code.highcharts.com/highcharts-more.js');
drupal_add_js('https://code.highcharts.com/modules/solid-gauge.js');
drupal_add_js('https://www.gstatic.com/charts/loader.js');

function dotgov_common_getMobileSnapshot($websiteid){
    $mobsnap = array();
    $query = db_query("SELECT c.* from field_data_field_mobile_websnapshot a, field_data_field_website_id b,file_managed c where b.field_website_id_nid=:nid and b.bundle='mobile_scan_information' and a.entity_id=b.entity_id and a.field_mobile_websnapshot_fid=c.fid", array(':nid' => $websiteid));
    foreach ($query as $result) {
        $mobsnap['uri'] = $result->uri;
        $mobsnap['fid'] = $result->fid;
    }
    return $mobsnap;
}