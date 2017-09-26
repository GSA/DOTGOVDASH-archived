<?php
/**
 * Created by PhpStorm.
 * User: kapilbulchandani
 * Date: 5/19/17
 * Time: 12:08 AM
 */

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
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/".$scanids['https_dap_scan_information']);
?>

<?php
//drupal_add_js('https://code.highcharts.com/highcharts-more.js');
//drupal_add_js('https://code.highcharts.com/modules/solid-gauge.js');
//drupal_add_js(drupal_get_path('module', 'activity_chart') . '/activity_chart.js');
?>
<?php print $output; ?>
<div><p><a class="link-all-reports" href="/<?=$scanpath?>">Go to Full Report</a></p></div>
<?php //dsm($view->result);
//dsm ($row->_field_data['nid']['entity']->field_https_score['und'][0]['safe_value']);
$chartdata= $row->_field_data['nid']['entity']->field_https_score['und'][0]['value'];
if ($chartdata <= 50){
    $chartcolor = '#ac0600';
}elseif($chartdata>=50 and $chartdata<=75){
    $chartcolor='#654f00';
}
else{
    $chartcolor='#29643a';
}
?>
<script type="text/javascript">
    Highcharts.chart('https_chart', {

            chart: {
                type: 'solidgauge',

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
                    text: '<?php echo ($chartdata); ?> %',
                    style: {
                        fontSize: '22px',
                        color:'<?php echo $chartcolor; ?>'
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

