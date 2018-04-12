<?php
drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
?>
<div id="<?=$trend_vars['container']?>" style="min-width: 100px; min-height: 60px; margin: 0 auto"></div>
<style>
    .highcharts-tooltip>span {
        height:10px;
        width:10px;
    }
</style>

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
