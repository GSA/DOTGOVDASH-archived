<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($view->style_plugin->rendered_fields);
$chartData = "[\"Agency\", \"Average M-15-13 and BOD 18-01 compliance Score\", { role: \"style\" } ],";
$chartColors = array('#0071bc', '#e31c3d', '#00a6d2', '#fdb81e', '#48a463');
foreach($view->style_plugin->rendered_fields as $key=>$val){
    $chartData .= "[\"".$val['field_agency_code']."\",".$val['field_m15_13_compliance_score'].",\"".$chartColors[$key]."\"],";
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
            title: "Top 5 M-15-13 and BOD 18-01 Compliant Agencies",
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
        var chart = new google.visualization.ColumnChart(document.getElementById("columnchart_values17"));
        chart.draw(view, options);
    }
</script>
<div id="columnchart_values17"></div>
<div class="field-content col-lg-12 nopadding clearfix">
<div class="col-lg-6 col-xs-6 nopadding"><a href="/improve-my-score">&nbsp;</a></div>
<div class="col-lg-6 col-xs-6 nopadding"><a href="/content/scoring-methods" title="" data-toggle="tooltip" class="infor" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">Click Here to see the scoring methods used to calculate the scores</span></a></div></div>
<?php if (arg(2) == 'reports-data') print '<a class="btn btn-primary" href="/agency/all/m1513_bod_data">Complete List</a>';?>  (Last scan date: <?=dotgov_common_lastScanDate()?>)<div><br>*Only the Top Major Agencies are shown in the graph</div>
