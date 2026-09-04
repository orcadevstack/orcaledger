#include <stdio.h>
#include <string.h>
#include "accounts.h"

int create_account(const char *id, const char *owner_id, const char *currency) {
    // TODO: persist to storage (DB, file, etc.)
    printf("Creating account %s for owner %s in %s\n", id, owner_id, currency);
    return 0;
}

int freeze_account(const char *id) {
    // TODO: update status in storage
    printf("Freezing account %s\n", id);
    return 0;
}

int close_account(const char *id) {
    // TODO: update status in storage
    printf("Closing account %s\n", id);
    return 0;
}

int get_account(const char *id, Account *out) {
    // TODO: load from storage
    printf("Loading account %s\n", id);
    memset(out, 0, sizeof(Account));
    snprintf(out->id, sizeof(out->id), "%s", id);
    snprintf(out->currency, sizeof(out->currency), "ZAR");
    out->status = 0;
    return 0;
}
