BLACKLIST = {"ACC-9999", "ACC-6666"}

class BlacklistRule:
    name = "BlacklistRule"

    def check(self, tx):
        if tx.account in BLACKLIST:
            return {"risk": 1.0, "msg": "Blacklisted account"}
        return {"risk": 0.0, "msg": "OK"}
