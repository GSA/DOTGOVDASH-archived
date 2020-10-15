<?php

function idea_act_govwideTrendData(){
    //Find Number of published websites
    $curdate = date("Y-m-d");
    $websitenos = db_query("select count(*) from node a, field_data_field_agency_branch b where a.type='website' and a.status ='1' and a.nid=b.entity_id and  b.field_agency_branch_value='executive'")->fetchField();
    $agencynos = db_query("select count(*) from node a, field_data_field_agency_branch b where a.type='agency' and a.status ='1' and a.nid=b.entity_id and  b.field_agency_branch_value='executive'")->fetchField();
    $avg_https = round(db_query("select avg(a.field_https_score_value) as avg_value from field_data_field_https_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_dap = round(db_query("select avg(a.field_dap_score_value) as avg_value from field_data_field_dap_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_mob_overall = round(db_query("select avg(a.field_mobile_overall_score_value) as avg_value from field_data_field_mobile_overall_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_mob_perform = round(db_query("select avg(a.field_mobile_performance_score_value) as avg_value from field_data_field_mobile_performance_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_mob_usab = round(db_query("select avg(a.field_mobile_usability_score_value) as avg_value from field_data_field_mobile_usability_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_sitespeed = round(db_query("select avg(a.field_site_speed_score_value) as avg_value from field_data_field_site_speed_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_ipv6 = round(db_query("select avg(a.field_ipv6_score_value) as avg_value from field_data_field_ipv6_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_dnssec = round(db_query("select avg(a.field_dnssec_score_value) as avg_value from field_data_field_dnssec_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_rc4 = round(db_query("select avg(a.field_free_of_insecr_prot_score_value) as avg_value from field_data_field_free_of_insecr_prot_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_m15 = round(db_query("select avg(a.field_m15_13_compliance_score_value) as avg_value from field_data_field_m15_13_compliance_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_uswds = round(db_query("select avg(a.field_uswds_score_value) as avg_value from field_data_field_uswds_score a , node b where a.entity_id=b.nid and b.type='website' and b.status='1'")->fetchField());
    $avg_pocwebsites = round(db_query("select count(field_website_security_poc_statu_value) as avg_value from field_data_field_website_security_poc_statu a , node b where a.entity_id=b.nid and b.type='website' and b.status='1' and field_website_security_poc_statu_value='1'")->fetchField());
    // $govwide_mob['mob_usab_friendly_nos'] = db_query("SELECT mob_usab_friendly FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    // $govwide_mob['mob_usab_notfriendly_nos'] = db_query("SELECT mob_usab_nonfriendly FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    // $govwide_mob['mob_perf_good_nos'] = db_query("SELECT mob_perf_good FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    // $govwide_mob['mob_perf_improve_nos'] = db_query("SELECT mob_perf_improve FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    // $govwide_mob['mob_perf_poor_nos'] = db_query("SELECT mob_perf_poor FROM custom_government_wide_archive order by date desc limit 1")->fetchField();

    $govwidewebsite['websitenos'] = $websitenos;
    $govwidewebsite['agencynos'] = $agencynos;
    $govwidewebsite['avg_https'] = $avg_https;
    $govwidewebsite['avg_dap'] = $avg_dap;
    $govwidewebsite['avg_mob_overall'] = $avg_mob_overall;
    $govwidewebsite['avg_mob_perform'] = $avg_mob_perform;
    $govwidewebsite['avg_mob_usab'] = $avg_mob_usab;
    $govwidewebsite['avg_sitespeed'] = $avg_sitespeed;
    $govwidewebsite['avg_ipv6'] = $avg_ipv6;
    $govwidewebsite['avg_dnssec'] = $avg_dnssec;
    $govwidewebsite['avg_rc4'] = $avg_rc4;
    $govwidewebsite['avg_m15'] = $avg_m15;
    $govwidewebsite['avg_uswds'] = $avg_uswds;
    $govwidewebsite['avg_poc'] = $avg_pocwebsites;
    // $agencydata['poor_nos'] = $govwide_mob['mob_perf_poor_nos'] ;
    // $agencydata['good_nos'] = $govwide_mob['mob_perf_good_nos'] ;
    // $agencydata['improve_nos'] = $govwide_mob['mob_perf_improve_nos'] ;
    // $agencydata['friendly_nos'] = $agency_mob['mob_usab_friendly_nos'] ;
    // $agencydata['nonfriendly_nos'] = $agency_mob['mob_usab_notfriendly_nos'] ;
    return $govwidewebsite;
}

/*
 * Get ALL Agency Data for Government-Wide Report Page
 */

function idea_act_getAllAgencyComplianceData(){
    $agencydata = array();

    //$agencydata['actual_total_websites']= db_query("SELECT num_of_websites FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $agencydata['total_websites']= db_query("select count(*) from node a, field_data_field_agency_branch b where a.type='website' and a.status ='1' and a.nid=b.entity_id and  b.field_agency_branch_value='executive'")->fetchField();

    //Query to get https data
    $httpresults = db_query("select IFNULL(field_https_status_value, 0) as field_https_status_value, count(field_https_status_value) as complnum from node a , field_data_field_https_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information' group by field_https_status_value", array());
    foreach ($httpresults as $httpresult) {
        if($httpresult->field_https_status_value == 'Yes')
            $agencydata['https_compliant'] += $httpresult->complnum;
        if($httpresult->field_https_status_value == 'No')
            $agencydata['https_noncompliant'] += $httpresult->complnum;
    }

    //Query to get DAP data
    $dapresults = db_query("select IFNULL(field_dap_score_value, 0) as field_dap_score_value, count(field_dap_score_value) as complnum from field_data_field_dap_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' group by field_dap_score_value", array());
    foreach ($dapresults as $dapresult) {
        if($dapresult->field_dap_score_value == '100')
            $agencydata['dap_compliant'] += $dapresult->complnum;
        if($dapresult->field_dap_score_value == '0')
            $agencydata['dap_noncompliant'] += $dapresult->complnum;
        $agencydata['dap_tottracked'] += $dapresult->complnum;
    }
    $agencydata['dap_null'] = $agencydata['total_websites']- ($agencydata['dap_compliant'] +$agencydata['dap_noncompliant']);

    if($agencydata['dap_null'] != 0) {
        $agencydata['dap_null_color'] = '#66364b';
        $agencydata['dap_null_label'] = 'Data Not Available';
    } else {
        $agencydata['dap_null_color'] = '';
        $agencydata['dap_null_label'] = '';
    }
    //Query to get DNSSEC data
    $dnsresults = db_query("select IFNULL(field_dnssec_compliance_value, 0) as field_dnssec_compliance_value, count(field_dnssec_compliance_value) as complnum from node a , field_data_field_dnssec_compliance b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='domain_scan_information'  group by field_dnssec_compliance_value", array());
    foreach ($dnsresults as $dnsresult) {
        if($dnsresult->field_dnssec_compliance_value == '1')
            $agencydata['dns_compliant'] += $dnsresult->complnum;
        if($dnsresult->field_dnssec_compliance_value == '0')
            $agencydata['dns_noncompliant'] += $dnsresult->complnum;
    }

    //Query to get IPV6 data
    $ipv6results = db_query("select IFNULL(field_ipv6_compliance_value, 0) as field_ipv6_compliance_value, count(field_ipv6_compliance_value)  as complnum from node a , field_data_field_ipv6_compliance b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='domain_scan_information'  group by field_ipv6_compliance_value", array());
    foreach ($ipv6results as $ipv6result) {
        if($ipv6result->field_ipv6_compliance_value == '1')
            $agencydata['ipv6_compliant'] += $ipv6result->complnum;
        if($ipv6result->field_ipv6_compliance_value == '0')
            $agencydata['ipv6_noncompliant'] += $ipv6result->complnum;
    }

    //Query to get M15-13 data
    $m15results = db_query("select IFNULL(field_compl_m_15_13_bod_value, 0) as field_compl_m_15_13_bod_value, count(field_compl_m_15_13_bod_value) as complnum from node a , field_data_field_compl_m_15_13_bod b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_compl_m_15_13_bod_value", array());
    foreach ($m15results as $m15result) {
        if($m15result->field_compl_m_15_13_bod_value == '1')
            $agencydata['m15_compliant'] += $m15result->complnum;
        if($m15result->field_compl_m_15_13_bod_value == '0')
            $agencydata['m15_noncompliant'] += $m15result->complnum;
        $agencydata['m15_tracked'] += $m15result->complnum;

    }

    //Query to get USWDS for Agency
    $uswdsresults = db_query("select IFNULL(field_uswds_score_value, 0) as field_uswds_score_value, count(field_uswds_score_value) as complnum from field_data_field_uswds_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' group by field_uswds_score_value", array());
    foreach ($uswdsresults as $uswdsresult) {
        if($uswdsresult->field_uswds_score_value == '100')
            $agencydata['uswds_compliant'] += $uswdsresult->complnum;
        if($uswdsresult->field_uswds_score_value == '0')
            $agencydata['uswds_noncompliant'] += $uswdsresult->complnum;
        $agencydata['uswds_tottracked'] += $uswdsresult->complnum;
    }
    $agencydata['uswds_null'] = $agencydata['total_websites']- ($agencydata['uswds_compliant'] +$agencydata['uswds_noncompliant']);
    if($agencydata['uswds_null'] != 0) {
        $agencydata['uswds_null_color']  = '#66364b';
        $agencydata['uswds_null_label'] = 'Data Not Available';
    } else {
        $agencydata['uswds_null_color']  = '';
        $agencydata['uswds_null_label'] = '';
    }

    //Query to get POC data for Agency
    $pocresults = db_query("select field_website_security_poc_statu_value,count(field_website_security_poc_statu_value)  as complnum from field_data_field_website_security_poc_statu a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' group by field_website_security_poc_statu_value");
    foreach ($pocresults as $pocresult) {
        if($pocresult->field_website_security_poc_statu_value == '1')
            $agencydata['poc_present'] += $pocresult->complnum;
        if($pocresult->field_website_security_poc_statu_value == '0')
            $agencydata['poc_notpresent'] += $pocresult->complnum;
        $agencydata['poc_tottracked'] += $pocresult->complnum;
    }

    //Query to get Insecure protocol data
    $insecresults = db_query("select IFNULL(field_free_of_rc4_3des_and_sslv2_value, 0) as field_free_of_rc4_3des_and_sslv2_value, count(field_free_of_rc4_3des_and_sslv2_value) as complnum from node a , field_data_field_free_of_rc4_3des_and_sslv2 b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_free_of_rc4_3des_and_sslv2_value", array());
    foreach ($insecresults as $insecresult) {
        if($insecresult->field_free_of_rc4_3des_and_sslv2_value == '1')
            $agencydata['insec_compliant'] += $insecresult->complnum;
        if($insecresult->field_free_of_rc4_3des_and_sslv2_value == '0')
            $agencydata['insec_noncompliant'] += $insecresult->complnum;
        $agencydata['free_tracked'] += $insecresult->complnum;
    }

    //Query to get SSL v2  data
    $v2results = db_query("select IFNULL(field_ssl_v2_from_pulse_value, 0) as field_ssl_v2_from_pulse_value, count(field_ssl_v2_from_pulse_value) as complnum from node a , field_data_field_ssl_v2_from_pulse b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information' group by field_ssl_v2_from_pulse_value", array());
    foreach ($v2results as $v2result) {
        if($v2result->field_ssl_v2_from_pulse_value == 'Yes')
            $agencydata['v2_support'] += $v2result->complnum;
        else
            $agencydata['v2_nosupport'] += $v2result->complnum;
    }

    //Query to get SSL v3  data
    $v3results = db_query("select IFNULL(field_ssl_v3_from_pulse_value, 0) as field_ssl_v3_from_pulse_value, count(field_ssl_v3_from_pulse_value) as complnum from node a , field_data_field_ssl_v3_from_pulse b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_ssl_v3_from_pulse_value", array());
    foreach ($v3results as $v3result) {
        if($v3result->field_ssl_v3_from_pulse_value == 'Yes')
            $agencydata['v3_support'] += $v3result->complnum;
        else
            $agencydata['v3_nosupport'] += $v3result->complnum;
    }


    //Query to get TLs v1  data
    $tls1results = db_query("select IFNULL(field_tls_v1_support_value, 0) as field_tls_v1_support_value, count(field_tls_v1_support_value) as complnum from node a , field_data_field_tls_v1_support b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='domain_scan_information'  group by field_tls_v1_support_value", array());
    foreach ($tls1results as $tls1result) {
        if($tls1result->field_tls_v1_support_value == '1')
            $agencydata['tlsv1_support'] += $tls1result->complnum;
        else
            $agencydata['tlsv1_nosupport'] += $tls1result->complnum;
    }

    //Query to get TLs v1.1  data
    $tls11results = db_query("select IFNULL(field_tls_v1_1_support_value, 0) as field_tls_v1_1_support_value, count(field_tls_v1_1_support_value) as complnum from node a , field_data_field_tls_v1_1_support b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='domain_scan_information'  group by field_tls_v1_1_support_value", array());
    foreach ($tls11results as $tls11result) {
        if($tls11result->field_tls_v1_1_support_value == '1')
            $agencydata['tlsv11_support'] += $tls11result->complnum;
        else
            $agencydata['tlsv11_nosupport'] += $tls11result->complnum;
    }


    //Query to get SSL v2  data
    $v2results = db_query("select IFNULL(field_ssl_v2_from_pulse_value, 0) as field_ssl_v2_from_pulse_value, count(field_ssl_v2_from_pulse_value) as complnum from node a , field_data_field_ssl_v2_from_pulse b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_ssl_v2_from_pulse_value", array());
    foreach ($v2results as $v2result) {
        if($v2result->field_ssl_v2_from_pulse_value == 'Yes')
            $agencydata['v2_support'] += $v2result->complnum;
        else
            $agencydata['v2_nosupport'] += $v2result->complnum;
    }

    //Query to get Enforce HTTPS  data
    $enfhttpsresults = db_query("select IFNULL(field_enforce_https_value, 0) as field_enforce_https_value, count(field_enforce_https_value) as complnum from node a , field_data_field_enforce_https b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_enforce_https_value", array());
    foreach ($enfhttpsresults as $enfhttpsresult) {
        if($enfhttpsresult->field_enforce_https_value == 'Yes')
            $agencydata['enfhttps_support'] += $enfhttpsresult->complnum;
        else
            $agencydata['enfhttps_nosupport'] += $enfhttpsresult->complnum;
    }

    //Query to get HSTS  data
    $hstsresults = db_query("select IFNULL(field_hsts_status_value, 0) as field_hsts_status_value, count(field_hsts_status_value) as complnum from node a , field_data_field_hsts_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_hsts_status_value", array());
    foreach ($hstsresults as $hstsresult) {
        if($hstsresult->field_hsts_status_value == 'Yes')
            $agencydata['hsts_support'] += $hstsresult->complnum;
        else
            $agencydata['hsts_nosupport'] += $hstsresult->complnum;
    }

    //Query to get HTTPS status  data
    $httpsresults = db_query("select IFNULL(field_https_status_value, 0) as field_https_status_value, count(field_https_status_value) as complnum from node a , field_data_field_https_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_https_status_value", array());
    foreach ($httpsresults as $httpsresult) {
        if($httpsresult->field_https_status_value == 'Yes')
            $agencydata['https_support'] += $httpsresult->complnum;
        else
            $agencydata['https_nosupport'] += $httpsresult->complnum;
    }
    $agencydata['https_null'] = $agencydata['total_websites']- ($agencydata['https_support'] +$agencydata['https_nosupport']);

    if($agencydata['https_null'] != 0) {
        $agencydata['https_null_color'] = '#66364b';
        $agencydata['https_null_label'] = 'Data Not Available';
    } else {
        $agencydata['https_null_color'] = '';
        $agencydata['https_null_label'] = '';
    }
    //Query to get Preload status  data
    $preloadresults = db_query("select IFNULL(field_preload_status_value, 0) as field_preload_status_value, count(field_preload_status_value) as complnum from node a , field_data_field_preload_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  group by field_preload_status_value", array());
    foreach ($preloadresults as $preloadresult) {
        if($preloadresult->field_preload_status_value == 'Yes')
            $agencydata['preload_support'] += $preloadresult->complnum;
        elseif($preloadresult->field_preload_status_value == 'Ready')
            $agencydata['preload_readysupport'] += $preloadresult->complnum;
        else
            $agencydata['preload_nosupport'] += $preloadresult->complnum;
    }


//Query to get Most Popular web servers for Agency
    $agwebservreslts = db_query("select d.title,d.status,c.name,b.field_web_server_tid, count(b.field_web_server_tid) cnt from field_data_field_web_agency_id a, field_data_field_web_server b ,taxonomy_term_data c , node d where a.bundle='website' and a.entity_id=b.entity_id and b.field_web_server_tid=c.tid  and a.entity_id=d.nid and d.status='1' group by b.field_web_server_tid order by cnt desc limit 4", array());
    foreach ($agwebservreslts as $agwebservres) {
        $agwebdata[$agwebservres->name] = $agwebservres->cnt;
    }
    $agencydata['ag_webserver'] = $agwebdata;


    //Query to get Most Popular Programming languages for Agency
    $agplreslts = db_query("select d.title,d.status,c.name,field_programming_languages_tid,count(field_programming_languages_tid) cnt from field_data_field_web_agency_id a, field_data_field_programming_languages b ,taxonomy_term_data c , node d where a.bundle='website' and a.entity_id=b.entity_id and field_programming_languages_tid=c.tid  and a.entity_id=d.nid and d.status='1' group by field_programming_languages_tid order by cnt desc limit 4", array());
    foreach ($agplreslts as $agplreslt) {
        $agpldata[$agplreslt->name] = $agplreslt->cnt;
    }
    $agencydata['ag_proglang'] = $agpldata;

    //Query to get Most Popular CMS for Agency
    $agcmsreslts = db_query("select d.title,d.status,c.name,field_cms_applications_tid,count(field_cms_applications_tid) cnt from field_data_field_web_agency_id a, field_data_field_cms_applications b ,taxonomy_term_data c , node d where a.bundle='website' and a.entity_id=b.entity_id and field_cms_applications_tid=c.tid and c.name not like '%\_%'   and a.entity_id=d.nid and d.status='1' group by field_cms_applications_tid order by cnt desc limit 4", array());
    foreach ($agcmsreslts as $agcmsreslt) {
        $agcmsdata[$agcmsreslt->name] = $agcmsreslt->cnt;
    }
    $agencydata['ag_cms'] = $agcmsdata;

    //Query to get Most Popular OS for Agency
    $agosreslts = db_query("select d.title,d.status,c.name,field_operating_systems_tid,count(field_operating_systems_tid) cnt from field_data_field_web_agency_id a, field_data_field_operating_systems b ,taxonomy_term_data c , node d where a.bundle='website' and a.entity_id=b.entity_id and field_operating_systems_tid=c.tid and c.name not like '%\_%'   and a.entity_id=d.nid and d.status='1' group by field_operating_systems_tid order by cnt desc limit 4", array());
    foreach ($agosreslts as $agosreslt) {
        $agosdata[$agosreslt->name] = $agosreslt->cnt;
    }
    $agencydata['ag_os'] = $agosdata;

    //Query to get Most Popular Javascript Framework for Agency
    $agjsreslts = db_query("select d.title,d.status,c.name,field_javascript_frameworks_tid,count(field_javascript_frameworks_tid) cnt from field_data_field_web_agency_id a, field_data_field_javascript_frameworks b ,taxonomy_term_data c , node d where a.bundle='website' and a.entity_id=b.entity_id and field_javascript_frameworks_tid=c.tid and c.name not like '%\_%'   and a.entity_id=d.nid and d.status='1' group by field_javascript_frameworks_tid order by cnt desc limit 4", array());
    foreach ($agjsreslts as $agjsreslt) {
        $agjsdata[$agjsreslt->name] = $agjsreslt->cnt;
    }
    $agencydata['ag_js'] = $agjsdata;

    //Query to get Most Popular CDN for Agency
    $agcdnreslts = db_query("select d.title,d.status,c.name,field_cdn_applications_tid,count(field_cdn_applications_tid) cnt from field_data_field_web_agency_id a, field_data_field_cdn_applications b ,taxonomy_term_data c , node d where  a.bundle='website' and a.entity_id=b.entity_id and field_cdn_applications_tid=c.tid and c.name not like '%\_%'   and a.entity_id=d.nid and d.status='1' group by field_cdn_applications_tid order by cnt desc limit 4", array());
    foreach ($agcdnreslts as $agcdnreslt) {
        $agcdndata[$agcdnreslt->name] = $agcdnreslt->cnt;
    }
    $agencydata['ag_cdn'] = $agcdndata;

    //Query to get Agency Accessibility errors
    $ag_avrg_color_cont =  round(db_query("select sum(c.field_accessible_group_colorcont_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_colorcont c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id", array())->fetchField());

    $ag_avrg_miss_image =  round(db_query("select sum(c.field_accessible_group_missingim_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_missingim c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id", array())->fetchField());

    $ag_avrg_html_attr =  round(db_query("select sum(c.field_accessible_group_htmlattri_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_htmlattri c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id ", array())->fetchField());

    $agencydata['ag_col_contrast'] = $ag_avrg_color_cont;
    $agencydata['ag_miss_image'] = $ag_avrg_miss_image;
    $agencydata['ag_html_attrib'] = $ag_avrg_html_attr;

    if(($ag_avrg_color_cont == '0') && ($ag_avrg_miss_image == '0') && ($ag_avrg_html_attr == '0')) {
        $agencyaccess_output = "<br><span style=\"color: #ac0600;font-size: 12px;\">Sorry No Graph Data to display.</span><br>";
    }else{
        $agencyaccess_output = theme('agencywide_accessgraphs_page', array('agencydata' => $agencydata));
    }
    $agencydata['ag_access_chart'] = $agencyaccess_output;

    $govwide_mob['mob_perf_good_nos'] = db_query("SELECT mob_perf_good FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $govwide_mob['mob_perf_improve_nos'] = db_query("SELECT mob_perf_improve FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $govwide_mob['mob_perf_poor_nos'] = db_query("SELECT mob_perf_poor FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $govwide_mob['mob_usab_friendly_nos'] = db_query("SELECT mob_usab_friendly FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $govwide_mob['mob_usab_notfriendly_nos'] = db_query("SELECT mob_usab_nonfriendly FROM custom_government_wide_archive order by date desc limit 1")->fetchField();
    $govwide_mob['null'] = $agencydata['total_websites'] - ($govwide_mob['mob_perf_good_nos']+ $govwide_mob['mob_perf_improve_nos']+ $govwide_mob['mob_perf_poor_nos']);
    $govwide_mob['usab_null'] = $agencydata['total_websites'] - ($govwide_mob['mob_usab_friendly_nos']+ $govwide_mob['mob_usab_notfriendly_nos']);

    $agencydata['total_non_na_websites'] = $govwide_mob['mob_perf_good_nos']+ $govwide_mob['mob_perf_improve_nos']+ $govwide_mob['mob_perf_poor_nos'];
    $agencydata['poor_nos'] = $govwide_mob['mob_perf_poor_nos'] ;
    $agencydata['good_nos'] = $govwide_mob['mob_perf_good_nos'] ;
    $agencydata['improve_nos'] = $govwide_mob['mob_perf_improve_nos'] ;
    $agencydata['friendly_nos'] = $govwide_mob['mob_usab_friendly_nos'] ;
    $agencydata['nonfriendly_nos'] = $govwide_mob['mob_usab_notfriendly_nos'] ;
    $agencydata['usab_null']= $govwide_mob['usab_null'];

    if($agencydata['usab_null'] != 0 ) {
        $agencydata['usab_null_color'] = '#66364b';
        $agencydata['usab_null_label'] = 'Data Not Available';
    } else {
        $agencydata['usab_null_color'] = '';
        $agencydata['usab_null_label'] = '';
    }
    $agencydata['perf_null']= $govwide_mob['null'];

    if($agencydata['perf_null'] != 0) {
        $agencydata['perf_null_color'] = '#66364b';
        $agencydata['perf_null_label'] = 'Data Not Available';
    } else {
        $agencydata['perf_null_color'] = '';
        $agencydata['perf_null_label'] = '';
    }

    $govwide_mob['govwide_mob_bad'] = round(db_query("select count(field_mobile_overall_score_value) from field_data_field_mobile_overall_score where field_mobile_overall_score_value<='49' and entity_id in (SELECT node.nid AS nid
FROM
node node
LEFT JOIN field_data_field_web_agency_id field_data_field_web_agency_id ON node.nid = field_data_field_web_agency_id.entity_id AND (field_data_field_web_agency_id.entity_type = 'node' AND field_data_field_web_agency_id.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('website')) )))")->fetchField());
    $govwide_mob['govwide_mob_avg'] = round(db_query("select count(field_mobile_overall_score_value) from field_data_field_mobile_overall_score where field_mobile_overall_score_value<='89' and  field_mobile_overall_score_value>='50' and entity_id in (SELECT node.nid AS nid
FROM
node node
LEFT JOIN field_data_field_web_agency_id field_data_field_web_agency_id ON node.nid = field_data_field_web_agency_id.entity_id AND (field_data_field_web_agency_id.entity_type = 'node' AND field_data_field_web_agency_id.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('website')) )))")->fetchField());
    $govwide_mob['govwide_mob_good'] = round(db_query("select count(field_mobile_overall_score_value) from field_data_field_mobile_overall_score where field_mobile_overall_score_value<='100' and  field_mobile_overall_score_value>='90' and entity_id in (SELECT node.nid AS nid
FROM
node node
LEFT JOIN field_data_field_web_agency_id field_data_field_web_agency_id ON node.nid = field_data_field_web_agency_id.entity_id AND (field_data_field_web_agency_id.entity_type = 'node' AND field_data_field_web_agency_id.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('website'))  )))")->fetchField());
    $govwide_mob['govwide_mob_null'] = round(db_query("select count(entity_id) from field_data_field_mobile_overall_score where field_mobile_overall_score_value is NULL and entity_id in (SELECT node.nid AS nid
FROM
node node
LEFT JOIN field_data_field_web_agency_id field_data_field_web_agency_id ON node.nid = field_data_field_web_agency_id.entity_id AND (field_data_field_web_agency_id.entity_type = 'node' AND field_data_field_web_agency_id.deleted = '0')
WHERE (( (node.status = '1') AND (node.type IN  ('website')) )))")->fetchField());

    $govwideaccess_output = theme('govwide_mobgraphs_page', array('govwidedata' => $govwide_mob));

    $agencydata['gov_mob_chart'] = $govwideaccess_output;

    $govwideaccess_mob_output = theme('govwide_mobusabgraphs_page', array('govwidedata' => $govwide_mob));
    $agencydata['gov_mob_usab_chart'] = $govwideaccess_mob_output;

    //Query to get Search Engine Name for Government wide
    $searchengines = db_query("select field_search_engine_name_value,count(field_search_engine_name_value) as complnum from node a , field_data_field_search_engine_name b  where a.status='1' and a.nid=b.entity_id and a.type='website' group by field_search_engine_name_value");
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
        }
        if($searchenginename != "None")
            $search_engine_data[$searchenginename] = $searchengine_nos;
    }
    arsort($search_engine_data);
    foreach($search_engine_data as $skey=>$sval){
        $search_engine_data_for_agencygraph .= "['$skey' , $sval],";
    }
    $agencydata['searchenginedata'] = $search_engine_data;
    $search_engine_graph_output = theme('agencywide_searchengines_page', array('search_engine_data_for_agencygraph' => $search_engine_data_for_agencygraph));
    $agencydata['searchengines_graph'] = $search_engine_graph_output;


    //Query to get Search data for an agency
    $searchresults = db_query("select field_search_status_value,count(field_search_status_value) as complnum from node a , field_data_field_search_status b  where a.status='1' and a.nid=b.entity_id  and a.type='website' group by field_search_status_value");
    $agency_search_status = array();
    foreach ($searchresults as $searchresult) {
        if($searchresult->field_search_status_value == '1')
            $agency_search_status['search_available'] += $searchresult->complnum;
        if($searchresult->field_search_status_value == '0')
            $agency_search_status['search_notavailable'] += $searchresult->complnum;
    }
    $agencydata['searchenginestatus'] = $agency_search_status;

    $search_status_graph_output = theme('agencywide_searchstatus_page', array('agencydata' => $agency_search_status));
    $agencydata['searchenginestatus_graph'] = $search_status_graph_output;

    return $agencydata;

}

/*
 * Find Last scan date
 */
function idea_act_lastScanDate(){
    $query = db_query("select nid,created from node where type='scans' order by nid desc limit 1");
    foreach ($query as $result) {
        $lastscantime = $result->created;
    }
    // Scan takes 2 or 3 days to complete.
    // Query returns lastscan date at the start of the scan not when scan completes.
    // Adding 2 or 3 days makes san date to show scan completion date.
    print date("m/d/Y",$lastscantime + + (2 * 24 * 60 * 60));
}



/*
 * Get Percentage
 */
function idea_act_applyDataPercentage($data,$websites)
{
    $actual_percent = ($data / $websites) * 100;
    $percent = round($actual_percent);

    if ($data != '') {
        if($actual_percent < 1 && $actual_percent > 0) {
            $dataPercentage = "< 1%";
        } else {
            $dataPercentage = "$percent%";
        }

    }
    else{
        $dataPercentage = "0%";
    }
    return $dataPercentage;

}


/*
 * Avoid chart slice when data is  0 < data < 1
 */

function idea_act_avoid_slice($data,$websites) {

    $actual_percent = ($data / $websites) * 100;

    if ($data != '') {
        if($actual_percent < 1 && $actual_percent > 0) {
            $chart_data = "0";
        } else {
            $chart_data = "$data";
        }
    }

    return $chart_data;

}


/*
 * hide not available legend on zero and na case
 */

function idea_act_avoid_null_legend($data,$websites) {

    $actual_percent = ($data / $websites) * 100;

    if ($data != '') {
        if($actual_percent < 1 && $actual_percent > 0) {
            $data_null_label = "";
        } else {
            $data_null_label = "Not Available";
        }
    }
    return $data_null_label;
}


/*
 * hide not available legend on zero and na case
 */

function idea_act_avoid_null_color($data,$websites) {

    $actual_percent = ($data / $websites) * 100;

    if ($data != '') {
        if($actual_percent < 1 && $actual_percent > 0) {
            $data_null_color = "";
        } else {
            $data_null_color = "#66364b";
        }
    }
    return $data_null_color;
}