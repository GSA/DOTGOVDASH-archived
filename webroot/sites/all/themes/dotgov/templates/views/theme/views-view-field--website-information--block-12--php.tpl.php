<?php
/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<style>
#searchengine_chart .highcharts-container {
    height:160px !important;
}
</style>

<div class="col-lg-12 nopadding clearfix">
    <?php dotgov_common_tooltip("tooltip5","id");?>
    <div class="col-xs-10">
        <h2 class="pane-title">On-Site Search Information</h2>
    </div>
    <div class="col-xs-2 nopadding">
        <div id="tooltip5" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
            <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>
    On-Site Search Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?> </span>
        </div>
    </div>
</div>

<?php if(!is_redirect($row->nid)): ?>
<div class="col-lg-6">
    <?php
    if($row->field_field_search_status['0']['raw']['value'] == "1") {
      $searchscore = "Yes";
    } elseif($row->field_field_search_status['0']['raw']['value'] == "0") {
      $searchscore = "No";
    } else {
      $searchscore = "NA";
    }

    if(trim($row->field_field_search_engine_name['0']['raw']['value']) == "") {
      $searchengine_name = "Not available";
    } else {
      $searchengine_name = $row->field_field_search_engine_name['0']['raw']['value'];
    }

    print "On-Site Search: $searchscore <br>";
    print "On-Site Search Engine: <span style='text-transform: capitalize;'>".$searchengine_name."</span>";
    ?>
</div>

<div class="col-lg-6">
    <div id="searchengine_chart" style="width: 130px; height:130px; margin: 0 auto">&nbsp;</div>
</div>
<?php else: ?>
    <div class="col-lg-12">
      <?php
      $redirect_message = '<span style="color:#a70000;">Website Redirect - Metric Not Applicable</span></br>';
      print "On-Site Search: " . $redirect_message;
      print "On-Site Search Engine Identified: " . $redirect_message;
      ?>
    </div>
<?php endif; ?>

<?php
$chartdata = $row->_field_data['nid']['entity']->field_search_status['und'][0]['value'];
$chartdatafont = "22px";
if (trim($chartdata) == '1') {
    $chartcolor = '#29643a';
    $chartdatatext = '100%';
    $chartdata = 100;
} elseif(trim($chartdata) == '0') {
    $chartcolor = '#ac0600';
    $chartdatatext = '0%';
    $chartdata = '0';
} elseif(trim($chartdata) == '') {
    $chartcolor = '#ac0600';
    $chartdatatext = 'Not Available';
    $chartdata = '0';
    $chartdatafont = "12px";
}
?>

<div class="sr-only">The graphic below indicates the level of On-Site Search Engine compliance, and this score is <?php echo $chartdata; ?>%.</div>

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . arg(1));
?>
<div class="col-lg-12 clearfix report-buttons">
    <div>
        <p><a class="link-all-reports" href="/<?=$scanpath?>">Go to Full Report</a></p>
    </div>
</div>

<script type="text/javascript">
    Highcharts.chart('searchengine_chart', {
            chart: {
                type: 'solidgauge',
                height:140
            },
            title: {
                text: ''
            },
            tooltip: {
                enabled:false,
            },
            pane: {
                startAngle: 0,
                endAngle: 360,
                background: [{
                    outerRadius: '118%',
                    innerRadius: '80%',
                    backgroundColor: '#d6d7d9',
                    borderWidth: 0
                }]
            },
            yAxis: {
                min: 0,
                max: 100,
                lineWidth: 0,
                tickPositions: [],
                title: {
                    text: '<?php echo $chartdatatext; ?>',
                    style: {
                        fontSize: '<?=$chartdatafont?>',
                        color:'<?php echo $chartcolor; ?>',
                    },
                    y: 30
                },
            },
            plotOptions: {
                solidgauge: {
                    dataLabels: {
                        enabled: false
                    },
                    linecap: 'round',
                    stickyTracking: false,
                    rounded: true
                }
            },
            series: [{
                name: 'On-Site Search Engine Compliance',
                data: [{
                    color: '<?php echo $chartcolor; ?>',
                    radius: '118%',
                    innerRadius: '80%',
                    y:<?php echo $chartdata; ?>
                }]
            }]
        }
    );
</script>
