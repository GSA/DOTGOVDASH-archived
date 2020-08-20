<!--<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>-->
<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart1);

function drawChart1() {

    var data = google.visualization.arrayToDataTable([
        ['Type', 'Number'],
        ['Poor',   <?php echo number_format($govwidedata['mob_perf_poor_nos'],1, '.', '');?>],
        ['Needs Improvement', <?php echo number_format($govwidedata['mob_perf_improve_nos'],1, '.', '');?>],
        ['Good',  <?php echo number_format($govwidedata['mob_perf_good_nos'],1, '.', ''); ?>],
        //['NA',  <?php //echo number_format($govwidedata['null'],1, '.', ''); ?>//],
    ]);
    var options = {
        colors: ['#ae0100', '#665000','#276437'],
        sliceVisibilityThreshold: 0,
        legend: {position: 'none'},
        backgroundColor: { fill:'transparent' },
        pieSliceText: 'percentage',
        dataLabels: {
            enabled: false
        },
        showInLegend: false,
        chartArea:{left:0,top:20,width:'100%',height:'70%'},
    };

var chart = new google.visualization.PieChart(document.getElementById('piechart1'));

chart.draw(data, options);
}
</script>
