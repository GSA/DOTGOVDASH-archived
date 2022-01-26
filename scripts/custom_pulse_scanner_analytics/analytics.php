<?php
$allDomains = file("https://raw.githubusercontent.com/cisagov/dotgov-data/main/current-federal.csv");
$data = [];
foreach ($allDomains as $line) {
  $data = str_getcsv($line);
  if($data[1] == "Federal Agency - Executive"){
    $domainname = strtolower($data[0]);
    $alldomains[]= $domainname;
    $alldomain_agency[$domainname] = $data[3];
    //	print $domainname."\n";
  }
}
$alldomains = array_unique($alldomains);
//print "\n".count($alldomains)."\n";
$json = file_get_contents("https://api.gsa.gov/analytics/dap/v1.1/reports/second-level-domain/data?api_key=CUluXOXEJqFO4Hqlt4YJpAlE8zua2rP3nUcIM2rZ&after=2020-02-01&limit=10000");
$domArr = json_decode($json);
foreach($domArr as $key=>$val){
  $domainNames[] = trim($val->domain);
  //print $val->domain."\n";
}
$domainNames = array_unique($domainNames);
print "\n".count($domainNames)."\n";
print '"Domain","Base Domain","URL","Agency","Sources","Participates in DAP?"';
print "\n";
foreach($alldomains as $key=>$val){
  $domurl = "https://".$val;
  if(in_array($val,$domainNames)){
    print "\"".$val."\",\"".$val."\",\"".$domurl."\",\"".$alldomain_agency[$val]."\",\"dotgov\",\"Yes\" \n";
  }
  else{
    print "\"".$val."\",\"".$val."\",\"".$domurl."\",\"".$alldomain_agency[$val]."\",\"dotgov\",\"No\" \n";
  }
}
?>
