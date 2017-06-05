<?php
/*
 * Lists all common functions used by scan engine
 */
include_once("../scripts/configSettings.php");

/*
 * Query to find all mobile scans(last scan) that ran before 3 hours. If the site is updated in last 3 hours no need to run the scan again
 * Interesting domains to watch out. abmc.gov has only https and http fails. aapi.gov redirects to white house
 */
function getSites()
{
    $websites = array();

    //$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value LIKE '%census.gov%' and b.nid=a.entity_id", array(':bundle' => 'website'));
   $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id", array(':bundle' => 'website'));
    //$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.nid not in (select c.field_website_id_nid from field_data_body a , node b, field_data_field_website_id c  where b.type='mobile_scan_information' and b.nid=a.entity_id and b.nid=c.entity_id and (UNIX_TIMESTAMP(CURRENT_TIMESTAMP()) - b.changed)/3600 >= 3)", array(':bundle' => 'website'));
    foreach ($query as $result) {
        $websites[$result->entity_id] = array("domain"=>$result->title,"url"=>$result->body_value);
    }
    return $websites;
}

/*
 * Start the Scan. Save node and get scan id.
 */

function startScan(){
    $date = date("m-d-Y");
    $scanstarttime = time();
    $node = new stdClass();
    $node->type = "scans";
    $node->language = LANGUAGE_NONE;
    $node->uid = "1";
    $node->name = "admin";
    $node->status = 1;
    $node->title = "Scan $date";
    $node->field_scan_start_time['und'][0]['value'] = time();
    $node->promote = 0;
    node_object_prepare($node);
    if($node=node_submit($node)){
        node_save($node);
        return $node->nid;
    }
}

/*
 * Run pageres command to generate website snapshots
 */

function getWebSnapshots($website,$storage){
    exec("pageres ". $website. " --format=jpg --filename=\"".$storage."<%= url %>\"");
}

/*
 * Execute the commands and returns and logs commands
 */
function execCommand($com, &$out, &$ret){
    include("../scripts/configSettings.php");
    exec("$com", $out, $ret);
    //print_r($out);
    if($ret !== 0){ // exec is successful only if the $return_var was set to 0. !== means equal and identical, that is it is an integer and it also is zero.
        writeToLogs("Command $com Failed",$logFile);
        return false;
    }
    else{
        writeToLogs("Executed Command ' $com ' Successfully",$logFile);
        return $out;
    }
}

/*
 * Get IP Information
 *
 */

function getIPInfo($domain){
    $command = "dig $domain +short";
    $outp = array();
    $comret = "";
    execCommand("$command",$outp,$comret);
    return $outp;
}

/*
 * Get Name Server Information
 *
 */

function getNSInfo($domain){
    $basedomain = getBaseDomain($domain);
    $command = "dig $basedomain +short";
    $outp = array();
    $comret = "";
    execCommand("$command",$outp,$comret);
    return $outp;
}

/*
 * Get Sites's final redirect destination
 */

function getSiteRedirectDest($domain){
    $redirectUrl = shell_exec("curl -w \"%{url_effective}\n\" -I -L -s -S -k http://".$domain." -o /dev/null");
    return $redirectUrl;
}

/*
 * Get SSL protocols and Ciphers Information
 *
 */

function getSSLInfo($domain){
    $sslinfo = array();
    $output = shell_exec("sslyze --regular --http_headers $domain");
    $sslinfo['raw'] = $output;
    $outputarr = explode("*",$output);
    foreach($outputarr as $val){
        //Check for SSL V2 support
        if (strpos($val, 'SSLV2 Cipher Suites:') !== false) {
            if (strpos($val, 'Server rejected all cipher suites') !== false){
                $sslv2 = 0;
            }
            else{
                $sslv2 = 1;
            }
            $sslinfo['sslv2'] = $sslv2;
        }
        //Check for SSL V3 support
        if (strpos($val, 'SSLV3 Cipher Suites:') !== false) {
            if (strpos($val, 'Server rejected all cipher suites') !== false){
                $sslv3 = 0;
            }
            else{
                $sslv3 = 1;
            }
            $sslinfo['sslv3'] = $sslv3;
        }
        //Check for TLS V1 support
        if (strpos($val, 'TLSV1 Cipher Suites:') !== false) {
            if (strpos($val, 'Server rejected all cipher suites') !== false){
                $tlsv1 = 0;
            }
            else{
                $tlsv1 = 1;
            }
            $sslinfo['tlsv1'] = $tlsv1;
        }
        //Check for TLS V1.1 support
        if (strpos($val, 'TLSV1_1 Cipher Suites:') !== false) {
            if (strpos($val, 'Server rejected all cipher suites') !== false){
                $tlsv11 = 0;
            }
            else{
                $tlsv11 = 1;
            }
            $sslinfo['tlsv11'] = $tlsv11;
        }
        //Check for TLS V1.2 support
        if (strpos($val, 'TLSV1_2 Cipher Suites:') !== false) {
            if (strpos($val, 'Server rejected all cipher suites') !== false){
                $tlsv12 = 0;
            }
            else{
                $tlsv12 = 1;
            }
            $sslinfo['tlsv12'] = $tlsv12;
        }
        //Check OpenSSL CCS Injection
        if (strpos($val, 'OpenSSL CCS Injection:') !== false) {
            if (strpos($val, 'OK - Not vulnerable') !== false){
                $opensslccs = 0;
            }
            else{
                $opensslccs = 1;
            }
            $sslinfo['opensslccs'] = $opensslccs;
        }
        //Check OpenSSL Heartbleed
        if (strpos($val, 'OpenSSL Heartbleed:') !== false) {
            if (strpos($val, 'OK - Not vulnerable') !== false){
                $opensslhb = 0;
            }
            else{
                $opensslhb = 1;
            }
            $sslinfo['opensslhb'] = $opensslhb;
        }
        //Check Downgrade Attacks
        if (strpos($val, 'Downgrade Attacks:') !== false) {
            if (strpos($val, 'OK - Supported') !== false){
                $downgrade = 0;
            }
            else{
                $downgrade = 1;
            }
            $sslinfo['downgrade'] = $downgrade;
        }
        //Check OCSP Stapling
        if (strpos($val, 'Certificate - OCSP Stapling:') !== false) {
            if (strpos($val, 'NOT SUPPORTED') !== false){
                $ocspstaple = 0;
            }
            else{
                $ocspstaple = 1;
            }
            $sslinfo['ocspstaple'] = $ocspstaple;
        }
        //Check HTTP Public Key Pinning (HPKP)
        if (strpos($val, 'HTTP Public Key Pinning (HPKP):') !== false) {
            if (strpos($val, 'NOT SUPPORTED') !== false){
                $hpkp = 0;
            }
            else{
                $hpkp = 1;
            }
            $sslinfo['hpkp'] = $hpkp;
        }
        //Check Deflate Compression
        if (strpos($val, 'Deflate Compression') !== false) {
            if (strpos($val, 'Compression disabled') !== false){
                $deflatecomp = 0;
            }
            else{
                $deflatecomp = 1;
            }
            $sslinfo['deflatecomp'] = $deflatecomp;
        }
        //Check Session Renegotiation:
        if (strpos($val, 'Session Renegotiation:') !== false) {
            $sesre = explode(PHP_EOL, $val);
            foreach($sesre as $sereval) {
                if (strpos($sereval, 'Client-initiated Renegotiation:') !== false) {
                    if ((strpos($sereval, 'Rejected') !== false) || (strpos($sereval, 'VULNERABLE') !== false)) {
                        $sesre_client = 0;
                    }
                    else{
                        $sesre_client = 1;
                    }
                }
                if (strpos($sereval, 'Secure Renegotiation:') !== false) {
                    if (strpos($sereval, 'OK - Supported') !== false) {
                        $sesre_client_secure = 1;
                    }
                    else{
                        $sesre_client_secure = 0;
                    }
                }
            }
            $sslinfo['sesre_client'] = $sesre_client;
            $sslinfo['sesre_client_secure'] = $sesre_client_secure;
        }
        //Extract Certificate Basic Information
        if (strpos($val, 'Certificate Basic Information:') !== false) {
            $certinfo = explode(PHP_EOL, $val);
            foreach($certinfo as $certinfoval) {
                if (preg_match('/Common Name:(?s)(.*)/', $certinfoval,$match1)) {
                    $cname = trim($match1[1]);
                }
                if (preg_match('/Issuer:(?s)(.*)/', $certinfoval,$match2)) {
                    $issuer = trim($match2[1]);
                }
                if (preg_match('/Not Before:(?s)(.*)/', $certinfoval,$match3)) {
                    $certfromdate = trim($match3[1]);
                }
                if (preg_match('/Not After:(?s)(.*)/', $certinfoval,$match4)) {
                    $certtodate = trim($match4[1]);
                }
                if (preg_match('/Signature Algorithm:(?s)(.*)/', $certinfoval,$match5)) {
                    $sigalgorithm = trim($match5[1]);
                }
                if (preg_match('/Public Key Algorithm:(?s)(.*)/', $certinfoval,$match6)) {
                    $pkeyalgorithm = trim($match6[1]);
                }
                if (preg_match('/X509v3 Subject Alternative Name:((?s).*)/', $certinfoval,$match7)) {
                    $certsan = trim($match7[1]);
                    if (preg_match('/.*?\[(.*)\].*?/', $certsan,$match12)) {
                        $sanname = trim($match12[1]);
                    }
                }
            }
            $sslinfo['cname'] = $cname;
            $sslinfo['issuer'] = $issuer;
            $sslinfo['certfromdate'] = $certfromdate;
            $sslinfo['certtodate'] = $certtodate;
            $sslinfo['sigalgorithm'] = $sigalgorithm;
            $sslinfo['pkeyalgorithm'] = $pkeyalgorithm;
            $sslinfo['sanname'] = $sanname;
        }
        //Extract Trust Certificate Information
        if (strpos($val, 'Certificate - Trust:') !== false) {
            $trustcertinfo = explode(PHP_EOL, $val);
            foreach($trustcertinfo as $trustcertinfoval) {
                if (preg_match('/Hostname Validation:.*(?s)(.*)/', $trustcertinfoval,$match11)) {
                    $hostv = trim($match11[1]);
                    $sslinfo['host_validation'] = $hostv;
                    if(preg_match('/(.*)OK - Subject Alternative Name matches(.*)/', $hostv)) {
                        $sslinfo['cert_status'] = 1;
                    }
                    else {
                        $sslinfo['cert_status'] = 0;
                    }
                }
                if (preg_match('/Received Chain:.*?\-\-\>(?s)(.*)/', $trustcertinfoval,$match12)) {
                    $cert_provider = trim($match12[1]);
                }
                if (preg_match('/Verified Chain:.*(?s)(.*)/', $trustcertinfoval,$match13)) {
                    $cert_verfied_chain = trim($match13[1]);
                }
            }
        }
        $sslinfo['cert_provider'] = $cert_provider;
        $sslinfo['cert_verfied_chain'] = $cert_verfied_chain;
    }
    return $sslinfo;
}

/*
 * Run Mobile API calls to Google and get the data
 */

function getMobileAPIdata($domain){
    include("../scripts/configSettings.php");
    $mobileAPIdataArr = array();
    //Call to Google Mobile Friendly API
    //We are not using drupal system_retrieve_file because it failed url calls to google randomly
    //$googMobileFriendlyApi = "https://www.googleapis.com/pagespeedonline/v3beta1/mobileReady?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&url=http://".$domain."&strategy=mobile";
    //$googMobileFriendlyApiHttps = "https://www.googleapis.com/pagespeedonline/v3beta1/mobileReady?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&url=https://".$domain."&strategy=mobile";
    $http_domain = "http://".$domain;
    $https_domain = "https://".$domain;
    $googleApiKey = "AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4";
    if(!$googMobileFriendlyApiData = mobileFriendlyApidata("$http_domain","$googleApiKey")) {
        $error = error_get_last();
        writeToLogs("API request failed to $http_domain . Error was: " . $error['message'],$logFile);
    }
    else{
        //$mobileAPIdataArr['mobFriendlyFile'] = "sites/default/files/mobilefriendly_reports/" . $domain . ".json";
        //Get Json data and enter to a file
        //file_put_contents($mobileAPIdataArr['mobFriendlyFile'], $googMobileFriendlyApiData);
        $mobFriendlyFile = file_save_data($googMobileFriendlyApiData,file_default_scheme().'://mobilefriendly_reports/'.$domain.'.json', FILE_EXISTS_REPLACE);
        $mobileAPIdataArr['mobFriendlyFile'] = array('fid' => $mobFriendlyFile->fid,'display' => 1, 'description' => '');
        $jsonMFarr = json_decode($googMobileFriendlyApiData, true);
        $mobileAPIdataArr['mobFriendlyScore'] = $jsonMFarr['ruleGroups']['USABILITY']['score'];
        $mobileAPIdataArr['mobFriendlyResult'] = $jsonMFarr['ruleGroups']['USABILITY']['pass'];
        $mobSnapshotData = str_replace('_', '/', $jsonMFarr['screenshot']['data']);
        $mobSnapshotData = str_replace('-', '+', $mobSnapshotData);
        $mobSnapshotData = base64_decode($mobSnapshotData);
        $mobileAPIdataArr['mobSnapshotData'] = $mobSnapshotData;

        $snapshotfile = file_save_data($mobSnapshotData,file_default_scheme().'://mobile_snapshots/'.$domain.'.jpg', FILE_EXISTS_REPLACE);
        $mobileAPIdataArr['mobSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
        //file_put_contents($mobileAPIdataArr['mobSnapshotFile'], $mobSnapshotData);
    }
    //Call to Google Inights Speed API
    //$googMobilePerformApi = "https://www.googleapis.com/pagespeedonline/v2/runPagespeed?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&strategy=mobile&url=".$domain."";
        //if(!$googMobilePerformApiData = file_get_contents("$googMobilePerformApi")) {
        if(!$googMobilePerformApiData = mobilePerformApidata("$http_domain","$googleApiKey")) {
            $error = error_get_last();
            writeToLogs("API request failed to $http_domain . Error was: " . $error['message'],$logFile);
        }
        else{
        //$mobileAPIdataArr['mobPerformFile'] = "sites/default/files/mobileperform_reports/" . $domain . ".json";
        //Get Json data and enter to a file
        //file_put_contents($mobileAPIdataArr['mobPerformFile'], $googMobilePerformApiData);
        $mobPerformFile = file_save_data($googMobilePerformApiData,file_default_scheme().'://mobileperform_reports/'.$domain.'.json', FILE_EXISTS_REPLACE);
        $mobileAPIdataArr['mobPerformFile'] = array('fid' => $mobPerformFile->fid,'display' => 1, 'description' => '');

        $jsonMParr = json_decode($googMobilePerformApiData, true);
        if($mobileAPIdataArr['mobSnapshotData'] == ''){
            $mobSnapshotData = str_replace('_', '/', $jsonMParr['screenshot']['data']);
            $mobSnapshotData = str_replace('-', '+', $mobSnapshotData);
            $mobSnapshotData = base64_decode($mobSnapshotData);
            $mobileAPIdataArr['mobSnapshotData'] = $mobSnapshotData;
            $snapshotfile = file_save_data($mobSnapshotData,file_default_scheme().'://mobile_snapshots/'.$domain.'.jpg', FILE_EXISTS_REPLACE);
            $mobileAPIdataArr['mobSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
        }
        $mobileAPIdataArr['mPScore'] = $jsonMParr['ruleGroups']['SPEED']['score'];
        if(($mobileAPIdataArr['mobFriendlyScore'] == '') || ($mobileAPIdataArr['mobFriendlyScore'] == '0'))
            $mobileAPIdataArr['mobFriendlyScore'] = $jsonMParr['ruleGroups']['USABILITY']['score'];
        $mobileAPIdataArr['mPStats'] = $jsonMParr['pageStats'];
    }
    return $mobileAPIdataArr;
}

/*
 * Get Mobile Friendly API through Curl calls
 */

function mobileFriendlyApidata($url, $apiKey)
{
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => 'https://www.googleapis.com/pagespeedonline/v3beta1/mobileReady?key='.$apiKey.'&url='.$url.'&strategy=mobile',
    ));
    $resp = curl_exec($curl);
    curl_close($curl);

    return $resp;
}


/*
 * Get Mobile Page Speed API through Curl calls
 */

function mobilePerformApidata($url, $apiKey)
{
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => 'https://www.googleapis.com/pagespeedonline/v2/runPagespeed?screenshot=true&key='.$apiKey.'&strategy=mobile&url='.$url.'',
    ));
    $resp = curl_exec($curl);
    curl_close($curl);

    return $resp;
}

/*
 * Get Alexa rank in an Array for Current Rank, delta Change of rank in last 3 months and Ranking in US
 */

function getAlexaRank($domain){
    $url = getBaseDomain($domain);
    $xml = simplexml_load_file('http://data.alexa.com/data?cli=10&dat=snbamz&url='.$url);
    if(isset($xml->SD[1])) {
        $rank = isset($xml->SD[1]->POPULARITY) ? (int)$xml->SD[1]->POPULARITY->attributes()->TEXT : 0;
        $rankDelta = (string)$xml->SD[1]->RANK->attributes()->DELTA;
        $rankCountry = (int)$xml->SD[1]->COUNTRY->attributes()->RANK;
    }
    else{
        $rank =  0;
        $rankDelta =  0;
        $rankCountry = 0;
    }
    $rankInfo = array(
        "rankDelta" => $rankDelta,
        "rankCountry" => $rankCountry,
        "rank" => $rank,
        "raw" => $xml
    );
    //$web=(string)$xml->SD[0]->attributes()->HOST;
    return $rankInfo;
}

function getBaseDomain($domain){
    $basehost = basename($domain);
    if (strpos($basehost, 'www.') !== false) {
        $theName = explode('www.', $basehost)[1];
        return $theName;
    }
    else{
        return $basehost;
    }

}

/*
 * Get Site Inspector output in Json
 */

function getSiteInspectorOutput($domain){
    $command = "../tools/site_inspector/bin/site-inspector  inspect -j $domain";
    $spout = shell_exec("$command");
    $spRawOut = json_decode($spout,true);
    //print_r($spRawOut);
    $spRaw['raw'] = $spout;
    $spRaw['cookie'] = $spRawOut['canonical_endpoint']['cookies']['cookie?'];
    $spRaw['secure_cookie'] = $spRawOut['canonical_endpoint']['cookies']['secure?'];
    $spRaw['content_security_policy'] = $spRawOut['canonical_endpoint']['headers']['content_security_policy'];
    $spRaw['click_jacking_protection'] = $spRawOut['canonical_endpoint']['headers']['click_jacking_protection'];
    $spRaw['xss_protection'] = $spRawOut['canonical_endpoint']['headers']['xss_protection'];
    $spRaw['cdn'] = $spRawOut['canonical_endpoint']['dns']['cdn'];
    $spRaw['cloud_provider'] = $spRawOut['canonical_endpoint']['dns']['cloud_provider'];
    $spRaw['sitemap_xml'] = $spRawOut['canonical_endpoint']['content']['sitemap_xml'];
    $spRaw['robots_txt'] = $spRawOut['canonical_endpoint']['content']['robots_txt'];
    $spRaw['proper_404s'] = $spRawOut['canonical_endpoint']['content']['proper_404s'];

    return $spRaw;
}

/*
 * Get Pulse data into a custom table
 * To import CSV the following line must be added to settings.php
 */

function getPulseData(){
    include("../scripts/configSettings.php");
    print "Import CSV";
    $localhttpsfile = "/tmp/pulsehttp.csv";
    $localdapfile = "/tmp/pulsedap.csv";
    $pulsehttpsurl = "https://pulse.cio.gov/data/domains/https.csv";
    $pulsedapurl = "https://pulse.cio.gov/data/domains/analytics.csv";
    //Get Pulse https data and enter to a temp table
    file_put_contents("$localhttpsfile", file_get_contents("$pulsehttpsurl"));
    db_query("truncate table custom_pulse_https_data");
    db_query("LOAD DATA LOCAL INFILE '".$localhttpsfile."' INTO TABLE `custom_pulse_https_data` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");

    //Get Pulse dap data and enter to a temp table
    file_put_contents("$localdapfile", file_get_contents("$pulsedapurl"));
    db_query("truncate table custom_pulse_dap_data");
    db_query("LOAD DATA LOCAL INFILE '".$localdapfile."' INTO TABLE `custom_pulse_dap_data` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");
    db_query("update custom_pulse_https_data a , custom_pulse_dap_data b set a.dap=b.dap where a.domain=b.domain");


}

/*
 * Update HTTPS and DAP Info
 */

function updateHttpsDAPInfo($siteid,$webscanId,$website){
    $date = date("m-d-Y");
    $node = new stdClass();
    $node->type = "https_dap_scan_information";
    $node->language = LANGUAGE_NONE;
    $node->uid = "1";
    $node->name = "admin";
    $node->status = 1;
    $node->title = "HTTPS DAP Scan ".$website['domain'];
    if(($nodeId = findNode($node->title,'https_dap_scan_information')) != FALSE){
        echo "found node $node->title $nodeId";
        $node->nid = $nodeId;
    }
        $node->promote = 0;
        $query = db_query("select * from  custom_pulse_https_data where domain=:domain", array(':domain' => $website['domain']));
        foreach ($query as $result) {
            $tags = array();
            $node->field_https_status['und'][0]['value'] = $result->HTTPS;
            $node->field_enforce_https['und'][0]['value'] = $result->EnfHTTPS;
            $node->field_hsts_status['und'][0]['value'] = $result->HSTS;
            $node->field_preload_status['und'][0]['value'] = $result->preloaded;
            $node->field_redirect['und'][0]['value'] = $result->redirect;
            if($result->redirect == 'Yes')
                $node->field_redirect_url['und'][0]['value'] = getSiteRedirectDest($website['domain']);
            $node->field_hsts_scan_time['und'][0]['value'] = (int)time();
            $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
            $node->field_website_id['und'][0]['nid'] = $siteid;
            $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
            $node->field_dap_status['und'][0]['value'] = ($result->dap == 'Yes')?1:0;
            if($result->dap == 'Yes')
                $node->field_dap_score['und'][0]['value'] = '100';
            else
                $node->field_dap_score['und'][0]['value'] = '0';

            $https_score = 0;
            if($result->HTTPS == 'Yes') {
                $https_score += 50;
                $tags[] = 'HTTPS';
            }
            if($result->EnfHTTPS == 'Yes') {
                $https_score += 10;
                $tags[] = 'FORCE HTTPS';
            }
            if($result->HSTS == 'Yes') {
                $https_score += 30;
                $tags[] = 'HSTS';
            }
            if($result->preloaded == 'Yes') {
                $https_score += 10;
                $tags[] = 'PRELOAD';
            }
            if($result->dap == 'Yes')
                $tags[] = 'DAP';
            $node->field_https_score['und'][0]['value'] = round($https_score);
        }

    //Save parent website node
    $wnode = node_load($siteid);
    $wnode->field_https_score['und'][0]['value'] = round($https_score);
    if($result->dap == 'Yes')
        $wnode->field_dap_score['und'][0]['value'] = '100';
    else
        $wnode->field_dap_score['und'][0]['value'] = '0';

    //Save Tags to parent website
    if(!empty($tags)) {
        if(!empty($wnode->field_website_tags)){
            foreach($wnode->field_website_tags['und'] as $ctk  =>$ctval){
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
                    $wnode->field_website_tags['und'][$crnTermCnt+$i]['tid'] = $terms_array['0'];
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
                    $wnode->field_website_tags['und'][$key]['tid'] = $term->tid;
                }
            }
            $i += 1;
        }

    }
    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
    }
    //print_r($node);
        node_object_prepare($node);
        if ($node = node_submit($node)) {
            node_save($node);
        }
}

/*
 * This will update Domain and SSL information. This will update domain_scan_information content type
 */
function updateDomainSSLInfo($siteid,$webscanId,$website){
    $tags = array();
    $start = microtime(true);
    $date = date("m-d-Y");
    $node = new stdClass();
    $node->type = "domain_scan_information";
    $node->language = LANGUAGE_NONE;
    $node->uid = "1";
    $node->name = "admin";
    $node->status = 1;
    $node->title = "Domain Scan ".$website['domain'];
    if(($nodeId = findNode($node->title,'domain_scan_information')) != FALSE){
        echo "found node $node->title $nodeId";
        $node->nid = $nodeId;
    }
        $node->promote = 0;
        $sslInfo = getSSLInfo($website['domain']);
        $node->body['und'][0]['value'] = $sslInfo['raw'];
        $node->field_dom_common_name['und'][0]['value'] = $sslInfo['cname'];
        $node->field_subject_alternative_name['und'][0]['value'] = $sslInfo['sanname'];
        //$node->field_domain_expiry['und'][0]['value'] = $sslInfo[''];
        //$node->field_domain_contact_name['und'][0]['value'] = $sslInfo[''];
        $node->field_ssl_certificate_valid_from['und'][0]['value'] = $sslInfo['certfromdate'];
        $node->field_ssl_certificate_expiry['und'][0]['value'] = $sslInfo['certtodate'];
        $node->field_ssl_certificate_status['und'][0]['value'] = $sslInfo['cert_status'];
        $node->field_ssl_certificate_chain['und'][0]['value'] = $sslInfo['cert_verfied_chain'];
        $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
        $node->field_website_id['und'][0]['nid'] = $siteid;
        $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
        $node->field_dom_scan_time['und'][0]['value'] = (int)time();
        $node->field_ssl_v2_support['und'][0]['value'] = ($sslInfo['sslv2'] == '')?0:1;
        $node->field_ssl_v3_support['und'][0]['value'] = ($sslInfo['sslv3'] == '')?0:1;
        $node->field_tls_v1_support['und'][0]['value'] = ($sslInfo['tlsv1'] == '')?0:1;
        $node->field_tls_v1_1_support['und'][0]['value'] = ($sslInfo['tlsv11'] == '')?0:1;
        $node->field_tls_v1_2_support['und'][0]['value'] = ($sslInfo['tlsv12'] == '')?0:1;
        $node->field_openssl_ccs_injection['und'][0]['value'] = ($sslInfo['opensslccs'] == '')?0:1;
        $node->field_openssl_heartbleed['und'][0]['value'] = ($sslInfo['opensslhb'] == '')?0:1;
        $node->field_downgrade_attacks['und'][0]['value'] = ($sslInfo['downgrade'] == '')?0:1;
        $node->field_certificate_ocsp_stapling['und'][0]['value'] = ($sslInfo['ocspstaple'] == '')?0:1;
        $node->field_http_public_hpkp['und'][0]['value'] = ($sslInfo['hpkp'] == '')?0:1;
        $node->field_deflate_compression['und'][0]['value'] = ($sslInfo['deflatecomp'] == '')?0:1;
        $node->field_session_reneg_client['und'][0]['value'] = ($sslInfo['sesre_client'] == '')?0:1;
        $node->field_session_secure_renegotiati['und'][0]['value'] = ($sslInfo['sesre_client_secure'] == '')?0:1;
        $node->field_certificate_issuer['und'][0]['value'] = $sslInfo['issuer'];
        $node->field_certificate_signature_algo['und'][0]['value'] = $sslInfo['sigalgorithm'];
        $node->field_certificate_public_key_alg['und'][0]['value'] = $sslInfo['pkeyalgorithm'];
        $node->field_cert_host_name_valid['und'][0]['value'] = $sslInfo['host_validation'];
        $node->field_certificate_provider['und'][0]['value'] = $sslInfo['cert_provider'];
        $alexaInfo = getAlexaRank($website['domain']);
        $node->field_alexa_raw_output['und'][0]['value'] = json_encode($alexaInfo['raw']);
        $node->field_alexa_ranking['und'][0]['value'] = $alexaInfo['rank'];
        $node->field_ip_address['und'][0]['value'] = implode(",",getIPInfo($website['domain']));
        $node->field_dns_names['und'][0]['value'] = implode(",",getNSInfo($website['domain']));
        $node->field_hosted_platform['und'][0]['value'] = $sslInfo['cert_provider'];
        //$node->field_technology_stacks['und'][0]['value'] = $sslInfo['cert_provider'];
        //$node->field_last_overall_rating['und'][0]['value'] = $sslInfo['cert_provider'];

        $siInfo = getSiteInspectorOutput($website['domain']);
        //Update Site Inspector details

        $node->field_cdn_provider_name['und'][0]['value'] = $siInfo['cdn'];
        $node->field_cloud_provider['und'][0]['value'] = $siInfo['cloud_provider'];
        $node->field_uses_sitemap['und'][0]['value'] = ($siInfo['sitemap_xml'] == '')?0:1;
        $node->field_uses_robots_txt['und'][0]['value'] = ($siInfo['robots_txt'] == '')?0:1;
        $node->field_have_proper_404['und'][0]['value'] = ($siInfo['proper_404s'] == '')?0:1;
        $node->field_content_security_policy['und'][0]['value'] = ($siInfo['content_security_policy'] == '')?0:1;
        $node->field_click_jacking_protection['und'][0]['value'] = ($siInfo['click_jacking_protection'] == '')?0:1;
        $node->field_xss_protection['und'][0]['value'] = ($siInfo['xss_protection'] == '')?0:1;
        $node->field_uses_cookies['und'][0]['value'] = ($siInfo['cookie'] == '')?0:1;
        $node->field_uses_secure_cookies['und'][0]['value'] = ($siInfo['secure_cookie'] == '')?0:1;
        $node->field_site_inspector_raw_out['und'][0]['value'] = $siInfo['raw'];


        $sslScore = 0;
        //Calculate SSL Score
        if($sslInfo['sslv2'] == '0')
            $sslScore += 20;
        else
            $tags[] = 'SSLV2';
        if($sslInfo['sslv3'] == '0')
            $sslScore += 15;
        else
            $tags[] = 'SSLV3';
        if($sslInfo['tlsv1'] == '0')
            $sslScore += 5;
        else
            $tags[] = 'TLSV1';
        if($sslInfo['tlsv11'] == '1') {
            $sslScore += 15;
            $tags[] = 'TLSV1.1';
        }
        if($sslInfo['tlsv12'] == '1') {
            $sslScore += 15;
            $tags[] = 'TLSV1.2';
        }
        if($sslInfo['opensslccs'] == '0')
            $sslScore += 10;
        else
            $tags[] = 'VULNERABLE';
        if($sslInfo['opensslhb'] == '0')
            $sslScore += 10;
        else
            $tags[] = 'VULNERABLE';
        if($sslInfo['downgrade'] == '0')
            $sslScore += 5;
        else
            $tags[] = 'VULNERABLE';
        if($sslInfo['hpkp'] == '1')
            $sslScore += 5;
        //Assign node Value
        $node->field_ssl_score['und'][0]['value'] = round($sslScore);

    //Save parent website node
    $wnode = node_load($siteid);
    $wnode->field_ssl_score['und'][0]['value'] = round($sslScore);

    //Save Tags to parent website
    if(!empty($tags)) {
        if(!empty($wnode->field_website_tags)){
            foreach($wnode->field_website_tags['und'] as $ctk  =>$ctval){
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
                    $wnode->field_website_tags['und'][$crnTermCnt+$i]['tid'] = $terms_array['0'];
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
                    $wnode->field_website_tags['und'][$key]['tid'] = $term->tid;
                }
            }
            $i += 1;
        }

    }
    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
    }

        node_object_prepare($node);
        if ($node = node_submit($node)) {
            node_save($node);
        }
        $end = microtime(true);
        print "Domain SSL scan for ".$website['domain']." took " . ($end - $start) . ' seconds';
}

/*
 * Update mobile scan Info in content type mobile_scan_info
 */

function updateMobileScanInfo($siteid,$webscanId,$website){
    $tags = array();
    $start = microtime(true);
    $date = date("m-d-Y");
    $node = new stdClass();
    $node->type = "mobile_scan_information";
    $node->language = LANGUAGE_NONE;
    $node->uid = "1";
    $node->name = "admin";
    $node->status = 1;
    $node->title = "Mobile Scan ".$website['domain'];
    if(($nodeId = findNode($node->title,'mobile_scan_information')) != FALSE){
        echo "found node $node->title $nodeId";
        $node->nid = $nodeId;
    }
        $node->promote = 0;
        $mobInfo = getMobileAPIdata($website['domain']);
        //print_r($mobInfo);
        $node->body['und'][0]['value'] = '';
        $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
        $node->field_website_id['und'][0]['nid'] = $siteid;
        $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
        $node->field_mobile_usability_score['und'][0]['value'] = round($mobInfo['mobFriendlyScore']);
        $node->field_mobile_usability_result['und'][0]['value'] = ($mobInfo['mobFriendlyResult'] == 'true')?1:0;
        $node->field_mobile_performance_score['und'][0]['value'] = round($mobInfo['mPScore']);
        $node->field_mobile_usability_report['und'][0] = $mobInfo['mobFriendlyFile'];
        $node->field_mobile_performance_report['und'][0] = $mobInfo['mobPerformFile'];
        $node->field_mobile_websnapshot['und'][0] = $mobInfo['mobSnapshotFile'];
        $node->field_html_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['htmlResponseBytes'];
        $node->field_text_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['textResponseBytes'];
        $node->field_css_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['cssResponseBytes'];
        $node->field_image_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['imageResponseBytes'];
        $node->field_js_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['javascriptResponseBytes'];
        $node->field_other_response_bytes['und'][0]['value'] = $mobInfo['mPStats']['otherResponseBytes'];
        $node->field_number_of_js_resources['und'][0]['value'] = $mobInfo['mPStats']['numberJsResources'];
        $node->field_number_of_css_resources['und'][0]['value'] = $mobInfo['mPStats']['numberCssResources'];
        $node->field_number_of_resources['und'][0]['value'] = $mobInfo['mPStats']['numberResources'];
        $node->field_number_of_hosts['und'][0]['value'] = $mobInfo['mPStats']['numberHosts'];
        $node->field_total_request_bytes['und'][0]['value'] = $mobInfo['mPStats']['totalRequestBytes'];
        $node->field_number_of_static_resources['und'][0]['value'] = $mobInfo['mPStats']['numberStaticResources'];
        $node->field_mobile_overall_score['und'][0]['value'] = round(($mobInfo['mobFriendlyScore']+$mobInfo['mPScore'])/2);

    if($mobInfo['mobFriendlyResult'] == 'true'){
        $tags[] = "MOBILE";
    }
    //Load Parent website id
    $wnode = node_load($siteid);
    $wnode->field_mobile_performance_score['und'][0]['value'] = round($mobInfo['mPScore']);
    $wnode->field_mobile_usability_score['und'][0]['value'] = round($mobInfo['mobFriendlyScore']);
    $wnode->field_mobile_overall_score['und'][0]['value'] = round(($mobInfo['mobFriendlyScore']+$mobInfo['mPScore'])/2);

    //Save Tags to parent website
    if(!empty($tags)) {
        if(!empty($wnode->field_website_tags)){
            foreach($wnode->field_website_tags['und'] as $ctk  =>$ctval){
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
                    $wnode->field_website_tags['und'][$crnTermCnt+$i]['tid'] = $terms_array['0'];
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
                    $wnode->field_website_tags['und'][$key]['tid'] = $term->tid;
                }
            }
            $i += 1;
        }
    }
    //Update Parent Website Node
    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
    }

        node_object_prepare($node);
        if ($node = node_submit($node)) {
            node_save($node);
        }
        $end = microtime(true);
        print "Mobile scan for ".$website['domain']." took " . ($end - $start) . ' seconds';
}

/*
 * Find if node exists form title then return nid else return false
 */

function findNode($title,$type){
    $nid = db_query("select nid from node where title=:title and type=:type", array(':title' => $title,':type' => $type))->fetchField();

    if (!empty($nid )) {
        return $nid;
    }
    else{
        return FALSE;
    }
}

/*
 * Find if Parent Agnecy node of a website
 */

function findParentAgencyNode($websiteid){
    $nid = db_query("select field_web_agency_id_nid from field_data_field_web_agency_id where entity_id=:entity_id", array(':entity_id' => $websiteid))->fetchField();

    if (!empty($nid )) {
        return $nid;
    }
    else{
        return FALSE;
    }
}

/*
 * Get website shortname domain from domain id
 */
//function getDomainName($domainid){
//
//}
/*
 * Log Output in log file
 */
function writeToLogs($content,$logFile){
    $datetime = date("Y:m:d h:i:s a");
    $log_content = $datetime . " " . $content."\n";
    print $log_content;
    if(file_exists($logFile)) {
        file_put_contents($logFile, $log_content, FILE_APPEND | LOCK_EX);
    }
    else{
        file_put_contents($logFile, $log_content);
    }
}
