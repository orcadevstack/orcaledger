#include <stdio.h>
#include <string.h>
#include "serializer.h"

int iso20022_serialize_pain_001(const Iso20022Payment *pmt,
                                char *xml_out, int xml_out_size) {
    snprintf(xml_out, xml_out_size,
             "<Document>"
             "<CstmrCdtTrfInitn>"
             "<PmtInf>"
             "<Dbtr><Nm>%s</Nm></Dbtr>"
             "<DbtrAcct><IBAN>%s</IBAN></DbtrAcct>"
             "<Cdtr><Nm>%s</Nm></Cdtr>"
             "<CdtrAcct><IBAN>%s</IBAN></CdtrAcct>"
             "<Amt Ccy=\"%s\">%s</Amt>"
             "</PmtInf>"
             "</CstmrCdtTrfInitn>"
             "</Document>",
             pmt->debtor_name,
             pmt->debtor_iban,
             pmt->creditor_name,
             pmt->creditor_iban,
             pmt->currency,
             pmt->amount);

    printf("[ISO20022] Serialized pain.001 XML\n");
    return 0;
}

int iso20022_serialize_pacs_008(const Iso20022Payment *pmt,
                                char *xml_out, int xml_out_size) {
    snprintf(xml_out, xml_out_size,
             "<Document>"
             "<FIToFICstmrCdtTrf>"
             "<CdtTrfTxInf>"
             "<DbtrAcct><IBAN>%s</IBAN></DbtrAcct>"
             "<CdtrAcct><IBAN>%s</IBAN></CdtrAcct>"
             "<Amt Ccy=\"%s\">%s</Amt>"
             "</CdtTrfTxInf>"
             "</FIToFICstmrCdtTrf>"
             "</Document>",
             pmt->debtor_iban,
             pmt->creditor_iban,
             pmt->currency,
             pmt->amount);

    printf("[ISO20022] Serialized pacs.008 XML\n");
    return 0;
}

int iso20022_parse_payment(const char *xml_in, Iso20022Payment *pmt) {
    printf("[ISO20022] Parsing XML payment message\n");
    memset(pmt, 0, sizeof(*pmt));
    // TODO: real XML parsing (libxml2, tinyxml, etc.)
    return 0;
}
