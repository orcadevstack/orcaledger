#ifndef ACCOUNTS_H
#define ACCOUNTS_H

typedef struct {
    char  id[64];
    char  owner_id[64];
    char  currency[8];
    int   status;   // 0=active, 1=frozen, 2=closed
} Account;

int create_account(const char *id, const char *owner_id, const char *currency);
int freeze_account(const char *id);
int close_account(const char *id);
int get_account(const char *id, Account *out);

#endif
