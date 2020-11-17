<!DOCTYPE html>
<html>

<head>
    <title>Agency-Wide Pivot Table</title>
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

        .tableScroll .scroll {
            width: 30px;
            height: 40px;
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

<div class="tableHeader">
<div class="filterSearch">
  <div class="filterSection">
      <span class="filterLabel">Agency:</span>
      <select class="filterList" id="filterItems">
      </select>
  </div>
  <div class="text">
      <p>Or</p>
  </div>
  <div class="searchSection">
      <span class="searchBox searchLabel">Search:</span>
      <input type="search" class="searchInput searchInputAlter" id="searchInput">
  </div>
  <div class="reset">
    <button type="submit" id="resetSearch2" value="Reset" class="btn btn-default resetSearch">Reset</button>
  </div>
</div>
<div class="downloadReport">
    <p>Download Accessibility Reports: <a href="/accessibility/agencywide/csvapi" target="_blank"> csv </a> | <a href="/accessibility/agencywide/xlsapi" target="_blank">xls</a></p>
</div>
</div>
<div class="tableScroll">
    <button id="left"> <img class="scroll" title="scroll-left" src="/sites/all/modules/custom/dd_accessibility/images/left-arrow.svg" /> </button>
    <button id="right"><img class="scroll" title="scroll-right" src="/sites/all/modules/custom/dd_accessibility/images/right-arrow.svg" /> </button>
</div>


        <div id="output" class="sticky agency-wide"></div>


        <script type="text/javascript">
            var jsonUrl = "/sites/default/files/accessibility_api/jsonapi.json";
            jQuery(function () {

                var dataClass = jQuery.pivotUtilities.CustomPivotData;
                var renderers = jQuery.pivotUtilities.custom_renderers;
                var extension = new PivotTableExtensions;
                var tabledata;
                var flagVal = 0;
                scrollTable();

                jQuery.getJSON(jsonUrl, function (mps) {
                    tabledata = mps;

                    jQuery("#output").pivotUI(mps, {
                        dataClass: dataClass,
                        cols: ["Agency"],
                        rows: ["WCAG Success Criteria", "ICT Group", "Test Rule"],
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
                        onRefresh: function (pivotUIOptions, config) {
                            extension.initFixedHeaders(jQuery('table.pvtTable'));
                            getFilterList();
                            colTotalLabel();
                            controlSearch();
                        }
                    });

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
                                jQuery(".pvtTable tbody tr").eq(x-1).find("th div").html("<a target='_blank' class='link' href='https://www.google.com/'>" + elmnt + "</a>");
                            }
                        }

                        //getFilterList();

                    }, 500);
                });

                // Change col total Label
                function colTotalLabel() {
                  jQuery( "th.pvtTotalLabel.colTotal .pvtFixedHeader" ).text( "Total Accessibility Issues" );
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
                    jQuery.getJSON(jsonUrl, function (mps) {
                        tableData = mps;
                        var lookup = {};
                        var items = tableData;
                        var result = [];
                        for (var item, i = 0; item = items[i++];) {
                            var name = item["Agency"];

                            if (!(name in lookup)) {
                                lookup[name] = 1;
                                result.push(name);
                                Array.prototype.last = function () {
                                    return this[this.length - 1];
                                };
                                //console.log(result.last());
                                var fResult = result.last();
                                var option = '';
                                option += '<option value="' + fResult + '">' + fResult + '</option>';
                                jQuery('#filterItems').append(option);
                            }
                        }
                    });

                    if(flagVal === 0)  {
                        jQuery('#filterItems').prepend('<option value="">-Any-</option>');
                        flagVal ++;
                    }
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
