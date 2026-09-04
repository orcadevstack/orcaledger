#ifndef ORCA_ISO8583_PARSER_H
#define ORCA_ISO8583_PARSER_H

#include "iso8583.h"

int iso8583_parse(const uint8_t *data, int len, Iso8583Message *out);
int iso8583_serialize(const Iso8583Message *msg, uint8_t *out, int *len);

#endif
