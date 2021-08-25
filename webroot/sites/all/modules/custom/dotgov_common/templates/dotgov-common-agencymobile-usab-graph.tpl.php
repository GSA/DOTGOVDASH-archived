<!--<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>-->
<script language="JavaScript">
    google.charts.load('current', {'packages':['corechart']});
    google.charts.setOnLoadCallback(drawChart1);

    function drawChart1() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            ['Mobile Friendly',     <?php echo number_format($agencydata['mob_usab_friendly_nos'],1, '.', '');?>],
            ['Not Mobile Friendly',      <?php echo number_format($agencydata['mob_usab_notfriendly_nos'],1, '.', '');?>],
        ])
        var options = {
            colors: ['#276437', '#ae0100', '#337ab7'],
            sliceVisibilityThreshold: 0,
            legend: {position: 'none'},
            backgroundColor: { fill:'transparent' },
            pieSliceText: 'percentage',
            dataLabels: {
                enabled: false
            },
            chartArea:{left:0,top:20,width:'100%',height:'70%'},
            showInLegend: false,
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechartmobusab'));

        chart.draw(data, options);
    }
</script>
