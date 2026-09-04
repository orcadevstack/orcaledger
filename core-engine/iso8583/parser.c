#include <stdio.h>
#include <string.h>
#include "parser.h"

int iso8583_parse(const uint8_t *data, int len, Iso8583Message *out) {
    printf("[ISO8583] Parsing raw message of %d bytes\n", len);
    memset(out, 0, sizeof(*out));
    // TODO: real bitmap + field parsing
    return 0;
}

int iso8583_serialize(const Iso8583Message *msg, uint8_t *out, int *len) {
    printf("[ISO8583] Serializing MTI=%s\n", msg->mti);
    // TODO: real serialization
    *len = 0;
    return 0;
}
