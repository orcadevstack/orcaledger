from fraud_detection.rules.velocity_rule import VelocityRule
from fraud_detection.rules.geo_rule import GeoRule
from fraud_detection.rules.device_rule import DeviceRule
from fraud_detection.rules.blacklist_rule import BlacklistRule
from fraud_detection.rules.pattern_rule import PatternRule

class RuleEngine:
    def __init__(self):
        self.rules = [
            VelocityRule(),
            GeoRule(),
            DeviceRule(),
            BlacklistRule(),
            PatternRule()
        ]

    def evaluate(self, tx):
        results = {}
        risk = 0

        for rule in self.rules:
            r = rule.check(tx)
            results[rule.name] = r
            risk += r["risk"]

        return {"results": results, "risk": risk}
