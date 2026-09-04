from fraud_detection.fraud_engine import FraudEngine

class FraudDetectionWorkflow:
    def __init__(self):
        self.engine = FraudEngine()

    def run(self, event):
        event["fraud_score"] = self.engine.evaluate(event)
        return event
