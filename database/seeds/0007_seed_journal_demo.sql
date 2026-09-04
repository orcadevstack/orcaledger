INSERT INTO journal (tx_id, debit_account, credit_account, amount, currency, raw_payload)
VALUES
    ('TX-DEMO-001', 'ACC-1001', 'ACC-1002', 10000, 'ZAR',
     '{"tx_id":"TX-DEMO-001","amount":10000,"currency":"ZAR"}'),

    ('TX-DEMO-002', 'ACC-1002', 'ACC-1001', 5000, 'ZAR',
     '{"tx_id":"TX-DEMO-002","amount":5000,"currency":"ZAR"}');
