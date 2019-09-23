<?php
/*

select nid,title from node where type='mobile_scan_information' and status='1' having title not in (select concat('Mobile Scan ',title) as title from node where type='website' and status='1');
select nid,title from node where type='https_dap_scan_information' and status='1' having title not in (select concat('HTTPS DAP Scan ',title) as title from node where type='website' and status='1');

select nid,title from node where type='site_speed_scan' and status='1' having title not in (select concat('Site Performance Scan ',title) as title from node where type='website' and status='1');
select nid,title from node where type='domain_scan_information' and status='1' having title not in (select concat('Domain Scan ',title) as title from node where type='website' and status='1');


*/
$nids = array(1537, 1687, 2224, 2374, 2383, 2395, 2887, 3115, 4459, 4573, 4588, 4705, 6073, 7418, 2816, 2846, 2987, 3041, 3110, 3149, 3176, 3185, 3284, 3350, 3353, 3626, 3698, 3818, 3881, 3884, 3911, 3935, 4130, 4202, 4247, 4445, 4532, 4715, 6071, 4880, 4929, 4930, 5109, 5159, 5162, 5166, 5326, 5330, 5399, 5406, 5854, 5892, 5897, 5899, 5936, 6074, 7419, 1683, 6072,1421, 1430, 1433, 1682, 1748, 1784, 1820, 1844, 1967, 2084, 2291, 2411, 2420, 2432, 2456, 2468, 2498, 2552, 2561, 2579, 2600, 2801);
$nodes = node_load_multiple($nids);
foreach ($nodes as $node) {
  // set status property to 1
  $node->status = 0;
  // re-save the node
  node_save($node);
}
?>

