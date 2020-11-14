<!DOCTYPE html>
<html>

<head>
    <title>Government-Wide Pivot Table</title>
    <meta charset="utf-8" />

    <!-- external libs from cdnjs -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.min.js"></script>
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery-ui.min.js"></script>

    <!-- PivotTable.js libs from ../dist -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/pivot.min.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/pivot.min.css">


    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/custom.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/custom.css">

    <!-- optional: mobile support with jqueryui-touch-punch -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.ui.touch-punch.min.js"></script>

    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
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

    <div class="tableScroll">
        <button id="left"> <img class="scroll" src="/sites/all/modules/custom/dd_accessibility/images/left-arrow.svg" /> </button>
        <button id="right"><img class="scroll" src="/sites/all/modules/custom/dd_accessibility/images/right-arrow.svg" /> </button>
    </div>

<div class="tableHeader">
  <div class="downloadReport">
    <a href="/accessibility/govwide/csvapi" target="_blank">RAW Data Download in CSV</a> &nbsp;|
    <a href="/accessibility/govwide/xlsapi" target="_blank">RAW Data Download in XLS</a>
  </div>

  <div class="filterSection">
      <span class="filterLabel">Agency</span>
      <select class="filterList" id="searchItems">
      </select>
  </div>
</div>
        <div id="output" class="sticky"></div>


        <script type="text/javascript">
            var jsonUrl = "/sites/default/files/accessibility_api/jsonapi.json";
            $(function () {

                var dataClass = $.pivotUtilities.CustomPivotData;
                var renderers = $.pivotUtilities.custom_renderers;
                var extension = new PivotTableExtensions;
                var tabledata;
                var flagVal = 0;
                scrollTable();

                $.getJSON(jsonUrl, function (mps) {
                    tabledata = mps;

                    $("#output").pivotUI(mps, {
                        dataClass: dataClass,
                        cols: ["Website", "Agency"],
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
                            extension.initFixedHeaders($('table.pvtTable'));
                            getFilterList();
                            colTotalLabel();
                        }
                    });

                    setTimeout(function () {
                        let totalRowsLen = $(".pvtTable tbody tr").length;
                        let x = 0;
                        for(let i =0; i< totalRowsLen; i++) {
                            if($(".pvtTable tbody tr.row"+i+"").length === 0) {
                                break;
                            } else {
                                let elmntLength = $(".pvtTable tbody tr.row"+i+"").length;
                                x = x + elmntLength;
                                var elmnt = $(".pvtTable tbody tr").eq(x-1).find("th div").html();
                                $(".pvtTable tbody tr").eq(x-1).find("th div").html("<a target='_blank' class='link' href='#'>" + elmnt + "</a>");
                            }
                        }

                        //getFilterList();

                    }, 500);
                });

                // Change col total Label
                function colTotalLabel() {
                  $( "th.pvtTotalLabel.colTotal .pvtFixedHeader" ).text( "Total Accessibility Issues" );
                }

                // Scroll Table
                function scrollTable() {
                    // scroll Right
                    $("#right").click(function () {
                        $('.pvtTableWrapper').animate({
                            scrollLeft: "+=400px"
                        }, "slow");
                    });

                    // scroll Left
                    $("#left").click(function () {
                        $('.pvtTableWrapper').animate({
                            scrollLeft: "-=400px"
                        }, "slow");
                    });
                }


                // to do fontResize
                function fontResize() {
                    $("#f-increase").click(function () {
                        var fontSize = parseInt($(this).css("font-size"));
                        fontSize = fontSize + 2 + "px";
                        $('table.pvtTable tbody tr th, table.pvtTable thead tr th, .pvtVal').css({ 'font-size': fontSize });

                    });


                    $("#f-reset").click(function () {
                        var fontSize = parseInt($(this).css("font-size"));
                        fontSize = "12px";
                        $('table.pvtTable tbody tr th, table.pvtTable thead tr th, .pvtVal').css({ 'font-size': fontSize });

                    });
                }

                // To do
                function loadAlert() {
                    $(".pvtHorizList > .axis_1.ui-sortable-handle").click(function () {
                        $(".pvtUi tbody tr:nth-child(2) td:first-child, .pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
                        $(".pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
                    });
                }

                // Filter by Agency or Website
                function getFilterList() {
                    $.getJSON(jsonUrl, function (mps) {
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
                                $('#searchItems').append(option);
                            }
                        }
                    });

                    if(flagVal === 0)  {
                        $('#searchItems').prepend('<option value="">-Any-</option>');
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
