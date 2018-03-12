<div id="<?=$trend_vars['container']?>" style="min-width: 310px; height: 400px; margin: 0 auto"></div>

<script type="text/javascript">//<![CDATA[

    Highcharts.chart('<?=$trend_vars['container']?>', {
        chart: {
            type: 'column'
        },
        title: {
            text: 'Trend Analysis'
        },
        xAxis: {
            categories: <?php echo json_encode($trend_vars['dates']); ?>
        },
        yAxis: {
            labels:
            {
                enabled: false
            }
        },
        credits: {
            enabled: false
        },
        series: [{
            name: 'Compliance',
            data: <?php echo json_encode($trend_vars['compliance']); ?>
        }, {
            name: 'Non Compliance',
            data: <?php echo json_encode($trend_vars['noncompliance']); ?>
        }]
    });

    //]]>

</script>