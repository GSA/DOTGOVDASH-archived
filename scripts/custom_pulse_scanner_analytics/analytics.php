<?php
#$allDomains_main = file("https://raw.githubusercontent.com/cisagov/dotgov-data/main/current-federal.csv");
#$allDomains_army = file("https://b81c0de9f2cd4c6a090c2882f5f7e3e70bbf003d@raw.githubusercontent.com/GSA/DOTGOVDASH/master/custom_domains.csv");
#$allDomains = array_merge($allDomains_main, $allDomains_army);
$allDomains = file("/tmp/current-federal.csv");
$data = [];
foreach ($allDomains as $line) {
  $data = str_getcsv($line);
  if($data[1] == "Federal - Executive"){
    $domainname = strtolower($data[0]);
//For army domains forcibly append www
  $domainname = str_replace("www.","",$domainname);
    $alldomains[]= $domainname;
    $alldomain_agency[$domainname] = $data[3];
    //	print $domainname."\n";
  }
}
$alldomains = array_unique($alldomains);
//print "\n".count($alldomains)."\n";
$date = date("Y-m-d");
$querydate = date("Y-m-d",strtotime(date("Y-m-d", strtotime($date)) . " -15 days"));
$json = file_get_contents("https://api.gsa.gov/analytics/dap/v1.1/reports/second-level-domain/data?api_key=CUluXOXEJqFO4Hqlt4YJpAlE8zua2rP3nUcIM2rZ&after=".$querydate."&limit=100000");
#print $json;
$domArr = json_decode($json);
foreach($domArr as $key=>$val){
  $domval = str_replace("www.","",$val->domain);
  #print $domval."\n";
  $domainNames[] = trim($domval);
  //print $val->domain."\n";
}
$domainNames = array_unique($domainNames);
#print "\n".count($domainNames)."\n";
print '"Domain","Base Domain","URL","Agency","Sources","Participates in DAP?"';
print "\n";
foreach($alldomains as $key=>$val){
  if(strpos($val,".mil") !== false){
   if(strpos($val,"www.") === false)
    $domainname = "www.".$val;
   else
    $domainname = $val;
  }
  else
    $domainname = $val;
  $domurl = "https://".$domainname;

  if(in_array($val,$domainNames)){
    print "\"".$domainname."\",\"".$domainname."\",\"".$domurl."\",\"".$alldomain_agency[$val]."\",\"dotgov\",\"Yes\"\n";
  }
  else{
    print "\"".$domainname."\",\"".$domainname."\",\"".$domurl."\",\"".$alldomain_agency[$val]."\",\"dotgov\",\"No\"\n";
  }
}
?>
