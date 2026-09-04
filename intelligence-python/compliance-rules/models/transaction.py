class Transaction:
    def __init__(self, tx_id, amount, currency, debit_account, credit_account, timestamp, geo_location):
        self.tx_id = tx_id
        self.amount = amount
        self.currency = currency
        self.debit_account = debit_account
        self.credit_account = credit_account
        self.timestamp = timestamp
        self.geo_location = geo_location
