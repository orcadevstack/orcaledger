CREATE TABLE settlement_batches (
    batch_id        VARCHAR(64) PRIMARY KEY,
    total_debit     BIGINT NOT NULL DEFAULT 0,
    total_credit    BIGINT NOT NULL DEFAULT 0,
    net_position    BIGINT NOT NULL DEFAULT 0,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW(),
    finalized_at    TIMESTAMP
);

CREATE TABLE settlement_entries (
    id              BIGSERIAL PRIMARY KEY,
    batch_id        VARCHAR(64) NOT NULL REFERENCES settlement_batches(batch_id),
    debit_bank      VARCHAR(64) NOT NULL,
    credit_bank     VARCHAR(64) NOT NULL,
    amount          BIGINT NOT NULL,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_settlement_batch ON settlement_entries(batch_id);
