<?php
if(isset($agencydata['search_available']))
  $search_available = $agencydata['search_available'];
else
  $search_available = 0;
if(isset($agencydata['search_notavailable']))
  $search_notavailable = $agencydata['search_notavailable'];
else
  $search_notavailable = 0;
?>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script language="JavaScript">
    google.charts.load('current', {'packages':['corechart']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            ['Search Available',     <?=$search_available?>],
            ['Search Not Available',      <?=$search_notavailable?>],
        ]);
        var options = {
            title: 'Search Engine Status Breakdown',
            colors: ['#4caf50', '#f44336'],
            sliceVisibilityThreshold: 0,
            dataLabels: {
                enabled: true
            },
            showInLegend: true,
            legend: 'none'
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechart3'));

        chart.draw(data, options);
    }
</script>
