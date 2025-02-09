<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<style>
  .page-break-margin {
	  margin-bottom: 6rem !important;
}
  </style>
<script src="/sites/all/themes/dotgov/js/html2pdf.bundle.min.js"></script>
<script type="text/javascript">
    function generatePDF(fileName, pageWidth, pageHeight, websiteInfoPage) {
      jQuery("body").addClass("loading");
      jQuery(".html2pdf__page-break").addClass("page-break-margin");

      if(websiteInfoPage) {
          jQuery( "#techstack" ).addClass( "split-column" );
      }
      var element = document.getElementById("main-container");
      // if width is less than than 768 px
      if (jQuery(window).width() < 768) {   
        jQuery("#desktop-break").removeClass(".html2pdf__page-break");
        html2pdf()
        .set({
            filename: fileName + '.pdf',
            image: {type: 'jpeg', quality: 1},
            html2canvas: {scale: 1, scrollX: 0, scrollY: 0, width: 1500 },
            pagebreak: { before: '#mobile-break', avoid: 'canvas' },
            jsPDF: {format:[400,900]},
        })
        .from(element)
        .save().then(function () {
          jQuery("#desktop-break").addClass(".html2pdf__page-break");
          jQuery( "#techstack" ).removeClass( "split-column" );
          jQuery("body").removeClass("loading");
          });
      } else {
        // if width is more than 768 px
        html2pdf()
          .set({
              filename: fileName + '.pdf',
              jsPDF: {format:[pageWidth,pageHeight]},
          })
          .from(element)
          .save().then(function () {
            jQuery( "#techstack" ).removeClass( "split-column" );
            jQuery("body").removeClass("loading");
            jQuery(".html2pdf__page-break").removeClass("page-break-margin");
          
            });
      }
    
    }
</script>
<div class="top-bar">
			<!-- top header-->
			<div class="container-fluid">
				<div class="row">
					<div class="col-xs-7 col-md-7 contacts col">
						<span class="item">An Official Website Of The United States Government</span> </div>
<div class="col-xs-5 col-md-5 contacts col" style="text-align:right;font-weight:bold;">
						<span>This site is currently in <a href="//18f.gsa.gov/dashboard/stages/#beta">beta</a></span> </div>
				</div>
			</div>
		</div>
  <div class="<?php print $container_class; ?>">
    <div class="row">
      <div class="col-sm-7">
    <div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="Digital Dashboard.gov - Home">
<h1 class="site-logo">Digital Dashboard</h1>
          <img src="<?php print $logo; ?>" alt="Digital Dashboard.gov - Home" />
        </a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
        <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>


    </div>

      </div>
      <div class="col-sm-5">

    <div class="header_block row">
      <div class="col-xs-12 pull-right">
      <?php if (!empty($secondary_nav)): ?>
        <?php print render($secondary_nav); ?>
      <?php endif; ?>
      </div>
      <div class="col-xs-12">
      <?php if (!empty($page['navigation'])): ?>
        <?php print render($page['navigation']); ?>
      <?php endif; ?>
      </div>
    </div>
      </div>
    </div>
</div>
<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">

        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
          <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      <?php endif; ?>
    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse" id="navbar-collapse">
        <nav role="navigation">
<h2 id="mainmenulabel" class="sr-only">Main Menu</h2>
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
                  </nav>
      </div>
    <?php endif; ?>

</header>


<div class="full full-banner">
<div class="col-sm-12">
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>

     <div class="container-fluid">
                        <h1  class="srt-blue">DIGITALDASHBOARD.GOV</h1>
                        <h2  class="srt-blue">
Helping Federal Agencies Do Digital Better			</h2>
                    </div>
    </div>
</div>
<div class="main-container <?php print $container_class; ?>" id="main-container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <!-- avoid breadcrump when pdf conversion in action -->
      <div id="element-to-hide" data-html2canvas-ignore="true"><?php if (!empty($breadcrumb)): print $breadcrumb; endif;?></div>
      <div id="main-content"></div>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<?php if (!empty($page['footer'])): ?>

  <footer class="footer <?php print $container_class; ?>">
    <?php print render($page['footer']); ?>
  </footer>

<?php endif; ?>
<script language="javascript" id="_fed_an_ua_tag" src="https://dap.digitalgov.gov/Universal-Federated-Analytics-Min.js?agency=GSA"></script>
