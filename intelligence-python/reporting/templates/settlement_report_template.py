def settlement_template(data):
    return {
        "title": "Settlement Report",
        "batch_id": data["batch_id"],
        "total_debit": data["total_debit"],
        "total_credit": data["total_credit"],
        "net_position": data["net_position"],
    }
