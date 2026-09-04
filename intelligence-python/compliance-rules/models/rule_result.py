class RuleResult:
    def __init__(self, rule_name, passed, message):
        self.rule_name = rule_name
        self.passed = passed
        self.message = message
