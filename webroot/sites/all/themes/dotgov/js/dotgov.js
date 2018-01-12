jQuery( document ).ready(function($) {
$( ".ui-accordion-content" ).css( "height", "auto" );
$("#favorites-list li").prepend('<i class="icon glyphicon glyphicon-star"></i>');
$("th").attr("scope","col");
$(".Website").text("Domains");
$(".Agency").text("Agencies");
});

