CREATE TABLE journal (
    id              BIGSERIAL PRIMARY KEY,
    tx_id           VARCHAR(64) UNIQUE NOT NULL,
    debit_account   VARCHAR(64) NOT NULL,
    credit_account  VARCHAR(64) NOT NULL,
    amount          BIGINT NOT NULL,
    currency        VARCHAR(8) NOT NULL,
    raw_payload     JSONB NOT NULL,
    created_at      TIMESTAMP NOT NULL DEFAULT NOW()
);
