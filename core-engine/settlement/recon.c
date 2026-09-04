#include <stdio.h>
#include <string.h>
#include "recon.h"

/* Simple in-memory reconciliation log */
typedef struct {
    char debit_bank[64];
    char credit_bank[64];
    int64_t amount;
} ReconEntry;

static ReconEntry recon_log[1024];
static int recon_count = 0;

int recon_record_entry(const char *batch_id,
                       const char *debit_bank,
                       const char *credit_bank,
                       int64_t amount) {

    printf("[RECON] Recording entry for batch %s: %s -> %s amount=%ld\n",
           batch_id, debit_bank, credit_bank, amount);

    snprintf(recon_log[recon_count].debit_bank, sizeof(recon_log[recon_count].debit_bank), "%s", debit_bank);
    snprintf(recon_log[recon_count].credit_bank, sizeof(recon_log[recon_count].credit_bank), "%s", credit_bank);
    recon_log[recon_count].amount = amount;

    recon_count++;
    return 0;
}

int recon_run(const char *batch_id) {
    printf("[RECON] Running reconciliation for batch %s\n", batch_id);

    for (int i = 0; i < recon_count; i++) {
        printf("[RECON] Entry %d: %s -> %s amount=%ld\n",
               i,
               recon_log[i].debit_bank,
               recon_log[i].credit_bank,
               recon_log[i].amount);
    }

    printf("[RECON] Reconciliation complete for batch %s\n", batch_id);
    return 0;
}
