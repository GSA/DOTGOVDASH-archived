<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
global $user;
$user_data = user_load( $user->uid );
$curuserAgency = $user_data->field_web_agency_id[ 'und' ][ 0 ][ 'nid' ];
$agencydata = dotgov_common_getAgencyComplianceData( $curuserAgency );

foreach ( $view->style_plugin->rendered_fields[ 0 ] as $key => $val ) {
    if ( $key == 'field_web_agency_id_1' )
        $agency_website_num = $val;
    if ( $key == 'field_dap_score' )
        $agency_dap_score = $val;
    if ( $key == 'field_https_score' )
        $agency_https_score = $val;
    if ( $key == 'field_mobile_overall_score' )
        $agency_mobovr_score = $val;
    if ( $key == 'field_mobile_performance_score' )
        $agency_mobperf_score = $val;
    if ( $key == 'field_mobile_usability_score' )
        $agency_mobusab_score = $val;
    if ( $key == 'field_dnssec_score' )
        $agency_dnssec_score = $val;
    if ( $key == 'field_ipv6_score' )
        $agency_ipv6_score = $val;
    if ( $key == 'field_https_score' )
        $agency_https_score = $val;
    if ( $key == 'field_free_of_insecr_prot_score' )
        $agency_insecprot_score = $val;
    if ( $key == 'field_m15_13_compliance_score' )
        $agency_m15_score = $val;
}

$agencynode = node_load( $curuserAgency );
drupal_set_title( $agencynode->title );
?>

<div class="main-container container-fluid">
    <header role="banner" id="page-header"> </header>
    <!-- /#page-header -->

    <div class="row">
        <section class="col-sm-12">
            <div class="region region-content">
                <section id="block-system-main" class="block block-system clearfix">
                    <div class="contextual-links-region">
                        <div class="panel-display pond clearfix ">
                            <div class="pond-container pond-header clearfix panel-panel">
                                <div class="pond-container-inner pond-header-inner panel-panel-inner">
                                    <div class="panel-pane pane-views pane-website-information">
                                        <div class="pane-content">
                                            <div class="view  view-display-id-block_5 web-agency view-dom-id-4aee3ca19c85ddeac4f7e1ff1e91dabc">
                                                <div class="attachment attachment-before">
                                                    <div class="view  view-display-id-attachment_1"> </div>
                                                </div>
                                                <div class="view-content">
                                                    <div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
                                                        <div class="views-field views-field-field-web-snapshot">
                                                            <div class="field-content">
                                                                <div class="col-xs-12  white-back">
                                                                    <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
                                                                        <h3>Agency</h3>
                                                                        <p>
                                                                            <?=$agencynode->title?>
                                                                        </p>
                                                                    </div>
                                                                    <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
                                                                        <?php
                                                                        if ( $agencynode->field_agency_logo[ 'und' ][ 0 ][ 'uri' ] != '' ) {
                                                                            ?>
                                                                            <img src="<?php print file_create_url($agencynode->field_agency_logo['und'][0]['uri']); ?>" alt="<?=$agencynode->title?>">
                                                                            <?php
                                                                        } else {
                                                                            print "&nbsp;";
                                                                        }
                                                                        ?>
                                                                    </div>
                                                                    <div class="col-lg-3 col-sm-12 col-xs-12 text-center">
                                                                        <h3>Public Domains Reported</h3>
                                                                        <p></p>
                                                                        <p>
                                                                            <?= $agency_website_num ?>
                                                                        </p>
                                                                        <p></p>
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
                            <div class="pond-container pond-secondary-column-content pond-column-content-row2 clearfix">
                                <div class="pond-secondary-column-content-region pond-column pond-secondary-column1 panel-panel">
                                    <div class="pond-secondary-column-content-region-inner pond-column-inner pond-secondary-column1-inner panel-panel-inner">

                                        <!--          <div class="panel-pane pane-views pane-website-information">-->
                                        <!---->
                                        <!--           <h2 class="pane-title">-->
                                        <!-- SSL Information </h2>-->
                                        <!---->
                                        <!---->
                                        <!--           <div class="pane-content">-->
                                        <!---->
                                        <!-- <div-->
                                        <!--  class="view  view-display-id-block_2 ssl-info view-dom-id-73293dc468f2cdd4986eebab02cda5d8">-->
                                        <!---->
                                        <!---->
                                        <!--  <div class="view-content">-->
                                        <!--   <div-->
                                        <!--    class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">-->
                                        <!---->
                                        <!---->
                                        <!--    <div class="views-field views-field-php">  <span-->
                                        <!--      class="field-content col-lg-12"></span></div>-->
                                        <!--    <div class="views-field views-field-nothing-1 clearfix">-->
                                        <!--     <div class="field-content col-lg-12 clearfix">-->
                                        <!--      <table width="90%">-->
                                        <!--       <th style="background-color: #215393;color: white;align:center;">-->
                                        <!--        Criteria-->
                                        <!--       </th>-->
                                        <!--       <th style="background-color: #215393;color: white">-->
                                        <!--        Supporting Domains-->
                                        <!--       </th>-->
                                        <!--       <th style="background-color: #215393;color: white;margin: 5px;align:center;">-->
                                        <!--        Non Suppporting Domains-->
                                        <!--       </th>-->
                                        <!--       <tr align="center">-->
                                        <!--        <td>SSL V2 Support</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['v2_support'], $agency_website_num) ?>
                                        <!-- </td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['v2_nosupport'], $agency_website_num) ?>
                                        <!-- </td>-->
                                        <!--       </tr>-->
                                        <!--       <tr align="center">-->
                                        <!--        <td>SSL V3 Support</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['v3_support'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['v3_nosupport'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--       </tr>-->
                                        <!--       <tr align="center">-->
                                        <!--        <td>TLS V1 Support</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv1_support'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv1_nosupport'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--       </tr>-->
                                        <!--       <tr align="center">-->
                                        <!--        <td>TLS V1.1 Support</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv11_support'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv11_nosupport'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--       </tr>-->
                                        <!--       <tr align="center">-->
                                        <!--        <td>TLS V1.2 Support</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv12_support'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--        <td>-->
                                        <?//= dotgov_common_applyDataColor($agencydata['tlsv12_nosupport'], $agency_website_num) ?>
                                        <!--</td>-->
                                        <!--       </tr>-->
                                        <!--      </table>-->
                                        <!--     </div>-->
                                        <!--    </div>-->
                                        <!---->
                                        <!---->
                                        <!--   </div>-->
                                        <!---->
                                        <!---->
                                        <!--  </div>-->
                                        <!---->
                                        <!-- </div>-->
                                        <!---->
                                        <!--           </div>-->
                                        <!---->
                                        <!---->
                                        <!--          </div>-->

                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> Accessibility Issues </h2>
                                            <div class="pane-content">
                                                <div class="view-wrapper">
                                                    <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                                        <div class="view-empty"> Average Color Contrast:
                                                            <?= round($agencydata['ag_col_contrast']/$agency_website_num,1); ?>
                                                            <br> Average HTML Attribute :
                                                            <?= round($agencydata['ag_html_attrib']/$agency_website_num,1); ?>
                                                            <br> Average Missing Image Description:
                                                            <?= round($agencydata['ag_miss_image']/$agency_website_num,1); ?>
                                                            <br>
                                                            <div id="piechart"></div>
                                                            <?php print $agencydata['ag_access_chart'];
                                                            if(($agencydata['ag_col_contrast'] + $agencydata['ag_html_attrib'] + $agencydata['ag_miss_image']) != 0){
                                                                print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of Accessibility issues by category</span>";
                                                            }?>
                                                        </div>
                                                    </div>
                                                </div>
                                                <!--							  <div class="view-button"><br>-->
                                                <!--                          <p><a class="link-all-reports" href="/accessibilityreportalldomains?field_web_agency_id_nid_selective=-->
                                                <?//=$curuserAgency?>
                                                <!--">Go to Full Report</a> </p>-->
                                                <!--                        </div>-->
                                            </div>
                                        </div>

                                        <!-- END OUTPUT from 'sites/all/modules/contrib/panels/templates/panels-pane.tpl.php' -->

                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> Mobile Information </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_6 view-dom-id-146fb84eddbe3dc34d2b2cff5758c7bc">
                                                    <div class="view-content">
                                                        <div class="view-wrapper">
                                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                                <?php
                                                                if ( $agency_mobperf_score >= '0' && $agency_mobperf_score <= '59' ) {
                                                                    $mobperfmstat = "Low";

                                                                } elseif ( $agency_mobperf_score >= '60' && $agency_mobperf_score <= '79' ) {
                                                                    $mobperfmstat = "Medium";

                                                                } elseif ( $agency_mobperf_score >= '80' && $agency_mobperf_score <= '100' ) {
                                                                    $mobperfmstat = "Good";

                                                                }

                                                                if ( $agency_mobusab_score >= '0' && $agency_mobusab_score <= '59' ) {
                                                                    $mobusabstat = "Low";

                                                                } elseif ( $agency_mobusab_score >= '60' && $agency_mobusab_score <= '79' ) {
                                                                    $mobusabstat = "Medium";

                                                                } elseif ( $agency_mobusab_score >= '80' && $agency_mobusab_score <= '100' ) {
                                                                    $mobusabstat = "Good";

                                                                }

                                                                ?>
                                                                <div class="views-field views-field-php-2 col-lg-6 nopadding">
                                                                    <div id="piechart1"></div>
                                                                    <?php print $agencydata['ag_mob_chart']; ?>
                                                                </div>

                                                                <div class="field-content col-lg-6" style="margin-top:32px;">
                                                                    <div id="mobile_chart">&nbsp;</div>
                                                                    <script type="text/javascript">
                                                                        Highcharts.chart( 'mobile_chart', {

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
                                                                                    background: [ {
                                                                                        outerRadius: '118%',
                                                                                        innerRadius: '80%',
                                                                                        backgroundColor: '#d6d7d9',
                                                                                        borderWidth: 0
                                                                                    } ]
                                                                                },

                                                                                yAxis: {
                                                                                    min: 0,
                                                                                    max: 100,
                                                                                    lineWidth: 0,
                                                                                    tickPositions: [],

                                                                                    title: {
                                                                                        text: '<?php echo $agency_mobovr_score;?>',
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

                                                                                series: [ {
                                                                                    name: 'Mobile Chart',
                                                                                    data: [ {
                                                                                        color: '<?php echo dotgov_common_getChartColor($agency_mobovr_score); ?>',
                                                                                        radius: '118%',
                                                                                        innerRadius: '80%',
                                                                                        y: <?php echo trim($agency_mobovr_score);?>
                                                                                    } ]
                                                                                } ]
                                                                            }


                                                                        );
                                                                    </script>
                                                                </div>

                                                                <div class="col-xs-12">
                                                                    Mobile Overall Average Score :
                                                                    <?php print $agency_mobovr_score ?> <br> Mobile Performance Score :
                                                                    <?= $agency_mobperf_score . ' (' . $mobperfmstat . ')' ?><br> Mobile Usability Score:
                                                                    <?= $agency_mobusab_score . ' (' . $mobusabstat . ')' ?><br>
                                                                </div>
                                                                <div class="views-field views-field-php-1">
                                                                    <div class="field-content">
                                                                        <?php
                                                                        $blockObject1 = block_load( 'trend_analysis', 'agency_mob' );
                                                                        $block1 = _block_get_renderable_array( _block_render_blocks( array( $blockObject1 ) ) );
                                                                        $output1 = drupal_render( $block1 );
                                                                        print "$output1<br><span style='color: " . dotgov_common_getChartColor( $agency_mobovr_score ) . ";font-size: 12px;font-style: italic;'>&nbsp;&nbsp;Above graph represents a monthly Mobile Trend</span>";
                                                                        ?>
                                                                    </div>
                                                                </div>
                                                                <div class="col-xs-12"> <a href="/improve-my-score">How to Improve Score</a> </div>
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> M-15-13 and BOD 18-01 Information </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_10 view-dom-id-93e7fd06306700be9064f5e8954f211b">
                                                    <div class="view-content">
                                                        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                            <div class="views-field views-field-php-2 col-lg-12">
                                                                <div class="view-wrapper">
                                                                    <p> Compliant with M-15-13 and BOD 18-01 Overall Average Score :
                                                                        <?= $agency_m15_score ?>
                                                                        % </p>
                                                                    <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                        <?php
                                                                        $blockObject2 = block_load( 'trend_analysis', 'agency_m15' );
                                                                        $block2 = _block_get_renderable_array( _block_render_blocks( array( $blockObject2 ) ) );
                                                                        $output2 = drupal_render( $block2 );
                                                                        print "$output2<br><span style='color: " . dotgov_common_getChartColor( $agency_m15_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly M-15-13 Trend</span>";
                                                                        ?>
                                                                    </div>
                                                                    <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                        <div id="m1513_chart">&nbsp;</div>
                                                                        <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                        <script type="text/javascript">
                                                                            Highcharts.chart( 'm1513_chart', {

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
                                                                                        background: [ {
                                                                                            outerRadius: '118%',
                                                                                            innerRadius: '80%',
                                                                                            backgroundColor: '#d6d7d9',
                                                                                            borderWidth: 0
                                                                                        } ]
                                                                                    },

                                                                                    yAxis: {
                                                                                        min: 0,
                                                                                        max: 100,
                                                                                        lineWidth: 0,
                                                                                        tickPositions: [],

                                                                                        title: {
                                                                                            text: '<?php echo $agency_m15_score;?> %',
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

                                                                                    series: [ {
                                                                                        name: 'M-15-13 Chart',
                                                                                        data: [ {
                                                                                            color: '<?php echo dotgov_common_getChartColor($agency_m15_score); ?>',
                                                                                            radius: '118%',
                                                                                            innerRadius: '80%',
                                                                                            y: <?php echo trim($agency_m15_score);?>
                                                                                        } ]
                                                                                    } ]
                                                                                }


                                                                            );
                                                                        </script>
                                                                    </div>
                                                                    <table width="100%">

                                                                        <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                                        <th style="background-color: #215393;color: white;"> Domains </th>
                                                                        <tr>
                                                                            <td>M-15-13 and BOD 18-01 Compliant Domains </td>
                                                                            <td>
                                                                                <?= dotgov_common_applyDataColor($agencydata['m15_compliant'], $agencydata['m15_tracked'],'#29643a') ?>
                                                                            </td>
                                                                        </tr>
                                                                        <tr>
                                                                            <td>M-15-13 and BOD 18-01 Non Compliant Domains </td>
                                                                            <td>
                                                                                <?= dotgov_common_applyDataColor($agencydata['m15_noncompliant'], $agencydata['m15_tracked'],'#ac0600') ?>
                                                                            </td>
                                                                        </tr>
                                                                    </table>
                                                                </div>
                                                                <!--							    <div class="view-button"><br>-->
                                                                <!--                                  <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                                <?//=$curuserAgency?>
                                                                <!--">Go to Full Report</a> </p>-->
                                                                <!--                                </div>-->
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="pond-secondary-column-content-region pond-column pond-secondary-column2 panel-panel">
                                    <div class="pond-secondary-column-content-region-inner pond-column-inner pond-secondary-column2-inner panel-panel-inner">
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> HTTPS Information </h2>
                                            <div class="pane-content">
                                                <div class="view-wrapper">
                                                    <div class="row">
                                                        <div class="col-md-12 col-lg-12">HTTPS Overall Average Score :
                                                            <?= $agency_https_score ?>
                                                            %</div>
                                                    </div>
                                                    <div class="row">
                                                        <div class="col-sm-12 col-lg-6">
                                                            <?php
                                                            $blockObject3 = block_load( 'trend_analysis', 'agency_https' );
                                                            $block3 = _block_get_renderable_array( _block_render_blocks( array( $blockObject3 ) ) );
                                                            $output3 = drupal_render( $block3 );
                                                            print "$output3 <br><span style='color: " . dotgov_common_getChartColor( $agency_https_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly HTTPS Trend</span>";
                                                            ?>
                                                        </div>
                                                        <div class="col-sm-12 col-lg-6">
                                                            <div id="https_chart">&nbsp;</div>
                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                            <script type="text/javascript">
                                                                Highcharts.chart( 'https_chart', {

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
                                                                            background: [ {
                                                                                outerRadius: '118%',
                                                                                innerRadius: '80%',
                                                                                backgroundColor: '#d6d7d9',
                                                                                borderWidth: 0
                                                                            } ]
                                                                        },

                                                                        yAxis: {
                                                                            min: 0,
                                                                            max: 100,
                                                                            lineWidth: 0,
                                                                            tickPositions: [],

                                                                            title: {
                                                                                text: '<?php echo $agency_https_score;?> %',
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

                                                                        series: [ {
                                                                            name: 'Free of Insecure Protocol Chart',
                                                                            data: [ {
                                                                                color: '<?php echo dotgov_common_getChartColor($agency_https_score); ?>',
                                                                                radius: '118%',
                                                                                innerRadius: '80%',
                                                                                y: <?php echo trim($agency_https_score);?>
                                                                            } ]
                                                                        } ]
                                                                    }


                                                                );
                                                            </script>
                                                        </div>
                                                    </div>
                                                    <table width="100%">

                                                        <th style="background-color: #215393;color: white;">Criteria</th>
                                                        <th style="background-color: #215393;color: white">Supporting Domains </th>
                                                        <th style="background-color: #215393;color: white">Non Supporting Domains </th>
                                                        <tr>
                                                            <td>Enforce HTTPS</td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['enfhttps_support'], $agency_website_num,'#29643a') ?>
                                                            </td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['enfhttps_nosupport'], $agency_website_num,'#ac0600') ?>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>HSTS Status</td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['hsts_support'], $agency_website_num,'#29643a') ?>
                                                            </td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['hsts_nosupport'], $agency_website_num,'#ac0600') ?>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>HTTPS Status</td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['https_support'], $agency_website_num,'#29643a') ?>
                                                            </td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['https_nosupport'], $agency_website_num,'#ac0600') ?>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>Preload Status</td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['preload_support'], $agency_website_num,'#29643a') ?>
                                                            </td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['preload_nosupport'], $agency_website_num,'#ac0600') ?>
                                                            </td>
                                                        </tr>
                                                        <tr>
                                                            <td>Preload Ready</td>
                                                            <td align="center">
                                                                <?= dotgov_common_applyDataColor($agencydata['preload_readysupport'], $agency_website_num,'#29643a') ?>
                                                            </td>
                                                            <td align="center">NA</td>
                                                        </tr>
                                                    </table>
                                                </div>
                                                <!--						<div class="view-button"><br>-->
                                                <!--                          <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                <?//=$curuserAgency?>
                                                <!--">Go to Full Report</a> </p>-->
                                                <!--                        </div>-->
                                            </div>
                                        </div>
                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title">DNSSEC Information </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_7 view-dom-id-3e71e61814bfdc7fd3678ddb5e0c33c9">
                                                    <div class="view-content">
                                                        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                            <div class="views-field views-field-nothing">
                                                                <div class="field-content col-lg-12">
                                                                    <div class="view-wrapper">
                                                                        <p>DNSSEC Overall Average Score :
                                                                            <?= $agency_dnssec_score ?>
                                                                            % </p>
                                                                        <div class="col-xs-12 col-md-6 col-lg-6">
                                                                            <?php
                                                                            $blockObject4 = block_load( 'trend_analysis', 'agency_dnssec' );
                                                                            $block4 = _block_get_renderable_array( _block_render_blocks( array( $blockObject4 ) ) );
                                                                            $output4 = drupal_render( $block4 );
                                                                            print "$output4<br><span style='color: " . dotgov_common_getChartColor( $agency_dnssec_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly DNSSEC Trend</span>";
                                                                            ?>
                                                                        </div>
                                                                        <div class="col-xs-12 col-md-6 col-lg-6">
                                                                            <div id="dnssec_chart">&nbsp;</div>
                                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                            <script type="text/javascript">
                                                                                Highcharts.chart( 'dnssec_chart', {

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
                                                                                            background: [ {
                                                                                                outerRadius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                backgroundColor: '#d6d7d9',
                                                                                                borderWidth: 0
                                                                                            } ]
                                                                                        },

                                                                                        yAxis: {
                                                                                            min: 0,
                                                                                            max: 100,
                                                                                            lineWidth: 0,
                                                                                            tickPositions: [],

                                                                                            title: {
                                                                                                text: '<?php echo $agency_dnssec_score;?> %',
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

                                                                                        series: [ {
                                                                                            name: 'DNSSEC Chart',
                                                                                            data: [ {
                                                                                                color: '<?php echo dotgov_common_getChartColor($agency_dnssec_score); ?>',
                                                                                                radius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                y: <?php echo trim($agency_dnssec_score);?>
                                                                                            } ]
                                                                                        } ]
                                                                                    }


                                                                                );
                                                                            </script>
                                                                        </div>
                                                                        <table width="100%">

                                                                            <th style="background-color: #215393;color: white;">Breakdown</th>
                                                                            <th style="background-color: #215393;color: white;">Domains</th>
                                                                            <tr>
                                                                                <td>DNSSEC Compliant Domains</td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['dns_compliant'], $agency_website_num,'#29643a') ?>
                                                                                </td>
                                                                            </tr>
                                                                            <tr>
                                                                                <td>DNSSEC Non Compliant Domains</td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['dns_noncompliant'], $agency_website_num,'#ac0600') ?>
                                                                                </td>
                                                                            </tr>
                                                                        </table>
                                                                    </div>
                                                                    <!--                                  <div class="view-button"><br>-->
                                                                    <!--                                    <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                                    <?//=$curuserAgency?>
                                                                    <!--">Go to Full Report</a> </p>-->
                                                                    <!--                                  </div>-->
                                                                </div>
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> Free of Insecure Protocols Information </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_11 view-dom-id-48cb0bd52b149a4150411d9b44b892bc">
                                                    <div class="view-content">
                                                        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                            <div class="views-field views-field-php-1 col-lg-12">
                                                                <div class="view-wrapper">
                                                                    <p>Free of RC4/3DES and SSLv2/SSLv3 Overall Average Score :
                                                                        <?= $agency_insecprot_score ?>
                                                                        %</p>
                                                                    <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                        <?php
                                                                        $blockObject5 = block_load( 'trend_analysis', 'agency_rc4' );
                                                                        $block5 = _block_get_renderable_array( _block_render_blocks( array( $blockObject5 ) ) );
                                                                        $output5 = drupal_render( $block5 );
                                                                        print "$output5<br><span style='color: " . dotgov_common_getChartColor( $agency_insecprot_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly Insecure Protocol Trend</span>";
                                                                        ?>
                                                                    </div>
                                                                    <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                        <div id="freeofinsecureprot_chart">&nbsp;</div>
                                                                        <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                        <script type="text/javascript">
                                                                            Highcharts.chart( 'freeofinsecureprot_chart', {

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
                                                                                        background: [ {
                                                                                            outerRadius: '118%',
                                                                                            innerRadius: '80%',
                                                                                            backgroundColor: '#d6d7d9',
                                                                                            borderWidth: 0
                                                                                        } ]
                                                                                    },

                                                                                    yAxis: {
                                                                                        min: 0,
                                                                                        max: 100,
                                                                                        lineWidth: 0,
                                                                                        tickPositions: [],

                                                                                        title: {
                                                                                            text: '<?php echo $agency_insecprot_score;?> %',
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

                                                                                    series: [ {
                                                                                        name: 'Free of Insecure Protocol Chart',
                                                                                        data: [ {
                                                                                            color: '<?php echo dotgov_common_getChartColor($agency_insecprot_score); ?>',
                                                                                            radius: '118%',
                                                                                            innerRadius: '80%',
                                                                                            y: <?php echo trim($agency_insecprot_score);?>
                                                                                        } ]
                                                                                    } ]
                                                                                }


                                                                            );
                                                                        </script>
                                                                    </div>
                                                                    <table width="100%">

                                                                        <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                                        <th style="background-color: #215393;color: white;"> Domains </th>
                                                                        <tr>
                                                                            <td>Domains Free of RC4/3DES and SSLv2/SSLv3 </td>
                                                                            <td>
                                                                                <?= dotgov_common_applyDataColor($agencydata['insec_compliant'], $agencydata['free_tracked'],'#29643a') ?>
                                                                            </td>
                                                                        </tr>
                                                                        <tr>
                                                                            <td>Domains Not Free of RC4/3DES and SSLv2/SSLv3 </td>
                                                                            <td>
                                                                                <?= dotgov_common_applyDataColor($agencydata['insec_noncompliant'], $agencydata['free_tracked'],'#ac0600') ?>
                                                                            </td>
                                                                        </tr>
                                                                    </table>
                                                                </div>
                                                                <!--                                <div class="view-button"><br>-->
                                                                <!--                                  <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                                <?//=$curuserAgency?>
                                                                <!--">Go to Full Report</a> </p>-->
                                                                <!--                                </div>-->
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
                                            <h2 class="pane-title"> DAP Information </h2>
                                            <div class="pane-content">
                                                <div class="view-wrapper" style="min-height:332px;">
                                                    <div class="view  view-display-id-block_4 view-dom-id-6181bfbb91a57a13154a09c584b98ec8">
                                                        <div class="view-content">
                                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                                <div class="views-field views-field-php"> <span class="field-content col-lg-12"> </span> </div>
                                                                <div class="views-field views-field-nothing clearfix">
                                                                    <div class="field-content col-lg-12">
                                                                        <p>DAP Overall Average Score :
                                                                            <?= $agency_dap_score ?>
                                                                            %</p>
                                                                        <div class="col-xs-12-col-sm-12 col-lg-6">
                                                                            <?php
                                                                            $blockObject6 = block_load( 'trend_analysis', 'agency_dap' );
                                                                            $block6 = _block_get_renderable_array( _block_render_blocks( array( $blockObject6 ) ) );
                                                                            $output6 = drupal_render( $block6 );
                                                                            print "$output6 <br><span style='color: " . dotgov_common_getChartColor( $agency_dap_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly DAP Trend</span>";
                                                                            ?>
                                                                        </div>
                                                                        <div class="col-xs-12-col-sm-12 col-lg-6">
                                                                            <div id="dap_chart">&nbsp;</div>
                                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                            <script type="text/javascript">
                                                                                Highcharts.chart( 'dap_chart', {

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
                                                                                            background: [ {
                                                                                                outerRadius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                backgroundColor: '#d6d7d9',
                                                                                                borderWidth: 0
                                                                                            } ]
                                                                                        },

                                                                                        yAxis: {
                                                                                            min: 0,
                                                                                            max: 100,
                                                                                            lineWidth: 0,
                                                                                            tickPositions: [],

                                                                                            title: {
                                                                                                text: '<?php echo $agency_dap_score;?> %',
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

                                                                                        series: [ {
                                                                                            name: 'DAP Chart',
                                                                                            data: [ {
                                                                                                color: '<?php echo dotgov_common_getChartColor($agency_dap_score); ?>',
                                                                                                radius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                y: <?php echo trim($agency_dap_score);?>
                                                                                            } ]
                                                                                        } ]
                                                                                    }


                                                                                );
                                                                            </script>
                                                                        </div>
                                                                        <table style="align-items: center;width:100%;">

                                                                            <th style="background-color: #215393;color: white;border: 1px;margin-left: -5px;"> Breakdown </th>
                                                                            <th style="background-color: #215393;color: white;border: 1px;"> Domains </th>
                                                                            <tr>
                                                                                <td>
                                                                                    DAP Compliant Domains
                                                                                    <font style="font-size: larger;font-color:blue;">*</font>
                                                                                </td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['dap_compliant'], $agencydata['dap_tottracked'],'#29643a') ?>
                                                                                </td>
                                                                            </tr>
                                                                            <tr>
                                                                                <td>DAP Non Compliant Domains
                                                                                    <font style="font-size: larger;font-color:blue;">*</font>
                                                                                </td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['dap_noncompliant'], $agencydata['dap_tottracked'],'#ac0600') ?>
                                                                                </td>
                                                                            </tr>
                                                                        </table>
                                                                    </div>
                                                                </div>
                                                            </div>
                                                        </div>
                                                    </div>
                                                    <div><br>
                                                        <p>
                                                            <font style="font-size: larger;font-color:blue;">*</font> : DAP information is based on data collected from <span style="font-color:blue"></span><a href="https://pulse.cio.gov/analytics/agencies" target="_new">pulse.cio.gov</a>
                                                            </span>
                                                        </p>
                                                    </div>
                                                </div>
                                                <!--					  <div class="view-button">-->
                                                <!--                          <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                <?//=$curuserAgency?>
                                                <!--">Go to Full Report</a> </p>-->
                                                <!--                        </div>-->

                                            </div>
                                        </div>
                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> IPV6 Information </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                                    <div class="view-content">
                                                        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                            <div class="views-field views-field-nothing">
                                                                <div class="field-content col-lg-12">
                                                                    <div class="view-wrapper">
                                                                        <p>IPV6 Overall Average Score :
                                                                            <?= $agency_ipv6_score ?>
                                                                            %
                                                                            </td>
                                                                        </p>
                                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                            <?php
                                                                            $blockObject7 = block_load( 'trend_analysis', 'agency_ipv6' );
                                                                            $block7 = _block_get_renderable_array( _block_render_blocks( array( $blockObject7 ) ) );
                                                                            $output7 = drupal_render( $block7 );
                                                                            print "$output7<br><span style='color: " . dotgov_common_getChartColor( $agency_ipv6_score ) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly IPv6 Trend</span>";
                                                                            ?>
                                                                        </div>
                                                                        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                                                            <div id="ipv6_chart">&nbsp;</div>
                                                                            <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                                            <script type="text/javascript">
                                                                                Highcharts.chart( 'ipv6_chart', {

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
                                                                                            background: [ {
                                                                                                outerRadius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                backgroundColor: '#d6d7d9',
                                                                                                borderWidth: 0
                                                                                            } ]
                                                                                        },

                                                                                        yAxis: {
                                                                                            min: 0,
                                                                                            max: 100,
                                                                                            lineWidth: 0,
                                                                                            tickPositions: [],

                                                                                            title: {
                                                                                                text: '<?php echo $agency_ipv6_score;?> %',
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

                                                                                        series: [ {
                                                                                            name: 'Free of Insecure Protocol Chart',
                                                                                            data: [ {
                                                                                                color: '<?php echo dotgov_common_getChartColor($agency_ipv6_score); ?>',
                                                                                                radius: '118%',
                                                                                                innerRadius: '80%',
                                                                                                y: <?php echo trim($agency_ipv6_score);?>
                                                                                            } ]
                                                                                        } ]
                                                                                    }


                                                                                );
                                                                            </script>
                                                                        </div>
                                                                        <table width="100%">

                                                                            <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                                            <th style="background-color: #215393;color: white;"> Domains </th>
                                                                            <tr width="100%">
                                                                                <td>IPv6 Compliant Domains</td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['ipv6_compliant'], $agency_website_num,'#29643a') ?>
                                                                                </td>
                                                                            </tr>
                                                                            <tr width="100%">
                                                                                <td>IPv6 Non Compliant Domains</td>
                                                                                <td>
                                                                                    <?= dotgov_common_applyDataColor($agencydata['ipv6_noncompliant'], $agency_website_num,'#ac0600') ?>
                                                                                </td>
                                                                            </tr>
                                                                        </table>
                                                                    </div>
                                                                    <!--                                  <div class="view-button"><br>-->
                                                                    <!--                                    <p><a class="link-all-reports" href="/website/all/reports?field_web_agency_id_nid=-->
                                                                    <?//=$curuserAgency?>
                                                                    <!--">Go to Full Report</a> </p>-->
                                                                    <!--                                  </div>-->
                                                                </div>
                                                            </div>
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div class="panel-separator"></div>
                                        <div class="panel-pane pane-views pane-website-information">
                                            <h2 class="pane-title"> Popular Technologies </h2>
                                            <div class="pane-content">
                                                <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                                    <div class="view-content">
                                                        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                            <div class="views-field views-field-nothing">
                                                                <div class="view-wrapper">
                                                                    <div class="field-content col-lg-12">

                                                                        <?php
                                                                        $no_data = 1;
                                                                        $message = "Below are the most popular technology stacks used in ";
                                                                        if ( $agencydata[ 'ag_webserver' ] != '' ) {
                                                                            if ( $no_data == 1 ) {
                                                                                $no_data = 0;
                                                                                print "<p>" . $message . $agencynode->title . ".</p>";
                                                                            }
                                                                            print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Web Server :";
                                                                            foreach ( $agencydata[ 'ag_webserver' ] as $akey => $aval ) {
                                                                                print "$akey($aval) ";
                                                                            }
                                                                            print "</span></div>";
                                                                        }
                                                                        if ( $agencydata[ 'ag_proglang' ] != '' ) {
                                                                            if ( $no_data == 1 ) {
                                                                                $no_data = 0;
                                                                                print "<p>" . $message . $agencynode->title . ".</p>";
                                                                            }
                                                                            print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Languages :";
                                                                            foreach ( $agencydata[ 'ag_proglang' ] as $akey => $aval ) {
                                                                                print "$akey($aval) ";
                                                                            }
                                                                            print "</span></div>";
                                                                        }

                                                                        if ( $agencydata[ 'ag_cms' ] != '' ) {
                                                                            if ( $no_data == 1 ) {
                                                                                $no_data = 0;
                                                                                print "<p>" . $message . $agencynode->title . ".</p>";
                                                                            }
                                                                            print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">CMS :";
                                                                            foreach ( $agencydata[ 'ag_cms' ] as $akey => $aval ) {
                                                                                print "$akey($aval) ";
                                                                            }
                                                                            print "</span></div>";
                                                                        }

                                                                        if ( $agencydata[ 'ag_os' ] != '' ) {
                                                                            if ( $no_data == 1 ) {
                                                                                $no_data = 0;
                                                                                print "<p>" . $message . $agencynode->title . ".</p>";
                                                                            }
                                                                            print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Operating Systems :";
                                                                            foreach ( $agencydata[ 'ag_os' ] as $akey => $aval ) {
                                                                                print "$akey($aval) ";
                                                                            }
                                                                            print "</span></div>";
                                                                        }

                                                                        //       if($agencydata['ag_js'] != ''){
                                                                        //if($no_data == 1) {
                                                                        //                                        $no_data = 0;
                                                                        //                                        print "<p>". $message . $agencynode->title .".</p>";
                                                                        //                                      }
                                                                        //        print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">JS Frameworks :";
                                                                        //        foreach($agencydata['ag_js'] as $akey=>$aval){
                                                                        //         print "$akey($aval) ";
                                                                        //        }
                                                                        //        print "</span></div>";
                                                                        //       }

                                                                        if ( $agencydata[ 'ag_cdn' ] != '' ) {
                                                                            if ( $no_data == 1 ) {
                                                                                $no_data = 0;
                                                                                print "<p>" . $message . $agencynode->title . ".</p>";
                                                                            }
                                                                            print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">CDN :";
                                                                            foreach ( $agencydata[ 'ag_cdn' ] as $akey => $aval ) {
                                                                                print "$akey($aval) ";
                                                                            }
                                                                            print "</span></div>";
                                                                        }

                                                                        if ( $no_data == 1 ) {
                                                                            print "<div><span style='font-size: 12px;font-style: italic;color: darkred;'>Data is not currently available.</span></div>";
                                                                        }
                                                                        ?>
                                                                    </div>
                                                                </div>
                                                                <!--                                  <div class="view-button" style="margin-left:15px;"><br>-->
                                                                <!--                                    <p><a class="link-all-reports" href="/technology-overview?field_web_agency_id_nid=-->
                                                                <?//=$curuserAgency?>
                                                                <!--">Go to Full Report</a> </p>-->
                                                                <!--                                  </div>-->
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
                        <!-- /.pond -->

                    </div>
                </section>
            </div>
        </section>
    </div>
</div>