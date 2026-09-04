#ifndef ORCA_RECON_H
#define ORCA_RECON_H

#include <stdint.h>

/* Record each settlement entry for reconciliation */
int recon_record_entry(const char *batch_id,
                       const char *debit_bank,
                       const char *credit_bank,
                       int64_t amount);

/* Run reconciliation for a batch */
int recon_run(const char *batch_id);

#endif
