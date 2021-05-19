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
            ['On-Site Search Detected',     <?=$search_available?>],
            ['On-Site Search Not Detected',      <?=$search_notavailable?>],
        ]);
        var options = {
            colors: ['#29633a', '#ac0600'],
            backgroundColor: {fill:'transparent'},
            sliceVisibilityThreshold: 0,
            dataLabels: {
                enabled: true
            },
            showInLegend: true,
            chartArea:{height:'50%',width:'100%'},
            legend: 'left'
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechart3'));

        chart.draw(data, options);
    }
</script>

