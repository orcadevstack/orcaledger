from compliance_rules.rule_loader import load_rules

class RuleEngine:
    def __init__(self):
        self.rules = load_rules()

    def evaluate(self, transaction):
        results = []
        for rule in self.rules:
            result = rule.check(transaction)
            results.append(result)
        return results
