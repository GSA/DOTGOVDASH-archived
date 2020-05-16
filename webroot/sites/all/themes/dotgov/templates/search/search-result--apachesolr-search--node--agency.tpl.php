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
    $websiteurl = "/website/".$result['node']->entity_id."/information";	
//if(arg(1) == "website_search") {
if($result['node']->bundle == 'website'){
    $techterms = dotgov_commmon_get_techTerms($result['node']->entity_id);
    //print "<pre>";
    //print_r($techterms);
    $webScanIds = dotgov_common_siteAsocScanids($result['node']->entity_id);
    $taxoTerms = dotgov_common_getNodeTaxonomy($result['node']->entity_id);
    $httpnode = node_load($webScanIds['domain_scan_information']);
    $ip = $httpnode->field_ip_address['und']['0']['value'];
    $ip = str_replace(",",",&nbsp;",$ip);
    ($ip == '')?$ip='N/A':$ip=$ip;
    $dns = $httpnode->field_dns_names['und']['0']['value'];
    ($dns == '')?$dns='N/A':$dns=$dns;
    $commonname = $httpnode->field_dom_common_name['und']['0']['value'];
    ($commonname == '')?$commonname='N/A':$commonname=$commonname;
    $san = $httpnode->field_subject_alternative_name['und']['0']['value'];
    ($san == '')?$san='N/A':$san=$san;
    $ssl_from = $httpnode->field_ssl_certificate_valid_from['und']['0']['value'];
    ($ssl_from == '')?$ssl_from='N/A':$ssl_from=$ssl_from;
    $ssl_to = $httpnode->field_ssl_certificate_expiry['und']['0']['value'];
    ($ssl_to == '')?$ssl_to='N/A':$ssl_to=$ssl_to;
    $ssl_stat = $httpnode->field_ssl_certificate_status['und']['0']['value'];
    ($ssl_stat == '')?$ssl_stat='N/A':$ssl_stat=$ssl_stat;
    $ssl_chain = $httpnode->field_ssl_certificate_chain['und']['0']['value'];
    ($ssl_chain == '')?$ssl_chain='N/A':$ssl_chain=$ssl_chain;
    $ssl_prov = $httpnode->field_certificate_provider['und']['0']['value'];
    ($ssl_prov == '')?$ssl_prov='N/A':$ssl_prov=$ssl_prov;
    $cloud_prov = $httpnode->field_cloud_provider['und']['0']['value'];
    ($cloud_prov == '')?$cloud_prov='N/A':$cloud_prov=$cloud_prov;
    $cdn_prov = $httpnode->field_cdn_provider_name['und']['0']['value'];
    ($cdn_prov == '')?$cdn_prov='N/A':$cdn_prov=$cdn_prov;
    ?>
    <li class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <h3 class="pane-title"<?php print $title_attributes; ?>>
        <a href="<?php print $websiteurl; ?>"><?php print $title; ?></a>
    </h3>
    </li>
         <div class="search-snippet-info">
             <div class="row clearfix">
             <?php
                print "<div class=\"col-lg-6\"><span>IP: $ip</span></div>";
                print "<div class=\"col-lg-6\"><span>DNS: $dns</span></div>";
                print "<div class=\"col-lg-6\">Common Name: $commonname</div>";
                print "<div class=\"col-lg-6\">SAN: $san</div>";
                print "<div class=\"col-lg-6\">Cert Status: $ssl_stat</div>";
                print "<div class=\"col-lg-6\">Cert Valid From: $ssl_from</div>";
                print "<div class=\"col-lg-6\">Cert Valid To: $ssl_to</div>";
                print "<div class=\"col-lg-6\">SSL Chain: $ssl_chain</div>";
                print "<div class=\"col-lg-6\">SSL provider: $ssl_prov</div>";
                print "<div class=\"col-lg-6\">CDN provider: $cloud_prov</div>";
                print "<div class=\"col-lg-6\">Cloud provider: $cdn_prov</div>";
             ?>
             </div>
             <ul class="dataset-resources unstyled">
                 <?php
                 foreach($taxoTerms as $tkey=>$tval) {
			//print "<li> <a class=\"label\" data-format=\"$tval\" href='/search/website_search/%2A?f[0]=im_field_website_tags%3A".$tkey."'>$tval</a></li>";
			print "<li> <span class=\"label\" data-format=\"$tval\">$tval</span></li>";
                 }
             ?>
             </ul>
             <div id="techstack" class="row dataset-resources">
             <?php
//             print "<pre>";
//             print_r($techterms);
             foreach($techterms as $techkey=>$techval) {
                 print "<div class='col-sm-4 nopadding dataset-resources clearfix'><span id='app-button' class='app-button'>".$techval['category']['name']." :&nbsp;<img alt='app-icon' class='app-icon' src='/".drupal_get_path('module', 'dotgov_common')."/images/icons/".$techval['icon']."'>$techkey ".$techval['appversion']."</span></div>";
             }
             ?>
            </div>
         </div>
    <?php
}
else {
//if($result['node']->bundle != 'website')
	$websiteurl = $url;
    ?>
    <li class="<?php print $classes; ?>"<?php print $attributes; ?>>
        <?php print render($title_prefix); ?>
        <h3 class="title"<?php print $title_attributes; ?>>
            <a href="<?php print $websiteurl; ?>"><?php print $title; ?></a>
        </h3>
        <?php print render($title_suffix); ?>
        <div class="search-snippet-info">
	    <div class="row clearfix">	
            <?php if ($snippet): 
                //print "<p class='search-snippet'".$content_attributes.">$snippet</p>";
		 print "<div class=\"col-lg-6\">Record Type: ".$result['node']->bundle_name." </div>";	
		 //print "<div class=\"col-lg-6\">Record Title: ".$result['node']->label." </div>";
		 //print "<div class=\"col-lg-6\">Record Number: ".$result['node']->entity_id." </div>";
		 //print "<div class=\"col-lg-6\">Record Created Date: ".date('m/d/Y h:i:s',$result['node']->created)." </div>";
		 print "<div class=\"col-lg-6\">Last Scan Date: ".date('m/d/Y h:i:s',$result['node']->changed)." </div>";
            endif; ?>
            </div>
        </div>
    </li>
    <?php
}
    ?>

