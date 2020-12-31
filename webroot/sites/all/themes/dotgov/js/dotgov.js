/**
 * @file
 * Global utilities.
 *
 */
(function($, Drupal) {

    'use strict';
jQuery(document).ready(function ($) {
//$('.page-search-site .breadcrumb span:nth-child(3)').html('<a href=/search/site>Data Discovery</a>');
$(".paginate_button ,.paginate_active").attr("role","link");

$('#edit-date-of-scan-min').attr('title','Choose date range');
$( "#favorites-add-favorite-form .panel-body" ).removeClass( "fade collapsed" ).addClass( "in" );
$( "#edit-add-3-body" ).removeClass( "fade collapsed" ).addClass( "in" );

	$(".ui-accordion-content").css("height", "auto");
	$("#favorites-list li").prepend('<i class="icon glyphicon glyphicon-star"></i>');
	$("th").attr("scope", "col");
	$(".Website").text("Websites");
	$(".Agency").text("Agencies");

	/* adding custom toggle js for favorites bookmark show-hide buttom */
	$(".block-favorites").append('<div class="close_bookmark"><a class="bookmark_close"><span><img src="/sites/all/themes/dotgov/images/close-bookmark.png" alt="Close Bookmarks" title="Close Bookmarks" /></span></a></div>');

	$("#addBookmark").click(function () {
		Drupal.favorites.add();
		$(function () {
			$("#infor").show().fadeIn(1000);
			setTimeout(function () {
				$("#infor").show().fadeOut(1000, function () {
					// location.reload(true);
				});
			}, 1000);
		});

	});
	$(".close_bookmark").click(function () {
		$(".block-favorites").toggle();
	});

	$(".favorites-remove").click(function () {
		$("#rmBookmark").show().delay(2000).fadeOut();
	});
	$(".view_bookmark").click(function () {
		$(".block-favorites").toggle();
	});
	$("#addbookmark").click(function () {
		$(".block-favorites").toggle();
	});

	/*setTimeout(function () {
	 $(".view_bookmark").click(function() {
	 $( ".block-favorites" ).toggle();
	 }),2000}); */
	var img_title = $(".page-overall-compliance .view-agency-logo h2").text();
	$(".page-overall-compliance .img-responsive").attr("title", img_title);
	$(".page-overall-compliance .img-responsive").attr("alt", img_title);
	$(".dataTable").addClass("table table-hover table-striped");
	$(".dataTables_wrapper").addClass("table-responsive");
	$('#block-favorites-0 #edit-title').before(function () {
		return $('<label />', {
			for: this.id
		}).text("Add Page").append(this.previousSibling)
	});
	$('.tabledrag-handle').html('<span class="sr-only">Click here to drag the link</span>');
	$(document).ajaxComplete(function () {
		$(".dataTable").addClass("table table-hover table-striped");
		$(".dataTables_wrapper").addClass("table-responsive");
	});

	$(document).ajaxComplete(function () {
		var agencyValue = $("#edit-field-web-agency-id-nid-selective").val();
		//console.log(agencyValue);
		if (agencyValue === "All") {
			$(".panel-accessibility-chart").css("display", "block");
		} else {
			$(".panel-accessibility-chart").css("display", "none");
		}
	});
	setTimeout(function () {

		$('#agency_acc_table_filter .input-sm').keyup(function () {
			if ($(this).val() == '') {
				$('.pane-agency-accessibility').show();
			} else {
				$('.pane-agency-accessibility').hide();
			}
		}), 1000
	});

	$('#agency_acc_table_filter .input-sm').keyup(function () {
		if ($(this).val() == '') {
			$('.panel-accessibility-chart').show();
		} else {
			$('.panel-accessibility-chart').hide();
		}
	});
	$( ".active" ).parents(".collapse").addClass( "in" );
$( ".facetapi-active" ).parents(".collapse").addClass( "in" );

	$( ".facetapi-active" ).parent().css( "background-color","#f1c393" );
});
})(jQuery, Drupal);