def apply_scorecard(features, model_score):
    rule_adjustment = 0

    if features["utilization"] > 0.9:
        rule_adjustment -= 50

    if features["num_delinquencies"] > 2:
        rule_adjustment -= 100

    return int(model_score * 700 + rule_adjustment)
