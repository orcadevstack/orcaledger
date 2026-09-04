class TransactionProcessor:
    def process(self, event):
        event["normalized_amount"] = event["amount"] / 100.0
        return event
