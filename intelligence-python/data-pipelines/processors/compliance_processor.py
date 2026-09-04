from compliance_rules.rule_engine import RuleEngine

class ComplianceProcessor:
    def __init__(self):
        self.engine = RuleEngine()

    def process(self, event):
        event["compliance_results"] = self.engine.evaluate(event)
        return event
