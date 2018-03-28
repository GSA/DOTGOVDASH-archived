<?php
dsm($trend_vars);
?>
<div id="<?=$trend_vars['container']?>" style="min-width: 300px; height: 150px; margin: 0 auto"></div>

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
      tickmarkPlacement: 'on',
      lineWidth: 0,
      minorGridLineWidth: 0,
      lineColor: 'transparent',
      minorTickLength: 0,
      tickLength: 0,
      title: {
        enabled: false
      },
      labels:{
        enabled:false//default is true
      }
    },
    yAxis: {
      gridLineColor: 'transparent',
      labels:{
        enabled:false//default is true
      },
      title: {
        enabled: false,
      },
    },
    tooltip: {
      split: true,
      valueSuffix: '%'
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
      name: 'Overall Score',
      data: <?php echo json_encode(array_values($trend_vars['moboverall'])); ?>
    }, {
      name: 'Usability Score',
      data: <?php echo json_encode(array_values($trend_vars['mobusab'])); ?>
    }, {
      name: 'Performance Score',
      data: <?php echo json_encode(array_values($trend_vars['mobperfrm'])); ?>
    }]
  });
</script>
