def evaluate_transaction(tx):
    # TODO: implement real fraud logic
    return {"tx_id": tx.get("id"), "fraud_score": 0.1, "flagged": False}

if __name__ == "__main__":
    sample = {"id": "TX123", "amount": 1000}
    print("Fraud evaluation:", evaluate_transaction(sample))
