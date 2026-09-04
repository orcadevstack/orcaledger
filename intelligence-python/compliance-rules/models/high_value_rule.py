from compliance_rules.rule_base import ComplianceRule
from compliance_rules.models.rule_result import RuleResult

class HighValueRule(ComplianceRule):
    name = "HighValueRule"
    description = "Flags transactions above R100,000"

    def check(self, transaction):
        if transaction.amount > 10000000:  # cents
            return RuleResult(self.name, False, "High-value transaction requires manual review")
        return RuleResult(self.name, True, "OK")
