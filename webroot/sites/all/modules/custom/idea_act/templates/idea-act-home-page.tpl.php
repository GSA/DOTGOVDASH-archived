<style>
@import "/sites/all/modules/custom/idea_act/css/style.css";
</style>
<?php
drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
?>

<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-9 dashboard-left">
                        <h1>21st Century IDEA Act Dashboard</h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div class="col-md-2 col-md-offset-1 text-right dashboard-right">
                        <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon" data-placement="left" data-toggle="tooltip" title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a>
                        <button class="button download-button" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="reports bg-white shadow">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="col-sm-6 col-md-4">
                            <p>Total Public-Facing Websites Reported</p>
                            <p class="number">1142</p>
                        </div>
                        <div class="col-sm-6 col-md-4">
                            <p>Total Federal Branch Agencies Reported</p>
                            <p class="number">143</p>
                        </div>
                    </div>
                </div>
            </div>
            <div class="requirements bg-white shadow relative-position">
                <div class="info-icon" id="tooltip-container">
                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                    </a>
                </div>                    <h2 class="h2-title">Modernization Requirements</h2>
                <div class="row text-center">
                    <div class="col-sm-12 modern-wrap mb-2">
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Accessibility</strong></h4>
                            <p>Websites shall be accessible to individuals with disabilities</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>USDWS</strong></h4>
                            <p>Websites shall be consistent in  appearance</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Search</strong></h4>
                            <p>Websites shall contain on-site search functionality</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Security</strong></h4>
                            <p>Websites shall have an industry standard  secure connections</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Mobile</strong></h4>
                            <p>Websites shall be fully functional on mobile devices</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Digital Analytics</strong></h4>
                            <p>Websites shall be designed with data-driven analysis</p>
                        </div>
                    </div>
                </div>
                <div class="explore text-center">
                    <a href="/test" class="btn btn-digital disabled">Explore All</a>
                </div>
            </div>
            <div class="agencies bg-white shadow relative-position">
                <h2 class="h2-title">Browse by Agencies</h2>
                <div class="info-icon" id="tooltip-container">
                    <a data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                    </a>
                </div>                    <div class="row text-center">
                    <div class="col-sm-12">
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/general-services.png" alt="General Services" />
                            <div>General Services Administration</div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">98</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/commerce.png" alt="Commerce">
                            <div>Department of Commerce</div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">50</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/human-services.png" alt="Human Services" />
                            <div>Health & Human Services </div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">107</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/justice.png" alt="Justice" />
                            <div>Department of Justice </div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">70</p>
                        </div>
                    </div>
                </div>
                <div id="explore-all"class="row text-center collapse">
                    <div class="col-sm-12">
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/general-services.png" alt="General Services" />
                            <div>General Services Administration</div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">98</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/commerce.png" alt="Commerce">
                            <div>Department of Commerce</div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">50</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/human-services.png" alt="Human Services" />
                            <div>Health & Human Services </div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">107</p>
                        </div>
                        <div class="col-sm-6 col-md-3">
                            <img src="/sites/all/modules/custom/idea_act/images/justice.png" alt="Justice" />
                            <div>Department of Justice </div>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class="number">70</p>
                        </div>
                    </div>
                </div>

                <div class="explore text-center">
                    <a data-toggle="collapse" data-target="#explore-all" class="btn btn-digital disabled">Explore All</a>
                </div>
            </div>
        </div>
    </div>
</div>
