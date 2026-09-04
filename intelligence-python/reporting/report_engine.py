from reporting.report_loader import load_reports

class ReportEngine:
    def __init__(self):
        self.reports = load_reports()

    def generate(self, report_name, data):
        report = self.reports[report_name]()
        return report.generate(data)
