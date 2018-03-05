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
$scanpath = drupal_get_path_alias("node/".$scanids['508_scan_information']);
 //print $output;
?>
<div id="access_chart" style="width: 245px; height:200px; float:right;">&nbsp;</div>
<?php 
//dsm($view->result[0]->_field_data['nid']['entity']);
?>
<div><p><a class="link-all-reports" href="/<?=$scanpath?>">Go to Full Report</a></p></div>

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
            showInLegend: true
        }
    },
    series: [{
        name: 'Percentage',
        colorByPoint: true,
        data: [{
            name: 'Color Contrast Issues',
            y: <?php print_r( $view->result[0]->_field_data['nid']['entity']->field_accessible_group_colorcont['und'][0]['value']);?>
        }, {
            name: 'HTML Attribute Issues',
            y: <?php print_r( $view->result[0]->_field_data['nid']['entity']->field_accessible_group_htmlattri['und'][0]['value']);?>
           
        }, {
            name: 'Missing Image Description Issues',
            y: <?php print_r( $view->result[0]->_field_data['nid']['entity']->field_accessible_group_missingim['und'][0]['value']); ?>
        }]
    }]
});
</script>
