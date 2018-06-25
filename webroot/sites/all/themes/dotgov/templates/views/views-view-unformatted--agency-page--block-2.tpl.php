<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Scan Criteria\", \"Overall Report\", { role: \"style\" } ],";
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463','#5b616b','#9e3131','#e59393');
$chartCrit = array("field_dap_score"=>"DAP","field_https_score"=>"HTTPS","field_mobile_overall_score"=>"MOBILE","field_mobile_performance_score"=>"MOBILE PERFORMANCE","field_mobile_usability_score"=>"MOBILE FRIENDLY","field_dnssec_score"=>'DNSSEC',"field_ipv6_score"=>"IPv6","field_site_speed_score"=>"SITE SPEED");
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
$chartCritval = array_values($chartCrit);

?>
<script type="text/javascript">
    google.charts.load('current', {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {
        var data = google.visualization.arrayToDataTable([
            ['Scans', '<?=implode("','",$chartCritval)?>'],
            ['Overall Score', <?=$chartData1?>],
        ]);



        var options = {
            chartArea: {
                left: '15%',
                top: 10,
                bottom: 5,
                width: '40%',
                height: '100%'
            },

            colors: ['<?=implode("','",array_values($chartColors))?>'],
            legend: { position: 'right' },
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
</script>
<div class="row ">
    <div class="col-xs-12">
        <h3><?=strip_tags($agencyName)?></h3>
        <p>Average score of all <?=$totWebsites?> websites scanned</p>
        <div id="columnchart_material"></div>
        <a href="/mywebsites" id="link-all-reports">Complete List</a> (Last Scan Date: <?=dotgov_common_lastScanDate()?>)</div>
    <span class="field-content col-lg-12"><a href="/content/scoring-methods" title="" data-toggle="tooltip" class="infor" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">Click Here to see the scoring methods used to calculate the scores</span></a></span>
</div>
