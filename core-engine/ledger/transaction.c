#include <stdio.h>
#include <string.h>
#include "transaction.h"

void init_transaction(Transaction *tx,
                      const char *tx_id,
                      const char *debit,
                      const char *credit,
                      int64_t amount) {

    snprintf(tx->tx_id, sizeof(tx->tx_id), "%s", tx_id);
    snprintf(tx->debit_account, sizeof(tx->debit_account), "%s", debit);
    snprintf(tx->credit_account, sizeof(tx->credit_account), "%s", credit);
    tx->amount = amount;
}

int validate_transaction(const Transaction *tx) {
    if (tx->amount <= 0) return 0;
    if (strlen(tx->debit_account) == 0) return 0;
    if (strlen(tx->credit_account) == 0) return 0;
    return 1;
}

int apply_transaction(const Transaction *tx) {
    printf("[LEDGER] Applying debit %s and credit %s for %ld\n",
           tx->debit_account, tx->credit_account, tx->amount);

    // TODO: update balances in database or memory
    return 0;
}

