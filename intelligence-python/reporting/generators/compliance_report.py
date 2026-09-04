from reporting.report_base import ReportBase
from reporting.templates.compliance_report_template import compliance_template

class ComplianceReport(ReportBase):
    name = "compliance_report"

    def generate(self, data):
        return compliance_template(data)
