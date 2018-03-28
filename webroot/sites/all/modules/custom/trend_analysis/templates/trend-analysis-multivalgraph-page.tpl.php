<div id="<?=$trend_vars['container']?>" style="min-width: 310px; height: 400px; margin: 0 auto"></div>

<script type="text/javascript">//<![CDATA[


  Highcharts.chart('<?=$trend_vars['container']?>', {
    chart: {
      type: 'areaspline'
    },
    title: {
      text: 'Acessibility Trend Analyis Chart'
    },
    legend: {
      layout: 'vertical',
      align: 'left',
      verticalAlign: 'top',
      x: 150,
      y: 100,
      floating: true,
      borderWidth: 1,
      backgroundColor: (Highcharts.theme && Highcharts.theme.legendBackgroundColor) || '#FFFFFF'
    },
    xAxis: {
      categories: <?php echo json_encode($trend_vars['dates']); ?>,
      labels: {
        rotation: 90
      }
    },
    yAxis: {
      title: {
        text: 'Error units'
      }
    },
    tooltip: {
      shared: true,
      valueSuffix: ' Errors'
    },
    credits: {
      enabled: false
    },
    plotOptions: {
      areaspline: {
        fillOpacity: 0.5
      }
    },
    series: [{
      name: 'Color Contrast',
      data: <?php echo json_encode(array_values($trend_vars['col_contrast'])); ?>,
    }, {
      name: 'HTML Attributes',
      data: <?php echo json_encode(array_values($trend_vars['html_attrib'])); ?>,
    },{
      name: 'Missing Images',
      data: <?php echo json_encode(array_values($trend_vars['miss_image'])); ?>
    }]
  });
  //]]>

</script>