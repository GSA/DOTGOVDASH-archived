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

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . $scanids['508_scan_information']);
$showlegend = 1;
$redirect_message = 'Website Redirect - Metric Not Applicable';
if(
  emptyOrNull($row->field_field_accessible_group_colorcont[ '0' ][ 'raw' ][ 'value' ]) &&
  emptyOrNull($row->field_field_accessible_group_htmlattri[ '0' ][ 'raw' ][ 'value' ]) &&
  emptyOrNull($row->field_field_accessible_group_missingim[ '0' ][ 'raw' ][ 'value' ])) {
    $showlegend = 0;
}
?>

<?php
$crit_text = '';
if ( !emptyOrNull($row->field_field_accessible_group_colorcont[ '0' ][ 'raw' ][ 'value' ])) {
  $crit_text .= "Color Contrast Issues : " . $row->field_field_accessible_group_colorcont[ '0' ][ 'raw' ][ 'value' ] ."<br>";
}
if ( !emptyOrNull($row->field_field_accessible_group_htmlattri[ '0' ][ 'raw' ][ 'value' ])) {
  $crit_text .= "HTML Attribute Issues : " . $row->field_field_accessible_group_htmlattri[ '0' ][ 'raw' ][ 'value' ] . "<br>";
}
if ( !emptyOrNull($row->field_field_accessible_group_missingim[ '0' ][ 'raw' ][ 'value' ])) {
  $crit_text .= "Missing Image Description : " . $row->field_field_accessible_group_missingim[ '0' ][ 'raw' ][ 'value' ] . "<br>";
}
dotgov_common_tooltip("tooltip9","id");
?>
<div class="col-xs-10 nopadding">
    <h2 class="pane-title">Accessibility Issues</h2>
</div>
<div class="col-xs-2 nopadding">
    <div id="tooltip9" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
        <span class="tooltiptext tooltip-left">
            <?php
                if (!is_redirect(arg(1))) {
                  print '<span style="color:#a70000;">' . $crit_text . "</span><br>";
                } else {
                    print '<span style="color:#a70000;">' . $redirect_message . "</span><br>";
                }
            ?>
        Accessibility Data is collected from pulse.gov website though a scan that last ran on <?php dotgov_common_lastScanDate(); ?>
        </span>
    </div>
</div>

<?php if (!is_redirect(arg(1))): ?>
    <div class="col-lg-5 nopadding">
        Color Contrast: <?php print $row->field_field_accessible_group_colorcont[ '0' ][ 'raw' ][ 'value' ]; ?> <br/>
        HTML Attribute: <?php print $row->field_field_accessible_group_htmlattri[ '0' ][ 'raw' ][ 'value' ]; ?> <br/>
        Missing Image Description: <?php print $row->field_field_accessible_group_missingim[ '0' ][ 'raw' ][ 'value' ]; ?>
    </div>
    <div class="col-lg-7 nopadding">
        <div id="access_chart" style="height:200px;">&nbsp</div>
    </div>
<?php else: ?>
    <div class="col-lg-12 nopadding">
        Color Contrast: <span style="color:#a70000;"><?php print $redirect_message; ?></span><br>
        HTML Attribute: <span style="color:#a70000;"><?php print $redirect_message; ?></span><br>
        Missing Image Description: <span style="color:#a70000;"><?php print $redirect_message; ?></span>
    </div>
<?php endif; ?>

<div class="col-lg-12 clearfix report-buttons">
    <p>
        <a href="/improve-my-score">How to Improve Score</a>
    </p>
    <p>
        <a class="link-all-reports" href="/<?php print $scanpath;?>">Go to Full Report</a>
        <a class="trend-analysis-reports link-all-reports" href="/accessibility_historical_data/<?=$scanids['508_scan_information']?>">Trend Analysis Report</a>
    </p>
</div>

<script type="text/javascript">
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
        legend:{

        },
        tooltip: {
            pointFormat: '{series.name}: <b>{point.percentage:.1f}%</b>'
        },
        plotOptions: {
            pie: {
                allowPointSelect: true,
                cursor: 'pointer',
                dataLabels: {
                    enabled: false
                },
                <?php if($showlegend == 1) print "showInLegend: true"; ?>
            }
        },
        series: [{
            name: 'Percentage',
            colorByPoint: true,
            data: [{
                name: 'Color Contrast Issues',
                y: <?php print_r(($view->result[0]->_field_data['nid']['entity']->field_accessible_group_colorcont['und'][0]['value']!= '')?$view->result[0]->_field_data['nid']['entity']->field_accessible_group_colorcont['und'][0]['value']:0);?>
            }, {
                name: 'HTML Attribute Issues',
                y: <?php print_r( ($view->result[0]->_field_data['nid']['entity']->field_accessible_group_htmlattri['und'][0]['value'] != '')?$view->result[0]->_field_data['nid']['entity']->field_accessible_group_htmlattri['und'][0]['value']:0);?>

            }, {
                name: 'Missing Image Description Issues',
                y: <?php print_r(($view->result[0]->_field_data['nid']['entity']->field_accessible_group_missingim['und'][0]['value'] != '')?$view->result[0]->_field_data['nid']['entity']->field_accessible_group_missingim['und'][0]['value']:0); ?>
            }]
        }]
    });
</script>