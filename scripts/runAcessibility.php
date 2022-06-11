<?php
//Output of this script should go to /tmp/results/a11y.csv
$domainlist = "/tmp/domainslist.csv";
echo "Domain,Base Domain,redirectedTo,typeCode,code,message,context,selector \n";

 $first = false;
    if (($handle = fopen($domainlist, "r")) !== FALSE) {
        while (!feof($handle)) {
            $data = fgetcsv($handle);
//Uncomment below lines to ignore first line
/*
            if (!$first) {
                $first = true;
                continue;
            }
*/
if(trim($data[0]) != ''){
$domain = "https://".strtolower($data[0]);
#shell_exec("timeout 15  docker run --rm dcycle/pa11y:1  --runner htmlcs --runner axe --ignore 'warning;notice' --reporter csv ".$domain."  |tail -n +2 >> access.csv");
//Actual command output comes as 
exec("timeout 15  docker run --rm dcycle/pa11y:1  --runner htmlcs --runner axe --ignore 'warning;notice' --reporter csv ".$domain."  |tail -n +2",$output);
foreach($output as $key=>$val){
print "$data[0],$data[0],$data[0],1,$val\n";
}
        }
}
        fclose($handle);

    }
//Sql query that works for above output
//LOAD DATA LOCAL INFILE '/web/e04tcm-dtgvscan.ent.ds.gsa.gov/html_newscan/webroot/access.csv' INTO TABLE csk FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' LINES TERMINATED BY '\n' (@website,@base_domain, @domain_redirected_to,@error_typecode,@err_type,@error_code,@error_message,@error_context,@error_selector) set website=@website,base_domain=@base_domain, domain_redirected_to=@domain_redirected_to,error_typecode=@error_typecode,error_code=@error_code,error_message=@error_message,error_context=@error_context,error_selector=@error_selector;
?>
