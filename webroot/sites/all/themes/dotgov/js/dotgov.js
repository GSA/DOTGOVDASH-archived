jQuery( document ).ready(function($) {
    $( ".ui-accordion-content" ).css( "height", "auto" );
    $("#favorites-list li").prepend('<i class="icon glyphicon glyphicon-star"></i>');
    $("th").attr("scope","col");
    $(".Website").text("Domains");
    $(".Agency").text("Agencies");

    /* adding custom toggle js for favorites bookmark show-hide buttom */
    $(".block-favorites").append('<div class="close_bookmark"><a class="bookmark_close"><span><img src="/sites/all/themes/dotgov/images/close-bookmark.png" alt="Close Bookmarks" title="Close Bookmarks" /></span></a></div>');

    $("#addBookmark").click(function() {
        Drupal.favorites.add();
        $(function(){
            $("#infor").show().fadeIn(1000);
            setTimeout(function(){
                $("#infor").show().fadeOut(1000, function(){
                    // location.reload(true);
                });
            }, 1000);
        });

    });
    $(".close_bookmark").click(function() {
        $( ".block-favorites" ).toggle();
    });

    $(".favorites-remove").click(function() {
        $("#rmBookmark").show().delay(2000).fadeOut();
    });
    $(".view_bookmark").click(function() {
        $( ".block-favorites" ).toggle();
    });
    /*setTimeout(function () {
     $(".view_bookmark").click(function() {
     $( ".block-favorites" ).toggle();
     }),2000}); */
var img_title=$(".page-overall-compliance .view-agency-logo h2").text();
$(".page-overall-compliance .img-responsive").attr("title",img_title);
$(".page-overall-compliance .img-responsive").attr("alt",img_title);
$(".dataTable").addClass("table table-hover table-striped");

});
