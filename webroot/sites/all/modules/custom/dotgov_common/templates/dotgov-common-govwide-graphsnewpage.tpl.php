<?php
global $base_url;

drupal_add_js("/sites/all/libraries/highcharts/modules/no-data-to-display.js");
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


$no_of_agency = $govwidedata['actualdata']['agencynos'];
$agency_website_num = $govwidedata['actualdata']['websitenos'];
$agency_dap_score = $govwidedata['actualdata']['avg_dap'];
$agency_https_score = $govwidedata['actualdata']['avg_https'];
$agency_mobovr_score = $govwidedata['actualdata']['avg_mob_overall'];
$agency_mobperf_score = $govwidedata['actualdata']['avg_mob_perform'];
$agency_mobusab_score = $govwidedata['actualdata']['avg_mob_usab'];
$agency_dnssec_score = $govwidedata['actualdata']['avg_dnssec'];
$agency_ipv6_score = $govwidedata['actualdata']['avg_ipv6'];
$agency_insecprot_score = $govwidedata['actualdata']['avg_rc4'];
$agency_m15_score = $govwidedata['actualdata']['avg_m15'];

$agencydata = dotgov_common_getAllAgencyComplianceData();
dotgov_common_tooltip("tooltip2","id");
dotgov_common_tooltip("tooltip4","id");
dotgov_common_tooltip("tooltip3","id");
dotgov_common_tooltip("tooltip5","id");
dotgov_common_tooltip("tooltip7","id");
dotgov_common_tooltip("tooltip6","id");
dotgov_common_tooltip("tooltip9","id");
dotgov_common_tooltip("tooltip8","id");
?>
<?php //print_r($govwidedata);print_r($agencydata);  ?>

<div class="row">
    <div class="col-sm-12">
        <div class="graph-container">
            <div class="panel-display pond clearfix ">
                <div class="pond-container pond-secondary-column-content pond-column-content-row2 clearfix">
                    <div class="pond-secondary-column-content-region pond-column pond-secondary-column1 panel-panel">
                        <div class="pond-secondary-column-content-region-inner pond-column-inner pond-secondary-column1-inner panel-panel-inner">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> HTTPS Information </h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip2" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i> <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>

    HTTPS Data is collected through a custom scanner component of digital dashboard that last ran on
                                            <?php dotgov_common_lastScanDate(); ?>
    </span> </div>
                                </div>                                <div class="pane-content">
                                    <div class="view-wrapper">
                                        <div class="row">
                                            <div class="col-md-12 col-lg-12">HTTPS Overall Average Score : <?php echo $agency_https_score ?>%</div>
                                        </div>
                                        <div class="row">
                                            <div class="col-sm-12 col-lg-6">
                                                <?php
                                                $blockObject3 = block_load('trend_analysis', 'agency_https');
                                                $block3 = _block_get_renderable_array(_block_render_blocks(array($blockObject3)));
                                                $output3 = drupal_render($block3);
                                                print "$output3 <br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly HTTPS Trend</span>";
                                                ?>
                                            </div>
                                            <div class="col-sm-12 col-lg-6">
                                                <div id="https_chart">&nbsp;</div>
                                                <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                <script type="text/javascript">
                                                    Highcharts.chart('https_chart', {
                                                        chart: {
                                                            type: 'solidgauge',
                                                        },
                                                        title: {
                                                            text: ''
                                                        },
                                                        tooltip: {
                                                            enabled: false,
                                                        },
                                                        pane: {
                                                            startAngle: 0,
                                                            endAngle: 360,
                                                            background: [{
                                                                outerRadius: '118%',
                                                                innerRadius: '80%',
                                                                backgroundColor: '#d6d7d9',
                                                                borderWidth: 0
                                                            }]
                                                        },

                                                        yAxis: {
                                                            min: 0,
                                                            max: 100,
                                                            lineWidth: 0,
                                                            tickPositions: [],

                                                            title: {
                                                                text: '<?php echo $agency_https_score; ?> %',
                                                                style: {
                                                                    fontSize: '22px',
                                                                    color: '<?php echo dotgov_common_getChartColor($agency_https_score); ?>'
                                                                },
                                                                y: 30
                                                            },

                                                        },
                                                        plotOptions: {
                                                            solidgauge: {
                                                                dataLabels: {
                                                                    enabled: false
                                                                },
                                                                linecap: 'round',
                                                                stickyTracking: false,
                                                                rounded: true
                                                            }
                                                        },
                                                        series: [{
                                                            name: 'Free of Insecure Protocol Chart',
                                                            data: [{
                                                                color: '<?php echo dotgov_common_getChartColor($agency_https_score); ?>',
                                                                radius: '118%',
                                                                innerRadius: '80%',
                                                                y: <?php echo trim($agency_https_score); ?>
                                                            }]
                                                        }]
                                                    });
                                                </script>
                                            </div>
                                        </div>
                                        <table width="100%">

                                            <th style="background-color: #215393;color: white;">Criteria</th>
                                            <th style="background-color: #215393;color: white">Supporting Websites </th>
                                            <th style="background-color: #215393;color: white">&nbsp;Non Supporting Websites </th>
                                            <tr>
                                                <td>Enforce HTTPS</td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['enfhttps_support'], $agency_website_num, '#29643a') ?></td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['enfhttps_nosupport'], $agency_website_num, '#ac0600') ?></td>
                                            </tr>
                                            <tr>
                                                <td>HSTS Status</td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['hsts_support'], $agency_website_num, '#29643a') ?></td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['hsts_nosupport'], $agency_website_num, '#ac0600') ?></td>
                                            </tr>
                                            <tr>
                                                <td>HTTPS Status</td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['https_support'], $agency_website_num, '#29643a') ?></td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['https_nosupport'], $agency_website_num, '#ac0600') ?></td>
                                            </tr>
                                            <tr>
                                                <td>Preload Status</td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['preload_support'], $agency_website_num, '#29643a') ?></td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['preload_nosupport'], $agency_website_num, '#ac0600') ?></td>
                                            </tr>
                                            <tr>
                                                <td>Preload Ready</td>
                                                <td align="center"><?php echo dotgov_common_applyDataColor($agencydata['preload_readysupport'], $agency_website_num, '#29643a') ?></td>
                                                <td align="center">NA</td>
                                            </tr>
                                        </table>
                                    </div>
                                    <div class="view-button"><br>
                                        <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">DAP Information</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip3" class="infor">
                                        <i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left">
          <img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code"><br>
			DAP Overall Average Score :
                                            <?= $agency_dap_score ?>%
        </span>
                                    </div>
                                </div>
                                <div class="pane-content">
                                    <div class="view-wrapper" style="min-height:359px;">
                                        <div class="view  view-display-id-block_4 view-dom-id-6181bfbb91a57a13154a09c584b98ec8">
                                            <div class="view-content">
                                                <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                    <div class="views-field views-field-php"> <span class="field-content col-lg-12"> </span> </div>
                                                    <div class="views-field views-field-nothing clearfix">
                                                        <div class="field-content col-lg-12">
                                                            <p>DAP Overall Average Score : <?php echo $agency_dap_score ?>%</p>
                                                            <div class = "col-xs-12-col-sm-12 col-lg-6">
                                                                <?php
                                                                $blockObject6 = block_load('trend_analysis', 'agency_dap');
                                                                $block6 = _block_get_renderable_array(_block_render_blocks(array($blockObject6)));
                                                                $output6 = drupal_render($block6);
                                                                print "$output6 <br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly DAP Trend</span>";
                                                                ?>
                                                            </div>
                                                            <div class = "col-xs-12-col-sm-12 col-lg-6">
                                                                <div id="dap_chart">&nbsp;</div>
                                                                <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                <script type="text/javascript">
                                                                    Highcharts.chart('dap_chart', {
                                                                        chart: {
                                                                            type: 'solidgauge',
                                                                        },
                                                                        title: {
                                                                            text: ''
                                                                        },
                                                                        tooltip: {
                                                                            enabled: false,
                                                                        },
                                                                        pane: {
                                                                            startAngle: 0,
                                                                            endAngle: 360,
                                                                            background: [{
                                                                                outerRadius: '118%',
                                                                                innerRadius: '80%',
                                                                                backgroundColor: '#d6d7d9',
                                                                                borderWidth: 0
                                                                            }]
                                                                        },
                                                                        yAxis: {
                                                                            min: 0,
                                                                            max: 100,
                                                                            lineWidth: 0,
                                                                            tickPositions: [],
                                                                            title: {
                                                                                text: '<?php echo $agency_dap_score; ?> %',
                                                                                style: {
                                                                                    fontSize: '22px',
                                                                                    color: '<?php echo dotgov_common_getChartColor($agency_dap_score); ?>'
                                                                                },
                                                                                y: 30
                                                                            },

                                                                        },
                                                                        plotOptions: {
                                                                            solidgauge: {
                                                                                dataLabels: {
                                                                                    enabled: false
                                                                                },
                                                                                linecap: 'round',
                                                                                stickyTracking: false,
                                                                                rounded: true
                                                                            }
                                                                        },
                                                                        series: [{
                                                                            name: 'DAP Chart',
                                                                            data: [{
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_dap_score); ?>',
                                                                                radius: '118%',
                                                                                innerRadius: '80%',
                                                                                y: <?php echo trim($agency_dap_score); ?>
                                                                            }]
                                                                        }]
                                                                    });
                                                                </script>
                                                            </div>
                                                            <table style="width:100%;">

                                                                <th style="background-color: #215393;color: white;border: 1px;"> Breakdown </th>
                                                                <th style="background-color: #215393;color: white;border: 1px;"> Websites </th>
                                                                <tr>
                                                                    <td> DAP Compliant Websites<font style="font-size: larger;font-color:blue;">*</font></td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['dap_compliant'], $agencydata['dap_tottracked'], '#29643a') ?></td>
                                                                </tr>
                                                                <tr>
                                                                    <td>DAP Non Compliant Websites<font style="font-size: larger;font-color:blue;">*</font></td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['dap_noncompliant'], $agencydata['dap_tottracked'], '#ac0600') ?></td>
                                                                </tr>
                                                            </table>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div><br>
                                            <p><font style="font-size: larger;font-color:blue;">*</font> : DAP information is based on data collected from <span style="font-color:blue"></span><a href="https://pulse.cio.gov/analytics/agencies" target="_new">pulse.cio.gov</a></span></p>
                                        </div>
                                    </div>
                                    <div class="view-button">
                                        <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">DNSSEC Information</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip5" class="infor">
                                        <i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left">
          <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>DNSSEC Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?>
        </span>
                                    </div>
                                </div>
                                <div class="pane-content">
                                    <div class="view  view-display-id-block_7 view-dom-id-3e71e61814bfdc7fd3678ddb5e0c33c9">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-nothing">
                                                    <div class="field-content col-lg-12">
                                                        <div class="view-wrapper">
                                                            <p>DNSSEC Overall Average Score : <?php echo $agency_dnssec_score ?>% </p>
                                                            <div class="col-xs-12 col-md-6 col-lg-6">
                                                                <?php
                                                                $blockObject4 = block_load('trend_analysis', 'agency_dnssec');
                                                                $block4 = _block_get_renderable_array(_block_render_blocks(array($blockObject4)));
                                                                $output4 = drupal_render($block4);
                                                                print "$output4<br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly DNSSEC Trend</span>";
                                                                ?>
                                                            </div>
                                                            <div class="col-xs-12 col-md-6 col-lg-6">
                                                                <div id="dnssec_chart">&nbsp;</div>
                                                                <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                <script type="text/javascript">
                                                                    Highcharts.chart('dnssec_chart', {
                                                                        chart: {
                                                                            type: 'solidgauge',
                                                                        },
                                                                        title: {
                                                                            text: ''
                                                                        },
                                                                        tooltip: {
                                                                            enabled: false,
                                                                        },
                                                                        pane: {
                                                                            startAngle: 0,
                                                                            endAngle: 360,
                                                                            background: [{
                                                                                outerRadius: '118%',
                                                                                innerRadius: '80%',
                                                                                backgroundColor: '#d6d7d9',
                                                                                borderWidth: 0
                                                                            }]
                                                                        },
                                                                        yAxis: {
                                                                            min: 0,
                                                                            max: 100,
                                                                            lineWidth: 0,
                                                                            tickPositions: [],
                                                                            title: {
                                                                                text: '<?php echo $agency_dnssec_score; ?> %',
                                                                                style: {
                                                                                    fontSize: '22px',
                                                                                    color: '<?php echo dotgov_common_getChartColor($agency_dnssec_score); ?>'
                                                                                },
                                                                                y: 30
                                                                            },

                                                                        },
                                                                        plotOptions: {
                                                                            solidgauge: {
                                                                                dataLabels: {
                                                                                    enabled: false
                                                                                },
                                                                                linecap: 'round',
                                                                                stickyTracking: false,
                                                                                rounded: true
                                                                            }
                                                                        },
                                                                        series: [{
                                                                            name: 'DNSSEC Chart',
                                                                            data: [{
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_dnssec_score); ?>',
                                                                                radius: '118%',
                                                                                innerRadius: '80%',
                                                                                y: <?php echo trim($agency_dnssec_score); ?>
                                                                            }]
                                                                        }]
                                                                    });
                                                                </script>
                                                            </div>
                                                            <table width="100%">

                                                                <th style="background-color: #215393;color: white;">Breakdown</th>
                                                                <th style="background-color: #215393;color: white;">Websites</th>
                                                                <tr>
                                                                    <td>DNSSEC Compliant Websites</td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['dns_compliant'], $agency_website_num, '#29643a') ?></td>
                                                                </tr>
                                                                <tr>
                                                                    <td>DNSSEC Non Compliant Websites</td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['dns_noncompliant'], $agency_website_num, '#ac0600') ?></td>
                                                                </tr>
                                                            </table>
                                                        </div>
                                                        <div class="view-button"><br>
                                                            <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> On-Site Search Information </h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip5" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left">
On-Site Search Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?> </span>
                                    </div>

                                </div>
                                <div class="pane-content">
                                    <div class="view-wrapper">
                                        <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                            <div class="view-empty">
                                                <table><tr><td><div id="piechart2"></div>
                                                            <br>
                                                            <?php print $agencydata['searchenginestatus_graph'];
                                                            //print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engine issues by category</span>";
                                                            ?>
                                                        </td><td><div id="piechart3"></div>
                                                            <br>
                                                            <?php print $agencydata['searchengines_graph'];
                                                            //print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engines</span>";
                                                            ?>
                                                        </td></tr>
                                                    <tr>
                                                        <td>
                                                            <table>
                                                                <tr style="background-color: #215393;color: white;"><td><b>On-Site Search Engine</td><td>&nbsp;Total </b></td></tr>
                                                                <?php
                                                                foreach($agencydata['searchenginedata'] as $skey=>$sval){
                                                                    print "<tr><td>".ucfirst($skey)."</td><td align='center'>   $sval</td> </tr>";
                                                                }
                                                                ?>
                                                            </table>
                                                        </td>
                                                        <td>
                                                            <?php
                                                            $searchenginestatus = $agencydata['searchenginestatus'];
                                                            ?>
                                                            <table>
                                                                <tr style="background-color: #215393;color: white;"><td>Sites w/ On-Site Search Engine</td><td>Sites w/out On-Site Search Engine</td></tr>
                                                                <tr><td align='center'><?=($searchenginestatus['search_available'] == "")?0:$searchenginestatus['search_available']?></td><td align='center'><?=($searchenginestatus['search_notavailable'] == "")?0:$searchenginestatus['search_notavailable']?></td></tr>
                                                            </table>
                                                        </td></tr>
                                                </table>


                                            </div>
                                        </div>
                                    </div>
                                    <div class="view-button"><br>
                                        <p><a class="btn btn-primary" href="/website/search/reports">Go to Full Report</a> </p>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="pond-secondary-column-content-region pond-column pond-secondary-column2 panel-panel">
                        <div class="pond-secondary-column-content-region-inner pond-column-inner pond-secondary-column2-inner panel-panel-inner">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-12 nopadding">
                                    <div class="col-xs-10 nopadding">
                                        <h2 class="pane-title"> Mobile Information </h2>
                                    </div>
                                    <div class="col-xs-2 nopadding">
                                        <div id="tooltip4" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                            <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code"><br>
								  Mobile Overall Average Score : <?php print $agency_mobovr_score; ?> <br>
                                  Mobile Performance Score :
                                                <?= $agency_mobperf_score; ?>
                                                <br>
                                  Mobile Usability Score:
                                                <?= $agency_mobusab_score; ?>
                                                <br></span>
                                        </div>
                                    </div>
                                </div><br clear="all" />
                                <div class="pane-content">
                                    <div class="view  view-display-id-block_6 view-dom-id-146fb84eddbe3dc34d2b2cff5758c7bc">
                                        <div class="view-content">
                                            <div class="view-wrapper">
                                                <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                    <?php
                                                    if ($agency_mobperf_score >= '0' && $agency_mobperf_score <= '59') {
                                                        $mobperfmstat = "Low";
                                                    } elseif ($agency_mobperf_score >= '60' && $agency_mobperf_score <= '79') {
                                                        $mobperfmstat = "Medium";
                                                    } elseif ($agency_mobperf_score >= '80' && $agency_mobperf_score <= '100') {
                                                        $mobperfmstat = "Good";
                                                    }

                                                    if ($agency_mobusab_score >= '0' && $agency_mobusab_score <= '59') {
                                                        $mobusabstat = "Low";
                                                    } elseif ($agency_mobusab_score >= '60' && $agency_mobusab_score <= '79') {
                                                        $mobusabstat = "Medium";
                                                    } elseif ($agency_mobusab_score >= '80' && $agency_mobusab_score <= '100') {
                                                        $mobusabstat = "Good";
                                                    }
                                                    ?>
                                                    <div class="col-lg-12 nopading">
                                                        <div class="views-field views-field-php-2 col-lg-6 nopadding">
                                                            <div id="piechart1"></div>
                                                            <?php print $agencydata['gov_mob_chart']; ?> </div>
                                                        <div class="field-content col-lg-6 nopadding" style="margin-top:35px;">
                                                            <div id="mobile_chart">&nbsp;</div>
                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                            <script type="text/javascript">
                                                                Highcharts.chart('mobile_chart', {
                                                                    chart: {type: 'solidgauge', },
                                                                    title: {text: ''},
                                                                    tooltip: {
                                                                        enabled: false,
                                                                    },
                                                                    pane: {
                                                                        startAngle: 0,
                                                                        endAngle: 360,
                                                                        background: [{
                                                                            outerRadius: '118%',
                                                                            innerRadius: '80%',
                                                                            backgroundColor: '#d6d7d9',
                                                                            borderWidth: 0
                                                                        }]
                                                                    },
                                                                    yAxis: {
                                                                        min: 0,
                                                                        max: 100,
                                                                        lineWidth: 0,
                                                                        tickPositions: [],
                                                                        title: {
                                                                            text: '<?php echo $agency_mobovr_score; ?>',
                                                                            style: {
                                                                                fontSize: '22px',
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_mobovr_score); ?>'
                                                                            },
                                                                            y: 30
                                                                        },

                                                                    },

                                                                    plotOptions: {
                                                                        solidgauge: {
                                                                            dataLabels: {
                                                                                enabled: false
                                                                            },
                                                                            linecap: 'round',
                                                                            stickyTracking: false,
                                                                            rounded: true
                                                                        }
                                                                    },
                                                                    series: [{
                                                                        name: 'Mobile Chart',
                                                                        data: [{
                                                                            color: '<?php echo dotgov_common_getChartColor($agency_mobovr_score); ?>',
                                                                            radius: '118%',
                                                                            innerRadius: '80%',
                                                                            y: <?php echo trim($agency_mobovr_score); ?>
                                                                        }]
                                                                    }]
                                                                });
                                                            </script>
                                                        </div>
                                                    </div>
                                                    <div class="views-field views-field-php-1 col-lg-12">
                                                        <div class="col-lg-12 nopadding"> Mobile Overall Average Score : <?php print $agency_mobovr_score ?> <br>
                                                            Mobile Performance Score : <?php echo $agency_mobperf_score . ' (' . $mobperfmstat . ')' ?><br>
                                                            Mobile Usability Score : <?php echo $agency_mobusab_score . ' (' . $mobusabstat . ')' ?> </div>
                                                        <div class="col-lg-12 nopadding">
                                                            <?php
                                                            $blockObject1 = block_load('trend_analysis', 'agency_mob');
                                                            $block1 = _block_get_renderable_array(_block_render_blocks(array($blockObject1)));
                                                            $output1 = drupal_render($block1);
                                                            print "$output1<br><span style='font-size: 12px;font-style: italic;'>&nbsp;&nbsp;Above graph represents a monthly Mobile Trend</span>";
                                                            ?>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                            <div class="view-button clearfix">
                                                <div class="row col-xs-12 nopadding clearfix" style="margin-top: 20px;">
                                                    <div class="col-xs-6"><a class="btn btn-primary" href="/mobile/report">Go to Full Report</a> </div>
                                                    <div class="col-xs-6" style="margin-top:8px;"> <a href="/improve-my-score">How to Improve Score</a> </div>

                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding"><h2 class="pane-title">M-15-13 and BOD 18-01 Information</h2></div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip7" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
M-15-13 and BOD 18-01 Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?></span>
                                    </div>
                                </div>
                                <div class="pane-content">
                                    <div class="view  view-display-id-block_10 view-dom-id-93e7fd06306700be9064f5e8954f211b">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-php-2 col-lg-12">
                                                    <div class="view-wrapper">
                                                        <p> Compliant with M-15-13 and BOD 18-01 Overall Average Score : <?php echo $agency_m15_score ?>% </p>
                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                            <?php
                                                            $blockObject2 = block_load('trend_analysis', 'agency_m15');
                                                            $block2 = _block_get_renderable_array(_block_render_blocks(array($blockObject2)));
                                                            $output2 = drupal_render($block2);
                                                            print "$output2<br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly M-15-13 Trend</span>";
                                                            ?>
                                                        </div>
                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                            <div id="m1513_chart">&nbsp;</div>
                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                            <script type="text/javascript">
                                                                Highcharts.chart('m1513_chart', {
                                                                    chart: {
                                                                        type: 'solidgauge',
                                                                    },
                                                                    title: {
                                                                        text: ''
                                                                    },
                                                                    tooltip: {
                                                                        enabled: false,
                                                                    },
                                                                    pane: {
                                                                        startAngle: 0,
                                                                        endAngle: 360,
                                                                        background: [{
                                                                            outerRadius: '118%',
                                                                            innerRadius: '80%',
                                                                            backgroundColor: '#d6d7d9',
                                                                            borderWidth: 0
                                                                        }]
                                                                    },
                                                                    yAxis: {
                                                                        min: 0,
                                                                        max: 100,
                                                                        lineWidth: 0,
                                                                        tickPositions: [],
                                                                        title: {
                                                                            text: '<?php echo $agency_m15_score; ?> %',
                                                                            style: {
                                                                                fontSize: '22px',
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_m15_score); ?>'
                                                                            },
                                                                            y: 30
                                                                        },

                                                                    },
                                                                    plotOptions: {
                                                                        solidgauge: {
                                                                            dataLabels: {
                                                                                enabled: false
                                                                            },
                                                                            linecap: 'round',
                                                                            stickyTracking: false,
                                                                            rounded: true
                                                                        }
                                                                    },
                                                                    series: [{
                                                                        name: 'M-15-13 Chart',
                                                                        data: [{
                                                                            color: '<?php echo dotgov_common_getChartColor($agency_m15_score); ?>',
                                                                            radius: '118%',
                                                                            innerRadius: '80%',
                                                                            y: <?php echo trim($agency_m15_score); ?>
                                                                        }]
                                                                    }]
                                                                });
                                                            </script>
                                                        </div>
                                                        <table width="100%">

                                                            <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                            <th style="background-color: #215393;color: white;"> Websites </th>
                                                            <tr>
                                                                <td>M-15-13 and BOD 18-01 Compliant Websites </td>
                                                                <td><?php echo dotgov_common_applyDataColor($agencydata['m15_compliant'], $agencydata['m15_tracked'], '#29643a') ?></td>
                                                            </tr>
                                                            <tr>
                                                                <td>M-15-13 and BOD 18-01 Non Compliant Websites </td>
                                                                <td><?php echo dotgov_common_applyDataColor($agencydata['m15_noncompliant'], $agencydata['m15_tracked'], '#ac0600') ?></td>
                                                            </tr>
                                                        </table>
                                                    </div>
                                                    <div class="view-button"><br>
                                                        <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> IPV6 Information </h2>
                                </div>
                                <div class="col-xs-2">
                                    <div id="tooltip6" class="infor">
                                        <i class='icon glyphicon glyphicon-info-sign'>&nbsp</i>
                                        <span class="tooltiptext tooltip-left">
            <img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code">
            IPV6 Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate();?>
        </span>
                                    </div>
                                </div>                                <div class="pane-content">
                                    <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-nothing">
                                                    <div class="field-content col-lg-12">
                                                        <div class="view-wrapper">
                                                            <p>IPV6 Overall Average Score : <?php echo $agency_ipv6_score ?>%</p>
                                                            <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                <?php
                                                                $blockObject7 = block_load('trend_analysis', 'agency_ipv6');
                                                                $block7 = _block_get_renderable_array(_block_render_blocks(array($blockObject7)));
                                                                $output7 = drupal_render($block7);
                                                                print "$output7<br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly IPv6 Trend</span>";
                                                                ?>
                                                            </div>
                                                            <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                <div id="ipv6_chart">&nbsp;</div>
                                                                <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                <script type="text/javascript">
                                                                    Highcharts.chart('ipv6_chart', {
                                                                        chart: {
                                                                            type: 'solidgauge',
                                                                        },
                                                                        title: {
                                                                            text: ''
                                                                        },
                                                                        tooltip: {
                                                                            enabled: false,
                                                                        },
                                                                        pane: {
                                                                            startAngle: 0,
                                                                            endAngle: 360,
                                                                            background: [{
                                                                                outerRadius: '118%',
                                                                                innerRadius: '80%',
                                                                                backgroundColor: '#d6d7d9',
                                                                                borderWidth: 0
                                                                            }]
                                                                        },
                                                                        yAxis: {
                                                                            min: 0,
                                                                            max: 100,
                                                                            lineWidth: 0,
                                                                            tickPositions: [],

                                                                            title: {
                                                                                text: '<?php echo $agency_ipv6_score; ?> %',
                                                                                style: {
                                                                                    fontSize: '22px',
                                                                                    color: '<?php echo dotgov_common_getChartColor($agency_ipv6_score); ?>'
                                                                                },
                                                                                y: 30
                                                                            },

                                                                        },
                                                                        plotOptions: {
                                                                            solidgauge: {
                                                                                dataLabels: {
                                                                                    enabled: false
                                                                                },
                                                                                linecap: 'round',
                                                                                stickyTracking: false,
                                                                                rounded: true
                                                                            }
                                                                        },
                                                                        series: [{
                                                                            name: 'Free of Insecure Protocol Chart',
                                                                            data: [{
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_ipv6_score); ?>',
                                                                                radius: '118%',
                                                                                innerRadius: '80%',
                                                                                y: <?php echo trim($agency_ipv6_score); ?>
                                                                            }]
                                                                        }]
                                                                    });
                                                                </script>
                                                            </div>
                                                            <table width="100%">

                                                                <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                                <th style="background-color: #215393;color: white;"> Websites </th>
                                                                <tr width="100%">
                                                                    <td>IPv6 Compliant Websites</td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['ipv6_compliant'], $agency_website_num, '#29643a') ?></td>
                                                                </tr>
                                                                <tr width="100%">
                                                                    <td>IPv6 Non Compliant Websites</td>
                                                                    <td><?php echo dotgov_common_applyDataColor($agencydata['ipv6_noncompliant'], $agency_website_num, '#ac0600') ?></td>
                                                                </tr>
                                                            </table>
                                                        </div>
                                                        <div class="view-button"><br>
                                                            <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>

                        </div>
                    </div>
                    <div class="pond-secondary-column-content-region pond-column pond-secondary-column3 panel-panel">
                        <div class="pond-secondary-column-content-region-inner pond-column-inner pond-secondary-column3-inner panel-panel-inner">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">Accessibility Issues</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip9" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left">
            <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br/>
        Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php dotgov_common_lastScanDate(); ?>
        </span>
                                    </div>
                                </div>    <br clear="all"/>                                  <div class="pane-content">
                                    <div class="view-wrapper">
                                        <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                            <div class="view-empty"> Average Color Contrast : <?php echo round($agencydata['ag_col_contrast'] / $agency_website_num, 1); ?> <br>
                                                Average HTML Attribute : <?php echo round($agencydata['ag_html_attrib'] / $agency_website_num, 1); ?> <br>
                                                Average Missing Image Description : <?php echo round($agencydata['ag_miss_image'] / $agency_website_num, 1); ?> <br>
                                                <div id="piechart"></div>

                                                <script language="JavaScript">
                                                    google.charts.load('current', {'packages':['corechart']});
                                                    google.charts.setOnLoadCallback(drawChart2);

                                                    function drawChart2() {

                                                        var data = google.visualization.arrayToDataTable([
                                                            ['Type', 'Number'],
                                                            ['Color Contrast Issues',     <?php echo number_format($agencydata['ag_col_contrast'],1, '.', '');?>],
                                                            ['HTML Attribute Issues',      <?php echo number_format($agencydata['ag_html_attrib'],1, '.', '');?>],
                                                            ['Missing Image Description Issues',  <?php echo number_format($agencydata['ag_miss_image'],1, '.', ''); ?>]
                                                        ]);
                                                        var options = {
                                                            title: 'Accessibility Issue Breakdown',
                                                            colors: ['#7cb5ec', '#90ed7d', '#434348'],
                                                            sliceVisibilityThreshold: 0,
                                                            dataLabels: {
                                                                enabled: true
                                                            },
                                                            showInLegend: true
                                                        };

                                                        var chart = new google.visualization.PieChart(document.getElementById('piechart'));

                                                        chart.draw(data, options);
                                                    }
                                                </script>
                                                <?php
                                                if(($agencydata['ag_col_contrast'] + $agencydata['ag_html_attrib'] + $agencydata['ag_miss_image']) != 0){
                                                    print "<span style='font-size: 12px;font-style: italic;'>Above graph shows the breakdown of Accessibility issues by category</span>";
                                                }?>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="view-button"><br>
                                        <p><a class="btn btn-primary" href="/accessibility-report-all-domains">Go to Full Report</a> </p>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding"><h2 class="pane-title">Free of Insecure Protocols Information</h2></div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip8" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
                                        <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
Free of RC4/3DES and SSLv2/SSLv3 Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?></span>
                                    </div>
                                </div>                                                      <div class="pane-content">
                                    <div class="view  view-display-id-block_11 view-dom-id-48cb0bd52b149a4150411d9b44b892bc">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-php-1 col-lg-12">
                                                    <div class="view-wrapper">
                                                        <p>Free of RC4/3DES and SSLv2/SSLv3 Overall Average Score : <?php echo $agency_insecprot_score ?>%</p>
                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                            <?php
                                                            $blockObject5 = block_load('trend_analysis', 'agency_rc4');
                                                            $block5 = _block_get_renderable_array(_block_render_blocks(array($blockObject5)));
                                                            $output5 = drupal_render($block5);
                                                            print "$output5<br><span style='font-size: 12px;font-style: italic;'>Above graph represents a monthly Insecure Protocol Trend</span>";
                                                            ?>
                                                        </div>
                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                            <div id="freeofinsecureprot_chart">&nbsp;</div>
                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                            <script type="text/javascript">
                                                                Highcharts.chart('freeofinsecureprot_chart', {
                                                                    chart: {
                                                                        type: 'solidgauge',
                                                                    },
                                                                    title: {
                                                                        text: ''
                                                                    },
                                                                    tooltip: {
                                                                        enabled: false,
                                                                    },
                                                                    pane: {
                                                                        startAngle: 0,
                                                                        endAngle: 360,
                                                                        background: [{
                                                                            outerRadius: '118%',
                                                                            innerRadius: '80%',
                                                                            backgroundColor: '#d6d7d9',
                                                                            borderWidth: 0
                                                                        }]
                                                                    },
                                                                    yAxis: {
                                                                        min: 0,
                                                                        max: 100,
                                                                        lineWidth: 0,
                                                                        tickPositions: [],
                                                                        title: {
                                                                            text: '<?php echo $agency_insecprot_score; ?> %',
                                                                            style: {
                                                                                fontSize: '22px',
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_insecprot_score); ?>'
                                                                            },
                                                                            y: 30
                                                                        },
                                                                    },
                                                                    plotOptions: {
                                                                        solidgauge: {
                                                                            dataLabels: {
                                                                                enabled: false
                                                                            },
                                                                            linecap: 'round',
                                                                            stickyTracking: false,
                                                                            rounded: true
                                                                        }
                                                                    },
                                                                    series: [{
                                                                        name: 'Free of Insecure Protocol Chart',
                                                                        data: [{
                                                                            color: '<?php echo dotgov_common_getChartColor($agency_insecprot_score); ?>',
                                                                            radius: '118%',
                                                                            innerRadius: '80%',
                                                                            y: <?php echo trim($agency_insecprot_score); ?>
                                                                        }]
                                                                    }]
                                                                });
                                                            </script>
                                                        </div>
                                                        <table width="100%">

                                                            <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                            <th style="background-color: #215393;color: white;"> Websites </th>
                                                            <tr>
                                                                <td>Websites Free of RC4/3DES and SSLv2/SSLv3 </td>
                                                                <td><?php echo dotgov_common_applyDataColor($agencydata['insec_compliant'], $agencydata['free_tracked'], '#29643a') ?></td>
                                                            </tr>
                                                            <tr>
                                                                <td>Websites Not Free of RC4/3DES and SSLv2/SSLv3 </td>
                                                                <td><?php echo dotgov_common_applyDataColor($agencydata['insec_noncompliant'], $agencydata['free_tracked'], '#ac0600') ?></td>
                                                            </tr>
                                                        </table>
                                                    </div>
                                                    <div class="view-button"><br>
                                                        <p><a class="btn btn-primary" href="/website/all/reports">Go to Full Report</a> </p>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="panel-separator"></div>
                            <div class="panel-pane pane-views pane-website-information" style="">
                                <h2 class="pane-title"> Popular Technologies </h2>
                                <div class="pane-content">
                                    <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-nothing">
                                                    <div class="view-wrapper" style="">
                                                        <div class="field-content col-lg-12">
                                                            <p> Below are the most popular technology stacks used </p>
                                                            <?php
                                                            if ($agencydata['ag_webserver'] != '') {
                                                                print "<div class=\"col-sm-12 nopadding dataset-resources\"><span class=\"app-button\" style=\"height:auto;\">Web Server : ";
                                                                foreach ($agencydata['ag_webserver'] as $akey => $aval) {
                                                                    print "$akey($aval) ";
                                                                }
                                                                print "</span></div>";
                                                            }
                                                            if ($agencydata['ag_proglang'] != '') {
                                                                print "<div class=\"col-sm-12 nopadding dataset-resources\"><span style=\"height:auto;\" class=\"app-button\">Languages : ";
                                                                foreach ($agencydata['ag_proglang'] as $akey => $aval) {
                                                                    print "$akey($aval) ";
                                                                }
                                                                print "</span></div>";
                                                            }

                                                            if ($agencydata['ag_cms'] != '') {
                                                                print "<div class=\"col-sm-12 nopadding dataset-resources\"><span style=\"height:auto;\" class=\"app-button\">CMS : ";
                                                                foreach ($agencydata['ag_cms'] as $akey => $aval) {
                                                                    print "$akey($aval) ";
                                                                }
                                                                print "</span></div>";
                                                            }

                                                            if ($agencydata['ag_os'] != '') {
                                                                print "<div class=\"col-sm-12 nopadding dataset-resources\"><span style=\"height:auto;\" class=\"app-button\">Operating Systems : ";
                                                                foreach ($agencydata['ag_os'] as $akey => $aval) {
                                                                    print "$akey($aval) ";
                                                                }
                                                                print "</span></div>";
                                                            }

                                                            if ($agencydata['ag_cdn'] != '') {
                                                                print "<div class=\"col-sm-12 nopadding dataset-resources\"><span style=\"height:auto;\" class=\"app-button\">CDN : ";
                                                                foreach ($agencydata['ag_cdn'] as $akey => $aval) {
                                                                    print "$akey($aval) ";
                                                                }
                                                                print "</span></div>";
                                                            }
                                                            ?>
                                                        </div>
                                                    </div>
                                                    <div class="view-button" style="margin-left:15px;"><br>
                                                        <p><a class="btn btn-primary" href="/technology-overview">Go to Full Report</a> </p>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
