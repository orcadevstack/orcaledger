from reporting.report_base import ReportBase
from reporting.templates.fraud_report_template import fraud_template

class FraudReport(ReportBase):
    name = "fraud_report"

    def generate(self, data):
        return fraud_template(data)
