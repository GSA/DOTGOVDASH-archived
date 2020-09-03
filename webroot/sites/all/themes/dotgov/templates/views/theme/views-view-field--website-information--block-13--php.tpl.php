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
    .mn-height-90 {
        min-height: 90px !important;
    }
    .mn-height-150 {
        min-height: 150px !important;
    }
</style>
<?php
$crit_text = '';
$redirect_message = 'Website Redirect - Metric Not Applicable';
if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if($row->field_field_uswds_status['0']['raw']['value'] == NULL) {
    $crit_text .= "USWDS Data not available for this site. ";
  }
}
dotgov_common_tooltip("tooltip10","id");
?>
<div class="col-xs-12 nopadding clearfix">
<div class="col-xs-10">
    <h2 class="pane-title">USWDS Code</h2>
</div>
<div class="col-xs-2 nopadding">
    <div id="tooltip3" class="infor">
        <a href="https://github.com/18F/site-scanning-documentation/blob/master/scans/live/uswds.md"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i></a>
    </div>
</div>
</div>
<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/".$scanids['uswds_scan']);

$query = db_query("select a.field_uswds_score_value,b.field_uswds_status_value from field_data_field_uswds_score a , field_data_field_uswds_status b,field_data_field_website_id c where a.entity_id=c.field_website_id_nid and b.entity_id=c.entity_id and a.entity_id=:nid",array(":nid"=>arg(1)));
foreach ($query as $result) {
    $uswdsscore = $result->field_uswds_score_value;
    $uswdsstat = $result->field_uswds_status_value;
}
$chartdatafont = "12px";
?>

<div class="col-lg-12 clearfix nopadding">
  <?php
  if(!is_redirect(arg(1))) {
    print '<div class="col-lg-6">';
    if($uswdsscore == NULL  || $uswdsscore == '') {
      print "USWDS Code: Not Detected<br>";
      $chartdatatext = "Not Detected";
      $chartdatafont = "12px";
      $chartdata = "0";
    }
    elseif($uswdsscore == '0') {
      print "USWDS Code: Not Detected<br>";
      $chartdatatext = "Not Detected";
      $chartdata = "0";
    }
    elseif($uswdsscore == '100') {
      print "USWDS Code: Detected<br>";
      $chartdatatext = "Detected";
      $chartdata = "100";
    }
    else {
      print "USWDS Code: Detected<br>";
      $chartdatatext = "Detected";
      $chartdata = $uswdsscore;
    }
  } else {
    print '<div class="col-sm-12 mn-height-90">';
    print '<p>USWDS Code: <span>Website Redirect - Metric Not Applicable</span></p><br>';
  }
  print '<p>The USWDS scan checks each domain for the use of U.S. Web Design System (USWDS) code and the code version</p>';
  ?>
</div>

<?php
if ($chartdata <= 50) {
    $chartcolor = '#664f02';
} elseif($chartdata>50 and $chartdata<=75) {
    $chartcolor='#664f02';
} else {
    $chartcolor='#664f02';
}
?>

<?php if (!is_redirect(arg(1))): ?>
  <div class="col-lg-6">
      <div id="uswds_chart" style="width: 130px; height:130px; margin: 0 auto">&nbsp;</div>
  </div>
<?php else: ?>
<div class="col-sm-12 mn-height-150">&nbsp;</div>
<?php endif; ?>

</div>

<div class="col-lg-12 clearfix report-buttons">
    <p>
        <a class="link-all-reports" href="/<?=$scanpath?>">Go to Full Report</a>
    </p>
</div>

<script type="text/javascript">
    Highcharts.chart('uswds_chart', {
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
                    size: '115.35',
                    linecap: 'round',
                    stickyTracking: false,
                    rounded: true
                }
            },
            series: [{
                name: 'USWDS',
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
