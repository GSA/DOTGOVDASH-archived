<?php
/*
 * File contains all configuration and settings for the Scan Engine
 */
global $logFile;
global $csvFile;
global $snapshotFolder;
$logFile = "../scripts/logs/dashboardScanLog-".date('Ymd').".log";
$csvFile = '../scripts/websiteListing.csv';
$snapshotFolder = "sites/default/files/tmp/snapshots/";
$accessible_domains_url = "https://staging.pulse.cio.gov/static/data/tables/accessibility/domains.json";
$accessible_errors_url = "https://staging.pulse.cio.gov/static/data/tables/accessibility/a11y.json"; 
$accessible_agencyAPI_url = "https://staging.pulse.cio.gov/static/data/tables/accessibility/agencies.json";
