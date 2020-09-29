<style>
@import "/sites/all/modules/custom/idea_act/css/style.css";
</style>
<script>
    function sumIt(total, num) {
        return total + num;
    }
    function customChartTooltip(chartId, toolTipId) {
        var customTooltip= function(tooltip) {
            // Tooltip Element
            var tooltipEl = document.getElementById(toolTipId);

            if (!tooltipEl) {
                tooltipEl = document.createElement('div');
                tooltipEl.id = toolTipId;
                tooltipEl.innerHTML = "<table></table>"
                document.getElementById(chartId).appendChild(tooltipEl);
            }

            // Hide if no tooltip
            if (tooltip.opacity === 0) {
                tooltipEl.style.opacity = 0;
                return;
            }

            // Set caret Position
            tooltipEl.classList.remove('above', 'below', 'no-transform');
            if (tooltip.yAlign) {
                tooltipEl.classList.add(tooltip.yAlign);
            } else {
                tooltipEl.classList.add('no-transform');
            }

            function getBody(bodyItem) {
                return bodyItem.lines;
            }

            // Set Text
            if (tooltip.body) {
                var titleLines = tooltip.title || [];
                var bodyLines = tooltip.body.map(getBody);

                var innerHtml = '<thead>';

                titleLines.forEach(function(title) {
                    innerHtml += '<tr><th>' + title + '</th></tr>';
                });
                innerHtml += '</thead><tbody>';

                bodyLines.forEach(function(body, i) {
                    var colors = tooltip.labelColors[i];
                    var style = 'background:' + colors.backgroundColor;
                    style += '; border-color:' + colors.borderColor;
                    style += '; border-width: 2px';
                    var span = '<span class="chartjs-tooltip-key" style="' + style + '"></span>';
                    innerHtml += '<tr><td>' + span + body + '</td></tr>';
                });
                innerHtml += '</tbody>';

                var tableRoot = tooltipEl.querySelector('table');
                tableRoot.innerHTML = innerHtml;
            }

            var position = this._chart.canvas.getBoundingClientRect();
            tooltipEl.style.opacity = 1;
            tooltipEl.style.left = tooltip.caretX + 'px';
            tooltipEl.style.top = tooltip.caretY + 'px';
            tooltipEl.style.fontSize = tooltip.fontSize;
            tooltipEl.style.fontStyle = tooltip._fontStyle;
            tooltipEl.style.padding = tooltip.yPadding + 'px ' + tooltip.xPadding + 'px';
        };
        return customTooltip;

    }

</script>
<?php
drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
drupal_set_title("21st Century IDEA Act Government-Wide Dashboard");
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
                    <div id="element-to-hide" data-html2canvas-ignore="true" class="col-sm-4 col-md-2 col-md-offset-1 text-right dashboard-right">
                        <!-- <a class="btn disabled" href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon"
                                 data-placement="left" data-toggle="tooltip"
                                 title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a> -->

                        <button class="button download-button" onclick="generatePDF('21st-gov-wide.pdf', 500, 730)" type="submit">Download</button>
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
                                            <div><p class="card-description"><i><b>Accessible - Accessible to Individuals with Disabilities</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be accessible to individuals with disabilities. The three accessibility metrics presented in this report provide an initial spot check of some common web accessibility issues that can be discovered through automated scanning. This is an indicator only, and is not intended to be a comprehensive assessment of website accessibility. </span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                            
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                 <div class="col-sm-6 mt-xs-1 center-mb-2">
                                    <h4 class="chart-data-title">Average Accessibility Issues by Type Per Website</h4>
                                    <p>Average Color Contrast: <?=round($agencydata['ag_col_contrast'] / $agency_website_num, 1);?></p>
                                    <p>Average HTML Attribute: <?=round($agencydata['ag_html_attrib'] / $agency_website_num, 1);?></p>
                                    <p>Average Missing Image Description: <?=round($agencydata['ag_miss_image'] / $agency_website_num, 1);?></p>
                                    <p>(Note: website redirects are excluded)</p>
                                </div>
                                <div class="col-sm-6 nopadding">
                                <h4 class="chart-data-title text-center">Total Number of Accessibility Issues for Websites</h4>
                                    <div class="chart-container" id="chart-1-ref">
                                        <canvas id="chart-gov1" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-1-legend-mobile"></div>
                                </div>
                            </div>

                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                      <a href="/ideaact/report/accessibility/websites" class="btn btn-digital explore">Explore</a>
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
                                            display: false,
                                            text: 'Total Number of Accessibility Issues for Websites',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            enabled: false,
                                            custom: customChartTooltip('chart-1-ref','chartjs-tooltip1'),
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce(sumIt);
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
                                                fontSize: 16,
                                                textMargin: 8,
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
                                        <div class="card-title">Websites with USWDS Code Usage</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>Consistent - Consistent in Appearance</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a consistent appearance. It also requires agencies to use this <a href="https://designsystem.digital.gov/maturity-model/" target="_blank"> maturity model</a> to gauge compliance with these <a href="https://designsystem.digital.gov/website-standards/" target="_blank">website standards</a> via use of the <a href="https://designsystem.digital.gov/" target="_blank">U.S. Web Design System</a>. This report provides a high-level view of websites and agencies using the U.S. Web Design System (USWDS) code. </span>
                                             <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
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
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>Breakdown</th>
                                                <th>Websites</th>
                                                <th>Percentage</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td class="">USWDS code detected</td>
                                                <td><?php echo number_format($agencydata['uswds_compliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['uswds_compliant'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                                <td class="">USWDS code not detected</td>
                                                <td><?php echo number_format($agencydata['uswds_noncompliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['uswds_noncompliant'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Data Not Available</td>
                                              <td><?php echo number_format( $agencydata['uswds_null']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['uswds_null'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Total</td>
                                              <td><?php echo number_format($agency_website_num); ?></td>
                                              <td>100%
                                                <a data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a>
                                              </td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                <h4 class="text-center chart-data-title">USWDS Code Usage for Websites</h4>
                                    <div class="chart-container" id="chart-2-ref">
                                        <canvas id="chart-gov2" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-2-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/ideaact/govwide/report" class="btn btn-digital explore">Explore</a>
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
                                            data: [<?php echo number_format($agencydata['uswds_compliant']); ?>, <?php echo number_format($agencydata['uswds_noncompliant']); ?>,<?php echo number_format( $agencydata['uswds_null']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#ed4878',
                                                '#00699e',
                                                '<?php print $agencydata['uswds_null_color']; ?>'
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['USWDS Code Detected', 'USWDS Code Not Detected','<?php print $agencydata['uswds_null_label']; ?>']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                        title: {
                                            display: false,
                                            text: 'USWDS Code Usage for Websites',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            enabled: false,
                                            custom: customChartTooltip('chart-2-ref','chartjs-tooltip2'),
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            displayColors: false,
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce(sumIt);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    var $actualPercentage = (val/<?php print $agency_website_num; ?>)*100;
                                                    return label + ': ' + Math.round($actualPercentage) + '%';
                                                }
                                            }
                                        },
                                        plugins: {

                                            labels: {
                                               render: function (args) {
                                                    var $actualPercentage = ((args.value)/ <?php print $agency_website_num; ?>)*100;
                                                    return Math.round($actualPercentage) + '%';   
                                                    },
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 16,
                                                textMargin: 8,
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
                                        <div class="card-title">Websites with Security Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>Secure - Provided through an Industry Standard Secure Connection</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a secure connection. The report shows how many agency websites are <a href="https://https.cio.gov/" target="_blank"> HTTPS</a> compliant.</span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
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
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                              <th>Criteria</th>
                                              <th>Total</th>
                                              <th>Percentage</th>
                                            </tr>
                                            </thead>
                                          <tbody>
                                            <tr>
                                              <td>HTTPS Compliant</td>
                                              <td><?php echo number_format($agencydata['https_support']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['https_support'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>HTTPS Non Compliant</td>
                                              <td><?php echo number_format($agencydata['https_nosupport']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['https_nosupport'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Data Not Available</td>
                                              <td><?php echo number_format($agencydata['https_null']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['https_null'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Total</td>
                                              <td><?php echo number_format($agency_website_num); ?></td>
                                              <td>100%
                                                <a data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a>
                                              </td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                <h4 class="text-center chart-data-title">HTTPS Websites Compliance</h4>
                                    <div class="chart-container" id="chart-3-ref">
                                        <canvas id="chart-gov3" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-3-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                      <a href="/ideaact/govwide/report" class="btn btn-digital explore">Explore</a>
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
                                                    <?php echo number_format($agencydata['https_nosupport']); ?>,
                                                    <?=idea_act_avoid_slice($agencydata['https_null'],$agency_website_num);?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#00a65f',
                                                '#97d1ff',
                                                '<?=idea_act_avoid_null_color($agencydata['https_null'],$agency_website_num);?>'
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: [ 'Compliant Websites',
                                                    'Non-Compliant Websites',
                                                   '<?=idea_act_avoid_null_legend($agencydata['https_null'],$agency_website_num);?>']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        //rotation: (-1.5*Math.PI) - (10/180 * Math.PI),
                                        title: {
                                            display: false,
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
                                            enabled: false,
                                            custom: customChartTooltip('chart-3-ref','chartjs-tooltip3'),
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                    var label = data.labels[tooltipItem.index];
                                                    var total = data.datasets[0].data.reduce(sumIt);
                                                    var val = data.datasets[0].data[tooltipItem.index];
                                                    var $actualPercentage = (val/<?php print $agency_website_num; ?>)*100;
                                                    return label + ': ' + Math.round($actualPercentage) + '%';                                               }
                                            }
                                        },
                                        plugins: {

                                            labels: {
                                               render: function (args) {
                                                    var $actualPercentage = ((args.value)/ <?php print $agency_website_num; ?>)*100;
                                                    return Math.round($actualPercentage) + '%';
                                                },
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 16,
                                                textMargin: 8,
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
                                        <div class="card-title">Websites with On-Site Search</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>Searchable - Contains a Search Function</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a search function that allows users to easily search content. This report provides a high-level view on how many websites have a search box (detectable through automated scanning), and provides a breakdown of specific on-site search products, where available. </span>
                                             <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
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
                                        <table class="idea-act-table">
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
                                <h4 class="text-center chart-data-title">On-Site Search Presence</h4>

                                    <div class="chart-container" id="chart-4-ref">
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
                                      <a href="/ideaact/govwide/report" class="btn btn-digital explore">Explore</a>
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
                                               '#224a58',
                                                '#00b8ad',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Not Detected', 'Detected']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,
                                        // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                        title: {
                                            display: false,
                                            text: 'On-site Search Engine',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        tooltips: {
                                            yPadding: 10,
                                            xPadding: 10,
                                            caretPadding: 5,
                                            caretSize: 5,
                                            enabled: false,
                                            custom: customChartTooltip('chart-4-ref','chartjs-tooltip4'),
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                        var label = data.labels[tooltipItem.index];
                                                        var total = data.datasets[0].data.reduce(sumIt);
                                                        var val = data.datasets[0].data[tooltipItem.index];
                                                        var $actualPercentage = (val * 100 / total).toFixed(2);
                                                        return label + ': ' + Math.round($actualPercentage) + '%';

                                                    }
                                            }
                                        },
                                        plugins: {
                                            labels: {
                                                render: function (args) {
                                                    return  args.percentage + '%';
                                                },
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 16,
                                                textMargin: 8,
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
                                        <div class="card-title">Websites with Mobile Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>Mobile-friendly - Fully Functional and Usable on Common Mobile Devices</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be fully functional and usable on common mobile devices. This report uses automated scanning to deliver Mobile Performance and Mobile Usability assessment results for each .gov website.</span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
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
                                <h4 class="text-center chart-data-title">Mobile Performance</h4>

                                    <div class="chart-container" id="chart-5-ref">
                                        <canvas id="chart-gov4" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-5-legend"></div>
                                    </div>
                                    <div class="table-responsive">

                                        <table class="idea-act-table">
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
                                                <td><?=idea_act_applyDataPercentage($agencydata['good_nos'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                                <td>Needs Improvement</td>
                                                <td><?php echo number_format($agencydata['improve_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['improve_nos'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                                <td>Poor</td>
                                                <td><?php echo number_format($agencydata['poor_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['poor_nos'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Data Not Available</td>
                                              <td><?php echo number_format($agencydata['perf_null']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['perf_null'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Total</td>
                                              <td><?php echo number_format($agency_website_num); ?></td>
                                              <td>100%
                                                <a data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a>
                                              </td>
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
                                                            <?php echo number_format($agencydata['poor_nos']); ?>,
                                                      <?php echo number_format($agencydata['perf_null']); ?>],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#c95d00',
                                                        '#218967',
                                                        '<?php print $agencydata['perf_null_color']; ?>',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Good', 'Needs Improvement', 'Poor','<?php print $agencydata['perf_null_label']; ?>']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,
                                                // rotation: (-5.5*Math.PI) - (25/180 * Math.PI),

                                                title: {
                                                    display: false,
                                                    text: 'Mobile Performance',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'
                                                },
                                                tooltips: {
                                                    yPadding: 10,
                                                    xPadding: 10,
                                                    caretPadding: 5,
                                                    caretSize: 5,
                                                    enabled: false,
                                                    custom: customChartTooltip('chart-5-ref','chartjs-tooltip5'),
                                                    callbacks: {
                                                        label: function(tooltipItem, data) {
                                                        var label = data.labels[tooltipItem.index];
                                                        var total = data.datasets[0].data.reduce(sumIt);
                                                        var val = data.datasets[0].data[tooltipItem.index];
                                                        var $actualPercentage = (val/<?php print $agency_website_num; ?>)*100;
                                                        return label + ': ' + Math.round($actualPercentage) + '%';
                                                    }
                                                    }
                                                },
                                                plugins: {

                                                    labels: {
                                                        render: function (args) {
                                                            var $actualPercentage = ((args.value)/ <?php print $agency_website_num; ?>)*100;
                                                            return Math.round($actualPercentage) + '%';
                                                        },
                                                        fontColor: '#102e54',
                                                        position: 'outside',
                                                        fontSize: 16,
                                                        textMargin: 8,
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
                                <h4 class="text-center chart-data-title">Mobile Usability</h4>

                                    <div class="chart-container" id="chart-6-ref">
                                        <canvas id="chart-gov5" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-6-legend"></div>
                                    </div>
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
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
                                                <td><?=idea_act_applyDataPercentage($agencydata['friendly_nos'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                                <td>Not Mobile Friendly</td>
                                                <td><?php echo number_format($agencydata['nonfriendly_nos']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['nonfriendly_nos'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Data Not Available</td>
                                              <td><?php echo number_format($agencydata['usab_null']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agencydata['usab_null'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Total</td>
                                              <td><?php echo number_format($agency_website_num); ?></td>
                                              <td>100%
                                                <a data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a>
                                              </td>
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
                                                            <?php echo number_format($agencydata['nonfriendly_nos']); ?>,
                                                            <?php echo number_format($agencydata['usab_null']); ?>],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#8ea116',
                                                        '#007790',
                                                        '<?php print $agencydata['usab_null_color']; ?>',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Mobile Friendly', 'Not Mobile Friendly','<?php print $agencydata['usab_null_label']; ?>']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,
                                                // rotation: (-1.5*Math.PI) - (10/180 * Math.PI),

                                                title: {
                                                    display: false,
                                                    text: 'Mobile Usability',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'
                                                },
                                                tooltips: {
                                                    yPadding: 10,
                                                    xPadding: 10,
                                                    caretPadding: 5,
                                                    caretSize: 5,
                                                    enabled: false,
                                                    custom: customChartTooltip('chart-6-ref','chartjs-tooltip6'),                                                    callbacks: {
                                                        label: function(tooltipItem, data) {
                                                        var label = data.labels[tooltipItem.index];
                                                        var total = data.datasets[0].data.reduce(sumIt);
                                                        var val = data.datasets[0].data[tooltipItem.index];
                                                        var $actualPercentage = (val/<?php print $agency_website_num; ?>)*100;
                                                        return label + ': ' + Math.round($actualPercentage) + '%';
                                                    }
                                                    }
                                                },
                                                plugins: {
                                                    labels: {
                                                        render: function (args) {
                                                            var $actualPercentage = ((args.value)/ <?php print $agency_website_num; ?>)*100;
                                                            return Math.round($actualPercentage) + '%';
                                                        },
                                                        fontColor: '#102e54',
                                                        position: 'outside',
                                                        fontSize: 16,
                                                        textMargin: 8,
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
                                      <a href="/ideaact/govwide/report" class="btn btn-digital explore">Explore</a>
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
                                        <div class="card-title">Websites with Digital Analytics</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><p class="card-description"><i><b>User-Centric - Designed around user needs with data-driven analysis influencing management and development decisions</b></i></p></div>
                                            <span class="fw-300 card-description f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be designed around user needs with data-driven analysis. The report shows how many websites have implemented the DAP (Digital Analytics Program) code. </span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
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
                                        <table class="idea-act-table">
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
                                                <td><?=idea_act_applyDataPercentage($agencydata['dap_compliant'],$agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                                <td>DAP Non-Compliant</td>
                                                <td><?php echo number_format($agencydata['dap_noncompliant']); ?></td>
                                                <td><?=idea_act_applyDataPercentage($agencydata['dap_noncompliant'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Data Not Available</td>
                                              <td><?php echo number_format( $agencydata['dap_null']); ?></td>
                                              <td><?=idea_act_applyDataPercentage( $agencydata['dap_null'], $agency_website_num)?></td>
                                            </tr>
                                            <tr>
                                              <td>Total</td>
                                              <td><?php echo number_format($agency_website_num); ?></td>
                                              <td>100%
                                                <a data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a>
                                              </td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                <h4 class="text-center chart-data-title">DAP Websites Compliance</h4>

                                    <div class="chart-container" id="chart-7-ref">
                                        <canvas id="chart-gov6" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div id="chart-7-legend-mobile"></div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                      <a href="/ideaact/govwide/report" class="btn btn-digital explore">Explore</a>
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
                                                    <?php echo number_format($agencydata['dap_noncompliant']); ?>,
                                              <?php echo $agencydata['dap_null']; ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#de9738',
                                                '#00a1be',
                                                '<?php print $agencydata['dap_null_color']; ?>'
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: [ 'Compliant Websites', 'Non-Compliant Websites','<?php print $agencydata['dap_null_label'];?>']
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
                                            enabled: false,
                                            custom: customChartTooltip('chart-7-ref','chartjs-tooltip7'),
                                            callbacks: {
                                                label: function(tooltipItem, data) {
                                                        var label = data.labels[tooltipItem.index];
                                                        var total = data.datasets[0].data.reduce(sumIt);
                                                        var val = data.datasets[0].data[tooltipItem.index];
                                                        var $actualPercentage = (val/<?php print $agency_website_num; ?>)*100;
                                                        return label + ': ' + Math.round($actualPercentage) + '%';                                              }
                                            }
                                        },
                                        title: {
                                            display: false,
                                            text: 'DAP Websites Compliance',
                                            fontSize: 18,
                                            fontColor: '#203b5f'
                                        },
                                        plugins: {

                                            labels: {
                                               render: function (args) {
                                                    var $actualPercentage = ((args.value)/ <?php print $agency_website_num; ?>)*100;
                                                    return Math.round($actualPercentage) + '%';                                              
                                                    },
                                                fontColor: '#102e54',
                                                position: 'outside',
                                                fontSize: 16,
                                                textMargin: 8,
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

