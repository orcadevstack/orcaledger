from credit_scoring.scoring_engine import ScoringEngine

class CreditScoringWorkflow:
    def __init__(self):
        self.engine = ScoringEngine()

    def run(self, event):
        event["credit_score"] = self.engine.score(event["profile"], event["transactions"])
        return event
