<?php
drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
$score_arr = array('trends_ssl','trends_https','trends_mobile_spark','agency_mob');
$agency_score_arr = array('agency_https','agency_dap','agency_dnssec','agency_ipv6','agency_m15','agency_rc4');
$agency_color_arr = array('agency_mob','agency_https','agency_dap','agency_dnssec','agency_ipv6','agency_m15','agency_rc4');
$negativecolor = '#ac0600';
$positivecolor = '#2a633b';
$threshold = '1';

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
if (in_array($trend_vars['blockname'],$agency_color_arr)) {
    $negativecolor = '#4d525a';
    $positivecolor = '#4d525a';
}
if (!empty($trend_vars['mobperfrm']) && is_array($trend_vars['mobperfrm'])) {
  $mobilePerf = array_slice($trend_vars['mobperfrm'], -5, 5);
  $mobilePerf = array_values($mobilePerf);
  $mobilePerf = array_map(function($value) {
    return $value === '' || $value === NULL ? -1 : (int) $value;
  }, $mobilePerf);
}

if (!empty($trend_vars['mobusab']) && is_array($trend_vars['mobusab'])) {
  $mobileUsab = array_slice($trend_vars['mobusab'], -5, 5);
  $mobileUsab = array_values($mobileUsab);
  $mobileUsab = array_map(function($value) {
    return $value === '' || $value === NULL ? -1 : (int) $value;
  }, $mobileUsab);
}

if (!empty($trend_vars['scandate'])) {
  $mobilePerfUsabScanDate = array_values(array_slice($trend_vars['scandate'], -5, 5));
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

<?php if($trend_vars['blockname'] == 'trends_mobile_spark'): ?>
    <div id="<?=$trend_vars['container']?>" style="min-width: 150px; height: 200px; margin: 0 auto"></div>
<?php else: ?>
    <div id="<?=$trend_vars['container']?>" style="min-width: 150px; height: 40px; margin: 0 auto"></div>
<?php endif; ?>

<script type="text/javascript">
//<![CDATA[
    <?php if($trend_vars['blockname'] == 'trends_mobile_spark'): ?>
        Highcharts.chart("<?=$trend_vars['container']?>", {
          chart: {
            type: 'column'
          },
          title: {
            text: ''
          },
          subtitle: {
            text: ''
          },
          xAxis: {
            categories: <?php print json_encode($mobilePerfUsabScanDate); ?>,
            crosshair: true
          },
          yAxis: {
            min: 0,
            max: 100,
            title: {
              text: 'Score (%)'
            }
          },
          tooltip: {
            formatter: function() {
              var s = '<span style="font-size:10px">' + this.x + '</span><table>';
              var scoreVal;
              jQuery.each(this.points, function(i, point) {
                if (point.y == -1) {
                  scoreVal = 'NA';
                } else {
                  scoreVal = point.y;
                }
                  s += '<tr><td style="color:' + point.color + ';padding:0">' + point.series.name + ':&nbsp;</td>' + '<td style="padding:0"><b>' + scoreVal + '</b></td></tr>';
              });
              return s += '</table>';
            },
            shared: true,
            useHTML: true
          },
          plotOptions: {
            column: {
              pointPadding: 0.2,
              borderWidth: 0
            }
          },
          series: [{
            name: 'Performance',
            data: <?php print json_encode($mobilePerf);?>
        
          }, {
            name: 'Usability',
            data: <?php print json_encode($mobileUsab);?>
        
          }]
        });
    <?php else: ?>
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
                    formatter: function() {
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
          
            <?php if (in_array($trend_vars['blockname'],$agency_score_arr)): ?>
                tooltip: {
                    formatter: function(){
                        if(this.y == -1)
                            return '<span style="font-size:10px">' + this.x + '</span><br><table> <tr><td>Score: <b>0%</b></td></tr></table>';
                        else
                        return '<span style="font-size:10px">' + this.x + '</span><br><table> <tr<td>Score: <b>' + this.y + '%</b></td></tr></table>';
                    }
                },
            <?php elseif($trend_vars['blockname'] == 'trends_mobile_spark'): ?>
                tooltip: {
                    formatter: function() {
                        if(this.y == -1)
                            return 'On '+this.x+' was Not Available';
                        else
                            return 'On '+this.x+' Score was '+this.y;
                    }
                },
            <?php elseif (!in_array($trend_vars['blockname'],$score_arr)): ?>
                tooltip: {
                    formatter: function() {
                        if(this.y == -1)
                            return 'On '+this.x+' was Not Compliant';
                        else if(this.y == '0')
                            return 'On '+this.x+' was Not Available';
                        else
                            return 'On '+this.x+' was Compliant';
                    }
                },
            <?php endif; ?>
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
    <?php endif; ?>
//]]>
</script>