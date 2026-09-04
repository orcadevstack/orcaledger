#include <stdio.h>
#include <string.h>
#include "settlement.h"
#include "recon.h"

static SettlementBatch current_batch;

int settlement_start_batch(const char *batch_id) {
    memset(&current_batch, 0, sizeof(current_batch));
    snprintf(current_batch.batch_id, sizeof(current_batch.batch_id), "%s", batch_id);

    printf("[SETTLEMENT] Starting batch %s\n", batch_id);
    return 0;
}

int settlement_add_entry(const char *batch_id,
                         const char *debit_bank,
                         const char *credit_bank,
                         int64_t amount) {

    if (strcmp(batch_id, current_batch.batch_id) != 0) {
        printf("[SETTLEMENT] Invalid batch ID\n");
        return -1;
    }

    printf("[SETTLEMENT] Adding entry: %s -> %s amount=%ld\n",
           debit_bank, credit_bank, amount);

    current_batch.total_debit += amount;
    current_batch.total_credit += amount;

    /* Record for reconciliation */
    recon_record_entry(batch_id, debit_bank, credit_bank, amount);

    return 0;
}

int settlement_finalize(const char *batch_id, SettlementBatch *out) {
    if (strcmp(batch_id, current_batch.batch_id) != 0) {
        printf("[SETTLEMENT] Invalid batch ID\n");
        return -1;
    }

    current_batch.net_position = current_batch.total_credit - current_batch.total_debit;

    printf("[SETTLEMENT] Finalizing batch %s\n", batch_id);
    printf("[SETTLEMENT] Total debit: %ld\n", current_batch.total_debit);
    printf("[SETTLEMENT] Total credit: %ld\n", current_batch.total_credit);
    printf("[SETTLEMENT] Net position: %ld\n", current_batch.net_position);

    memcpy(out, &current_batch, sizeof(SettlementBatch));

    /* Trigger reconciliation */
    recon_run(batch_id);

    return 0;
}
