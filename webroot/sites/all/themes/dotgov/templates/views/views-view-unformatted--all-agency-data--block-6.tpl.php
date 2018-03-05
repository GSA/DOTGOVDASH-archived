<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Agency\", \"Average DAP Score\", { role: \"style\" } ],";
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463');
foreach($view->style_plugin->rendered_fields as $key=>$val){
    $chartData .= "[\"".$val['field_agency_code']."\",".(int)($val['field_dap_score']?$val['field_dap_score']:0).",\"".$chartColors[$key]."\"],";
}
// echo $chartData;
// $chartData = "";
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
            title: "Top 5 DAP Compliant Agencies",
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
        var chart = new google.visualization.ColumnChart(document.getElementById("columnchart_values6"));
        chart.draw(view, options);
    }
</script>
<div id="columnchart_values6"></div>
<span class="field-content col-lg-12"><a href="/content/scoring-methods" title="" data-toggle="tooltip" class="infor" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">information</span></a></span>
<?php if (arg(2) == 'reports-data') print '<a id="link-all-reports" href="/agency/all/dap_data">Complete List</a>';?> (Last scan date: <?=dotgov_common_lastScanDate()?>)<div><br>*Only the Top 5 Performing Agencies are shown</div>
