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

    function flexTable(){
        if ($(window).width() < 768) {
            $("table").each(function (i) {
                $(this).find(".table-responsive-stack-thead").show();
                $(this).find('thead').hide();
            });
            // window is less than 768px
        } else {
            $("table").each(function (i) {
                $(this).find(".table-responsive-stack-thead").hide();
                $(this).find('thead').show();
            });
        }
        // flextable
    }
    
    flexTable();
    
    window.onresize = function(event) {
        flexTable();
    };

});

// jQuery Knob
jQuery(function($) {

    $(".alternate-chart").knob({
        change : function (value) {
        },
        'fgColor': '#538200',
        'width' : 250,
        'height' : 300,
        release : function (value) {
            console.log("release : " + value);
        },
        cancel : function () {
            console.log("cancel : ", this);
        },
        format : function (value) {
            return  '0%';
        },
        draw : function () {

            // "tron" case
            if(this.$.data('skin') == 'tron') {

                this.cursorExt = 0.3;

                var a = this.arc(this.cv)  // Arc
                    , pa                   // Previous arc
                    , r = 1;

                this.g.lineWidth = this.lineWidth;

                if (this.o.displayPrevious) {
                    pa = this.arc(this.v);
                    this.g.beginPath();
                    this.g.strokeStyle = this.pColor;
                    this.g.arc(this.xy, this.xy, this.radius - this.lineWidth, pa.s, pa.e, pa.d);
                    this.g.stroke();
                }

                this.g.beginPath();
                this.g.strokeStyle = r ? this.o.fgColor : this.fgColor ;
                this.g.arc(this.xy, this.xy, this.radius - this.lineWidth, a.s, a.e, a.d);
                this.g.stroke();

                this.g.lineWidth = 2;
                this.g.beginPath();
                this.g.strokeStyle = this.o.fgColor;
                this.g.arc( this.xy, this.xy, this.radius - this.lineWidth + 1 + this.lineWidth * 2 / 3, 0, 2 * Math.PI, false);
                this.g.stroke();

                return false;
            }
        }
    });

    $("input.infinite").knob(
                        {
                        min : 0
                        , max : 20
                        , stopper : false
                        , change : function () {
                                        if(v > this.cv){
                                            if(up){
                                                decr();
                                                up=0;
                                            }else{up=1;down=0;}
                                        } else {
                                            if(v < this.cv){
                                                if(down){
                                                    incr();
                                                    down=0;
                                                }else{down=1;up=0;}
                                            }
                                        }
                                        v = this.cv;
                                    }
                        });
});
})(jQuery, Drupal);
  