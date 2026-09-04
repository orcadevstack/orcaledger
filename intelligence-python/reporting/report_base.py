class ReportBase:
    name = "BaseReport"

    def generate(self, data):
        raise NotImplementedError
