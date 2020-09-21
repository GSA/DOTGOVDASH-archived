<style>
@import "/sites/all/modules/custom/idea_act/css/style.css";
.h2-title {
    padding-bottom: 2rem;
}
</style>

<?php
drupal_add_css("https://fonts.googleapis.com/css2?family=Fira+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap");
drupal_set_title("21st Century IDEA Act Report");
$agencies = $agency_data['actualdata']['agency_data'];
$total_websites_count = $agency_data['actualdata']['total_websites_count'];

//print "<pre>";  print_r($agencies); print "</pre>"; exit;
?>

<div class="idea-container">
    <div class="row">
        <div class="col-lg-10 col-lg-offset-1">
            <div class="row row-no-gutters">
                <div class="col-md-12 dashboard-wrap">
                    <div class="col-md-9 dashboard-left">
                        <h1>21st Century IDEA Act Report</h1>
                        <p class="description">This page provides a snapshot of the 21st Century IDEA Act conformance across federal government executive branch public-facing websites.</p>
                    </div>
                    <div id="element-to-hide" data-html2canvas-ignore="true" class="col-md-2 col-md-offset-1 text-right dashboard-right">
                        <!-- <a href="#">
                            <img src="/sites/all/modules/custom/idea_act/images/question-icon.png" alt="question icon" class="question-icon" data-placement="left" data-toggle="tooltip" title="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed doLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do" />
                        </a> -->
                        <button class="button download-button"  onclick="generatePDF('idea_act_home_page.pdf', 400, 735)" type="submit">Download</button>
                    </div>
                </div>
            </div>
            <div class="reports bg-white shadow">
                <div class="row">
                    <div class="col-sm-12">
                        <div class="col-sm-6 col-md-4 mb-2 mt-2">
                            <p>Total Public-Facing Websites Reported</p>
                            <p class="number"><?php echo $total_websites_count['total_websites'] ?></p>
                        </div>
                        <div class="col-sm-6 col-md-4 mb-2 mt-2">
                            <p>Total Federal Branch Agencies Reported</p>
                            <p class="number"><?php echo $total_websites_count['total_agencies'] ?></p>
                        </div>
                    </div>
                </div>
            </div>
            <div class="requirements bg-white shadow relative-position">
                <div class="info-icon" id="tooltip-container">
                    <a  class="btn disabled" data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                    </a>
                </div>                    
                <h2 class="h2-title">Modernization Requirements</h2>
                <div class="row text-center">
                    <div class="col-sm-12 modern-wrap mb-2">
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>Accessibility</strong></h4>
                            <p>Websites shall be accessible to individuals with disabilities</p>
                        </div>
                        <div class="col-sm-6 col-md-2 modern-item">
                            <h4><strong>USWDS</strong></h4>
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
                    <a href="//digital.gov/resources/21st-century-integrated-digital-experience-act/" class="btn btn-digital">Explore All</a>
                </div>
            </div>
            <div class="agencies bg-white shadow relative-position">
                <div class="info-icon" id="tooltip-container">
                    <a  class="btn disabled" data-toggle="tooltip" title="<span><img class='tt-img' src='/sites/all/modules/custom/idea_act/images/gov-logo.png'><br><p class='tt-text'>Info Line 1 <br>Info Line 2 <br>Info Line 3</p></span>"><img src="/sites/all/modules/custom/idea_act/images/info.png" alt="info">
                    </a>
                </div>     
                <h2 class="h2-title">Browse by Agencies</h2>          
                <div class="row text-center browse-agencies">
                    <div class="row1">
                       <?php
                       $count = 0;
                        foreach ($agencies as $key => $agency) {
                            print "<a href=/ideaact/agencywide/dashboard/".$agency['nid']."><div class='col-sm-6 col-md-3 agency-info '>
                            <img class='agency-logo' src='" . $agency['url'] . "' alt='". $agency['title'] ."' />
                            <p class='agency-title'>". $agency['title'] ."</p>
                            <p><strong><i>Total Websites</i></strong></p>
                            <p class='number'>". $agency['websitenos'] ."</p>
                          </div></a>";
                          if ($count == 3) {
                              print "</div><div class='row2' style='display:none;' id='row-none'>";
                          }
                          $count++;
                        }
                        ?>
                        </div>
                </div>

                <div class="explore text-center">
                    <a class="btn btn-digital show-agencies" id="btn-explore" >Explore All</a>
                </div>
                </div>
            </div>
        </div>
    </div>
</div>
