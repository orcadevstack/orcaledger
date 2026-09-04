#include <stdio.h>
#include <string.h>
#include "journal.h"

int write_journal_entry(const Transaction *tx) {
    printf("[JOURNAL] Writing immutable entry for %s\n", tx->tx_id);

    // TODO: append to file or database
    return 0;
}

int read_journal_entry(const char *tx_id, Transaction *out) {
    printf("[JOURNAL] Reading journal entry %s\n", tx_id);

    // TODO: load from storage
    memset(out, 0, sizeof(Transaction));
    return 0;
}
