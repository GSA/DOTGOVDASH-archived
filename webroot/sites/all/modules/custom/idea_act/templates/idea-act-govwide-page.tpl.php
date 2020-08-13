<!DOCTYPE html>
<html lang="en">

<head>
    <title>Gov wide Home</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <link
        href="https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap"
        rel="stylesheet">
    <link rel="stylesheet" href="/sites/all/modules/custom/idea_act/css/style.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>
    <script src="https://cdn.jsdelivr.net/gh/emn178/chartjs-plugin-labels/src/chartjs-plugin-labels.js"></script>
    <style>

    </style>
</head>

<body class="gov_home">
<div class="container-fluid idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-9 dashboard-left">
                        <h1>Government Wide - <span>Century IDEA Act Dashboard</span></h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div class="col-md-2 col-md-offset-1 text-right dashboard-right">
                        <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon"
                                 data-placement="left" data-toggle="tooltip"
                                 title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a>
                        <button class="button download-button" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="reports bg-white shadow">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="col-sm-5 col-md-4">
                            <p>Total Federal Branch Agencies Reported</p>
                            <p class="number">143</p>
                        </div>
                        <div class="col-sm-5 col-md-4">
                            <p>Total Public-Facing Websites Reported</p>
                            <p class="number">1142</p>
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
                                </div>                                    <div class="col-sm-6 mt-xs-1">
                                    <h4>Average Accessibility Issues by Type Per Website</h4>
                                    <p>Average Color Contrast: 3.5</p>
                                    <p>Average HTML Attribute: 3.7</p>
                                    <p>Average Missing Image Description: 1.2</p>
                                    <p>(Note: website redirects are excluded)</p>
                                </div>
                                <div class="col-sm-6">
                                    <div class="chart-container">
                                        <canvas id="chart-gov1" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                </div>
                            </div>

                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-1-legend"></div></div>
                            </div>

                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov1').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [1339, 4219, 3980],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#563eb6',
                                                '#d07413',
                                                '#808f4e',

                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Color Contrast Issues', 'Missing Image Description Issues', 'HTML Attribute Issues']
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
                                </div>                                    <div class="col-md-6">
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
                                                <td>911</td>
                                                <td>78%</td>
                                            </tr>
                                            <tr>
                                                <td>Websites without USWDS code detected</td>
                                                <td>218</td>
                                                <td>22%</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov2" width="250" height="300" aria-label="Charts" role="img"></canvas>

                                    </div>
                                </div>
                            </div>
                            <div class="card-body relative-position row nmt-3">
                                <div class="col-sm-6">
                                    <div class="explore mb-2">
                                        <a href="/test" class="btn btn-digital disabled">Explore</a>
                                    </div>
                                </div>
                                <div class="col-sm-6">
                                    <div id="chart-2-legend"></div></div>
                            </div>
                            <script lang="javascript">
                                var ctx = document.getElementById('chart-gov2').getContext('2d');
                                var chart = new Chart(ctx, {
                                    type: 'doughnut',
                                    data: {
                                        datasets: [{
                                            data: [22, 78],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#00699e',
                                                '#ed4878',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['USWDS Code Not Detected', 'USWDS Code Usage']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: 'USWDS Code Usage Breakdown for Websites',
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
                                var myLegendContainer = document.getElementById("chart-2-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
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
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>                                    <div class="col-md-6">
                                    <div class="table-responsive">
                                        <table>
                                            <thead>
                                            <tr>
                                                <th>Criteria</th>
                                                <th>Compliant</th>
                                                <th>Non-compliant</th>
                                            </tr>
                                            </thead>
                                            <tbody>
                                            <tr>
                                                <td>HTTPS Status Websites</td>
                                                <td>887</td>
                                                <td>74%</td>
                                            </tr>
                                            <tr>
                                                <td>HTTPS Status Percentage</td>
                                                <td>257</td>
                                                <td>26%</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov3" width="250" height="300" aria-label="Charts" role="img"></canvas>

                                    </div>
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
                                            data: [26, 74],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#97d1ff',
                                                '#00a65f',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Non-compliant Websites', 'Compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: 'HTTPS Websites Compliance',
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
                                var myLegendContainer = document.getElementById("chart-3-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
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
                                </div>                                    <div class="col-md-6">
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
                                            <tr>
                                                <td>Custom Search</td>
                                                <td>228</td>
                                                <td>25%</td>
                                            </tr>
                                            <tr>
                                                <td>Search.usa.gov</td>
                                                <td>151</td>
                                                <td>15%</td>
                                            </tr>
                                            <tr>
                                                <td>Drupal Core Search</td>
                                                <td>104</td>
                                                <td>9%</td>
                                            </tr>
                                            <tr>
                                                <td>Google Custom Search</td>
                                                <td>27</td>
                                                <td>3%</td>
                                            </tr>
                                            <tr>
                                                <td>Apache Solr</td>
                                                <td>6</td>
                                                <td>< 1%</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov-search" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
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
                                            data: [67, 33],
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
                                            text: 'On-site Search Engine Breakdown',
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
                                var myLegendContainer = document.getElementById("chart-4-legend");
                                myLegendContainer.innerHTML = chart.generateLegend();
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
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>                                    <div class="col-md-6 mb-2">
                                    <div class="chart-container">
                                        <canvas id="chart-gov4" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-5-legend"></div>
                                    </div>
                                    <div class="table-responsive">
                                        <table class="mt-1">
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
                                                <td>294</td>
                                                <td>19%</td>
                                            </tr>
                                            <tr>
                                                <td>Poor</td>
                                                <td>430</td>
                                                <td>41%</td>
                                            </tr>
                                            <tr>
                                                <td>Needs Improvement</td>
                                                <td>420</td>
                                                <td>40%</td>
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
                                                    data: [19, 19, 40],
                                                    borderWidth: 0,
                                                    backgroundColor: [
                                                        '#563eb6',
                                                        '#218967',
                                                        '#c95d00'
                                                    ]
                                                }],
                                                // These labels appear in the legend and in the tooltips when hovering different arcs
                                                labels: ['Good', 'Poor', 'Needs Improvement']
                                            },

                                            // Configuration options go here
                                            options: {
                                                // responsive: true,
                                                maintainAspectRatio: false,

                                                title: {
                                                    display: true,
                                                    text: 'Mobile Performance Breakdown',
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
                                        var myLegendContainer = document.getElementById("chart-5-legend");
                                        myLegendContainer.innerHTML = chart.generateLegend();
                                    </script>

                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov5" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
                                    <div class="legend-container">
                                        <div id="chart-6-legend"></div>
                                    </div>
                                    <div class="table-responsive">
                                        <table class="mt-1">
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
                                                <td>460</td>
                                                <td>44%</td>
                                            </tr>
                                            <tr>
                                                <td>Not Mobile Friendly</td>
                                                <td>570</td>
                                                <td>56%</td>
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
                                                    data: [44, 56],
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
                                                    text: 'Mobile Friendly Breakdown',
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
                                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                                    </a>
                                </div>                                    <div class="col-md-6">
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
                                                <td>718</td>
                                                <td>71%</td>
                                            </tr>
                                            <tr>
                                                <td>DAP Non-Compliant Websites</td>
                                                <td>334</td>
                                                <td>29%</td>
                                            </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </div>
                                <div class="col-md-6 mt-xs-1">
                                    <div class="chart-container">
                                        <canvas id="chart-gov6" width="250" height="300" aria-label="Charts" role="img"></canvas>
                                    </div>
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
                                            data: [71, 29],
                                            borderWidth: 0,
                                            backgroundColor: [
                                                '#00a1be',
                                                '#de9738',
                                            ]
                                        }],
                                        // These labels appear in the legend and in the tooltips when hovering different arcs
                                        labels: ['Non-compliant Websites', 'compliant Websites']
                                    },

                                    // Configuration options go here
                                    options: {
                                        // responsive: true,
                                        maintainAspectRatio: false,

                                        title: {
                                            display: true,
                                            text: 'DAP Website Compliance',
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
                            </script>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<script>
    $('#tooltip-container [data-toggle="tooltip"]').tooltip({
        animated: 'fade',
        placement: 'left',
        html: true,
        background: '#000'
    });

    $('table').find("th").each(function (i) {
        $('table td:nth-child(' + (i + 1) + ')').prepend('<span class="table-responsive-stack-thead">'+ $(this).text() + ':</span> ');
        $('.table-responsive-stack-thead').hide();
    });

    $( 'table' ).each(function() {
        var thCount = $(this).find("th").length;
        var rowGrow = 100 / thCount + '%';
        //console.log(rowGrow);
        $(this).find("th, td").css('flex-basis', rowGrow);
    });

    function flexTable(){
        if ($(window).width() < 768) {
            $("table").each(function (i) {
                $(this).find(".table-responsive-stack-thead").show();
                $(this).find('thead').hide();
            });
            // window is less than 768px
        } else {
            $("table").each(function (i) {
                $(this).find(".table-responsive-stack-thead").hide();
                $(this).find('thead').show();
            });
        }
        // flextable
    }

    flexTable();

    window.onresize = function(event) {
        flexTable();
    };
</script>
</body>

</html>
