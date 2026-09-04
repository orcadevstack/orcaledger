#ifndef ORCA_ISO20022_SERIALIZER_H
#define ORCA_ISO20022_SERIALIZER_H

#include "iso20022.h"

int iso20022_serialize_pain_001(const Iso20022Payment *pmt,
                                char *xml_out, int xml_out_size);

int iso20022_serialize_pacs_008(const Iso20022Payment *pmt,
                                char *xml_out, int xml_out_size);

int iso20022_parse_payment(const char *xml_in, Iso20022Payment *pmt);

#endif
