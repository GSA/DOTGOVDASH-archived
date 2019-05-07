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
//
$query = db_query("select a.field_dap_score_value,b.field_dap_status_value from field_data_field_dap_score a , field_data_field_dap_status b,field_data_field_website_id c where a.entity_id=c.field_website_id_nid and b.entity_id=c.entity_id and a.entity_id=:nid",array(":nid"=>arg(1)));
foreach ($query as $result) {
$dapscore = $result->field_dap_score_value;
$dapstat = $result->field_dap_status_value;
}
//drupal_add_js('https://code.highcharts.com/highcharts-more.js');
//drupal_add_js('https://code.highcharts.com/modules/solid-gauge.js');
//drupal_add_js(drupal_get_path('module', 'activity_chart') . '/activity_chart.js');
$chartdatafont = "22px";
?>
<div class="col-lg-6">
<?php
if($dapscore == NULL  || $dapscore == '') {
    print "DAP Score: Not Available<br>";
    print "DAP Status: Not Available<br>";
    $chartdatatext = "Not Available";
    $chartdatafont = "12px";
    $chartdata = "0";
}
elseif($dapscore == '0') {
    print "DAP Score: 0%<br>";
    print "DAP Status: Not Implemented<br>";
    $chartdatatext = "0%";
    $chartdata = "0";
}
elseif($dapscore == '100') {
    print "DAP Score: 100%<br>";
    print "DAP Status: Implemented<br>";
    $chartdatatext = "100%";
    $chartdata = "100";
}
else {
    print "DAP Score: ".$dapscore."%<br>";
    print "DAP Status: Implemented<br>";
    $chartdatatext = $dapscore."%";
    $chartdata = $dapscore;
}

?>
</div>
<?php print $output;?>

<?php //dsm($view->result);
//dsm ($row->_field_data['nid']['entity']->field_https_score['und'][0]['safe_value']);


if ($chartdata <= 50){
    $chartcolor = '#ac0600';
}elseif($chartdata>50 and $chartdata<=75){
    $chartcolor='#654f00';
}

else{
    $chartcolor='#29643a';
}

?>
<script type="text/javascript">
    Highcharts.chart('dap_chart', {

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
                    text: '<?php echo ($chartdatatext); ?>',
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
                name: 'DAP',
                data: [{
                    color: '<?php echo $chartcolor; ?>',
                    radius: '118%',
                    innerRadius: '80%',
                    y:<?=$chartdata?>
                }]
            }]
        }


    );
</script>



