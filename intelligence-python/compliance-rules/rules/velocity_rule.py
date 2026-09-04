from compliance_rules.rule_base import ComplianceRule
from compliance_rules.models.rule_result import RuleResult

class VelocityRule(ComplianceRule):
    name = "VelocityRule"
    description = "Detects rapid repeated transactions"

    def check(self, transaction):
        # Placeholder: real version queries PostgreSQL
        return RuleResult(self.name, True, "OK")
