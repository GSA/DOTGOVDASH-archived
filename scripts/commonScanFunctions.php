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

//Remove ice.gov from scan as there is a firewall blocking it
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.status='1'", array(':bundle' => 'website'));
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id and b.status='1' and a.entity_id >'1071'", array(':bundle' => 'website'));
    #$query = db_query("select a.field_website_id_nid as entity_id,c.title,d.body_value from field_data_field_website_id a , field_data_field_site_inspector_raw_out b , node c , field_data_body d where a.entity_id=b.entity_id and a.bundle='domain_scan_information' and a.field_website_id_nid=c.nid and c.nid=d.entity_id and b.field_site_inspector_raw_out_value like '%site-inspector 3.1.1%'");
    //$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value not LIKE 'ice.gov' and b.title='gsa.gov' and b.nid=a.entity_id  and b.status='1'", array(':bundle' => 'website'));
    $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value not LIKE 'ice.gov' and b.nid=a.entity_id  and b.status='1'", array(':bundle' => 'website'));
//    $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id", array(':bundle' => 'website'));
//$query = db_query("select b.field_website_id_nid entity_id,d.body_value,c.title from field_data_field_site_inspector_raw_out a , field_data_field_website_id b , node c , field_data_body d where a.field_site_inspector_raw_out_value like '%Error:%' and a.entity_id=b.entity_id and b.field_website_id_nid = c.nid and c.nid = d.entity_id");

//Find all failed mobile scan sites and run mobile scan for them
#$query = db_query("select b.field_website_id_nid entity_id,d.body_value,c.title from field_data_field_mobile_perf_error_code a , field_data_field_website_id b , node c , field_data_body d where a.field_mobile_perf_error_code_value is not null and a.entity_id=b.entity_id and b.field_website_id_nid = c.nid and c.nid = d.entity_id UNION select b.field_website_id_nid entity_id,d.body_value,c.title from field_data_field_mobile_usab_error_code a , field_data_field_website_id b , node c , field_data_body d where a.field_mobile_usab_error_code_value is not null and a.entity_id=b.entity_id and b.field_website_id_nid = c.nid and c.nid = d.entity_id");
    //$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value LIKE '%cjis.gov%' and b.nid=a.entity_id", array(':bundle' => 'website'));
    //$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and a.body_value in ('afadvantage.gov','ama.gov','asc.gov','atf.gov','broadbandmap.gov','buildingamerica.gov','cfda.gov','cjis.gov','cncsoig.gov','earmarks.gov','exploretsp.gov','faca.gov','facadatabase.gov','fbo.gov','fercalt.gov','fha.gov','frtib.gov','fsgb.gov','g5.gov','geomac.gov','gop.gov','grants.gov','grantsolutions.gov','green.gov','gsaadvantage.gov','guideline.gov','guidelines.gov','highperformancebuildings.gov','housecommunications.gov','iarpa-ideas.gov','idealab.gov','invasivespeciesinfo.gov','irs.gov','irsauctions.gov','irssales.gov','itap.gov','itdashboard.gov','juvenilecouncil.gov','labor.gov','lcacommons.gov','malwareinvestigator.gov','max.gov','medicalcountermeasures.gov','nara.gov','nbm.gov','ncix.gov','nepa.gov','nfpors.gov','ngc.gov','nls.gov','nmcourt.gov','realestatesales.gov','republicans.gov','saferproduct.gov','saferproducts.gov','safetyact.gov','sam.gov','sen.gov','sss.gov','stb.gov','stopfraud.gov','thisfreelife.gov','tsc.gov','tsp.gov','usaid.gov','uspis.gov','wh.gov','worldwar1centennial.gov','businessdefense.gov','notalone.gov') and b.nid=a.entity_id", array(':bundle' => 'website'));


    #$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b where a.bundle=:bundle and b.nid=a.entity_id  and  b.status='1' and a.entity_id > '634'", array(':bundle' => 'website'));

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
    include("../scripts/configSettings.php");
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

    $httpdir = file_default_scheme().'://pulsehttps';
    $pulsedir = file_default_scheme().'://pulsedap';
    file_prepare_directory($httpdir, FILE_CREATE_DIRECTORY);
    file_prepare_directory($pulsedir, FILE_CREATE_DIRECTORY);
    $httpfiledata = file_get_contents('/tmp/pulsehttp.csv', true);
    $dapfiledata = file_get_contents('/tmp/pulsedap.csv', true);
    runUswdsScan();
    $uswdsfiledata = file_get_contents("/tmp/uswdsresults/results/uswds2.csv");
    $uswdsfile =  file_save_data($uswdsfiledata,file_default_scheme().'://uswdsscan/'.uswds_source.'_'.date("Y-m-d-h-i-s-a").'.csv', FILE_EXISTS_REPLACE);

    $httpsdatafile = file_save_data($httpfiledata,file_default_scheme().'://pulsehttps/'.pulse_http_source.'_'.date("Y-m-d-h-i-s-a").'.csv', FILE_EXISTS_REPLACE);
    $dapdatafile = file_save_data($dapfiledata,file_default_scheme().'://pulsedap/'.pulse_dap_source.'_'.date("Y-m-d-h-i-s-a").'.csv', FILE_EXISTS_REPLACE);

    //Get NIST Ipv6 data
    $ipv6dir = file_default_scheme().'://ipv6_nist_source';
    exec("timeout 15 wget --no-check-certificate -O /tmp/nist_ipv6.html https://usgv6-deploymon.antd.nist.gov/cgi-bin/generate-all.www");
    file_prepare_directory($ipv6dir, FILE_CREATE_DIRECTORY);
    $ipv6filedata = file_get_contents('/tmp/nist_ipv6.html', true);
    $ipv6datafile = file_save_data($ipv6filedata,file_default_scheme().'://ipv6_nist_source/'.nist_ipv6.'_'.date("Y-m-d-h-i-s-a").'.html', FILE_EXISTS_REPLACE);

    //Run Accessbility Scan through Pa11y
    writeToLogs("Collecting Accessbility Data through Pa11y using domain scan tool",$logFile);
    runAccessibilityNewCustomScan();
    $pa11yfiledata = file_get_contents("/tmp/results/a11y.csv");
    $pa11yfile =  file_save_data($pa11yfiledata,file_default_scheme().'://accessibilityscan/'.pa11y_source.'_'.date("Y-m-d-h-i-s-a").'.csv', FILE_EXISTS_REPLACE);

    $node->field_pulse_source_https_file['und'][0] = array('fid' => $httpsdatafile->fid,'display' => 1, 'description' => 'Pulse HTTPS scan source File');
    $node->field_pulse_source_analytics_fil['und'][0] = array('fid' => $dapdatafile->fid,'display' => 1, 'description' => 'Pulse DAP scan source File');
    $node->field_uswds_scan_file['und'][0] = array('fid' => $uswdsfile->fid,'display' => 1, 'description' => 'USWDS scan source File');
    $node->field_accessibility_scan_file['und'][0] = array('fid' => $pa11yfile->fid,'display' => 1, 'description' => 'Pa11y scan source File');
    $node->field_nist_ipv6_data['und'][0] = array('fid' => $ipv6datafile->fid,'display' => 1, 'description' => 'NIST Ipv6 scan source File');
    node_object_prepare($node);
    if($node=node_submit($node)){
        node_save($node);
        return $node->nid;
    }
}

/*
* Run USWDS Scan
*/
function runUswdsScan(){
    exec("../tools/domain-scan/scan /tmp/alldomains.csv --scan=uswds2 --workers=50 --output=/tmp/uswdsresults/");
    //exec("timeout 15 wget -O /tmp/uswdsresults/results/uswds2.csv \"https://api.gsa.gov/technology/site-scanner/v1/scans/uswds2/csv/?domaintype=Federal%20Agency%20-%20Executive&api_key=6i0A3HhMw1FAmhXokiEWrpjfWqGztEtaodHxGFfj\"");
}

/*
 * Run New Custom Accessibility Scan
 */
function runAccessibilityNewCustomScan(){
    //run pa11y Scan
    exec("timeout 15 ../tools/domain-scan/scan /tmp/alldomains.csv --scan=a11y --workers=50 --output=/tmp/");
    db_query("truncate table custom_accessibility_issues");
    db_query("set global local_infile=true");
    db_query("LOAD DATA LOCAL INFILE '/tmp/results/a11y.csv' INTO TABLE custom_accessibility_issues FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' (website,base_domain, domain_redirected_to,error_typecode,error_code,error_message,error_context,error_selector);");

    db_query("delete from custom_accessibility_issues where error_code not in ('WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.EmptyNoId','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.NoContent','aria-allowed-role','aria-hidden-focus','aria-input-field-name','aria-toggle-field-name','button-name','color-contrast','WCAG2AA.Principle1.Guideline1_4.1_4_3.G145','WCAG2AA.Principle1.Guideline1_4.1_4_3.G18','document-title','duplicate-id','WCAG2AA.Principle4.Guideline4_1.4_1_1.F77','empty-heading','WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.EmptyTitle','form-field-multiple-labels','frame-title','frame-title-unique','WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.HeadersRequired','WCAG2AA.Principle1.Guideline1_3.1_3_1.H42.2','html-has-lang','html-lang-valid','WCAG2AA.Principle2.Guideline2_4.2_4_1.H64.1','image-alt','WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.IncorrectAttr','input-button-name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputButton.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputCheckbox.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputFile.Name','input-image-alt','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputImage.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputPassword.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputRadio.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputText.Name','label','WCAG2AA.Principle1.Guideline1_3.1_3_1.F68','WCAG2AA.Principle1.Guideline1_3.1_3_1.H39.3.LayoutTable','link-name','list','listitem','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Li.Name','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Button.Name','WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeadersAttrs','WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeaderIds','WCAG2AA.Principle1.Guideline1_3.1_3_1.H43,H63','WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.NoTitleEl','role-img-alt','scope-attr-valid','scrollable-region-focusable','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Select.Name','td-headers-attr','WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Textarea.Name','WCAG2AA.Principle3.Guideline3_1.3_1_2.H58.1.Lang','valid-lan_g')");
  accessibility_new_updateTable();

}

function access_new_table_update($websites){
    $website = $websites['website'];
    $error_scan_type =$websites['runner'];
    $error_cat = $websites['category'];
    $wcag_code = $websites['wcag_ref'];
    $website_id = $websites['website_id'];
    if(trim($website_id) == "")
        $website_id = 'NULL';
    $code = $websites['code'];
    $agency_id = $websites['agency_id'];
    if(trim($agency_id) == "")
        $agency_id = 'NULL';
    $agency_name = $websites['agency_name'];
    print "update custom_accessibility_issues set error_scan_type = '$error_scan_type',wcag_code='$wcag_code',error_cat='$error_cat',agency_id= $agency_id,website_id=$website_id,agency_name = '$agency_name' where website='$website' and error_code = '$code' \n";
    echo "access_table_update() - ".$websites['website']."\n";
    db_query("update custom_accessibility_issues set error_scan_type = '$error_scan_type',wcag_code='$wcag_code',error_cat='$error_cat',agency_id= $agency_id,website_id=$website_id,agency_name = '$agency_name' where website='$website' and error_code = '$code'");

}

function findParentAgencyName($websiteid){
    $agencyname = db_query("select field_parent_agency_name_value from field_data_field_parent_agency_name where entity_id=:entity_id", array(':entity_id' => $websiteid))->fetchField();

    if (!empty($agencyname )) {
        return $agencyname;
    }
    else{
        return FALSE;
    }
}

function accessibility_new_updateWebsite($domain)
{
  $websites = array();
  $websites['website_id'] = findNode($domain, 'website');
  $websites['agency_id'] = findParentAgencyNode($websites['website_id']);
  $websites['agency_name'] = findParentAgencyName($websites['website_id']);
  $websites['website'] = $domain;
  $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($domain)))->fetchField();
  if($check_redirect != 'Yes') {
#read current-federal.csv and loop the below query over each table
    $accessibility_results = db_query("SELECT error_code,error_message,error_context,error_selector FROM custom_accessibility_issues where website = '$domain'");
    echo " accessibility_scan() - Website scan " . $websites['website'] . "\n";
    foreach ($accessibility_results as $result) {
      $websites['code'] = $result->error_code;
      $websites['message'] = $result->error_message;
      $websites['context'] = $result->error_context;
      $websites['selector'] = $result->error_selector;

      if ($websites['code'] == 'image-alt' || $websites['code'] == 'role-img-alt') {

        $websites['category'] = 'Images';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '1.1.1 Non-text Content';
      } elseif ($websites['code'] == 'aria-hidden-focus' || $websites['code'] == 'aria-input-field-name' || $websites['code'] == 'aria-toggle-field-name'
        || $websites['code'] == 'form-field-multiple-labels' || $websites['code'] == 'label') {

        $websites['category'] = 'Forms';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.F68' || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeadersAttrs'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputCheckbox.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputFile.Name'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputPassword.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputRadio.Name'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputText.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputText.Name'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Select.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Textarea.Name') {

        $websites['category'] = 'Forms';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H39.3.LayoutTable' || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43,H63'
        || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.HeadersRequired' || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.IncorrectAttr'
        || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeaderIds' || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeadersAttrs'
      ) {

        $websites['category'] = 'Tables';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'scope-attr-valid' || $websites['code'] == 'td-headers-attr') {

        $websites['category'] = 'Tables';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'empty-heading' || $websites['code'] == 'listitem') {

        $websites['category'] = 'Content Structure';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H42.2') {

        $websites['category'] = 'Content Structure';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '1.3.1 Info and Relationships';
      } elseif ($websites['code'] == 'color-contrast') {

        $websites['category'] = 'Contrast';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '1.4.3 Contrast (Minimum)';
      } elseif ($websites['code'] == 'WCAG2AA.Principle1.Guideline1_4.1_4_3.G145' || $websites['code'] == 'WCAG2AA.Principle1.Guideline1_4.1_4_3.G18') {

        $websites['category'] = 'Contrast';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '1.4.3 Contrast (Minimum)';
      } elseif ($websites['code'] == 'scrollable-region-focusable') {

        $websites['category'] = 'Keyboard Access';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '2.1.1 Keyboard';
      } elseif ($websites['code'] == 'WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.EmptyTitle' || $websites['code'] == 'WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.NoTitleEl') {

        $websites['category'] = 'Page Titles';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '2.4.2';
      } elseif ($websites['code'] == 'document-title') {

        $websites['category'] = 'Page Titles';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '2.4.2 Page Titled';
      } elseif ($websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.EmptyNoId' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.NoContent'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Button.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputButton.Name'
        || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputImage.Name' || $websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Li.Name'
      ) {

        $websites['category'] = 'Links and Buttons';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '2.4.4 Link Purpose (In Context)';
      } elseif ($websites['code'] == 'aria-allowed-role' || $websites['code'] == 'button-name'
        || $websites['code'] == 'input-button-name' || $websites['code'] == 'input-image-alt'
        || $websites['code'] == 'link-name' || $websites['code'] == 'list'
      ) {
        $websites['category'] = 'Links and Buttons';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '2.4.4 Link Purpose (In Context)';
      } elseif ($websites['code'] == 'html-has-lang' || $websites['code'] == 'html-lang-valid'
        || $websites['code'] == 'valid-lang') {
        $websites['category'] = 'Language';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '3.1.1 Language of Page';
      } elseif ($websites['code'] == 'WCAG2AA.Principle3.Guideline3_1.3_1_1.H57.3.Lang' || $websites['code'] == 'WCAG2AA.Principle3.Guideline3_1.3_1_2.H58.1.Lang'
      ) {
        $websites['category'] = 'Language';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '3.1.1 Language of Page';
      } elseif ($websites['code'] == 'duplicate-id') {
        $websites['category'] = 'Parsing';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '4.1.1 Parsing';
      } elseif ($websites['code'] == 'WCAG2AA.Principle4.Guideline4_1.4_1_1.F77') {
        $websites['category'] = 'Parsing';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '4.1.1 Parsing';
      } elseif ($websites['code'] == 'WCAG2AA.Principle2.Guideline2_4.2_4_1.H64.1') {
        $websites['category'] = 'Frames and iFrames';
        $websites['runner'] = 'htmlcs 2.5.1';
        $websites['wcag_ref'] = '4.1.2 Name, Role, Value';
      } elseif ($websites['code'] == 'frame-title-unique' || $websites['code'] == 'frame-title') {
        $websites['category'] = 'Frames and iFrames';
        $websites['runner'] = 'axe-core 3.5';
        $websites['wcag_ref'] = '4.1.2 Name, Role, Value';
      } else {

        $websites['category'] = '';
        $websites['runner'] = '';
        $websites['wcag_ref'] = '';
      }
      access_new_table_update($websites);
    }
  }
  else {
    db_query("delete from custom_accessibility_issues where website=:domain", array(':domain' => trim($domain)));
  }
}

function accessibility_new_updateTable()
{
    $first = false;
    if (($handle = fopen('/tmp/alldomains.csv', "r")) !== FALSE) {
        while (!feof($handle)) {
            $data = fgetcsv($handle);
            if (!$first) {
                $first = true;
                continue;
            }
            accessibility_new_updateWebsite($data[0]);
        }

        fclose($handle);

    }
}

function updateUswdsScanInfo($webscanId){
    $csv = readCSV("/tmp/uswdsresults/results/uswds2.csv");

    $i =1;
    $lineresult = "";
    foreach($csv as $csval) {
        $hostname = "$csval[0]";
        //Check if the site is a redirect. If redirect dont run scan.
        $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($hostname)))->fetchField();

        $scan_stat_code = "$csval[13]";
        $custom_score = "$csval[15]";
        $uswds_version = "$csval[20]";
        $uswds_detected = "$csval[18]";
        $usa_detected = "$csval[17]";
        $api_url = "$csval[5]";
        $api_update_date = "$csval[6]";
        $uswds_flag_detected = "$csval[8]";
        $uswds_flagincss_detected = "$csval[9]";
        $uswds_mwfont_detected = "$csval[10]";
        $uswds_psfont_detected = "$csval[11]";
        $uswds_ssfont_detected = "$csval[12]";
        $uswds_tables = "$csval[14]";
        $usa_classes_detected = "$csval[16]";
        $uswds_incss_detected = "$csval[19]";
        if($check_redirect != "Yes") {
            if ($custom_score != "0") {
                $uswds_status = "1";
                $uswds_score = "100";
            } else {
                $uswds_status = "0";
                $uswds_score = "0";
            }

        }
        else{
            $uswds_status = NULL;
            $uswds_score = NULL;
        }
        $lineresult = $api_url . " \n Domain,Base Domain,domain,status_code,usa_classes_detected,uswds_detected,usa_detected,flag_detected,flagincss_detected,sourcesansfont_detected,uswdsincss_detected,merriweatherfont_detected,publicsansfont_detected,uswdsversion,tables,total_score \n";
        $lineresult .= implode(",", $csval);
        $siteid = findNode($hostname, 'website');
        if (trim($siteid) != "") {
            //Load Parent website id
            $wnode = node_load($siteid);

            $tags = array();
            $start = microtime(true);
            $date = date("m-d-Y");
            $node = new stdClass();
            $node->type = "uswds_scan";
            $node->language = LANGUAGE_NONE;
            $node->uid = "1";
            $node->name = "admin";
            $node->status = 1;
            $node->title = "USWDS Scan " . $hostname;
            if (($nodeId = findNode($node->title, 'uswds_scan')) != FALSE) {
                echo "found node $node->title $nodeId";
                $node->nid = $nodeId;
            }
            $node->promote = 0;
            $node->body['und'][0]['value'] = $lineresult;
            $node->field_uswds_status['und'][0]['value'] = $uswds_status;
            $node->field_uswds_score['und'][0]['value'] = $uswds_score;
            $node->field_uswds_scan_web_status_code['und'][0]['value'] = $scan_stat_code;
            $node->field_uswds_usa_detected['und'][0]['value'] = $usa_detected;
            $node->field_uswds_detected['und'][0]['value'] = $uswds_detected;
            $node->field_uswds_version['und'][0]['value'] = $uswds_version;
            $node->field_uswds_api_url['und'][0]['value'] = $api_url;
            $node->field_uswds_api_scan_time['und'][0]['value'] = $api_update_date;
            $node->field_uswds_flag_detected['und'][0]['value'] = $uswds_flag_detected;
            $node->field_uswds_flagin_css_detected['und'][0]['value'] = $uswds_flagincss_detected;
            $node->field_uswds_marriweather_font_de['und'][0]['value'] = $uswds_mwfont_detected;
            $node->field_uswds_public_sans_font_det['und'][0]['value'] = $uswds_psfont_detected;
            $node->field_uswds_source_san_font_det['und'][0]['value'] = $uswds_ssfont_detected;
            $node->field_uswds_tables['und'][0]['value'] = $uswds_tables;
            $node->field_uswds_usa_classes_detected['und'][0]['value'] = $usa_classes_detected;
            $node->field_uswds_incss_detected['und'][0]['value'] = $uswds_incss_detected;
            $node->field_uswds_total_custom_score['und'][0]['value'] = $custom_score;

            $node->field_website_id['und'][0]['nid'] = $siteid;
            $node->field_web_agency_id['und'][0]['nid'] = $wnode->field_web_agency_id['und'][0]['nid'];
            $node->field_web_scan_id['und'][0]['nid'] = $webscanId;

            node_object_prepare($node);
            if ($node = node_submit($node)) {
                node_save($node);
            }
            if($uswds_score == "100") {
                $tags[] = "USWDS";
            }
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

            $wnode->field_uswds_score['und'][0]['value'] = $uswds_score;

            //Update Parent Website Node
            $wnode->field_uswds_scan_node['und'][0]['target_id'] = $node->nid;
            node_object_prepare($wnode);
            if ($wnode = node_submit($wnode)) {
                node_save($wnode);
            }

            print "$hostname -- $siteid , $scan_stat_code , $custom_score , $uswds_status , $uswds_score \n";

            $end = microtime(true);
            print "USWDS scan for " . $hostname . " took " . ($end - $start) . ' seconds';

        }
        else{
            print "Parent Domain $hostname is not tracked in DD currently \n";
        }
    }
}


/*
 * Run pageres command to generate website snapshots
 */

function getWebSnapshots($website,$storage){
    exec("timeout 15 pageres ". $website. " --format=jpg --filename=\"".$storage."<%= url %>\"");
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
    $command = "timeout 15 dig $domain +short @205.171.2.65";
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
    $command = "timeout 15 dig $basedomain +short @205.171.2.65";
    $outp = array();
    $comret = "";
    execCommand("$command",$outp,$comret);
    return $outp;
}

/*
 * Get Sites's final redirect destination
 */

function getSiteRedirectDest($domain){
    $redirectUrl = shell_exec("timeout 15 curl -w \"%{url_effective}\n\" -I -L -s -S -k http://".$domain." -o /dev/null");
    return $redirectUrl;
}

/*
 * Get SSL protocols and Ciphers Information
 *
 */

function getSSLInfo($domain){
    $sslinfo = array();
    $output = shell_exec("timeout 15 python3.6 -m sslyze --regular --http_headers $domain");
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
        $spout = shell_exec("timeout 15 ../tools/ssllabs-scan/ssllabs-scan -grade -usecache=true ".$website['domain']);
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
        if(isset($jsonMFarr['error']['errors'])){
            $mobileAPIdataArr['mobFriendlyErrorCode'] = $jsonMFarr['error']['code'];
            $mobileAPIdataArr['mobFriendlyErrorMessage'] = $jsonMFarr['error']['errors'][0]['message'];
        }

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
        if(isset($jsonMParr['error']['errors'])){
            $mobileAPIdataArr['mobPerformErrorCode'] = $jsonMParr['error']['code'];
            $mobileAPIdataArr['mobPerformErrorMessage'] = $jsonMParr['error']['errors'][0]['message'];
        }
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
 * Run Mobile API calls to Google and get the data using pagespped v5 api
 */

function getMobileApiDataPagespeedV5($domain){
    include("../scripts/configSettings.php");
    $mobileAPIdataArr = array();
    //Call to Google Mobile Friendly API
    //We are not using drupal system_retrieve_file because it failed url calls to google randomly
    //$googMobileFriendlyApi = "https://www.googleapis.com/pagespeedonline/v3beta1/mobileReady?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&url=http://".$domain."&strategy=mobile";
    //$googMobileFriendlyApiHttps = "https://www.googleapis.com/pagespeedonline/v3beta1/mobileReady?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&url=https://".$domain."&strategy=mobile";
    $http_domain = "http://".$domain;
    $https_domain = "https://".$domain;
    $googleApiKey = "AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4";
    $googMobileFriendlyApiData = mobileFriendlyApidataNewAPI($https_domain,$googleApiKey);
    //$mobileAPIdataArr['mobFriendlyFile'] = "sites/default/files/mobilefriendly_reports/" . $domain . ".json";
    //Get Json data and enter to a file
    //file_put_contents($mobileAPIdataArr['mobFriendlyFile'], $googMobileFriendlyApiData);
    $mobFriendlyFile = file_save_data($googMobileFriendlyApiData['returnstack'],file_default_scheme().'://mobilefriendly_reports/'.$domain.'.json', FILE_EXISTS_REPLACE);
    $mobileAPIdataArr['mobFriendlyFile'] = array('fid' => $mobFriendlyFile->fid,'display' => 1, 'description' => '');
//        $jsonMFarr = json_decode($googMobileFriendlyApiData, true);
//        if(isset($jsonMFarr['error']['errors'])){
    if(stripos($googMobileFriendlyApiData['returnstack'],"<title>Error") !== false){
        $mobileAPIdataArr['mobFriendlyErrorCode'] = '502';
        $mobileAPIdataArr['mobFriendlyErrorMessage'] = $googMobileFriendlyApiData['returnstack'];
    }

    $mobileAPIdataArr['mobFriendlyScore'] = $googMobileFriendlyApiData['score'];
    $mobileAPIdataArr['mobFriendlyResult'] =$googMobileFriendlyApiData['stat'];
//        $mobSnapshotData = str_replace('_', '/', $googMobileFriendlyApiData['image']);
//        $mobSnapshotData = str_replace('-', '+', $mobSnapshotData);
//        $mobSnapshotData = base64_decode($googMobileFriendlyApiData['image']);
    $mobileAPIdataArr['mobSnapshotData'] = base64_decode($googMobileFriendlyApiData['image']);

    $snapshotfile = file_save_data($mobileAPIdataArr['mobSnapshotData'],file_default_scheme().'://mobile_snapshots/'.$domain.'.png', FILE_EXISTS_REPLACE);
    $mobileAPIdataArr['mobSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
    //file_put_contents($mobileAPIdataArr['mobSnapshotFile'], $mobSnapshotData);

    //Call to Google Inights Speed API
    //$googMobilePerformApi = "https://www.googleapis.com/pagespeedonline/v2/runPagespeed?screenshot=true&key=AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4&strategy=mobile&url=".$domain."";
    //if(!$googMobilePerformApiData = file_get_contents("$googMobilePerformApi")) {
    if(!$googMobilePerformApiData = googleApiv5data("$http_domain","mobile","performance", "$googleApiKey")) {
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
        if(isset($jsonMParr['error']['errors'])){
            $mobileAPIdataArr['mobPerformErrorCode'] = $jsonMParr['error']['code'];
            $mobileAPIdataArr['mobPerformErrorMessage'] = $jsonMParr['error']['errors'][0]['message'];
        }
        if($mobileAPIdataArr['mobSnapshotData'] == ''){
            $mobSnapshotData = str_replace('_', '/', $jsonMParr['lighthouseResult']['audits']['final-screenshot']['details']['data']);
            $mobSnapshotData = str_replace('-', '+', $mobSnapshotData);
            $mobSnapshotData = base64_decode($mobSnapshotData);
            $mobileAPIdataArr['mobSnapshotData'] = $mobSnapshotData;
            //$snapshotfile = file_save_data($mobSnapshotData,file_default_scheme().'://mobile_snapshots/'.$domain.'.jpg', FILE_EXISTS_REPLACE);
            //$mobileAPIdataArr['mobSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
        }
        $mobperfscore =   round(($jsonMParr['lighthouseResult']['categories']['performance']['score'] * 100));

        $mobileAPIdataArr['mPScore'] = $mobperfscore;
//        if(($mobileAPIdataArr['mobFriendlyScore'] == '') || ($mobileAPIdataArr['mobFriendlyScore'] == '0'))
//            $mobileAPIdataArr['mobFriendlyScore'] = $jsonMParr['ruleGroups']['USABILITY']['score'];
        //$mobileAPIdataArr['mPStats'] = $jsonMParr['pageStats'];
        foreach($jsonMParr['lighthouseResult']['audits']['resource-summary']['details']['items'] as $jkey=>$jval){
            if($jval['resourceType'] == "total"){
                $mobileAPIdataArr['mPStats']['totalRequestBytes'] = $jval['size'];
                $mobileAPIdataArr['mPStats']['numberResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "image"){
                $mobileAPIdataArr['mPStats']['imageResponseBytes'] = $jval['size'];
                $mobileAPIdataArr['mPStats']['numberImageResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "script"){
                $mobileAPIdataArr['mPStats']['javascriptResponseBytes'] = $jval['size'];
                $mobileAPIdataArr['mPStats']['numberJsResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "stylesheet"){
                $mobileAPIdataArr['mPStats']['cssResponseBytes'] = $jval['size'];
                $mobileAPIdataArr['mPStats']['numberCssResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "document"){
                $mobileAPIdataArr['mPStats']['htmlResponseBytes'] = $jval['size'];
            }
            if($jval['resourceType'] == "other"){
                $mobileAPIdataArr['mPStats']['otherResponseBytes'] = $jval['size'];
            }
        }

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

function mobileFriendlyApidataNewAPI($data, $apiKey){
    $url="https://searchconsole.googleapis.com/v1/urlTestingTools/mobileFriendlyTest:run?key=".$apiKey;
    $mobret = array();
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    $payload = json_encode( array( "url"=> $data , "requestScreenshot"=> "true") );
    curl_setopt( $ch, CURLOPT_POSTFIELDS, $payload );
    curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
    curl_setopt( $ch, CURLOPT_HTTPHEADER, array('Content-Type:application/json'));
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $api_content = curl_exec ($ch);
    curl_close ($ch);

    $api_result = json_decode($api_content);

    if($api_content) {
        if (trim($api_result->mobileFriendliness) == "MOBILE_FRIENDLY") {
            $mobileFriendlyScore = "100";
            $mobileFriendlyPass = "1";
            $mobileImage = $api_result->screenshot->data;
        }
        elseif (trim($api_result->mobileFriendliness) == "NOT_MOBILE_FRIENDLY") {
            $mobileFriendlyScore = "0";
            $mobileFriendlyPass = "0";
            $mobileImage = $api_result->screenshot->data;
        }
        else {
            $mobileFriendlyScore = NULL;
            $mobileFriendlyPass = NULL;
            $mobileImage = "";
        }
        $mobret['stat'] = $mobileFriendlyPass;
        $mobret['score'] = $mobileFriendlyScore;
        $mobret['image'] = $mobileImage;
        $mobret['returnstack'] = $api_content;
        return $mobret;
    }else{
        $mobileFriendlyScore = NULL;
        $mobileFriendlyPass = NULL;
        $mobileImage = "";
        $mobret['stat'] = $mobileFriendlyPass;
        $mobret['score'] = $mobileFriendlyScore;
        $mobret['image'] = $mobileImage;
        $mobret['returnstack'] = $api_content;
        return $mobret;
    }
}

/*
 * Get Data from google page speed api
 * Category can be "accessibility" , "best-practices" , "performance" , "pwa" , "seo"
 */
function googleApiv5data($url,$type, $category, $apiKey)
{

    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_RETURNTRANSFER => 1,
        CURLOPT_URL => 'https://www.googleapis.com/pagespeedonline/v5/runPagespeed?key='.$apiKey.'&url='.$url.'&strategy='.$type.'&category='.$category,
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
    $dnsseccom = "timeout 15 dig +dnssec $domain @205.171.2.65|grep -i 'rrsig'";
    $outp = array();
    $comret = "";
    execCommand("$dnsseccom",$outp,$comret);
    $commandOutputforStore = implode("\n", $outp);
    //If the command output is null there is no RRSIG (DNNSEC cryptographic signature) info for the domain
    if(trim($commandOutputforStore) == '')
        $dnssecstat = '0';
    else
        $dnssecstat = '1';

    $dnssecret['status'] = $dnssecstat;
    $dnssecret['output'] = $commandOutputforStore;
    return $dnssecret;
}


/*
 * Get IPv6 status of a domain. This is a custom scanner differrent from NIST
 * we use nslookup
 */

function getCustomIpv6Status($domain){
    $ipv6com = "timeout 15 nslookup -q=aaaa $domain 205.171.2.65";
    $outp = array();
    $comret = "";
    execCommand("$ipv6com",$outp,$comret);
    $commandOutputforStore = implode("\n", $outp);
//Check if the command ouputs a valid ipv6 address
    if (strpos($commandOutputforStore, 'has AAAA address') !== false) {
        $ipv6stat = '1';
    }
    else{
        $ipv6stat = '0';
    }

    $ipv6address = shell_exec("timeout 15 dig AAAA +short $domain @205.171.2.65");
    $ipv6ret['status'] = $ipv6stat;
    execCommand("timeout 15 dig AAAA +short $domain @205.171.2.65",$ipv6outp,$ipcomret);
    $ipv6ret['address'] = $ipv6outp[0];
    $ipv6ret['output'] = $commandOutputforStore;
    return $ipv6ret;
}

//This function checks status of IPV6 domain in nist. This just checks for the domain is present in the list of ipv6 servers we download earlier from NIST at https://usgv6-deploymon.antd.nist.gov/cgi-bin/generate-all.www
function getIPv6StatfromNIST($domain){
    $newdom1 = explode('.',$domain);
    $newdom = 'gov.'.$newdom1[0].'.';
    $html = file_get_contents("/tmp/nist_ipv6.html");
    if( strpos($html,$newdom) !== false) {
        $ipv6stat = '1';
    }
    else{
        $ipv6stat = '0';
    }
    return $ipv6stat;
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
    $domainsourcefile = "/tmp/current-federal.csv";
    $pulsehttpsurl = "https://pulse.cio.gov/data/domains/https.csv";
    $pulsedapurl = "https://pulse.cio.gov/data/hosts/analytics.csv";
    //Get Pulse https data and enter to a temp table
//    file_put_contents("$localhttpsfile", file_get_contents("$pulsehttpsurl"));
    //Run script to generate http data
    //first download current-federal.csv from github
    writeToLogs("Get Latest Websites list and import to database",$logFile);
    shell_exec("timeout 15 wget https://raw.githubusercontent.com/GSA/data/master/dotgov-domains/current-federal.csv -O /tmp/current-federal.csv");
    //Process data in to custom_current_federal_websites db table
    db_query("set global local_infile=true");
    db_query("LOAD DATA LOCAL INFILE '".$domainsourcefile."' INTO TABLE `custom_current_federal_websites` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");
    db_query("update custom_current_federal_websites set security_contact=NULL where security_contact='(blank)';");
    writeToLogs("Run script to generate https file and import to db",$logFile);
    exec("cd ../scripts/custom_pulse_single_https/ && /usr/bin/python3.6 single_https.py --csvpath /tmp/current-federal.csv");
    shell_exec("/bin/cp -f ../scripts/custom_pulse_single_https/https_scan.csv /tmp/pulsehttp.csv");
    db_query("truncate table custom_pulse_https_data");
    db_query("LOAD DATA LOCAL INFILE '".$localhttpsfile."' INTO TABLE `custom_pulse_https_data` FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' ignore 1 lines");
    exec("drush sql-query \"select domain from custom_pulse_https_data group by domain\" > /tmp/alldomains.csv");
    //Get Pulse dap data and enter to a temp table
    //file_put_contents("$localdapfile", file_get_contents("$pulsedapurl"));
    //This is the latest scan which uses GSA analytics api instead of pulse and generates a file at /tmp/pulsedap.csv
    writeToLogs("Run script to generate dap file and import to db",$logFile);
    exec("/usr/bin/python3.6 ../scripts/custom_pulse_scanner_analytics/secondLevelDomain.py");

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
    $tags = array();
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
        $redirectstat = $result->redirect;
        $node->field_redirect['und'][0]['value'] = $result->redirect;
        if($redirectstat == 'Yes')
            $node->field_redirect_url['und'][0]['value'] = getSiteRedirectDest($website['domain']);
        $node->field_hsts_scan_time['und'][0]['value'] = (int)time();
        $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
        $node->field_website_id['und'][0]['nid'] = $siteid;
        $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);
        if($redirectstat != 'Yes') {
            if ($result->dap == 'Yes') {
                $dapstatus = 1;
                $dapscore = '100';
            } elseif ($result->dap == 'No') {
                $dapstatus = 0;
                $dapscore = '0';
            } else {
                $dapstatus = NULL;
                $dapscore = NULL;
            }
            $node->field_dap_status['und'][0]['value'] = $dapstatus;
            $node->field_dap_score['und'][0]['value'] = $dapscore;
        }
        else{
            $node->field_dap_status['und'][0]['value'] = NULL;
            $node->field_dap_score['und'][0]['value'] = NULL;
        }

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

        if($result->Compliant_mbod == 'Yes') {
            $tags[] = 'Compliant with M-15-13 and BOD 18-01';
            $m15_score = '100';
            $m15status = 1;
        }
        elseif($result->Compliant_mbod == 'No') {
            $m15_score = '0';
            $m15status = 0;
        }
        else{
            $m15_score = NULL;
            $m15status = NULL;
        }
        if($result->freeofunsecure == 'Yes') {
            $tags[] = 'Free of RC4/3DES and SSLv2/SSLv3';
            $rc4_score = '100';
            $rc4status = 1;
        }
        elseif($result->freeofunsecure == 'No') {
            $rc4_score = '0';
            $rc4status = 0;
        }
        else{
            $rc4_score = NULL;
            $rc4status = NULL;
        }

    }
    $node->field_https_score['und'][0]['value'] = round($https_score);
    $node->field_compl_m_15_13_bod['und'][0]['value'] = $m15status;
    $node->field_free_of_rc4_3des_and_sslv2['und'][0]['value'] = $rc4status;

    //Save parent website node
    $wnode = node_load($siteid);
    $wnode->field_https_score['und'][0]['value'] = round($https_score);
    $wnode->field_m15_13_compliance_score['und'][0]['value'] = $m15_score;
    $wnode->field_free_of_insecr_prot_score['und'][0]['value'] = $rc4_score;
    $wnode->field_redirect['und'][0]['value'] = $redirectstat;
    if($redirectstat == 'Yes'){
        $tags[] = 'REDIRECT';
        $wnode->field_dap_score['und'][0]['value'] = NULL;
    }else{
        $wnode->field_dap_score['und'][0]['value'] = $dapscore;
        if($result->dap == 'Yes')
            $tags[] = 'DAP';
    }


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

    }else{
        $wnode->field_website_tags['und'] = NULL;
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
    //$siInfo['dnssec'] = getDnssecStatus($website['domain']);
    $dnssecret = getDnssecStatus($website['domain']);
    $ipv6nistret = getIPv6StatfromNIST($website['domain']);
    $ipv6custret = getCustomIpv6Status($website['domain']);

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

    if(($ipv6nistret == '') || ($ipv6nistret == '0'))
        $node->field_ipv6_compliance['und'][0]['value'] = 0;
    else
        $node->field_ipv6_compliance['und'][0]['value'] = 1;

    if(($dnssecret['status'] == '') || ($dnssecret['status'] == '0'))
        $node->field_dnssec_compliance['und'][0]['value'] = 0;
    else
        $node->field_dnssec_compliance['und'][0]['value'] = 1;

    $node->field_dnssec_scan_output['und'][0]['value'] = $dnssecret['output'];


    if(($ipv6custret['status'] == '') || ($ipv6custret['status'] == '0'))
        $node->field_ipv6_custom_scan_status['und'][0]['value'] = 0;
    else
        $node->field_ipv6_custom_scan_status['und'][0]['value'] = 1;

    $node->field_ipv6_custom_scan_output['und'][0]['value'] = $ipv6custret['output'];
    $node->field_ipv6_address['und'][0]['value'] = $ipv6custret['address'];

    //Get SSL labs scan ouput
    //$ssllabsInfo = collectSslLabsDomInfo($website['domain']);
    //$node->field_ssl_labs_score['und'][0]['value'] = $ssllabsInfo['grade'];
    //$node->field_ssl_labs_raw_out['und'][0]['value'] = $ssllabsInfo['raw'];
    //$sslLabsFile = file_save_data($ssllabsInfo['reportcontent'],file_default_scheme().'://ssl_labs_reports/'.$website["domain"].'.json', FILE_EXISTS_REPLACE);
    //$sslLabsFileArr = array('fid' => $sslLabsFile->fid,'display' => 1, 'description' => '');
    //$node->field_ssl_labs_report['und'][0] = $sslLabsFileArr;

//Save parent website node
    $wnode = node_load($siteid);
    //Set all tags to null here
    $wnode->field_website_tags['und'] = NULL;

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
    if($ipv6nistret == '1') {
        $tags[] = 'IPV6';
        $wnode->field_ipv6_score['und'][0]['value'] = '100';
    }
    else
        $wnode->field_ipv6_score['und'][0]['value'] = '0';

    if($dnssecret['status'] == '1') {
        $tags[] = 'DNSSEC';
        $wnode->field_dnssec_score['und'][0]['value'] = '100';
    }
    else
        $wnode->field_dnssec_score['und'][0]['value'] = '0';
    print_r($sslInfo);
    if($sslInfo['opensslccs'] == '0')
        $sslScore += 10;
    //else
    //  $tags[] = 'VULNERABLE';
    if($sslInfo['opensslhb'] == '0')
        $sslScore += 10;
    // else
    //   $tags[] = 'VULNERABLE';
    if($sslInfo['downgrade'] == '0')
        $sslScore += 5;
    // else
    //   $tags[] = 'VULNERABLE';
    if($sslInfo['hpkp'] == '1')
        $sslScore += 5;
    //Assign node Value
    $node->field_ssl_score['und'][0]['value'] = round($sslScore);

    $wnode->field_ssl_score['und'][0]['value'] = round($sslScore);

    //Save Tags to parent website
    if(!empty($tags)) {
        //   if(!empty($wnode->field_website_tags)){
        //      foreach($wnode->field_website_tags['und'] as $ctk  =>$ctval){
        //         $currentTerms[] = $ctval['tid'];
        //    }
        //   $crnTermCnt = count($currentTerms);
        //  }
        $currentTerms = array();
        $crnTermCnt = 0;

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
    //print_r($mobInfo);
    $node->body['und'][0]['value'] = '';
    $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
    $node->field_website_id['und'][0]['nid'] = $siteid;
    $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteid);

    //Load Parent website id
    $wnode = node_load($siteid);

    //Check if the site is a redirect. If redirect dont run scan.
    $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($website['domain'])))->fetchField();
    if($check_redirect != "Yes") {
        $mobInfo = getMobileApiDataPagespeedV5($website['domain']);
//    if($mobInfo['mobFriendlyErrorCode'] != '') {
//        $field_mobile_usability_score = NULL;
//    }
//    else{
        $field_mobile_usability_score = $mobInfo['mobFriendlyScore'];
//    }

        $field_mobile_usability_result = ($mobInfo['mobFriendlyResult'] == 'true') ? 1 : 0;
        if ($mobInfo['mobPerformErrorCode'] != '') {
            $field_mobile_performance_score = NULL;
        } else {
            $field_mobile_performance_score = round($mobInfo['mPScore']);
        }
        if (($mobInfo['mobFriendlyErrorCode'] != '') && ($mobInfo['mobPerformErrorCode'] != '')) {
            $field_mobile_overall_score = NULL;
        } elseif (($mobInfo['mobFriendlyErrorCode'] != '') && ($mobInfo['mobPerformErrorCode'] == '')) {
            $field_mobile_overall_score = round($mobInfo['mPScore']);
        } elseif (($mobInfo['mobFriendlyErrorCode'] == '') && ($mobInfo['mobPerformErrorCode'] != '')) {
            $field_mobile_overall_score = round($mobInfo['mobFriendlyScore']);
        } else {
            $field_mobile_overall_score = round(($mobInfo['mobFriendlyScore'] + $mobInfo['mPScore']) / 2);
        }
        if ($field_mobile_performance_score == NULL)
            $field_mobile_perf_status = NULL;
        elseif (($field_mobile_performance_score >= "0") && ($field_mobile_performance_score < 50)) {
            $field_mobile_perf_status = "Poor";
        } elseif (($field_mobile_performance_score >= "50") && ($field_mobile_performance_score < 90)) {
            $field_mobile_perf_status = "Needs Improvement";
        } elseif (($field_mobile_performance_score >= "90") && ($field_mobile_performance_score < 100)) {
            $field_mobile_perf_status = "Good";
        }
        if ($field_mobile_usability_score == NULL)
            $field_mobile_usab_status = NULL;
        elseif ($field_mobile_usability_score == "0") {
            $field_mobile_usab_status = "Not Mobile Friendly";
        } elseif ($field_mobile_usability_score == "100") {
            $field_mobile_usab_status = "Mobile Friendly";
            //Add tag if the site is mobile friendly
            $tags[] = "MOBILE";
        }
        $node->field_mobile_usability_score['und'][0]['value'] = $field_mobile_usability_score;
        $node->field_mobile_performance_score['und'][0]['value'] = $field_mobile_performance_score;
        $node->field_mobile_overall_score['und'][0]['value'] = $field_mobile_overall_score;
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

        $node->field_mobile_perf_error_code['und'][0]['value'] = $mobInfo['mobPerformErrorCode'];
        $node->field_mobile_perf_error_message['und'][0]['value'] = $mobInfo['mobPerformErrorMessage'];
        $node->field_mobile_usab_error_code['und'][0]['value'] = $mobInfo['mobFriendlyErrorCode'];
        $node->field_mobile_usab_error_message['und'][0]['value'] = $mobInfo['mobFriendlyErrorMessage'];
        $node->field_mobile_performance_status['und'][0]['value'] = $field_mobile_perf_status;
        $node->field_mobile_usability_status['und'][0]['value'] = $field_mobile_usab_status;


//    if($mobInfo['mobFriendlyResult'] == 'true'){
//        $tags[] = "MOBILE";
//    }


        $wnode->field_mobile_usability_score['und'][0]['value'] = $field_mobile_usability_score;
        $wnode->field_mobile_performance_score['und'][0]['value'] = $field_mobile_performance_score;
        $wnode->field_mobile_overall_score['und'][0]['value'] = $field_mobile_overall_score;
        $wnode->field_mobile_performance_status['und'][0]['value'] = $field_mobile_perf_status;
        $wnode->field_mobile_usability_status['und'][0]['value'] = $field_mobile_usab_status;
        //Save Tags to parent website
        if (!empty($tags)) {
            if (!empty($wnode->field_website_tags)) {
                foreach ($wnode->field_website_tags['und'] as $ctk => $ctval) {
                    $currentTerms[] = $ctval['tid'];
                }
                $crnTermCnt = count($currentTerms);
            }
            $i = 1;
            foreach (array_unique($tags) as $key => $tag) {
                if ($term = taxonomy_get_term_by_name($tag)) {
                    $terms_array = array_keys($term);
                    //Check if the term already assigned to the node
                    if (!in_array($terms_array['0'], $currentTerms)) {
                        $wnode->field_website_tags['und'][$crnTermCnt + $i]['tid'] = $terms_array['0'];
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
    }
    else{
        //For redirected sites all are null
        $node->field_mobile_performance_status['und'][0]['value'] = NULL;
        $node->field_mobile_usability_status['und'][0]['value'] = NULL;
        $node->field_mobile_usability_score['und'][0]['value'] = NULL;
        $node->field_mobile_performance_score['und'][0]['value'] = NULL;
        $node->field_mobile_overall_score['und'][0]['value'] = NULL;

        $wnode->field_mobile_usability_score['und'][0]['value'] = NULL;
        $wnode->field_mobile_performance_score['und'][0]['value'] = NULL;
        $wnode->field_mobile_overall_score['und'][0]['value'] = NULL;
        $wnode->field_mobile_performance_status['und'][0]['value'] = NULL;
        $wnode->field_mobile_usability_status['und'][0]['value'] = NULL;
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

    //Load Parent website id
    $wnode = node_load($siteid);

    $node->promote = 0;
    //Check if the site is a redirect. If redirect dont run scan.
    $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($website['domain'])))->fetchField();
    if($check_redirect != "Yes") {
        $siteInfo = getSitePerformanceAPIdataV5($website['domain']);
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

        $wnode->field_site_speed_score['und'][0]['value'] = round($siteInfo['mPScore']);

    }
    else{
        //For rediect sites score is null
        $node->field_site_speed_score['und'][0]['value'] = NULL;

        $wnode->field_site_speed_score['und'][0]['value'] = NULL;

    }



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
 * Run Site performance API calls to Google and get the data from pagespped v5 api
 */

function getSitePerformanceAPIdataV5($domain){
    include("../scripts/configSettings.php");
    $siteSpeedAPIdataArr = array();
    //We are not using drupal system_retrieve_file because it failed url calls to google randomly
    $http_domain = "http://".$domain;
    $https_domain = "https://".$domain;
    $googleApiKey = "AIzaSyDXNreglPI5GTgZRi2Le71DZUGQe2o77h4";

    //Call to Google Inights Speed API
    if(!$googSitePerformApiData = googleApiv5data("$http_domain","desktop","performance", "$googleApiKey")) {
        $error = error_get_last();
        writeToLogs("API request failed to $http_domain . Error was: " . $error['message'],$logFile);
    }
    else{
        $sitePerformFile = file_save_data($googSitePerformApiData,file_default_scheme().'://sitespeed_reports/'.$domain.'.json', FILE_EXISTS_REPLACE);
        $siteSpeedAPIdataArr['sitePerformFile'] = array('fid' => $sitePerformFile->fid,'display' => 1, 'description' => '');

        $jsonMParr = json_decode($googSitePerformApiData, true);
        if($siteSpeedAPIdataArr['siteSnapshotData'] == ''){
            $siteSnapshotData = str_replace('_', '/', $jsonMParr['lighthouseResult']['audits']['final-screenshot']['details']['data']);
            $siteSnapshotData = str_replace('-', '+', $siteSnapshotData);
            $siteSnapshotData = base64_decode($siteSnapshotData);
            $siteSpeedAPIdataArr['siteSnapshotData'] = $siteSnapshotData;
            $snapshotfile = file_save_data($siteSnapshotData,file_default_scheme().'://desktop_snapshots/'.$domain.'.jpg', FILE_EXISTS_REPLACE);
            $siteSpeedAPIdataArr['siteSnapshotFile'] = array('fid' => $snapshotfile->fid,'display' => 1, 'description' => '');
        }
        $mobperfscore =   round(($jsonMParr['lighthouseResult']['categories']['performance']['score'] * 100));
        $siteSpeedAPIdataArr['mPScore'] = $mobperfscore;
        foreach($jsonMParr['lighthouseResult']['audits']['resource-summary']['details']['items'] as $jkey=>$jval){
            if($jval['resourceType'] == "total"){
                $siteSpeedAPIdataArr['mPStats']['totalRequestBytes'] = $jval['size'];
                $siteSpeedAPIdataArr['mPStats']['numberResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "image"){
                $siteSpeedAPIdataArr['mPStats']['imageResponseBytes'] = $jval['size'];
                $siteSpeedAPIdataArr['mPStats']['numberImageResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "script"){
                $siteSpeedAPIdataArr['mPStats']['javascriptResponseBytes'] = $jval['size'];
                $siteSpeedAPIdataArr['mPStats']['numberJsResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "stylesheet"){
                $siteSpeedAPIdataArr['mPStats']['cssResponseBytes'] = $jval['size'];
                $siteSpeedAPIdataArr['mPStats']['numberCssResources'] = $jval['requestCount'];
            }
            if($jval['resourceType'] == "document"){
                $siteSpeedAPIdataArr['mPStats']['htmlResponseBytes'] = $jval['size'];
            }
            if($jval['resourceType'] == "other"){
                $siteSpeedAPIdataArr['mPStats']['otherResponseBytes'] = $jval['size'];
            }
        }


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
            $websitepoc = db_query("select security_contact from custom_current_federal_websites where domain=:domain limit 1", array(':domain' => strtoupper(trim($csval[0]))))->fetchField();
            if((trim($websitepoc) != "") || ($websitepoc != NULL)){
                $websitepocstat = "1";
            }
            else{
                $websitepocstat = "0";
            }
            $node->field_website_security_poc[$node->language][0]['value'] = $websitepoc;
            $node->field_website_security_poc_statu[$node->language][0]['value'] = $websitepocstat;

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
    unset($line_of_text[0]);
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
    $comout = shell_exec("timeout 15 dig +trace $website @205.171.2.65");
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

    //Check if the site is a redirect. If redirect dont run scan.
    $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($website)))->fetchField();
    if($check_redirect != "Yes") {
        //Associate field names with categories of technology
        $varCatassoc = array("cms" => "field_cms_applications",
            "widgets" => "field_widget_applications",
            "analytics" => "field_analytics_applications",
            "font scripts" => "field_font_script_applications",
            "web servers" => "field_web_server",
            "cache tools" => "field_cache_tools",
            "javascript libraries" => "field_javascript_frameworks",
            "javascript frameworks" => "field_javascript_frameworks",
            "programming languages" => "field_programming_languages",
            "advertising networks" => "field_advertising_networks",
            "blogs" => "field_blog_applications",
            "build ci systems" => "field_build_ci_systems",
            "captchas" => "field_captcha_applications",
            "cdn" => "field_cdn_applications",
            "comment systems" => "field_comment_systems_applicatio",
            "control systems" => "field_control_systems_applicatio",
            "crm" => "field_crm_applications",
            "database managers" => "field_database_managers",
            "databases" => "field_databases",
            "dev tools" => "field_dev_tools",
            "document management systems" => "field_document_management_system",
            "documentation tools" => "field_documentation_tools",
            "ecommerce" => "field_ecommerce_applications",
            "editors" => "field_editor_applications",
            "feed readers" => "field_feed_readers",
            "hosting panels" => "field_hosting_panels",
            "issue trackers" => "field_issue_trackers",
            "javascript graphics" => "field_javascript_graphics_applic",
            "landing page builders" => "field_landing_page_builders",
            "live chat" => "field_live_chat_applications",
            "lms" => "field_lms_applications",
            "maps" => "field_maps_applications",
            "marketing automation" => "field_marketing_automation",
            "media servers" => "field_media_servers",
            "message boards" => "field_message_boards",
            "miscellaneous" => "field_miscellaneous_application",
            "mobile frameworks" => "field_mobile_frameworks",
            "network devices" => "field_network_devices",
            "network storage" => "field_network_storage",
            "operating systems" => "field_operating_systems",
            "payment processors" => "field_payment_processors",
            "photo galleries" => "field_photo_galleries",
            "remote access" => "field_remote_access",
            "rich text editors" => "field_rich_text_editors",
            "search engines" => "field_search_engines",
            "tag managers" => "field_tag_managers",
            "video players" => "field_video_players",
            "web frameworks" => "field_web_frameworks",
            "web mail" => "field_web_mail_applications",
            "web server extensions" => "field_web_server_extensions",
            "wikis" => "field_wiki_applications");
        $weburl = "http://" . $website;
        //$command = "node index.js $weburl";
        //$tsout = shell_exec("export npm_config_loglevel=silent;cd ../tools/wappalyzer/;$command");
        $command = "timeout 15 node /usr/lib/node_modules/wappalyzer/index.js $weburl";
        shell_exec("export npm_config_loglevel=silent");
        $tsout = shell_exec("export npm_config_loglevel=silent;$command");
        if (strpos($tsout, 'JQMIGRATE:') !== false) {
            $tsout1 = explode(" version 1.4.1", $tsout);
            $tsout = $tsout1[1];
        }
        $tsout = "[$tsout]";
        $tsout2 = strstr($tsout, '[{"');
        $tsout2 = str_replace('\'', '\\\'', $tsout2);
        $tsout2 = str_replace("\\n", "", $tsout2);

        $tsobj = json_decode($tsout2);



        $tags = array();
        $k = 1;
        foreach ($tsobj[0]->technologies as $tskey => $tsobj) {
            //foreach($tsobj as $tskey=>$tsobj){
            $tsAppname = $tsobj->name;
            //$tsAppCat = $tsobj->categories[0];
            $tsAppCat1 = (Array)$tsobj->categories[0];
//            $tsAppCat = array_values($tsAppCat1)[0];
            $tsAppCat = $tsAppCat1['name'];
            print_r($tsobj);
            print "--- \n";


            //$tags[$tsAppCat] = array();
            //if version is present append version to technology

            if (trim($tsobj->version) != '') {
                $tsAppname .= "_" . $tsobj->version;
                //if (!in_array($tsAppname, $tags[$tsAppCat]))
                $tags[strtolower($tsAppCat)][] = $tsAppname;
            }

            $tags[strtolower($tsAppCat)][] = $tsobj->name;
        }
        //print_r($tags);
        $curNodeid = findNode($website, 'website');
        $webnode = node_load($curNodeid);
        $webnode->field_technology_scan_raw['und'][0]['value'] = $tsout2;
        $cdnproviders = findCDNProvider("$website");
        foreach ($varCatassoc as $vkey => $vval) {
            $webnode->{$vval} = array();
            //print "$vkey -- $vval \n";
        }
        if (!empty($cdnproviders)) {
            $tags['cdn'] = array_values($cdnproviders);
        }
        print_r($tags);
        foreach ($tags as $key => $tagarr) {
            $i = 0;
            foreach ($tagarr as $tkey => $tag) {
                if (array_key_exists($key, $varCatassoc)) {
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
        //Assign Search Scan Results here to the domain
        $query = db_query("select * from search_scan where domain=:domain", array(':domain' => $website));
        foreach ($query as $result) {
            if ($result->search_available == 'yes')
                $search_available = 1;
            elseif ($result->search_available == 'no')
                $search_available = 0;
            $webnode->field_search_engine_name['und'][0]['value'] = $result->type;
            $webnode->field_search_status['und'][0]['value'] = $search_available;
        }
        //print_r($webnode->field_analytics_applications);
        node_object_prepare($webnode);
        if ($webnode = node_submit($webnode)) {
            node_save($webnode);
        }
    }
    else{
        $curNodeid = findNode($website, 'website');
        $webnode = node_load($curNodeid);
        $webnode->field_search_engine_name['und'][0]['value'] = NULL;
        $webnode->field_search_status['und'][0]['value'] = NULL;
        node_object_prepare($webnode);
        if ($webnode = node_submit($webnode)) {
            node_save($webnode);
        }
    }
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
    db_query("update custom_pulse_https_data set branch='legislative' where agency in 	('Architect of the Capitol','Congressional Office of Compliance','Government Publishing Office','Library of Congress','Stennis Center for Public Service','The Legislative Branch (Congress)','U.S. Capitol Police')");
    //Update Judicial Branch Sites
    db_query("update custom_pulse_https_data set branch='judicial' where  agency in ('The Supreme Court','U.S Courts')");
    //Update Executive Bracnh Sites
    db_query("update custom_pulse_https_data set branch='executive' where agency not in ('Architect of the Capitol','Congressional Office of Compliance','Government Publishing Office','Library of Congress','Stennis Center for Public Service','The Legislative Branch (Congress)','U.S. Capitol Police','The Supreme Court','U.S Courts')");

    /*
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
    */
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



/*
 * Create Government Wide Snapshot for Archival and trend analysis purpose
 */
function archiveGovwideTrendData(){
    //Find Number of published websites
    $curdate = date("Y-m-d");
    $websitenos = db_query("select count(*) from node where type='website' and status ='1'")->fetchField();
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

    //Query to get Agency Accessibility errors
    $ag_avrg_color_cont =  round(db_query("select sum(c.field_accessible_group_colorcont_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_colorcont c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id", array())->fetchField());

    $ag_avrg_miss_image =  round(db_query("select sum(c.field_accessible_group_missingim_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_missingim c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id", array())->fetchField());

    $ag_avrg_html_attr =  round(db_query("select sum(c.field_accessible_group_htmlattri_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_htmlattri c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id ", array())->fetchField());
    $agencynos = db_query("select count(*) from node a, field_data_field_agency_branch b where a.type='agency' and a.status ='1' and a.nid=b.entity_id and  b.field_agency_branch_value='executive'")->fetchField();

    //Queries for new Mobile Data
    $mobnew_poor_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b where  a.entity_id=b.nid  and b.type='website' and b.status=1 and a.field_mobile_performance_status_value='Poor'")->fetchField();
    $mobnew_improve_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b where  a.entity_id=b.nid  and b.type='website' and b.status=1 and a.field_mobile_performance_status_value='Needs Improvement'")->fetchField();
    $mobnew_good_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b where  a.entity_id=b.nid  and b.type='website' and b.status=1 and a.field_mobile_performance_status_value='Good'")->fetchField();
    $mobnew_friendly_sites =  db_query("select count(a.field_mobile_usability_status_value) from field_data_field_mobile_usability_status a, node b where  a.entity_id=b.nid  and b.type='website' and b.status=1 and a.field_mobile_usability_status_value='Mobile Friendly'")->fetchField();
    $mobnew_unfriendly_sites =  db_query("select count(a.field_mobile_usability_status_value) from field_data_field_mobile_usability_status a, node b where  a.entity_id=b.nid  and b.type='website' and b.status=1 and a.field_mobile_usability_status_value='Not Mobile Friendly'")->fetchField();

    $dap_websites = db_query("select count(a.title) as complnum from node a, field_data_field_dap_score b where a.nid=b.entity_id and a.status='1' and a.type='website' and b.field_dap_score_value='100'")->fetchField();

    $redirect_websites = db_query("select count(a.title) as complnum from node a, field_data_field_redirect b where a.nid=b.entity_id and a.status='1' and a.type='website' and b.field_redirect_value='Yes'")->fetchField();

    $poc_websites = db_query("select count(a.field_website_security_poc_statu_value) as avg_value from field_data_field_website_security_poc_statu a , node b where a.entity_id=b.nid and b.type='website' and b.status='1' and a.field_website_security_poc_statu_value='1'")->fetchField();

    $https_websites = db_query("select count(field_https_status_value) as complnum from node a , field_data_field_https_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and a.type='https_dap_scan_information'  and field_https_status_value ='Yes' group by field_https_status_value")->fetchField();

    $uswds_websites = db_query("select count(field_uswds_score_value) as complnum from field_data_field_uswds_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and field_uswds_score_value='100' group by field_uswds_score_value")->fetchField();

    //Query to get Search data for govtwide
    $searchresults = db_query("select field_search_status_value,count(field_search_status_value) as complnum from node a , field_data_field_search_status b  where a.status='1' and a.nid=b.entity_id  and a.type='website' group by field_search_status_value");
    $agency_search_status = array();
    $search_available = "";
    $search_notavailable = "";
    foreach ($searchresults as $searchresult) {
        if($searchresult->field_search_status_value == '1')
            $search_available += $searchresult->complnum;
        if($searchresult->field_search_status_value == '0')
            $search_notavailable += $searchresult->complnum;
    }
    print  " $websitenos - $agencynos - $avg_https -- $avg_dap -- $avg_mob_overall -- $avg_mob_perform -- $avg_mob_usab - $avg_sitespeed - $avg_ipv6 - $avg_dnssec -  $avg_rc4 - $avg_m15 - $ag_avrg_color_cont - $ag_avrg_miss_image - $ag_avrg_html_attr - $search_available - $search_notavailable - $avg_uswds ,$mobnew_poor_sites,$mobnew_improve_sites,$mobnew_good_sites,$mobnew_friendly_sites,$mobnew_unfriendly_sites,$dap_websites,$https_websites,$uswds_websites , $redirect_websites, $poc_websites\n";
    print "insert into custom_government_wide_archive values(NULL,CURDATE(),NOW(),'$websitenos','$avg_https','$avg_dap','$avg_mob_overall','$avg_mob_usab','$avg_mob_perform','$avg_sitespeed','$avg_ipv6','$avg_dnssec','$avg_rc4','$avg_m15','$ag_avrg_color_cont','$ag_avrg_html_attr','$ag_avrg_miss_image','$search_available','$search_notavailable','$agencynos','$avg_uswds','$mobnew_good_sites','$mobnew_improve_sites','$mobnew_poor_sites','$mobnew_friendly_sites','$mobnew_unfriendly_sites','$dap_websites','$https_websites','$uswds_websites') ON DUPLICATE KEY UPDATE    
num_of_websites='$websitenos',average_https_score='$avg_https',average_dap_score='$avg_dap',average_mob_overall_score='$avg_mob_overall',average_mob_usab_score='$avg_mob_usab',average_mob_perfrml_score='$avg_mob_perform',average_sitespeed_score='$avg_sitespeed',average_ipv6_score='$avg_ipv6',average_dnssec_score='$avg_dnssec',average_rc4_score='$avg_rc4',average_m15_score='$avg_m15',tot_color_contrast='$ag_avrg_color_cont',tot_html_attrib='$ag_avrg_html_attr',tot_missing_image='$ag_avrg_miss_image',num_of_agencies='$agencynos',search_available='$search_available',search_notavailable='$search_notavailable',average_uswds_score='$avg_uswds', mob_perf_good='$mobnew_good_sites',mob_perf_improve='$mobnew_improve_sites',mob_perf_poor='$mobnew_poor_sites',mob_usab_friendly='$mobnew_friendly_sites',mob_usab_nonfriendly='$mobnew_unfriendly_sites',dap_websites='$dap_websites',https_websites='$https_websites',uswds_websites='$uswds_websites',poc_websites='$poc_websites',redirect_websites='$redirect_websites' \n";
//Update/Insert Archive record for current data sets
    db_query("insert into custom_government_wide_archive values(NULL,CURDATE(),NOW(),'$websitenos','$avg_https','$avg_dap','$avg_mob_overall','$avg_mob_usab','$avg_mob_perform','$avg_sitespeed','$avg_ipv6','$avg_dnssec','$avg_rc4','$avg_m15','$ag_avrg_color_cont','$ag_avrg_html_attr','$ag_avrg_miss_image','$search_available','$search_notavailable','$agencynos','$avg_uswds','$mobnew_good_sites','$mobnew_improve_sites','$mobnew_poor_sites','$mobnew_friendly_sites','$mobnew_unfriendly_sites','$dap_websites','$https_websites','$uswds_websites','$poc_websites','$redirect_websites') ON DUPLICATE KEY UPDATE    
num_of_websites='$websitenos',average_https_score='$avg_https',average_dap_score='$avg_dap',average_mob_overall_score='$avg_mob_overall',average_mob_usab_score='$avg_mob_usab',average_mob_perfrml_score='$avg_mob_perform',average_sitespeed_score='$avg_sitespeed',average_ipv6_score='$avg_ipv6',average_dnssec_score='$avg_dnssec',average_rc4_score='$avg_rc4',average_m15_score='$avg_m15',tot_color_contrast='$ag_avrg_color_cont',tot_html_attrib='$ag_avrg_html_attr',tot_missing_image='$ag_avrg_miss_image',num_of_agencies='$agencynos',search_available='$search_available',search_notavailable='$search_notavailable',average_uswds_score='$avg_uswds', mob_perf_good='$mobnew_good_sites',mob_perf_improve='$mobnew_improve_sites',mob_perf_poor='$mobnew_poor_sites',mob_usab_friendly='$mobnew_friendly_sites',mob_usab_nonfriendly='$mobnew_unfriendly_sites',dap_websites='$dap_websites',https_websites='$https_websites',uswds_websites='$uswds_websites',poc_websites='$poc_websites',redirect_websites='$redirect_websites'");

}

function archiveAgencywideTrendData(){
    $query = db_query("select nid,title from node where type=:bundle", array(':bundle' => 'agency'));
    $curdate = date("Y-m-d");
    foreach ($query as $result) {
        $websitenos = db_query("select count(*) from node a , field_data_field_web_agency_id b   where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField();
        $avg_https = round(db_query("select avg(c.field_https_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_https_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_dap = round(db_query("select avg(c.field_dap_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_dap_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_mob_overall = round(db_query("select avg(c.field_mobile_overall_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_overall_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_mob_perform = round(db_query("select avg(c.field_mobile_performance_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_performance_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_mob_usab = round(db_query("select avg(c.field_mobile_usability_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_usability_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_sitespeed = round(db_query("select avg(c.field_site_speed_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_site_speed_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_ipv6 = round(db_query("select avg(c.field_ipv6_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_ipv6_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_dnssec = round(db_query("select avg(c.field_dnssec_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_dnssec_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_rc4 = round(db_query("select avg(c.field_free_of_insecr_prot_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_free_of_insecr_prot_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $avg_m15 = round(db_query("select avg(c.field_m15_13_compliance_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_m15_13_compliance_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField());
        $ag_avrg_color_cont =  round(db_query("select sum(c.field_accessible_group_colorcont_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_colorcont c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $ag_avrg_miss_image =  round(db_query("select sum(c.field_accessible_group_missingim_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_missingim c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $ag_avrg_html_attr =  round(db_query("select sum(c.field_accessible_group_htmlattri_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_accessible_group_htmlattri c  where a.type='508_scan_information' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $ag_avrg_uswds_score =  round(db_query("select avg(c.field_uswds_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_uswds_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());

        //Queries for new Mobile Data
        $mobnew_poor_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b, field_data_field_web_agency_id c  where   b.nid=a.entity_id and c.entity_id=a.entity_id   and b.type='website' and b.status=1 and  b.type=c.bundle and a.field_mobile_performance_status_value='Poor' and c.field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField();
        $mobnew_improve_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b, field_data_field_web_agency_id c  where   b.nid=a.entity_id and c.entity_id=a.entity_id   and b.type='website' and b.status=1 and  b.type=c.bundle and a.field_mobile_performance_status_value='Needs Improvement' and c.field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField();
        $mobnew_good_sites =  db_query("select count(a.field_mobile_performance_status_value) from field_data_field_mobile_performance_status a, node b, field_data_field_web_agency_id c  where   b.nid=a.entity_id and c.entity_id=a.entity_id   and b.type='website' and b.status=1 and  b.type=c.bundle and a.field_mobile_performance_status_value='Good' and c.field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField();
        $mobnew_friendly_sites =  db_query("select count(field_mobile_usability_status_value) from field_data_field_mobile_usability_status a, node b, field_data_field_web_agency_id c  where   b.nid=a.entity_id and c.entity_id=a.entity_id   and b.type='website' and b.status=1 and  b.type=c.bundle and field_mobile_usability_status_value='Mobile Friendly'  and c.field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField();
        $mobnew_unfriendly_sites =  db_query("select count(field_mobile_usability_status_value) from field_data_field_mobile_usability_status a, node b, field_data_field_web_agency_id c  where   b.nid=a.entity_id and c.entity_id=a.entity_id   and b.type='website' and b.status=1 and  b.type=c.bundle and field_mobile_usability_status_value='Not Mobile Friendly' and c.field_web_agency_id_nid=:agencyid", array(':agencyid' =>  $result->nid))->fetchField();

        $dap_websites = db_query("select count(field_dap_score_value)  as complnum from field_data_field_dap_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid and field_dap_score_value='100' group by field_dap_score_value", array(':agencyid' =>  $result->nid))->fetchField();
        $https_websites = db_query("select count(field_https_status_value)  as complnum from node a , field_data_field_https_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='https_dap_scan_information'  and field_https_status_value='Yes' group by field_https_status_value", array(':agencyid' =>  $result->nid))->fetchField();
        $uswds_websites = db_query("select count(field_uswds_score_value)  as complnum from field_data_field_uswds_score a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid and field_uswds_score_value='100' group by field_uswds_score_value", array(':agencyid' =>  $result->nid))->fetchField();

        $redirect_websites = db_query("select count(a.field_redirect_value)  as complnum from field_data_field_redirect a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid and a.field_redirect_value='Yes' group by a.field_redirect_value", array(':agencyid' =>  $result->nid))->fetchField();

        $poc_websites = db_query("select count(a.field_website_security_poc_statu_value)  as complnum from field_data_field_website_security_poc_statu a , node b, field_data_field_web_agency_id c where a.entity_id=b.nid and a.entity_id=c.entity_id  and c.bundle='website' and b.status='1' and c.field_web_agency_id_nid=:agencyid and a.field_website_security_poc_statu_value='1' group by a.field_website_security_poc_statu_value", array(':agencyid' =>  $result->nid))->fetchField();

        $uswds_websites = ($uswds_websites == '')?'NULL':$uswds_websites;
        $dap_websites = ($dap_websites == '')?'NULL':$dap_websites;
        $https_websites = ($https_websites == '')?'NULL':$https_websites;
        $redirect_websites = ($redirect_websites == '')?'NULL':$redirect_websites;
        $poc_websites = ($poc_websites == '')?'NULL':$poc_websites;


        //Query to get Search data for an agency
        $searchresults = db_query("select field_search_status_value,count(field_search_status_value) as complnum from node a , field_data_field_search_status b , field_data_field_web_agency_id c where a.status='1' and a.nid=b.entity_id and a.nid=c.entity_id and b.entity_id=c.entity_id and c.field_web_agency_id_nid=:agencyid and a.type='website' group by field_search_status_value", array(':agencyid' => $result->nid));
        $agency_search_status = array();
        $search_available = 0;
        $search_notavailable = 0;
        foreach ($searchresults as $searchresult) {
            if($searchresult->field_search_status_value == '1')
                $search_available += $searchresult->complnum;
            if($searchresult->field_search_status_value == '0')
                $search_notavailable += $searchresult->complnum;
        }

        //  print  $result->nid."-- $result->title -- $websitenos - $avg_https\n";
        print  "$result->nid -- $result->title -- $websitenos - $avg_https -- $avg_dap -- $avg_mob_overall -- $avg_mob_perform -- $avg_mob_usab - $avg_sitespeed - $avg_ipv6 - $avg_dnssec -  $avg_rc4 - $avg_m15 - $ag_avrg_color_cont - $ag_avrg_miss_image - $ag_avrg_html_attr - $search_available - $search_notavailable - $ag_avrg_uswds_score,$mobnew_poor_sites,$mobnew_improve_sites,$mobnew_good_sites,$mobnew_friendly_sites,$mobnew_unfriendly_sites ,$dap_websites,$https_websites,$uswds_websites \n";
        if($websitenos != '0'){
            print "insert into custom_agencywide_archive values(NULL,CURDATE(),NOW(),'$result->title','$result->nid','$websitenos','$avg_https','$avg_dap','$avg_mob_overall','$avg_mob_usab','$avg_mob_perform','$avg_sitespeed','$avg_ipv6','$avg_dnssec','$avg_rc4','$avg_m15','$ag_avrg_color_cont','$ag_avrg_html_attr','$ag_avrg_miss_image','$search_available','$search_notavailable','$ag_avrg_uswds_score','$mobnew_good_sites','$mobnew_improve_sites','$mobnew_poor_sites','$mobnew_friendly_sites','$mobnew_unfriendly_sites','$dap_websites','$https_websites','$uswds_websites') ON DUPLICATE KEY UPDATE     num_of_websites='$websitenos',average_https_score='$avg_https',average_dap_score='$avg_dap',average_mob_overall_score='$avg_mob_overall',average_mob_usab_score='$avg_mob_usab',average_mob_perfrml_score='$avg_mob_perform',average_sitespeed_score='$avg_sitespeed',average_ipv6_score='$avg_ipv6',average_dnssec_score='$avg_dnssec',average_rc4_score='$avg_rc4',average_m15_score='$avg_m15',tot_color_contrast='$ag_avrg_color_cont',tot_html_attrib='$ag_avrg_html_attr',tot_missing_image='$ag_avrg_miss_image',search_available='$search_available',search_notavailable='$search_notavailable', average_uswds_score='$ag_avrg_uswds_score', mob_perf_good='$mobnew_good_sites',mob_perf_improve='$mobnew_improve_sites',mob_perf_poor='$mobnew_poor_sites',mob_usab_friendly='$mobnew_friendly_sites',mob_usab_nonfriendly='$mobnew_unfriendly_sites',dap_websites='$dap_websites',https_websites='$https_websites',uswds_websites='$uswds_websites',poc_websites=$poc_websites,redirect_websites=$redirect_websites \n";
            db_query("insert into custom_agencywide_archive values(NULL,CURDATE(),NOW(),'$result->title','$result->nid','$websitenos','$avg_https','$avg_dap','$avg_mob_overall','$avg_mob_usab','$avg_mob_perform','$avg_sitespeed','$avg_ipv6','$avg_dnssec','$avg_rc4','$avg_m15','$ag_avrg_color_cont','$ag_avrg_html_attr','$ag_avrg_miss_image','$search_available','$search_notavailable','$ag_avrg_uswds_score','$mobnew_good_sites','$mobnew_improve_sites','$mobnew_poor_sites','$mobnew_friendly_sites','$mobnew_unfriendly_sites',$dap_websites,$https_websites,$uswds_websites,$poc_websites,$redirect_websites) ON DUPLICATE KEY UPDATE     num_of_websites='$websitenos',average_https_score='$avg_https',average_dap_score='$avg_dap',average_mob_overall_score='$avg_mob_overall',average_mob_usab_score='$avg_mob_usab',average_mob_perfrml_score='$avg_mob_perform',average_sitespeed_score='$avg_sitespeed',average_ipv6_score='$avg_ipv6',average_dnssec_score='$avg_dnssec',average_rc4_score='$avg_rc4',average_m15_score='$avg_m15',tot_color_contrast='$ag_avrg_color_cont',tot_html_attrib='$ag_avrg_html_attr',tot_missing_image='$ag_avrg_miss_image',search_available='$search_available',search_notavailable='$search_notavailable', average_uswds_score='$ag_avrg_uswds_score', mob_perf_good='$mobnew_good_sites',mob_perf_improve='$mobnew_improve_sites',mob_perf_poor='$mobnew_poor_sites',mob_usab_friendly='$mobnew_friendly_sites',mob_usab_nonfriendly='$mobnew_unfriendly_sites',dap_websites=$dap_websites,https_websites=$https_websites,uswds_websites=$uswds_websites,poc_websites=$poc_websites,redirect_websites=$redirect_websites");

        }
    }

}

/*
 * Extract Accessibility Info
 */
function extractAccessibilityErrors($domain){
    $comOut = shell_exec("timeout 15 /usr/bin/pa11y --ignore 'warning;notice' --reporter json https://".$domain);
    $decodedJson =  json_decode($comOut);
    $errorArr = array();
    foreach ($decodedJson as $stObj){
//        if($stObj->code == 'WCAG2AA.Principle1.Guideline1_1.1_1_1.H30.2'){
        if (strpos($stObj->code, 'WCAG2AA.Principle1.Guideline1_1') !== false) {
            $errorArr['Missing Image Descriptions'][] = $stObj;
        }
//        if($stObj->code == 'WCAG2AA.Principle1.Guideline1_4.1_4_3.G18.Fail'){
        if (strpos($stObj->code, 'WCAG2AA.Principle1.Guideline1_4') !== false) {
            $errorArr['Color Contrast - Initial Findings'][] = $stObj;
        }
//        if($stObj->code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.NoContent'){
        if (strpos($stObj->code, 'WCAG2AA.Principle4.Guideline4_1') !== false) {
            $errorArr['HTML Attribute - Initial Findings'][] = $stObj;
        }
    }
    $accessJson = json_encode($errorArr);
    return $accessJson;
}

/*
 * Update Accessibility Node with scan result
 */
function updateAccessibilityScanCustom($website,$webscanId){
    include("../scripts/configSettings.php");
    $start = microtime(true);
    $domain = $website;
    $siteId = findNode($website,'website');
    if($siteId != '') {
        //Check if the site is a redirect. If redirect dont run scan.
        $check_redirect = db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($website)))->fetchField();
        if ($check_redirect != "Yes") {
            $errorlist = extractAccessibilityErrors($domain);
            print_r($errorlist);
            $errorlist_decode = json_decode($errorlist);
            if (count($errorlist_decode) != 0) {
                //  if ($domval['domain'] == 'inl.gov') {
                //$allDomainNewArr[$domval['domain']]['errorlist'] = $domval['errorlist'];
                //$allDomainNewArr[$domval['domain']]['errordetails'] = $allDomErrArr['data'][$domain];
                $errorgroupTerms = array();
                $totError = 0;
                foreach ($errorlist_decode as $derror => $derrorval) {
                    $wcagCodearrOld = array();

                    if ($derror == 'Color Contrast - Initial Findings')
                        $cntColor = count($derrorval);
                    elseif ($derror == 'HTML Attribute - Initial Findings')
                        $cntHTML = count($derrorval);
                    elseif ($derror == 'Missing Image Descriptions')
                        $cntMissing = count($derrorval);

                    if ($derrorval != 0) {
                        $errorgroupTerms[] = $derror;
                    }
                    foreach ($derrorval as $errorintk1 => $errorintv1) {
//print_r($errorintv1);
                        foreach ($errorintv1 as $errorintk => $errorintv) {
                            if ($errorintk == "code")
                                $wcagCodearrOld[$errorintv] = $errorintv;
                        }
                        $wcagCodearr[$derror] = $wcagCodearrOld;
                    }
                }
                $totError = $cntColor + $cntHTML + $cntMissing;
//print_r($errorlist_decode);
//print_r($wcagCodearr);

                //$agencyId = findNode($domval['agency'],'agency');

                //Create Accessibility Scanning Node

                $date = date("m-d-Y");
                $node = new stdClass();
                $node->type = "508_scan_information";
                $node->language = LANGUAGE_NONE;
                $node->uid = "1";
                $node->name = "admin";
                $node->status = 1;
                $node->title = "Accessibility Scan " . $website;
                if (($nodeId = findNode($node->title, '508_scan_information')) != FALSE) {
                    echo "found node $node->title $nodeId";
                    $node->nid = $nodeId;
                }
                $node->promote = 0;

                $node->field_web_scan_id['und'][0]['nid'] = $webscanId;
                $node->field_website_id['und'][0]['nid'] = $siteId;
                $node->field_web_agency_id['und'][0]['nid'] = findParentAgencyNode($siteId);
                $node->field_508_scan_time['und'][0]['value'] = time();
                $node->field_accessibility_raw_scan['und'][0]['value'] = $errorlist;
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

                if (!empty($wnode->field_accessibility_errors)) {
                    foreach ($wnode->field_accessibility_errors['und'] as $etk => $etval) {
                        $currentTermsErr[] = $etval['tid'];
                    }
                    $crnTermCntErr = count($currentTermsErr);
                }

                if (!empty($wnode->field_accessibility_error_group)) {
                    foreach ($wnode->field_accessibility_error_group['und'] as $egtk => $egval) {
                        $currentTermsErrGrp[] = $egval['tid'];
                    }
                    $crnTermCntErrGrp = count($currentTermsErrGrp);
                }

                foreach ($wcagCodearr as $tagkey => $tags) {

                    if ($eterm = taxonomy_get_term_by_name($tagkey)) {
                        //print_r($eterm);
                        //$wnode->field_accessibility_error_group['und'][$j]['tid'] = $eterm->tid;
                        $terms_array = array_keys($eterm);
                        //Check if the term already assigned to the node
                        if (!in_array($terms_array['0'], $currentTermsErrGrp)) {
                            $wnode->field_accessibility_error_group['und'][$crnTermCntErrGrp + $j]['tid'] = $terms_array['0'];
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
                        $crnTermCntErr = $crnTermCntErr + $j;
                        if ($term = taxonomy_get_term_by_name($tag)) {
                            $terms_array_err = array_keys($term);
                            //Check if the term already assigned to the node
                            if (!in_array($terms_array_err['0'], $currentTermsErr)) {
                                $wnode->field_accessibility_errors['und'][$crnTermCntErr]['tid'] = $terms_array_err['0'];
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
                $wnode->field_section_508_scan_node['und'][0]['target_id'] = $node->nid;

                node_object_prepare($wnode);
                if ($wnode = node_submit($wnode)) {
                    node_save($wnode);
                }


                // }
            }
        }
    }
    else{
        //Redirect sites dont have any data for accessbility

    }
    $end = microtime(true);
    writeToLogs("Accessibility scan for ".$domain." took " . ($end - $start) . "seconds.", $logFile);
}

/*
 * Run Full Search Engine Scan and update search_scan custom table. Node will be updated during techscan.
 */

function runSearchEngineScan(){
    include("../scripts/configSettings.php");

    $nonwww_domains = array("accessibility.gov","ayudaconmibanco.gov","agingstats.gov","bankanswers.gov");
    $httpsonly_domains = array("ars-grin.gov","cbca.gov","cupcao.gov","eaglecash.gov","foiaonline.gov","wapa.gov","votebymail.gov","usphs.gov","ttb.gov","psa.gov","pretrialservices.gov","oversight.gov","navycash.gov","sss.gov");
    $ignore_domains = array("famep.gov","geocommunicator.gov","golearn.gov","hru.gov","icbemp.gov","lmrcouncil.gov","ncpw.gov","nea.gov","notalone.gov","ogis.gov","osc.gov","osdls.gov","qatesttwai.gov","reo.gov","tox21.gov","watermonitor.gov","atcreform.gov","doeal.gov","ots.gov","smarterskies.gov","aftac.gov");
    $curl_domains = array("lep.gov");
    writeToLogs("Get List of websites to Run Search Scan On",$logFile);
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b  where a.bundle=:bundle and b.nid=a.entity_id  and b.title not in (select domain from search_scan_copy)  and b.status='1' and b.title='911.gov' order by title", array(':bundle' => 'website'));
//$query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b  where a.bundle=:bundle and b.nid=a.entity_id   and b.status='1' and b.title not in (select domain from search_scan) order by title", array(':bundle' => 'website'));
    $query = db_query("select a.entity_id,a.body_value,b.title from field_data_body a , node b  where a.bundle=:bundle and b.nid=a.entity_id   and b.status='1'  order by title", array(':bundle' => 'website'));
    foreach ($query as $result) {
        print $result->title."";
        //Check if the site is a redirect. If redirect dont run scan.
        $check_redirect =  db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($result->title)))->fetchField();
        if($check_redirect != "Yes") {
            if (!in_array($result->title, $ignore_domains)) {
                if (in_array($result->title, $nonwww_domains)) {
                    $weburl = "http://" . trim($result->title);
                } else {
                    if (in_array($result->title, $httpsonly_domains)) {
                        $weburl = "https://www." . trim($result->title);
                    } else {
                        $weburl = "http://www." . trim($result->title);
                    }
                }
//    if(($curl_stat_code != '') && ($curl_stat_code != '404')){
//        $weburl = "http://".trim($result->title);
//    }
//    else{
//        $weburl = "http://www.".trim($result->title);
//    }
                $curl_stat_code = trim(shell_exec("timeout 15 curl -I  --stderr /dev/null $weburl | head -1 | cut -d' ' -f2"));

                if ($curl_stat_code != '') {
                    //$html = shell_exec("curl -L -k --silent https://".trim($result->title));
                    //$html = shell_exec("wget  --no-check-certificate --trust-server-names -qO- --max-redirect=1 -T 5 -t 1 ".$weburl);
                    //$html = shell_exec("phantomjs ../scripts/phantomjs_website.js \"".$weburl."/\"");
                    if (in_array($result->title, $curl_domains)) {
                        $html = shell_exec("timeout 15 curl -L -k --silent https://" . trim($result->title));
                    } else {
                        $html = shell_exec("timeout 15 google-chrome --no-sandbox --headless --disable-gpu --dump-dom --ignore-certificate-errors --user-agent=\"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.50 Safari/537.36\"  --timeout=15000  \"" . $weburl . "/\"");
                    }

                    print_r($html);
                    $dom = new DomDocument;
                    $dom->preserveWhiteSpace = FALSE;
                    $dom->loadHTML($html);
                    $params = $dom->getElementsByTagName('form'); // Find Sections
                    $params1 = $dom->getElementsByTagName('input'); // Find Sections
                    if ($params->length == 0) {
                        if ($params1->length != 0) {
                            $params = $params1;
                        }
                    }
                    print_r($params1);
                    $l = 0;
                    $forms1 = array();
                    foreach ($params1 as $param1) {
                        $forms1[$l][0] = $params1->item($l)->getAttribute('name');
                        $forms1[$l][1] = $params1->item($l)->getAttribute('action');
                        $forms1[$l][2] = $params1->item($l)->getAttribute('method');
                        $forms1[$l][3] = $params1->item($l)->getAttribute('type');
                        if (($forms1[$l][3] == 'text') || ($forms1[$l][3] == 'search')) {
                            $search_input_type = "text";
                        }
                        $l++;
                    }
                    //If the source does have a form or input process these
                    if (($params->length != 0) && ($search_input_type == 'text')) {
                        $k = 0;
                        $forms = array();
                        $searchtype = "";
                        $ded_searchdomain = "";
                        $search_avail = "";
                        foreach ($params as $param) {
                            $search_avail = "yes";
                            $forms = array();
                            $forms[$k][0] = $params->item($k)->getAttribute('name');
                            $forms[$k][1] = $params->item($k)->getAttribute('action');
                            $forms[$k][2] = $params->item($k)->getAttribute('method');
                            if (strpos($html, 'usasearch') !== FALSE) {
                                $searchtype = "search.usa.gov";
                            } elseif (strpos($html, 'search.usa.gov') !== FALSE) {
                                $searchtype = "search.usa.gov";
                            } elseif (strpos($html, "cse.google.com") !== FALSE) {
                                $searchtype = "google custom search";
                            } elseif (strpos($forms[$k][1], 'search.usa.gov') !== FALSE) {
                                $searchtype = "search.usa.gov";
                            } elseif (strpos($forms[$k][1], 'google') !== FALSE) {
                                $searchtype = "google search";
                            } elseif (strpos($forms[$k][1], "search." . trim($result->title)) !== FALSE) {
                                $searchtype = "search.usa.gov";
                            } elseif (strpos($forms[$k][1], 'http') === FALSE) {
                                $searchtype = "custom search";
                                //In custom search append action urls and find if the search has solr
                                $html_search = shell_exec("timeout 15 wget --no-check-certificate --trust-server-names -qO- --max-redirect=1 -T 5 -t 1 https://" . trim($result->title) . "/" . $forms[$k][1] . "?keys=test");
                                //Check if the site is Drupal based by checking against tag 32
                                $check_drupal = db_query("select b.title from field_data_field_cms_applications a, node b where a.field_cms_applications_tid='32' and a.entity_id=b.nid and b.title=:title", array(':title' => trim($result->title)))->fetchField();
                                //print $html_search;
                                if (strpos($html_search, 'solr') !== FALSE) {
                                    $searchtype = "apache solr";
                                } elseif ($check_drupal != '') {
                                    $searchtype = "drupal core search";
                                }
                            } else {
                                $check_drupal = db_query("select b.title from field_data_field_cms_applications a, node b where a.field_cms_applications_tid='32' and a.entity_id=b.nid and b.title=:title", array(':title' => trim($result->title)))->fetchField();
                                if ($check_drupal != '') {
                                    $searchtype = "drupal core search";
                                } else {
                                    $searchtype = "custom search";
                                }
                            }
                            if (strpos($forms[$k][1], trim($result->title)) !== FALSE) {
                                $ded_searchdomain = "yes";
                            } else {
                                $ded_searchdomain = "no";
                            }

                            db_query("replace into search_scan(domain,name,action,method,type,dedicated_search_domain,search_available) values( :title,:name,:action,:method,:type,:ddomain,:avail)", array(':title' => $result->title, ':name' => $params->item($k)->getAttribute('name'), ':action' => substr($params->item($k)->getAttribute('action'), 0, 255), ':method' => $params->item($k)->getAttribute('method'), ':type' => $searchtype, ':ddomain' => $ded_searchdomain, ':avail' => $search_avail));
                            $k++;
                        }
                    } elseif ((strpos($html, 'cse.google.com') !== FALSE)) {
                        $search_avail = "yes";
                        $type = "google custom search";
                        db_query("replace into search_scan(domain,search_available,type) values( :title,:avail,:type)", array(':title' => $result->title, ':avail' => $search_avail, ':type' => $type));
                    } elseif ((strpos($html, 'search.usa.gov') !== FALSE)) {
                        $search_avail = "yes";
                        $type = "search.usa.gov";
                        db_query("replace into search_scan(domain,search_available,type) values( :title,:avail,:type)", array(':title' => $result->title, ':avail' => $search_avail, ':type' => $type));
                    } else {
                        $search_avail = "no";
                        db_query("replace into search_scan(domain,search_available) values( :title,:avail)", array(':title' => $result->title, ':avail' => $search_avail));
                    }

                } else {
                    print "Sorry website is unavailable \n";
                    db_query("replace into search_scan(domain,search_available,domain_available) values( :title,:avail,:domavail)", array(':title' => $result->title, ':avail' => "no", ':domavail' => "no"));
                }
            } else {
                print "Sorry website is unavailable \n";
                db_query("replace into search_scan(domain,search_available,domain_available) values( :title,:avail,:domavail)", array(':title' => $result->title, ':avail' => "no", ':domavail' => "no"));
            }
        }
        else{
            print "Sorry website is unavailable \n";
            db_query("replace into search_scan(domain,search_available,domain_available) values( :title,:avail,:domavail)", array(':title' => $result->title, ':avail' => NULL, ':domavail' => "redirect"));
        }
    }

}

/**
 * When all scans are complete update scanEndDate node
 */
function updateScanEndDateTime() {
    $nid = db_query('SELECT MAX(nid) FROM node WHERE type = :type', array(':type' => 'scans'))->fetchField();

    if (!empty($nid)) {
        $node = node_load($nid);
        $title = 'Scan ' . date('m-d-Y', $node->created) . ' through ' . date('m-d-Y');

        $wrapper = entity_metadata_wrapper('node', $node);
        $wrapper->title->set($title);
        $wrapper->field_scan_end_time->set(time());
        $wrapper->save();
    }
}

/**
 * Summary Email
 */

function sendGovtWideSummaryEmail($starttime,$endtime){
    $mailto = "ayaskant.sahu@gsa.gov,OGP_Web_Portfolio_Support@gsa.gov";
    $subject = "Digital Dashboard Scan Summary Email";
    $govwidedata = dotgov_common_govwideTrendData();
    $difference = dateDifference($starttime,$endtime);
    $message = "
Here is the overall summary of the digitaldashboard.gov scan that was run on :".PHP_EOL.
        "Scan start Time: $starttime ".PHP_EOL.
        "Scan end time: $endtime".PHP_EOL.
        "Total Time taken for the scan : $difference".PHP_EOL.
        "Number of websites scanned: ".$govwidedata['websitenos']." ".PHP_EOL.
        "Number of Agencies scanned: ".$govwidedata['agencynos']." ".PHP_EOL.
        "Average HTTPS Score: ".$govwidedata['avg_https']." ".PHP_EOL.
        "Average DAP Score: ".$govwidedata['avg_dap']." ".PHP_EOL.
        "Average Mobile Performance Score: ".$govwidedata['avg_mob_perform']." ".PHP_EOL.
        "Average Mobile Uaability Score: ".$govwidedata['avg_mob_usab']." ".PHP_EOL.
        "Average Mobile  Overall Score: ".$govwidedata['avg_mob_overall']." ".PHP_EOL.
        "Average Overall Sitespeed Score: ".$govwidedata['avg_sitespeed']." ".PHP_EOL.
        "Average DNSSEC Score: ".$govwidedata['avg_dnssec']." ".PHP_EOL.
        "Average IPV6 Score: ".$govwidedata['avg_ipv6']." ".PHP_EOL.
        "Average M-15-13 and BOD 18-01 Score: ".$govwidedata['avg_m15']." ".PHP_EOL.
        "Average Free of RC4/3DES and SSLv2/SSLv3 Score: ".$govwidedata['avg_rc4']." ".PHP_EOL.
        "Here is the scan report attached below:".PHP_EOL.
        "".PHP_EOL.
        "".PHP_EOL.
        "";

    $attachment = array(
        'filecontent' => nl2br(file_get_contents('/web/e04tcm-acqprdweb.ent.ds.gsa.gov/html/scripts/logs/acquisitionProcessingLog-20190121.log')),
        'filename' => 'testfile.html',
        'filemime' => 'application/html'
    );
    global $language;
    $params['subject'] = t($subject);
    $params['body']    = array(t($message));
    $params['attachment'] = $attachment;

    drupal_mail('smtp', 'smtp-test', $mailto, $language, $params);
    print "Summary email Sent to the stakeholders \n";
}

//Find difference in date
function dateDifference($startdate,$enddate){
// Declare and define two dates
    $date1 = strtotime($startdate);
    $date2 = strtotime($enddate);
// Formulate the Difference between two dates
    $diff = abs($date2 - $date1);
// To get the year divide the resultant date into
// total seconds in a year (365*60*60*24)
    $years = floor($diff / (365*60*60*24));
// To get the month, subtract it with years and
// divide the resultant date into
// total seconds in a month (30*60*60*24)
    $months = floor(($diff - $years * 365*60*60*24)
        / (30*60*60*24));

// To get the day, subtract it with years and
// months and divide the resultant date into
// total seconds in a days (60*60*24)
    $days = floor(($diff - $years * 365*60*60*24 -
            $months*30*60*60*24)/ (60*60*24));
// To get the hour, subtract it with years,
// months & seconds and divide the resultant
// date into total seconds in a hours (60*60)
    $hours = floor(($diff - $years * 365*60*60*24
            - $months*30*60*60*24 - $days*60*60*24)
        / (60*60));

// To get the minutes, subtract it with years,
// months, seconds and hours and divide the
// resultant date into total seconds i.e. 60
    $minutes = floor(($diff - $years * 365*60*60*24
            - $months*30*60*60*24 - $days*60*60*24
            - $hours*60*60)/ 60);

// To get the minutes, subtract it with years,
// months, seconds, hours and minutes
    $seconds = floor(($diff - $years * 365*60*60*24
        - $months*30*60*60*24 - $days*60*60*24
        - $hours*60*60 - $minutes*60));

// Print the result
    $datediff  = "$days days, $hours hours, $minutes minutes, $seconds seconds";
    return $datediff;
}

//Unpublish all website nodes and related scan nodes which are not in pulse. Also unpublish all agencies which are not in scan.

function cleanupNodesAfterScan(){

//Find all websites currently active and only publish those and their child nodes and unpublish others and their child nodes.
    $query = db_query("select title,nid,status from node where type='website'");
    $i = 1;
    $j = 1;
    $k = 1;
    foreach ($query as $result) {
        //Only if the website is recently captured and valid executive branch
        $validwebsite = db_query("select domain from custom_pulse_https_data where domain=:website and branch='executive'", array(':website' => $result->title))->fetchField();
        print "$i --".$result->title. "\n";
        if($validwebsite) {
            print "$j -- ".$result->title . "-".$result->nid."-".$result->status." is valid \n";
            //Check if status is unpublished then publish the node
            if($result->status == 0){
                publishNode($result->nid);
            }
            //Find all scan ids tied to this website
            $query1 = db_query("select a.*,b.status from field_data_field_website_id a , node b where  a.entity_id=b.nid and a.field_website_id_nid='".$result->nid."'");
            foreach ($query1 as $result1) {
                print $result->title." - ".$result1->bundle."-".$result1->entity_id." will be published\n";
                //Check if status is unpublished then publish the node
                if($result1->status == 0){
                    publishNode($result1->entity_id);
                }
            }
            $j += 1;
        }
        else{
            print "$k -- invalid site --". $result->title . "-".$result->nid."  will be unpublished\n";
            //Check if status is published then unpublish the node
            if($result->status == 1){
                unPublishNode($result->nid);
            }
            //Find all scan ids tied to this website
            $query2 = db_query("select a.*,b.status from field_data_field_website_id a , node b where  a.entity_id=b.nid and a.field_website_id_nid='".$result->nid."'");
            foreach ($query2 as $result2) {
                print $result->title." - ".$result2->bundle."-".$result2->entity_id." will be unpublished\n";
                //Check if status is published then unpublish the node
                if($result2->status == 1){
                    unPublishNode($result2->entity_id);
                }
            }
            $k += 1;

        }
        $i += 1;
    }

    //Find all scan nodes which are orphaned or doesn't have a parent website id and unpublish them
    $query13 = db_query("select nid,title,type from node a ,field_data_field_website_id b where type in ('site_speed_scan','508_scan_information','domain_scan_information','https_dap_scan_information','mobile_scan_information','uswds_scan') and a.nid=b.entity_id and a.status='1' and field_website_id_nid  not in (select nid from node where status='1')");
    foreach ($query13 as $result13) {
        print $result13->title." - ".$result13->type."-".$result13->nid." orpahaned nodes will be unpublished\n";
        unPublishNode($result13->nid);
    }
    //Clean bad https domain
    $query14 = db_query("select nid,title,type from node a where type in ('https_dap_scan_information') and status='1' and a.nid not in (select nid from node a ,field_data_field_website_id b where type in ('https_dap_scan_information') and a.nid=b.entity_id and a.status='1' and field_website_id_nid  in (select nid from node))");
    foreach ($query14 as $result14) {
        print $result14->title." - ".$result14->type."-".$result14->nid." orpahaned nodes will be unpublished\n";
        unPublishNode($result14->nid);
    }
//Find all websites currently active and only publish those and their child nodes and unpublish others and their child nodes.
    $query12 = db_query("select title,nid,status from node where type='agency'");
    foreach ($query12 as $result12) {
//Only if the agency is recently captured and valid executive branch agency
        $validagency = db_query("select agency from custom_pulse_https_data where Agency=:agency and branch='executive'", array(':agency' => $result12->title))->fetchField();
        if($validagency) {
            print $result12->title . "-".$result12->nid."-".$result12->status." is valid \n";
            //Check if status is unpublished then publish the node
            if($result12->status == 0){
                publishNode($result12->nid);
            }
        }
        else{
            print $result12->title . "-".$result12->nid."-".$result12->status." is in valid \n";
            //Check if status is published then unpublish the node
            if($result12->status == 1){
                unPublishNode($result12->nid);
            }

        }
    }

}

function updateAccessibilityScan_custom($website,$scanid)
{
    include("../scripts/configSettings.php");
    $start = microtime(true);
    $domain = $website;
    $siteId = findNode($domain,'website');
    $parentAgencyId = findParentAgencyNode($siteId);
    if ($siteId != '') {
        //Check if the site is a redirect. If redirect dont run scan.
        $check_redirect = db_query("select redirect from custom_pulse_https_data where domain=:domain", array(':domain' => trim($website)))->fetchField();
        if ($check_redirect != "Yes") {
            $errorlist = db_query("select website_id,agency_id,agency_name,error_scan_type,wcag_code,error_cat,website,error_typecode,error_code,error_message,error_context,error_selector from custom_accessibility_issues where website=:website", array(':website' =>  $website));
            $count = 0;
            $field_axe_html_has_lang =0;
            $imagealt =0;
            $roleimgalt=0;
            $ariahiddenfocus=0;
            $ariainputfieldname=0;
            $ariatogglefieldname=0;
            $formfieldmultiplelabels=0;
            $linkname=0;
            $label=0;
            $cntF68=0;
            $cntH91InputCheckboxName=0;
            $cntH91InputFileName=0;
            $cntH91InputPasswordName=0;
            $cntH91InputRadioName=0;
            $cntH91InputTextName=0;
            $cntH91SelectName=0;
            $cntH91TextareaName=0;
            $cntH43MissingHeadersAttrs=0;
            $cntH393LayoutTable=0;
            $cntH43HeadersRequired=0;
            $cntH43IncorrectAttr=0;
            $cntH43MissingHeaderIds=0;
            $scopeattrvalid=0;
            $cntH43H63=0;
            $tdheadersattr=0;
            $inputbuttonname=0;
            $buttonname=0;
            $inputimagealt=0;
            $list=0;
            $ariaallowedrole=0;
            $emptyheading=0;
            $cntlistitem=0;
            $WCAG2AAPrinciple4Guideline4_14_1_2H91ButtonName=0;
            $cntcolorcontrast=0;
            $documenttitle=0;
            $cntH422=0;
            $cntH251EmptyTitle=0;
            $cntH251NoTitleEl=0;
            $scrollableregionfocusable=0;
            $cntH91AEmptyNoId=0;
            $cntH91ANoContent=0;
            $frametitleunique=0;
            $cntH91ButtonName=0;
            $cntH91InputButtonName=0;
            $cntH91InputImageName=0;
            $H91LiName=0;
            $htmllangvalid=0;
            $duplicateid=0;
            $H573Lang=0;
            $cntH581Lang=0;
            $cntvalidlang=0;
            $cntF77=0;
            $cntH641=0;
            $frametitle=0;
            $cntG145=0;
            $cntG18=0;

            foreach ($errorlist as $error ) {
                $count++;
                $website = $error->website;
                $website_id = $error->website_id;
                $agency_id = $error->agency_id;
                $agency_name = $error->agency_name;
                $error_scan_type = $error->error_scan_type;
                $wcag_code = $error->wcag_code;
                $error_cat = $error->error_cat;
                $error_typecode = $error->error_typecode;
                $error_code = $error->error_code;
                $error_message = $error->error_message;
                $error_context = $error->error_context;
                $error_selector = $error->error_selector;
                $error_json = json_encode($error);

                if ($count != 0) {
                    if ($error_code == 'html-has-lang') {
                        $field_axe_html_has_lang++;
                    }
                    if ($error_code == 'image-alt') {
                        $imagealt++;
                    }
                    if ($error_code == 'role-img-alt') {
                        $roleimgalt++;
                    }
                    if ($error_code == 'aria-hidden-focus') {
                        $ariahiddenfocus++;
                    }
                    if ($error_code == 'aria-input-field-name') {
                        $ariainputfieldname++;
                    }
                    if ($error_code == 'aria-toggle-field-name') {
                        $ariatogglefieldname++;
                    }
                    if ($error_code == 'form-field-multiple-labels') {
                        $formfieldmultiplelabels++;
                    }
                    if ($error_code == 'label') {
                        $label++;
                    }
                    if ($error_code == 'link-name') {
                        $linkname++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Button.Name') {
                        $WCAG2AAPrinciple4Guideline4_14_1_2H91ButtonName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.F68') {
                        $cntF68++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeadersAttrs') {
                        $cntH43MissingHeadersAttrs++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputCheckbox.Name') {
                        $cntH91InputCheckboxName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputFile.Name') {
                        $cntH91InputFileName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputPassword.Name') {
                        $cntH91InputPasswordName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputRadio.Name') {
                        $cntH91InputRadioName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputText.Name') {
                        $cntH91InputTextName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Select.Name') {
                        $cntH91SelectName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Textarea.Name') {
                        $cntH91TextareaName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H39.3.LayoutTable') {
                        $cntH393LayoutTable++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43,H63') {
                        $cntH43H63++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.HeadersRequired') {
                        $cntH43HeadersRequired++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.IncorrectAttr') {
                        $cntH43IncorrectAttr++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H43.MissingHeaderIds') {
                        $cntH43MissingHeaderIds++;
                    }
                    if ($error_code == 'scope-attr-valid') {
                        $scopeattrvalid++;
                    }
                    if ($error_code == 'td-headers-attr') {
                        $tdheadersattr++;
                    }
                    if ($error_code == 'empty-heading') {

                        $emptyheading++;
                    }
                    if ($error_code == 'listitem') {
                        $cntlistitem++;
                    }
                    if ($error_code == 'color-contrast') {
                        $cntcolorcontrast++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_3.1_3_1.H42.2') {
                        $cntH422++;
                    }
                    if ($error_code == 'scrollable-region-focusable') {
                        $scrollableregionfocusable++;
                    }
                    if ($error_code == 'document-title') {
                        $documenttitle++;
                    }
                    if ($error_code == 'WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.EmptyTitle') {
                        $cntH251EmptyTitle++;
                    }
                    if ($error_code == 'WCAG2AA.Principle2.Guideline2_4.2_4_2.H25.1.NoTitleEl') {
                        $cntH251NoTitleEl++;
                    }
                    if ($error_code == 'aria-allowed-role') {
                        $ariaallowedrole++;
                    }
                    if ($error_code == 'button-name') {
                        $buttonname++;
                    }
                    if ($error_code == 'input-button-name') {
                        $inputbuttonname++;
                    }
                    if ($error_code == 'input-image-alt') {
                        $inputimagealt++;
                    }
                    if ($error_code == 'link-name') {
                        $linkname++;
                    }
                    if ($error_code == 'list') {
                        $list++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.EmptyNoId') {
                        $cntH91AEmptyNoId++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.A.NoContent') {
                        $cntH91ANoContent++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Button.Name') {
                        $cntH91ButtonName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputButton.Name') {
                        $cntH91InputButtonName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.InputImage.Name') {
                        $cntH91InputImageName++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_2.H91.Li.Name') {
                        $H91LiName++;
                    }
                    if ($error_code == 'html-lang-valid') {
                        $htmllangvalid++;
                    }
                    if ($error_code == 'duplicate-id') {
                        $duplicateid++;
                    }
                    if ($error_code == 'WCAG2AA.Principle3.Guideline3_1.3_1_1.H57.3.Lang') {
                        $H573Lang++;
                    }
                    if ($error_code == 'WCAG2AA.Principle3.Guideline3_1.3_1_2.H58.1.Lang') {
                        $cntH581Lang++;
                    }
                    if ($error_code == 'WCAG2AA.Principle4.Guideline4_1.4_1_1.F77') {
                        $cntF77++;
                    }
                    if ($error_code == 'WCAG2AA.Principle2.Guideline2_4.2_4_1.H64.1') {
                        $cntH641++;
                    }
                    if ($error_code == 'frame-title-unique') {
                        $frametitleunique++;
                    }
                    if ($error_code == 'frame-title') {
                        $frametitle++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_4.1_4_3.G145') {
                        $cntG145++;
                    }
                    if ($error_code == 'WCAG2AA.Principle1.Guideline1_4.1_4_3.G18') {
                        $cntG18++;
                    }
                    if ($error_code == 'valid-lang') {
                        $cntvalidlang++;
                    }



//        print($error_json);
                }
            }
            $total_errors = $count;
//      print($count);
//      print("Total errors for" . $website . ' is ' . $total_errors);
            $images =array($imagealt,$roleimgalt);
            $parsing =array($duplicateid,$cntF77);
            $pageTitles=array($documenttitle,$cntH251EmptyTitle,$cntH251NoTitleEl);
            $linksnbuttons=array($ariaallowedrole,$H91LiName,$cntH91ButtonName,$cntH91InputButtonName,$cntH91InputImageName,$inputbuttonname,$buttonname,$cntH91InputImageName,$list,$inputimagealt,$linkname,$cntH91AEmptyNoId,$cntH91ANoContent,);
            $language=array($H573Lang,$cntH581Lang,$htmllangvalid,$field_axe_html_has_lang,$cntvalidlang);
            $keyboardAccess =array($scrollableregionfocusable);
            $framesniFrames = array($frametitleunique,$frametitle,$cntH641);
            $contrast = array($cntG145,$cntG18,$cntcolorcontrast);
            $contentStructure =array($cntlistitem,$cntH422,$emptyheading);
            $tables=array($cntH43H63,$cntH43MissingHeadersAttrs,$cntH43HeadersRequired,$cntH43MissingHeaderIds,$scopeattrvalid,$cntH393LayoutTable,$cntH43IncorrectAttr,$tdheadersattr);
            $forms =array($ariahiddenfocus,$cntH91TextareaName,$cntH91InputPasswordName,$cntH91SelectName,$cntH91InputTextName,$cntH91InputRadioName,$ariatogglefieldname,$ariainputfieldname,$formfieldmultiplelabels,$label,$cntF68,$cntH91InputCheckboxName,$cntH91InputFileName,);


            $date = date("m-d-Y");
            $node = new stdClass();
            $node->type = "508_scan_information";
            $node->language = LANGUAGE_NONE;
            $node->uid = "1";
            $node->name = "admin";
            $node->status = 1;
            $node->title = "Accessibility Scan " . $website;
            if (($nodeId = findNode($node->title, '508_scan_information')) != FALSE) {
                echo "found node $node->title $nodeId";
                $node->nid = $nodeId;
            }
            $node->promote = 0;

            $node->field_web_scan_id['und'][0]['nid'] =$scanid;
            $node->field_website_id['und'][0]['nid'] = $siteId;
            $node->field_web_agency_id['und'][0]['nid'] = $parentAgencyId;
            $node->field_508_scan_time['und'][0]['value'] = time();

            $node->field_axe_html_has_lang['und'][0]['value'] = $field_axe_html_has_lang;
            $node->field_axe_image_alt['und'][0]['value'] = $imagealt;
            $node->field_axe_role_img_alt['und'][0]['value'] = $roleimgalt;
            $node->field_axe_aria_hidden_focus['und'][0]['value'] = $ariahiddenfocus;
            $node->field_axe_aria_input_field_name['und'][0]['value'] = $ariainputfieldname;
            $node->field_axe_aria_toggle_field_name['und'][0]['value'] = $ariatogglefieldname;
            $node->field_axe_form_field_multiple_la['und'][0]['value'] = $formfieldmultiplelabels;
            $node->field_axe_label['und'][0]['value'] = $label;
            $node->field_axe_link_name['und'][0]['value'] = $linkname;
            $node->field_hcs_h91_button_name['und'][0]['value'] = $WCAG2AAPrinciple4Guideline4_14_1_2H91ButtonName;
            $node->field_axe_scope_attr_valid['und'][0]['value'] = $scopeattrvalid;
            $node->field_axe_td_headers_attr['und'][0]['value'] = $tdheadersattr;
            $node->field_hcs_h39_3_layouttable['und'][0]['value'] = $cntH393LayoutTable;
            $node->field_hcs_h43_h63['und'][0]['value'] = $cntH43H63;
            $node->field_hcs_h43_headersrequired['und'][0]['value'] = $cntH43HeadersRequired;
            $node->field_hcs_h43_incorrectattr['und'][0]['value'] = $cntH43IncorrectAttr;
            $node->field_hcs_h43_missingheaderids['und'][0]['value'] = $cntH43MissingHeaderIds;
            $node->field_hcs_h43_missingheadersattr['und'][0]['value'] = $cntH43MissingHeadersAttrs;
            $node->field_hcs_f68['und'][0]['value'] = $cntF68;
            $node-> field_hcs_h91_inputfile_name['und'][0]['value'] = $cntH91InputFileName;
            $node->field_hcs_h91_inputcheckbox_name['und'][0]['value'] = $cntH91InputCheckboxName;
            $node->field_hcs_h91_inputpassword_name['und'][0]['value'] = $cntH91InputPasswordName;
            $node->field_hcs_h91_inputradio_name['und'][0]['value'] = $cntH91InputRadioName;
            $node->field_hcs_h91_inputtext_name['und'][0]['value'] = $cntH91InputTextName;
            $node->field_hcs_h91_select_name['und'][0]['value'] = $cntH91SelectName;
            $node->field_hcs_h91_textarea_name['und'][0]['value'] = $cntH91TextareaName;
            $node->field_axe_color_contrast['und'][0]['value'] = $cntcolorcontrast;
            $node->field_hcs_g145['und'][0]['value'] = $cntG145;
            $node->field_hcs_g18['und'][0]['value'] = $cntG18;
            $node->field_axe_empty_heading['und'][0]['value'] = $emptyheading;
            $node->field_axe_listitem['und'][0]['value'] = $cntlistitem;
            $node->field_hcs_h42_2['und'][0]['value'] = $cntH422 ;
            $node->field_axe_frame_title['und'][0]['value'] = $frametitle;
            $node->field_axe_frame_title_unique['und'][0]['value'] = $frametitleunique;
            $node->field_hcs_h64_1['und'][0]['value'] = $cntH641;
            $node->field_axe_scrollable_region_focu['und'][0]['value'] = $scrollableregionfocusable;
            $node->field_axe_aria_allowed_role['und'][0]['value'] = $ariaallowedrole;
            $node->field_axe_button_name['und'][0]['value'] = $buttonname;
            $node->field_axe_input_button_name['und'][0]['value'] = $inputbuttonname;
            $node->field_axe_link_name['und'][0]['value'] = $linkname;
            $node->field_axe_list['und'][0]['value'] = $list;
            $node->field_hcs_h91_a_emptynoid['und'][0]['value'] = $cntH91AEmptyNoId;
            $node->field_hcs_h91_a_nocontent['und'][0]['value'] = $cntH91ANoContent;
            $node->field_hcs_h91_button_name['und'][0]['value'] = $cntH91ButtonName;
            $node->field_hcs_h91_inputbutton_name['und'][0]['value'] = $cntH91InputButtonName;
            $node->field_hcs_h91_inputimage_name['und'][0]['value'] = $cntH91InputImageName;
            $node->field_hcs_h91_li_name['und'][0]['value'] = $H91LiName;
            $node->field_axe_document_title['und'][0]['value'] = $documenttitle;
            $node->field_hcs_h25_1_emptytitle['und'][0]['value'] = $cntH251EmptyTitle;
            $node->field_hcs_h25_1_notitleel['und'][0]['value'] = $cntH251NoTitleEl;
            $node->field_axe_duplicate_id['und'][0]['value'] = $duplicateid;
            $node->field_hcs_f77['und'][0]['value'] = $cntF77;
            $node->field_hcs_h58_1_lang['und'][0]['value'] =$cntH581Lang;
            $node->field_axe_html_lang_valid['und'][0]['value']=$htmllangvalid;
            $node->field_axe_valid_lang['und'][0]['value']=$cntvalidlang;

            $node->field_images_total['und'][0]['value']= array_sum($images);
            $node->field_1_1_1_non_text_content_tot['und'][0]['value']=array_sum($images);
            $node->field_parsing_total['und'][0]['value']=array_sum($parsing);
            $node->field_4_1_1_parsing_total['und'][0]['value']=array_sum($parsing);
            $node->field_page_titles_total['und'][0]['value']=array_sum($pageTitles);
            $node->field_2_4_2_page_titled_total['und'][0]['value']=array_sum($pageTitles);
            $node->field_links_and_buttons_total['und'][0]['value']=array_sum($linksnbuttons);
            $node->field_2_4_4_link_purpose_in_cont['und'][0]['value']=array_sum($linksnbuttons);
            $node->field_3_1_1_language_of_page_tot['und'][0]['value']=array_sum($language);
            $node->field_language_total['und'][0]['value']=array_sum($language);
            $node->field_keyboard_access_total['und'][0]['value']=array_sum($keyboardAccess);
            $node->	field_2_1_1_keyboard_total['und'][0]['value']=array_sum($keyboardAccess);
            $node->field_frames_and_iframes_total['und'][0]['value']=array_sum($framesniFrames);
            $node->field_4_1_2_name_role_value_tota['und'][0]['value']=array_sum($framesniFrames);
            $node->field_contrast_total['und'][0]['value']=array_sum($contrast);
            $node->field_1_4_3_contrast_minimum_tot	['und'][0]['value']=array_sum($contrast);
            $node->field_content_structure_total['und'][0]['value']=array_sum($contentStructure);
            $node->field_tables_total['und'][0]['value']=array_sum($tables);
            $node->	field_forms_total['und'][0]['value']=array_sum($forms);
            $node->field_1_3_1info_and_relation_tot['und'][0]['value']=array_sum($contentStructure)+array_sum($tables)+array_sum($forms);


            //      $node->field_accessibility_raw_scan['und'][0]['value'] = $errorlist;

            $access_errors = db_query("select distinct error_cat from custom_accessibility_issues where website_id=:website", array('website' => $siteId));
            foreach ($access_errors as $error) {
                $ict_terms[] = $error->error_cat;
            }


            //Save Tags to parent website
            if(!empty($ict_terms)) {
                if(!empty($node->field_ict_group)){
                    foreach($node->field_ict_group['und'] as $ctk  =>$ctval){
                        $currentTerms[] = $ctval['tid'];
                    }
                    $crnTermCnt = count($currentTerms);
                }

                $i = 1;
                foreach (array_unique($ict_terms) as $key => $tag) {
                    if ($term = taxonomy_get_term_by_name($tag)) {
                        $terms_array = array_keys($term);
                        //Check if the term already assigned to the node
                        if(!in_array($terms_array['0'],$currentTerms)){
                            $node->field_ict_group['und'][$crnTermCnt+$i]['tid'] = $terms_array['0'];
                        }
                    } else {
                        $term = new STDClass();
                        $term->name = $tag;
                        $term->vid = 6;
                        if (!empty($term->name)) {
                            taxonomy_term_save($term);
//                        $term = taxonomy_get_term_by_name($tag);
//                        foreach($term as $term_id){
//                            $node->product_tags[LANGUAGE_NONE][$key]['tid'] = $term_id->tid;
//                        }
                            $node->field_ict_group['und'][$key]['tid'] = $term->tid;
                        }
                    }
                    $i += 1;
                }

            }else{
                $node->field_ict_group['und'] = NULL;
            }


            $code_errors = db_query("select distinct error_code from custom_accessibility_issues where website_id=:website", array('website' => $siteId));
            foreach ($code_errors as $codeerror) {
                $error_terms[] = $codeerror->error_code;
            }

            //Save Tags to parent website
            if(!empty($error_terms)) {
                if(!empty($node->field_error_code)){
                    foreach($node->field_error_code['und'] as $ctk1  =>$ctval1){
                        $currentTerms1[] = $ctval1['tid'];
                    }
                    $crnTermCnt1 = count($currentTerms1);
                }

                $j = 1;
                foreach (array_unique($error_terms) as $key1 => $tag1) {
                    if ($term1 = taxonomy_get_term_by_name($tag1)) {
                        $terms_array1 = array_keys($term1);
                        //Check if the term already assigned to the node
                        if(!in_array($terms_array1['0'],$currentTerms1)){
                            $node->field_error_code['und'][$crnTermCnt1+$j]['tid'] = $terms_array1['0'];
                        }
                    } else {
                        $term1 = new STDClass();
                        $term1->name = $tag1;
                        $term1->vid = 6;
                        if (!empty($term1->name)) {
                            taxonomy_term_save($term1);
//                        $term = taxonomy_get_term_by_name($tag);
//                        foreach($term as $term_id){
//                            $node->product_tags[LANGUAGE_NONE][$key]['tid'] = $term_id->tid;
//                        }
                            $node->field_error_code['und'][$key1]['tid'] = $term1->tid;
                        }
                    }
                    $j += 1;
                }

            }else{
                $node->field_error_code['und'] = NULL;
            }

            node_object_prepare($node);
            if ($node = node_submit($node)) {
                node_save($node);
            }

        }
        else{
            print('Website is a redirect \n');
        }
    }
}

# Run Custom Accessbility Scan
//function runCustomAccessbilityScanNew($scanId){
//    $first = false;
//    if (($handle = fopen('/tmp/current-federal.csv', "r")) !== FALSE) {
//        while (!feof($handle)) {
//            $data = fgetcsv($handle);
//            if (!$first) {
//                $first = true;
//                continue;
//            }
//            if($data[1]=='Federal Agency - Executive') {
//                updateAccessibilityScan_custom($data[0]);
//            }
//        }
//
//        fclose($handle);
//
//    }
//}

/*
 * Create Government Wide Snapshot for Archival and trend analysis purpose
 */
function access_archiveGovwideTrendData(){
    //Find Number of published websites
    $curdate = date("Y-m-d");
    $websitenos = db_query("select count(*) from node where type='website' and status ='1'")->fetchField();
    $agencynos = db_query("select count(*) from node a, field_data_field_agency_branch b where a.type='agency' and a.status ='1' and a.nid=b.entity_id and  b.field_agency_branch_value='executive'")->fetchField();

    //Query to get Accessibility errors
    $total_forms =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Forms'", array())->fetchField());

    $total_images =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Images'", array())->fetchField());

    $total_content_structure =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Content Structure'", array())->fetchField());
    $total_tables =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Tables'", array())->fetchField());
    $total_contrast =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Contrast'", array())->fetchField());
    $total_keyboard_access =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Keyboard Access'", array())->fetchField());

    $total_page_titles =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Page Titles'", array())->fetchField());

    $total_language =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Language'", array())->fetchField());

    $total_links_and_buttons =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Links and Buttons'", array())->fetchField());
    $total_parsing =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Parsing'", array())->fetchField());
    $total_frames_and_iframes =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Frames and iFrames'", array())->fetchField());


    $total_nontext_content =$total_images ;
    $total_info_and_relationships = $total_content_structure + $total_tables + $total_forms ;
    $total__contrast_minimum =$total_contrast;
    $total_keyboard =$total_keyboard_access;
    $total_page_titled =$total_page_titles;
    $total_link_purpose_incontext = $total_links_and_buttons;
    $total_languae_of_page =$total_language;
    $total_name_role_value =$total_frames_and_iframes;
    $total_wcag_parsing =$total_parsing;



//  print  ( $websitenos. '' .$agencynos . '' . $total_forms . '' . $total_images . '' . $total_content_structure . '' . $total_tables . '' . $total_contrast . '' .$total_keyboard_access . '' . $total_page_titles . '' . $total_language . '' . $total_links_and_buttons . '' . $total_parsing . '' .$total_frames_and_iframes);
//  print "insert into custom_government_wide_archive values(NULL,CURDATE(),NOW(),'$websitenos','$ag_avrg_color_cont','$ag_avrg_html_attr','$ag_avrg_miss_image','$agencynos') ON DUPLICATE KEY UPDATE
//num_of_websites='$websitenos',tot_color_contrast='$ag_avrg_color_cont',tot_html_attrib='$ag_avrg_html_attr',tot_missing_image='$ag_avrg_miss_image',num_of_agencies='$agencynos' \n";

//Update/Insert Archive record for current data sets
    db_query("insert into custom_gov_wide_access_archive values(NULL,CURDATE(),NOW(),'$websitenos','$agencynos','$total_nontext_content','$total_info_and_relationships','$total__contrast_minimum','$total_keyboard','$total_page_titled',
                    '$total_link_purpose_incontext','$total_languae_of_page','$total_wcag_parsing','$total_name_role_value','$total_images','$total_content_structure','$total_forms','$total_tables','$total_contrast','$total_keyboard_access',
                    '$total_page_titles','$total_language','$total_links_and_buttons','$total_parsing','$total_frames_and_iframes') ON DUPLICATE KEY UPDATE
                    num_of_websites='$websitenos',num_of_agencies='$agencynos',total_1_1_1_nontext_content	='$total_nontext_content',total_1_3_1_info_and_relationships='$total_info_and_relationships',total_1_4_3_contrastminimum='$total__contrast_minimum',total_2_1_1_keyboard='$total_keyboard',total_2_4_2_page_titled='$total_page_titled',
                    total_2_4_3_link_purpose_incontext='$total_link_purpose_incontext',total_3_1_1_languae_of_page='$total_languae_of_page',total_4_1_1_parsing='$total_wcag_parsing',total_4_1_2_name_role_value='$total_name_role_value',total_images='$total_images',total_content_structure='$total_content_structure',total_forms='$total_forms',
                    total_tables='$total_tables',total_contrast='$total_contrast',total_keyboard_access='$total_keyboard_access',total_page_titles='$total_page_titles',
                    total_language ='$total_language',total_links_and_buttons='$total_links_and_buttons',total_parsing='$total_parsing',total_frames_and_iframes='$total_frames_and_iframes'");
}

function access_archiveAgencyWideTrendData(){
    $query = db_query("select nid,title from node where type=:bundle", array(':bundle' => 'agency'));
    $curdate = date("Y-m-d");
    foreach ($query as $result) {
        $websitenos = db_query("select count(*) from node a , field_data_field_web_agency_id b   where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and field_web_agency_id_nid=:agencyid",array(':agencyid' => $result->nid))->fetchField();

        //Query to get Accessibility errors
        $total_agforms =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Forms' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());

        $total_agimages =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Images' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());

        $total_agcontent_structure =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Content Structure' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agtables =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Tables' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agcontrast =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Contrast' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agkeyboard_access =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Keyboard Access' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agpage_titles =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Page Titles' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_aglanguage =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Language' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());

        $total_aglinks_and_buttons =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Links and Buttons' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agparsing =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Parsing' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());
        $total_agframes_and_iframes =  round(db_query("select count(error_cat) as avg_value from custom_accessibility_issues where error_cat = 'Frames and iFrames' and agency_id=:agencyid", array(':agencyid' =>  $result->nid))->fetchField());



        $total_agnontext_content =$total_agimages ;
        $total_aginfo_and_relationships = $total_agcontent_structure + $total_agtables + $total_agforms ;
        $total__agcontrast_minimum =$total_agcontrast;
        $total_agkeyboard =$total_agkeyboard_access;
        $total_agpage_titled =$total_agpage_titles;
        $total_aglink_purpose_incontext = $total_aglinks_and_buttons;
        $total_aglanguae_of_page =$total_aglanguage;
        $total_agname_role_value =$total_agframes_and_iframes;
        $total_agwcag_parsing =$total_agparsing;

        if($websitenos != '0'){
            db_query("insert into custom_agency_wide_access_archive values(NULL,CURDATE(),NOW(),'$websitenos','$result->title','$result->nid','$total_agnontext_content','$total_aginfo_and_relationships','$total__agcontrast_minimum','$total_agkeyboard','$total_agpage_titled',
                    '$total_aglink_purpose_incontext','$total_aglanguae_of_page','$total_agwcag_parsing','$total_agname_role_value','$total_agimages','$total_agcontent_structure','$total_agforms','$total_agtables','$total_agcontrast','$total_agkeyboard_access',
                    '$total_agpage_titles','$total_aglanguage','$total_aglinks_and_buttons','$total_agparsing','$total_agframes_and_iframes') ON DUPLICATE KEY UPDATE
                    num_of_websites='$websitenos',agency='$result->title',agency_id='$result->nid',agtotal_1_1_1_nontext_content	='$total_agnontext_content',agtotal_1_3_1_info_and_relationships='$total_aginfo_and_relationships',agtotal_1_4_3_contrastminimum='$total__agcontrast_minimum',agtotal_2_1_1_keyboard='$total_agkeyboard',agtotal_2_4_2_page_titled='$total_agpage_titled',
                    agtotal_2_4_3_link_purpose_incontext='$total_aglink_purpose_incontext',agtotal_3_1_1_languae_of_page='$total_aglanguae_of_page',agtotal_4_1_1_parsing='$total_agwcag_parsing',agtotal_4_1_2_name_role_value='$total_agname_role_value',agtotal_images='$total_agimages',agtotal_content_structure='$total_agcontent_structure',agtotal_forms='$total_agforms',
                    agtotal_tables='$total_agtables',agtotal_contrast='$total_agcontrast',agtotal_keyboard_access='$total_agkeyboard_access',agtotal_page_titles='$total_agpage_titles',
                    agtotal_language ='$total_aglanguage',agtotal_links_and_buttons='$total_aglinks_and_buttons',agtotal_parsing='$total_agparsing',agtotal_frames_and_iframes='$total_agframes_and_iframes'");
        }

    }

}

function unPublishNode($nid){
    // Load a node
    $node = node_load($nid);
    // set status property to 0
    $node->status = 0;
    // re-save the node
    node_save($node);
    print "Unpublished ".$node->title." ".$node->nid." of type ".$node->type."\n";
}
function publishNode($nid){
    // Load a node
    $node = node_load($nid);
    // set status property to 0
    $node->status = 1;
    // re-save the node
    node_save($node);
    print "Published ".$node->title." ".$node->nid." of type ".$node->type."\n";
}
