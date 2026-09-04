class SettlementWorkflow:
    def run(self, event):
        event["settled"] = True
        return event
