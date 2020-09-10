<style>
@import "/sites/all/modules/custom/idea_act/css/style.css";
</style>
<?php
drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
$websitedata = ideaact_get_website_data(arg(3));
?>
<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-8 dashboard-left">
                        <h1>GSA.gov <span>(General Services Administration)</span></h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div class="col-md-2 col-md-offset-2 text-right dashboard-right">
                        <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon" data-placement="left" data-toggle="tooltip" title="" data-original-title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do">
                        </a>
                        <button class="button download-button" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="general-services-wrap bg-white shadow">
                <div class="row row-no-gutters">
                    <div class="col-sm-12">
                        <div class="col-sm-9 col-md-6">
                            <div class="row">
                                <div class="col-md-12 d-flex">
                                    <div class="col-sm-3"> <img src="/sites/all/modules/custom/idea_act/images/general-services.png" alt="General Services" width="100"></div>
                                    <div class="col-sm-9">
                                        <p><b>General Services Administration</b></p>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="col-sm-3 col-md-2 col-md-offset-4 logo-wrap">
                            <img src="/sites/all/modules/custom/idea_act/images/logo.png" alt="logo" width="100">
                        </div>
                    </div>
                </div>
            </div>
<!--            <div class="relative-position mb-2 web-info">-->
<!--                <div class="row">-->
<!--                    <div class="col-sm-6">-->
<!--                        <div class="card card-default shadow">-->
<!--                            <div class="card-header card-title">Website Information</div>-->
<!--                            <div class="card-body card-5-7 clearfix">-->
<!--                                <div class="card-left">-->
<!--                                    <img class="dblock-center img-responsive" src="/sites/all/modules/custom/idea_act/images/geography.png" alt="geography" width="70">-->
<!--                                </div>-->
<!--                                <div class="card-right" style="min-height: 200px;">-->
<!---->
<!--                                    <ul class="list-unstyled">-->
<!--                                        <li>ID: National Archives and Records Administration</li>-->
<!--                                        <li>Site: Domain Scan 911commission.gov</li>-->
<!--                                        <li>IP: 129.120.93.242</li>-->
<!--                                        <li>DNS: 129.120.93.242</li>-->
<!--                                        <li>Hosted At: Not Available</li>-->
<!--                                        <li>Cloud Provider:Not Available</li>-->
<!--                                        <li>Alexa Ranking: 0</li></ul>-->
<!---->
<!---->
<!--                                </div>-->
<!--                            </div>-->
<!--                        </div>-->
<!--                    </div>-->
<!--                    <div class="col-sm-6 mt-xs-1">-->
<!--                        <div class="card card-default shadow">-->
<!--                            <div class="card-header card-title">Certificate Information</div>-->
<!--                            <div class="card-body card-5-7 clearfix">-->
<!--                                <div class="card-left">-->
<!--                                    <img class="dblock-center img-responsive" src="/sites/all/modules/custom/idea_act/images/cloud.png" alt="cloud" width="70">-->
<!--                                </div>-->
<!--                                <div class="card-right" style="min-height: 200px; ">-->
<!--                                    <ul class="list-unstyled">-->
<!--                                        <li>Common Name: Not Available</li>-->
<!--                                        <li> Not Available</li>-->
<!--                                        <li>Valid From: Not Available</li>-->
<!--                                        <li>Valid To: Not Available</li>-->
<!--                                        <li>Certificate Issuer: Not Available</li>-->
<!--                                        <li>Certificate provider: Not Available</li>-->
<!--                                        <li>Certificate Status: Not Available</li>-->
<!--                                        <li>Certificate Chain: Not Available</li>-->
<!--                                    </ul>-->
<!--                                </div>-->
<!--                            </div>-->
<!--                        </div>-->
<!--                    </div>-->
<!--                </div>-->
<!--            </div>-->

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
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="chart-container">
                                        <canvas id="chart-webhome" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>

                                    <div class="legend-container">
                                        <div id="chart-1-legend"></div>
                                    </div>
                                    <script lang="javascript">
                                        var ctx = document.getElementById('chart-webhome').getContext('2d');
                                        var chart = new Chart(ctx, {
                                            type: 'doughnut',
                                            data: {
                                                datasets: [{
                                                    data: [6, 2, 14],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#d07413',
                                                        '#218967',
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Color Contrast Issues', 'HTML Attribute Issues', 'Missing Image Desciption Issues']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,

                                                title: {

                                                    display: true,
                                                    text: 'GSA Accessibility spotchecks',
                                                    fontSize: 18,
                                                    fontColor: '#203b5f'

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
                                    </script>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-title">This website has 14 issues with missing image descriptions, 10 issues with HTML attributes and 6 issues with color contrast. </p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                                <a href="/test" class="btn btn-digital disabled">Explore</a>
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Mobile Information</th>
                                                <th>Score</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>Mobile Performance Score </td>
                                                <td>97</td>
                                            </tr>
                                            <tr>
                                                <td>Mobile Usability Score</td>
                                                <td>99</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-title">This website is very responsive and mobile friendly.</p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                                <a href="/test" class="btn btn-digital disabled">Explore</a>
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>Enforce HTTPS</td>
                                                <td>Yes</td>
                                            </tr>
                                            <tr>
                                                <td>HSTS Status</td>
                                                <td>Yes</td>
                                            </tr>
                                            <tr>
                                                <td>HTTPS Score</td>
                                                <td>90</td>
                                            </tr>
                                            <tr>
                                                <td>Preload Status</td>
                                                <td>No</td>
                                            </tr>
                                            <tr>
                                                <td>Preload Ready</td>
                                                <td>No</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-title">This website meets security requirements. The data on the left shows the evaluation criteria. </p>
                                    <div class="row">
                                        <div class="col-sm-12 website--inner">
                                            <div class="col-md-5 pl-0 mt-xs-2">
                                                <div class="shadow p-1">
                                                    <h5>M-15-13 and BOD 18-01 Information</h5>
                                                    <div>Compliant</div>
                                                    <div>Score: 100</div>
                                                </div>
                                            </div>
                                            <div class="col-md-5 col-md-offset-1 mt-xs-2 pr-0">
                                                <div class="shadow p-1">
                                                    <h5>Free of Insecure Protocols Information</h5>
                                                    <div>Free of RC4/3DES and </div>
                                                    <div>SSLv2/SSlv3: 1 </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                                <a href="/test" class="btn btn-digital disabled">Explore</a>
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
                                            <div><i><b>21st Century IDEA Act</b></i></div>
                                            <span class="fw-300">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do</span>
                                            <a href="#"><b>Read More</b></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row">
                                <div class="info-icon" id="tooltip-container">
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table>
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
                                    <p class="card-title"> <?= $websitedata['uswdstext'] ?></p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                                <a href="/test" class="btn btn-digital disabled">Explore</a>
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
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>
                                <div class="col-sm-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>On-site Search</th>
                                                <th>Status</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>On-site search engine:</td>
                                                <td>Available</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-sm-6 mt-xs-1">
                                    <p class="card-title">This website has an on-site search.</p>
                                </div>
                            </div>
                            <div class="explore mb-2 px-2">
                                <a href="/test" class="btn btn-digital disabled">Explore</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
