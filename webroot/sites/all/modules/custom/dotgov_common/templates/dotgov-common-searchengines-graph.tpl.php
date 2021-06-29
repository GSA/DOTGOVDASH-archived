<?php
if(trim($search_engine_data_for_agencygraph) == "")
  $search_engine_data_for_agencygraph = "0,0";
?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script language="JavaScript">
    google.charts.load('current', {packages: ['corechart', 'bar']});
    google.charts.setOnLoadCallback(drawBasic);

    function drawBasic() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            <?=$search_engine_data_for_agencygraph?>
        ]);

        var options = {
            colors: ['#3f51b5', '#337ab7', '#ffc107', '#7cb5ec', '#795548', '#009688','#f44336'],
            backgroundColor: {fill:'transparent'},
            chartArea: {width: '100%'},
            hAxis: {
                minValue: 0
            }
        };

        var chart = new google.visualization.BarChart(document.getElementById('piechart2'));

        chart.draw(data, options);
    }
</script>
