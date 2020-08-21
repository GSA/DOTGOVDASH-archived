<style>
@import "/sites/all/modules/custom/idea_act/css/style.css";
</style>
<?php
drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
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
$chartdata = $govwidedata['actualdata'];
$websitenos = $chartdata['websitenos'];
$agencynos = $chartdata['agencynos'];
unset($chartdata['websitenos']);
unset($chartdata['agencynos']);
foreach ($chartdata as $key => $val) {
    $chartseries1 .= "{\"name\":\"$labeldesc[$key]\",\"y\":" . (int) $val . ",\"showInLegend\":true},";
}
$chartseries = array_values($chartdata);
$agencydata = idea_act_getAllAgencyComplianceData();
if(trim($search_engine_data_for_agencygraph) == "")
$search_engine_data_for_agencygraph = "0,0";

?>

<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-sm-12 dashboard-wrap">
                    <div class="col-sm-8 col-md-9 dashboard-left">
                        <h1>Government-Wide - <span>21st Century IDEA Act Dashboard</span></h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div class="col-sm-4 col-md-2 col-md-offset-1 text-right dashboard-right">
                        <a class="btn disabled" href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon"
                                 data-placement="left" data-toggle="tooltip"
                                 title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a>
                       
                        <button class="button download-button" onclick="generatePDF('21st-gov-wide.pdf', 400, 695)" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="reports bg-white shadow">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="col-sm-5 col-md-4">
                            <p>Total Federal Branch Agencies Reported</p>
                            <p class="number"><?=$agencynos?></p>
                        </div>
                        <div class="col-sm-5 col-md-4">
                            <p>Total Public-Facing Websites Reported</p>
                            <p class="number"><?=$websitenos?></p>
                        </div>
                        <div class="col-sm-2 col-md-4">
                            <div class="text-md-right">
                                <img src="/sites/all/modules/custom/idea_act/images/gov-logo.png" alt="Gov Logo" width="100" />
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">Accessibility Spot Checks</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a class="pe-none" href="#"><b>Read More</b></a>
                                            
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>                                   
                                 <div class="col-sm-6 mt-xs-1">
                                    <h4>Average Accessibility Issues by Type Per Website</h4>
                                    <p>Average Color Contrast: <?=round($agencydata['ag_col_contrast'] / $agency_website_num, 1);?></p>
                                    <p>Average HTML Attribute: <?=round($agencydata['ag_html_attrib'] / $agency_website_num, 1);?></p>
                                    <p>Average Missing Image Description: <?=round($agencydata['ag_miss_image'] / $agency_website_num, 1);?></p>
                                    <p>(Note: website redirects are excluded)</p>
                                </div>
                                <div class="col-sm-6">
                                    <div class="chart-container">
                                        <canvas id="chart-gov1" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-1-legend-mobile"></div>
                                </div>
                            </div>

                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-1-legend"></div>
                                </div>
                            </div>

                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov1').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?php echo number_format($agencydata['ag_col_contrast'], 1, '.', ''); ?>, <?php echo number_format($agencydata['ag_html_attrib'], 1, '.', ''); ?>, <?php echo number_format($agencydata['ag_miss_image'], 1, '.', ''); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#563eb6',
                                                '#d07413',
                                                '#808f4e',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Color Contrast Issues', 'HTML Attribute Issues','Missing Image Description Issues']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        
                                        title: {
                                            display: true,
                                            text: 'Total Number of Accessibility Issues for Websites',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    return label + ': ' + val ;
                                                }
                                            }
                                        },
                                        plugins: {
                                            labels: {
                                                render: 'value',
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 18,
                                                textMargin: 12,
                                                fontStyle: 'bold',
                                            }
                                        },
                                        legend: {
                                            position: 'bottom',
                                            display: false,
                                            labels: {
                                                fontColor: 'rgb(0, 0, 0)',
                                                usePointStyle: true,
                                                pointStyle: String
                                            }
                                        }
                                    }
                                });
                                var myLegendContainer = document.getElementById("chart-1-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
                                var myLegendContainerMobile = document.getElementById("chart-1-legend-mobile");
                                myLegendContainerMobile.innerHTML = chart.generateLegend();
                            </script>

                        </div>
                    </div>
                </div>
            </div>
 
            <div class="relative-position mb-2">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">USWDS Code Usage</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                             <a class="pe-none" href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a  class="btn disabled" href="//github.com/18F/site-scanning-documentation/blob/main/scans/live/uswds.md" target="_blank"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>     
                                
                                <div class="col-md-6 uswds-table">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Breakdown</th>
                                                <th>Websites</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td class="">Websites with USWDS code detected</td>
                                                <td><?php echo number_format($agencydata['uswds_compliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['uswds_compliant'], $agencydata['uswds_tottracked'])?></td>
                                            </tr>
                                            <tr>
                                                <td class="">Websites without USWDS code detected</td>
                                                <td><?php echo number_format($agencydata['uswds_noncompliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['uswds_noncompliant'], $agencydata['uswds_tottracked'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov2" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-2-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-2-legend"></div>
                                </div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov2').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?php echo number_format($agencydata['uswds_compliant']); ?>, <?php echo number_format($agencydata['uswds_noncompliant']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#ed4878',
                                                '#00699e',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['USWDS Code Detected', 'USWDS Code Not Detected']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                        title: {
                                            display: true,
                                            text: 'USWDS Code Usage Breakdown for Websites',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    return label + ': ' + Math.round( val * 100 / total) + '%';
                                                }
                                            }
                                        },
                                        plugins: {

                                            labels: {
                                                render: 'data',
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 18,
                                                textMargin: 12,
                                                fontStyle: 'bold',
                                            }
                                        },
                                        legend: {
                                            position: 'bottom',
                                            display: false,
                                            labels: {
                                                fontColor: 'rgb(0, 0, 0)',
                                                usePointStyle: true,
                                                pointStyle: String
                                            }
                                        }
                                    }
                                });
                                var myLegendContainer = document.getElementById("chart-2-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();

                                var myLegendContainerMobile = document.getElementById("chart-2-legend-mobile");
                                myLegendContainerMobile.innerHTML = chart.generateLegend();
                            </script>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">Security Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                             <a class="pe-none" href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> HTTPS Data is collected through a custom scanner component of digital dashboard that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div> 
                                <div class="col-md-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Compliant</th>
                                                <th>Non-Compliant</th>

                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>HTTPS Status Websites</td>
                                                <td><?php echo number_format($agencydata['https_support']); ?></td>
                                                <td><?php echo number_format($agencydata['https_nosupport']); ?></td>

                                            </tr>
                                            <tr>
                                                <td>HTTPS Status Percentage</td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['https_support'], $agency_website_num)?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['https_nosupport'], $agency_website_num)?></td>
                                            </tr>
                                            
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov3" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-3-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-3-legend"></div></div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov3').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?php echo number_format($agencydata['https_support']); ?>,
                                                    <?php echo number_format($agencydata['https_nosupport']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#00a65f',
                                                '#97d1ff'
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: [ 'Compliant Websites','Non-Compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        //rotation: (-1.5*Math.PI) - (10/180 * Math.PI),
                                        title: {
                                            display: true,
                                            text: 'HTTPS Websites Compliance',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    return label + ': ' + Math.round( val * 100 / total) + '%';
                                                }
                                            }
                                        },
                                        plugins: {

                                            labels: {
                                                render: 'data',
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 18,
                                                textMargin: 12,
                                                fontStyle: 'bold',
                                            }
                                        },
                                        legend: {
                                            position: 'bottom',
                                            display: false,
                                            labels: {
                                                fontColor: 'rgb(0, 0, 0)',
                                                usePointStyle: true,
                                                pointStyle: String
                                            }
                                        }
                                    }
                                });
                                var myLegendContainer = document.getElementById("chart-3-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
                                var myLegendContainerMobile = document.getElementById("chart-3-legend-mobile");
                                myLegendContainerMobile.innerHTML = chart.generateLegend();
                            </script>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">On-Site Search</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                             <a class="pe-none" href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><p class='tt-text'> On-Site Search Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>         
                                
                                <div class="col-md-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>On-Site Search Engine</th>
                                                <th>Total</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <?php
                                            foreach ($agencydata['searchenginedata'] as $skey => $sval) {
                                                $percent = round(($sval / $websitenos) *100);
                                                $percent =  ($percent < 1) ?  '< 1' : $percent;
                                                print "<tr style='text-transform: capitalize;'><td>" . ucfirst($skey) . "</td><td> $sval</td>
                                                <td>$percent% </td></tr>";
                                            }
                                          ?>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                    <?php $searchenginestatus = $agencydata['searchenginestatus'];
                                       ?>
                                        <canvas id="chart-gov-search" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-4-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-4-legend"></div></div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov-search').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?=($searchenginestatus['search_notavailable'] == "") ? 0 : $searchenginestatus['search_notavailable']?>, 
                                            <?=($searchenginestatus['search_available'] == "") ? 0 : $searchenginestatus['search_available']?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#a52700',
                                                '#00b8ad',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Not Available', 'Available']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                        title: {
                                            display: true,
                                            text: 'On-site Search Engine Breakdown',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    return label + ': ' + Math.round( val * 100 / total) + '%';
                                                }
                                            }
                                        },
                                        plugins: {
                                            labels: {
                                                render: 'data',
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 18,
                                                textMargin: 12,
                                                fontStyle: 'bold',
                                            }
                                        },
                                        legend: {
                                            position: 'bottom',
                                            display: false,
                                            labels: {
                                                fontColor: 'rgb(0, 0, 0)',
                                                usePointStyle: true,
                                                pointStyle: String
                                            }
                                        }
                                    }
                                });
                                var myLegendContainer = document.getElementById("chart-4-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
                                var myLegendContainerMobile = document.getElementById("chart-4-legend-mobile");
                                myLegendContainerMobile.innerHTML = chart.generateLegend();
                            </script>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2 mobile-requirements">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">Mobile Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                             <a class="pe-none" href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Mobile Data is collected from Google API through a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>    
                                
                                <div class="col-md-6 mb-2">
                                    <div class="chart-container">
                                        <canvas id="chart-gov4" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-5-legend"></div>
                                    </div>
                                    <div class="table-responsive">
                                    
                                        <table>
                                            <thead>
                                        
                                            <tr>
                                                <th>Breakdown</th>
                                                <th>Websites</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>Good</td>
                                                <td><?php echo number_format($agencydata['good_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['good_nos'], $agencydata['total_non_na_websites'])?></td>
                                            </tr>
                                            <tr>
                                                <td>Needs Improvement</td>
                                                <td><?php echo number_format($agencydata['improve_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['improve_nos'],$agencydata['total_non_na_websites'])?></td>
                                            </tr>
                                            <tr>
                                                <td>Poor</td>
                                                <td><?php echo number_format($agencydata['poor_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['poor_nos'], $agencydata['total_non_na_websites'])?></td>
                                            </tr>

                                            </tbody>
                                        </table>
                                    </div>
                                    <script lang="javascript">
                                        var ctx = document.getElementById('chart-gov4').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [<?php echo number_format($agencydata['good_nos']); ?>,
                                                            <?php echo number_format($agencydata['improve_nos']); ?>,
                                                            <?php echo number_format($agencydata['poor_nos']); ?>,],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#c95d00',
                                                        '#218967'
                                                        
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Good', 'Needs Improvement', 'Poor']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,
                                                // rotation: (-5.5*Math.PI) - (25/180 * Math.PI),

                                                title: {
                                                    display: true,
                                                    text: 'Mobile Performance Breakdown',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'
                                                },
                                                tooltips: {
                                                    yPadding: 10,
                                                    xPadding: 10,
                                                    caretPadding: 5,
                                                    caretSize: 5,
                                                    displayColors: false,
                                                    callbacks: {
                                                        label: function(tooltipItem, data) {
                                                            var label = data.labels[tooltipItem.index];
                                                            var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                            var val = data.datasets[0].data[tooltipItem.index];
                                                            return label + ': ' + Math.round( val * 100 / total) + '%';
                                                        }
                                                    }
                                                },
                                                plugins: {

                                                    labels: {
                                                        render: 'data',
                                                        fontColor: '#102e54',
                                                        position: 'outside',
                                                        fontSize: 18,
                                                        textMargin: 12,
                                                        fontStyle: 'bold',
                                                    }
                                                },
                                                legend: {
                                                    position: 'bottom',
                                                    display: false,
                                                    labels: {
                                                        fontColor: 'rgb(0, 0, 0)',
                                                        usePointStyle: true,
                                                        pointStyle: String
                                                    }
                                                }
                                            }
                                        });
                                        var myLegendContainer = document.getElementById("chart-5-legend");
                                        myLegendContainer.innerHTML = chart.generateLegend();
                                    </script>

                                </div>
                                <div class="col-md-6 mt-xs-1 px-xs-0">
                                    <div class="chart-container">
                                        <canvas id="chart-gov5" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-6-legend"></div>
                                    </div>
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Breakdown</th>
                                                <th>Websites</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>Mobile Friendly</td>
                                                <td><?php echo number_format($agencydata['friendly_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['friendly_nos'], $agencydata['friendly_nos']+$agencydata['nonfriendly_nos'])?></td>
                                            </tr>
                                            <tr>
                                                <td>Not Mobile Friendly</td>
                                                <td><?php echo number_format($agencydata['nonfriendly_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['nonfriendly_nos'],$agencydata['friendly_nos']+$agencydata['nonfriendly_nos'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                    <script lang="javascript">
                                        var ctx = document.getElementById('chart-gov5').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [<?php echo number_format($agencydata['friendly_nos']); ?>,
                                                            <?php echo number_format($agencydata['nonfriendly_nos']); ?>],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#8ea116',
                                                        '#007790',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Mobile Friendly', 'Not Mobile Friendly']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,
                                                // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                                title: {
                                                    display: true,
                                                    text: 'Mobile Usability Breakdown',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'
                                                },
                                                tooltips: {
                                                    yPadding: 10,
                                                    xPadding: 10,
                                                    caretPadding: 5,
                                                    caretSize: 5,
                                                    displayColors: false,
                                                    callbacks: {
                                                        label: function(tooltipItem, data) {
                                                            var label = data.labels[tooltipItem.index];
                                                            var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                            var val = data.datasets[0].data[tooltipItem.index];
                                                            return label + ': ' + Math.round( val * 100 / total) + '%';
                                                        }
                                                    }
                                                },
                                                plugins: {
                                                    labels: {
                                                        render: 'data',
                                                        fontColor: '#102e54',
                                                        position: 'outside',
                                                        fontSize: 18,
                                                        textMargin: 12,
                                                        fontStyle: 'bold',
                                                    }
                                                },
                                                legend: {
                                                    position: 'bottom',
                                                    display: false,
                                                    labels: {
                                                        fontColor: 'rgb(0, 0, 0)',
                                                        usePointStyle: true,
                                                        pointStyle: String
                                                    }
                                                }
                                            }
                                        });
                                        var myLegendContainer = document.getElementById("chart-6-legend");
                                        myLegendContainer.innerHTML = chart.generateLegend();
                                    </script>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3 mt-sm-0">
                                <div class="col-md-6 mb-2">
                                    <div class="explore">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="card card-default shadow">
                            <div class="card-header row row-no-gutters">
                                <div class="col-sm-12">
                                    <div class="col-sm-6">
                                        <div class="card-title">Digital Analytics</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>21st Century IDEA Act</b></i></p></div>
                                            <span class="fw-300 card-description">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                             <a class="pe-none" href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                            <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> DAP Overall Average Score : <?=$agency_dap_score?>%"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>  
                                
                                <div class="col-md-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Websites</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>DAP Compliant</td>
                                                <td><?php echo number_format($agencydata['dap_compliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['dap_compliant'], $agencydata['dap_tottracked'])?></td>
                                            </tr>
                                            <tr>
                                                <td>DAP Non-Compliant</td>
                                                <td><?php echo number_format($agencydata['dap_noncompliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['dap_noncompliant'], $agencydata['dap_tottracked'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov6" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-7-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-7-legend"></div></div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov6').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?php echo number_format($agencydata['dap_compliant']); ?>,
                                                    <?php echo number_format($agencydata['dap_noncompliant']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#de9738',
                                                '#00a1be'
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: [ 'Compliant Websites', 'Non-Compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce((a, b) => a + b, 0);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    return label + ': ' + Math.round( val * 100 / total) + '%';
                                                }
                                            }
                                        },
                                        title: {
                                            display: true,
                                            text: 'DAP Websites Compliance',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        plugins: {

                                            labels: {
                                                render: 'data',
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 18,
                                                textMargin: 12,
                                                fontStyle: 'bold',
                                            }
                                        },
                                        legend: {
                                            position: 'bottom',
                                            display: false,
                                            labels: {
                                                fontColor: 'rgb(0, 0, 0)',
                                                usePointStyle: true,
                                                pointStyle: String
                                            }
                                        }
                                    }
                                });
                                var myLegendContainer = document.getElementById("chart-7-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
                                var myLegendContainerMobile = document.getElementById("chart-7-legend-mobile");
                                myLegendContainerMobile.innerHTML = chart.generateLegend();
                            </script>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

