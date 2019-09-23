<div class="<?php print $classes; ?>">  
  <?php if ($rows): ?>
    <div class="view-content">
		<?php $pviewTitle = trim(check_plain($view->get_title())); ?>  
		<?php  $pdata = $view->style_plugin->render_fields($view->result); ?>  
		<?php
		$piearr = array();
		foreach($pdata as $key=>$val){
			// list($nameKey, $versionKey) = explode('_', $val['field_cdn_applications']);	
			$part = explode('_', $val['field_cdn_applications']);
			$nameKey = @$part[0];
			if(isset($nameKey) && !empty($nameKey)){
				if (isset($piearr[$nameKey]) && !empty($piearr[$nameKey])) {
					//$piearr[$nameKey] += $val['field_cdn_applications_1'];
				}else{
					$piearr[$nameKey] = $val['field_cdn_applications_1'];
				}
			}
		}
		?>
		<div id="cdn_applications" class="gov-wide-chart" style="">&nbsp;</div>
		<script type="text/javascript">
		Highcharts.chart('cdn_applications', 
		{
		  "chart": {"type": "pie","style": {"fontFamily": "Arial","fontSize": 12},"backgroundColor": "transparent"},
		  "title": {"text": "","style": {"color": "#000","fontWeight": "normal","fontStyle": "normal","fontSize": 14}},
		  "colors": ["#2f7ed8","#0d233a","#8bbc21","#910000","#1aadce","#492970","#f28f43","#77a1e5","#c42525","#a6c96a"],
		  "plotOptions": {"series": {"dataLabels": {"enabled": false}},"pie": {"dataLabels": {"distance": -30,"color": "white","format": "{percentage:.1f}%"}}},
		  "tooltip": {"enabled": true,"useHTML": false,"pointFormat": "<b>{point.y} ({point.percentage:.1f}%)</b><br/>"},
		  "legend": {"enabled": true,"title": {"text": "<?php echo $pviewTitle; ?>","style": {"fontWeight": "bold","fontStyle": "normal"}},"verticalAlign": "bottom","layout": "horizontal","itemStyle": {"fontWeight": "normal","fontStyle": "normal"}},
		  "credits": {"enabled": false},
		  "series": [{"name": "<?php echo $pviewTitle; ?>","marker": {"radius": 3},
		      "showInLegend": true,
		      "connectNulls": true,
		      "tooltip": [],
		      "data": [
		        <?php foreach ($piearr as $name => $cnt) { ?>
		        		{ name: '<?php echo $name; ?>', y: <?php echo $cnt; ?> },         	
		        <?php }?>
		      ]
		    }
		  ]
		});
		</script>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
</div><?php /* class view */ ?>