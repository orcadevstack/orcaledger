#ifndef ORCA_LEDGER_H
#define ORCA_LEDGER_H

#include <stdint.h>

typedef struct {
    char tx_id[64];
    char account_debit[64];
    char account_credit[64];
    int64_t amount;
} LedgerEntry;

int post_transaction(const char *tx_id,
                     const char *debit_account,
                     const char *credit_account,
                     int64_t amount);

int get_ledger_entry(const char *tx_id, LedgerEntry *out);

#endif
