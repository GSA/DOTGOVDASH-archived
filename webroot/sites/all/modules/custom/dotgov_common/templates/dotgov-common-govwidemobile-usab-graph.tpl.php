<!--<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>-->
<script language="JavaScript">
    google.charts.load('current', {'packages':['corechart']});
    google.charts.setOnLoadCallback(drawChart1);

    function drawChart1() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            ['Mobile Friendly',     <?php echo number_format($govwidedata['mob_usab_friendly_nos'],1, '.', '');?>],
            ['Not Mobile Friendly',      <?php echo number_format($govwidedata['mob_usab_notfriendly_nos'],1, '.', '');?>],
            ['NA',  <?php echo number_format($govwidedata['usab_null'],1, '.', ''); ?>],

        ])
        var options = {
            colors: ['#276437','#ae0100','#66746a'],
            sliceVisibilityThreshold: 0,
            legend: {position: 'none'},
            backgroundColor: { fill:'transparent' },
            pieSliceText: 'percentage',
            dataLabels: {
                enabled: false
            },
            showInLegend: false,
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechartusab'));

        chart.draw(data, options);
    }
</script>