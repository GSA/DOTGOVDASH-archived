<?php
drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
?>
<div id="<?=$trend_vars['container']?>"  style="min-width: 300px; min-height: 300px; margin: 0 auto"></div>

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
          data: <?php echo json_encode($trend_vars['compliance']); ?>
        }, {
            name: 'Non Compliance',
            data: <?php echo json_encode($trend_vars['noncompliance']); ?>
        }],
        lang: {
        noData: "No Data to Show"
    },
    noData: {
        style: {
            fontWeight: 'bold',
                fontSize: '15px',
                color: '#303030'
        }
    }
    });

    //]]>

</script>
