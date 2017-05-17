<?php
/**
 * @file
 * views_all.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_all_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'website_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'website information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'website information';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: IP Address */
  $handler->display->display_options['fields']['field_ip_address']['id'] = 'field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['table'] = 'field_data_field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['field'] = 'field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['label'] = 'IP';
  /* Field: Content: DNS Names */
  $handler->display->display_options['fields']['field_dns_names']['id'] = 'field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['table'] = 'field_data_field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['field'] = 'field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['label'] = 'DNS';
  /* Field: Content: CDN Provider name */
  $handler->display->display_options['fields']['field_cdn_provider_name']['id'] = 'field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['table'] = 'field_data_field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['field'] = 'field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['label'] = 'Hosted At';
  /* Field: Content: Cloud Provider */
  $handler->display->display_options['fields']['field_cloud_provider']['id'] = 'field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['table'] = 'field_data_field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['field'] = 'field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['label'] = '';
  $handler->display->display_options['fields']['field_cloud_provider']['element_label_colon'] = FALSE;
  /* Field: Content: Alexa ranking */
  $handler->display->display_options['fields']['field_alexa_ranking']['id'] = 'field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['table'] = 'field_data_field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['field'] = 'field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['label'] = 'Alexa Ranking';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'domain_scan_information' => 'domain_scan_information',
  );

  /* Display: Website Information Page */
  $handler = $view->new_display('page', 'Website Information Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Website Information';
  $handler->display->display_options['display_description'] = 'Website Information Page';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'website_information/%/%/show';

  /* Display: Website Information */
  $handler = $view->new_display('block', 'Website Information', 'block');
  $handler->display->display_options['display_description'] = 'Website Information';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Website Information';

  /* Display: Domain Information */
  $handler = $view->new_display('block', 'Domain Information', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Domain Information';
  $handler->display->display_options['display_description'] = 'Domain Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Common Name */
  $handler->display->display_options['fields']['field_dom_common_name']['id'] = 'field_dom_common_name';
  $handler->display->display_options['fields']['field_dom_common_name']['table'] = 'field_data_field_dom_common_name';
  $handler->display->display_options['fields']['field_dom_common_name']['field'] = 'field_dom_common_name';
  /* Field: Content: Subject Alternative Name */
  $handler->display->display_options['fields']['field_subject_alternative_name']['id'] = 'field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['table'] = 'field_data_field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['field'] = 'field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['label'] = 'SAN';
  /* Field: Content: SSL Certificate Valid from */
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['id'] = 'field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['table'] = 'field_data_field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['field'] = 'field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['label'] = 'Valid From';
  /* Field: Content: SSL Certificate Expiry */
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['id'] = 'field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['table'] = 'field_data_field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['field'] = 'field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['label'] = 'Valid To';
  /* Field: Content: Certificate Issuer */
  $handler->display->display_options['fields']['field_certificate_issuer']['id'] = 'field_certificate_issuer';
  $handler->display->display_options['fields']['field_certificate_issuer']['table'] = 'field_data_field_certificate_issuer';
  $handler->display->display_options['fields']['field_certificate_issuer']['field'] = 'field_certificate_issuer';
  /* Field: Content: Certificate provider */
  $handler->display->display_options['fields']['field_certificate_provider']['id'] = 'field_certificate_provider';
  $handler->display->display_options['fields']['field_certificate_provider']['table'] = 'field_data_field_certificate_provider';
  $handler->display->display_options['fields']['field_certificate_provider']['field'] = 'field_certificate_provider';
  /* Field: Content: SSL Certificate Status */
  $handler->display->display_options['fields']['field_ssl_certificate_status']['id'] = 'field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['table'] = 'field_data_field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['field'] = 'field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['label'] = 'Certificate Status';
  /* Field: Content: SSL Certificate Chain */
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['id'] = 'field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['table'] = 'field_data_field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['field'] = 'field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['label'] = 'Certificate Chain';
  $handler->display->display_options['block_description'] = 'Domain Information';

  /* Display: SSL Information */
  $handler = $view->new_display('block', 'SSL Information', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'SSL Information';
  $handler->display->display_options['display_description'] = 'SSL Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Downgrade Attacks */
  $handler->display->display_options['fields']['field_downgrade_attacks']['id'] = 'field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['table'] = 'field_data_field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['field'] = 'field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['label'] = 'Downgrade Attack';
  /* Field: Content: HTTP Public Key Pinning (HPKP) */
  $handler->display->display_options['fields']['field_http_public_hpkp']['id'] = 'field_http_public_hpkp';
  $handler->display->display_options['fields']['field_http_public_hpkp']['table'] = 'field_data_field_http_public_hpkp';
  $handler->display->display_options['fields']['field_http_public_hpkp']['field'] = 'field_http_public_hpkp';
  /* Field: Content: OpenSSL CCS Injection */
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['id'] = 'field_openssl_ccs_injection';
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['table'] = 'field_data_field_openssl_ccs_injection';
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['field'] = 'field_openssl_ccs_injection';
  /* Field: Content: OpenSSL Heartbleed */
  $handler->display->display_options['fields']['field_openssl_heartbleed']['id'] = 'field_openssl_heartbleed';
  $handler->display->display_options['fields']['field_openssl_heartbleed']['table'] = 'field_data_field_openssl_heartbleed';
  $handler->display->display_options['fields']['field_openssl_heartbleed']['field'] = 'field_openssl_heartbleed';
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  /* Field: Content: SSL V2 Support */
  $handler->display->display_options['fields']['field_ssl_v2_support']['id'] = 'field_ssl_v2_support';
  $handler->display->display_options['fields']['field_ssl_v2_support']['table'] = 'field_data_field_ssl_v2_support';
  $handler->display->display_options['fields']['field_ssl_v2_support']['field'] = 'field_ssl_v2_support';
  /* Field: Content: SSL V3 Support */
  $handler->display->display_options['fields']['field_ssl_v3_support']['id'] = 'field_ssl_v3_support';
  $handler->display->display_options['fields']['field_ssl_v3_support']['table'] = 'field_data_field_ssl_v3_support';
  $handler->display->display_options['fields']['field_ssl_v3_support']['field'] = 'field_ssl_v3_support';
  /* Field: Content: TLS V1 Support */
  $handler->display->display_options['fields']['field_tls_v1_support']['id'] = 'field_tls_v1_support';
  $handler->display->display_options['fields']['field_tls_v1_support']['table'] = 'field_data_field_tls_v1_support';
  $handler->display->display_options['fields']['field_tls_v1_support']['field'] = 'field_tls_v1_support';
  /* Field: Content: TLS V1.1 Support */
  $handler->display->display_options['fields']['field_tls_v1_1_support']['id'] = 'field_tls_v1_1_support';
  $handler->display->display_options['fields']['field_tls_v1_1_support']['table'] = 'field_data_field_tls_v1_1_support';
  $handler->display->display_options['fields']['field_tls_v1_1_support']['field'] = 'field_tls_v1_1_support';
  /* Field: Content: TLS V1.2 Support */
  $handler->display->display_options['fields']['field_tls_v1_2_support']['id'] = 'field_tls_v1_2_support';
  $handler->display->display_options['fields']['field_tls_v1_2_support']['table'] = 'field_data_field_tls_v1_2_support';
  $handler->display->display_options['fields']['field_tls_v1_2_support']['field'] = 'field_tls_v1_2_support';
  $handler->display->display_options['block_description'] = 'SSL Information';

  /* Display: HTTPS Information */
  $handler = $view->new_display('block', 'HTTPS Information', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'HTTPS Information';
  $handler->display->display_options['display_description'] = 'HTTPS Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Enforce HTTPS */
  $handler->display->display_options['fields']['field_enforce_https']['id'] = 'field_enforce_https';
  $handler->display->display_options['fields']['field_enforce_https']['table'] = 'field_data_field_enforce_https';
  $handler->display->display_options['fields']['field_enforce_https']['field'] = 'field_enforce_https';
  /* Field: Content: HSTS Status */
  $handler->display->display_options['fields']['field_hsts_status']['id'] = 'field_hsts_status';
  $handler->display->display_options['fields']['field_hsts_status']['table'] = 'field_data_field_hsts_status';
  $handler->display->display_options['fields']['field_hsts_status']['field'] = 'field_hsts_status';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  /* Field: Content: HTTPS Status */
  $handler->display->display_options['fields']['field_https_status']['id'] = 'field_https_status';
  $handler->display->display_options['fields']['field_https_status']['table'] = 'field_data_field_https_status';
  $handler->display->display_options['fields']['field_https_status']['field'] = 'field_https_status';
  /* Field: Content: Preload Status */
  $handler->display->display_options['fields']['field_preload_status']['id'] = 'field_preload_status';
  $handler->display->display_options['fields']['field_preload_status']['table'] = 'field_data_field_preload_status';
  $handler->display->display_options['fields']['field_preload_status']['field'] = 'field_preload_status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'https_dap_scan_information' => 'https_dap_scan_information',
  );

  /* Display: DAP Information */
  $handler = $view->new_display('block', 'DAP Information', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'DAP Information';
  $handler->display->display_options['display_description'] = 'DAP Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  /* Field: Content: DAP Status */
  $handler->display->display_options['fields']['field_dap_status']['id'] = 'field_dap_status';
  $handler->display->display_options['fields']['field_dap_status']['table'] = 'field_data_field_dap_status';
  $handler->display->display_options['fields']['field_dap_status']['field'] = 'field_dap_status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'https_dap_scan_information' => 'https_dap_scan_information',
  );

  /* Display: Web Agency Information */
  $handler = $view->new_display('block', 'Web Agency Information', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agency Information';
  $handler->display->display_options['display_description'] = 'Web Agency Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Parent Agency */
  $handler->display->display_options['fields']['field_web_parent_agency']['id'] = 'field_web_parent_agency';
  $handler->display->display_options['fields']['field_web_parent_agency']['table'] = 'field_data_field_web_parent_agency';
  $handler->display->display_options['fields']['field_web_parent_agency']['field'] = 'field_web_parent_agency';
  /* Field: Content: Parent Agency Name */
  $handler->display->display_options['fields']['field_parent_agency_name']['id'] = 'field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['table'] = 'field_data_field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['field'] = 'field_parent_agency_name';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'URL';
  /* Field: Content: Agency Logo */
  $handler->display->display_options['fields']['field_agency_logo']['id'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['table'] = 'field_data_field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['field'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_agency_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Agency Logo */
  $handler->display->display_options['fields']['field_agency_logo']['id'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['table'] = 'field_data_field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['field'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['label'] = '';
  $handler->display->display_options['fields']['field_agency_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_agency_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Agency ID (field_web_agency_id) */
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['validate']['type'] = 'node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agency' => 'agency',
  );
  $handler->display->display_options['displays'] = array(
    'block_5' => 'block_5',
    'default' => 0,
    'page' => 0,
    'block' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
  );
  $export['website_information'] = $view;

  return $export;
}
