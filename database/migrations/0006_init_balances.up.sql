CREATE TABLE account_balances (
    account_id      VARCHAR(64) PRIMARY KEY REFERENCES accounts(id),
    balance         BIGINT NOT NULL DEFAULT 0,
    currency        VARCHAR(8) NOT NULL,
    updated_at      TIMESTAMP NOT NULL DEFAULT NOW()
);
