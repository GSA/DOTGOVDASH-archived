<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<style>
.mn-height-165 { min-height: 165px !important; }
.mn-height-80 { min-height: 60px !important; }
</style>

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . $scanids['508_scan_information']);
$showlegend = 1;
$redirect_message = 'Website Redirect - Metric Not Applicable';

$colorcont = $row->field_field_accessible_group_colorcont[ '0' ][ 'raw' ][ 'value' ];
$htmlattri = $row->field_field_accessible_group_htmlattri[ '0' ][ 'raw' ][ 'value' ];
$missingim = $row->field_field_accessible_group_missingim[ '0' ][ 'raw' ][ 'value' ];

if(emptyOrNull($colorcont) && emptyOrNull($htmlattri) && emptyOrNull($missingim)) {
    $showlegend = 0;
}

$crit_text = '';
if ( !emptyOrNull($colorcont)) {
  $crit_text .= "Color Contrast Issues : " . $colorcont ."<br>";
}
if ( !emptyOrNull($htmlattri)) {
  $crit_text .= "HTML Attribute Issues : " . $htmlattri . "<br>";
}
if ( !emptyOrNull($missingim)) {
  $crit_text .= "Missing Image Description : " . $missingim . "<br>";
}
dotgov_common_tooltip("tooltip9","id");
?>

<div class="col-xs-12 nopadding clearfix">
<div class="col-xs-10 nopadding">
    <h2 class="pane-title">Accessibility Issues</h2>
</div>
<div class="col-xs-2 nopadding">
    <div id="tooltip9" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
        <span class="tooltiptext tooltip-left">
            <?php
                if (!is_redirect(arg(1))) {
                    print '<span style="color:white;">' . $crit_text . "</span><br>";
                } else {
                    print '<span style="color:white;">' . $redirect_message . "</span><br>";
                }
            ?>
        Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php dotgov_common_lastScanDate(); ?>
        </span>
    </div>
</div>
</div>
<?php if (!is_redirect(arg(1))): ?>
    <div class="col-xs-12 nopadding">
        Color Contrast: <?php print !emptyOrNull($colorcont) ? $colorcont : 0; ?> <br/>
        HTML Attribute: <?php print !emptyOrNull($htmlattri) ? $htmlattri : 0; ?> <br/>
        Missing Image Description: <?php print !emptyOrNull($missingim) ? $missingim : 0; ?>
    </div>
    <div class="col-xs-12 nopadding">
        <div style="display:block; float:left;min-height: 185px; width:100%;">
            <div class="col-xs-7">
            <ul class="access-issues nopadding" style="margin-left: auto;margin-top: 30px;font-size:12px; line-height: 16px;">
            <li class="b-1">Color Contrast Issues</li>
            <li class="b-2">HTML Attribute issues</li>
            <li class="b-3">Missing Image description</li>
        </ul>
            </div>
            <div class="col-xs-5">
            <div id="access_chart" style="height: 150px;width: 150px;margin-top: -22px;margin-left: -10px;"></div>
            </div>
        </div>    
        <!-- <div id="access_chart" style="height:192px;">&nbsp</div> -->
    </div> 
<?php else: ?>
    <div class="col-sm-12 mn-height-80 nopadding">
        Color Contrast: <span style="color:#a70000;"><?php print $redirect_message; ?></span><br>
        HTML Attribute: <span style="color:#a70000;"><?php print $redirect_message; ?></span><br>
        Missing Image Description: <span style="color:#a70000;"><?php print $redirect_message; ?></span>
    </div>
    <div class="col-sm-12 mn-height-165">&nbsp;</div>
<?php endif; ?>

<div class="col-lg-12 clearfix report-buttons nopadding">
    <p>
        <a href="/improve-my-score">How to Improve Score</a>
    </p>
    <p>
        <a class="link-all-reports" href="/<?php print $scanpath;?>">Go to Full Report</a>
        <a class="trend-analysis-reports link-all-reports" href="/accessibility_historical_data/<?=$scanids['508_scan_information']?>">Trend Analysis Report</a>
    </p>
</div>

<script type="text/javascript">
    var data = [];
    data = colorPercentage(data, 'Color Contrast Issues', <?php print_r(!emptyOrNull($colorcont) ? $colorcont : 0); ?>);
    data = colorPercentage(data, 'HTML Attribute Issues', <?php print_r(!emptyOrNull($htmlattri) ? $htmlattri : 0); ?>);
    data = colorPercentage(data, 'Missing Image Description Issues', <?php print_r(!emptyOrNull($missingim) ? $missingim : 0); ?>);

    function colorPercentage(data, dataName, dataY) {
      if (dataY >= 0) {
        data.push({
          name: dataName,
          y: dataY
        });
      }
      return data;
    }
    Highcharts.chart('access_chart', {
        chart: {
            plotBackgroundColor: null,
            plotBorderWidth: null,
            plotShadow: false,
            type: 'pie'
        },
        title: {
            text: ''
        },
        credits: {
            enabled: false
        },
        legend:{
            enabled: false
        },
        tooltip: {
            pointFormat: '{series.name}: <b>{point.percentage:.1f}%</b>'
        },
        plotOptions: {
            pie: {
                allowPointSelect: true,
                cursor: 'pointer',
                dataLabels: {
                    enabled: true,
                    format: "<br>{point.percentage:.1f}%",
                    distance: -16,
                    filter: {
                      property: 'percentage',
                      operator: '>',
                      value: 18
                    }
                },
                size: '101.78',
                <?php if($showlegend == 1) print "showInLegend: true"; ?>
            }
        },
        series: [{
            name: 'Percentage',
            colorByPoint: true,
            data: data
        }]
    });
</script>