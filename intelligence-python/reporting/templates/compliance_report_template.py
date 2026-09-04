def compliance_template(data):
    return {
        "title": "Compliance Report",
        "tx_id": data["tx_id"],
        "results": data["results"],
        "risk_score": data["risk_score"],
    }
