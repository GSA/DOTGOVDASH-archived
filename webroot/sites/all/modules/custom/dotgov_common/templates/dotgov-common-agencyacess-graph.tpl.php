<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script language="JavaScript">
google.charts.load('current', {'packages':['corechart']});
google.charts.setOnLoadCallback(drawChart);

function drawChart() {

var data = google.visualization.arrayToDataTable([
['Type', 'Number'],
['Color Contrast Issues',     <?php echo number_format($agencydata['ag_col_contrast'],1, '.', '');?>],
['HTML Attribute Issues',      <?php echo number_format($agencydata['ag_html_attrib'],1, '.', '');?>],
['Missing Image Description Issues',  <?php echo number_format($agencydata['ag_miss_image'],1, '.', ''); ?>]
]);
var options = {
title: 'Accessibility Issue Breakdown',
    colors: ['#7cb5ec', '#90ed7d', '#434348'],
    sliceVisibilityThreshold: 0,
    dataLabels: {
        enabled: true
    },
    showInLegend: true
};

var chart = new google.visualization.PieChart(document.getElementById('piechart'));

chart.draw(data, options);
}
</script>
