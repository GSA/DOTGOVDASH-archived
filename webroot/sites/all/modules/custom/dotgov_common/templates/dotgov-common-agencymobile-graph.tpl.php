<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart1);

function drawChart1() {

    var data = google.visualization.arrayToDataTable([
        ['Type', 'Number'],
        ['Good',  <?php echo number_format($agencydata['mob_perf_good_nos'],1, '.', ''); ?>],
        ['Needs Improvement',      <?php echo number_format($agencydata['mob_perf_improve_nos'],1, '.', '');?>],
        ['Poor',  <?php echo number_format($agencydata['mob_perf_poor_nos'],1, '.', ''); ?>],
    ]);
    var options = {
        colors: ['#276437', '#665000','#ae0100', '#337ab7'],
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
var chart = new google.visualization.PieChart(document.getElementById('piechartmob'));

chart.draw(data, options);
}
</script>
