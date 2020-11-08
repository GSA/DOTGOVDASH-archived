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
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibilitycss//pivot.min.css">


    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/custom.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/custom.css">

    <!-- optional: mobile support with jqueryui-touch-punch -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.ui.touch-punch.min.js"></script>

    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <style>
        table.pvtTable tbody tr th.pvtRowLabel.rowexpanded {
            cursor:auto !important;
        }
        .link {
            text-decoration: none;
            color: inherit;
        }

        .link:hover {
            text-decoration: underline;
        }

        /* .pvtUi tbody tr:first-child td{
                    display: inline-block;
            } */

        .pvtUi tbody tr:first-child td.pvtVals {
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

        td.pvtAxisContainer.pvtHorizList.pvtCols.ui-sortable {
            display: none;
        }

        div {
            font-size: 14px;
        }

        th.pvtTotalLabel.colTotal {
            background: #f9f9f9;
        }

    </style>
</head>

<body>
<div><table border="0"><tr><td><a href="/accessibility/govwide/csvapi" target="_blank">RAW Data Download in CSV &nbsp;|</td><td><a href="/accessibility/govwide/jsonapi" target="_blank">RAW Data Download in JSON</td></tr></table></div>

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
                // cols: [ "Domain",  "Agency"],
                // rows: ["code"],
                cols: ["Agency Name","Website Name"],
                rows: [ "WCAG Success Criteria", "ICT Group", "Test Rule Name"],
                renderers: renderers,
                rendererName: "Table With Pagination",

                rendererOptions: {
                    rowSubtotalDisplay: {
                        disableFrom: 1
                    },
                    colSubtotalDisplay: {
                        disableFrom: 0
                    },
                    collapseColsAt: 0,
                },
                onRefresh: function (pivotUIOptions) {
                    extension.initFixedHeaders($('table.pvtTable'));
                    //loadClick();
                    // loadAlert();
                }
            });

        });
        // To do
        // function loadAlert() {
        //     $( ".pvtHorizList > .axis_1.ui-sortable-handle" ).click(function() {
        //         $( ".pvtUi tbody tr:nth-child(2) td:first-child, .pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
        //         $( ".pvtUi tbody tr:nth-child(2) td:first-child div:nth-child(2) .pvtCheckContainer").show();
        //     });
        // }

        function loadClick() {
            if(tabledata) {
                var navLinkMap = new Map();
                for (var i=0; i<tabledata.length; i++) {
                    if(tabledata[i].redirectedTo) {
                        navLinkMap[tabledata[i].code] = tabledata[i].redirectedTo
                    }
                }
            }

            setTimeout(function(){
                $.each( $(".pvtTable tbody tr"), function( key, value ) {
                    if(key < ($(".pvtTable tbody tr").length - 1)) {
                        var elmnt = $(".pvtTable tbody tr").eq(key).find("th div").html();
                        $(".pvtTable tbody tr").eq(key).find("th div").html("<a target='_blank' class='link' href='"+navLinkMap[elmnt]+"'>"+elmnt+"</a>");
                    }
                });
            }, 500);
        }

    });
</script>


</body>

</html>