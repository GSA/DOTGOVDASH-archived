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

#$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.status='1'", array(':bundle' => 'website'));
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value LIKE 'access-board.gov' and b.nid=a.entity_id", array(':bundle' => 'website'));
//    $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id", array(':bundle' => 'website'));
//$query = db_query("select b.field_website_id_nid entity_id,d.body_value,c.title from field_data_field_site_inspector_raw_out a , field_data_field_website_id b , node c , field_data_body d where a.field_site_inspector_raw_out_value like '%Error:%' and a.entity_id=b.entity_id and b.field_website_id_nid = c.nid and c.nid = d.entity_id");
  $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id  and  b.status='1' and a.entity_id > '634'", array(':bundle' => 'website'));

    //Final Query
//    $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.nid not in (select c.field_website_id_nid from field_data_body a , node b, field_data_field_website_id c  where b.type='mobile_scan_information' and b.nid=a.entity_id and b.nid=c.entity_id and (UNIX_TIMESTAMP(CURRENT_TIMESTAMP()) - b.changed)/3600 >= 3)", array(':bundle' => 'website'));
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
 *
 *Initiatte all SSL labs domain scans at once
 */
function initiateSslLabsHostScan(){
    $listWebsites = getSites();
    foreach($listWebsites as $key=>$website){
        print $website['domain']." Scan Initiated at SSLlabs\n";
        //collectSslLabsDomInfo($website['domain']);
        $spout = shell_exec("../tools/ssllabs-scan/ssllabs-scan -grade -usecache=true ".$website['domain']);
    }
}

/*
 * SSL labs scan collect report info
 */

function collectSslLabsDomInfo($domain){
    include("../scripts/configSettings.php");
    require_once '../tools/ssllabs/sslLabsApi.php';
    //Return API response as JSON string
    $api = new sslLabsApi();
    $apiinfo = $api->fetchHostInformation($domain,false,false,true,24);

    //Set content-type header for JSON output
    writeToLogs("Starting  SSLlabs scan for website $domain \n",$logFile);

    $ip = getIPInfo($domain);
    $sslapi  = $api->fetchHostInformationCached($domain,24,false);
    $sslapiobj = json_decode($sslapi);
    //Consider results only if status is READY and not In Progress
    //print_r($sslapiobj);
    if($sslapiobj->status == 'READY'){
        foreach($sslapiobj->endpoints as $ekey=>$eval){
            //ignore capture grade from any endpoint where its available
            if($eval->grade != '') {
                print $eval->ipAddress."-".$eval->grade."\n";
                $grade = $eval->grade;
            }
        }
    }
    $sslData = array("raw"=>$apiinfo,"reportcontent"=>$sslapi,"grade"=>$grade);
    return $sslData;
}

/*
 * SSL labs scan collect report info
 */

function collectSslLabsDomRepInfo($domain){
    require_once '../tools/ssllabs/sslLabsApi.php';
    //Return API response as JSON string
    $api = new sslLabsApi();

    //Return API response as JSON object
    //$api = new sslLabsApi(true);

    //Set content-type header for JSON output
    print "Collecting ". $domain." Information from SSLlabs\n";
    $ip = getIPInfo($domain);
    $sslapi  = $api->fetchEndpointData($domain,(int)$ip[0],true);
    return $sslapi;
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
 * Get Site Page Speed API through Curl calls
 */

function sitePerformApidata($url, $apiKey)
{
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => 'https://www.googleapis.com/pagespeedonline/v2/runPagespeed?screenshot=true&key='.$apiKey.'&strategy=desktop&url='.$url.'',
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
    //Pass Site Inspector
    //$command = "/usr/local/lib/ruby/gems/2.4.0/gems/site-inspector-3.1.1/bin/site-inspector inspect -j $domain";
    $spout = shell_exec("export RUBYOPT=-W0;$command");
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
    $spRaw['humans_txt'] = $spRawOut['canonical_endpoint']['content']['humans_txt'];
    $spRaw['proper_404s'] = $spRawOut['canonical_endpoint']['content']['proper_404s'];
    $spRaw['dnssec'] = $spRawOut['canonical_endpoint']['dns']['dnssec'];
    $spRaw['ipv6'] = $spRawOut['canonical_endpoint']['dns']['ipv6'];

    return $spRaw;
}

/*
 * Get dnssec status of a domain. Domains with dnssec will return output with RRSIG data (DNNSEC cryptographic signature)
 * dig +dnssec pic.gov @8.8.8.8|grep -i 'rrsig'
 */

function getDnssecStatus($domain){
      $dnsseccom = "dig +dnssec $domain @8.8.8.8|grep -i 'rrsig'";
  $outp = array();
  $comret = "";
  execCommand("$dnsseccom",$outp,$comret);
  $commandString = implode(" ", $outp);
  //If the command output is null there is no RRSIG (DNNSEC cryptographic signature) info for the domain
  if(trim($commandString) == '')
    $dnssecstat = '0';
  else
    $dnssecstat = '1';
  return $dnssecstat;
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
    $pulsedapurl = "https://pulse.cio.gov/data/hosts/analytics.csv";
    //Get Pulse https data and enter to a temp table
    file_put_contents("$localhttpsfile", file_get_contents("$pulsehttpsurl"));
    db_query("truncate table custom_pulse_https_data");
    db_query("LOAD DATA LOCAL INFILE '".$localhttpsfile."' INTO TABLE `custom_pulse_https_data` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");

    //Get Pulse dap data and enter to a temp table
    file_put_contents("$localdapfile", file_get_contents("$pulsedapurl"));
    db_query("truncate table custom_pulse_dap_data");
    db_query("LOAD DATA LOCAL INFILE '".$localdapfile."' INTO TABLE `custom_pulse_dap_data` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");
    db_query("update custom_pulse_https_data a , custom_pulse_dap_data b set a.dap=b.dap where a.domain=b.domain");

  //Update branch information since pulse is not giving that data any more
  updateBranchInfo();

    //Update Agency information from CSV file
    updatePulseAgencyInfo("$localhttpsfile");

    //Update Website information from CSV file
    updatePulseWebsiteInfo("$localhttpsfile");
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

  //Collect HTTPS and Redirect status from Domain scan and update HTTPS
    $domainScanNodeTit = "Domain Scan ".$website['domain'];
    if(($domainNodeId = findNode($domainScanNodeTit,'domain_scan_information')) != FALSE){
        $domquery = db_query("select field_site_inspector_raw_out_value from  field_data_field_site_inspector_raw_out where entity_id=:nid", array(':nid' => $domainNodeId));
        foreach ($domquery as $domresult) {
            $domjson = json_decode($domresult->field_site_inspector_raw_out_value);
            $domjsonHttp =  $domjson->https;
            $domjsonRed =  $domjson->redirect;
            if($domjsonHttp == '1')
              $domjsonHttp = 'Yes';
            else
              $domjsonHttp = 'No';
          if($domjsonRed == '1')
            $domjsonRed = 'Yes';
          else
            $domjsonRed = 'No';

            db_query("update custom_pulse_https_data set HTTPS = '$domjsonHttp' , redirect = '$domjsonRed' where domain=:domain",array(':domain' => $website['domain']));
        }
    }

    $query = db_query("select * from  custom_pulse_https_data where domain=:domain", array(':domain' => $website['domain']));
    foreach ($query as $result) {
        $tags = array();
        $node->field_https_status['und'][0]['value'] = $result->HTTPS;
        $node->field_enforce_https['und'][0]['value'] = $result->EnfHTTPS;
        $node->field_hsts_status['und'][0]['value'] = $result->HSTS;
        $node->field_preload_status['und'][0]['value'] = $result->preloaded;
        $node->field_compl_m_15_13_bod['und'][0]['value'] = $result->Compliant_mbod;
        $node->field_free_of_rc4_3des_and_sslv2['und'][0]['value'] = $result->freeofunsecure;
        $node->field_3des_status['und'][0]['value'] = $result->des3;
        $node->field_rc4_status['und'][0]['value'] = $result->rc4;
        $node->field_ssl_v2_from_pulse['und'][0]['value'] = $result->sslv2;
        $node->field_ssl_v3_from_pulse['und'][0]['value'] = $result->sslv3;
        $node->field_redirect['und'][0]['value'] = $result->redirect;
        if($result->redirect == 'Yes')
            $node->field_redirect_url['und'][0]['value'] = getSiteRedirectDest($website['domain']);
        $node->field_hsts_scan_time['und'][0]['value'] = (int)time();
        $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
        $node->field_website_id['und'][0]['nid'] = $siteid;
        $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
        if($result->dap == 'Yes') {
            $dapstatus = 1;
            $dapscore = '100';
        }
        elseif($result->dap == 'No') {
            $dapstatus = 0;
            $dapscore = '0';
        }
        else {
            $dapstatus = NULL;
            $dapscore = NULL;
        }
        $node->field_dap_status['und'][0]['value'] = $dapstatus;
        $node->field_dap_score['und'][0]['value'] = $dapscore;

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
    $wnode->field_dap_score['und'][0]['value'] = $dapscore;


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

    //print_r($node);
    node_object_prepare($node);
    if ($node = node_submit($node)) {
        node_save($node);
    }

    $wnode->field_https_scan_node['und'][0]['target_id'] = $node->nid;

    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
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
    //Override Siteinspector dnssec with custom dnssec result
     $siInfo['dnssec'] = getDnssecStatus($website['domain']);
	
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
    $node->field_ipv6_compliance['und'][0]['value'] = ($siInfo['ipv6'] == '')?0:1;
    $node->field_dnssec_compliance['und'][0]['value'] = $siInfo['dnssec'];

    //Get SSL labs scan ouput
    //$ssllabsInfo = collectSslLabsDomInfo($website['domain']);
    //$node->field_ssl_labs_score['und'][0]['value'] = $ssllabsInfo['grade'];
    //$node->field_ssl_labs_raw_out['und'][0]['value'] = $ssllabsInfo['raw'];
    //$sslLabsFile = file_save_data($ssllabsInfo['reportcontent'],file_default_scheme().'://ssl_labs_reports/'.$website["domain"].'.json', FILE_EXISTS_REPLACE);
    //$sslLabsFileArr = array('fid' => $sslLabsFile->fid,'display' => 1, 'description' => '');
    //$node->field_ssl_labs_report['und'][0] = $sslLabsFileArr;

//Save parent website node
    $wnode = node_load($siteid);

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
    if($siInfo['ipv6'] == '1') {
        $tags[] = 'IPV6';
        $wnode->field_ipv6_score['und'][0]['value'] = '100';
    }
    else
        $wnode->field_ipv6_score['und'][0]['value'] = '0';

    if($siInfo['dnssec'] == '1') {
        $tags[] = 'DNSSEC';
        $wnode->field_dnssec_score['und'][0]['value'] = '100';
    }
    else
        $wnode->field_dnssec_score['und'][0]['value'] = '0';

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

    node_object_prepare($node);
    if ($node = node_submit($node)) {
        node_save($node);
    }

    $wnode->field_domain_scan_node['und'][0]['target_id'] = $node->nid;
    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
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
    node_object_prepare($node);
    if ($node = node_submit($node)) {
        node_save($node);
    }

    //Update Parent Website Node
    $wnode->field_mobile_scan_node['und'][0]['target_id'] = $node->nid;
    node_object_prepare($wnode);
    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
    }


    $end = microtime(true);
    print "Mobile scan for ".$website['domain']." took " . ($end - $start) . ' seconds';
}

/*
 * Update site speed scan Info in content type site_speed_scan
 */

function updateSiteScanInfo($siteid,$webscanId,$website){
    $tags = array();
    $start = microtime(true);
    $date = date("m-d-Y");
    $node = new stdClass();
    $node->type = "site_speed_scan";
    $node->language = LANGUAGE_NONE;
    $node->uid = "1";
    $node->name = "admin";
    $node->status = 1;
    $node->title = "Site Performance Scan ".$website['domain'];
    if(($nodeId = findNode($node->title,'site_speed_scan')) != FALSE){
        echo "found node $node->title $nodeId";
        $node->nid = $nodeId;
    }
    $node->promote = 0;
    $siteInfo = getSitePerformanceAPIdata($website['domain']);
    //print_r($mobInfo);
    $node->body['und'][0]['value'] = '';
    $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
    $node->field_website_id['und'][0]['nid'] = $siteid;
    $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
    $node->field_site_speed_score['und'][0]['value'] = round($siteInfo['mPScore']);
    $node->field_site_speed_report_location['und'][0] = $siteInfo['sitePerformFile'];
    $node->field_website_desktop_snapshot['und'][0] = $siteInfo['siteSnapshotFile'];
    $node->field_html_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['htmlResponseBytes'];
    $node->field_text_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['textResponseBytes'];
    $node->field_css_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['cssResponseBytes'];
    $node->field_image_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['imageResponseBytes'];
    $node->field_js_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['javascriptResponseBytes'];
    $node->field_other_response_bytes['und'][0]['value'] = $siteInfo['mPStats']['otherResponseBytes'];
    $node->field_number_of_js_resources['und'][0]['value'] = $siteInfo['mPStats']['numberJsResources'];
    $node->field_number_of_css_resources['und'][0]['value'] = $siteInfo['mPStats']['numberCssResources'];
    $node->field_number_of_resources['und'][0]['value'] = $siteInfo['mPStats']['numberResources'];
    $node->field_number_of_hosts['und'][0]['value'] = $siteInfo['mPStats']['numberHosts'];
    $node->field_total_request_bytes['und'][0]['value'] = $siteInfo['mPStats']['totalRequestBytes'];
    $node->field_number_of_static_resources['und'][0]['value'] = $siteInfo['mPStats']['numberStaticResources'];


    //Load Parent website id
    $wnode = node_load($siteid);
    $wnode->field_site_speed_score['und'][0]['value'] = round($siteInfo['mPScore']);


    node_object_prepare($node);
    if ($node = node_submit($node)) {
        node_save($node);
    }

    //Update Parent Website Node
    $wnode->field_site_speed_scan_node['und'][0]['target_id'] = $node->nid;
    node_object_prepare($wnode);

    if ($wnode = node_submit($wnode)) {
        node_save($wnode);
    }


    $end = microtime(true);
    print "Site speed scan for ".$website['domain']." took " . ($end - $start) . ' seconds';
}


/*
 * Run Site performance API calls to Google and get the data
 */

function getSitePerformanceAPIdata($domain){
    include("../scripts/configSettings.php");
    $siteSpeedAPIdataArr = array();
    //We are not using drupal system_retrieve_file because it failed url calls to google randomly
    $http_domain = "http://".$domain;
    $https_domain = "https://".$domain;
    $googleApiKey = "AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4";

    //Call to Google Inights Speed API
    if(!$googSitePerformApiData = sitePerformApidata("$http_domain","$googleApiKey")) {
        $error = error_get_last();
        writeToLogs("API request failed to $http_domain . Error was: " . $error['message'],$logFile);
    }
    else{
        $sitePerformFile = file_save_data($googSitePerformApiData,file_default_scheme().'://sitespeed_reports/'.$domain.'.json', FILE_EXISTS_REPLACE);
        $siteSpeedAPIdataArr['sitePerformFile'] = array('fid' => $sitePerformFile->fid,'display' => 1, 'description' => '');

        $jsonMParr = json_decode($googSitePerformApiData, true);
        if($siteSpeedAPIdataArr['siteSnapshotData'] == ''){
            $siteSnapshotData = str_replace('_', '/', $jsonMParr['screenshot']['data']);
            $siteSnapshotData = str_replace('-', '+', $siteSnapshotData);
            $siteSnapshotData = base64_decode($siteSnapshotData);
            $siteSpeedAPIdataArr['siteSnapshotData'] = $siteSnapshotData;
            $snapshotfile = file_save_data($siteSnapshotData,file_default_scheme().'://desktop_snapshots/'.$domain.'.jpg', FILE_EXISTS_REPLACE);
            $siteSpeedAPIdataArr['siteSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
        }
        $siteSpeedAPIdataArr['mPScore'] = $jsonMParr['ruleGroups']['SPEED']['score'];
        $siteSpeedAPIdataArr['mPStats'] = $jsonMParr['pageStats'];


    }
    return $siteSpeedAPIdataArr;
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

/*
 * Update the pulse Agency Information
 */
function updatePulseAgencyInfo($csvfile){
    // Set path to CSV file
    //$csvFile = '../scripts/websiteListing.csv';

    $csv = readCSV("$csvfile");

    $i =1;
    foreach($csv as $csval){
        print "$csval[3] \n";
        if(trim($csval[3]) != ''){
          $branchname = getBranchInfo($csval[3]);
            //Check if the Agency exists if not create a new agency
            if(($agencyId = findNode($csval[3],'agency')) != FALSE){
                echo "found agency $agencyId";
                $anode = node_load($agencyId);
                //Update only branch info for agency in case it changed

                if($anode->field_agency_branch[$anode->language][0]['value'] != $branchname) {
                    $anode->field_agency_branch[$anode->language][0]['value'] = $branchname;
                    node_object_prepare($anode);
                    if ($anode = node_submit($anode)) {
                        node_save($anode);
                    }
                }
            }
            else{
                //Create new agnecy
                $anode = new stdClass();  // Create a new node object
                $anode->type = 'agency';  // Content type
                $anode->language = LANGUAGE_NONE;  // Or e.g. 'en' if locale is enabled

                $anode->title = $csval[3];
                $anode->status = 1;   // (1 or 0): published or unpublished
                $anode->promote = 0;  // (1 or 0): promoted to front page or not
                $anode->sticky = 0;  // (1 or 0): sticky at top of lists or not
                $anode->comment = 0;  // 2 = comments open, 1 = comments closed, 0 = comments hidden
// Add author of the node
                $anode->uid = "1";
                $anode->name = "admin";
                $anode->field_agency_branch[$anode->language][0]['value'] = $branchname;
                node_object_prepare($anode);
                if($anode=node_submit($anode)){
                    node_save($anode);
                }
            }
            $i++;
        }
    }

}

/*
 * Update the pulse Website Information
 */
function updatePulseWebsiteInfo($csvfile){
    // Set path to CSV file
    //$csvFile = '../scripts/websiteListing.csv';

    $csv = readCSV("$csvfile");

    $i =1;
    foreach($csv as $csval){
        print "$csval[0] \n";
        //if((($nodeId = findNode($csval[0],'website')) == FALSE) && ($csval[0] != '')){
        if(trim($csval[0]) != ''){
            $node = new stdClass();  // Create a new node object
            $node->type = 'website';  // Content type
            $node->language = LANGUAGE_NONE;  // Or e.g. 'en' if locale is enabled

            if(($nodeId = findNode($csval[0],'website')) != FALSE){
                echo "Found node ".$node->title." $nodeId";
                $node->nid = $nodeId;
            }

            $node->title = $csval[0];

            $node->body[$node->language][0]['value'] = $csval[1];
            $node->field_agency_branch[$node->language][0]['value'] = getBranchInfo($csval[3]);

            //Check if the Agency exists if not create a new agency
            if(($agencyId = findNode($csval[3],'agency')) != FALSE){
                echo "found agency $agencyId";
                $node->field_web_agency_id[$node->language][0]['nid'] = $agencyId;
            }

            $node->field_parent_agency_name[$node->language][0]['value'] = $csval[3];

            $node->field_website_type[$node->language][0]['value'] = "full";

            $node->status = 1;   // (1 or 0): published or unpublished
            $node->promote = 0;  // (1 or 0): promoted to front page or not
            $node->sticky = 0;  // (1 or 0): sticky at top of lists or not
            $node->comment = 0;  // 2 = comments open, 1 = comments closed, 0 = comments hidden
// Add author of the node
            $node->uid = "1";
            $node->name = "admin";
            node_object_prepare($node);  //Set some default values

// Save the node
            if($node=node_submit($node)){
                node_save($node);
            }

            $i++;

        }
    }

}

function readCSV($csvFile){
    $file_handle = fopen($csvFile, 'r');
    while (!feof($file_handle) ) {
        $line_of_text[] = fgetcsv($file_handle, 1024);
    }
    fclose($file_handle);
    return $line_of_text;
}

function findCDNProvider($website){
    //List of Potential Domains matching CDN providers. Borrowed from https://github.com/turbobytes/cdnfinder
    $cdnMatchList = array(
        ".clients.turbobytes.net"=>"TurboBytes",
        ".turbobytes-cdn.com"=>"TurboBytes",
        ".afxcdn.net"=>"afxcdn.net",
        ".akamai.net"=>"Akamai",
        ".akam.net"=>"Akamai",
        ".akamaiedge.net"=>"Akamai",
        ".akamaized.net"=>"Akamai",
        ".akamaihd.net"=>"Akamai",
        ".akamaistream.net"=>"Akamai",
        ".edgekey.net"=>"Akamai",
        ".edgesuite.net"=>"Akamai",
        ".akadns.net"=>"Akamai",
        ".akamaitech.net"=>"Akamai",
        ".akamaitechnologies."=>"Akamai",
        ".gslb.tbcache.com"=>"Alimama",
        ".cloudfront.net"=>"Amazon Cloudfront",
        ".anankecdn.com.br"=>"Ananke",
        ".att-dsa.net"=>"AT&T",
        ".azioncdn.net"=>"Azion",
        ".belugacdn.com"=>"BelugaCDN",
        ".bluehatnetwork.com"=>"Blue Hat Network",
        ".systemcdn.net"=>"EdgeCast",
        ".cachefly.net"=>"Cachefly",
        ".cdn77.net"=>"CDN77",
        ".cdn77.org"=>"CDN77",
        ".panthercdn.com"=>"CDNetworks",
        ".cdngc.net"=>"CDNetworks",
        ".gccdn.net"=>"CDNetworks",
        ".gccdn.cn"=>"CDNetworks",
        ".cdnify.io"=>"CDNify",
        ".ccgslb.com"=>"ChinaCache",
        ".ccgslb.net"=>"ChinaCache",
        ".c3cache.net"=>"ChinaCache",
        ".chinacache.net"=>"ChinaCache",
        ".c3cdn.net"=>"ChinaCache",
        ".lxdns.com"=>"ChinaNetCenter",
        ".speedcdns.com"=>"QUANTIL/ChinaNetCenter",
        ".cloudflare.com"=>"Cloudflare",
        ".cloudflare.net"=>"Cloudflare",
        ".edgecastcdn.net"=>"EdgeCast",
        ".adn."=>"EdgeCast",
        ".wac."=>"EdgeCast",
        ".wpc."=>"EdgeCast",
        ".fastly.net"=>"Fastly",
        ".fastlylb.net"=>"Fastly",
        ".google."=>"Google",
        "googlesyndication."=>"Google",
        "youtube."=>"Google",
        ".googleusercontent.com"=>"Google",
        ".l.doubleclick.net"=>"Google",
        ".hiberniacdn.com"=>"Hibernia",
        ".hwcdn.net"=>"Highwinds",
        ".incapdns.net"=>"Incapsula",
        ".inscname.net"=>"Instartlogic",
        ".insnw.net"=>"Instartlogic",
        ".internapcdn.net"=>"Internap",
        ".kxcdn.com"=>"KeyCDN",
        ".lswcdn.net"=>"LeaseWeb CDN",
        ".footprint.net"=>"Level3",
        ".llnwd.net"=>"Limelight",
        ".lldns.net"=>"Limelight",
        ".netdna-cdn.com"=>"MaxCDN",
        ".netdna-ssl.com"=>"MaxCDN",
        ".netdna.com"=>"MaxCDN",
        ".mncdn.com"=>"Medianova",
        ".instacontent.net"=>"Mirror Image",
        ".mirror-image.net"=>"Mirror Image",
        ".cap-mii.net"=>"Mirror Image",
        ".rncdn1.com"=>"Reflected Networks",
        ".simplecdn.net"=>"Simple CDN",
        ".swiftcdn1.com"=>"SwiftCDN",
        ".swiftserve.com"=>"SwiftServe",
        ".gslb.taobao.com"=>"Taobao",
        ".cdn.bitgravity.com"=>"Tata communications",
        ".cdn.telefonica.com"=>"Telefonica",
        ".vo.msecnd.net"=>"Windows Azure",
        ".ay1.b.yahoo.com"=>"Yahoo",
        ".yimg."=>"Yahoo",
        ".zenedge.net"=>"Zenedge"
    );
    $comout = shell_exec("dig +trace $website");
    $cdnMatched = array();
    $match = "false";
    //print $comout;
    foreach($cdnMatchList as $key=>$val){
        if (strpos($comout, $key) !== false) {
            $cdnMatched[$val] = $val;
            $match = true;
        }
    }
    if(($match == "false") && (strpos($website, "www.") === false)){
        $www_website = "www.".$website;
        $cdnMatched = findCDNProvider($www_website);
    }
    return $cdnMatched;
}

/*
 * Run Scan to collect Website information
 */

function updateTechStackInfo($website){
    //Associate field names with categories of technology
    $varCatassoc = array("cms"=>"field_cms_applications",
        "widgets"=>"field_widget_applications",
        "analytics"=>"field_analytics_applications",
        "font scripts"=>"field_font_script_applications",
        "web servers"=>"field_web_server",
        "cache tools"=>"field_cache_tools",
        "javascript frameworks"=>"field_javascript_frameworks",
        "programming languages"=>"field_programming_languages",
        "advertising networks"=>"field_advertising_networks",
        "blogs"=>"field_blog_applications",
        "build ci systems"=>"field_build_ci_systems",
        "captchas"=>"field_captcha_applications",
        "cdn"=>"field_cdn_applications",
        "comment systems"=>"field_comment_systems_applicatio",
        "control systems"=>"field_control_systems_applicatio",
        "crm"=>"field_crm_applications",
        "database managers"=>"field_database_managers",
        "databases"=>"field_databases",
        "dev tools"=>"field_dev_tools",
        "document management systems"=>"field_document_management_system",
        "documentation tools"=>"field_documentation_tools",
        "ecommerce"=>"field_ecommerce_applications",
        "editors"=>"field_editor_applications",
        "feed readers"=>"field_feed_readers",
        "hosting panels"=>"field_hosting_panels",
        "issue trackers"=>"field_issue_trackers",
        "javascript graphics"=>"field_javascript_graphics_applic",
        "landing page builders"=>"field_landing_page_builders",
        "live chat"=>"field_live_chat_applications",
        "lms"=>"field_lms_applications",
        "maps"=>"field_maps_applications",
        "marketing automation"=>"field_marketing_automation",
        "media servers"=>"field_media_servers",
        "message boards"=>"field_message_boards",
        "miscellaneous"=>"field_miscellaneous_application",
        "mobile frameworks"=>"field_mobile_frameworks",
        "network devices"=>"field_network_devices",
        "network storage"=>"field_network_storage",
        "operating systems"=>"field_operating_systems",
        "payment processors"=>"field_payment_processors",
        "photo galleries"=>"field_photo_galleries",
        "remote access"=>"field_remote_access",
        "rich text editors"=>"field_rich_text_editors",
        "search engines"=>"field_search_engines",
        "tag managers"=>"field_tag_managers",
        "video players"=>"field_video_players",
        "web frameworks"=>"field_web_frameworks",
        "web mail"=>"field_web_mail_applications",
        "web server extensions"=>"field_web_server_extensions",
        "wikis"=>"field_wiki_applications");
    $weburl = "http://".$website;
    //$command = "node index.js $weburl";
    //$tsout = shell_exec("export npm_config_loglevel=silent;cd ../tools/wappalyzer/;$command");
    $command = "node /usr/lib/node_modules/wappalyzer/index.js $weburl";
    shell_exec("export npm_config_loglevel=silent");
    $tsout = shell_exec("export npm_config_loglevel=silent;$command");
if (strpos($tsout, 'JQMIGRATE:') !== false) {
    $tsout1 = explode(" version 1.4.1",$tsout);
    $tsout = $tsout1[1];
}
    $tsout2 = strstr($tsout,'[{"');
    $tsout2 = str_replace('\'', '\\\'', $tsout2);
    $tsout2 = str_replace("\\n","",$tsout2);

    $tsobj = json_decode($tsout2);
    $tags = array();
    $k = 1;
    //foreach($tsobj->applications as $tskey=>$tsobj){
    foreach($tsobj as $tskey=>$tsobj){
        $tsAppname = $tsobj->name;
        //$tsAppCat = $tsobj->categories[0];
        $tsAppCat1 = (Array)$tsobj->categories[0];
        $tsAppCat = array_values($tsAppCat1)[0];

        //$tags[$tsAppCat] = array();
        //if version is present append version to technology

        if(trim($tsobj->version) != '') {
            $tsAppname .= "_" . $tsobj->version;
            //if (!in_array($tsAppname, $tags[$tsAppCat]))
                $tags[strtolower($tsAppCat)][] = $tsAppname;
        }

            $tags[strtolower($tsAppCat)][] = $tsobj->name;
    }
    //print_r($tags);
    $curNodeid = findNode($website,'website');
    $webnode = node_load($curNodeid);
    $webnode->field_technology_scan_raw['und'][0]['value'] = $tsout2;
    $cdnproviders = findCDNProvider("$website");
foreach($varCatassoc as $vkey=>$vval){
		 $webnode->{$vval} = array();
		//print "$vkey -- $vval \n";
	}
    if(!empty($cdnproviders)){
        $tags['cdn'] = array_values($cdnproviders);
    }
    print_r($tags);
    foreach ($tags as $key => $tagarr) {
        $i = 0;
        foreach ($tagarr as $tkey => $tag) {
            if(array_key_exists($key,$varCatassoc)){
                //Check if term exists
                if ($term = taxonomy_get_term_by_name($tag)) {
                    $terms_array = array_keys($term);

                    $webnode->{$varCatassoc["$key"]}['und'][$i]['tid'] = $terms_array['0'];

                } else {
                    //Create a new term and assign
                    $term = new STDClass();
                    $term->name = $tag;
                    $term->vid = 2;
                    if (!empty($term->name)) {
                        taxonomy_term_save($term);
                        $webnode->{$varCatassoc["$key"]}['und'][$i]['tid'] = $term->tid;
                    }
                }

            }
            $i += 1;
        }

    }
    //print_r($webnode->field_analytics_applications);
    node_object_prepare($webnode);
    if ($webnode = node_submit($webnode)) {
        node_save($webnode);
    }
}


function recursive_array_search($needle,$haystack) {
    foreach($haystack as $key=>$value) {
        $current_key=$key;
        if($needle===$value OR (is_array($value) && recursive_array_search($needle,$value) !== false)) {
            return $current_key;
        }
    }
    return false;
}

/*
 * Function for Accessibility Scan.
 */
function updateAccessibleScanInfo($webscanId){
    include("../scripts/configSettings.php");

    //Define the accessible url
    $accessInfo = getAccessibleAPIdata();

    $all_agencies_file= file_default_scheme() . '://accessibility_reports/all_agencies.json';
    $allDomAgencycontents = file_get_contents($all_agencies_file);
    $allDomAgencycontents = utf8_encode($allDomAgencycontents);
    $allAgenArr = json_decode($allDomAgencycontents, true);
    foreach($allAgenArr['data'] as $errorlistk => $errorlistv) {
 if (($agAgencyNodeId = findNode($errorlistv['agency'],'agency')) != FALSE) {
        $pageCnt = $errorlistv['pages_count'];
        $agColCont = $errorlistv['Color Contrast - Initial Findings'];
        $agMissImage = $errorlistv['Missing Image Descriptions'];
        $agHtmlAtrrib = $errorlistv['HTML Attribute - Initial Findings'];
        $agFormFind = $errorlistv['Form - Initial Findings'];
        $agAvError = $errorlistv['Average Errors per Page'];
        $date = date("m-d-Y");
        $agnode = new stdClass();
        $agnode->type = "accessibility_agency_scan_inform";
        $agnode->language = LANGUAGE_NONE;
        $agnode->uid = "1";
        $agnode->name = "admin";
        $agnode->status = 1;
        $agnode->title = "Accessibility Agency Scan " . $errorlistv['agency'];
        if (($nodeId = findNode($agnode->title, 'accessibility_agency_scan_inform')) != FALSE) {
            echo "found node $agnode->title $nodeId";
            $agnode->nid = $nodeId;
        }
        $agnode->promote = 0;

        $agnode->field_web_scan_id['und'][0]['nid'] = $webscanId;
        $agnode->field_web_agency_id['und'][0]['nid'] = $agAgencyNodeId;
        $agnode->field_agac_average_errors_page['und'][0]['value'] = $agAvError;
        $agnode->field_agac_agency_pages_cnt['und'][0]['value'] = $pageCnt;
        $agnode->field_agac_color_contrast_aver['und'][0]['value'] = $agColCont;
        $agnode->field_agac_missing_image_avrg['und'][0]['value'] = $agMissImage;
        $agnode->field_agac_html_attribute_avrg['und'][0]['value'] = $agHtmlAtrrib;
        $agnode->field_agac_form_init_find_avrg['und'][0]['value'] = $agFormFind;
        $agnode->body['und'][0]['value'] = json_encode($errorlistv);

        node_object_prepare($agnode);
        if ($agnode = node_submit($agnode)) {
            node_save($agnode);
        }
        print "$agAgencyNodeId --  ".$errorlistv['agency']." \n";
    }
    }


    $all_errors_file= file_default_scheme() . '://accessibility_reports/all_errors.json';
    $allDomErrcontents = file_get_contents($all_errors_file);
    $allDomErrcontents = utf8_encode($allDomErrcontents);
    $allDomErrArr = json_decode($allDomErrcontents, true);

    //Process detailed error data. We mostly use this to capture the exact WCAG code and updating website content
    foreach($allDomErrArr['data'] as $errorlistk => $errorlistv){
        foreach($errorlistv as $errorintk1=>$errorintv1) {
            $wcagCodearrOld = array();
            foreach($errorintv1 as $errorintk=>$errorintv) {
                $wcagCodearrOld[] = $errorintv['code'];
                //print $errorlistk."--".$errorintk1."--".$errorintv['code']."\n";
            }
            $wcagCodearr[$errorlistk][$errorintk1] = array_unique($wcagCodearrOld);
        }
    }

    $all_domains_file= 'sites/default/files/accessibility_reports/all_domains.json';
    $allDomcontents = file_get_contents($all_domains_file);
    $allDomcontents = utf8_encode($allDomcontents);
    $allDomArr = json_decode($allDomcontents, true);

    //Process All Domains file
    $allDomainNewArr = array();
    foreach($allDomArr['data'] as $domkey=>$domval) {
        $start = microtime(true);
        $domain = $domval['domain'];
        $siteId = findNode($domval['domain'],'website');
        if($siteId != '') {
          //  if ($domval['domain'] == 'inl.gov') {
                $allDomainNewArr[$domval['domain']]['errorlist'] = $domval['errorlist'];
                $allDomainNewArr[$domval['domain']]['errordetails'] = $allDomErrArr['data'][$domain];
                $errorgroupTerms = array();
                $totError = 0;
                foreach ($domval['errorlist'] as $derror => $derrorval) {
                    if ($derror == 'Color Contrast - Initial Findings')
                        $cntColor = $derrorval;
                    elseif ($derror == 'HTML Attribute - Initial Findings')
                        $cntHTML = $derrorval;
                    elseif ($derror == 'Missing Image Descriptions')
                        $cntMissing = $derrorval;

                    if ($derrorval != 0) {
                        $errorgroupTerms[] = $derror;
                    }
                    $totError += $derrorval;
                }

                //$agencyId = findNode($domval['agency'],'agency');

                //Create Accessibility Scanning Node

                $date = date("m-d-Y");
                $node = new stdClass();
                $node->type = "508_scan_information";
                $node->language = LANGUAGE_NONE;
                $node->uid = "1";
                $node->name = "admin";
                $node->status = 1;
                $node->title = "Accessibility Scan " . $domval['domain'];
                if (($nodeId = findNode($node->title, '508_scan_information')) != FALSE) {
                    echo "found node $node->title $nodeId";
                    $node->nid = $nodeId;
                }
                $node->promote = 0;

                $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
                $node->field_website_id['und'][0]['nid'] = $siteId;
                $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteId);
                $node->field_508_scan_time['und'][0]['value'] = time();
                $node->field_accessibility_raw_scan['und'][0]['value'] = json_encode($allDomErrArr['data'][$domain]);
                $node->field_accessible_group_colorcont['und'][0]['value'] = $cntColor;
                $node->field_accessible_group_htmlattri['und'][0]['value'] = $cntHTML;
                $node->field_accessible_group_missingim['und'][0]['value'] = $cntMissing;

                node_object_prepare($node);
                if ($node = node_submit($node)) {
                    node_save($node);
                }

                //Update Parent Website with required tagging info
                //print_r($wcagCodearr[$domval['domain']]);

                $wnode = node_load($siteId);
                $wnode->field_accessibility_total_errors['und'][0]['value'] = $totError;
                $j = 1;
                $i = 1;

                if(!empty($wnode->field_accessibility_errors)){
                    foreach($wnode->field_accessibility_errors['und'] as $etk  =>$etval){
                        $currentTermsErr[] = $etval['tid'];
                    }
                    $crnTermCntErr = count($currentTermsErr);
                }

                if(!empty($wnode->field_accessibility_error_group)){
                    foreach($wnode->field_accessibility_error_group['und'] as $egtk  =>$egval){
                        $currentTermsErrGrp[] = $egval['tid'];
                    }
                    $crnTermCntErrGrp = count($currentTermsErrGrp);
                }

                foreach($wcagCodearr[$domval['domain']] as $tagkey => $tags) {

                    if ($eterm = taxonomy_get_term_by_name($tagkey)) {
                        //print_r($eterm);
                        //$wnode->field_accessibility_error_group['und'][$j]['tid'] = $eterm->tid;
                        $terms_array = array_keys($eterm);
                        //Check if the term already assigned to the node
                        if(!in_array($terms_array['0'],$currentTermsErrGrp)){
                            $wnode->field_accessibility_error_group['und'][$crnTermCntErrGrp+$j]['tid'] = $terms_array['0'];
                        }
                    } else {
                        $eterm = new STDClass();
                        $eterm->name = $tagkey;
                        $eterm->vid = 5;
                        if (!empty($eterm->name)) {
                            taxonomy_term_save($eterm);
                            $wnode->field_accessibility_error_group['und'][$j]['tid'] = $eterm->tid;
                        }
                    }

                    foreach ($tags as $key => $tag) {
                        if ($term = taxonomy_get_term_by_name($tag)) {
                            $terms_array_err = array_keys($term);
                            //Check if the term already assigned to the node
//                            print_r($term);
                            if(!in_array($terms_array_err['0'],$crnTermCntErr)) {
                                $wnode->field_accessibility_errors['und'][$crnTermCntErr+$j]['tid'] = $terms_array_err['0'];
                            }
                        } else {
                            $term = new STDClass();
                            $term->name = $tag;
                            $term->vid = 4;
                            if (!empty($term->name)) {
                                taxonomy_term_save($term);
                                $wnode->field_accessibility_errors['und'][$i]['tid'] = $term->tid;
                            }
                        }
                        $i += 1;
                    }
                    $j += 1;
                }
                node_object_prepare($wnode);
                if ($wnode = node_submit($wnode)) {
                    node_save($wnode);
                }


           // }
        }
        $end = microtime(true);
        writeToLogs("Accessibility scan for ".$domval['domain']." took " . ($end - $start) . "seconds.", $logFile);
    }

    writeToLogs("Accessibility Scans for all domains is finished.",$logFile);

    //print_r($wcagCodearr);
    //print_r($errorgroupTerms);

}

/*
 * Get Json Data through Curl calls
 */

function getJsondata($url)
{
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => $url,
    ));
    $resp = curl_exec($curl);
    curl_close($curl);

    return $resp;
}


/*
 * Function to get Accessible Data from Pulse API. The scan source is
 * https://staging.pulse.cio.gov/static/data/tables/accessibility/a11y.json
 * https://staging.pulse.cio.gov/static/data/tables/accessibility/domains.json
 */

function getAccessibleAPIdata(){
    include("../scripts/configSettings.php");
    //We are not using drupal system_retrieve_file because it failed url calls to google randomly

    //Call to Pulse accessibility All Domains API
    if(!$siteAccessApiData = getJsondata("$accessible_domains_url")) {
        $error = error_get_last();
        writeToLogs("API request failed to $accessible_domains_url . Error was: " . $error['message'],$logFile);
    }
    else {
        $allDomsFile = file_save_data($siteAccessApiData, file_default_scheme() . '://accessibility_reports/all_domains.json', FILE_EXISTS_REPLACE);
    }


    //Call to Pulse accessibility All Errors API
    if(!$siteAccessErrorApiData = getJsondata("$accessible_errors_url")) {
        $error = error_get_last();
        writeToLogs("API request failed to $accessible_errors_url . Error was: " . $error['message'],$logFile);
    }
    else {
        $allErrorsFile = file_save_data($siteAccessErrorApiData, file_default_scheme() . '://accessibility_reports/all_errors.json', FILE_EXISTS_REPLACE);
    }

    //Call to Pulse accessibility All Agencies API
    if(!$agencyAccessApiData = getJsondata("$accessible_agencyAPI_url")) {
        $error = error_get_last();
        writeToLogs("API request failed to $accessible_agencyAPI_url . Error was: " . $error['message'],$logFile);
    }
    else {
        $allAgenciesFile = file_save_data($agencyAccessApiData, file_default_scheme() . '://accessibility_reports/all_agencies.json', FILE_EXISTS_REPLACE);
    }

}

/*
 * Update Branch Info. Previously pulse was giving this data
 */

function updateBranchInfo(){
  //Update Legislative Branch sites
  db_query("update custom_pulse_https_data set branch='legislative' where agency in 
	('Architect of the Capitol','Congressional Office of Compliance','Government Publishing Office','Library of Congress','Stennis Center for Public Service','The Legislative Branch (Congress)','U.S. Capitol Police')");
  //Update Judicial Branch Sites
  db_query("update custom_pulse_https_data set branch='judicial' where  agency in ('The Supreme Court','U.S Courts')");
  //Update Executive Bracnh Sites
  db_query("update custom_pulse_https_data set branch='executive' where agency in 
	(('Administrative Conference of the United States'),('Advisory Council on Historic Preservation'),
	('African Development Foundation'),
	('American Battle Monuments Commission'),
	('AMTRAK'),
	('Appalachian Regional Commission'),
	('Appraisal Subcommittee'),
	('Armed Forces Retirement Home'),
	('Central Intelligence Agency'),
	('Civil Air Patrol'),
	('Comm for People Who Are Blind/Severly Disabled'),
	('Commodity Futures Trading Commission'),
	('Consumer Financial Protection Bureau'),
	('Consumer Product Safety Commission'),
	('Corporation for National & Community Service'),
	('Council of Inspector General on Integrity and Efficiency'),
	('Court Services and Offender Supervision'),
	('Defense Nuclear Facilities Safety Board'),
	('Delta Regional Authority'),
	('Denali Commission'),
	('Department of Agriculture'),
	('Department of Commerce'),
	('Department of Defense'),
	('Department of Education'),
	('Department of Energy'),
	('Department of Health And Human Services'),
	('Department of Homeland Security'),
	('Department of Housing And Urban Development'),
	('Department of Justice'),
	('Department of Labor'),
	('Department of State'),
	('Department of State OIG'),
	('Department of the Interior'),
	('Department of the Treasury'),
	('Department of Transportation'),
	('Department of Veterans Affairs'),
	('Director of National Intelligence'),
	('Environmental Protection Agency'),
	('Equal Employment Opportunity Commission'),
	('Executive Office of the President'),
	('Export/Import Bank of the U.S.'),
	('Federal Communications Commission'),
	('Federal Deposit Insurance Corporation'),
	('Federal Elections Commission'),
	('Federal Energy Regulatory Commission'),
	('Federal Housing Finance Agency'),
	('Federal Housing Finance Agency Office of Inspector General'),
	('Federal Labor Relations Authority'),
	('Federal Maritime Commission'),
	('Federal Mediation and Conciliation Service'),
	('Federal Mine Safety and Health Review Company'),
	('Federal Reserve System'),
	('Federal Retirement Thrift Investment Board'),
	('Federal Trade Commission'),
	('General Services Administration'),
	('Gulf Coast Ecosystem Restoration Council (GCERC)'),
	('Harry S. Truman Scholarship Foundation'),
	('Institute of Museum and Library Services'),
	('Inter-American Foundation'),
	('International Broadcasting Bureau'),
	('James Madison Memorial Fellowship Foundation'),
	('Legal Services Corporation'),
	('Marine Mammal Commission'),
	('Medicaid and CHIP Payment and Access Commission'),
	('Medical Payment Advisory Commission'),
	('Merit Systems Protection Board'),
	('Millennium Challenge Corporation'),
	('Morris K. Udall Foundation'),
	('National Aeronautics and Space Administration'),
	('National Archives and Records Administration'),
	('National Capital Planning Commission'),
	('National Council on Disability'),
	('National Credit Union Administration'),
	('National Endowment for the Arts'),
	('National Endowment for the Humanities'),
	('National Gallery of Art'),
	('National Indian Gaming Commission'),
	('National Labor Relations Board'),
	('National Mediation Board'),
	('National Nanotechnology Coordination Office'),
	('National Nuclear Security Administration'),
	('National Science Foundation'),
	('National Security Agency'),
	('National Transportation Safety Board'),
	('Networking Information Technology Research and Development (NITRD)'),
	('Nuclear Regulatory Commission'),
	('Occupational Safety & Health Review Commission'),
	('Office of Government Ethics'),
	('Office of Personnel Management'),
	('Overseas Private Investment Corporation'),
	('Pension Benefit Guaranty Corporation'),
	('Postal Rate Commission'),
	('Railroad Retirement Board'),
	('Securities and Exchange Commission'),
	('Selective Service System'),
	('Small Business Administration'),
	('Smithsonian Institution'),
	('Social Security Administration'),
	('Social Security Advisory Board'),
	('Special IG for Afghanistan Reconstruction'),
	('State Justice Institute (SJI)'),
	('Surface Transportation Board (STB)'),
	('Tennessee Valley Authority'),
	('Terrorist Screening Center'),
	('The Intelligence Community'),
	('The United States World War One Centennial Commission'),
	('U. S. Access Board'),
	('U. S. International Trade Commission'),
	('U. S. Office of Special Counsel'),
	('U. S. Peace Corps'),
	('U. S. Postal Service'),
	('U.S. Agency for International Development'),
	('U.S. Chemical Safety and Hazard Investigation Board'),
	('U.S. Commission of Fine Arts'),
	('U.S. Commission on Civil Rights'),
	('U.S. Postal Service, Office of Inspector General'),
	('U.S. Trade and Development Agency'),
	('United Stated Global Change Research Program'),
	('United States Office of Government Ethics'),
	('US Interagency Council on Homelessness'))");
}

/*
 * Get Branch Info from Agency name
 */
function getBranchInfo($agencyname){

  $branchname = db_query("select branch from custom_pulse_https_data where agency=:agencyname limit 1", array(':agencyname' => $agencyname))->fetchField();
  if($branchname == '')
    $branchname = 'NA';
  return $branchname;
}
