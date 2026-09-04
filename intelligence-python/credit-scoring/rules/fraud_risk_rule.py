def fraud_risk_score(profile):
    if profile.flagged_fraud:
        return -500
    return 0
