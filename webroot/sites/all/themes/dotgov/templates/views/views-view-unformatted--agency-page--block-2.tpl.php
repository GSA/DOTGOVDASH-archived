<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Scan Criteria\", \"Overall Compliance Report\", { role: \"style\" } ],";
$chartColors = array('#2e8540', '#94bfa2', '#4773aa', '#8ba6ca', '#00a6d2','#205493');
$chartCrit = array("field_ssl_score"=>"SSL","field_dap_score"=>"DAP","field_https_score"=>"HTTPS","field_mobile_overall_score"=>"MOBILE","field_mobile_performance_score"=>"MOBILE PERFORMANCE","field_mobile_usability_score"=>"MOBILE FRIENDLY");
$i = 0;
$chartData1 = "";
foreach($view->style_plugin->rendered_fields[0] as $key=>$val){
    if($key == 'field_web_agency_id')
        $agencyName = "$val";
    elseif($key == 'field_web_agency_id_1')
        $totWebsites = "$val";
    else {
        $chartData .= "[\"" . $chartCrit[$key] . "\"," . $val . ",\"" . $chartColors[$i] . "\"],";
        $chartData1 .= $val . ",";
        $i += 1;
    }
}
?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">
    google.charts.load('current', {'packages':['bar']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {
        var data = google.visualization.arrayToDataTable([
            ['Scans', '<?=implode("','",array_values($chartCrit))?>'],
            ['Overall Score', <?=$chartData1?>],
        ]);

        var options = {
            chart: {
                title: '<?=strip_tags($agencyName)?> Compliance Report',
                subtitle: 'Average score of all <?=$totWebsites?> websites scanned',
            },
            colors: ['<?=implode("','",array_values($chartColors))?>'],
            legend: { position: "left" },
            bars: 'vertical',
            vAxis: {format: 'decimal'},
            width: '100%',
            height:250,
        };

        var chart = new google.charts.Bar(document.getElementById('columnchart_material'));

        chart.draw(data, google.charts.Bar.convertOptions(options));
    }
</script>
<div id="columnchart_material"></div>
<p><button id="link-all-reports"><a href="/website/all/reports">Complete List</a></button>
</p>