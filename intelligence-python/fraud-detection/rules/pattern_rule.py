class PatternRule:
    name = "PatternRule"

    def check(self, tx):
        if tx.merchant_category == "GAMBLING" and tx.amount > 50000:
            return {"risk": 0.5, "msg": "High-risk merchant pattern"}
        return {"risk": 0.0, "msg": "OK"}
