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
$websitedata = ideaact_get_website_data(arg(3));
drupal_set_title($websitedata['agencyname']);
?>
<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-8 dashboard-left">
                    <h1><?php print $websitedata['websitename']; ?> <span>(<?php print $websitedata['agencyname']; ?>)</span></h1>
                        <p class="description">This is an act that aims to improve the digital experience for government customers and reinforces existing requirements for federal public websites.</p>
                    </div>
                    <div class="col-md-2 col-md-offset-2 text-right dashboard-right">
                        <!-- <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon" data-placement="left" data-toggle="tooltip" title="" data-original-title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do">
                        </a> -->
                        <button id="element-to-hide" data-html2canvas-ignore="true" class="button download-button" onclick="generatePDF('idea_act_website_<?php print strtr($websitedata['websitename'], '.', '_'); ?>.pdf', 400, 1000)" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="bg-white shadow">
                <div class="row row-no-gutters">
                    <div class="col-sm-12">
                        <div class="col-sm-9 col-md-6">
                            <div class="row">
                                <div class="col-md-12 d-flex">
                                    <?php print $websitedata['agency_header_info']; ?>
                                </div>
                            </div>
                        </div>
                        <div class="col-sm-3 col-md-2 col-md-offset-4">
                            <?php print $websitedata['agencyacr']; ?>
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
                                            <div><i><b>Accessible - Accessible to Individuals with Disabilities</b></i></div>
                                            <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be accessible to individuals with disabilities. The three accessibility metrics presented in this report provide an initial spot check of some common web accessibility issues that can be discovered through automated scanning. This is an indicator only, and is not intended to be a comprehensive assessment of website accessibility. </span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-Accessibility-Spot-Checks?" data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6 nopadding">

                                    <?php print  $websitedata['web-access-chart'];?>
                                    <script language="javascript">
                                        var ctx = document.getElementById('chart-webhome').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [<?php echo number_format( $websitedata['colorcont'], 1, '.', ''); ?>, <?php echo number_format($websitedata['htmlattri'], 1, '.', ''); ?>, <?php echo number_format($websitedata['missingim'], 1, '.', ''); ?>],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#d07413',
                                                        '#218967',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Color Contrast Issues', 'HTML Attribute Issues', 'Missing Image Description']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,

                                                title: {
                                                    display: false,
                                                    text: 'Accessibility spot checks',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'

                                                },
                                                tooltips: {
                                                    enabled: false,
                                                    custom: customChartTooltip('chart-11-ref','chartjs-tooltip1'),
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
                                    </script>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-wi-desc"> <?=$websitedata['Accestext']?></p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/report/accessibility/website/<?=$websitedata['access_id'] ?>" class= "btn btn-digital <?= $websitedata['explore_btn']?> ">Explore</a>
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
                                        <div class="card-title">Mobile Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><i><b>Mobile-friendly - Fully Functional and Usable on Common Mobile Devices</b></i></div>
                                            <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be fully functional and usable on common mobile devices. This report uses automated scanning to deliver Mobile Performance and Mobile Usability assessment results for each .gov website.</span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-Mobile?" data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>Mobile Information</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>Mobile Performance </td>
                                                <td><?= $websitedata['mobileperf'] ?></td>
                                            </tr>
                                            <tr>
                                                <td>Mobile Usability</td>
                                                <td><?= $websitedata['mobileusab'] ?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-wi-desc"> <?= $websitedata['mobtext']?></p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
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
                                        <div class="card-title">Security Requirements</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><i><b>Secure - Provided through an Industry Standard Secure Connection</b></i></div>
                                            <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a secure connection. The report shows how many agency websites are <a href="https://https.cio.gov/" target="_blank"> HTTPS</a> compliant.</span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-Security?" data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                              <td>Enforce HTTPS</td>
                                              <td><?=$websitedata['EnforceHttps']?></td>
                                            </tr>
                                            <tr>
                                              <td>HTTPS Status</td>
                                              <td><?=$websitedata['HttpsStatus']?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-wi-desc"><?=$websitedata['Securitytext'] ?> </p>
                                    <div class="row">
                                        <div class="col-sm-12 website--inner">
                                            <div class="col-md-5 pl-0 mt-xs-2">
                                                <div class="shadow p-1">
                                                    <h5>M-15-13 and BOD 18-01 Information</h5>
                                                    <div><?= $websitedata['m1513status']?></div>
                                                </div>
                                            </div>
                                            <div class="col-md-5 col-md-offset-1 mt-xs-2 pr-0">
                                                <div class="shadow p-1">
                                                    <h5>Free of Insecure Protocols Information</h5>
                                                    <div>Free of RC4/3DES and </div>
                                                    <div>SSLv2/SSlv3: <?= $websitedata['Freestatus']?> </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
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
                                        <div class="card-title">Security Point of Contact (POC)</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><i><b>Secure - Provided through an Industry Standard Secure Connection</b></i></div>
                                            <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a secure connection. The report shows how many agency websites are <a href="https://https.cio.gov/" target="_blank"> HTTPS</a> compliant.</span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-Security?" data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                              <td>Security POC</td>
                                              <td><?php print  $websitedata['poc_status']; ?></td>
                                            </tr>

                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-wi-desc"><?php print $websitedata['poc_description']; ?> </p>

                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
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
                                        <div class="card-title">USWDS Code Usage</div>
                                    </div>
                                    <div class="col-sm-6 mt-xs-1">
                                        <div>
                                            <div><i><b>Consistent - Consistent in Appearance</b></i></div>
                                            <span class="fw-300 f-12 font-italic card-description">21st Century IDEA requires all executive branch public-facing websites and digital services to have a consistent appearance. It also requires agencies to use this <a href="https://designsystem.digital.gov/maturity-model/" target="_blank"> maturity model</a> to gauge compliance with these <a href="https://designsystem.digital.gov/website-standards/" target="_blank">website standards</a> via use of the <a href="https://designsystem.digital.gov/" target="_blank">U.S. Web Design System</a>. This report provides a high-level view of websites and agencies using the U.S. Web Design System (USWDS) code.  </span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-USWDS?" data-toggle="tooltip" ><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>USWDS Checks</th>
                                                <th> Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>USWDS Code</td>
                                                <td><?php
                                                  print $websitedata['uswdsstatus']?></td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-wi-desc" > <?= $websitedata['uswdstext'] ?></p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <div class="relative-position mb-2" id="mobile-break">
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
                                            <div><i><b>Searchable - Contains a Search Function</b></i></div>
                                            <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to have a search function that allows users to easily search content. This report provides a high-level view on how many websites have a search box (detectable through automated scanning), and provides a breakdown of specific on-site search products, where available.  </span>
                                            <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a class="btn" href="/faq#faq-What-is-Search?" data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table class="idea-act-table">
                                            <thead>
                                            <tr>
                                                <th>On-site Search</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>On-site search</td>
                                                <td> <?= $websitedata['onsitestatus']
                                                ?> </td>
                                            </tr>
                                            <tr>
                                              <td>Search engine</td>
                                              <td> <?php
                                                print "<span style='text-transform: capitalize;'>".$websitedata['onsiteengine']."</span>";?> </td>
                                            </tr>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                  <p class="card-wi-desc"> <?= $websitedata['onsitetext'] ?></p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                              <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
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
                          <div><i><b>User-Centric - Designed around user needs with data-driven analysis influencing management and development decisions</b></i></div>
                          <span class="fw-300 f-12 font-italic">21st Century IDEA requires all executive branch public-facing websites and digital services to be designed around user needs with data-driven analysis. The report shows how many websites have implemented the DAP (Digital Analytics Program) code. </span>
                          <a class="f-12 font-italic" href="/faq"><b>Read More</b></a>
                        </div>
                      </div>
                    </div>
                  </div>
                  <div class="card-body relative-position row">
                    <div class="info-icon" id="tooltip-container">
                      <a class="btn" href="/faq#faq-What-is-Digital-Analytics?"  data-toggle="tooltip"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                      </a>
                    </div>
                    <div class="col-sm-6">
                      <div class="table-responsive">
                        <table class="idea-act-table">
                          <thead>
                          <tr>
                            <th scope="col" style="padding-right:50px">DAP</th>
                            <th scope="col" style="padding-left:30px"> Status</th>
                          </tr>
                          </thead>
                          <tbody>
                          <tr>
                            <td>DAP  </td>
                            <td style="padding-left:30px"><?php print $websitedata['dapstatus']?></td>
                          </tr>
                          </tbody>
                        </table>
                      </div>
                    </div>
                    <div class="col-sm-6 mt-xs-1">
                      <p class="card-wi-desc" > <?= $websitedata['daptext']?>.</p>
                    </div>
                  </div>
                  <div class="explore mb-2 px-2">
                    <a href="/idea/govwide/website/<?=arg(3)?>" class="btn btn-digital explore">Explore</a>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
    </div>
</div>
