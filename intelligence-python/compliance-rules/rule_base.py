class ComplianceRule:
    name = "BaseRule"
    description = "Generic compliance rule"

    def check(self, transaction):
        raise NotImplementedError("Rule must implement check()")
