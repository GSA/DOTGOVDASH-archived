import csv
import os
from pathlib import Path
import logging
import time
import sys
import argparse
from pathlib import Path
import requests
import re
import base64
import json
import logging


def process_pshtt_data(pshtt_row, sslyze_row):
    parameter_list = {'Domain': None, 'Base Domain': None, 'URL': None, 'SSLv2': None,
                      'SSLv3': None, 'Enforces HTTPS': None, 'hsts': None,
                      'cipherfree': None, 'M-15-13 and BOD 18-01': None,
                      '3DES': None, 'RC4': None, 'Preloaded': None}

    print("Processing data from pshtt.csv and sslyze.csv")

    if pshtt_row is not None:
        m1513 = None
        parameter_list['Domain'] = pshtt_row['Domain']
        searchdomain = "\"" + pshtt_row['Domain'] + "\""
        parameter_list['Base Domain'] = pshtt_row['Base Domain']
        parameter_list['URL'] = pshtt_row['Canonical URL']
        with open('./results/preloaded.txt') as preloaded_file:

            preloaded_data = preloaded_file.read()
            if searchdomain in preloaded_data:
                print('HSTS PRELOADED VALUE CHANGED')
                pshtt_row['HSTS Preloaded'] = "True"
            if pshtt_row['Live'] == 'True':

                print("--------------**********---------------")
                # HSTS age
                if pshtt_row["HSTS Max Age"]:
                    hsts_age = int(pshtt_row["HSTS Max Age"])
                else:
                    hsts_age = None
                # Characterize the presence and completeness of HSTS.
                # assumes that HTTPS would be technically present, with or without issues
                if pshtt_row["Downgrades HTTPS"] == "True":
                    https = 0  # No
                else:
                    if pshtt_row["Valid HTTPS"] == "True":
                        https = 2  # Yes
                    elif pshtt_row["HTTPS Bad Chain"] == "True" and pshtt_row["HTTPS Bad Hostname"] == "False":
                        https = 1  # Yes
                    else:
                        https = -1  # No

                uses_https = https
            # "Yes (Strict)" means HTTP immediately redirects to HTTPS,
            # *and* that HTTP eventually redirects to HTTPS.
            #
            # Since a pure redirector domain can't "default" to HTTPS
            # for itself, we'll say it "Enforces HTTPS" if it immediately
            # redirects to an HTTPS URL.

            # Is HTTPS enforced?
                if uses_https <= 0:
                    behavior = 0  # N/A

                else:
                    if pshtt_row["Strictly Forces HTTPS"] == "True" and (pshtt_row["Defaults to HTTPS"] == "True" or pshtt_row["Redirect"] == "True"):
                        behavior = 3  # Yes (Strict)

                    # "Yes" means HTTP eventually redirects to HTTPS
                    elif pshtt_row["Strictly Forces HTTPS"] == "False" and pshtt_row["Defaults to HTTPS"] == "True":
                        behavior = 2  # Yes

                    # Either both are False, or just 'Strict Force' is True,
                    # which doesn't matter on its own.
                    # A "present" is better than a downgrade.
                    else:
                        behavior = 1  # Present (considered 'No')

                if behavior == 2:
                    parameter_list['Enforces HTTPS'] = 'Yes'
                elif behavior == 3:
                    parameter_list['Enforces HTTPS'] = 'Yes'
                else:
                    parameter_list['Enforces HTTPS'] = 'No'

                #  Otherwise, without HTTPS there can be no HSTS for the domain directly.
                if https <= 0:
                    hsts = -1  # N/A (considered 'No')
                    bod_crypto = -1
                # HSTS is present for the canonical endpoint.
                else:
                    if pshtt_row["HSTS"] == "True" and hsts_age:
                        # Say No for too-short max-age's, and note in the extended details.
                        if hsts_age >= 31536000:
                            hsts = 2  # Yes, directly
                        else:
                            hsts = 1  # No

                    else:
                        hsts = 0  # No
                # deciding if hsts is yes or no
                if hsts == 2:
                    parameter_list['hsts'] = 'Yes'
                else:
                    parameter_list['hsts'] = 'No'

                # Separate preload status from HSTS status:
                # * Domains can be preloaded through manual overrides.
                # * Confusing to mix an endpoint-level decision with a domain-level decision.
                # Final calculation: is the service compliant with all of M-15-13
                # (HTTPS+HSTS) and BOD 18-01 (that + RC4/3DES/SSLv2/SSLv3)?

                # For M-15-13 compliance, the service has to enforce HTTPS,
                # and has to have strong HSTS in place (can be via preloading)

                m1513 = (behavior >= 2) and (hsts >= 2)

                if sslyze_row is None:

                    bod_crypto = -1

                else:

                    if sslyze_row['Any RC4'] == 'True':
                        parameter_list['RC4'] = 'Yes'
                        print("testing sslyze")
                    elif sslyze_row['Any RC4'] == 'False':
                        parameter_list['RC4'] = 'No'
                    else:
                        parameter_list['RC4'] = None
                    if sslyze_row['Any 3DES'] == 'True':
                        parameter_list['3DES'] = 'Yes'
                    elif sslyze_row['Any 3DES'] == 'False':
                        parameter_list['3DES'] = 'No'
                    else:
                        parameter_list['3DES'] = None
                    if sslyze_row['SSLv2'] == 'True':
                        parameter_list['SSLv2'] = 'Yes'
                    elif sslyze_row['SSLv2'] == 'False':
                        parameter_list['SSLv2'] = 'No'
                    else:
                        parameter_list['SSLv2'] = None
                    if sslyze_row['SSLv3'] == 'True':
                        parameter_list['SSLv3'] = 'Yes'
                    elif sslyze_row['SSLv3'] == 'False':
                        parameter_list['SSLv3'] = 'No'
                    else:
                        parameter_list['SSLv3'] = None

                    # complaint to bodcrypto, m1513 and free of rc4, 3des, sslv2, sslv3
                    # N/A if no HTTPS
                    if parameter_list['RC4'] == 'Yes' or parameter_list['3DES'] == 'Yes' or parameter_list['SSLv2'] == 'Yes' or parameter_list['SSLv3'] == 'Yes':
                        bod_crypto = 0
                        parameter_list['cipherfree'] = 'No'
                    elif parameter_list['RC4'] == 'No' or parameter_list['3DES'] == 'No' or parameter_list['SSLv2'] == 'No' or parameter_list['SSLv3'] == 'No':
                        bod_crypto = 1
                        parameter_list['cipherfree'] = 'Yes'
                    else:
                        bod_crypto = 1
                        parameter_list['cipherfree'] = None

                # For BOD compliance, only ding if we have scan data:
                # * If our scanner dropped, give benefit of the doubt.
                # * If they have no HTTPS, this will fix itself once HTTPS comes on.
                bod1801 = m1513 and (bod_crypto != 0)

                compliant = bod1801  # equivalent, since BOD is a superset
                if compliant is True:
                    parameter_list['M-15-13 and BOD 18-01'] = 'Yes'
                elif compliant is False:
                    parameter_list['M-15-13 and BOD 18-01'] = 'No'
                else:
                    parameter_list['M-15-13 and BOD 18-01'] = compliant

            else:
                print("Website does not have any live end points, not eligible fot hsts/https")
                print(pshtt_row['Live'])

    # Preloaded or not

            if pshtt_row["HSTS Preloaded"] == "True":
                parameter_list['Preloaded'] = 'Yes'
            elif pshtt_row["HSTS Preload Ready"] == "True":
                parameter_list['Preloaded'] = 'Ready'
            else:
                parameter_list['Preloaded'] = 'No'

    else:
        print('pshtt.csv file is empty')

    return parameter_list


def load_preload_list():
  preload_json = None

  # Downloads the chromium preloaded domain list and sets it to a global set
  file_url = 'https://chromium.googlesource.com/chromium/src/net/+/master/http/transport_security_state_static.json?format=TEXT'

  try:
    request = requests.get(file_url)
  except (requests.exceptions.SSLError, requests.exceptions.ConnectionError) as err:
    logging.exception('Failed to fetch preload list: {}'.format(file_url))
    logging.debug('{}'.format(err))
    return []

  raw = request.content

  # To avoid parsing the contents of the file out of the source tree viewer's
  # HTML, we download it as a raw file. googlesource.com Base64-encodes the
  # file to avoid potential content injection issues, so we need to decode it
  # before using it. https://code.google.com/p/gitiles/issues/detail?id=7
  raw = base64.b64decode(raw).decode('utf-8')

  # The .json file contains '//' comments, which are not actually valid JSON,
  # and confuse Python's JSON decoder. Begone, foul comments!
  raw = ''.join([re.sub(r'^\s*//.*$', '', line)
                 for line in raw.splitlines()])

  preload_json = json.loads(raw)

  # For our purposes, we only care about entries that includeSubDomains
  fully_preloaded = []
  for entry in preload_json['entries']:
    if entry.get('include_subdomains', False) is True:
      fully_preloaded.append(entry['name'])

  return fully_preloaded


# loading data to https csv
def load_https_data(agencies, parameter_list):
    domain = parameter_list['Domain']
    print("loading data to https_scan.csv")
    with open('https_scan.csv', mode='a') as csv_file:
        row_data = {'Domain': parameter_list['Domain'], 'Base Domain': parameter_list['Base Domain'],
                    'URL': parameter_list['URL'], 'SSLv2': parameter_list['SSLv2'],
                    'SSLv3': parameter_list['SSLv3'], 'Enforces HTTPS': parameter_list['Enforces HTTPS'],
                    'Strict Transport Security (HSTS)':  parameter_list['hsts'],
                    'Agency': agencies, 'Sources': 'dotgov',
                    'Free of RC4/3DES and SSLv2/SSLv3': parameter_list['cipherfree'],
                    'Compliant with M-15-13 and BOD 18-01': parameter_list['M-15-13 and BOD 18-01'],
                    '3DES': parameter_list['3DES'], 'RC4': parameter_list['RC4'],
                    'Preloaded': parameter_list['Preloaded']}
        fieldnames = ['Domain', 'Base Domain',
                      'URL', 'Agency', 'Sources',
                      'Compliant with M-15-13 and BOD 18-01',
                      'Enforces HTTPS',
                      'Strict Transport Security (HSTS)',
                      'Free of RC4/3DES and SSLv2/SSLv3',
                      '3DES', 'RC4', 'SSLv2', 'SSLv3',
                      'Preloaded']
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

        if csv_file.tell() == 0:
            writer.writeheader()

        writer.writerow(row_data)
    csv_file.close()


def csv_run_command(csv_path):
    cmd = "/Users/navyasree.kumbam/Documents/Ecas\ Project/domain-scan/scan" + " " + csv_path + " " + "--scan=pshtt,sslyze --workers=25"
    os.system(cmd)
    print("scan done")
    #loading HSTS preloaded data
    preloaded = load_preload_list()
    preloaded_data = Path('./results/preloaded.txt').open('w')
    for data in preloaded:
      preloaded_data.write("\""+data + "\"" + "\n")
    if Path('./results/pshtt.csv').exists():
        sslyze_row = None
        agency_name = None
        pshtt_row = None
        print("loop started")
        for domain_row in csv.DictReader(open(csv_path)):
            for pshtt in csv.DictReader(open('./results/pshtt.csv')):
                if pshtt['Domain'] == domain_row['Domain Name'].lower().strip():
                    agency_name = domain_row['Agency'].strip()
                    domain = domain_row['Domain Name'].lower().strip()
                    pshtt_row = pshtt
                    break
                else:
                  pshtt_row = None
            if Path('./results/sslyze.csv').exists():
                for sslyze in csv.DictReader(open('./results/sslyze.csv')):
                    if sslyze['Domain'] == domain_row['Domain Name'].lower().strip():
                        sslyze_row = sslyze
                        break
                    else:
                      sslyze_row = None
            process_data = process_pshtt_data(pshtt_row, sslyze_row)
            load_https_data(agency_name, process_data)

    else:
        logging.info('pshtt.csv does not exist')


def single_domain_run_command(domain_name):
    cmd = "/Users/navyasree.kumbam/Documents/Ecas\ Project/domain-scan/scan" + " " + domain_name + " " + "--scan=pshtt,sslyze"
    os.system(cmd)
    with open('/Users/navyasree.kumbam/Desktop/current-federal.csv') as domain_file:
        for dict_row in csv.DictReader(domain_file):
            if dict_row['Domain Name'].lower().strip() == domain_name:
                agency_name = dict_row['Agency']
                break
            else:
                agency_name = None

    if Path('./results/pshtt.csv').exists():
        pshtt = None
        sslyze = None
        for dict_pshtt in csv.DictReader(open('./results/pshtt.csv')):
            pshtt = dict_pshtt
        if Path('./results/sslyze.csv').exists():
            for dict_sslyze in csv.DictReader(open('./results/sslyze.csv')):
                sslyze = dict_sslyze

        data = process_pshtt_data(pshtt, sslyze)
        load_https_data(agency_name, data)
    else:
        logging.info('pshtt.csv does not exist')


def run():

    parser = argparse.ArgumentParser(prefix_chars="--")
    parser.add_argument("--domain_name", default="", type=str, help= "Provide domain name ex: python3 single_https.py --domain_name sam.gov")
    parser.add_argument("--csvpath", default="", type=str, help= "Provide csv path ex: python3 single_https.py --csvpath current-federal.csv")
    args = parser.parse_args()
    csv_path = args.csvpath
    domain_name = args.domain_name
    # Clearing the https scan file before starting a new scan
    https_csv = Path('https_scan.csv').open('w')
    https_csv.truncate()
    print('Clearing the https scan csv file before starting a new scan')
    if domain_name != "":
        domain_name = domain_name.lower().strip()
        single_domain_run_command(domain_name)
    elif csv_path != "":
        csv_run_command(csv_path)
    else:
        logging.warning("Either of the arguments --domain_name or --csv_path need to be provided")
    https_csv.close()


if __name__ == '__main__':
    run()
