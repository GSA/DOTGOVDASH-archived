<!--<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>-->
<script language="JavaScript">
    google.charts.load('current', {'packages':['corechart']});
    google.charts.setOnLoadCallback(drawChart1);

    function drawChart1() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            ['Mobile Friendly',     <?php echo number_format($govwidedata['mob_usab_friendly_nos'],1, '.', '');?>],
            ['Not Mobile Friendly',      <?php echo number_format($govwidedata['mob_perf_improve_nos'],1, '.', '');?>],
        ])
        var options = {
            colors: ['#276437','#ae0100'],
            sliceVisibilityThreshold: 0,
            legend: {position: 'none'},
            backgroundColor: { fill:'transparent' },
            pieSliceText: 'none',
            dataLabels: {
                enabled: false
            },
            showInLegend: false,
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechartusab'));

        chart.draw(data, options);
    }
</script>
