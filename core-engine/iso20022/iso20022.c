#include <stdio.h>
#include <string.h>
#include "iso20022.h"

static void init_payment(Iso20022Payment *pmt) {
    memset(pmt, 0, sizeof(*pmt));
    snprintf(pmt->msg_id, sizeof(pmt->msg_id), "MSG-%ld", time(NULL));
    snprintf(pmt->instr_id, sizeof(pmt->instr_id), "INSTR-%ld", time(NULL));
    snprintf(pmt->end_to_end_id, sizeof(pmt->end_to_end_id), "E2E-%ld", time(NULL));
}

int iso20022_build_pain_001(Iso20022Payment *pmt,
                            const char *debtor_name,
                            const char *debtor_iban,
                            const char *creditor_name,
                            const char *creditor_iban,
                            const char *currency,
                            const char *amount) {
    init_payment(pmt);

    snprintf(pmt->debtor_name, sizeof(pmt->debtor_name), "%s", debtor_name);
    snprintf(pmt->debtor_iban, sizeof(pmt->debtor_iban), "%s", debtor_iban);
    snprintf(pmt->creditor_name, sizeof(pmt->creditor_name), "%s", creditor_name);
    snprintf(pmt->creditor_iban, sizeof(pmt->creditor_iban), "%s", creditor_iban);
    snprintf(pmt->currency, sizeof(pmt->currency), "%s", currency);
    snprintf(pmt->amount, sizeof(pmt->amount), "%s", amount);

    printf("[ISO20022] Built pain.001 for %s -> %s %s %s\n",
           debtor_iban, creditor_iban, currency, amount);
    return 0;
}

int iso20022_build_pacs_008(Iso20022Payment *pmt,
                            const char *debtor_iban,
                            const char *creditor_iban,
                            const char *currency,
                            const char *amount) {
    init_payment(pmt);

    snprintf(pmt->debtor_iban, sizeof(pmt->debtor_iban), "%s", debtor_iban);
    snprintf(pmt->creditor_iban, sizeof(pmt->creditor_iban), "%s", creditor_iban);
    snprintf(pmt->currency, sizeof(pmt->currency), "%s", currency);
    snprintf(pmt->amount, sizeof(pmt->amount), "%s", amount);

    printf("[ISO20022] Built pacs.008 for %s -> %s %s %s\n",
           debtor_iban, creditor_iban, currency, amount);
    return 0;
}
