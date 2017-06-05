<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
if(isset($_GET['field_web_agency_id_nid'])){
	if($_GET['field_web_agency_id_nid'] == 'All') 
		$agtit = "Compliance Report";
	else{
	$agnode = node_load($_GET['field_web_agency_id_nid']);
	$agtit = "Compliance Report for ".$agnode->title;
	}
}
else
	 $agtit = "Compliance Report";
$chartData = "[\"Scan Criteria\", \"Overall Compliance Report\", { role: \"style\" } ],";
$chartColors = array('#91cee5','#e61638', '#00a5d4', '#ffb900', '#44a560', '#aeb0b5');
$chartCrit = array("field_ssl_score"=>"SSL","field_dap_score"=>"DAP","field_https_score"=>"HTTPS","field_mobile_overall_score"=>"MOBILE","field_mobile_performance_score"=>"MOBILE PERFORMANCE","field_mobile_usability_score"=>"MOBILE FRIENDLY");
$i = 0;
$chartData1 = "";
foreach($view->style_plugin->rendered_fields[0] as $key=>$val){
    if($key == 'field_web_agency_id_1')
        $totWebsites = "$val";
    else {
        $chartData .= "[\"" . $chartCrit[$key] . "\"," . $val . ",\"" . $chartColors[$i] . "\"],";
        $chartData1 .= $val . ",";
        $i += 1;
    }
}
?>
<script type="text/javascript">
    google.charts.load('current', {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {
        var data = google.visualization.arrayToDataTable([
            ['Scans', '<?=implode("','",array_values($chartCrit))?>'],
            ['Overall Score', <?=$chartData1?>],
        ]);



        var options = {
           chartArea: {
      left: '15%',
      top: 30,
      width: '70%',
      height: '70%'
    },
                           
            colors: ['<?=implode("','",array_values($chartColors))?>'],
            legend: { position: 'top' },
            bars: 'vertical',
            vAxis: {format: 'decimal'},
            width: '50%',
            bar: {groupWidth: '50%'},
        };

        var chart = new google.visualization.ColumnChart(document.getElementById('columnchart_material'));

          chart.draw(data, options);    
};
</script>
<div class="row ">
<div class="col-xs-12">
<h3><?=$agtit ;?></h3>
<p>Average score of all <?=$totWebsites?> websites scanned</p>
<div id="columnchart_material"></div>
<p><button id="link-all-reports"><a href="/website/all/reports">Complete List</a></button>
</p>
</div>
</div>