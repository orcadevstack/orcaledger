INSERT INTO ledger_entries (tx_id, account_id, entry_type, amount, currency)
VALUES
    ('TX-DEMO-001', 'ACC-1001', 'DEBIT', 10000, 'ZAR'),
    ('TX-DEMO-001', 'ACC-1002', 'CREDIT', 10000, 'ZAR'),

    ('TX-DEMO-002', 'ACC-1002', 'DEBIT', 5000, 'ZAR'),
    ('TX-DEMO-002', 'ACC-1001', 'CREDIT', 5000, 'ZAR');
