<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart);

function drawChart() {

var data = google.visualization.arrayToDataTable([
['Type', 'Number'],
['Bad',     <?php echo number_format($agencydata['agency_mob_bad'],1, '.', '');?>],
['Average',      <?php echo number_format($agencydata['agency_mob_avg'],1, '.', '');?>],
['Good',  <?php echo number_format($agencydata['agency_mob_good'],1, '.', ''); ?>]
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
};

var chart = new google.visualization.PieChart(document.getElementById('piechart1'));

chart.draw(data, options);
}
</script>
