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
<?php print $output; ?>
<?php
$data_performance = $row->field_field_mobile_performance_score[0]['raw']['value'];
$data_usability =  $row->field_field_mobile_usability_score[0]['raw']['value'];
$data_overall =  $row->field_field_mobile_overall_score[0]['raw']['value'];
$nid = $row->field_field_website_id[0]['raw']['nid'];

if(isNullNotZero($data_performance) && !empty($nid)) {
  $result_perf = get_mobile_score_information($nid, NULL, -1);
  $result_performance = $result_perf['performance'];
}

if(isNullNotZero($data_usability) && !empty($nid)) {
  $result_usab = get_mobile_score_information($nid, -1, NULL);
  $result_usability = $result_usab['usability'];
}

if(!isNullNotZero($data_performance) && !isNullNotZero($data_usability)) {
  if (!isNullNotZero($data_overall)) {
    $chartdata = $data_overall;
  } else {
    $chartdata = round(($data_performance + $data_usability) / 2);
  }
} elseif((isNullNotZero($data_performance) && isNullNotZero($data_usability)) || (isNullNotZero($data_performance) || isNullNotZero($data_usability))) {
    $chartdata = -1;
}

if ($chartdata <= 50) {
    $chartcolor = '#ac0600';
} elseif($chartdata>50 and $chartdata<=75) {
    $chartcolor='#654f00';
} else {
    $chartcolor='#29643a';
}
?>

<?php
// Mobile Information PHP1
$redirect_message = 'Website Redirect - Metric Not Applicable';
$crit_text = '';
if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] != '' ) {
    $crit_text .= "Mobile Performance Score by Google : " . $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] ."\n";
  } else {
    $crit_text .= "Mobile Performance Score by Google : Not Available";
  }
} else {
  $crit_text .= "Mobile Performance Score by Google: <span style=\"color:white;\">" . $redirect_message . "</span><br>";
}

if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] != '' ) {
    $crit_text .= "Mobile Compatibility Score by Google : " . $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ]." ";
  } else {
    $crit_text .= "Mobile Compatibility Score by Google : Not Available";
  }
} else {
  $crit_text .= "Mobile Compatibility Score by Google: <span style=\"color:white;\">" . $redirect_message . "</span><br>";
}

dotgov_common_tooltip("tooltip4","id");
?>
<div class="col-xs-10">
    <h2 class="pane-title"> Mobile Information </h2>
</div>
<div class="col-xs-2 nopadding">
    <div id="tooltip4" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
        <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart.png" alt="Image for the color code"><br>
          <?php print nl2br($crit_text);?></span>
    </div>
</div>

<div class="col-lg-12 clearfix">
<?php
if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] == NULL ) {
    print "Mobile Performance Score: <a class=\"nostyle\" data-toggle=\"tooltip\" title=\"Scanning failed to return data for this component, so it is marked as Not Available\">Not Available</a><br>";
  } else {
    print "Mobile Performance Score: " . $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] . "<br>";
  }
} else {
  print "Mobile Performance Score: <span style=\"color:#a70000;\">" . $redirect_message . "</span><br>";
}

if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] == NULL ) {
    print "Mobile Usability Score: <a class=\"nostyle\" data-toggle=\"tooltip\" title=\"Scanning failed to return data for this component, so it is marked as Not Available\">Not Available</a><br>";
  } else {
    print "Mobile Usability Score: " . $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] . "<br>";
  }
} else {
  print "Mobile Usability Score: <span style=\"color:#a70000;\">" . $redirect_message . "</span><br>";
}
?>
</div>

<div class="col-lg-12 clearfix">
<?php
$blockObject = block_load('trend_analysis', 'trends_mobile_spark');
$block = _block_get_renderable_array(_block_render_blocks(array($blockObject)));
$output = drupal_render($block);

if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  print $output;
}
?>
</div>

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . $row->nid);
?>
<div class="col-lg-12 clearfix report-buttons" style="margin-top:10px;">
    <p>
        <a href="/improve-my-score">How to Improve Score</a>
    </p>
    <p>
        <a class="link-all-reports" href="/<?=$scanpath;?>">Go to Full Report</a>
        <a class="trend-analysis-reports link-all-reports" href="/historical_scan_score_data/<?=$row->nid;?>">Trend Analysis Report</a>
    </p>
</div>

<div class="sr-only">The graphic below indicates the level of Mobile score, and this score is <?php echo $chartdata; ?>%.</div>

<script type="text/javascript">
    Highcharts.chart('mobile_chart', {
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
                    text: '<?php echo (!isNullNotZero($chartdata) && $chartdata != -1 ? $chartdata : '<span style="font-size: 12px;">Not Available</span>'); ?>',
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