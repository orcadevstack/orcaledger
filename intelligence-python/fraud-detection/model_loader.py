import pickle

def load_model():
    with open("fraud_detection/models/isolation_forest.pkl", "rb") as f:
        return pickle.load(f)
