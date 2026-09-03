def score_customer(customer):
    # TODO: implement real credit scoring
    return {"customer_id": customer.get("id"), "score": 650}

if __name__ == "__main__":
    sample = {"id": "CUST001"}
    print("Credit score:", score_customer(sample))
