<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart1);

function drawChart1() {

    var data = google.visualization.arrayToDataTable([
        ['Type', 'Number'],
        ['Poor',  <?php echo number_format($agencydata['mob_perf_poor_nos'],1, '.', ''); ?>],
        ['Need Improvement',      <?php echo number_format($agencydata['mob_perf_improve_nos'],1, '.', '');?>],
        ['Good',  <?php echo number_format($agencydata['mob_perf_good_nos'],1, '.', ''); ?>],
        ['NA',  <?php echo number_format($agencydata['null'],1, '.', ''); ?>]

    ]);
    var options = {
        colors: ['#ae0100', '#665000','#276437','#66746a'],
        sliceVisibilityThreshold: 0,
        legend: {position: 'none'},
        backgroundColor: { fill:'transparent' },
        pieSliceText: 'percentage',
        dataLabels: {
            enabled: false
        },
        showInLegend: false,
    };
var chart = new google.visualization.PieChart(document.getElementById('piechartmob'));

chart.draw(data, options);
}
</script>
