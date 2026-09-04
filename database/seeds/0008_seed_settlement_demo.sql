INSERT INTO settlement_batches (batch_id, total_debit, total_credit, net_position)
VALUES ('BATCH-DEMO', 15000, 15000, 0);

INSERT INTO settlement_entries (batch_id, debit_bank, credit_bank, amount)
VALUES
    ('BATCH-DEMO', 'BANK-A', 'BANK-B', 10000),
    ('BATCH-DEMO', 'BANK-B', 'BANK-A', 5000);
