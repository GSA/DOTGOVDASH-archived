<?php
$score_arr = array('trends_ssl','trends_https');
if (in_array($trend_vars['blockname'],$score_arr)){
  $compliancetext = 'Score';
}
else{
  $compliancetext = 'Compliance';
}
?>
<div id="<?=$trend_vars['container']?>" style="min-width: 150px; height: 50px; margin: 0 auto"></div>

<script type="text/javascript">//<![CDATA[

  Highcharts.chart('<?=$trend_vars['container']?>', {
    chart: {
          type: 'area'
        },
    title: {
      useHTML: true,
      text: '',
      x: 0,
    },
        credits: {
          enabled: false
        },
    xAxis: {
      tooltip: {
        formatter: function()
        {
return 'Compliance';
        }
      },
      lineWidth: 0,
      minorGridLineWidth: 0,
      lineColor: 'transparent',
      minorTickLength: 0,
      tickLength: 0,
      labels:{
        enabled:false//default is true
      },
      title: {
        enabled: false,
      },
        categories: <?php echo json_encode($trend_vars['dates']); ?>,
      },
    yAxis: {
      gridLineColor: 'transparent',
      labels:{
        enabled:false//default is true
      },
      title: {
        enabled: false,
        rotation: 0,
      }
    },
      series: [{
        tooltip: {
          formatter: function()
          {
            return 'Compliance';
          }
        },
      threshold: 0,
      negativeColor: 'red',
      color: 'green',
      type: 'area',
        name: '<?=$compliancetext?>',
        showInLegend: false,
        data: <?php echo json_encode($trend_vars['compliance'],JSON_NUMERIC_CHECK); ?>

    }]
      });
    //]]>

  </script>




