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

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/".$scanids['domain_scan_information']);
$chartdata = $row->_field_data['nid']['entity']->field_dnssec_score['und'][0]['value'];
if ($chartdata == 0) {
    $chartcolor = '#ac0600';
} elseif ($chartdata > 0){
    $chartcolor = '#29643a';
    $chartdata = 100;
}

dotgov_common_tooltip("tooltip5","id");
?>
<div class="col-xs-10">
    <h2 class="pane-title">DNSSEC Information</h2>
</div>
<div class="col-xs-2">
    <div id="tooltip5" class="infor">
        <img class="info-icon" src="/sites/all/themes/dotgov/images/info.png" width="20" alt="info icon">
        <span class="tooltiptext tooltip-left">
          <img src="/sites/all/themes/dotgov/images/helpchart.png"  alt="Image for the color code" ><br>DNSSEC Data is collected through a custom scanner component of dotgov dashboard that last ran on <?php dotgov_common_lastScanDate(); ?>
        </span>
    </div>
</div>

<div id="dnssec_chart" style="width: 130px; height:130px; margin: 0 auto">&nbsp;</div>
<div class="sr-only">The graphic below indicates the level of DNSSEC compliance, and this score is <?php echo $chartdata; ?>%.</div>

<div class="col-lg-6">
    <?php print 'DNSSEC Compliance: ' . $row->field_field_dnssec_score_1[0]['raw']['value'] . '%<br>'; ?>
</div>

<?php
$blockObject = block_load('trend_analysis', 'trends_dnssec_sparkline');
$block = _block_get_renderable_array(_block_render_blocks(array($blockObject)));
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . $scanids['domain_scan_information']);
?>
<div class="col-lg-12">
    <?php print drupal_render($block); ?>
</div>

<div class="col-lg-12 clearfix report-buttons">
    <p>
        <a href="/improve-my-score">How to Improve Score</a>
    </p>
    <p>
        <a class="link-all-reports" href="/<?=$scanpath?>">Go to Full Report</a>
        <a class="trend-analysis-reports link-all-reports" href="/historical_scan_score_data/<?=arg(1)?>?order=field_dnssec_score-revision_id&sort=desc">Trend Analysis Report</a>
    </p>
</div>

<script type="text/javascript">
    Highcharts.chart('dnssec_chart', {
            chart: {
                type: 'solidgauge',
            },
            title: {
                text: ''
            },
            credits: {
                enabled: false
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
                    text: '<?php echo ($chartdata); ?> %',
                    style: {
                        fontSize: '22px',
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
                name: 'HTTPS',
                data: [{
                    color: '<?php echo $chartcolor; ?>',
                    radius: '118%',
                    innerRadius: '80%',
                    y:<?php echo ($chartdata); ?>
                }]
            }]
        }
    );
</script>