<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Agency\", \"Average SSL Score\", { role: \"style\" } ],";
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463');
foreach($view->style_plugin->rendered_fields as $key=>$val){
    $chartData .= "[\"".$val['field_agency_code']."\",".$val['field_ssl_score'].",\"".$chartColors[$key]."\"],";
}
?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">
    google.charts.load("current", {packages:['corechart']});
    google.charts.setOnLoadCallback(drawChart);
    window.onload = drawChart();
    window.onresize = drawChart;
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
            title: "Top SSL Compliant Agencies",
            bar: {groupWidth: "95%"},
            legend: { position: "top" },
        };
        var chart = new google.visualization.ColumnChart(document.getElementById("columnchart_values4"));
        chart.draw(view, options);
    }
</script>
<button id="link-all-reports"><a href="/agency/all/data/ssl">Complete List</a></button>
<div id="columnchart_values4" style="width: 900px; height: 300px;"></div>
<p><br><br><br><br><br><br><br><br></p>