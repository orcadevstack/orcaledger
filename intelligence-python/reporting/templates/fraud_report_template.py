def fraud_template(data):
    return {
        "title": "Fraud Detection Report",
        "tx_id": data["tx_id"],
        "ml_score": data["ml_score"],
        "anomaly_score": data["anomaly_score"],
        "rule_results": data["rule_results"],
        "final_score": data["final_score"],
    }
