#ifndef ORCA_JOURNAL_H
#define ORCA_JOURNAL_H

#include "transaction.h"

int write_journal_entry(const Transaction *tx);
int read_journal_entry(const char *tx_id, Transaction *out);

#endif
