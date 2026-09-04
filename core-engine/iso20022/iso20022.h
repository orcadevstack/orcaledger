#ifndef ORCA_ISO20022_H
#define ORCA_ISO20022_H

#include <stddef.h>

typedef struct {
    char msg_id[64];
    char instr_id[64];
    char end_to_end_id[64];
    char debtor_name[128];
    char debtor_iban[64];
    char creditor_name[128];
    char creditor_iban[64];
    char currency[8];
    char amount[32];
} Iso20022Payment;

int iso20022_build_pain_001(Iso20022Payment *pmt,
                            const char *debtor_name,
                            const char *debtor_iban,
                            const char *creditor_name,
                            const char *creditor_iban,
                            const char *currency,
                            const char *amount);

int iso20022_build_pacs_008(Iso20022Payment *pmt,
                            const char *debtor_iban,
                            const char *creditor_iban,
                            const char *currency,
                            const char *amount);

#endif
