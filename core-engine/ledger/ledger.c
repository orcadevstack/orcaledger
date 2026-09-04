#include <stdio.h>
#include <string.h>
#include "ledger.h"
#include "transaction.h"
#include "journal.h"
#include "db.h"

/* Global DB connection for ledger module */
static OrcaDb g_db;

/* Initialize DB connection for ledger */
int ledger_init_db(const char *conninfo) {
    printf("[LEDGER] Initializing DB connection...\n");
    return db_init(&g_db, conninfo);
}

/* Apply double-entry transaction into ledger_entries table */
int apply_transaction(const Transaction *tx) {
    char sql[512];

    snprintf(sql, sizeof(sql),
        "INSERT INTO ledger_entries (tx_id, account_id, entry_type, amount, currency) "
        "VALUES ('%s','%s','DEBIT',%ld,'ZAR'),"
        "       ('%s','%s','CREDIT',%ld,'ZAR');",
        tx->tx_id, tx->debit_account, tx->amount,
        tx->tx_id, tx->credit_account, tx->amount
    );

    printf("[LEDGER] Applying transaction to DB: %s\n", tx->tx_id);

    if (db_exec(&g_db, sql) != 0) {
        printf("[LEDGER] ERROR: Failed to insert ledger entries\n");
        return -1;
    }

    return 0;
}

/* Main ledger posting function */
int post_transaction(const char *tx_id,
                     const char *debit_account,
                     const char *credit_account,
                     int64_t amount) {

    printf("[LEDGER] Posting transaction %s\n", tx_id);

    /* 1. Build transaction object */
    Transaction tx;
    init_transaction(&tx, tx_id, debit_account, credit_account, amount);

    /* 2. Validate */
    if (!validate_transaction(&tx)) {
        printf("[LEDGER] ERROR: Validation failed for %s\n", tx_id);
        return -1;
    }

    /* 3. Write immutable journal entry */
    if (write_journal_entry(&tx) != 0) {
        printf("[LEDGER] ERROR: Journal write failed for %s\n", tx_id);
        return -1;
    }

    /* 4. Apply double-entry ledger posting */
    if (apply_transaction(&tx) != 0) {
        printf("[LEDGER] ERROR: Ledger apply failed for %s\n", tx_id);
        return -1;
    }

    printf("[LEDGER] SUCCESS: Transaction %s posted\n", tx_id);
    return 0;
}
