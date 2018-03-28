<div id="<?=$trend_vars['container']?>" style="min-width: 310px; height: 400px; margin: 0 auto"></div>

<script type="text/javascript">//<![CDATA[

    Highcharts.chart('<?=$trend_vars['container']?>', {
        colors: ['#2e8540','#f45b5b'],
        tooltip: {
            formatter: function()
            {
                if(this.y == '100')
                    return  'Compliant on '+this.x;
                else
                    return 'Non Compliant on '+this.x;

            }
        },
        chart: {
            type: 'column'
        },
        title: {
            text: 'Trend Analysis'
        },
        xAxis: {
            categories: <?php echo json_encode($trend_vars['dates']); ?>,
            labels: {
                rotation: 90
            }
        },
        yAxis: {
            labels:
            {
                enabled: false
            },
            title: {
                enabled: true,
                text: 'Compliance'
            }
        },
        credits: {
            enabled: false
        },
        series: [{
            name: 'Compliance',
          showInLegend: false,
          data: <?php echo json_encode($trend_vars['compliance']); ?>
        }, {
            name: 'Non Compliance',
            data: <?php echo json_encode($trend_vars['noncompliance']); ?>
        }]
    });

    //]]>

</script>