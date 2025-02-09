<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
#dsm($view);
#print_r($view->style_plugin->rendered_fields);
if(isset($_GET['field_web_agency_id_nid'])){
   if($_GET['field_web_agency_id_nid'] == 'All') 
      $agtit = "Government-Wide Report";
   else{
   $agnode = node_load($_GET['field_web_agency_id_nid']);
   $agtit = "Report for ".$agnode->title;
   }
}
else
    $agtit = "Report";
$chartData = "[\"Scan Criteria\", \"Overall Report\", { role: \"style\" }, { role: 'annotation' } ],";
#$chartColors = array('#0071bc','#205493', '#112e51', '#212121', '#323a45', '#aeb0b5','#046b99','#00a6d2');
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463','#5b616b','#e59393','#e31c3d','#48a463');
#$chartCrit = array("field_ssl_score"=>"SSL","field_dap_score"=>"DAP","field_https_score"=>"HTTPS","field_mobile_overall_score"=>"MOBILE","field_mobile_performance_score"=>"MOBILE PERFORMANCE","field_mobile_usability_score"=>"MOBILE FRIENDLY");
$chartCrit = array("field_dap_score"=>"DAP","field_https_score"=>"HTTPS","field_mobile_overall_score"=>"MOBILE OVERALL","field_mobile_performance_score"=>"MOBILE PERFORMANCE","field_mobile_usability_score"=>"MOBILE USABILITY","field_dnssec_score"=>'DNSSEC',"field_ipv6_score"=>"IPv6","field_site_speed_score"=>"SITE SPEED",'field_free_of_insecr_prot_score'=>'Free of RC4/3DES and SSLv2/SSLv3','field_m15_13_compliance_score'=>'M-15-13 and BOD 18-01 Compliance');
$i = 0;
$chartData1 = "";
foreach($view->style_plugin->rendered_fields[0] as $key=>$val){
    if($key == 'field_web_agency_id_1')
        $totWebsites = "$val";
    else {
	if($val == ''){
		//$val = '0';
		continue;
	}
        $chartData .= "[\"" . $chartCrit[$key] . "\"," . $val . ",\"" . $chartColors[$i] ."\",".$val."],";
        $chartData1 .= $val . ",";
        $i += 1;
    }
}
$chartCritval = array_values($chartCrit);
#sort($chartCritval);
?>
<script type="text/javascript">
    google.charts.load('current', {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {
		var data = google.visualization.arrayToDataTable([<?=$chartData?>]);
        <?php /*var data_old = google.visualization.arrayToDataTable([
            ['Scans', '<?=implode("','",$chartCritval)?>'],
			['Overall Score', <?=$chartData1?>]]

        );*/ ?>
        var options = {
           /*chartArea: {
				//left: '15%',
				//top: 10,
				//bottom: 5,
				width: '40%',
				height: '100%'
		},*/
             title: "<?=$agtit ;?>",             
            colors: ['<?=implode("','",array_values($chartColors))?>'],
            //legend: { position: 'right' },
			legend: 'none',
            bars: 'vertical',
            vAxis: {format: 'decimal',    
				viewWindow: {
				min:0,
				max:100
			}
       },
            width: '50%',
            bar: {groupWidth: '100%'},
        };

        var chart = new google.visualization.ColumnChart(document.getElementById('columnchart_material'));

          chart.draw(data, options);    
};
/* google.load("visualization", "1", { 
	packages: ["corechart"], 
	callback: function() { drawChart(); }
}); */
</script>
<div class="row ">
<div class="col-xs-12">
<h3><?=$agtit ;?></h3>
<p>Average score of all <?=$totWebsites?> websites scanned</p>
<div id="columnchart_material"></div>
<a href="/website/all/reports-new" id="link-all-reports">Complete List</a> (Last Scan Date: <?=dotgov_common_lastScanDate()?>)</div>
<span class="field-content col-lg-12"><a href="/content/scoring-methods" title="" data-toggle="tooltip" class="infor" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">Click Here to see the scoring methods used to calculate the scores</span></a></span>
</div>
