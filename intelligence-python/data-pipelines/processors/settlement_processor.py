class SettlementProcessor:
    def process(self, event):
        event["net"] = event["credit"] - event["debit"]
        return event
