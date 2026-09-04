CREATE TABLE ledger_entries (
    id              BIGSERIAL PRIMARY KEY,
    tx_id           VARCHAR(64) NOT NULL,
    account_id      VARCHAR(64) NOT NULL REFERENCES accounts(id),
    entry_type      VARCHAR(6) NOT NULL, -- DEBIT or CREDIT
    amount          BIGINT NOT NULL,     -- minor units (cents)
    currency        VARCHAR(8) NOT NULL,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_ledger_tx ON ledger_entries(tx_id);
CREATE INDEX idx_ledger_account ON ledger_entries(account_id);
