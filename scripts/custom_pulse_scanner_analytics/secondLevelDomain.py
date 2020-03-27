import requests, csv, sys, urllib3
from datetime import datetime, timedelta
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

allDomains = "https://raw.githubusercontent.com/GSA/data/master/dotgov-domains/current-federal.csv" #source for domain list
data = []

#download csv file contents
with requests.Session() as s:
    download = s.get(allDomains)
    decoded_content = download.content.decode('utf-8')
    cr = csv.reader(decoded_content.splitlines(), delimiter=',')
    my_list = list(cr)
    my_list.sort()
n_list = [] #new list to include only executive agency domains
for row in my_list:
    if "Federal Agency - Executive".lower() == row[1].lower():
        n_list.append(row)
# print(n_list)

days_to_subtract = 10 #how many days back to go for scan, default is 10
limit = 100000 #limit of results return, default is 10000

date = (datetime.today() - timedelta(days=days_to_subtract)).strftime("%Y-%m-%d")
response = requests.get('https://api.gsa.gov/analytics/dap/v1.1/reports/second-level-domain/data?api_key=CUluXOXEJqFO4Hqlt4YJpAlE8zua2rP3nUcIM2rZ&after=' + date + '&limit=' + str(limit) + '', verify=False)
contents = response.text.replace('{', '\n{').replace('}]', '}\n]')
open("analyticsSecondLevelDomain.csv", 'w').close() #empty file
f = open("analyticsSecondLevelDomain.csv", mode='a')
f.write('"Domain","Base Domain","URL","Agency","Sources","Participates in DAP?"')
f.close()

#using source, check if domain present in list and write results to
for r in n_list:
    url = r[0].lower()
    with open('/tmp/pulsedap.csv', mode='a') as ana_csv:
        analytics_writer = csv.writer(ana_csv, delimiter=',', quotechar='"', quoting=csv.QUOTE_ALL)
        if "\"" + r[0].lower() + "\"" in contents:
            analytics_writer.writerow([url, url, "https://"+url, r[3], "dotgov", "Yes"])
        else:
            analytics_writer.writerow([url, url, "https://"+url, r[3], "dotgov", "No"])
