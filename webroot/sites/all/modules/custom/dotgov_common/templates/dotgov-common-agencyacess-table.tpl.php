
<!--
<link rel="stylesheet" type="text/css" href="/css/result-light.css">

<link rel="stylesheet" type="text/css" href="https://code.jquery.com/ui/1.9.2/themes/base/jquery-ui.css">
<link rel="stylesheet" type="text/css" href="//cdn.datatables.net/1.10.1/css/jquery.dataTables.css">
<script type="text/javascript" src="//cdn.datatables.net/1.10.1/js/jquery.dataTables.min.js"></script>
<link rel="stylesheet" type="text/css" href="//cdn.datatables.net/responsive/1.0.0/css/dataTables.responsive.css">-->
<script src="//cdn.datatables.net/1.10.19/js/jquery.dataTables.min.js"></script>

<script src="//cdn.datatables.net/1.10.19/js/dataTables.bootstrap.min.js"></script>
<script src="//cdn.datatables.net/buttons/1.5.2/js/dataTables.buttons.min.js"></script>
<script src="//cdn.datatables.net/buttons/1.5.2/js/buttons.bootstrap.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/jszip/3.1.3/jszip.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/pdfmake.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/vfs_fonts.js"></script>
<script src="//cdn.datatables.net/buttons/1.5.2/js/buttons.html5.min.js"></script>
<script src="//cdn.datatables.net/buttons/1.5.2/js/buttons.print.min.js"></script>
<script src="//cdn.datatables.net/buttons/1.5.2/js/buttons.colVis.min.js"></script>

<style type="text/css">
   .dataTables_filter {
	width: 50%;
	float: right;
	text-align: right;
}
</style>
<!-- TODO: Missing CoffeeScript 2 -->
<script type="text/javascript">


    
        jQuery(document).ready(function() {
             jQuery('#agency_acc_table').DataTable( {
                responsive: true,
                paging: false,
dom: '<"toolbar">Bfrtip',
        buttons: [
             {extend:'csv', text:'csv'}, {extend:'excel',text:'xls'}
        ]
            } );

jQuery("div.toolbar").html('Download Agency Level Accessibility Report:');
jQuery("div.toolbar").css('float','left');
        } );


</script>
<div class="table-responsive white-back">
    <div class="col-lg-12 col-sm-12 col-xs-12 nopadding" style="margin-bottom:15px;">

    </div>


    <table width="100%" class="display datatables-processed dataTable table table-hover table-striped white-back" id="agency_acc_table" cellspacing="0">
        <thead>
        <tr>
            <th>Agency</th>
            <th>Number of Websites</th>
            <th>Average Color Contrast Issues</th>
            <th>Average HTML Attribute Issues</th>
            <th>Average Missing Image Issues</th>
        </tr>
        </thead>
        <tbody>
        <?php
        foreach($govwidedata['actualdata'] as $key=>$val){
            if(trim($val['agencyname']) != "") {
                print "<tr><td><a href='/agency_home/" . $key . "'>" . $val['agencyname'] . "</a></td>";
                print "<td>" . $val['websitenos'] . "</td>";
                print "<td>" . (($val['colorcontr_avg'] != '') ? number_format($val['colorcontr_avg'], 1) : 0) . "</td>";
                print "<td>" . (($val['htmlattr_avg'] != '') ? number_format($val['htmlattr_avg'], 1) : 0) . "</td>";
                print "<td>" . (($val['missingimg_avg'] != '') ? number_format($val['missingimg_avg'], 1) : 0) . "</td>";
                print "</tr>";
            }
        }

        ?>
        </tr>
        </tbody>
    </table>
</div>

