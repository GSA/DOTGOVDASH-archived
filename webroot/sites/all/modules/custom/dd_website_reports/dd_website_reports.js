(function($) {
Drupal.behaviors.myBehavior = {
  attach: function (context, settings) {
	  
	//enable accordion for all the tables
	$(".view-all-website-reports-new.view-display-id-page_1 .view-content").accordion( { collapsible: true } ); 

    //read more functionality for each table
	var read_more_length = 20;
    $('.view-all-website-reports-new.view-display-id-page_1 .view-content table').each(function(counter){
        var rowCount =  jQuery('tr', this).length;
		if(rowCount > read_more_length ) {
		  jQuery(this).find('tr:gt('+read_more_length+')').hide();
		  jQuery(this).after( "<div class='text-center'><a data-id='"+counter+"' href='#' class='load-more-results'>Load More Results</a></div>" );
		  jQuery(this).after( "<div class='table-"+counter+" text-center results-count'>Showing <span class='current-length'>"+ read_more_length +"</span> of "+ (rowCount-1) +" sites</div>" );
		}	
		counter = counter + 1;
		
    });
	
	jQuery('.load-more-results').click(function(e){
		e.preventDefault();
		//get the number of hidden rows in the table
		var total_rows = jQuery(this).parent().parent().find('tr').length;
		var no_of_hidden_rows = jQuery(this).parent().parent().find('tr').not(':visible').length;
		var no_of_visible_rows = jQuery(this).parent().parent().find('tr:visible').length;
		var no_of_rows_to_show = no_of_visible_rows + read_more_length;
		jQuery(this).parent().parent().find('tr:lt('+no_of_rows_to_show+')').show();
		var elementId = jQuery(this).data('id');
		if(no_of_rows_to_show >=  total_rows ) {
			jQuery('.table-'+elementId+' .current-length').text((total_rows-1));
			jQuery(this).hide();
		}else {
			jQuery('.table-'+elementId+' .current-length').text((no_of_rows_to_show - 1));
		}

	});


  }
};
})(jQuery);
