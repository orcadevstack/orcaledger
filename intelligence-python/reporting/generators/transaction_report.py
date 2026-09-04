from reporting.report_base import ReportBase
from reporting.templates.transaction_report_template import transaction_template

class TransactionReport(ReportBase):
    name = "transaction_report"

    def generate(self, data):
        return transaction_template(data)
