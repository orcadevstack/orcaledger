def extract_features(tx):
    return {
        "amount": tx.amount,
        "hour": tx.timestamp.hour,
        "geo": tx.geo_location,
        "device": tx.device_id,
        "velocity": tx.velocity,
        "merchant": tx.merchant_category,
        "is_blacklisted": int(tx.account in tx.blacklist),
    }
