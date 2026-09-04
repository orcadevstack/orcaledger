CREATE TABLE reconciliation_log (
    id              BIGSERIAL PRIMARY KEY,
    batch_id        VARCHAR(64) NOT NULL REFERENCES settlement_batches(batch_id),
    debit_bank      VARCHAR(64) NOT NULL,
    credit_bank     VARCHAR(64) NOT NULL,
    amount          BIGINT NOT NULL,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_recon_batch ON reconciliation_log(batch_id);
