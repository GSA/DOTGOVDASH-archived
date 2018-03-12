<?php
include_once("../scripts/commonScanFunctions.php");

 $query = db_query("select b.nid,b.title,a.field_technology_scan_raw_value from field_data_field_technology_scan_raw a , node b where b.nid=a.entity_id and b.status='1' and b.nid='13'");

 foreach ($query as $result) {
    print $result->nid."--".$result->field_technology_scan_raw_value."\n";
     $rawval = $result->field_technology_scan_raw_value;
         $nid = $result->nid;
             $website = $result->title;
     updateTechStackInfo1($rawval,$website,$nid);
 }

function updateTechStackInfo1($rawval,$website,$nid){
    //Associate field names with categories of technology
    $varCatassoc = array("cms"=>"field_cms_applications",
        "widgets"=>"field_widget_applications",
        "analytics"=>"field_analytics_applications",
        "font scripts"=>"field_font_script_applications",
        "web servers"=>"field_web_server",
        "cache tools"=>"field_cache_tools",
        "javascript frameworks"=>"field_javascript_frameworks",
        "programming languages"=>"field_programming_languages",
        "advertising networks"=>"field_advertising_networks",
        "blogs"=>"field_blog_applications",
        "build ci systems"=>"field_build_ci_systems",
        "captchas"=>"field_captcha_applications",
        "cdn"=>"field_cdn_applications",
        "comment systems"=>"field_comment_systems_applicatio",
        "control systems"=>"field_control_systems_applicatio",
        "crm"=>"field_crm_applications",
        "database managers"=>"field_database_managers",
        "databases"=>"field_databases",
        "dev tools"=>"field_dev_tools",
        "document management systems"=>"field_document_management_system",
        "documentation tools"=>"field_documentation_tools",
        "ecommerce"=>"field_ecommerce_applications",
        "editors"=>"field_editor_applications",
        "feed readers"=>"field_feed_readers",
        "hosting panels"=>"field_hosting_panels",
        "issue trackers"=>"field_issue_trackers",
        "javascript graphics"=>"field_javascript_graphics_applic",
        "landing page builders"=>"field_landing_page_builders",
        "live chat"=>"field_live_chat_applications",
        "lms"=>"field_lms_applications",
        "maps"=>"field_maps_applications",
        "marketing automation"=>"field_marketing_automation",
        "media servers"=>"field_media_servers",
        "message boards"=>"field_message_boards",
        "miscellaneous"=>"field_miscellaneous_application",
        "mobile frameworks"=>"field_mobile_frameworks",
        "network devices"=>"field_network_devices",
        "network storage"=>"field_network_storage",
        "operating systems"=>"field_operating_systems",
        "payment processors"=>"field_payment_processors",
        "photo galleries"=>"field_photo_galleries",
        "remote access"=>"field_remote_access",
        "rich text editors"=>"field_rich_text_editors",
        "search engines"=>"field_search_engines",
        "tag managers"=>"field_tag_managers",
        "video players"=>"field_video_players",
        "web frameworks"=>"field_web_frameworks",
        "web mail"=>"field_web_mail_applications",
        "web server extensions"=>"field_web_server_extensions",
        "wikis"=>"field_wiki_applications");

    $tsobj = json_decode($rawval);
    $tags = array();
    $k = 1;
    //foreach($tsobj->applications as $tskey=>$tsobj){
    foreach($tsobj as $tskey=>$tsobj){
        $tsAppname = $tsobj->name;
        //$tsAppCat = $tsobj->categories[0];
        $tsAppCat1 = (Array)$tsobj->categories[0];
        $tsAppCat = array_values($tsAppCat1)[0];

        //$tags[$tsAppCat] = array();
        //if version is present append version to technology

        if(trim($tsobj->version) != '') {
            $tsAppname .= "_" . $tsobj->version;
            //if (!in_array($tsAppname, $tags[$tsAppCat]))
            $tags[strtolower($tsAppCat)][] = $tsAppname;
        }

        $tags[strtolower($tsAppCat)][] = $tsobj->name;
    }
    //print_r($tags);
    $webnode = node_load($nid);
    $webnode->field_technology_scan_raw['und'][0]['value'] = $rawval;
    $cdnproviders = findCDNProvider("$website");
    foreach($varCatassoc as $vkey=>$vval){
        $webnode->{$vval} = array();
        //print "$vkey -- $vval \n";
    }
    if(!empty($cdnproviders)){
        $tags['cdn'] = array_values($cdnproviders);
    }
    print_r($tags);
    foreach ($tags as $key => $tagarr) {
        $i = 0;
        foreach ($tagarr as $tkey => $tag) {
            if(array_key_exists($key,$varCatassoc)){
                //Check if term exists
                if ($term = taxonomy_get_term_by_name($tag)) {
                    $terms_array = array_keys($term);

                    $webnode->{$varCatassoc["$key"]}['und'][$i]['tid'] = $terms_array['0'];

                } else {
                    //Create a new term and assign
                    $term = new STDClass();
                    $term->name = $tag;
                    $term->vid = 2;
                    if (!empty($term->name)) {
                        taxonomy_term_save($term);
                        $webnode->{$varCatassoc["$key"]}['und'][$i]['tid'] = $term->tid;
                    }
                }

            }
            $i += 1;
        }

    }
    //print_r($webnode->field_analytics_applications);
    node_object_prepare($webnode);
    if ($webnode = node_submit($webnode)) {
        node_save($webnode);
    }
}

?>