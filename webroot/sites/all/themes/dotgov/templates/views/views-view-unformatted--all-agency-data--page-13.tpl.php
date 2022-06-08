<style>
    .view-wrapper {
        min-height: 380px;
    }
    .font-italic {
        font-style:italic;
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

    .min-330 {
        min-height: 330px;
    }

</style>
<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
dotgov_common_tooltip("tooltip2", "id");
dotgov_common_tooltip("tooltip4", "id");
dotgov_common_tooltip("tooltip3", "id");
dotgov_common_tooltip("tooltip5", "id");
dotgov_common_tooltip("tooltip7", "id");
dotgov_common_tooltip("tooltip6", "id");
dotgov_common_tooltip("tooltip9", "id");
dotgov_common_tooltip("tooltip8", "id");

$agencydata = dotgov_common_getAgencyComplianceData(arg(1));

foreach ($view->style_plugin->rendered_fields[0] as $key => $val) {
    if ($key == 'field_web_agency_id_1') {
        $agency_website_num = $val;
    }

}
$agency_https_score = round(db_query("select avg(c.field_https_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_https_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_dap_score = round(db_query("select avg(c.field_dap_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_dap_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_mobovr_score = round(db_query("select avg(c.field_mobile_overall_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_overall_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_mobperf_score = round(db_query("select avg(c.field_mobile_performance_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_performance_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_mobusab_score = round(db_query("select avg(c.field_mobile_usability_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_mobile_usability_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_ipv6_score = round(db_query("select avg(c.field_ipv6_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_ipv6_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_dnssec_score = round(db_query("select avg(c.field_dnssec_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_dnssec_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_insecprot_score = round(db_query("select avg(c.field_free_of_insecr_prot_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_free_of_insecr_prot_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_m15_score = round(db_query("select avg(c.field_m15_13_compliance_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_m15_13_compliance_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());
$agency_uswds_score = round(db_query("select avg(c.field_uswds_score_value) as avg_value from node a , field_data_field_web_agency_id b , field_data_field_uswds_score c  where a.type='website' and a.type=b.bundle and a.status ='1' and a.nid=b.entity_id and b.entity_id=c.entity_id and field_web_agency_id_nid=:agencyid", array(':agencyid' => arg(1)))->fetchField());

$agencynode = node_load(arg(1));

$mobperf_arr = array($agencydata['good'], $agencydata['improve'], $agencydata['poor']);
$mobperf_arr = dotgov_common_get_percentage($mobperf_arr, $agencydata['good']+$agencydata['improve']+$agencydata['poor']);
$mobusab_arr = array($agencydata['friendly'], $agencydata['nonfriendly']);
$mobusab_arr = dotgov_common_get_percentage($mobusab_arr, $agencydata['friendly']+$agencydata['nonfriendly']);

$dnssec_arr = array($agencydata['dns_compliant'], $agencydata['dns_noncompliant']);
$dnssec_arr = dotgov_common_get_percentage($dnssec_arr, $agency_website_num);

$enfhttps_arr = array($agencydata['enfhttps_support'], $agencydata['enfhttps_nosupport']);
$enfhttps_arr = dotgov_common_get_percentage($enfhttps_arr, $agency_website_num);
$hsts_arr = array($agencydata['hsts_support'], $agencydata['hsts_nosupport']);
$hsts_arr = dotgov_common_get_percentage($hsts_arr, $agency_website_num);
$https_arr = array($agencydata['https_support'], $agencydata['https_nosupport']);
$https_arr = dotgov_common_get_percentage($https_arr, $agency_website_num);
$preload_arr = array($agencydata['preload_support'], $agencydata['preload_nosupport']);
$preload_arr = dotgov_common_get_percentage($preload_arr, $agency_website_num);
$preloadready_arr = array($agencydata['preload_readysupport']);
$preloadready_arr = dotgov_common_get_percentage($preloadready_arr, $agency_website_num);

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
<div class="download-pdf">
    <a href="#" onclick="generatePDF('<?=$agencynode->title?>' ,600,1150, false)"><img src="/sites/all/themes/dotgov/images/pdf-download.svg" style="height: 40px;cursor: pointer;" alt="Download Pdf">
    </a>
</div>
<div class="main-container container-fluid nopadding">
    <div class="row">
        <section class="col-sm-12 nopadding">
            <div class="col-xs-12 nopadding clearfix">
                <div class="col-xs-12">
                    <div class="field-content">
                        <div class="col-xs-12 no-height white-back">
                            <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
                                <h3>Agency</h3>
                                <p>
                                    <?=$agencynode->title?>
                                </p>
                            </div>
                            <div class="col-lg-4 col-sm-12 col-xs-12 text-center">
                                <?php
if ($agencynode->field_agency_logo['und'][0]['uri'] != '') {
    ?>
                                    <img width='100' src="<?php print file_create_url($agencynode->field_agency_logo['und'][0]['uri']);?>" alt="<?=$agencynode->title?>">
                                    <?php
} else {
    print "&nbsp;";
}
?>
                            </div>
                            <div class="col-lg-3 col-sm-12 col-xs-12 text-center">
                                <h3>Public-Facing Websites Reported</h3>
                                <p></p>
                                <p>
                                    <?=$agency_website_num?>
                                </p>
                                <p></p>
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
                      <div class="panel-pane pane-views pane-website-information">
                        <div class="col-xs-12 nopadding">
                          <div class="col-xs-10 nopadding">
                            <h2 class="pane-title"> Mobile Information </h2>
                          </div>
                          <div class="col-xs-2 nopadding">
                            <div id="tooltip4" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart_mobile.png" alt="Image for the color code"><br>
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
                                    <div class="views-field views-field-php-2 col-lg-6 nopadding grey-gradient" style="height:270px;">
                                      <div class ="col-md-12 col-lg-12" style="padding-left:10px;">
                                        <h5>Mobile Performance Breakdown</h5>
                                      </div>
                                      <div class="col-lg-6 col-md-6" style="padding-right:0px;margin-top:15px;padding-left:10px;font-size: 10px;">
                                        <span class="dot good"></span>Good<br/>
                                        <span class="dot avg"></span>Needs Improvement <br/>
                                        <span class="dot low"></span>Poor <br/>
                                      </div>
                                      <div class="col-lg-6 col-md-6 nopadding">
                                        <div id="piechartmob" style="margin-top:-17px;height:140px;"></div>
                                        <?php print $agencydata['ag_mob_chart'];?>
                                      </div>
                                      <table style="width:100%" aria-label="Mobile Performance Breakdown Table">
                                        <th style="background-color: #215393;color: white;"> Breakdown </th>
                                        <th style="background-color: #215393;color: white;"> Websites </th>
                                        <tr>
                                          <td>Good</td>
                                          <td><?=dotgov_common_getColor($agencydata['good'], '#276437', $mobperf_arr[0])?></td>
                                        </tr>
                                        <tr>
                                          <td>Needs Improvement</td>
                                          <td><?=dotgov_common_getColor($agencydata['improve'], '#665000', $mobperf_arr[1])?></td>
                                        </tr>
                                        <tr>
                                          <td>Poor</td>
                                          <td><?=dotgov_common_getColor($agencydata['poor'], '#ae0100', $mobperf_arr[2])?></td>
                                        </tr>
                                        <tr>
                                          <td>Total</td>
                                          <td><span style="font-weight:bold;"><?=$agencydata['good']+$agencydata['improve']+$agencydata['poor'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                        </tr>
                                      </table>
                                    </div>
                                    <div class="col-xs-12 col-lg-6 nopadding grey-gradient second" style="height:270px;">
                                      <div class ="col-md-12 col-lg-12" style="padding-left:10px;">
                                        <h5>Mobile Usability Breakdown
                                      </div>
                                      <div class="col-lg-6 col-md-6" style="padding-right:0px;margin-top:15px;padding-left:10px;font-size: 10px">
                                        <span class="dot good"></span>Mobile Friendly <br/>
                                        <span class="dot low"></span>Not Mobile Friendly <br/>
                                      </div>
                                      <div class="col-lg-6 col-md-6 nopadding">
                                        <div id="piechartmobusab" style="margin-top:-17px;height:140px;"></div>
                                        <?php print $agencydata['ag_mob_usab_chart'];?>
                                      </div>
                                      <table style="width:100%" aria-label="Mobile Usability Breakdown Table">
                                        <th style="background-color: #215393;color: white;"> Breakdown </th>
                                        <th style="background-color: #215393;color: white;"> Websites </th>
                                        <tr>
                                          <td>Mobile Friendly</td>
                                          <td><?=dotgov_common_getColor($agencydata['friendly'], '#276437', $mobusab_arr[0])?></td>
                                        </tr>
                                        <tr>
                                          <td>Not Mobile Friendly</td>
                                          <td><?=dotgov_common_getColor($agencydata['nonfriendly'], '#ae0100', $mobusab_arr[1])?></td>
                                        </tr>
                                        <tr>
                                          <td>Total</td>
                                          <td><span style="font-weight:bold;"><?=$agencydata['friendly']+$agencydata['nonfriendly'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                        </tr>
                                      </table>
                                    </div>
                                  </div>
                                </div>
                              </div>
                              <br clear="all" />
                              <div class='col-lg-12 text-center clearfix'><span style='color:#29643a; font-size: 10px;font-style: italic;'>
                                       Above graphs show the breakdown of Mobile Performance and Mobile Usability. The graphs and breakdowns only include websites that have data. <?=$agencydata['data_na'];?> websites do not have data for Mobile Performance and <?=$agencydata['data_na_usab'];?> websites do not have data for Mobile Usability.</span></div>
                              <br clear="all" />
                              <div class="view-button clearfix">
                                <div class="row text-center">
                                  <a class="" title="link for mobile performance full report" href="/website/mobile/reports?field_web_agency_id_nid=<?=arg(1)?>"> <img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                  <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
                                    <div id="tooltip9" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"> <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br/>
                    Accessibility Data is collected from pulse.gov website though a scan that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content clearfix">
                                    <div class="view-wrapper" style="min-height:290px;">
                                        <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                            <div class="view-empty clearfix">
                                                <div class="col-lg-6 grey-gradient" style="height:270px;">
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
                                                        <span style="font-size:12px;">(Note: Website redirects are excluded. Accessibility Spot Checks include only Color Contrast, HTML Attributes and Missing Image Description Accessibility Issues)</span></div>
                                                </div>
                                                <div class="col-lg-6 grey-gradient second" style="height:270px;">
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
                                                            chartArea:{left:0,top:0,height: '50%',width:'100%'},
                                                            legend:{position:'left',alignment:'center'}
                                                        };

                                                        var chart = new google.visualization.PieChart(document.getElementById('piechart'));

                                                        chart.draw(data, options);
                                                    }
                                                    window.onload = function() {
                                                      function myFunction(x) {
                                                        if (x.matches && !document.getElementById('new-br')) { //less than 1342 and no br. create br
                                                            var e = document.createElement('br');
                                                            e.setAttribute("id", "new-br");
                                                            e.setAttribute("clear", "all");
                                                            document.getElementById('br-height').insertBefore(e, document.getElementById('br-height').childNodes[2]);
                                                        } else if (document.getElementById('new-br')) { //greater than 1342 and br exists, remove it
                                                            document.getElementById('new-br').remove();
                                                        }
                                                      }
                                                      var x = window.matchMedia("(max-width: 1362px)");
                                                      myFunction(x); // Call listener function at run time
                                                      x.addListener(myFunction); // Attach listener function on state changes
                                                    }
                                                </script>
                                                <?php
                                                    if (($agencydata['ag_col_contrast'] + $agencydata['ag_html_attrib'] + $agencydata['ag_miss_image']) != 0) {
                                                        print "<div class='col-lg-12 text-center clearfix' id='br-height'><br clear=\"all\" /><br clear=\"all\" /><span style='color:#29643a; font-size: 10px;font-style: italic;'>
                                                    Above graph shows the breakdown of Accessibility Issues by category</span></div>
                                                    ";
                                                    }
                                                    ?>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="view-button">
                                        <div class="row text-center">
                                            <a title="link for accessiblity issues full report" href="/accessibilityreportalldomains?field_web_agency_id_nid_selective=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                            <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">DNSSEC Information</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip5" class="infor"> <img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"> <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
                    DNSSEC Data is collected through a custom scanner component of dotgov dashboard that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content">
                                    <div class="view  view-display-id-block_7 view-dom-id-3e71e61814bfdc7fd3678ddb5e0c33c9">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-nothing">
                                                    <div class="field-content col-lg-12">
                                                        <div class="view-wrapper" style="min-height:350px">
                                                            <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient" style="height:165px;">
                                                                <h5>DNSSEC Score Breakdown</h5>
                                                                <table width="100%" class="dnssec-table" aria-label="DNSSEC Score Breakdown Table">

                                                                    <th style="background-color: #215393;color: white;">Breakdown</th>
                                                                    <th style="background-color: #215393;color: white;">Websites </th>
                                                                    <tr>
                                                                        <td>DNSSEC Compliant Websites</td>
                                                                        <td><?=dotgov_common_getColor($agencydata['dns_compliant'], '#29643a', $dnssec_arr[0])?></td>
                                                                    </tr>
                                                                    <tr>
                                                                        <td>DNSSEC Non Compliant Websites</td>
                                                                        <td><?=dotgov_common_getColor($agencydata['dns_noncompliant'], '#ac0600', $dnssec_arr[1])?></td>
                                                                    </tr>
                                                                    <tr>
                                                                       <td>Total</td>
                                                                       <td><span style="font-weight:bold;"><?=$agency_website_num;?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                                                    </tr>
                                                                </table>
                                                            </div>
                                                            <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient second" style="height:165px;">
                                                                <h5>DNSSEC Overall Average Score :
                                                                    <?=$agency_dnssec_score?>
                                                                    % </h5>
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
                                                                <a class="" title="link for DNSSEC full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                                                <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
                    <div class="col-xs-12 col-lg-6">
                        <div class="white-back no-height">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> On-Site Search Information </h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip5" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"> On-Site Search Data is collected through a custom scanner component of dotgov dashboard that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content">
                                    <div class="view-wrapper" style="min-height:350px">
                                        <div class="view  view-display-id-block_9 view-dom-id-0e17f9248601bc7d12258e818483f4b0">
                                            <div class="view-empty">
                                                <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient min-330 pie-chart" >
                                                    <div class ="col-md-12 col-lg-12 nopadding" >
                                                       <h5>On-Site Search Engine Status Breakdown</h5>
                                                    </div>
                                                    <div id="piechart3"></div>
                                                    <?php print $agencydata['searchenginestatus_graph'];
//print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engines by category</span>";
$searchenginestatus = $agencydata['searchenginestatus'];
?>
                                                    <table  aria-label="On-Site Search Engine Breakdown Table">
                                                        <tr style="background-color: #215393;color: white;">
                                                            <td style="padding-right: 12px;"> On-Site Search Detected</td>
                                                            <td>On-Site Search Not Detected</td>
                                                        </tr>
                                                        <tr>
                                                            <td><?=($searchenginestatus['search_available'] == "") ? 0 : $searchenginestatus['search_available']?></td>
                                                            <td><?=($searchenginestatus['search_notavailable'] == "") ? 0 : $searchenginestatus['search_notavailable']?></td>
                                                        </tr>
                                                    </table><span style="font-size:12px;">(Note: website redirects are excluded)</span>
                                                </div>
                                                <div class="col-xs-12 col-md-12 col-lg-6 grey-gradient min-330 second bar-chart" >
                                                    <div class ="col-md-12 col-lg-12 nopadding" >
                                                       <h5>On-Site Search Engine Breakdown</h5>
                                                    </div>
                                                    <div id="piechart2"></div>
                                                    <?php print $agencydata['searchengines_graph'];
//print "<span style='color:#29643a; font-size: 12px;font-style: italic;'>Above graph shows the breakdown of On-Site Search Engines</span>";
?>
                                                    <table style="width:100%" aria-label="On-Site Search Engine Status Table">
                                                        <tr style="background-color: #215393;color: white;">
                                                            <td>On-Site Search Engine</td>
                                                            <td>&nbsp;Total</td>
                                                        </tr>
                                                        <?php
foreach ($agencydata['searchenginedata'] as $skey => $sval) {
    print "<tr style='text-transform: capitalize;'><td>" . ucfirst($skey) . "</td><td align='center'>   $sval</td> </tr>";
}
?>
                                                    </table></div>
                                            </div>


                                            <div class="clearfix">&nbsp;</div>
                                        </div>
                                    </div>
                                    <div class="view-button clearfix"><div class="row text-center">
                                            <a class="" title="link for Search engine status full report" href="/website/search/reports?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                            <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
                    <div class="col-xs-12  col-lg-4">
                        <div class="white-back no-height">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> HTTPS Information </h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip2" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
                    HTTPS Data is collected through a custom scanner component of digital dashboard that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content clearfix">
                                    <div class="view-wrapper">
                                        <div class="grey-gradient clearfix">
                                            <div class="col-xs-12">
                                                <h5>HTTPS score breakdown</h5>
                                                <div class="col-sm-12 col-lg-6 nopadding">
                                                    <p>  HTTPS Overall Average Score :
                                                        <?=$agency_https_score?>
                                                        % </p>
                                                    <span style="font-size:12px;" class="font-italic">The individual site score is based on several different metrics. See scoring methods for more info.</span>
                                                </div>
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
                                                    </script>
                                                </div>
                                            </div>
                                            <table width="100%" aria-label="HTTPS score breakdown Table">
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
                                                    <td align="center"><?=dotgov_common_getColor($agencydata['preload_readysupport'], '#29643a', $preloadready_arr[0])?></td>
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
                                    <div class="view-button">
                                        <div class="row text-center">
                                            <a class="" title="link for htts trend full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                            <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-xs-12 col-lg-4">
                        <div class="white-back no-height">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">M-15-13 and BOD 18-01 Information</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                                    <div id="tooltip7" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
                    M-15-13 and BOD 18-01 Data is collected through a custom scanner component of dotgov dashboard that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content clearfix">
                                    <div class="view  view-display-id-block_10 view-dom-id-93e7fd06306700be9064f5e8954f211b">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-php-2 col-lg-12">
                                                    <div class="view-wrapper">
                                                        <div class="grey-gradient clearfix min-295">

                                                            <div class="col-xs-12 height-wrap-first"><h5>M-15-13 and BOD 18-01 score breakdown</h5>
                                                                <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding">
                                                                    <p> Compliant with M-15-13 and BOD 18-01 Overall Average Score :
                                                                        <?=$agency_m15_score?>
                                                                        % </p>
                                                                    <span style="font-size:12px;" class="font-italic">The individual site score is 100 for compliant 0 for non-compliant</span>
                                                                </div>
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
                                                                    </script>
                                                                </div></div>
                                                            <table width="100%" aria-label="M-15-13 and BOD 18-01 score breakdown Table">

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
                                                                <tr>
                                                                   <td>Total</td>
                                                                   <td><span style="font-weight:bold;"><?=$agencydata['m15_compliant']+$agencydata['m15_noncompliant'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
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
                                                    <div class="view-button">
                                                        <div class="row text-center">
                                                            <a class="" title="link for  M-15-13 Trend full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                                            <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
                    <div class="col-xs-12 col-lg-4">
                        <div class="white-back no-height">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title"> IPV6 Information </h2>
                                </div>
                                <div class="col-xs-2">
                                    <div id="tooltip6" class="infor"> <img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">  <span class="tooltiptext tooltip-left"> <img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code"> IPV6 Data is collected through a custom scanner component of dotgov dashboard that last ran on
                                            <?php dotgov_common_lastScanDate();?>
                    </span> </div>
                                </div>
                                <br clear="all"/>
                                <div class="pane-content clearfix">
                                    <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                        <div class="view-content">
                                            <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                                <div class="views-field views-field-nothing">
                                                    <div class="field-content col-lg-12">
                                                        <div class="view-wrapper">
                                                            <div class="grey-gradient clearfix min-295">
                                                                <div class="col-xs-12 height-wrap-first"><h5>IPV6 score breakdown</h5>
                                                                    <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 nopadding">
                                                                        <p>IPV6 Overall Average Score :
                                                                            <?=$agency_ipv6_score?>
                                                                            %

                                                                        </p><span style="font-size:12px;" class="font-italic">The individual site score is 100 for compliant 0 for non-compliant</span>
                                                                    </div>
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
                                                                        </script>
                                                                    </div></div>
                                                                <table width="100%" aria-label="IPV6 Score Breakdown Table">

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
                                                                    <tr width="100%">
                                                                       <td>Total</td>
                                                                       <td><span style="font-weight:bold;"><?=$agency_website_num;?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                                                    </tr>
                                                                </table><span class="col-xs-12 text-center clearfix" style="font-size:10px;">(website redirects are excluded)</span></div>
                                                            <div class="row">
                                                                <?php
$blockObject7 = block_load('trend_analysis', 'agency_ipv6');
$block7 = _block_get_renderable_array(_block_render_blocks(array($blockObject7)));
$output7 = drupal_render($block7);
print "$output7 <span class='col-xs-12 nopadding text-center' style='color: " . dotgov_common_getChartColor($agency_ipv6_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly IPv6 Trend</span>";
?>
                                                            </div>
                                                        </div>
                                                        <div class="view-button">
                                                            <div class="row text-center">
                                                                <a class="" title="link for IPv6 Trend full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                                                <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
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
            <div class="panel-separator clearfix"></div>
            <div class="out-wrapper">
                <div class="col-xs-12 nopadding clearfix">
                    <div class="col-xs-12 col-lg-4">
                        <div class="white-back">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">DAP Information</h2>
                                </div>
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
                                                        </script>
                                                    </div>
                                                        </div>
                                                    <table style="width:100%;" aria-label="DAP Information Breakdown Table">

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
                                                        <tr>
                                                           <td>Total</td>
                                                           <td><span style="font-weight:bold;"><?=$agencydata['dap_compliant'] + $agencydata['dap_noncompliant'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                                        </tr>
                                                    </table>
                                                    <div class="col-xs-12 clearfix">
                                                        <span class="text-center col-xs-12" style="font-size:10px;">(Note: website redirects are excluded)</span> </div>
                                                </div>
                                                <div class="col-xs-12 nopadding clearfix"> <?php
$blockObject6 = block_load('trend_analysis', 'agency_dap');
$block6 = _block_get_renderable_array(_block_render_blocks(array($blockObject6)));
$output6 = drupal_render($block6);
print "$output6 <br><span class='col-xs-12 clearfix text-center' style='color: " . dotgov_common_getChartColor($agency_dap_score) . ";font-size: 12px;font-style: italic;'>Above graph represents a monthly DAP Trend</span>";
?></div>

                                            </div>


                                        </div>


                                    </div>
                                    <div class="view-button">
                                        <div class="row text-center">
                                            <a class="" title="link for DAP Trend full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                            <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-xs-12 col-lg-4">
                        <div class="white-back">
                            <div class="panel-pane pane-views pane-website-information">
                            <div class="col-xs-10 nopadding">
                        <h2 class="pane-title">Free of Insecure Protocols Information</h2>
                     </div>
                     <div class="col-xs-2 nopadding">
                        <div id="tooltip8" class="infor"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">
                           <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
                           Free of RC4/3DES and SSLv2/SSLv3 Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate();?></span>
                        </div>
                     </div>
                     <br clear="all" />
                     <div class="pane-content clearfix">
                        <div class="view-wrapper">
                           <div class="grey-gradient clearfix">
                              <div class="col-xs-12 clearfix">
                                <h5>Free of RC4/3DES and SSLv2/SSLv3 score breakdown</h5></div>
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
                                                </script>
                                            </div>
                                                </div>
                                            <table width="100%" aria-label="Free of RC4/3DES and SSLv2/SSLv3 score breakdown Table">

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
                                                <tr>
                                                   <td>Total</td>
                                                   <td><span style="font-weight:bold;"><?=$agencydata['insec_compliant'] + $agencydata['insec_noncompliant'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
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
                                    <div class="row text-center">
                                        <a class="" title="link for Insecure Protocol Trend full report" href="/website/all/reports-new?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"/></a>
                                        <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a>
                                    </div>



                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="col-xs-12 col-lg-4">
                        <div class="white-back">
                            <div class="panel-pane pane-views pane-website-information">
                                <div class="col-xs-10 nopadding">
                                    <h2 class="pane-title">USWDS Code</h2>
                                </div>
                                <div class="col-xs-2 nopadding">
                        <div id="tooltip3" class="infor">
                           <a href="https://github.com/18F/site-scanning-documentation/blob/master/scans/uswds.md"><img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon"> </a><span class="ext" aria-label="(link is external)"></span>
                        </div>
                     </div>
                     <br clear="all"/>
                     <div class="pane-content clearfix">
                        <div class="view-wrapper">
                           <div class="view-content">
                              <div class="field-content col-lg-12 nopadding">
                                 <div class="grey-gradient clearfix">
                                 <div class="col-xs-12" style="min-height:89px;">
                                       <h5>USWDS Code Usage</h5>
                                       <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12 nopadding">
                                          <p>The USWDS scan checks each domain for the use of U.S. Web Design System (USWDS) code and the code version.</p>
                                       </div>
                                                </div>
                                                <div style="display:block; float:left;max-height:145px; width:100%;">
                                    <div class="col-xs-6 col-sm-6 col-lg-6" style="margin-top: 30px;">

                                        <ul class="uswds nopadding" style="font-size:12px; line-height: 16px;">
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
                                                            // legend:{position:'left',alignment:'center'}
                                                        };

                                                        var chart = new google.visualization.PieChart(document.getElementById('piechartLast'));

                                                        chart.draw(data, options);

                                                    }
                                                </script>
                                            </div>

                                                <table style="width:100%;" aria-label="USWDS Code Table">

                                                    <th style="background-color: #215393;color: white;border: 1px;"> Breakdown </th>
                                                    <th style="background-color: #215393;color: white;border: 1px;"> Websites </th>
                                                    <tr>
                                                        <td> Websites with USWDS code detected<font style="font-size: larger;font-color:blue;"></font></td>
                                                        <td><?=dotgov_common_getColor($agencydata['uswds_compliant'], '#66746a', $uswds_arr[0])?></td>
                                                    </tr>
                                                    <tr>
                                                        <td>Websites without USWDS code detected<font style="font-size: larger;font-color:blue;"></font></td>
                                                        <td><?=dotgov_common_getColor($agencydata['uswds_noncompliant'], '#8ac99c', $uswds_arr[1])?></td>
                                                    </tr>
                                                    <tr>
                                                       <td>Total</td>
                                                       <td><span style="font-weight:bold;"><?=$agencydata['uswds_compliant'] + $agencydata['uswds_noncompliant'];?> (100 %) <a style="position: absolute;" data-toggle="tooltip" title="Percentages may not total 100 due to rounding.">*</a></span></td>
                                                    </tr>
                                                </table>
                                                <div class="col-xs-12 clearfix">
                                                    <span class="text-center col-xs-12" style="font-size:10px;">(Note: website redirects are excluded)</span> </div>
                                            </div>
                                        </div>

                                    </div>

                                </div>
                            </div>
                        </div>
                        <div class="view-button">
                                        <div class="row text-center">
                                          <a class="" title="link for USWDS Code Usage full report" href="/website/all/uswds?field_web_agency_id_nid=<?=arg(1)?>"><img src="/sites/all/themes/dotgov/images/DD-btn_full_report.png" width="" height="25" alt="image-for-link"></a>
                                          <a title="link for learn more" href="https://designsystem.digital.gov/maturity-model/" target="_blank" rel="noopener noreferrer"><img src="/sites/all/themes/dotgov/images/DD-btn_learn-more1.png" width="" height="25" alt="image-for-link"></a>
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
                          <div class="panel-pane pane-views pane-website-information" style="">
                              <h2 class="pane-title"> Popular Technologies </h2>
                              <div class="pane-content">
                                  <div class="view  view-display-id-block_8 view-dom-id-b6c9491539ed2fa13d8d26fb2e0fc9c7">
                                      <div class="view-content">
                                          <div class="views-row views-row-1 views-row-odd views-row-first views-row-last row clearfix">
                                              <div class="views-field views-field-nothing">
                                                  <div class="view-wrapper" style="">
                                                      <div class="field-content col-lg-12">
                                                          <?php
$message = "Below are the most popular technology stacks used in ";
$no_data = 1;
if ($agencydata['ag_webserver'] != '') {
    if ($no_data == 1) {
        $no_data = 0;
        print "<p>" . $message . $agencynode->title . ".</p>";
    }
    print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Web Server :";
    foreach ($agencydata['ag_webserver'] as $akey => $aval) {
        print "$akey($aval) ";
    }
    print "</span></div>";
}
if ($agencydata['ag_proglang'] != '') {
    if ($no_data == 1) {
        $no_data = 0;
        print "<p>" . $message . $agencynode->title . ".</p>";
    }
    print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Languages :";
    foreach ($agencydata['ag_proglang'] as $akey => $aval) {
        print "$akey($aval) ";
    }
    print "</span></div>";
}

if ($agencydata['ag_cms'] != '') {
    if ($no_data == 1) {
        $no_data = 0;
        print "<p>" . $message . $agencynode->title . ".</p>";
    }
    print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">CMS :";
    foreach ($agencydata['ag_cms'] as $akey => $aval) {
        print "$akey($aval) ";
    }
    print "</span></div>";
}

if ($agencydata['ag_os'] != '') {
    if ($no_data == 1) {
        $no_data = 0;
        print "<p>" . $message . $agencynode->title . ".</p>";
    }
    print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">Operating Systems :";
    foreach ($agencydata['ag_os'] as $akey => $aval) {
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

if ($agencydata['ag_cdn'] != '') {
    if ($no_data == 1) {
        $no_data = 0;
        print "<p>" . $message . $agencynode->title . ".</p>";
    }
    print "<div class=\"col-sm-12 nopadding dataset-resources\"><span id=\"app-button\" class=\"app-button\">CDN :";
    foreach ($agencydata['ag_cdn'] as $akey => $aval) {
        print "$akey($aval) ";
    }
    print "</span></div>";
}

if ($no_data == 1) {
    print "<div><span style='font-size: 12px;font-style: italic;color: darkred;'>Data is not currently available.</span></div>";
}
?>
                                                      </div>
                                                  </div>
                                                  <div class="view-button">

                                                      <div class="row col-xs-12 nopadding">
                                                          <div class="col-xs-12 col-lg-6 text-left" style="visibility: hidden"> <a href="/improve-my-score" title="link for improve my score"><img src="/sites/all/themes/dotgov/images/DD-btn_imp_scores.png" width="" height="25" alt="image-for-link"/></a> </div>
                                                      </div></div>
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
        </section>
</div>
</div>
