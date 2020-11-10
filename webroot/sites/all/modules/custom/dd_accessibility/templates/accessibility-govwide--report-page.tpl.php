<!DOCTYPE html>

<!DOCTYPE html>
<html>

<head>
    <title>Customized Pivot Table</title>
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

        .tableScroll {
            float: right;
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

        /* .pvtUi tbody tr:first-child td{
                    display: inline-block;
            } */

        /* .pvtUi tbody tr:first-child td.pvtVals {
            display: none;
        }

        .pvtUi tbody tr:first-child td .pvtRenderer{
            display: none;
        }

        .pvtUi tbody tr:first-child td:last-child {
            display: block;
        }

        .pvtUi tbody tr:first-child td:first-child {
            display: none;
        }

        .pvtUi tbody tr:nth-child(2) td:nth-child(2) {
            display: none;
        }

        .pvtUi tbody tr:first-child td.pvtAxisContainer.pvtHorizList.pvtCols.ui-sortable li:first-child {
            display: none;
        }

        .pvtUi tbody tr:nth-child(2) td:first-child div, .pvtUi tbody tr:nth-child(2) td:first-child li   {
            display: none;
        }


        .pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2){
            display: inherit;
        }


        div {
            font-size: 14px;
        }

        th.pvtTotalLabel.colTotal {
            background: #f9f9f9;
        } */
        /* td.pvtAxisContainer.pvtHorizList.pvtCols.ui-sortable {
            display: none;
        } */
        #searchItems {
            margin-left: 20px;
            padding: 1px;
        }

        .pvtTableSearchSection {
            display: flex;
        }


    </style>
</head>
<body>
    <div class="tableScroll">
        <button id="left"> <img class="scroll" src="/sites/all/modules/custom/dd_accessibility/templates/images/left-arrow.svg" /> </button>
        <button id="right"><img class="scroll" src="/sites/all/modules/custom/dd_accessibility/templates/images/right-arrow.svg" /> </button>
    </div>


    <div id="output" class="sticky" style="margin: 30px;"></div>


    <script type="text/javascript">
        $(function () {

            var dataClass = $.pivotUtilities.CustomPivotData;
            var renderers = $.pivotUtilities.custom_renderers;
            var extension = new PivotTableExtensions;
            var tabledata;

            $.getJSON("/sites/default/files/accessibility_api/jsonapi.json", function (mps) {
                tabledata = mps;

                $("#output").pivotUI(mps, {
                    dataClass: dataClass,
                    cols: ["Agency Name", "Website Name"],
                    rows: ["WCAG Success Criteria", "ICT Group", "Test Rule Name"],
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
                        scrollTable();
                        getFilterList();
                    }
                });
                setTimeout(function () {
                    console.log($(".pvtTable tbody tr.row0").length);
                    console.log($(".pvtTable tbody tr").length);
                    let totalRowsLen = $(".pvtTable tbody tr").length;
                    let x = 0;
                    for(let i =0; i< totalRowsLen; i++) {
                        console.log(i + " value length " + $(".pvtTable tbody tr.row"+i+"").length);
                        if($(".pvtTable tbody tr.row"+i+"").length === 0) {
                            break;
                        } else {
                            let elmntLength = $(".pvtTable tbody tr.row"+i+"").length;
                            x = x + elmntLength;
                            console.log(x);
                            var elmnt = $(".pvtTable tbody tr").eq(x-1).find("th div").html();
                            console.log(elmntLength, elmnt);
                            $(".pvtTable tbody tr").eq(x-1).find("th div").html("<a target='_blank' class='link' href='https://www.google.com/'>" + elmnt + "</a>");
                        }
                    }

                    getFilterList();

                }, 500);
            });


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
                    console.log(fontSize);
                    fontSize = fontSize + 2 + "px";
                    console.log(fontSize);
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

            // Filter by Agency
            function getFilterList() {
                $.getJSON("/sites/default/files/accessibility_api/jsonapi.json", function (mps) {
                    tableData = mps;
                    var lookup = {};
                    var items = tableData;
                    var result = [];
                    $('#searchItems').append("<option>select</option>");
                    for (var item, i = 0; item = items[i++];) {
                        var name = item["Agency Name"];

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
                    if(localStorage.getItem("selectItemVal")) {
                        console.log(localStorage.getItem("selectItemVal"))
                        $("#searchItems :selected").val(localStorage.getItem("selectItemVal"));
                    }
                });
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
