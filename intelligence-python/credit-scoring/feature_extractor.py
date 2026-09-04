def extract_features(profile, transactions):
    return {
        "age": profile.age,
        "income": profile.income,
        "avg_tx_amount": sum(t.amount for t in transactions) / len(transactions),
        "max_tx_amount": max(t.amount for t in transactions),
        "num_delinquencies": sum(1 for t in transactions if t.is_late),
        "utilization": profile.current_balance / profile.credit_limit,
    }
