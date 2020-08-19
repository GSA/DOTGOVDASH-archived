<link rel="stylesheet" type="text/css" href="/css/result-light.css">

<link rel="stylesheet" type="text/css" href="https://code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
<script type="text/javascript" src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/1.10.13/js/jquery.dataTables.min.js"></script>
<style type="text/css">

</style>
<!-- TODO: Missing CoffeeScript 2 -->

<script type="text/javascript">
    window.onload=function(){
        $(document).ready(function(){
            $.fn.dataTable.ext.search.push(
                function (settings, data, dataIndex) {
                    var min = $('#min').datepicker("getDate");
                    var max = $('#max').datepicker("getDate");
                    var startDate = new Date(data[1]);
                    if (min == null && max == null) { return true; }
                    if (min == null && startDate <= max) { return true;}
                    if(max == null && startDate >= min) {return true;}
                    if (startDate <= max && startDate >= min) { return true; }
                    return false;
                }
            );

            $("#min").datepicker({ onSelect: function () { table.draw(); }, changeMonth: true, changeYear: true });
            $("#max").datepicker({ onSelect: function () { table.draw(); }, changeMonth: true, changeYear: true });
            var table = $('#trendtable').DataTable(
               { "order": [[ 1, "desc" ]] }
);

            // Event listener to the two range filtering inputs to redraw on input
            $('#min, #max').change(function () {
                table.draw();
            });
        });

    }

</script>
<body>
<p><a href="/trend_analysis/<?php print $trend_vars['website_id_nid'];?>">Click Here to View Historical Data in Graph</a></p>
<div class="table-responsive">
<div class="col-lg-12 col-sm-12 col-xs-12 nopadding" style="margin-bottom:15px;">
<form>
  <div class= "col-lg-12 col-xs-12 nopadding" style="margin-bottom:15px;">
    <label for="min" style="margin-right:10px;"> Start Date:</label>
	<input name="min" id="min" type="text">
  </div>
  <div class= "col-lg-12 col-xs-12 nopadding" style="margin-bottom:15px;">
	  <label for="max" style="margin-right:16px;">End Date:</label>
	  <input name="max" id="max" type="text">
  </div>
  <div class= "col-lg-12 col-xs-12 nopadding">
    <button type="button" id="edit-submit-historical-content-summary" name="" value="Apply" class="btn btn-info form-submit">Apply</button>
    <button type="submit" id="edit-reset" name="op" value="Reset" class="btn btn-default form-submit">Reset</button>
  </div>
</form>
</div>

<table width="100%" class="display white-back views-table cols-13 table table-hover table-striped" id="trendtable" cellspacing="0">
    <thead>
    <?php if($trend_vars['is_mobile_scan'] === true): ?>
        <tr>
            <th>Website</th>
            <th>Updated Date</th>
            <th>Mobile Usability Status</th>
            <th>Mobile Performance Status</th>
        </tr>
    <?php else: ?>
        <tr>
            <th>Website</th>
            <th>Updated Date</th>
            <th>DAP Score</th>
            <th>DNSSEC Score</th>
            <th>Free of RC4/3DES and SSLv2/SSLv3 score</th>
            <th>HTTPS score</th>
            <th>IPv6  Score</th>
            <th>M-15-13 and BOD 18-01 Compliance Score</th>
            <th>Site Speed Score</th>
            <th>SSL Score</th>
            <th>Mobile Usability Status</th>
            <th>Mobile Performance Status</th>
        </tr>
    <?php endif; ?>
    </thead>
    <tbody>
    <?php
    foreach($trend_vars['trend_arr'] as $key=>$val) {
        print "<tr><td>".$trend_vars['trend_title']."</td>";
        print "<td>".$key."</td>";
        if($trend_vars['is_mobile_scan'] === true) {
            if(!isset($val['mobile_usability_stat']) || ($val['mobile_usability_stat'] == '') || ($val['mobile_usability_stat'] == NULL)){
                print "<td>Not Available</td>";
            }
            else{
                print "<td>".$val['mobile_usability_stat']."</td>";
            }

            if(!isset($val['mobile_perf_stat']) || ($val['mobile_perf_stat'] == '') || ($val['mobile_perf_stat'] == NULL)){
                print "<td>Not Available</td>";
            }
            else{
                print "<td>".$val['mobile_perf_stat']."</td>";
            }

            print "</tr>";
        } else {
            if(!isset($val['dap']) || ($val['dap'] == '') || ($val['dap'] == NULL)){
                print "<td>Not Available</td>";
            }
            else{
                print "<td>".$val['dap']."</td>";
            }

            if(!isset($val['dnssec']) || ($val['dnssec'] == '') || ($val['dnssec'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['dnssec']."</td>";
            }

            if(!isset($val['insec']) || ($val['insec'] == '') || ($val['insec'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['insec']."</td>";
            }

            if(!isset($val['https']) || ($val['https'] == '') || ($val['https'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['https']."</td>";
            }

            if(!isset($val['ipv6']) || ($val['ipv6'] == '') || ($val['ipv6'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['ipv6']."</td>";
            }

            if(!isset($val['m15']) || ($val['m15'] == '') || ($val['m15'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['m15']."</td>";
            }

            if(!isset($val['sitespeed']) || ($val['sitespeed'] == '') || ($val['sitespeed'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['sitespeed']."</td>";
            }

            if(!isset($val['ssl']) || ($val['ssl'] == '') || ($val['ssl'] == NULL)){
            print "<td>Not Available</td>";
            }
            else{
            print "<td>".$val['ssl']."</td>";
            }

            if(!isset($val['mobile_usability_stat']) || ($val['mobile_usability_stat'] == '') || ($val['mobile_usability_stat'] == NULL)){
                print "<td>Not Available</td>";
            }
            else{
                print "<td>".$val['mobile_usability_stat']."</td>";
            }

            if(!isset($val['mobile_perf_stat']) || ($val['mobile_perf_stat'] == '') || ($val['mobile_perf_stat'] == NULL)){
                print "<td>Not Available</td>";
            }
            else{
                print "<td>".$val['mobile_perf_stat']."</td>";
            }
            print "</tr>";
        }
    }
    ?>
    </tbody>
</table>
</div>
