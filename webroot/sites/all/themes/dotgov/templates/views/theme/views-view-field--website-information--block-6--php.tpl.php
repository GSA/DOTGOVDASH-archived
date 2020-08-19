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
  if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] == "" || $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] === NULL) {
    $crit_text .= "Mobile Performance: Not Available\n";
  } else if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] < 50 ) {
    $crit_text .= "Mobile Performance: Poor\n";
  } else if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] < 90 ) {
    $crit_text .= "Mobile Performance: Needs Improvement\n";
  } else {
    $crit_text .= "Mobile Performance Good";
  }
} else {
  $crit_text .= "Mobile Performance: <span style=\"color:white;\">" . $redirect_message . "</span><br>";
}

if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] === "" || $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] === NULL) {
    $crit_text .= "Mobile Usability: Not Available";
  } else if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] == 100) {
    $crit_text .= "Mobile Usability: Mobile Friendly";
  } else {
    $crit_text .= "Mobile Usability: Not Mobile Friendly";
  }
} else {
  $crit_text .= "Mobile Usability: <span style=\"color:white;\">" . $redirect_message . "</span><br>";
}

dotgov_common_tooltip("tooltip4","id");
?>
<div class="col-xs-10">
    <h2 class="pane-title"> Mobile Information </h2>
</div>
<div class="col-xs-2 nopadding" style="z-index: 3;">
    <div id="tooltip4" class="infor"><i class='icon glyphicon glyphicon-info-sign'>&nbsp;</i>
        <span class="tooltiptext tooltip-left"><img src="/sites/all/themes/dotgov/images/helpchart_mobile.png" alt="Image for the color code"><br>
          <?php print nl2br($crit_text);?></span>
    </div>
</div>

<div class="col-lg-12 clearfix">
<?php
$chart_data_font = "7.5px";
$performance_title = "Mobile Performance";
$usability_title = "Mobile Usability";
if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] == "" || $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] === NULL) {
    $performance_chart_data_text = "Not Available";
    $performance_chart_color = "#ac0600";
  } else if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] < 50 ) {
    $performance_chart_data_text = "Poor";
    $performance_chart_color = "#ac0600";
  } else if ( $row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ] < 90 ) {
    $performance_chart_data_text = "Needs Improvement";
    $performance_chart_color = "#654f00";
  } else {
    $performance_chart_data_text = "Good";
    $performance_chart_color = "#29643a";
  }
  $performance_chart_data = intval($row->field_field_mobile_performance_score[ '0' ][ 'raw' ][ 'value' ]);
  print "$performance_title: $performance_chart_data_text<br>";
} else {
  print "$performance_title: <span style=\"color:#a70000;\">" . $redirect_message . "</span><br>";
}

if (!is_redirect($row->field_field_website_id[0]['raw']['nid'])) {
  if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] === "" || $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] === NULL) {
    $usability_chart_data_text = "Not Available";
    $usability_chart_data = "0";
    $usability_chart_color = "#ac0600";
  } else if ( $row->field_field_mobile_usability_score[ '0' ][ 'raw' ][ 'value' ] == 100) {
    $usability_chart_data_text = "Mobile Friendly";
    $usability_chart_data = "100";
    $usability_chart_color = "#29643a";
  } else {
    $usability_chart_data_text = "Not Mobile Friendly";
    $usability_chart_data = "0";
    $usability_chart_color = "#ac0600";
  }
  print "$usability_title: $usability_chart_data_text";
} else {
  print "$usability_title: <span style=\"color:#a70000;\">" . $redirect_message . "</span><br>";
}
?>
</div>

<?php if (!is_redirect(arg(1))): ?>
<div class="col-lg-12 clearfix">
  <div class="col-lg-6" style="left: 50px;">

  </div>
  <div class="col-lg-6" style="left: 60px;">
  </div>
</div>
<?php endif; ?>
<div class="col-lg-12 clearfix" style="min-height: 210px;">
  <?php if (!is_redirect(arg(1))): ?>
    <div class="col-lg-6">
        <div id="performance_chart" style="width: 140px; height:140px; margin: 0 auto">&nbsp;</div>
        <p class="text-center" style="color: #1c5295; font-size: 17px;"><?php echo($performance_title); ?></p>
    </div>
    <div class="col-lg-6">
        <div id="usability_chart" style="width: 140px; height:140px; margin: 0 auto">&nbsp;</div>
        <p class="text-center" style="color: #1c5295; font-size: 17px;"><?php echo($usability_title); ?></p>
    </div>
  <?php endif; ?>
</div>

<?php
$scanids = dotgov_common_siteAsocScanids(arg(1));
$scanpath = drupal_get_path_alias("node/" . $row->nid);
?>
<div class="col-lg-12 clearfix report-buttons" style="margin-top: 0px;">
    <p>
        <a href="/improve-my-score">How to Improve Score</a>
    </p>
    <p>
        <a class="link-all-reports" href="/<?=$scanpath;?>">Go to Full Report</a>
        <a class="trend-analysis-reports link-all-reports" href="/historical_scan_score_data/<?=arg(1);?>">Trend Analysis Report</a>
    </p>
</div>

<div class="sr-only">The graphic below indicates the level of Mobile score, and this score is <?php echo $chartdata; ?>%.</div>

<script type="text/javascript">
    Highcharts.chart('performance_chart', {
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
                    text: '<?php echo ($performance_chart_data_text); ?>',
                    style: {
                        fontSize: '<?=$chart_data_font?>',
                        color:'<?php echo $performance_chart_color; ?>',
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
                name: 'Mobile Performance',
                data: [{
                    color: '<?php echo $performance_chart_color; ?>',
                    radius: '118%',
                    innerRadius: '80%',
                    y:<?=$performance_chart_data?>
                }]
            }]
        }
    );
    Highcharts.chart('usability_chart', {
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
                    text: '<?php echo ($usability_chart_data_text); ?>',
                    style: {
                        fontSize: '<?=$chart_data_font?>',
                        color:'<?php echo $usability_chart_color; ?>',
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
                name: '<?php echo ($usability_chart_data_text); ?>',
                data: [{
                    color: '<?php echo $usability_chart_color; ?>',
                    radius: '118%',
                    innerRadius: '80%',
                    y:<?=$usability_chart_data?>
                }]
            }]
        }
    );
</script>
