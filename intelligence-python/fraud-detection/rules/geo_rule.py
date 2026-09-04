class GeoRule:
    name = "GeoRule"

    def check(self, tx):
        if tx.geo_location not in ["ZA", "US", "EU"]:
            return {"risk": 0.7, "msg": "Unusual geolocation"}
        return {"risk": 0.0, "msg": "OK"}
