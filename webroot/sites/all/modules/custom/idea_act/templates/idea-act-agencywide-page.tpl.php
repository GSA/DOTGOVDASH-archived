<style>
  @import "/sites/all/modules/custom/idea_act/css/style.css";
</style>

<script>
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
$agency_data = ideaact_get_agencywide_data(arg(3));

drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
foreach ($chartdata as $key => $val) {
  $chartseries1 .= "{\"name\":\"$labeldesc[$key]\",\"y\":" . (int) $val . ",\"showInLegend\":true},";
}
$chartseries = array_values($chartdata);
$agency_data = ideaact_get_agencywide_data(arg(3));
if(trim($search_engine_data_for_agencygraph) == "")
  $search_engine_data_for_agencygraph = "0,0";

$agencynode = node_load(arg(3));
$agency_data['agency_title'] = $agencynode->title;
 $pdf_file_name = '21st_Century_'.$agencynode->title.'.pdf';
?>

<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-9 dashboard-left">
                        <h1><?=$agencynode->title?> - <span>21st Century IDEA Act Dashboard</span></h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div class="col-md-2 col-md-offset-1 text-right dashboard-right">
                        <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon"
                                 data-placement="left" data-toggle="tooltip"
                                 title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a>

                      <button class="button download-button" onclick="generatePDF( '<?= $pdf_file_name?>', 400, 695)" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="reports bg-white shadow">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="col-sm-10 col-md-8">
                            <p>Total Public-Facing Websites Reported</p>
                            <p class="number"><?= $agency_data['no_of_websites']?></p>
                        </div>
                        <div class="col-sm-2 col-md-4">
                            <div class="text-md-right">
                              <?php
                              if ($agencynode->field_agency_logo['und'][0]['uri'] != '') {
                                ?>
                                <img src="<?php print file_create_url($agencynode->field_agency_logo['und'][0]['uri']);?>" alt="<?=$agencynode->title?>">
                                <?php
                              } else {
                                print "&nbsp;";
                              }
                              ?>
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
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
                                        <p>Average Color Contrast: <?= round($agency_data['ag_col_contrast'] / $agency_data['no_of_websites'], 1);?></p>
                                        <p>Average HTML Attribute: <?=  round($agency_data['ag_html_attrib'] / $agency_data['no_of_websites'], 1);?></p>
                                        <p>Average Missing Image Description: <?=  round($agency_data['ag_miss_image'] / $agency_data['no_of_websites'], 1);?></p>
                                        <p>(Note: website redirects are excluded)</p>
                                </div>
                                <div class="col-sm-6">
                                  <div class="chart-container" id="chart-1-ref">
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
                                <div class="col-sm-6 legend-container">
                                    <div id="chart-1-legend"></div></div>
                            </div>

                            <!-- script to render the pie chart -->
                          <script lang="javascript">
                              var ctx = document.getElementById('chart-gov1').getContext('2d');
                              var chart = new Chart(ctx, {
                                  type: 'doughnut',
                                  data: {
                                      datasets: [{
                                          data: [<?php echo number_format($agency_data['ag_col_contrast'], 1, '.', ''); ?>, <?php echo number_format($agency_data['ag_html_attrib'], 1, '.', ''); ?>, <?php echo number_format($agency_data['ag_miss_image'], 1, '.', ''); ?>],
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
                                          text: 'Total Number of Accessibility Issues for <?= $agency_data['agency_title']?> Websites',
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                              <div class="info-icon" id="tooltip-container">
                                <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                </a>
                              </div>
                              <div class="col-md-6">
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
                                              <td>Websites with USWDS code detected</td>
                                              <td><?php echo number_format($agency_data['uswds_compliant']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['uswds_compliant'], $agency_data['uswds_tottracked'])?></td>
                                            </tr>
                                            <tr>
                                              <td>Websites without USWDS code detected</td>
                                              <td><?php echo number_format($agency_data['uswds_noncompliant']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['uswds_noncompliant'], $agency_data['uswds_tottracked'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                     <div class="chart-container" id="chart-2-ref">
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
                                <div class="col-sm-6 legend-container">
                                    <div id="chart-2-legend"></div></div>
                            </div>

                            <!-- rendering chart container -->
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov2').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [ <?php echo number_format($agency_data['uswds_compliant']); ?>, <?php echo number_format($agency_data['uswds_noncompliant']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#ed4878',
                                                '#00699e',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: [ 'USWDS Code Detected','USWDS Code Not Detected']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: 'USWDS Code Usage Breakdown for <?= $agency_data['agency_title']?> Websites',
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                              <div class="info-icon" id="tooltip-container">
                                <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                </a>
                              </div>                                      <div class="col-md-6">
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
                                              <td><?php echo number_format($agency_data['https_support']); ?></td>
                                              <td><?php echo number_format($agency_data['https_nosupport']); ?></td>
                                            </tr>
                                            <tr>
                                              <td>HTTPS Status Percentage</td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['https_support'], $agency_data['no_of_websites'])?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['https_nosupport'], $agency_data['no_of_websites'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container" id="chart-3-ref">
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
                                <div class="col-sm-6 legend-container">
                                    <div id="chart-3-legend"></div></div>
                            </div>

                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov3').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [<?php echo number_format($agency_data['https_support']); ?>,
                                              <?php echo number_format($agency_data['https_nosupport']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#00a65f',
                                                '#97d1ff',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Compliant Websites','Non-Compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: '<?= $agency_data['agency_title']?> HTTPS Websites Compliance',
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
                                        <div class="card-title">On-site Search</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                              <div class="info-icon" id="tooltip-container">
                                <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
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
                                            foreach ($agency_data['searchenginedata'] as $skey => $sval) {
                                              $percent = round(($sval /  $agency_data['no_of_websites']) *100);
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
                                  <div class="chart-container" id="chart-4-ref">
                                      <?php $searchenginestatus = $agency_data['searchenginestatus'];
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
                                <div class="col-sm-6 legend-container">
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

                                        title: {
                                            display: true,
                                            text: '<?= $agency_data['agency_title']?> On-site Search Engine Breakdown',
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
                                            custom: customChartTooltip('chart-4-ref','chartjs-tooltip4'),
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                              <div class="info-icon" id="tooltip-container">
                                <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                </a>
                              </div>
                              <div class="col-md-6 mb-2">
                                    <div class="chart-container" id="chart-5-ref">
                                        <canvas id="chart-6" width="250" height="300" aria-label="Charts" role="img"></canvas>
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
                                              <td><?php echo number_format($agency_data['mob_perf_good_nos']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['mob_perf_good_nos'], $agency_data['total_non_na_websites'])?></td>
                                            </tr>
                                            <tr>
                                              <td>Needs Improvement</td>
                                              <td><?php echo number_format($agency_data['mob_perf_improve_nos']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['mob_perf_improve_nos'],$agency_data['total_non_na_websites'])?></td>
                                            </tr>
                                            <tr>
                                              <td>Poor</td>
                                              <td><?php echo number_format($agency_data['mob_perf_poor_nos']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['mob_perf_poor_nos'], $agency_data['total_non_na_websites'])?></td>
                                            </tr>

                                            </tbody>
                                        </table>
                                    </div>
                                    <script lang="javascript">
                                        var ctx = document.getElementById('chart-6').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [<?php echo number_format($agency_data['mob_perf_good_nos']); ?>,
                                                      <?php echo number_format($agency_data['mob_perf_improve_nos']); ?>,
                                                      <?php echo number_format($agency_data['mob_perf_poor_nos']); ?>,],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#c95d00',
                                                        '#218967',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Good', 'Needs Improvement', 'Poor']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,

                                                title: {
                                                    display: true,
                                                    text: '<?= $agency_data['agency_title']?> Mobile Performance Breakdown',
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
                                                    custom: customChartTooltip('chart-5-ref','chartjs-tooltip5'),
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
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container" id="chart-6-ref">
                                        <canvas id="chart-5" width="250" height="300" aria-label="Charts" role="img"></canvas>
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
                                              <td><?php echo number_format($agency_data['mob_usab_friendly_nos']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['mob_usab_friendly_nos'], $agency_data['mob_usab_friendly_nos']+$agency_data['mob_usab_notfriendly_nos'])?></td>
                                            </tr>
                                            <tr>
                                              <td>Not Mobile Friendly</td>
                                              <td><?php echo number_format($agency_data['mob_usab_notfriendly_nos']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['mob_usab_notfriendly_nos'],$agency_data['mob_usab_friendly_nos']+$agency_data['mob_usab_notfriendly_nos'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                    <script lang="javascript">
                                        var ctx = document.getElementById('chart-5').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [<?php echo number_format($agency_data['mob_usab_friendly_nos']); ?>,
                                                      <?php echo number_format($agency_data['mob_usab_notfriendly_nos']); ?>],
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

                                                title: {
                                                    display: true,
                                                    text: '<?= $agency_data['agency_title']?> Mobile Usability Breakdown',
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
                                                    custom: customChartTooltip('chart-6-ref','chartjs-tooltip6'),
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
                                                    },
                                                    legendCallback: function(chart) {
                                                        var text = [];
                                                        text.push('<ul class="' + chart.id + '-legend">');
                                                        for (var i = 0; i < chart.data.datasets.length; i++) {
                                                            text.push('<li><span style="background-color:' +
                                                                chart.data.datasets[i].backgroundColor +
                                                                '"></span>');
                                                            if (chart.data.datasets[i].label) {
                                                                text.push(chart.data.datasets[i].label);
                                                            }
                                                            text.push('</li>');
                                                        }
                                                        text.push('</ul>');
                                                        return text.join('');
                                                    }
                                                }
                                            }
                                        });
                                        var myLegendContainer = document.getElementById("chart-6-legend");
                                        myLegendContainer.innerHTML = chart.generateLegend();
                                    </script>
                                </div>
                            </div>

                            <div class="card-body relative-position row nmt-3">
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                  <a class="btn disabled" data-toggle="tooltip" title="<span><img width='150' height='100' class='tt-img' src='/sites/all/themes/dotgov/images/helpchart.png'><br><p class='tt-text'> Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php idea_act_lastScanDate();?>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
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
                                              <td><?php echo number_format($agency_data['dap_compliant']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['dap_compliant'], $agency_data['dap_tottracked'])?></td>
                                            </tr>
                                            <tr>
                                              <td>DAP Non-Compliant</td>
                                              <td><?php echo number_format($agency_data['dap_noncompliant']); ?></td>
                                              <td><?=idea_act_applyDataPercentage($agency_data['dap_noncompliant'], $agency_data['dap_tottracked'])?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container" id="chart-7-ref">
                                        <canvas id="chart-7" width="250" height="300" aria-label="Charts" role="img"></canvas>
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
                                <div class="col-sm-6 legend-container">
                                    <div id="chart-7-legend"></div></div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-7').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [
                                              <?php echo number_format($agency_data['dap_compliant']); ?>,
                                              <?php echo number_format($agency_data['dap_noncompliant']); ?>],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#de9738',
                                                '#00a1be',

                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Compliant Websites','Non-Compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: '<?= $agency_data['agency_title']?> DAP Websites Compliance',
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
                                            custom: customChartTooltip('chart-7-ref','chartjs-tooltip7'),
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


