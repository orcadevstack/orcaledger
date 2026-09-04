from compliance_rules.rule_base import ComplianceRule
from compliance_rules.models.rule_result import RuleResult

class UnusualPatternRule(ComplianceRule):
    name = "UnusualPatternRule"
    description = "Detects unusual transaction patterns"

    def check(self, transaction):
        # Placeholder for ML model integration
        return RuleResult(self.name, True, "OK")
