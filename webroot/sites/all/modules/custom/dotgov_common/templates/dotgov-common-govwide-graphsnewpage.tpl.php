<style>
   .page-overall-gov-wide-compliance .view-wrapper {
   min-height: 430px;
   }
   .font-italic {
   font-style:italic;
   }
   .panel-pane h2.pane-title{
   height:40px;
   }
   .white-back{
   min-height:530px!important;
   height:auto;
   }
   .no-height{
   min-height:150px!important;
   height:auto!important;
   }
   .min-295 {
   min-height: 295px;
   }
   .min-300 {
   min-height: 300px;
   }
</style>
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
   $labeldesc['avg_uswds'] = 'USWDS Score';

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
   $agency_uswds_score = $govwidedata['actualdata']['avg_uswds'];

   $agencydata = dotgov_common_getAllAgencyComplianceData();
   dotgov_common_tooltip("tooltip2", "id");
   dotgov_common_tooltip("tooltip4", "id");
   dotgov_common_tooltip("tooltip3", "id");
   dotgov_common_tooltip("tooltip5", "id");
   dotgov_common_tooltip("tooltip7", "id");
   dotgov_common_tooltip("tooltip6", "id");
   dotgov_common_tooltip("tooltip9", "id");
   dotgov_common_tooltip("tooltip8", "id");
   dotgov_common_tooltip("tooltip10", "id");
   
   $mobperf_arr = array($agencydata['good_nos'], $agencydata['improve_nos'], $agencydata['poor_nos'], $agencydata['data_na_nos']);
   $mobperf_arr = dotgov_common_get_percentage($mobperf_arr, $agency_website_num);
   $mobusab_arr = array($agencydata['friendly_nos'], $agencydata['nonfriendly_nos'], $agencydata['data_na_usab_nos']);
   $mobusab_arr = dotgov_common_get_percentage($mobusab_arr, $agency_website_num);

   $dnssec_arr = array($agencydata['dns_compliant'], $agencydata['dns_noncompliant']);
   $dnssec_arr = dotgov_common_get_percentage($dnssec_arr, $agency_website_num);

   $enfhttps_arr = array($agencydata['enfhttps_support'], $agencydata['enfhttps_nosupport']);
   $enfhttps_arr = dotgov_common_get_percentage($enfhttps_arr, $agency_website_num);
   $hsts_arr = array($agencydata['hsts_support'], $agencydata['hsts_nosupport']);
   $hsts_arr = dotgov_common_get_percentage($hsts_arr, $agency_website_num);
   $https_arr = array($agencydata['https_support'], $agencydata['https_nosupport']);
   $https_arr = dotgov_common_get_percentage($https_arr, $agency_website_num);
   $preload_arr = array($agencydata['preload_support'], $agencydata['preload_nosupport'], $agencydata['preload_readysupport']);
   $preload_arr = dotgov_common_get_percentage($preload_arr, $agency_website_num);

   $m15_arr = array($agencydata['m15_compliant'], $agencydata['m15_noncompliant']);
   $m15_arr = dotgov_common_get_percentage($m15_arr, $agencydata['m15_tracked']);
   $ipv6_arr = array($agencydata['ipv6_compliant'], $agencydata['ipv6_noncompliant']);
   $ipv6_arr = dotgov_common_get_percentage($ipv6_arr, $agency_website_num);
   $dap_arr = array($agencydata['dap_compliant'], $agencydata['dap_noncompliant']);
   $dap_arr = dotgov_common_get_percentage($dap_arr, $agencydata['dap_tottracked']);
   $insecprot_arr = array($agencydata['insec_compliant'], $agencydata['insec_noncompliant']);
   $insecprot_arr = dotgov_common_get_percentage($insecprot_arr, $agencydata['free_tracked']);
   $uswds_arr = array($agencydata['uswds_compliant'], $agencydata['uswds_noncompliant']);
   $uswds_arr = dotgov_common_get_percentage($uswds_arr, $agencydata['uswds_tottracked']);
   ?>
<?php //print_r($govwidedata);print_r($agencydata);  ?>
<div class="row">
   <div class="col-sm-12 nopadding">
      <div class="graph-container">
         <div class="out-wrapper">
            <div class="col-xs-12 nopadding clearfix">
              <div class="col-xs-12 col-lg-6">
                <div class="white-back no-height">
                  <div class="panel-pane pane-views pane-website-information">
                    <div class="col-xs-12 nopadding">
                      <div class="col-xs-10 nopadding">
                        <h2 class="pane-title"> Mobile Information </h2>
                      </div>
                      <div class="col-xs-2 nopadding">
                        <div id="tooltip4" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon"> <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart_mobile.png" alt="Image for the color code"><br>
                              Mobile Data is collected from Google API through a scan that last ran on
                              <?php dotgov_common_lastScanDate();?>
                              </span>
                        </div>
                      </div>
                      <br clear="all"/>
                    </div>
                    <div class="pane-content clearfix">
                      <div class="view  view-display-id-block_6 view-dom-id-146fb84eddbe3dc34d2b2cff5758c7bc">
                        <div class="view-content">
                          <div class="view-wrapper-new clearfix">
                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                              <div class="col-xs-12 clearfix">
                                <div class="views-field views-field-php-2 col-lg-6 nopadding grey-gradient" style="height:250px;">
                                  <div class ="col-md-12 col-lg-12" style="padding-left:10px;">
                                    <h5>Mobile Performance Breakdown</h5>
                                  </div>
                                  <div class="col-lg-6 col-md-6" style="padding-right:0px;margin-top:15px;padding-left:10px;font-size: 12px">
                                    <span class="dot good"></span>Good<br/>
                                    <span class="dot avg"></span>Needs Improvement <br/>
                                    <span class="dot low"></span>Poor <br/>
                                    <span class="dot na"></span>Data Not Available<br/>
                                  </div>
                                  <div class="col-lg-6 col-md-6 nopadding">
                                    <div id="piechart1" style="margin-top:-17px;height:140px;"></div>
                                    <?php print $agencydata['gov_mob_chart'];?>
                                  </div>
                                  <table style="width:100%">
                                    <th style="background-color: #215393;color: white;"> Breakdown </th>
                                    <th style="background-color: #215393;color: white;"> Websites </th>
                                    <tr>
                                      <td>Good</td>
                                      <td><?=dotgov_common_getColor($agencydata['good_nos'], '#276437', $mobperf_arr[0])?></td>
                                    </tr>
                                    <tr>
                                      <td>Needs Improvement</td>
                                      <td><?=dotgov_common_getColor($agencydata['improve_nos'], '#665000', $mobperf_arr[1])?></td>
                                    </tr>
                                    <tr>
                                      <td>Poor</td>
                                      <td><?=dotgov_common_getColor($agencydata['poor_nos'], '#ae0100', $mobperf_arr[2])?></td>
                                    </tr>
                                    <tr>
                                      <td>Data Not Available</td>
                                      <td><?=dotgov_common_getColor($agencydata['data_na_nos'], '#337ab7', $mobperf_arr[3])?></td>
                                    </tr>
                                  </table>
                                </div>
                                <div class="col-xs-12 col-lg-6 nopadding grey-gradient second" style="height:250px;">
                                  <div class ="col-md-12 col-lg-12" style="padding-left:10px;">
                                    <h5>Mobile Usability Breakdown
                                  </div>
                                  <div class="col-lg-6 col-md-6" style="padding-right:0px;margin-top:15px;padding-left:10px;font-size: 12px">
                                    <span class="dot good"></span>Mobile Friendly <br/>
                                    <span class="dot low"></span>Not Mobile Friendly <br/>
                                    <span class="dot na"></span>Data Not Available <br/>
                                  </div>
                                  <div class="col-lg-6 col-md-6 nopadding">
                                    <div id="piechartusab" style="margin-top:-17px;height:140px;"></div>
                                    <?php print $agencydata['gov_mob_usab_chart'];?>
                                  </div>
                                  <table style="width:100%">
                                    <th style="background-color: #215393;color: white;"> Breakdown </th>
                                    <th style="background-color: #215393;color: white;"> Websites </th>
                                    <tr>
                                      <td>Mobile Friendly</td>
                                      <td><?=dotgov_common_getColor($agencydata['friendly_nos'], '#276437', $mobusab_arr[0])?></td>
                                    </tr>
                                    <tr>
                                      <td>Not Mobile Friendly</td>
                                      <td><?=dotgov_common_getColor($agencydata['nonfriendly_nos'], '#ae0100', $mobusab_arr[1])?></td>
                                    </tr>
                                    <tr>
                                      <td>Data Not Available</td>
                                      <td><?=dotgov_common_getColor($agencydata['data_na_usab_nos'], '#337ab7', $mobusab_arr[2])?></td>
                                    </tr>
                                  </table>
                                </div>
                              </div>
                            </div>
                          </div>
                          <br clear="all" />
                          <div class='col-lg-12 text-center clearfix'><span style='color:#29643a; font-size: 10px;font-style: italic;'>
                                       Above graphs show the breakdown of Mobile Performance and Mobile Usability</span></div>
                          <br clear="all" />
                          <div class="view-button clearfix">
                            <div class="row text-center">
                              <a class="" href="/mobile/report"> <img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt=""/></a>
                              <a href="/improve-my-score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt=""/></a>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div class="col-xs-12 col-lg-6">
                  <div class="white-back no-height">
                     <div class="panel-pane pane-views pane-website-information">
                        <div class="col-xs-10 nopadding">
                           <h2 class="pane-title">Accessibility Spot Checks</h2>
                        </div>
                        <div class="col-xs-2 nopadding">
                           <div id="tooltip9" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon"> <span class="tooltiptext tooltip-left"> <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br/>
                              Accessibility Data is collected from pulse.gov website though a scan that last ran on
                              <?php dotgov_common_lastScanDate();?>
                              </span>
                           </div>
                        </div>
                        <br clear="all"/>
                        <div class="pane-content clearfix">
                           <div class="view-wrapper" style="min-height:290px;">
                              <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                 <div class="view-empty clearfix">
                                    <div class="col-lg-6 grey-gradient" style="height:250px;">
                                       <div class ="col-md-12 col-lg-12 nopadding" >
                                          <h5>Accessibility Issues by Type</h5>
                                       </div>
                                       <div class="col-md-12 col-lg-12 nopadding" style="margin:27px 0;">
                                          <p>Average Color Contrast:
                                             <?=round($agencydata['ag_col_contrast'] / $agency_website_num, 1);?>
                                          </p>
                                          <p> Average HTML Attribute :
                                             <?=round($agencydata['ag_html_attrib'] / $agency_website_num, 1);?>
                                          </p>
                                          <p>Average Missing Image Description:
                                             <?=round($agencydata['ag_miss_image'] / $agency_website_num, 1);?>
                                          </p>
                                          <span style="font-size:12px;">(Note: Website redirects are excluded. Accessibility Spot Checks include only Color Contrast, HTML Attributes and Missing Image Description Accessibility Issues)</span>
                                       </div>
                                    </div>
                                    <div class="col-lg-6 grey-gradient second" style="height:250px;">
                                       <div class ="col-md-12 col-lg-12 nopadding" >
                                          <h5>Average Accessibility Issues by Type per Website</h5>
                                       </div>
                                       <div  class="clearfix"></div>
                                       <div id="piechart"></div>
                                    </div>
                                    <script language="JavaScript">
                                       google.charts.load('current', {'packages':['corechart']});
                                       google.charts.setOnLoadCallback(drawChart);

                                       function drawChart() {

                                           var data = google.visualization.arrayToDataTable([
                                               ['Type', 'Number'],
                                               ['Color Contrast Issues',     <?php echo number_format($agencydata['ag_col_contrast'], 1, '.', ''); ?>],
                                               ['HTML Attribute Issues',      <?php echo number_format($agencydata['ag_html_attrib'], 1, '.', ''); ?>],
                                               ['Missing Image Description Issues',  <?php echo number_format($agencydata['ag_miss_image'], 1, '.', ''); ?>]
                                           ]);
                                           var options = {
                                               colors: ['#7cb5ec', '#90ed7d', '#434348'],
                                               sliceVisibilityThreshold: 0,
                                               dataLabels: {
                                                   enabled: true
                                               },
                                               showInLegend: true,
                                               backgroundColor:"transparent",
                                               chartArea:{left:0,top:20,width:'100%',height:'50%'},
                                               legend:{position:'left',alignment:'center'}
                                           };

                                           var chart = new google.visualization.PieChart(document.getElementById('piechart'));

                                           chart.draw(data, options);
                                             var svgTags = document.querySelectorAll('#piechart svg');
                                             var c = document.createElement('canvas');
                                             c.width = svgTags.clientWidth;
                                             c.height = svgTags.clientHeight;
                                             svgTags.parentNode.insertBefore(c, svgTags);
                                             var div = document.createElement('div');
                                             div.appendChild(svgTags);
                                             canvg(c, div.innerHTML);
                                       }
                                    </script>
                                    <?php
                                       if (($agencydata['ag_col_contrast'] + $agencydata['ag_html_attrib'] + $agencydata['ag_miss_image']) != 0) {
                                          print "<div class='col-lg-12 text-center clearfix'><span style='color:#29643a; font-size: 10px;font-style: italic;'>
                                                                              Above graph shows the breakdown of Accessibility Issues by category</span></div>
                                                                              ";
                                       }
                                       ?>
                                 </div>
                              </div>
                           </div>
                           <div class="view-button">
                              <div class="row text-center">
                                 <a href="/accessibilityreportalldomains"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt=""/></a>
                                 <a href="/improve-my-score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt=""/></a>
                              </div>
                           </div>
                        </div>
                     </div>
                  </div>
               </div>
            </div>
         </div>
         <div class="panel-separator clearfix"></div>
         <div class="out-wrapper">
            <div class="col-xs-12 nopadding clearfix">
               <div class="col-xs-12 col-lg-6">
                  <div class="white-back no-height">
                     <div class="col-xs-10 nopadding">
                        <h2 class="pane-title">DNSSEC Information</h2>
                     </div>
                     <div class="col-xs-2 nopadding">
                        <div id="tooltip5" class="infor"> <img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon"> <span class="tooltiptext tooltip-left"> <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
                           DNSSEC Data is collected through a custom scanner component of dotgov dashboard that last ran on
                           <?php dotgov_common_lastScanDate();?>
                           </span>
                        </div>
                     </div>
                     <br clear="all" />
                     <div class="pane-content">
                        <div class="view  view-display-id-block_7 view-dom-id-3e71e61814bfdc7fd3678ddb5e0c33c9">
                           <div class="view-content">
                              <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                 <div class="views-field views-field-nothing">
                                    <div class="field-content col-lg-12">
                                       <div class="view-wrapper" style="min-height:325px">
                                          <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient" style="height:165px;">
                                             <h5>DNSSEC Score Breakdown</h5>
                                             <table width="100%" class="dnssec-table">
                                                <th style="background-color: #215393;color: white;">Breakdown</th>
                                                <th style="background-color: #215393;color: white;">Websites</th>
                                                <tr>
                                                   <td>DNSSEC Compliant Websites</td>
                                                   <td><?=dotgov_common_getColor($agencydata['dns_compliant'], '#29643a', $dnssec_arr[0])?></td>
                                                </tr>
                                                <tr>
                                                   <td>DNSSEC Non Compliant Websites</td>
                                                   <td><?=dotgov_common_getColor($agencydata['dns_noncompliant'], '#ac0600', $dnssec_arr[1])?></td>
                                                </tr>
                                             </table>
                                          </div>
                                          <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient second" style="height:165px;">
                                             <h5>DNSSEC Overall Average Score :
                                                <?=$agency_dnssec_score?>
                                                %
                                             </h5>
                                             <div class="col-lg-6 col-xs-12" style="padding-left:0;font-size:12px;">When DNSSEC protocol is enabled, the score is 100 for compliance and zero is for non-compliance</div>
                                             <div class="col-lg-6 col-xs-12 nopadding">
                                                <div id="dnssec_chart" style="height:120px;width:120px;">&nbsp;</div>
                                             </div>
                                             <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                             <script type="text/javascript">
                                                Highcharts.chart( 'dnssec_chart', {

                                                        chart: {
                                                            type: 'solidgauge',
                                                            backgroundColor: 'transparent'

                                                        },
                                                        credits: {
                                                            enabled: false
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

                                                        series: [ {
                                                            name: 'DNSSEC Chart',
                                                            data: [ {
                                                                color: '<?php echo dotgov_common_getChartColor($agency_dnssec_score); ?>',
                                                                radius: '118%',
                                                                innerRadius: '80%',
                                                                y: <?php echo trim($agency_dnssec_score); ?>
                                                            } ]
                                                        } ]
                                                    }


                                                );
                                                var svgTags = document.querySelectorAll('#dnssec_chart svg');
                                                var c = document.createElement('canvas');
                                                c.width = svgTags.clientWidth;
                                                c.height = svgTags.clientHeight;
                                                svgTags.parentNode.insertBefore(c, svgTags);
                                                var div = document.createElement('div');
                                                div.appendChild(svgTags);
                                                canvg(c, div.innerHTML);
                                             </script>
                                          </div>
                                          <div class="col-xs-12 col-lg-12">
                                             <?php
                                                $blockObject4 = block_load('trend_analysis', 'agency_dnssec');
                                                $block4 = _block_get_renderable_array(_block_render_blocks(array($blockObject4)));
                                                $output4 = drupal_render($block4);
                                                print "$output4<br><div class='col-lg-12 text-center clearfix'><span style='color: " . dotgov_common_getChartColor($agency_dnssec_score) . ";font-size: 10px;font-style: italic;'>Above graph represents a monthly DNSSEC Trend</span></div>";
                                                ?>
                                          </div>
                                       </div>
                                       <div class="view-button">
                                          <div class="row text-center">
                                             <a class="" href="/website/all/reports"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt=""/></a>
                                             <a href="/improve-my-score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt=""/></a>
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
               <div class="col-xs-12 col-lg-6">
                  <div class="white-back no-height">
                     <div class="col-xs-10 nopadding">
                        <h2 class="pane-title"> On-Site Search Information </h2>
                     </div>
                     <div class="col-xs-2 nopadding">
                        <div id="tooltip5" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">
                           <span class="tooltiptext tooltip-left">
                           On-Site Search Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate();?> </span>
                        </div>
                     </div>
                     <br clear="all" />
                     <div class="pane-content">
                        <div class="view-wrapper" style="min-height:325px">
                           <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                              <div class="view-empty">
                                 <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient pie-chart" >
                                    <div id="piechart3"></div>
                                    <?php print $agencydata['searchengines_graph'];
                                       //print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engines</span>";
                                       ?>
                                    <table style="width:100%">
                                       <tr style="background-color: #215393;color: white;">
                                          <td>On-Site Search Engine</td>
                                          <td>&nbsp;Total</td>
                                       </tr>
                                       <?php
                                          foreach ($agencydata['searchenginedata'] as $skey => $sval) {
                                             print "<tr style='text-transform: capitalize;'><td>" . ucfirst($skey) . "</td><td align='center'>   $sval</td> </tr>";
                                          }
                                          ?>
                                    </table>
                                 </div>
                                 <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient min-300 second bar-chart" >
                                    <div id="piechart2"></div>
                                    <?php print $agencydata['searchenginestatus_graph'];
                                       //print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engines by category</span>";
                                       $searchenginestatus = $agencydata['searchenginestatus'];
                                       ?>
                                    <table>
                                       <tr style="background-color: #215393;color: white;">
                                          <td> On-Site Search Available</td>
                                          <td>On-Site Search Not Available</td>
                                       </tr>
                                       <tr>
                                          <td><?=($searchenginestatus['search_available'] == "") ? 0 : $searchenginestatus['search_available']?></td>
                                          <td><?=($searchenginestatus['search_notavailable'] == "") ? 0 : $searchenginestatus['search_notavailable']?></td>
                                       </tr>
                                    </table>
                                    <span style="font-size:12px;">(Note: website redirects are excluded)</span>
                                 </div>
                              </div>
                              <div class="clearfix">&nbsp;</div>
                           </div>
                        </div>
                        <div class="view-button clearfix">
                           <div class="row text-center">
                              <a class="" href="/website/search/reports"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt=""/></a>
                              <a href="/improve-my-score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt=""/></a>
                           </div>
                        </div>
                     </div>
                  </div>
               </div>
            </div>
         </div>
         <div class="panel-separator clearfix"></div>
         <div class="out-wrapper">
            <div class="col-xs-12 nopadding clearfix">
               <div class="col-xs-12  col-lg-4">
                  <div class="white-back">
                     <div class="panel-pane pane-views pane-website-information">
                        <?php
                         echo trim(dotgov_common_title('HTTPS'));
                         echo trim(dotgov_common_info_icon("HTTPS Data is collected through a custom scanner component of digital dashboard that last ran on", "tooltip2", dotgov_common_lastScanDateStr()));
                        ?>
                        <br clear="all"/>
                        <div class="pane-content">
                           <div class="view-wrapper">
                              <div class="grey-gradient clearfix">
                                 <div class="col-xs-12 height-wrap-first">
                                    <h5>HTTPS score breakdown</h5>
                                    <?php
                                     echo trim(dotgov_common_subtext("HTTPS", $agency_https_score, "The individual site score is based on several different metrics. See scoring methods for more info."));
                                    ?>
                                    <div class="col-sm-12 col-lg-6 nopadding">
                                       <div id="https_chart">&nbsp;</div>
                                       <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                       <script type="text/javascript">
                                          Highcharts.chart( 'https_chart', {

                                                  chart: {
                                                      type: 'solidgauge',
                                                      backgroundColor: 'transparent'

                                                  },
                                                  credits: {
                                                      enabled: false
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

                                                  series: [ {
                                                      name: 'Free of Insecure Protocol Chart',
                                                      data: [ {
                                                          color: '<?php echo dotgov_common_getChartColor($agency_https_score); ?>',
                                                          radius: '118%',
                                                          innerRadius: '80%',
                                                          y: <?php echo trim($agency_https_score); ?>
                                                      } ]
                                                  } ]
                                              }


                                          );
                                          var svgTags = document.querySelectorAll('#https_chart svg');
                                                var c = document.createElement('canvas');
                                                c.width = svgTags.clientWidth;
                                                c.height = svgTags.clientHeight;
                                                svgTags.parentNode.insertBefore(c, svgTags);
                                                var div = document.createElement('div');
                                                div.appendChild(svgTags);
                                                canvg(c, div.innerHTML);
                                       </script>
                                    </div>
                                 </div>
                                 <table width="100%">
                                    <th style="background-color: #215393;color: white;">Criteria</th>
                                    <th style="background-color: #215393;color: white">Supporting Websites </th>
                                    <th style="background-color: #215393;color: white">Non Supporting Websites </th>
                                    <tr>
                                       <td>Enforce HTTPS</td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['enfhttps_support'], '#29643a', $enfhttps_arr[0])?></td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['enfhttps_nosupport'], '#ac0600', $enfhttps_arr[1])?></td>
                                    </tr>
                                    <tr>
                                       <td>HSTS Status</td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['hsts_support'], '#29643a', $hsts_arr[0])?></td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['hsts_nosupport'], '#ac0600', $hsts_arr[1])?></td>
                                    </tr>
                                    <tr>
                                       <td>HTTPS Status</td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['https_support'], '#29643a', $https_arr[0])?></td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['https_nosupport'], '#ac0600', $https_arr[1])?></td>
                                    </tr>
                                    <tr>
                                       <td>Preload Status</td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['preload_support'], '#29643a', $preload_arr[0])?></td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['preload_nosupport'], '#ac0600', $preload_arr[1])?></td>
                                    </tr>
                                    <tr>
                                       <td>Preload Ready</td>
                                       <td align="center"><?=dotgov_common_getColor($agencydata['preload_readysupport'], '#29643a', $preload_arr[2])?></td>
                                       <td align="center">NA</td>
                                    </tr>
                                 </table>
                                 <span class="col-xs-12 clearfix text-center" style="font-size:10px;">(website redirects are excluded)</span>
                              </div>
                              <div class="row">
                                 <?php
                                    $blockObject3 = block_load('trend_analysis', 'agency_https');
                                    $block3 = _block_get_renderable_array(_block_render_blocks(array($blockObject3)));
                                    $output3 = drupal_render($block3);
                                    print "$output3 <span class='col-xs-12 text-center clearfix' style='color: " . dotgov_common_getChartColor($agency_https_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly HTTPS Trend</span>";
                                    ?>
                              </div>
                           </div>
                           <?php echo trim(dotgov_common_footer()); ?>
                        </div>
                     </div>
                  </div>
               </div>
               <div class="col-xs-12 col-lg-4">
                  <div class="white-back">
                     <?php
                       echo trim(dotgov_common_title('M-15-13 and BOD 18-01'));
                       echo trim(dotgov_common_info_icon("M-15-13 and BOD 18-01 Data is collected through a custom scanner component of dotgov dashboard that last ran on", "tooltip7", dotgov_common_lastScanDateStr()));
                     ?>
                     <br clear="all"/>
                     <div class="pane-content clearfix">
                        <div class="view  view-display-id-block_10 view-dom-id-93e7fd06306700be9064f5e8954f211b">
                           <div class="view-content">
                              <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                 <div class="views-field views-field-php-2 col-lg-12">
                                    <div class="view-wrapper">
                                       <div class="grey-gradient clearfix min-295">
                                          <div class="col-xs-12 height-wrap-first">
                                             <h5>M-15-13 and BOD 18-01 score breakdown</h5>
                                             <?php
                                              echo trim(dotgov_common_subtext("Compliant with M-15-13 and BOD 18-01", $agency_m15_score, "The individual site score is 100 for compliant 0 for non-compliant", "col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding"));
                                             ?>
                                             <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding">
                                                <div id="m1513_chart">&nbsp;</div>
                                                <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                <script type="text/javascript">
                                                   Highcharts.chart( 'm1513_chart', {

                                                           chart: {
                                                               type: 'solidgauge',
                                                               backgroundColor:'transparent'

                                                           },
                                                           credits: {
                                                               enabled: false
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

                                                           series: [ {
                                                               name: 'M-15-13 Chart',
                                                               data: [ {
                                                                   color: '<?php echo dotgov_common_getChartColor($agency_m15_score); ?>',
                                                                   radius: '118%',
                                                                   innerRadius: '80%',
                                                                   y: <?php echo trim($agency_m15_score); ?>
                                                               } ]
                                                           } ]
                                                       }


                                                   );

                                                   var svgTags = document.querySelectorAll('#m1513_chart svg');
                                                var c = document.createElement('canvas');
                                                c.width = svgTags.clientWidth;
                                                c.height = svgTags.clientHeight;
                                                svgTags.parentNode.insertBefore(c, svgTags);
                                                var div = document.createElement('div');
                                                div.appendChild(svgTags);
                                                canvg(c, div.innerHTML);
                                                </script>
                                             </div>
                                          </div>
                                          <table width="100%">
                                             <th style="background-color: #215393;color: white;"> Breakdown </th>
                                             <th style="background-color: #215393;color: white;"> Websites </th>
                                             <tr>
                                                <td>M-15-13 and BOD 18-01 Compliant Websites </td>
                                                <td><?=dotgov_common_getColor($agencydata['m15_compliant'], '#29643a', $m15_arr[0])?></td>
                                             </tr>
                                             <tr>
                                                <td>M-15-13 and BOD 18-01 Non Compliant Websites </td>
                                                <td><?=dotgov_common_getColor($agencydata['m15_noncompliant'], '#ac0600', $m15_arr[1])?></td>
                                             </tr>
                                          </table>
                                          <span class="col-xs-12 text-center clearfix" style="font-size:10px;">(website redirects are excluded)</span>
                                       </div>
                                       <div class="col-xs-12 clearfix">
                                          <?php
                                             $blockObject2 = block_load('trend_analysis', 'agency_m15');
                                             $block2 = _block_get_renderable_array(_block_render_blocks(array($blockObject2)));
                                             $output2 = drupal_render($block2);
                                             print "$output2 <span class='col-xs-12 text-center'style='color: " . dotgov_common_getChartColor($agency_m15_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly M-15-13 Trend</span>";
                                             ?>
                                       </div>
                                    </div>
                                    <?php echo trim(dotgov_common_footer()); ?>
                                 </div>
                              </div>
                           </div>
                        </div>
                     </div>
                  </div>
               </div>
               <div class="col-xs-12 col-lg-4">
                  <div class="white-back">
                     <?php
                       echo trim(dotgov_common_title('IPV6'));
                       echo trim(dotgov_common_info_icon("IPV6 Data is collected through a custom scanner component of dotgov dashboard that last ran on", "tooltip6", dotgov_common_lastScanDateStr()));
                     ?>
                     <br clear="all"/>
                     <div class="pane-content clearfix">
                        <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                           <div class="view-content">
                              <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                 <div class="views-field views-field-nothing">
                                    <div class="field-content col-lg-12">
                                       <div class="view-wrapper">
                                          <div class="grey-gradient clearfix min-295">
                                             <div class="col-xs-12 height-wrap-first">
                                                <h5>IPV6 score breakdown</h5>
                                                <?php
                                                  echo trim(dotgov_common_subtext("IPV6", $agency_ipv6_score, "The individual site score is 100 for compliant 0 for non-compliant", "col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding"));
                                                ?>
                                                <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding">
                                                   <div id="ipv6_chart">&nbsp;</div>
                                                   <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                                   <script type="text/javascript">
                                                      Highcharts.chart( 'ipv6_chart', {

                                                              chart: {
                                                                  type: 'solidgauge',
                                                                  backgroundColor:'transparent'

                                                              },
                                                              credits: {
                                                                  enabled: false
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

                                                              series: [ {
                                                                  name: 'Free of Insecure Protocol Chart',
                                                                  data: [ {
                                                                      color: '<?php echo dotgov_common_getChartColor($agency_ipv6_score); ?>',
                                                                      radius: '118%',
                                                                      innerRadius: '80%',
                                                                      y: <?php echo trim($agency_ipv6_score); ?>
                                                                  } ]
                                                              } ]
                                                          }


                                                      );

                                                      var svgTags = document.querySelectorAll('#ipv6_chart svg');
                                                      var c = document.createElement('canvas');
                                                      c.width = svgTags.clientWidth;
                                                      c.height = svgTags.clientHeight;
                                                      svgTags.parentNode.insertBefore(c, svgTags);
                                                      var div = document.createElement('div');
                                                      div.appendChild(svgTags);
                                                      canvg(c, div.innerHTML);
                                                   </script>
                                                </div>
                                             </div>
                                             <table width="100%">
                                                <th style="background-color: #215393;color: white;"> Breakdown </th>
                                                <th style="background-color: #215393;color: white;"> Websites </th>
                                                <tr width="100%">
                                                   <td>IPv6 Compliant Websites</td>
                                                   <td><?=dotgov_common_getColor($agencydata['ipv6_compliant'], '#29643a', $ipv6_arr[0])?></td>
                                                </tr>
                                                <tr width="100%">
                                                   <td>IPv6 Non Compliant Websites</td>
                                                   <td><?=dotgov_common_getColor($agencydata['ipv6_noncompliant'], '#ac0600', $ipv6_arr[1])?></td>
                                                </tr>
                                             </table>
                                             <span class="col-xs-12 text-center clearfix" style="font-size:10px;">(website redirects are excluded)</span>
                                          </div>
                                          <div class="row">
                                             <?php
                                                $blockObject7 = block_load('trend_analysis', 'agency_ipv6');
                                                $block7 = _block_get_renderable_array(_block_render_blocks(array($blockObject7)));
                                                $output7 = drupal_render($block7);
                                                print "$output7 <span class='col-xs-12 nopadding text-center' style='color: " . dotgov_common_getChartColor($agency_ipv6_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly IPv6 Trend</span>";
                                                ?>
                                          </div>
                                       </div>
                                       <?php echo trim(dotgov_common_footer()); ?>
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
         <div class="panel-separator clearfix"></div>
         <div class="out-wrapper">
            <div class="col-xs-12 nopadding clearfix">
               <div class="col-xs-12 col-lg-4">
                  <div class="white-back">
                     <?php
                      echo trim(dotgov_common_title("DAP"));
                     ?>
                     <div class="col-xs-2 nopadding">
                        <div id="tooltip3" class="infor">
                           <img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">
                           <span class="tooltiptext tooltip-left">
                           <img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code"><br>
                           DAP Overall Average Score :
                           <?=$agency_dap_score?>%
                           </span>
                        </div>
                     </div>
                     <br clear="all"/>
                     <div class="pane-content clearfix">
                        <div class="view-wrapper">
                           <div class="view-content">
                              <div class="field-content col-lg-12 nopadding">
                                 <div class="grey-gradient clearfix">
                                    <div class="col-xs-12">
                                       <h5>DAP score breakdown</h5>
                                    </div>
                                    <div class = "col-xs-12" style="min-height:55px;">
                                       <p>DAP Overall Average Score :
                                          <?=$agency_dap_score?>
                                          %
                                       </p>
                                    </div>
                                    <div style="display:block; float:left;min-height:145px; width:100%;">
                                       <div class="col-xs-12-col-sm-12 col-lg-6" style="margin-top: 30px;">
                                          <span style="font-size:12px;" class="font-italic">The individual site score is 100 for compliant 0 for non-compliant</span>
                                       </div>
                                       <div class = "col-xs-12-col-sm-12 col-lg-6">
                                          <div id="dap_chart">&nbsp;</div>
                                          <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                          <script type="text/javascript">
                                             Highcharts.chart( 'dap_chart', {

                                                     chart: {
                                                         type: 'solidgauge',
                                                         backgroundColor:'transparent'

                                                     },
                                                     credits: {
                                                         enabled: false
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

                                                     series: [ {
                                                         name: 'DAP Chart',
                                                         data: [ {
                                                             color: '<?php echo dotgov_common_getChartColor($agency_dap_score); ?>',
                                                             radius: '118%',
                                                             innerRadius: '80%',
                                                             y: <?php echo trim($agency_dap_score); ?>
                                                         } ]
                                                     } ]
                                                 }


                                             );

                                                var svgTags = document.querySelectorAll('#dap_chart svg');
                                                var c = document.createElement('canvas');
                                                c.width = svgTags.clientWidth;
                                                c.height = svgTags.clientHeight;
                                                svgTags.parentNode.insertBefore(c, svgTags);
                                                var div = document.createElement('div');
                                                div.appendChild(svgTags);
                                                canvg(c, div.innerHTML);


                                          </script>
                                       </div>
                                    </div>
                                    <table style="width:100%;">
                                       <th style="background-color: #215393;color: white;border: 1px;"> Breakdown </th>
                                       <th style="background-color: #215393;color: white;border: 1px;"> Websites </th>
                                       <tr>
                                          <td> DAP Compliant Websites</td>
                                          <td><?=dotgov_common_getColor($agencydata['dap_compliant'], '#29643a', $dap_arr[0])?></td>
                                       </tr>
                                       <tr>
                                          <td>DAP Non Compliant Websites</td>
                                          <td><?=dotgov_common_getColor($agencydata['dap_noncompliant'], '#ac0600', $dap_arr[1])?></td>
                                       </tr>
                                    </table>
                                    <div class="col-xs-12 clearfix">
                                       <span class="text-center col-xs-12" style="font-size:10px;">(Note: website redirects are excluded)</span>
                                    </div>
                                 </div>
                                 <div class="col-xs-12 nopadding clearfix"> <?php
                                    $blockObject6 = block_load('trend_analysis', 'agency_dap');
                                    $block6 = _block_get_renderable_array(_block_render_blocks(array($blockObject6)));
                                    $output6 = drupal_render($block6);
                                    print "$output6 <br><span class='col-xs-12 clearfix text-center' style='color: " . dotgov_common_getChartColor($agency_dap_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly DAP Trend</span>";
                                    ?>
                                 </div>
                              </div>
                           </div>
                        </div>
                        <?php echo trim(dotgov_common_footer()); ?>
                     </div>
                  </div>
               </div>
               <div class="col-xs-12 col-lg-4">
                  <div class="white-back">
                     <?php
                       echo trim(dotgov_common_title('Free of Insecure Protocols'));
                       echo trim(dotgov_common_info_icon("Free of RC4/3DES and SSLv2/SSLv3 Data is collected through a custom scanner component of dotgov dashboard that last ran on", "tooltip8", dotgov_common_lastScanDateStr()));
                     ?>
                     <br clear="all" />
                     <div class="pane-content clearfix">
                        <div class="view-wrapper">
                           <div class="grey-gradient clearfix">
                              <div class="col-xs-12 clearfix">
                                 <h5>Free of RC4/3DES and SSLv2/SSLv3 score breakdown</h5>
                              </div>
                              <div class="col-xs-12" style="min-height:55px;">
                                 <p>Free of RC4/3DES and SSLv2/SSLv3 Overall Average Score :
                                    <?=$agency_insecprot_score?>
                                    %
                                 </p>
                              </div>
                              <div style="display:block; float:left;min-height:145px;width:100%">
                                 <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6"  style="margin-top: 30px;" >
                                    <span style="font-size:12px;" class="font-italic">The individual site score is 100 for compliant 0 for non-compliant</span>
                                 </div>
                                 <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6">
                                    <div id="freeofinsecureprot_chart">&nbsp;</div>
                                    <div class="sr-only">The graphic below indicates the level of HTTPS compliance, and this score is 100%.</div>
                                    <script type="text/javascript">
                                       Highcharts.chart( 'freeofinsecureprot_chart', {

                                               chart: {
                                                   type: 'solidgauge',
                                                   backgroundColor:'transparent'

                                               },
                                               credits: {
                                                   enabled: false
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

                                               series: [ {
                                                   name: 'Free of Insecure Protocol Chart',
                                                   data: [ {
                                                       color: '<?php echo dotgov_common_getChartColor($agency_insecprot_score); ?>',
                                                       radius: '118%',
                                                       innerRadius: '80%',
                                                       y: <?php echo trim($agency_insecprot_score); ?>
                                                   } ]
                                               } ]
                                           }


                                       );

                                             var svgTags = document.querySelectorAll('#freeofinsecureprot_chart svg');
                                             var c = document.createElement('canvas');
                                             c.width = svgTags.clientWidth;
                                             c.height = svgTags.clientHeight;
                                             svgTags.parentNode.insertBefore(c, svgTags);
                                             var div = document.createElement('div');
                                             div.appendChild(svgTags);
                                             canvg(c, div.innerHTML);
                                    </script>
                                 </div>
                              </div>
                              <table width="100%">
                                 <th style="background-color: #215393;color: white;"> Breakdown </th>
                                 <th style="background-color: #215393;color: white;"> Websites </th>
                                 <tr>
                                    <td>Websites Free of RC4/3DES and SSLv2/SSLv3 </td>
                                    <td><?=dotgov_common_getColor($agencydata['insec_compliant'], '#29643a', $insecprot_arr[0])?></td>
                                 </tr>
                                 <tr>
                                    <td>Websites Not Free of RC4/3DES and SSLv2/SSLv3 </td>
                                    <td><?=dotgov_common_getColor($agencydata['insec_noncompliant'], '#ac0600', $insecprot_arr[1])?></td>
                                 </tr>
                              </table>
                              <span class="text-center col-xs-12" style="font-size:10px;">(Note: website redirects are excluded)</span>
                           </div>
                           <div class="col-xs-12">
                              <?php
                                 $blockObject5 = block_load('trend_analysis', 'agency_rc4');
                                 $block5 = _block_get_renderable_array(_block_render_blocks(array($blockObject5)));
                                 $output5 = drupal_render($block5);
                                 print "$output5<br><span class='text-center col-xs-12 nopadding' style='color: " . dotgov_common_getChartColor($agency_insecprot_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly Insecure Protocol Trend</span>";
                                 ?>
                           </div>
                        </div>
                        <?php echo trim(dotgov_common_footer()); ?>
                     </div>
                  </div>
               </div>
               <div class="col-xs-12 col-lg-4">
                  <div class="white-back">
                     <div class="col-xs-10 nopadding">
                        <h2 class="pane-title">USWDS Code</h2>
                     </div>
                     <div class="col-xs-2 nopadding">
                        <div id="tooltip10" class="infor">
                           <a href="https://github.com/18F/site-scanning-documentation/blob/master/scans/uswds.md"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon"></a><span class="ext" aria-label="(link is external)"></span>
                        </div>
                     </div>
                     <br clear="all" />
                     <div class="pane-content clearfix">
                        <div class="view-wrapper">
                           <div class="view-content">
                              <div class="field-content col-lg-12 nopadding">
                                 <div class="grey-gradient clearfix">
                                    <div class="col-xs-12">
                                       <h5>USWDS Code Usage</h5>
                                    </div>
                                    <div class="col-xs-12" style="min-height:55px;">
                                       <p>The USWDS scan checks each domain for the use of U.S. Web Design System (USWDS) code and
                                          the code version.
                                       </p>
                                    </div>
                                    <div style="display:block; float:left;max-height:145px; width:100%;">
                                       <div class="col-xs-6 col-sm-6 col-lg-6" style="margin-top: 30px;">
                                          <ul class="uswds nopadding" style="font-size:12px; margin-left: 16px; line-height: 16px;">
                                             <li class="und">USWDS Code Detected</li>
                                             <li class="ud">USWDS Code Not Detected</li>
                                          </ul>
                                       </div>
                                       <div class="col-xs-6 col-sm-6 col-lg-6">
                                          <div id="piechartLast" style="max-width: 265px;float: right;"></div>
                                       </div>

                                       <script language="JavaScript">
                                          google.charts.load('current', {'packages':['corechart']});
                                          google.charts.setOnLoadCallback(drawuswdsChart);

                                          function drawuswdsChart() {

                                              var data = google.visualization.arrayToDataTable([
                                                  ['Type', 'Number'],
                                                  ['USWDS Code Detected',  <?php echo number_format($agencydata['uswds_compliant'], 1, '.', ''); ?>],
                                                  ['USWDS Code Not Detected', <?php echo number_format($agencydata['uswds_noncompliant'], 1, '.', ''); ?>],
                                              ]);
                                              var options = {
                                                  width: 200,
                                                  colors: ['#66746a', '#8ac99c'],
                                                  sliceVisibilityThreshold: 0,
                                                  dataLabels: {
                                                      enabled: true
                                                  },
                                                  legend: {position: 'none'},
                                                  showInLegend: true,
                                                  backgroundColor:"transparent",
                                                  chartArea:{left:'35%',bottom: '30%',height: 180,width:115.35},
                                              };

                                              var chart = new google.visualization.PieChart(document.getElementById('piechartLast'));

                                              chart.draw(data, options);
                                                // Process SVGTags in IE
                                                var svgTags = document.querySelectorAll('#piechartLast svg');
                                                var c = document.createElement('canvas');
                                                c.width = svgTags.clientWidth;
                                                c.height = svgTags.clientHeight;
                                                svgTags.parentNode.insertBefore(c, svgTags);
                                                var div = document.createElement('div');
                                                div.appendChild(svgTags);
                                                canvg(c, div.innerHTML);
                                          }
                                       </script>
                                    </div>
                                 </div>
                                 <table style="width:100%;">
                                    <th style="background-color: #215393;color: white;border: 1px;"> Breakdown </th>
                                    <th style="background-color: #215393;color: white;border: 1px;"> Websites </th>
                                    <tr>
                                       <td> Websites with USWDS code detected<font style="font-size: larger;font-color:blue;">
                                          </font>
                                       </td>
                                       <td><?=dotgov_common_getColor($agencydata['uswds_compliant'], '#66746a', $uswds_arr[0])?></td>
                                       </td>
                                    </tr>
                                    <tr>
                                       <td>Websites without USWDS code detected<font style="font-size: larger;font-color:blue;">
                                          </font>
                                       </td>
                                       <td><?=dotgov_common_getColor($agencydata['uswds_noncompliant'], '#8ac99c', $uswds_arr[1])?></td>
                                       </td>
                                    </tr>
                                 </table>
                                 <div class="col-xs-12 clearfix">
                                    <span class="text-center col-xs-12" style="font-size:10px;">(Note: website redirects are
                                    excluded)</span>
                                 </div>
                              </div>

                           </div>
                        </div>
                     </div>
                     <?php echo trim(dotgov_common_footer("/website/all/uswds", "https://designsystem.digital.gov/maturity-model/", "/sites/all/themes/dotgov/images/DD-btn_learn-more1.png")); ?>
                  </div>
               </div>
            </div>
         </div>
      </div>
      <div class="panel-separator clearfix"></div>
      <div class="out-wrapper">
         <div class="col-xs-12 nopadding clearfix">
            <div class="col-xs-12 col-lg-4">
               <div class="white-back no-height">
                  <h2 class="pane-title"> Popular Technologies </h2>
                  <div class="pane-content">
                     <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                        <div class="view-content">
                           <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                              <div class="views-field views-field-nothing">
                                 <div class="view-wrapper" style="min-height:454px;">
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
