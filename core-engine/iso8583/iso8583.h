#ifndef ORCA_ISO8583_H
#define ORCA_ISO8583_H

#include <stdint.h>

typedef struct {
    char    mti[5];          // Message Type Indicator
    uint8_t bitmap[16];      // Primary + secondary bitmap
    char    fields[129][256]; // Up to field 128
} Iso8583Message;

int iso8583_build_auth_request(Iso8583Message *msg,
                               const char *pan,
                               const char *amount,
                               const char *stan);

int iso8583_build_financial_tx(Iso8583Message *msg,
                               const char *pan,
                               const char *amount,
                               const char *stan);

#endif
