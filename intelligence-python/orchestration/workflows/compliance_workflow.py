from compliance_rules.rule_engine import RuleEngine

class ComplianceWorkflow:
    def __init__(self):
        self.engine = RuleEngine()

    def run(self, event):
        event["compliance"] = self.engine.evaluate(event)
        return event
