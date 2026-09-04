def transaction_template(data):
    return {
        "title": "Transaction Report",
        "tx_id": data["tx_id"],
        "amount": data["amount"],
        "currency": data["currency"],
        "timestamp": data["timestamp"],
        "status": data["status"],
    }
