CREATE TABLE settlement_batches (
    batch_id        VARCHAR(64) PRIMARY KEY,
    total_debit     BIGINT NOT NULL DEFAULT 0,
    total_credit    BIGINT NOT NULL DEFAULT 0,
    net_position    BIGINT NOT NULL DEFAULT 0,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW(),
    finalized_at    TIMESTAMP
);
