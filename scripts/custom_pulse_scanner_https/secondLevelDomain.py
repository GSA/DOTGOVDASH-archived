import requests, csv, sys

response = requests.get('https://api.gsa.gov/analytics/dap/v1.1/reports/second-level-domain/data?api_key=CUluXOXEJqFO4Hqlt4YJpAlE8zua2rP3nUcIM2rZ&after=2020-02-01', verify=False)
contents = response.text.replace('{', '\n{').replace('}]', '}\n]')
CSV_URL = "https://raw.githubusercontent.com/GSA/data/master/dotgov-domains/current-federal.csv" #source for domain list
#download csv file contents
with requests.Session() as s:
    download = s.get(CSV_URL)
    decoded_content = download.content.decode('utf-8')
    cr = csv.reader(decoded_content.splitlines(), delimiter=',')
    my_list = list(cr)
    my_list.sort()
open("analyticsSecondLevelDomain.csv", 'w').close()

#using source, check if domain present in list and write results to
for r in my_list:
    with open('analyticsSecondLevelDomain.csv', mode='a') as ana_csv:
        analytics_writer = csv.writer(ana_csv, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        if "\"" + r[0].lower() + "\"" in contents:
            analytics_writer.writerow([r[0], "True"])
        else:
            analytics_writer.writerow([r[0], "False"])
