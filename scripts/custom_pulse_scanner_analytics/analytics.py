import requests, csv, sys

base = "https://api.gsa.gov/analytics/dap/v1.1/domain/"
route = "/reports/site/data?"
key = "api_key=CUluXOXEJqFO4Hqlt4YJpAlE8zua2rP3nUcIM2rZ"
param = "&limit=1"

CSV_URL = "https://raw.githubusercontent.com/cisagov/dotgov-data/main/current-federal.csv"

#to collect one domain, will print output but not save to csv
if len(sys.argv) == 2:
    domain = sys.argv[1].lower()
    url = base + domain + route + key + param #construct url
    response = requests.get(url, verify=False).text #sends request
    print(domain + " Participates in Dap: " + ("Yes\n" if "{\"id\":" in response else "No\n"))
#to collect all domains
else:
    #download csv file contents
    with requests.Session() as s:
        download = s.get(CSV_URL)
        decoded_content = download.content.decode('utf-8')
        cr = csv.reader(decoded_content.splitlines(), delimiter=',')
        my_list = list(cr)
        my_list.sort()

    #empty csv output file
    open("analytics.csv", "w").close()
    f=open("analytics.csv", "a+")
    f.write("Domain Name,Participates in Dap" + "\n")
    f.close()

    #process each domain in list
    for row in my_list:
        domain = row[0].lower() #convert domains to lowercase
        url = base + domain + route + key + param #construct url
        response = requests.get(url, verify=False).text #sends request

        #write result
        f=open("analytics.csv", "a+")
        f.write(domain + ",Yes\n" if "{\"id\":" in response else domain + ",No\n") #return if the domain is in dap or not
        f.close()
