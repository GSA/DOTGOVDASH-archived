<!--<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>-->
<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart1);

function drawChart1() {

var data = google.visualization.arrayToDataTable([
['Type', 'Number'],
['Bad',     <?php echo number_format($govwidedata['govwide_mob_bad'],1, '.', '');?>],
['Average',      <?php echo number_format($govwidedata['govwide_mob_avg'],1, '.', '');?>],
['Good',  <?php echo number_format($govwidedata['govwide_mob_good'],1, '.', ''); ?>]
]);
var options = {
    colors: ['#ae0100', '#665000','#276437'],
    sliceVisibilityThreshold: 0,
    legend: {position: 'none'},
    backgroundColor: { fill:'transparent' },
    pieSliceText: 'label',
    dataLabels: {
        enabled: false
    },
    showInLegend: false,
    tooltip:{trigger:'selection'}
};

    var chart = new google.visualization.PieChart(document.getElementById('piechart1'));
    google.visualization.events.addListener(chart, 'ready', function(e) {
        chart.setSelection([{row:2,column:null}]);
    });
    chart.draw(data, options);

}
</script>
