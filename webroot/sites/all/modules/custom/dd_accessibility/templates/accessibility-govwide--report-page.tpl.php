<html>
<head>
    <title>Government Wide Accessibility Report</title>
    <!-- external libs from cdnjs -->
    <script src="/sites/all/modules/custom/dd_accessibility/js/plotly-basic-latest.min.js"></script>

    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.min.js"></script>
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery-ui.min.js"></script>
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/papaparse.min.js"></script>

    <!-- PivotTable.js libs from ../dist -->
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/pivot.css">
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/pivot.js"></script>
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/plotly_renderers.js"></script>
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/subtotal.js"></script>
    <link rel="stylesheet" type="text/css" href="/sites/all/modules/custom/dd_accessibility/css/subtotal.css">
    <style>
        body {font-family: Verdana;}
        .pvtVertList li {display: none;}
        table.pvtTable thead tr th {
            background: linear-gradient(#547f99, #6f9ebb, #547f99);
            color: #fff;
        }

        table.pvtTable tbody tr th, table.pvtTable thead tr th, table.pvtTable tbody tr td {
            border: none;
        }

        .pvtTable {
            position: sticky !important;
            top: 0;
            z-index: 10;
        }

        /* .pvtTable thead {
            position: -webkit-sticky;
            position: sticky;
            top: 0;
            font-size: 14px;
        } */

        .pvtTable thead th {
            position: -webkit-sticky;
            position: sticky;
            top: 0;
            bottom: 0;
            font-size: 14px;
        }

        .pvtHorizList, .pvtVertList, .pvtRows , .pvtRenderer, .pvtAggregator{
            display: none;
        }


        table.pvtTable tbody tr th, table.pvtTable thead tr th {
            background-color: transparent;
        }

        table.pvtTable tr:nth-child(2n+1) td {
            background: #f9f9f9;
        }

        table.pvtTable tbody tr td {
            padding: 8px !important;
            font-size: 14px;
        }

        th.pvtTotalLabel.rowTotal, th.pvtAxisLabel,th.pvtColLabel.colshow {
            font-size: 14px;
        }

        table.pvtTable .pvtAxisLabel.expanded {
            font-size: 14px;
        }

        .pvtVals {
            display: none;
        }

        table.pvtTable .pvtAxisLabel {
            font-size: 14px;
        }

        /* .pvtTotalLabel {display: none; }
       .pvtTotal {display: none; }
       .pvtGrandTotal {display: none; } */

    </style>

    <!-- optional: mobile support with jqueryui-touch-punch -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.ui.touch-punch.min.js"></script>

</head>
<body>
<div><table border="0"><tr><td><a href="/accessibility/govwide/csvapi" target="_blank">Download CSV &nbsp;|</td><td><a href="/accessibility/govwide/jsonapi" target="_blank">&nbsp;Download JSON</td></tr></table></div>
<?php
if(arg(3) == "") {
    ?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: ["agency_name"],
                    rows: ["website", "error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
    <?php
}
elseif(arg(3) == "2") {
    ?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: [],
                    rows: [ "agency_name","website","error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
<?php
}
elseif(arg(3) == "3") {
?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: ["agency_name"],
                    rows: [ "error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        collapseAt: 0
                    },
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
    <?php
}
    elseif(arg(3) == "4") {
    ?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: ["agency_name","website"  ],
                    rows: [ "error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        collapseRowsAt: 3,
                    },
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
    <?php
}
    elseif(arg(3) == "5") {
    ?>
    <script type="text/javascript">
        $(function(){
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal",$.pivotUtilities.plotly_renderers];
            $.getJSON("/jsonapi.json", function(mps) {
                $("#output").pivotUI(mps,
                    {
                        cols: ["agency_name","website"  ],
                        rows: [ "error_cat", "wcag_code", "error_code"],
                        renderer: renderer,
                        menuLimit: 200,
                        rowSubtotalDisplay: {
                            collapseAt: 0
                        },
                        rowSubtotalDisplay: {
                            displayOnTop: false
                        }
                    },
                );
            });
        });


    </script>
    <?php
}
    elseif(arg(3) == "6") {
    ?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: ["agency_name","website"  ],
                    rows: [ "error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        collapseRowsAt: 3,
                    },
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
    <?php
}
    elseif(arg(3) == "7") {
    ?>
    <script type="text/javascript">

        // This example loads the "Canadian Parliament 2012" dataset

        $(function () {
            var dataClass = $.pivotUtilities.SubtotalPivotData;
            var renderer = $.pivotUtilities.subtotal_renderers["Table With Subtotal"];

            $.getJSON("/jsonapi.json", function (mps) {
                $("#output").pivot(mps, {
                    dataClass: dataClass,
                    cols: ["agency_name" ],
                    rows: [ "error_cat", "wcag_code", "error_code"],
                    renderer: renderer,
                    rowSubtotalDisplay: {
                        collapseRowsAt: 3,
                    },
                    rowSubtotalDisplay: {
                        displayOnTop: false
                    }
                });
            });
        });
    </script>
    <?php
}
?>

<div id="output" style="margin: 30px; display: inline-block; overflow-x:scroll ; overflow-y: scroll; width: 100%;"></div>

</body>
</html>