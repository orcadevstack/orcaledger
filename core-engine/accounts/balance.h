#include <stdio.h>
#include "balance.h"

long get_available_balance(const char *account_id) {
    // TODO: query ledger + holds
    printf("Computing available balance for %s\n", account_id);
    return 0;
}

long get_ledger_balance(const char *account_id) {
    // TODO: sum all ledger entries
    printf("Computing ledger balance for %s\n", account_id);
    return 0;
}
