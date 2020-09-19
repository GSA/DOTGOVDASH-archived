/**
 * @file
 * Global utilities.
 *
 */
(function($, Drupal) {

    'use strict';
  
jQuery(document).ready(function ($) {

    $("#btn-explore").click(function(){
        var btn_text = $(this).text();
        if (btn_text == 'Explore All') {
          $(this).html("Collapse All");
          $( ".row2").fadeIn(3000);

        }
        else {
          $(this).html("Explore All");
          $( ".row2").fadeOut(2000);
        }
    });

    $('#tooltip-container [data-toggle="tooltip"]').tooltip({
        animated: 'fade',
        placement: 'left',
        html: true,
        background: '#000'
    });

    $('table').find("th").each(function (i) {
        $('table td:nth-child(' + (i + 1) + ')').prepend('<span class="table-responsive-stack-thead">'+ $(this).text() + ':</span> ');
        $('.table-responsive-stack-thead').hide();
    });

    $( 'table' ).each(function() {
        var thCount = $(this).find("th").length;
        var rowGrow = 100 / thCount + '%';
        //console.log(rowGrow);
        $(this).find("th, td").css('flex-basis', rowGrow);
    });

    // function flexTable(){
    //     if ($(window).width() < 768) {
    //         $("table").each(function (i) {
    //             $(this).find(".table-responsive-stack-thead").show();
    //             $(this).find('thead').hide();
    //         });
    //     } else {
    //         $("table").each(function (i) {
    //             $(this).find(".table-responsive-stack-thead").hide();
    //             $(this).find('thead').show();
    //         });
    //     }
    //     // flextable
    // }
    
    // flexTable();
    
    // window.onresize = function(event) {
    //     flexTable();
    // };

});

})(jQuery, Drupal);
  