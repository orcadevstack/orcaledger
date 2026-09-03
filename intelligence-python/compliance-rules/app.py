def check_compliance(tx):
    # TODO: implement AML, sanctions, KYC checks
    return {"tx_id": tx.get("id"), "compliant": True}

if __name__ == "__main__":
    sample = {"id": "TX123"}
    print("Compliance check:", check_compliance(sample))
