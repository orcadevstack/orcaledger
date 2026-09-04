def utilization_score(profile):
    if profile.utilization > 0.8:
        return -100
    return 0
