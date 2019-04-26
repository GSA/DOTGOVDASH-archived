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
if ( arg( 1 ) == "website_search" )
	$searchtitle = "Search";
else
	$searchtitle = "Data Discovery";
?>
<div class="top-bar">
	<!-- top header-->
	<div class="container-fluid">
		<div class="row">
			<div class="col-xs-7 col-md-7 contacts col">
				<span class="item">An Official Website Of The United States Government</span> </div>
			<div class="col-xs-5 col-md-5 contacts col" style="text-align:right;font-weight:bold;">
				<span>This site is currently in <a href="//18f.gsa.gov/dashboard/stages/#alpha">alpha</a></span> </div>
		</div>
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
				<a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
					<?php print $site_name; ?>
				</a>
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
				<div class="col-xs-10 pull-right">
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

<div class="main-container <?php print $container_class; ?>">

	<a id="main-content"></a>
	<?php print render($title_prefix); ?>
	<?php if (!empty($title)): ?>
	<h1 class="page-header">
		<?=$searchtitle; ?>
	</h1>
	<?php endif; ?>
	<?php print render($title_suffix); ?>
	<?php if ($searchtitle =="Data Discovery"){ ?>
	<div>
		<p style="text-align:center;margin-bottom:10px;">The data discovery module is currently under development. It is illustrated here to show functionality and intended use. The data presented here should not be used for any reporting or decision making purposes</p>
	</div>
	<?php } ?>
	<div class="search-wrapper">
		<div class="row box-back clearfix">
			<ul class="col-xs-12 col-sm-12 col-lg-2 nav nopadding">
				<li class="col-xs-4 datadisc active nopadding"> <a data-toggle="tab" href="#dd" title="Data Discovery"> <img  alt="Data Discovery" title="Data Discovery" src="/sites/all/themes/dotgov/images/data-discovery-tab.png"/> </a> </li>
				<li class="col-xs-4 popular nopadding"><a data-toggle="tab" href="#popular" title="Popular Reports"><img alt="Popular Reports" title="Popular Reports" src="/sites/all/themes/dotgov/images/reports-tab.png"/></a>
				</li>
				<li class="col-xs-4 fav nopadding"><a data-toggle="tab" href="#fav" title="Saved Searches"><img alt="Saved Searches" title="Saved Searches" src="/sites/all/themes/dotgov/images/bookmark-tab.png"/></a>
				</li>
			</ul>
		</div>
		
		<?php // if (!empty($breadcrumb)): print $breadcrumb; endif;?>
		<div class="row border">

			<?php if (!empty($page['sidebar_first'])): ?>
			<aside class="col-sm-3" role="complementary">
				<?php print render($page['sidebar_first']); ?>
			</aside>
			<!-- /#sidebar-first -->
			<?php endif; ?>

			<section class="col-sm-12">
				<?php if (!empty($page['highlighted'])): ?>
				<div class="highlighted jumbotron">
					<?php print render($page['highlighted']); ?>
				</div>
				<?php endif; ?>

				<?php print $messages; ?>
				<?php if (!empty($tabs)): ?>
				<?php print render($tabs); ?>
				<?php endif; ?>
				<?php if (!empty($page['help'])): ?>
				<?php print render($page['help']); ?>
				<?php endif; ?>
				<?php if (!empty($action_links)): ?>
				<ul class="action-links">
					<?php print render($action_links); ?>
				</ul>
				<?php endif; ?>
				<div class="tab-content">

					<div id="dd" class="tab-pane fade in active">
<div class="heading clearfix">
			<h2><img class="perform-disc" alt="Perform Data Discovery" title="Perform Data Discovery" src="/sites/all/themes/dotgov/images/perform-disc.png" style="width:28px;margin-right:10px;">Perform Data Discovery</h2>
		</div>
		<hr>
						<div class="panel panel-search">
							<div class="panel-heading" role="tab" id="headingOne">
								<h4 class="panel-title"><span>1</span> <a role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseOne" aria-expanded="true" aria-controls="collapseOne"> Enter Search Terms (Optional) </a> </h4>
							</div>
							<div id="collapseOne" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingOne">
								<div class="panel-body">
<div class="col-lg-6 col-sm-12">
	<?php
	$params = drupal_get_query_parameters();
	//print arg(1)."**";
	$link = url('/search/site/', array('query' => $params));
	//print $link;
	?>
	<form class="search-form" action='/search/site?<?=$_SERVER["QUERY_STRING"]?>' method="get" id="search-form" accept-charset="UTF-8" _lpchecked="1"><div><div class="form-inline form-wrapper form-group" id="edit-basic"><div class="form-item form-item-keys form-type-textfield form-group"> <label class="control-label" for="edit-keys">Enter terms</label>
					<input class="apachesolr-autocomplete form-control form-text ui-autocomplete-input form-autocomplete" data-apachesolr-autocomplete-id="search-form" type="text" id="edit-keys" name="keys" value="" size="20" maxlength="255" autocomplete="off"><span role="status" aria-live="polite" class="ui-helper-hidden-accessible"></span></div>
				</form></div>
		</div>
									<?php //print render($page['content']); ?> </div></div>
							</div>
						</div>




						<aside class="col-sm-12 nopadding" role="complementary" style="margin-bottom:15px;">
							<div class="panel panel-search">
								<div class="panel-heading" role="tab" id="headingTwo">
									<h4 class="panel-title"><span>2</span> <a class="collapsed" role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseTwo" aria-expanded="false" aria-controls="collapseTwo">Select Dimensions </a> </h4>
								</div>
								<div id="collapseTwo" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingTwo">
									<div class="panel-body">
										<?php print render($page['sidebar_second']); ?>

<script language="JavaScript">
function searchsubmit(){
	window.location = '/search/site/'+document.getElementById('edit-keys').value+'?<?=$_SERVER['QUERY_STRING']?>';
}
</script>
										 

</div>

							</div>
						</aside>

<div class="col-sm-12 nopadding">
<div class="panel panel-search">
  <div class="panel-heading" role="tab" id="headingThree">
    <h4 class="panel-title"><span>3</span> <a role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseThree" aria-expanded="true" aria-controls="collapseOne">Make Final Selections and Start Discovering Data! </a> </h4>
  </div>
  <div id="collapseThree" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingThree">
    <div class="panel-body">
      <div class="col-lg-12 col-sm-12">
<h2 class="pane-title" style="margin-top:0;">Filter by Agency:</h2>
		<?php
						$block_ag = module_invoke('panels_mini', 'block_view', 'agencies');
						print $block_ag[ 'content' ];
						?>
	  </div>
      <div class="col-sm-12 text-center">
        <form action='/test?<?=$_SERVER['QUERY_STRING']?>' method="get">
<a href="/multistep-search" class="btn btn-primary" style="margin-right:10px;">Reset</a>

          <input type="button" id="search-submit" name="op" value="Discover" class="btn btn-primary form-submit" onclick="searchsubmit();">
          <span class="sr-only">Discover</span>
          </input>
        </form>
      </div>
    </div>
  </div>
</div>
</div>

						<!-- /#sidebar-second -->
					</div><br clear ="all" />
					<div id="popular" class="tab-pane fade">
<div class="heading clearfix">
			<h2 style="margin-top:-15px;"><img class="perform-disc" alt="Popular Reports" title="Popular Reports" src="/sites/all/themes/dotgov/images/pop_reports.png" style="width:28px;margin-right:10px;">Popular Reports</h2>
		</div>
		<hr>
						<?php
						$block = module_invoke( 'block', 'block_view', '6' );
						print $block[ 'content' ];
						?> </div>
					<div id="fav" class="tab-pane fade">
<div class="heading clearfix">
			<h2 style="margin-top:-15px;"><img class="perform-disc" alt="Saved Searches" title="Saved Searches" src="/sites/all/themes/dotgov/images/saved_search.png" style="width:28px;margin-right:10px;">Saved Searches</h2>
		</div>
		<hr>
						<?php
						$block_fav = module_invoke( 'favorites', 'block_view', '0' );
						print $block_fav[ 'content' ];
						?> </div>
				</div>						
			</section>


		</div>
	</div>
</div>
<div id="bottom-sticky">
	<a class="view_bookmark" title="Add/View Bookmarks">View Bookmarks</a>
</div>
<?php if (!empty($page['footer'])): ?>

<footer class="footer <?php print $container_class; ?>">
	<?php print render($page['footer']); ?>
</footer>

<?php endif; ?>
