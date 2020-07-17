<style>
.no-height{
    min-height:150px!important;
    height:auto!important;
}
</style>

<div class="view view-all-agency-data view-id-all_agency_data view-display-id-block_15 white-back no-height view-dom-id-149e4767a827975c222867424f37ca00">
    <div class="view-content">
        <div class="table-responsive">
            <table class="views-table cols-11 table table-hover table-striped">
                <caption>Tabular Report</caption>
                <thead>
                <tr>
                    <th class="views-field views-field-field-web-agency-id-1" scope="col">
                        Websites          </th>
                    <th class="views-field views-field-field-web-agency-id-1" scope="col">
                        Agencies          </th>
                    <th class="views-field views-field-field-dap-score" scope="col">
                        Average DAP Score          </th>
                    <th class="views-field views-field-field-https-score" scope="col">
                        Average HTTPS Score          </th>
                    <th class="views-field views-field-field-mobile-overall-score" scope="col">
                        Average Mobile Overall Score          </th>
                    <th class="views-field views-field-field-mobile-performance-score" scope="col">
                        Average Mobile Performance Score          </th>
                    <th class="views-field views-field-field-mobile-usability-score" scope="col">
                        Average Mobile Usability Score          </th>
                    <th class="views-field views-field-field-site-speed-score" scope="col">
                        Average Site Speed Score          </th>
                    <th class="views-field views-field-field-ipv6-score" scope="col">
                        Average IPv6 Score          </th>
                    <th class="views-field views-field-field-dnssec-score" scope="col">
                        Average DNSSEC Score          </th>
                    <th class="views-field views-field-field-free-of-insecr-prot-score" scope="col">
                        Average Free of RC4/3DES and SSLv2/SSLv3 score          </th>
                    <th class="views-field views-field-field-m15-13-compliance-score" scope="col">
                        Average M-15-13 and BOD 18-01 Compliance Score          </th>
                </tr>
                </thead>
                <tbody>
                <tr class="odd views-row-first views-row-last">
                    <td class="views-field views-field-field-web-agency-id-1">
                        <a href="/website/all/reports"><?=$govwidedata['actualdata']['websitenos']?></a>          </td>
                    <td class="views-field views-field-field-web-agency-id-1">
                        <a href="/agency/all/data"><?=$govwidedata['actualdata']['agencynos']?></a>          </td>
                    <td class="views-field views-field-field-dap-score">
                        <?=$govwidedata['actualdata']['avg_dap']?>          </td>
                    <td class="views-field views-field-field-https-score">
                        <?=$govwidedata['actualdata']['avg_https']?>          </td>
                    <td class="views-field views-field-field-mobile-overall-score">
                        <?=$govwidedata['actualdata']['avg_mob_overall']?>          </td>
                    <td class="views-field views-field-field-mobile-performance-score">
                        <?=$govwidedata['actualdata']['avg_mob_perform']?>          </td>
                    <td class="views-field views-field-field-mobile-usability-score">
                        <?=$govwidedata['actualdata']['avg_mob_usab']?>          </td>
                    <td class="views-field views-field-field-site-speed-score">
                        <?=$govwidedata['actualdata']['avg_sitespeed']?>          </td>
                    <td class="views-field views-field-field-ipv6-score">
                        <?=$govwidedata['actualdata']['avg_ipv6']?>          </td>
                    <td class="views-field views-field-field-dnssec-score">
                        <?=$govwidedata['actualdata']['avg_dnssec']?>          </td>
                    <td class="views-field views-field-field-free-of-insecr-prot-score">
                        <?=$govwidedata['actualdata']['avg_rc4']?>          </td>
                    <td class="views-field views-field-field-m15-13-compliance-score">
                        <?=$govwidedata['actualdata']['avg_m15']?>          </td>
                </tr>
                </tbody>
            </table>
        </div>
    </div>
</div>