from compliance_rules.rule_base import ComplianceRule
from compliance_rules.models.rule_result import RuleResult

BLACKLIST = {"ACC-9999", "ACC-6666"}

class BlacklistRule(ComplianceRule):
    name = "BlacklistRule"
    description = "Blocks blacklisted accounts"

    def check(self, transaction):
        if transaction.debit_account in BLACKLIST or transaction.credit_account in BLACKLIST:
            return RuleResult(self.name, False, "Account is blacklisted")
        return RuleResult(self.name, True, "OK")
