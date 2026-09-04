import pickle

def load_model():
    with open("credit_scoring/models/logistic_regression.pkl", "rb") as f:
        return pickle.load(f)
