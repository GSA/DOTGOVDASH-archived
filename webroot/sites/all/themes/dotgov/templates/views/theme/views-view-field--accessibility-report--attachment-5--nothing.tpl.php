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

<?php //print $output;
?>
<div id="access_chart" style="width:560px;">&nbsp;</div>
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
	legend: {
                    enabled: true,
                    floating: true,
                 
                    
                    labelFormatter : function() { 
                        var total = 0, percentage; jQuery.each(this.series.data, function() { total+=this.y; });
                        percentage=((this.y/total)*100).toFixed(2); 
                        return this.name +'\xa0'+ this.y + '\xa0(<span style=\"color:'+this.color+'\">'+percentage+ '%</span>)'; 
                    }

            }, 
    tooltip: {
        pointFormat: '{series.name}: <b>{point.percentage:.1f}%</b>'
    },
    plotOptions: {
       pie: {
            allowPointSelect: true,
            cursor: 'pointer',
            dataLabels: {
                enabled: true
            },
		   showInLegend: true
		   
        }
    },
	
	
    series: [{
        name: 'Percentage',
        colorByPoint: true,
        data: [{
            name: 'Color Contrast Issues',
            y: <?php echo $row->field_data_field_accessible_group_colorcont_field_accessible;?>
        }, {
            name: 'HTML Attribute Issues',
            y: <?php echo $row->field_data_field_accessible_group_htmlattri_field_accessible;?>
           
        }, {
            name: 'Missing Image Description Issues',
            y: <?php echo $row->field_data_field_accessible_group_missingim_field_accessible; ?>
        }]
    }]
});
</script>
