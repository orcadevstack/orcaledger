class VelocityRule:
    name = "VelocityRule"

    def check(self, tx):
        if tx.velocity > 10:
            return {"risk": 0.8, "msg": "High transaction velocity"}
        return {"risk": 0.0, "msg": "OK"}
