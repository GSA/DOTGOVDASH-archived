<?php
/*
 * The Script to initiate scan. Pass through all url entities and and capture necessary data
 * 1.Snapshots needs to be created in webroot/sites/default/files/tmp/snapshots and then moved to webroot/sites/default/files/snapshots when they are saved in the node. Remove tmp files after processing is done.
 * There are a few scans that are run on all sites at the same time. Because its effective to get all information at once and update the results. From performance and number of url calls we make, this can be much better approach in some case.
 * Most scans will run from
 */
include_once("../scripts/commonScanFunctions.php");
$startTime = date("Y:m:d h:i:s");
//Send mail or not . Valid values are yes or no
$sendmail = "yes";
//Before Starting scan get the latest website listing and data from pulse
writeToLogs("Get Latest Websites and data from Pulse\n",$logFile);
getPulseData();
runSearchEngineScan();
//Update Search engine table with custom collected data from search_customidentfied_domains.csv
exec("drush sql-query \"create table if not exists tmpdomains(domain varchar(255),search_available varchar(11));\"");
exec("drush sql-query \"truncate tmpdomains;\"");
exec("drush sql-query \"load data local infile '../scripts/search_customidentfied_domains.csv' into table tmpdomains FIELDS TERMINATED BY ',';\"");
exec("drush sql-query \"update search_scan a, tmpdomains b set a.search_available=b.search_available where a.domain=b.domain;\"");
exec("drush sql-query \"update search_scan set search_available = 'NA',type = NULL where domain in (select a.title from node a, field_data_field_redirect b, field_data_field_website_id c where a.nid=c.field_website_id_nid and b.entity_id=c.entity_id and b.field_redirect_value='yes');\"");
exec("drush sql-query \"drop table tmpdomains;\"");

//Start the scan and get the scan id.
writeToLogs("Starting Scan",$logFile);
$scanId = startScan();
//Start USWDS Scan
writeToLogs("Collect USWDS Data through a full scan",$logFile);
updateUswdsScanInfo($webscanId);
//Below are the full scans run for all websites at once. DAP and HTTPS info are collected from pulse site at once for perforamnce optimization
writeToLogs("Collecting HTTPS and DAP data from Pulse",$logFile);
//Get the latest reports from pulse accessibility to local.
//This wont be executed anymore as pulse accessibility API site is down
//updateAccessibleScanInfo($scanId);

//Below are scans that are run individually for each site.

$listWebsites = getSites();
foreach($listWebsites as $key=>$website){

    //Update technology Stack Infomration
    writeToLogs("Running Technology Scan for site ".$website['domain'],$logFile);
    updateTechStackInfo($website['domain']);

    writeToLogs("\nStart Domain and SSL Scan for ".$website['domain'],$logFile);
    updateDomainSSLInfo($key,$scanId,$website);

    //Update HTTPS and DAP info in Drupal. HTTPS info is dependent on domain scan
    writeToLogs("\nStart HTTPS and DAP Scan ".$website['domain'],$logFile);
    updateHttpsDAPInfo($key,$scanId,$website);

    writeToLogs("\nStart Mobile Scan for ".$website['domain'],$logFile);
    updateMobileScanInfo($key,$scanId,$website);
    writeToLogs("\nStart Site Speed Scan for ".$website['domain'],$logFile);
    updateSiteScanInfo($key,$scanId,$website);

//Get the latest reports from pulse accessibility to local.
    writeToLogs("\nStart Accessibility Scan for ".$website['domain'],$logFile);
   // updateAccessibilityScanCustom($website['domain'],$scanId);
    updateAccessibilityScan_custom($website['domain'],$scanId);

}
cleanupNodesAfterScan();
//After scan is done. Run the taxonomy processor. This will parse all taxonomy data and create/edit taxonomies and tag appropriate content.
archiveGovwideTrendData();
archiveAgencywideTrendData();
access_archiveGovwideTrendData();
access_archiveAgencyWideTrendData();

$endTime = date("Y:m:d h:i:s");
if($sendmail == "yes"){
    sendGovtWideSummaryEmail($startTime,$endTime);
}
print "Finished Processing!\n";