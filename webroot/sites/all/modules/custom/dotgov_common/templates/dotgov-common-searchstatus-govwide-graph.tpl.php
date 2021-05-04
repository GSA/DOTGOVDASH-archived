<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script language="JavaScript">
    google.charts.load('current', {'packages':['corechart']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

        var data = google.visualization.arrayToDataTable([
            ['Type', 'Number'],
            ['Search Available',     <?=$agencydata['search_available']?>],
            ['Search Not Available',      <?=$agencydata['search_notavailable']?>],
        ]);
        var options = {
            title: 'Search Engine Status Breakdown',
            colors: ['#4caf50', '#f44336'],
            backgroundColor: {fill:'transparent'},
            sliceVisibilityThreshold: 0,
            dataLabels: {
                enabled: true
            },
            showInLegend: true,
            legend: 'none'
        };

        var chart = new google.visualization.PieChart(document.getElementById('piechart3'));

        chart.draw(data, options);
    }
</script>
