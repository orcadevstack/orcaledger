from compliance_rules.rule_base import ComplianceRule
from compliance_rules.models.rule_result import RuleResult

class GeoRule(ComplianceRule):
    name = "GeoRule"
    description = "Detects unusual geolocation activity"

    def check(self, transaction):
        if transaction.geo_location not in ["ZA", "US", "EU"]:
            return RuleResult(self.name, False, "Unusual geolocation")
        return RuleResult(self.name, True, "OK")
