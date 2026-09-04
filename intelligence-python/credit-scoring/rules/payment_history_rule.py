def payment_history_score(profile):
    if profile.late_payments > 3:
        return -150
    return 0
