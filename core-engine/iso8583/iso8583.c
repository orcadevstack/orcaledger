#include <stdio.h>
#include <string.h>
#include "iso8583.h"

static void set_field(Iso8583Message *msg, int field, const char *value) {
    if (field < 1 || field > 128) return;
    snprintf(msg->fields[field], sizeof(msg->fields[field]), "%s", value);
}

int iso8583_build_auth_request(Iso8583Message *msg,
                               const char *pan,
                               const char *amount,
                               const char *stan) {
    memset(msg, 0, sizeof(*msg));
    snprintf(msg->mti, sizeof(msg->mti), "0100"); // auth request

    set_field(msg, 2, pan);      // PAN
    set_field(msg, 4, amount);   // Amount
    set_field(msg, 11, stan);    // STAN

    printf("[ISO8583] Built auth request for PAN=%s amount=%s stan=%s\n",
           pan, amount, stan);
    return 0;
}

int iso8583_build_financial_tx(Iso8583Message *msg,
                               const char *pan,
                               const char *amount,
                               const char *stan) {
    memset(msg, 0, sizeof(*msg));
    snprintf(msg->mti, sizeof(msg->mti), "0200"); // financial tx

    set_field(msg, 2, pan);
    set_field(msg, 4, amount);
    set_field(msg, 11, stan);

    printf("[ISO8583] Built financial tx for PAN=%s amount=%s stan=%s\n",
           pan, amount, stan);
    return 0;
}
