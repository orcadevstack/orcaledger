class DeviceRule:
    name = "DeviceRule"

    def check(self, tx):
        if tx.device_id != tx.last_known_device:
            return {"risk": 0.6, "msg": "New device detected"}
        return {"risk": 0.0, "msg": "OK"}
