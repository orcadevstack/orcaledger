from reporting.report_base import ReportBase
from reporting.templates.settlement_report_template import settlement_template

class SettlementReport(ReportBase):
    name = "settlement_report"

    def generate(self, data):
        return settlement_template(data)
