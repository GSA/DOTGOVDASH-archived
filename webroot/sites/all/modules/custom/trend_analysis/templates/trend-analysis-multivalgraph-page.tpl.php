<?php
drupal_add_js("https://code.highcharts.com/modules/no-data-to-display.js");
if($trend_vars['blockname'] == 'trends_mobile_chart'){
    $charttitle = "Mobile Trend Analysis Chart";
    $series1name = 'Mobile Overall Score';
    $series2name = 'Mobile Performance Score';
    $series3name = 'Mobile Usability Score';
    $series1data = json_encode(array_values($trend_vars['moboverall']));
    $series2data = json_encode(array_values($trend_vars['mobperfrm']));
    $series3data = json_encode(array_values($trend_vars['mobusab']));
    $valuesuffix = '%';
}
elseif($trend_vars['blockname'] == 'trends_accessible_chart'){
    $charttitle = "Acessibility Trend Analysis Chart";
    $series1name = 'Color Contrast';
    $series2name = 'HTML Attributes';
    $series3name = 'Missing Images';
    $series1data = json_encode(array_values($trend_vars['col_contrast']));
    $series2data = json_encode(array_values($trend_vars['html_attrib']));
    $series3data = json_encode(array_values($trend_vars['miss_image']));
    $valuesuffix = ' Errors';
}
?>

<div id="<?=$trend_vars['container']?>" style="min-width: 300px; min-height: 300px; margin: 0 auto;"></div>
<script type="text/javascript">//<![CDATA[

    Highcharts.chart('<?=$trend_vars['container']?>', {
        chart: {
            type: 'area'
        },
        title: {
            text: ''
        },
        subtitle: {
            text: ''
        },
        xAxis: {
            categories: <?php echo json_encode($trend_vars['dates']); ?>,
            title: {
                enabled: false
            },
            labels:{
                rotation: 90
            }

        },
        yAxis: {
            labels:{
                enabled:false//default is true
            },
            title: {
                enabled: true,
            },
        },
        tooltip: {
            split: true,
            valueSuffix: '<?=$valuesuffix?>',
	    useHTML: true,
	},

        plotOptions: {
            area: {
                stacking: 'normal',
                lineColor: '#666666',
                lineWidth: 1,
                showInLegend: false,
                marker: {
                    lineWidth: 1,
                    lineColor: '#666666'
                }
            }
        },
        series: [{
            name: '<?=$series1name?>',
            data: <?php echo $series1data; ?>,
        }, {
            name: '<?=$series2name?>',
            data: <?php echo $series2data; ?>,
        },{
            name: '<?=$series3name?>',
            data: <?php echo $series3data; ?>
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
</script>

