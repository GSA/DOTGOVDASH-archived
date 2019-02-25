<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-results.tpl.php. This and the parent template are
 * dependent to one another sharing the markup for definition lists.
 *
 * Available variables:
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result. Does not apply to user searches.
 * - $info: String of all the meta information ready for print. Does not apply
 *   to user searches.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Default keys within $info_split:
 * - $info_split['module']: The module that implemented the search query.
 * - $info_split['user']: Author of the node linked to users profile. Depends
 *   on permission.
 * - $info_split['date']: Last update of the node. Short formatted.
 * - $info_split['comment']: Number of comments output as "% comments", %
 *   being the count. Depends on comment.module.
 *
 * Other variables:
 * - $classes_array: Array of HTML class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $title_attributes_array: Array of HTML attributes for the title. It is
 *   flattened into a string within the variable $title_attributes.
 * - $content_attributes_array: Array of HTML attributes for the content. It is
 *   flattened into a string within the variable $content_attributes.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array does not apply to user searches so it is recommended to check
 * for its existence before printing. The default keys of 'type', 'user' and
 * 'date' always exist for node searches. Modules may provide other data.
 * @code
 *   <?php if (isset($info_split['comment'])): ?>
 *     <span class="info-comment">
 *       <?php print $info_split['comment']; ?>
 *     </span>
 *   <?php endif; ?>
 * @endcode
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess()
 * @see template_preprocess_search_result()
 * @see template_process()
 *
 * @ingroup themeable
 */
$websiteurl = "/website/" . $result[ 'node' ]->entity_id . "/information";
//if(arg(1) == "website_search") {
if ( $result[ 'node' ]->bundle == 'website' ) {
    $mobsnap = dotgov_common_getMobileSnapshot($result[ 'node' ]->entity_id);
    if(file_exists(drupal_realpath($mobsnap['uri'])) && (filesize(drupal_realpath($mobsnap['uri'])) != '0'))
        $imageoutput =  '<img src="'.file_create_url($mobsnap['uri']).'" height="150px" width="182px" title="website-logo" alt="website-logo" />';
    else
        $imageoutput = '&nbsp;';


    $techterms = dotgov_commmon_get_techTerms( $result[ 'node' ]->entity_id );
    //print "<pre>";
    //print_r($techterms);
    $webScanIds = dotgov_common_siteAsocScanids( $result[ 'node' ]->entity_id );
    $taxoTerms = dotgov_common_getNodeTaxonomy( $result[ 'node' ]->entity_id );
    $httpnode = node_load( $webScanIds[ 'domain_scan_information' ] );
    $ip = $httpnode->field_ip_address[ 'und' ][ '0' ][ 'value' ];
    $ip = str_replace( ",", ",&nbsp;", $ip );
    ( $ip == '' ) ? $ip = 'N/A': $ip = $ip;
    $dns = $httpnode->field_dns_names[ 'und' ][ '0' ][ 'value' ];
    ( $dns == '' ) ? $dns = 'N/A': $dns = $dns;
    $commonname = $httpnode->field_dom_common_name[ 'und' ][ '0' ][ 'value' ];
    ( $commonname == '' ) ? $commonname = 'N/A': $commonname = $commonname;
    $san = $httpnode->field_subject_alternative_name[ 'und' ][ '0' ][ 'value' ];
    ( $san == '' ) ? $san = 'N/A': $san = $san;
    $ssl_from = $httpnode->field_ssl_certificate_valid_from[ 'und' ][ '0' ][ 'value' ];
    ( $ssl_from == '' ) ? $ssl_from = 'N/A': $ssl_from = $ssl_from;
    $ssl_to = $httpnode->field_ssl_certificate_expiry[ 'und' ][ '0' ][ 'value' ];
    ( $ssl_to == '' ) ? $ssl_to = 'N/A': $ssl_to = $ssl_to;
    $ssl_stat = $httpnode->field_ssl_certificate_status[ 'und' ][ '0' ][ 'value' ];
    ( $ssl_stat == '' ) ? $ssl_stat = 'N/A': $ssl_stat = $ssl_stat;
    $ssl_chain = $httpnode->field_ssl_certificate_chain[ 'und' ][ '0' ][ 'value' ];
    ( $ssl_chain == '' ) ? $ssl_chain = 'N/A': $ssl_chain = $ssl_chain;
    $ssl_prov = $httpnode->field_certificate_provider[ 'und' ][ '0' ][ 'value' ];
    ( $ssl_prov == '' ) ? $ssl_prov = 'N/A': $ssl_prov = $ssl_prov;
    $cloud_prov = $httpnode->field_cloud_provider[ 'und' ][ '0' ][ 'value' ];
    ( $cloud_prov == '' ) ? $cloud_prov = 'N/A': $cloud_prov = $cloud_prov;
    $cdn_prov = $httpnode->field_cdn_provider_name[ 'und' ][ '0' ][ 'value' ];
    ( $cdn_prov == '' ) ? $cdn_prov = 'N/A': $cdn_prov = $cdn_prov;

    $compliant_taxonomy = array("DAP","Compliant with M-15-13 and BOD 18-01","DNSSEC","FORCE HTTPS","Free of RC4/3DES and SSLv2/SSLv3","HSTS","HTTPS","IPV6","MOBILE","PRELOAD","TLSV1.1","TLSV1.2");
    $noncompliant_taxonomy = array("SSLV2","SSLV3","VULNERABLE","TLSV1");
    $tooltip = array("DAP" => "This site is Digital Analytics Platform Compliant","Compliant with M-15-13 and BOD 18-01" => "This site is Compliant with M-15-13 and BOD 18-01 directives. For more information please visit https://https.cio.gov/ and https://cyber.dhs.gov/directives/","DNSSEC" => "This site is DNSSEC Compliant","FORCE HTTPS"=> "This site is forces https protocol on client browsers","Free of RC4/3DES and SSLv2/SSLv3"=> "This site is free of bad protocols like RC4/3DES and SSLv2/SSLv3","HSTS" => "This Site is HTTP Strict Transport Security compliant","HTTPS" => "This site is HTTPS secure protocol compliant","IPV6" => "This Site is IPv6 Compliant","MOBILE" => "This site is optimized to have a mobile friendly view","PRELOAD" => "This site is in hsts preload list. HSTS Preloading is a mechanism whereby a list of hosts that wish to enforce the use of SSL/TLS on their site is built into a browser. This list is compiled by Google and is utilised by Chrome, Firefox and Safari.","TLSV1.1" => "This site is compliant with TLS 1.1 protocol","TLSV1.2" => "This site is compliant with the latest TLS 1.2 protocol","SSLV2"=> "This site is compliant with old and outdated SSL v2 protocol. This protcol should be immediately disabled on the server.","SSLV3"=> "This site is compliant with old and outdated SSL v3 protocol. This protcol should be immediately disabled on the server.","VULNERABLE"=> "This site is vulnerable to multiple bad protocols like OpenSSL CCS Injection, OpenSSL Heartbleed or Downgrade Attacks","TLSV1"=> "This site is compliant with old and outdated TLS 1.0 protocol. This protcol should be immediately disabled on the server.");
    ?>
    <style>
        .taxotooltip {
            position: relative;
            display: inline-block;
        }

        .taxotooltip .tooltiptext {
            visibility: hidden;
            width: 120px;
            background-color: black;
            color: #fff;
            text-align: center;
            border-radius: 6px;
            padding: 5px 0;
            position: absolute;
            z-index: 1;
            bottom: 150%;
            left: 50%;
            margin-left: -60px;
        }
        .taxotooltip .tooltiptext::after {
            content: "";
            position: absolute;
            top: 100%;
            left: 50%;
            margin-left: -5px;
            border-width: 5px;
            border-style: solid;
            border-color: black transparent transparent transparent;
        }
        .taxotooltip:hover .tooltiptext {
            visibility: visible;
        }
    </style>
    <li class="<?php print $classes; ?>" <?php print $attributes; ?>>

    <div class="col-xs-12 nopadding">
        <div class="col-xs-3">
            <a href="<?php print $websiteurl; ?>"><div class="image-container"><?=$imageoutput?>
            </div></a>
            <?php print render($title_prefix); ?>
            <h4 class="pane-title" <?php print $title_attributes; ?>>
                <a href="<?php print $websiteurl; ?>"><?php print $title; ?></a>
                </h3>

        </div>
        <div class="col-xs-9">
                <?php
                $compliant_text = "";
                $noncompliant_text = "";
                foreach ( $taxoTerms as $tkey => $tval ) {
                    //print "<li> <a class=\"label\" data-format=\"$tval\" href='/search/website_search/%2A?f[0]=im_field_website_tags%3A".$tkey."'>$tval</a></li>";
                    if(in_array($tval,$compliant_taxonomy)) {
                        $compliant_text .= "<div class='taxotooltip'><li> <span class=\"label\" data-format=\"$tval\" style=\"margin-bottom:5px;\">$tval</span><span class=\"tooltiptext\">$tooltip[$tval]</span></li></div>";
                    }
                    elseif(in_array($tval,$noncompliant_taxonomy)) {
                        if($tval == "VULNERABLE"){
                            $tvaltext = "Insecure Protocol";
                        }
                        else{
                            $tvaltext = $tval;
                        }
                        $noncompliant_text .= "<div class='taxotooltip'><li> <span class=\"label\" data-format=\"$tval\" style=\"margin-bottom:5px;\">$tvaltext</span><span class=\"tooltiptext\">$tooltip[$tval]</span></li></div>";
                    }
                }
                ?>
            <div><b>Compliant</b></div>
            <ul class="dataset-resources unstyled">
                <?php if(trim($compliant_text) != '')
                    print $compliant_text;
                else
                    print "NA";
                ?>
            </ul>
                <div><b>Non-Compliant</b></div>
                <ul class="dataset-resources unstyled">
                    <?php if(trim($noncompliant_text) != '')
                        print $noncompliant_text;
                    else
                        print "NA";
                    ?>
                </ul>
            <div><b>Technologies Identified</b></div>
            <div id="techstack" class="row dataset-resources">
                <?php
                if(!empty($techterms)) {
                    foreach ($techterms as $techkey => $techval) {
                        print "<div class='col-sm-4 nopadding dataset-resources clearfix'><span id='app-button' class='app-button'>" . $techval['category']['name'] . " :&nbsp;<img alt='app-icon' class='app-icon' src='/" . drupal_get_path('module', 'dotgov_common') . "/images/icons/" . $techval['icon'] . "'>$techkey " . $techval['appversion'] . "</span></div>";
                    }
                }
                else{
                    print "NA";
                }
                ?>
            </div>

        </div>
    </div>

    <?php
} else {
    //if($result['node']->bundle != 'website')
    $websiteurl = $url;
    ?>
    <li class="<?php print $classes; ?>" <?php print $attributes; ?>>
        <?php print render($title_prefix); ?>
        <h3 class="title" <?php print $title_attributes; ?>>
            <a href="<?php print $websiteurl; ?>"><?php print $title; ?></a>
        </h3>
        <?php print render($title_suffix); ?>
        <div class="search-snippet-info">
            <div class="row clearfix">
                <?php if ($snippet):
                    //print "<p class='search-snippet'".$content_attributes.">$snippet</p>";
                    print "<div class=\"col-lg-6\">Record Type: ".$result['node']->bundle_name." </div>";
                    print "<div class=\"col-lg-6\">Record Title: ".$result['node']->label." </div>";
                    print "<div class=\"col-lg-6\">Record Number: ".$result['node']->entity_id." </div>";
                    print "<div class=\"col-lg-6\">Record Created Date: ".date('m/d/Y h:i:s',$result['node']->created)." </div>";
                    print "<div class=\"col-lg-6\">Record Changed Date: ".date('m/d/Y h:i:s',$result['node']->changed)." </div>";
                endif; ?>
            </div>
        </div>
    </li>
    <?php
}
?>
<br clear="all" /></li><hr>