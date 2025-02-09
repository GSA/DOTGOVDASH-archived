<!DOCTYPE html>
<html>

<head>
    <title>Government-Wide Pivot Table</title>
    <meta charset="utf-8" />

    <!-- external libs from cdnjs -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery-ui.min.js"></script>

    <!-- PivotTable.js libs from ../dist -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/pivot.min.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/pivot.min.css">


    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/custom.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/custom.css">

    <!-- optional: mobile support with jqueryui-touch-punch -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.ui.touch-punch.min.js"></script>

    <style>
        table.pvtTable tbody tr th.pvtRowLabel.rowexpanded {
            cursor: auto !important;
        }

        .link {
            text-decoration: none;
            color: inherit;
        }

        .link:hover {
            text-decoration: underline;
        }

        .tableScroll button {
            border: none;
            background: transparent;
            cursor: pointer;
        }

        #f-increase img {
            width: 30px;
        }

        #f-reset img {
            width: 20px;
        }

        .pvtTableSearchSection {
            display: flex;
        }


    </style>
</head>
<body>

<div class="container-fluid access-table-controls">
    <div class="row">
        <div class="col-xs-12">
            <div class="row">
                <div class="col-md-12" style="display: flex;">
                    <span class="filterLabel">Agency:</span>
                    <select class="filterList" id="filterItems" title="filter-agency" aria-label="select-agency">
                    </select>
                </div>
                <div class="col-xs-12">
                    <p class="or">OR</p>
                </div>
                <div class="col-md-6 search-box">
                    <label class="searchBox searchLabel">Search:
                    <input type="search" class="searchInput searchInputAlter" id="searchInput"></label>
                    <button type="submit" id="resetSearch2" value="Reset" class="btn btn-default resetSearch">Reset</button>
                </div>
                <div class="col-md-6 link-download">    
                    <p>Download Accessibility Reports: <a href="/accessibility/govwide/csvapi" target="_blank"> csv </a> | <a href="/accessibility/govwide/xlsapi" target="_blank">xls</a></p>
                </div>
            </div>
            
        </div>
        <div class="col-xs-12">
            <div class="row">
                <div class="col-md-12 tableScroll">
                    <button id="left"> <img class="scroll" title="scroll-left" src="/sites/all/modules/custom/dd_accessibility/images/left-arrow.svg" /> </button>
                    <button id="right"><img class="scroll" title="scroll-right" src="/sites/all/modules/custom/dd_accessibility/images/right-arrow.svg" /> </button>
                </div>
            </div>
        </div>
    </div>
</div>

        <div id="output" class="sticky gov-my-agency-wide"></div>


        <script type="text/javascript">
            var jsonUrl = "/sites/default/files/accessibility_api/jsonapi.json";
            jQuery(function () {
                var dataClass = jQuery.pivotUtilities.CustomPivotData;
                var renderers = jQuery.pivotUtilities.custom_renderers;
                var extension = new PivotTableExtensions;
                var tabledata;
                var flagVal = 0;
                getFilterList();
                scrollTable();

                jQuery( ".searchInput" ).change(function() {
                    jQuery( ".filterList" ).prop("disabled", true);
                });

                jQuery.getJSON(jsonUrl, function (mps) {
                    tabledata = mps;

                    jQuery("#output").pivotUI(mps, {
                        dataClass: dataClass,
                        cols: ["Website", "Agency"],
                        rows: ["WCAG Success Criteria", "Content Type", "Test Rule"],
                        renderers: renderers,
                        rendererName: "Table With Pagination",
                        rendererOptions: {
                            rowSubtotalDisplay: {
                                disableFrom: 1
                            },
                            colSubtotalDisplay: {
                                disableFrom: 0
                            }

                        },
                        onRefresh: function (pivotUIOptions) {
                            extension.initFixedHeaders(jQuery('table.pvtTable'));
                            colTotalLabel();
                            controlSearch();
                            setTableProperties();
                            setTimeout(function () {
                                settheadariaLabel();
                                ariaLabel();
                            }, 1000);
                        }
                    });


                    function setTableProperties() {
                        // Disable below two lines in UAT
                        jQuery( "<tr style='visibility: hidden;position: absolute;'><th scope='row'>Empty Header</th></tr>" ).insertBefore( jQuery( "table.pvtUi > tbody:first-child > tr:first-child" ) );
                        jQuery( "table.pvtUi > tbody:first-child > tr:nth-child(2)" ).addClass('d-none');
                        // Enable below in QA
                        // jQuery( "<tr style='visibility: hidden;position: absolute;'><th scope='row'>Empty Header</th></tr>" ).insertBefore( jQuery( "table.pvtUi > tr:first-child" ) );
                        // jQuery( "table.pvtUi > tr:nth-child(2)" ).addClass('d-none');
                        jQuery('table.pvtUi').attr('title','Accessibility table renderer');
                        jQuery('table.pvtUi').attr('title','Accessibility table renderer');
                        jQuery(".pvtRenderer, .pvtAggregator").attr({
                            title: 'filte-table',
                            'aria-label': "select-filter"});

                        jQuery('table.pvtTable').attr('title','Government Wide Accessibility table');
                    }

                    setTimeout(function () {
                
                        let totalRowsLen = jQuery(".pvtTable tbody tr").length;
                        let x = 0;
                        for(let i =0; i< totalRowsLen; i++) {
                            if(jQuery(".pvtTable tbody tr.row"+i+"").length === 0) {
                                break;
                            } else {
                                let elmntLength = jQuery(".pvtTable tbody tr.row"+i+"").length;
                                x = x + elmntLength;
                                var elmnt = jQuery(".pvtTable tbody tr").eq(x-1).find("th div").html();
                               // jQuery(".pvtTable tbody tr").eq(x-1).find("th div").html("<a target='_blank' class='link' href='#'>" + elmnt + "</a>");
                            }
                        }

                        //getFilterList();

                    }, 500);
                });

                // Change col total Label
                function colTotalLabel() {
                  jQuery( "th.pvtTotalLabel.colTotal .pvtFixedHeader" ).text( "Total Accessibility Issues" );
                }

                // Set Table header aria Attr 
                function settheadariaLabel() {
                    let totalTr = jQuery('#pvtTable thead tr').length;
                    for(let i=0; i<totalTr; i++) {
                        let totalTheads = jQuery('#pvtTable thead tr').eq(i).find("th").length;
                        for(let j =0; j<totalTheads; j++) {                            
                            if( jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).hasClass("expanded") ||
                               jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).hasClass("rowexpanded")) {
                                jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).find("div").attr("aria-label", "rowexpanded");
                            } 
                            console.log(jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).hasClass('rowcollapsed'));                            

                            if(jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).hasClass('collapsed') ||
                               jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).hasClass('rowcollapsed')) {
                                jQuery('#pvtTable thead tr').eq(i).find("th").eq(j).find("div").attr("aria-label", "rowcollapsed");

                            } 
                        }                       
                    }                    
                }

                // Aria-label 
                function ariaLabel() {
                    let totalTr = jQuery('#pvtTable tbody tr').length;
                    for(let i=0; i<totalTr; i++) {
                        let totalTheads = jQuery('#pvtTable tbody tr').eq(i).find("th").length;
                        for(let j =0; j<totalTheads; j++) {                            
                            if( jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).hasClass("expanded") ||
                               jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).hasClass("rowexpanded")) {
                                jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).find("div").attr("aria-label", "rowexpanded");
                            } 

                            if(jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).hasClass('collapsed') ||
                               jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).hasClass('rowcollapsed')) {
                                jQuery('#pvtTable tbody tr').eq(i).find("th").eq(j).find("div").attr("aria-label", "rowcollapsed");

                            } 
                        }                       
                    }                    
                }

                // toggle search and Filter actions
                function controlSearch() {
                  jQuery( "#filterItems" ).change(function() {
                    jQuery( "#searchInput" ).prop("disabled", true)
                    jQuery("#searchInput").css("cursor", "not-allowed");
                    jQuery("#searchInput").css("opacity", "0.5");
                  });

                  jQuery( "#searchInput" ).change(function() {
                    jQuery( "#filterItems" ).prop("disabled", true)
                    jQuery( "#filterItems" ).css("cursor", "not-allowed");
                  });
                }
                // Scroll Table
                function scrollTable() {
                    // scroll Right
                    jQuery("#right").click(function () {
                        jQuery('.pvtTableWrapper').animate({
                            scrollLeft: "+=400px"
                        }, "slow");
                    });

                    // scroll Left
                    jQuery("#left").click(function () {
                        jQuery('.pvtTableWrapper').animate({
                            scrollLeft: "-=400px"
                        }, "slow");
                    });
                }


                // to do fontResize
                function fontResize() {
                    jQuery("#f-increase").click(function () {
                        var fontSize = parseInt(jQuery(this).css("font-size"));
                        fontSize = fontSize + 2 + "px";
                        jQuery('table.pvtTable tbody tr th, table.pvtTable thead tr th, .pvtVal').css({ 'font-size': fontSize });

                    });


                    jQuery("#f-reset").click(function () {
                        var fontSize = parseInt(jQuery(this).css("font-size"));
                        fontSize = "12px";
                        jQuery('table.pvtTable tbody tr th, table.pvtTable thead tr th, .pvtVal').css({ 'font-size': fontSize });

                    });
                }

                // To do
                function loadAlert() {
                    jQuery(".pvtHorizList > .axis_1.ui-sortable-handle").click(function () {
                        jQuery(".pvtUi tbody tr:nth-child(2) td:first-child, .pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
                        jQuery(".pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
                    });
                }

                // Filter by Agency or Website
                function getFilterList() {
                    jQuery.getJSON(jsonUrl, function(mps) {
                        tableData = mps;
                        var lookup = {};
                        var items = tableData;
                        var result = [];
                        for (var item, i = 0; item = items[i++];) {
                            var name = item["Agency"];
                           
                            if (!(name in lookup)) {
                                lookup[name] = 1;
                                if(name) {
                                    result.push(name);
                                }                               
                            }
                        }

                        var fResult = result.sort(function (n1,n2) {
                            return (n1.toLowerCase() > n2.toLowerCase()) ? 1 : -1;
                        });

                        jQuery('#filterItems').append(
                            jQuery.map(fResult, function(v,k){
                                return jQuery("<option>").val(v).text(v);
                            })
                        );
                    });

                    if(flagVal === 0)  {
                        jQuery('#filterItems').prepend('<option value="">- Any -</option>');
                        flagVal++;
                    }
                    settheadariaLabel();
                    ariaLabel();
                }

                function loadClick() {
                    if (tabledata) {
                        var navLinkMap = new Map();
                        for (var i = 0; i < tabledata.length; i++) {
                            if (tabledata[i].redirectedTo) {
                                navLinkMap[tabledata[i].code] = tabledata[i].redirectedTo
                            }
                        }
                    }
                }

            });
        </script>


</body>

</html>
