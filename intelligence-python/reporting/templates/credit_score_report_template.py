def credit_score_template(data):
    return {
        "title": "Credit Score Report",
        "profile_id": data["profile_id"],
        "score": data["score"],
        "risk_band": data["risk_band"],
    }
