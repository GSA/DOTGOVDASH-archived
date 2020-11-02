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

    </style>

    <!-- optional: mobile support with jqueryui-touch-punch -->
    <script type="text/javascript" src="/sites/all/modules/custom/dd_accessibility/js/jquery.ui.touch-punch.min.js"></script>

</head>
<body>
<div><table border="0"><tr><td style="background-color: #00CCFF"><a href="/accessibility/govwide/csvapi" target="_blank">Download CSV</td><td style="background-color: #1b809e"><a href="/accessibility/govwide/jsonapi" target="_blank">Download JSON</td></tr></table></div>
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
<?
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
    <?
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
    <?
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
    <?
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
    <?
}
?>

<div id="output" style="margin: 30px; display: inline-block; overflow-x:scroll ; overflow-y: scroll; width: 100%;"></div>

</body>
</html>