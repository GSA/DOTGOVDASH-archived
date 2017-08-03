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