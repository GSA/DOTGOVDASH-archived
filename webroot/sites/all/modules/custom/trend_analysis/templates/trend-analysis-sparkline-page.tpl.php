<?php
drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
$score_arr = array('trends_ssl','trends_https','trends_mobile_spark');
$negativecolor = '#ac0600';
$positivecolor = '#2a633b';
$threshold = '0';

if (in_array($trend_vars['blockname'],$score_arr)){
    $compliancetext = 'Score';
    $negativecolor = '#ac0600';
    $positivecolor = '#4d525a';
}
else{
    $compliancetext = 'Compliance';
    $negativecolor = '#ac0600';
    $positivecolor = '#2a633b';
}
//if (in_array($trend_vars['blockname'],$score_arr)){
//  $compliancetext = 'Score';
//    $threshold = '75';
//    if((end($trend_vars['compliance']) <= '75') && (end($trend_vars['compliance']) > '50')){
//        $threshold = '50';
//        $negativecolor = '#ac0600';
//        $positivecolor = '#654f00';
//    }
//    elseif(end($trend_vars['compliance']) <= '50'){
//        $negativecolor = '#ac0600';
//    }
//}
//else{
//  $compliancetext = 'Compliance';
//    $threshold = '0';
//}
?>
<div id="<?=$trend_vars['container']?>" style="min-width: 150px; height: 50px; margin: 0 auto"></div>

<script type="text/javascript">//<![CDATA[

  Highcharts.chart('<?=$trend_vars['container']?>', {
    chart: {
          type: 'area',
	events: {
            load: function(){
                var p = this.series[0].points[<?=(count($trend_vars['compliance'])-1)?>];
                this.tooltip.refresh(p);
            }
        }
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
<?php
      if (!in_array($trend_vars['blockname'],$score_arr)){
      ?>
      tooltip: {
          formatter: function()
          {
              if(this.y == 0 || this.y == -1)
                  return 'On '+this.x+' was Not Compliant';
              else
                  return 'On '+this.x+' was Compliant';
          }
      },
      <?php } ?>
      series: [{
      threshold: <?=$threshold?>,
      negativeColor: '<?=$negativecolor?>',
      color: '<?=$positivecolor?>',
      type: 'area',
        name: '<?=$compliancetext?>',
        showInLegend: false,
        data: <?php echo json_encode($trend_vars['compliance'],JSON_NUMERIC_CHECK); ?>,
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
