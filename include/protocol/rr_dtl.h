/**
 * @file: the Detail of Resoure Record
 *
 * @brief: The distribution of the protocol depended on the different TYPE
 *          leads to different DATA format.
 *              Reference: https://www.ietf.org/rfc/rfc1035.txt
 */
#include "type.h"
#include "std_rr.h"

/**
 * 3.2.2. TYPE values
 *
 * TYPE fields are used in resource records.
 * subset of QTYPEs.
 * Note that these types are a
 * TYPE value and meaning
 *
 *  A 1 a host address
 *  NS 2 an authoritative name server
 *  MD 3 a mail destination (Obsolete - use MX)
 *  MF 4 a mail forwarder (Obsolete - use MX)
 *  CNAME 5 the canonical name for an alias
 *  SOA 6 marks the start of a zone of authority
 *  MB 7 a mailbox domain name (EXPERIMENTAL)
 *  MG 8 a mail group member (EXPERIMENTAL)
 *  MR 9 a mail rename domain name (EXPERIMENTAL)
 *  NULL 10 a null RR (EXPERIMENTAL)
 *  WKS 11 a well known service description
 *  PTR 12 a domain name pointer
 *  HINFO 13 host information
 *  MINFO 14 mailbox or mail list information
 *  MX 15 mail exchange
 *  TXT 16 text strings
 */
/*typedef enum {
    _A       = 1,
    _NS      = 2,
    _MD      = 3,
    _MF      = 4,
    _CNAME   = 5,
    _SOA     = 6,
    _MB      = 7,
    _MG      = 8,
    _MR      = 9,
    _NULL    =10,
    _WKS     =11,
    _PTR     =12,
    _HINFO   =13,
    _MINFO   =14,
    _MX      =15,
    _TXT     =16,
} RR_TYPE_t;*/

/**
 * 3.2.3. QTYPE values
 *
 * QTYPE fields appear in the question part of a query.
 * superset of TYPEs, hence all TYPEs are valid QTYPEs.
 * following QTYPEs are defined:
 *
 * AXFR  252 A request for a transfer of an entire zone
 * MAILB 253 A request for mailbox-related records (MB, MG or MR)
 * MAILA 254 A request for mail agent RRs (Obsolete - see MX)
 * *     255 A request for all records
 */
enum {
    _A       =  1,
    _NS      =  2,
    _MD      =  3,
    _MF      =  4,
    _CNAME   =  5,
    _SOA     =  6,
    _MB      =  7,
    _MG      =  8,
    _MR      =  9,
    _NULL    = 10,
    _WKS     = 11,
    _PTR     = 12,
    _HINFO   = 13,
    _MINFO   = 14,
    _MX      = 15,
    _TXT     = 16,
    _AXFR    =252,
    _MAILB   =253,
    _MAILA   =254,
    _wildcard=255,
};

typedef u16_t RR_QTYPE_t;

///FIXME: Not felixable
typedef RR_QTYPE_t RR_TYPE_t;

const char const *_RR_QTYPE[256] = {
    [0] = "\0",
    [1] = "_A    ",
    [2] = "_NS   ",
    [3] = "_MD   ",
    [4] = "_MF   ",
    [5] = "_CNAME",
    [6] = "_SOA  ",
    [7] = "_MB   ",
    [8] = "_MG   ",
    [9] = "_MR   ",
    [10] = "_NULL ",
    [11] = "_WKS  ",
    [12] = "_PTR  ",
    [13] = "_HINFO",
    [14] = "_MINFO",
    [15] = "_MX   ",
    [16] = "_TXT  ",
    [17 ... 251] = "\0",
    [252] = "_AXFR ",
    [253] = "_MAILB",
    [254] = "_MAILA",
    [255] = "_*    ",
};
#define _RR_TYPE _RR_QTYPE

/*const char const *RR_TYPE[256] = {
    [0] = "\0",
    [1] = "_A    ",
    [2] = "_NS   ",
    [3] = "_MD   ",
    [4] = "_MF   ",
    [5] = "_CNAME",
    [6] = "_SOA  ",
    [7] = "_MB   ",
    [8] = "_MG   ",
    [9] = "_MR   ",
    [10] = "_NULL ",
    [11] = "_WKS  ",
    [12] = "_PTR  ",
    [13] = "_HINFO",
    [14] = "_MINFO",
    [15] = "_MX   ",
    [16] = "_TXT  ",
    [17 ... 255] = "\0",
};*/

/**
 * 3.2.4. CLASS values
 *
 * CLASS fields appear in resource records.
 * and values are defined:
 * The following CLASS mnemonics
 *
 *  IN 1 the Internet
 *  CS 2 the CSNET class (Obsolete - used only for examples in
 *                          some obsolete RFCs)
 *  CH 3 the CHAOS class
 *  HS 4 Hesiod [Dyer 87]
 */
/*typedef enum {
    _IN = 1;
    _CS = 2;
    _CH = 3;
    _HS = 4;
} RR_CLASS_t;*/

/**
 * 3.2.5. QCLASS values
 *
 * QCLASS fields appear in the question section of a query. QCLASS values
 * are a superset of CLASS values; every CLASS is a valid QCLASS. In
 * addition to CLASS values, the following QCLASSes are defined:
 * 
 * *  255 any class
 */
enum {
    _IN = 1,
    _CS = 2,
    _CH = 3,
    _HS = 4,
    _NONE = 254,///DDNS
///FIXME: redeclartion
//    _* =255,
};

typedef u16_t RR_QCLASS_t;

///FIXME: Not felixable
typedef RR_QCLASS_t RR_CLASS_t;

const char const *_RR_QCLASS[256] = {
    [0] = "\0",
    [1] = "_IN",
    [2] = "_CS",
    [3] = "_CH",
    [4] = "_HS",
    ///[5 ... 254] = "\0",
    [5 ... 253] = "\0",
    [254] = "_NONE",///DDNS
    [255] = "_*",
};
#define _RR_CLASS _RR_QCLASS
