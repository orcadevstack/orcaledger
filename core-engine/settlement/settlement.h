#ifndef ORCA_SETTLEMENT_H
#define ORCA_SETTLEMENT_H

#include <stdint.h>

typedef struct {
    char batch_id[64];
    int64_t total_debit;
    int64_t total_credit;
    int64_t net_position;
} SettlementBatch;

/* Start a settlement batch */
int settlement_start_batch(const char *batch_id);

/* Add a transaction to the batch */
int settlement_add_entry(const char *batch_id,
                         const char *debit_bank,
                         const char *credit_bank,
                         int64_t amount);

/* Finalize settlement (compute net positions) */
int settlement_finalize(const char *batch_id, SettlementBatch *out);

#endif
