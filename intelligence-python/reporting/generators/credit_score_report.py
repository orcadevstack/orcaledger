from reporting.report_base import ReportBase
from reporting.templates.credit_score_report_template import credit_score_template

class CreditScoreReport(ReportBase):
    name = "credit_score_report"

    def generate(self, data):
        return credit_score_template(data)
