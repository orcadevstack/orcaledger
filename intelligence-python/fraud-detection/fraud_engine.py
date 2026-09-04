from fraud_detection.feature_extractor import extract_features
from fraud_detection.model_loader import load_model
from fraud_detection.rule_engine import RuleEngine
from fraud_detection.anomaly_detector import detect_anomaly

class FraudEngine:
    def __init__(self):
        self.model = load_model()
        self.rule_engine = RuleEngine()

    def evaluate(self, transaction):
        features = extract_features(transaction)

        ml_score = self.model.predict_proba([features])[0][1]
        anomaly_score = detect_anomaly(features)
        rule_results = self.rule_engine.evaluate(transaction)

        final_score = ml_score * 0.6 + anomaly_score * 0.2 + rule_results["risk"] * 0.2

        return {
            "ml_score": ml_score,
            "anomaly_score": anomaly_score,
            "rule_results": rule_results,
            "final_score": final_score
        }
