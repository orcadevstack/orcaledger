class TransactionWorkflow:
    def run(self, event):
        event["status"] = "processed"
        return event
