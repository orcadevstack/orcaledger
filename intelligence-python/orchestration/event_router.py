class EventRouter:
    def route(self, event):
        etype = event.get("type")

        if etype == "transaction":
            return "transaction_workflow"
        if etype == "settlement":
            return "settlement_workflow"
        if etype == "compliance":
            return "compliance_workflow"
        if etype == "credit_score":
            return "credit_scoring_workflow"
        if etype == "fraud":
            return "fraud_detection_workflow"

        raise Exception(f"Unknown event type: {etype}")
