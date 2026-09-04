from credit_scoring.feature_extractor import extract_features
from credit_scoring.scorecard import apply_scorecard
from credit_scoring.model_loader import load_model

class ScoringEngine:
    def __init__(self):
        self.model = load_model()

    def score(self, profile, transactions):
        features = extract_features(profile, transactions)
        model_score = self.model.predict_proba([features])[0][1]
        final_score = apply_scorecard(features, model_score)
        return final_score
