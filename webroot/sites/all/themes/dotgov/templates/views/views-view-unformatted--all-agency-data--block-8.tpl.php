<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Agency\", \"Average Mobile Performance Score\", { role: \"style\" } ],";
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463');
foreach($view->style_plugin->rendered_fields as $key=>$val){
    $chartData .= "[\"".$val['field_agency_code']."\",".$val['field_mobile_performance_score'].",\"".$chartColors[$key]."\"],";
}
?>
<script type="text/javascript">
    google.charts.load("current", {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);
    function drawChart() {
        var data = google.visualization.arrayToDataTable([
            <?=$chartData?>
        ]);

        var view = new google.visualization.DataView(data);
        view.setColumns([0, 1,
            { calc: "stringify",
                sourceColumn: 1,
                type: "string",
                role: "annotation" },
            2]);

        var options = {
            title: "Top 5 Agencies with Fastest Mobile Sites",
            width: '100%',
            height:250,
            bar: {groupWidth: "95%"},
            legend: { position: "top" },
vAxis: {  viewWindow: {
            min:0,
	    max:100
        }
}

        };
        var chart = new google.visualization.ColumnChart(document.getElementById("columnchart_values8"));
        chart.draw(view, options);
    }
</script>
<div id="columnchart_values8" ></div>
<span class="field-content col-lg-12"><a href="/content/scoring-methods" title="" data-toggle="tooltip" class="infor" ''="" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">information</span></a></span>
<a id="link-all-reports" href="/agency/all/mobile_data">Complete List</a> (Last scan date: <?=dotgov_common_lastScanDate()?>)
