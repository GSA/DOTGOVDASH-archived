<?php global $base_url; ?>
<?php
$labeldesc['avg_https'] = 'HTTPS Score';
$labeldesc['avg_dap'] = 'DAP Score';
$labeldesc['avg_mob_overall'] = 'Mobile Overall Score';
$labeldesc['avg_mob_perform'] = 'Mobile Performance Score';
$labeldesc['avg_mob_usab'] = 'Mobile Usability Score';
$labeldesc['avg_sitespeed'] = 'Site Speed Score';
$labeldesc['avg_ipv6'] = 'IPv6 Score';
$labeldesc['avg_dnssec'] = 'DNSSEC Score';
$labeldesc['avg_rc4'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
$labeldesc['avg_m15'] = 'M-15-13 and BOD 18-01 Compliance Score';

$chartdata = $govwidedata['actualdata'];
$websitenos = $chartdata['websitenos'];
$agencynos = $chartdata['agencynos'];
unset($chartdata['websitenos']);
unset($chartdata['agencynos']);
foreach ($chartdata as $key => $val) {
    $chartseries1 .= "{\"name\":\"$labeldesc[$key]\",\"y\":" . (int) $val . ",\"showInLegend\":true},";
}
$chartseries = array_values($chartdata);
?>

<?php
drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
?>
<div  class="main-govwidecontents">
    <div class="content-wrap">
        <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
            <p><span style="font-size:16px;text-align:center;">About</span><br/>This page reports the total overall government data captured in a virtual way. You can see healths of all government websites for each criteria for which we score</p>
        </div>
        <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
            <img src="<?php echo $base_url; ?>/sites/all/modules/custom/dotgov_common/images/gov-wide-report-logo.png " alt="Govwide Report" style="width:100px; height:100px;"/>
        </div>
        <div class="col-lg-4 col-sm-12 col-xs-12 text-center" style="margin-top:30px;">
            <?php echo "Total Agencies: ". $agencynos . "<br>"; ?>
            <?php echo "Total Domain: " . $websitenos ."<br>"; ?>
        </div>
    </div>
</div>
<div class="main-govwidechart">
    <div class="view view-all-agency-data view-id-all_agency_data view-display-id-page_5 white-back view-dom-id-b562269ee2f951e205ff4aa51b8a3ac0 custom-tpl-code">
        <div class="view-content">
            <div id="govwidechart"  style="min-width: 300px; min-height: 300px; margin: 0 auto"></div>
            <script type="text/javascript">//<![CDATA[
                Highcharts.chart('govwidechart', {
                    chart: {
                        type: 'column'
                    },
                    title: {
                        text: ''
                    },
                    xAxis: {
                        //categories: ['HTTPS Score', 'DAP Score', 'Mobile Overall Score', 'Mobile Performance Score', 'Mobile Usability score', 'Site Speed Score', 'IPv6 Score', 'DNSSEC Score', 'Free for RC4/3DES & SSLv2/SSLv3 Score', 'M-15-13 and BOD 18-01 Compliance Score'],
                        labels: {
                            enabled: false,
                            rotation: 90
                        },
                        title: {
                            enabled: true,
                            text: 'Average of <?= $govwidedata['actualdata']['websitenos'] ?> Websites',
                            style: {
                                fontWeight: 'bold',
                                //color: 'black'
                                //(Highcharts.theme && Highcharts.theme.textColor) || 'gray'
                            }
                        }
                    },
                    yAxis: {
                        labels:
                        {
                            enabled: true
                        },
                        title: {
                            enabled: false,
                        }
                    },
                    credits: {
                        enabled: true
                    },
                    plotOptions: {
                        series: {
                            pointWidth: 30,
                            dataLabels: {
                                enabled: true,
                                inside: true,
                                color: 'blue',
                                align: 'center',
                            },
                            responsive: {
                                rules: [{
                                    condition: {
                                        maxWidth: 500
                                    },
                                    chartOptions: {
                                        legend: {
                                            align: 'center',
                                            verticalAlign: 'bottom',
                                            layout: 'horizontal'
                                        },
                                        yAxis: {
                                            labels: {
                                                align: 'left',
                                                x: 0,
                                                y: -5
                                            },
                                        },
                                        subtitle: {
                                            text: null
                                        },
                                    }
                                }]
                            }
                        }
                    },
                    series: [
                        {
                            name: 'HTTPS Score',
                        },
                        {
                            name: 'DAP Score',
                        },
                        {
                            name: 'Mobile Overall Score',
                        },
                        {
                            name: 'Mobile Performance Score',
                        },
                        {
                            name: 'Mobile Usability score',
                        },
                        {
                            name: 'Site Speed Score',
                        },
                        {
                            name: 'IPv6 Score',
                        },
                        {
                            name: 'DNSSEC Score',
                        },
                        {
                            name: 'Free for RC4/3DES & SSLv2/SSLv3 Score',
                        },
                        {
                            name: 'M-15-13 and BOD 18-01 Compliance Score',
                        },
                        {
                            name: 'Average of <?= $govwidedata['actualdata']['websitenos'] ?> Websites',
                            'colorByPoint': true,
                            // colors: ['#0e243a','#8bbd22','#900000','#1cadce','#482a6f','#f28e42','#76a0e6','#c42626','#a6ca6a','#000000'],
                            data: <?php echo "[" . $chartseries1 . "]"; ?>,
                            showInLegend: false,
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
                //]]></script>
        </div>
    </div>
    <div class="view-footer">
        <div class="field-content col-lg-12"><a href="<?php echo $base_url; ?>/content/scoring-methods" title="" data-toggle="tooltip" class="infor" data-original-title="Click Here to see the scoring methods used to calculate the scores"><i class="icon glyphicon glyphicon-info-sign"></i><span class="sr-only">information</span></a></div>
        <a id="link-all-reports" href="<?php echo $base_url; ?>/website/all/reports">Complete List </a>&nbsp;( Last scan date: <?= dotgov_common_lastScanDate() ?> )
    </div>
</div>
