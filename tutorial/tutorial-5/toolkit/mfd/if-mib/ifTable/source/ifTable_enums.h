/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c,v 1.2 2004/02/29 23:02:51 rstory Exp $
 *
 * $Id$
 */
#ifndef IFTABLE_ENUMS_H
#define IFTABLE_ENUMS_H

#include <net/if_arp.h>

#ifdef __cplusplus
extern          "C" {
#endif

    /*
     * NOTES on emus
     * =============
     *
     * Value Mapping
     * -------------
     * If the values for your data type don't exactly match the
     * possible values defined by the mib, you should map them
     * below. For example, a boolean flag (1/0) is usually represented
     * as a TruthValue in a MIB, which maps to the values (1/2).
     *
     */

/*************************************************************************
 *************************************************************************
 *
 * enum definitions for table ifTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * ifType (IANAifType / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef IANAifType_ENUMS
#define IANAifType_ENUMS

#define IANAifType_OTHER  1
#define IANAifType_REGULAR1822  2
#define IANAifType_HDH1822  3
#define IANAifType_DDNX25  4
#define IANAifType_RFC877X25  5
#define IANAifType_ETHERNETCSMACD  6
#define IANAifType_ISO88023CSMACD  7
#define IANAifType_ISO88024TOKENBUS  8
#define IANAifType_ISO88025TOKENRING  9
#define IANAifType_ISO88026MAN  10
#define IANAifType_STARLAN  11
#define IANAifType_PROTEON10MBIT  12
#define IANAifType_PROTEON80MBIT  13
#define IANAifType_HYPERCHANNEL  14
#define IANAifType_FDDI  15
#define IANAifType_LAPB  16
#define IANAifType_SDLC  17
#define IANAifType_DS1  18
#define IANAifType_E1  19
#define IANAifType_BASICISDN  20
#define IANAifType_PRIMARYISDN  21
#define IANAifType_PROPPOINTTOPOINTSERIAL  22
#define IANAifType_PPP  23
#define IANAifType_SOFTWARELOOPBACK  24
#define IANAifType_EON  25
#define IANAifType_ETHERNET3MBIT  26
#define IANAifType_NSIP  27
#define IANAifType_SLIP  28
#define IANAifType_ULTRA  29
#define IANAifType_DS3  30
#define IANAifType_SIP  31
#define IANAifType_FRAMERELAY  32
#define IANAifType_RS232  33
#define IANAifType_PARA  34
#define IANAifType_ARCNET  35
#define IANAifType_ARCNETPLUS  36
#define IANAifType_ATM  37
#define IANAifType_MIOX25  38
#define IANAifType_SONET  39
#define IANAifType_X25PLE  40
#define IANAifType_ISO88022LLC  41
#define IANAifType_LOCALTALK  42
#define IANAifType_SMDSDXI  43
#define IANAifType_FRAMERELAYSERVICE  44
#define IANAifType_V35  45
#define IANAifType_HSSI  46
#define IANAifType_HIPPI  47
#define IANAifType_MODEM  48
#define IANAifType_AAL5  49
#define IANAifType_SONETPATH  50
#define IANAifType_SONETVT  51
#define IANAifType_SMDSICIP  52
#define IANAifType_PROPVIRTUAL  53
#define IANAifType_PROPMULTIPLEXOR  54
#define IANAifType_IEEE80212  55
#define IANAifType_FIBRECHANNEL  56
#define IANAifType_HIPPIINTERFACE  57
#define IANAifType_FRAMERELAYINTERCONNECT  58
#define IANAifType_AFLANE8023  59
#define IANAifType_AFLANE8025  60
#define IANAifType_CCTEMUL  61
#define IANAifType_FASTETHER  62
#define IANAifType_ISDN  63
#define IANAifType_V11  64
#define IANAifType_V36  65
#define IANAifType_G703AT64K  66
#define IANAifType_G703AT2MB  67
#define IANAifType_QLLC  68
#define IANAifType_FASTETHERFX  69
#define IANAifType_CHANNEL  70
#define IANAifType_IEEE80211  71
#define IANAifType_IBM370PARCHAN  72
#define IANAifType_ESCON  73
#define IANAifType_DLSW  74
#define IANAifType_ISDNS  75
#define IANAifType_ISDNU  76
#define IANAifType_LAPD  77
#define IANAifType_IPSWITCH  78
#define IANAifType_RSRB  79
#define IANAifType_ATMLOGICAL  80
#define IANAifType_DS0  81
#define IANAifType_DS0BUNDLE  82
#define IANAifType_BSC  83
#define IANAifType_ASYNC  84
#define IANAifType_CNR  85
#define IANAifType_ISO88025DTR  86
#define IANAifType_EPLRS  87
#define IANAifType_ARAP  88
#define IANAifType_PROPCNLS  89
#define IANAifType_HOSTPAD  90
#define IANAifType_TERMPAD  91
#define IANAifType_FRAMERELAYMPI  92
#define IANAifType_X213  93
#define IANAifType_ADSL  94
#define IANAifType_RADSL  95
#define IANAifType_SDSL  96
#define IANAifType_VDSL  97
#define IANAifType_ISO88025CRFPINT  98
#define IANAifType_MYRINET  99
#define IANAifType_VOICEEM  100
#define IANAifType_VOICEFXO  101
#define IANAifType_VOICEFXS  102
#define IANAifType_VOICEENCAP  103
#define IANAifType_VOICEOVERIP  104
#define IANAifType_ATMDXI  105
#define IANAifType_ATMFUNI  106
#define IANAifType_ATMIMA  107
#define IANAifType_PPPMULTILINKBUNDLE  108
#define IANAifType_IPOVERCDLC  109
#define IANAifType_IPOVERCLAW  110
#define IANAifType_STACKTOSTACK  111
#define IANAifType_VIRTUALIPADDRESS  112
#define IANAifType_MPC  113
#define IANAifType_IPOVERATM  114
#define IANAifType_ISO88025FIBER  115
#define IANAifType_TDLC  116
#define IANAifType_GIGABITETHERNET  117
#define IANAifType_HDLC  118
#define IANAifType_LAPF  119
#define IANAifType_V37  120
#define IANAifType_X25MLP  121
#define IANAifType_X25HUNTGROUP  122
#define IANAifType_TRASNPHDLC  123
#define IANAifType_INTERLEAVE  124
#define IANAifType_FAST  125
#define IANAifType_IP  126
#define IANAifType_DOCSCABLEMACLAYER  127
#define IANAifType_DOCSCABLEDOWNSTREAM  128
#define IANAifType_DOCSCABLEUPSTREAM  129
#define IANAifType_A12MPPSWITCH  130
#define IANAifType_TUNNEL  131
#define IANAifType_COFFEE  132
#define IANAifType_CES  133
#define IANAifType_ATMSUBINTERFACE  134
#define IANAifType_L2VLAN  135
#define IANAifType_L3IPVLAN  136
#define IANAifType_L3IPXVLAN  137
#define IANAifType_DIGITALPOWERLINE  138
#define IANAifType_MEDIAMAILOVERIP  139
#define IANAifType_DTM  140
#define IANAifType_DCN  141
#define IANAifType_IPFORWARD  142
#define IANAifType_MSDSL  143
#define IANAifType_IEEE1394  144
#define IANAifType_IF_GSN  145
#define IANAifType_DVBRCCMACLAYER  146
#define IANAifType_DVBRCCDOWNSTREAM  147
#define IANAifType_DVBRCCUPSTREAM  148
#define IANAifType_ATMVIRTUAL  149
#define IANAifType_MPLSTUNNEL  150
#define IANAifType_SRP  151
#define IANAifType_VOICEOVERATM  152
#define IANAifType_VOICEOVERFRAMERELAY  153
#define IANAifType_IDSL  154
#define IANAifType_COMPOSITELINK  155
#define IANAifType_SS7SIGLINK  156
#define IANAifType_PROPWIRELESSP2P  157
#define IANAifType_FRFORWARD  158
#define IANAifType_RFC1483  159
#define IANAifType_USB  160
#define IANAifType_IEEE8023ADLAG  161
#define IANAifType_BGPPOLICYACCOUNTING  162
#define IANAifType_FRF16MFRBUNDLE  163
#define IANAifType_H323GATEKEEPER  164
#define IANAifType_H323PROXY  165
#define IANAifType_MPLS  166
#define IANAifType_MFSIGLINK  167
#define IANAifType_HDSL2  168
#define IANAifType_SHDSL  169
#define IANAifType_DS1FDL  170
#define IANAifType_POS  171
#define IANAifType_DVBASIIN  172
#define IANAifType_DVBASIOUT  173
#define IANAifType_PLC  174
#define IANAifType_NFAS  175
#define IANAifType_TR008  176
#define IANAifType_GR303RDT  177
#define IANAifType_GR303IDT  178
#define IANAifType_ISUP  179
#define IANAifType_PROPDOCSWIRELESSMACLAYER  180
#define IANAifType_PROPDOCSWIRELESSDOWNSTREAM  181
#define IANAifType_PROPDOCSWIRELESSUPSTREAM  182
#define IANAifType_HIPERLAN2  183
#define IANAifType_PROPBWAP2MP  184
#define IANAifType_SONETOVERHEADCHANNEL  185
#define IANAifType_DIGITALWRAPPEROVERHEADCHANNEL  186
#define IANAifType_AAL2  187
#define IANAifType_RADIOMAC  188
#define IANAifType_ATMRADIO  189
#define IANAifType_IMT  190
#define IANAifType_MVL  191
#define IANAifType_REACHDSL  192
#define IANAifType_FRDLCIENDPT  193
#define IANAifType_ATMVCIENDPT  194
#define IANAifType_OPTICALCHANNEL  195
#define IANAifType_OPTICALTRANSPORT  196
#define IANAifType_PROPATM  197
#define IANAifType_VOICEOVERCABLE  198
#define IANAifType_INFINIBAND  199
#define IANAifType_TELINK  200
#define IANAifType_Q2931  201
#define IANAifType_VIRTUALTG  202
#define IANAifType_SIPTG  203
#define IANAifType_SIPSIG  204
#define IANAifType_DOCSCABLEUPSTREAMCHANNEL  205
#define IANAifType_ECONET  206
#define IANAifType_PON155  207
#define IANAifType_PON622  208
#define IANAifType_BRIDGE  209
#define IANAifType_LINEGROUP  210
#define IANAifType_VOICEEMFGD  211
#define IANAifType_VOICEFGDEANA  212
#define IANAifType_VOICEDID  213
#define IANAifType_MPEGTRANSPORT  214
#define IANAifType_SIXTOFOUR  215
#define IANAifType_GTP  216
#define IANAifType_PDNETHERLOOP1  217
#define IANAifType_PDNETHERLOOP2  218
#define IANAifType_OPTICALCHANNELGROUP  219
#define IANAifType_HOMEPNA  220
#define IANAifType_GFP  221


#endif                          /* IANAifType_ENUMS */

    /*
     * TODO:
     * value mapping (see notes at top of file)
     */
#define INTERNAL_IFTYPE_ETHERNETCSMACD  ARPHRD_ETHER
#define INTERNAL_IFTYPE_FDDI  ARPHRD_FDDI
#define INTERNAL_IFTYPE_PPP  ARPHRD_PPP
#define INTERNAL_IFTYPE_SOFTWARELOOPBACK  ARPHRD_LOOPBACK
#define INTERNAL_IFTYPE_SLIP  ARPHRD_SLIP
#define INTERNAL_IFTYPE_ARCNET  ARPHRD_ARCNET
#ifdef ARPHRD_ATM
#define INTERNAL_IFTYPE_ATM  ARPHRD_ATM
#endif
#define INTERNAL_IFTYPE_LOCALTALK  ARPHRD_LOCALTLK
#ifdef ARPHRD_HIPPI
#define INTERNAL_IFTYPE_HIPPI  ARPHRD_HIPPI
#endif
#define INTERNAL_IFTYPE_TUNNEL  ARPHRD_TUNNEL

/*************************************************************
 * constants for enums for the MIB node
 * ifAdminStatus (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef ifAdminStatus_ENUMS
#define ifAdminStatus_ENUMS

#define ifAdminStatus_UP  1
#define ifAdminStatus_DOWN  2
#define ifAdminStatus_TESTING  3


#endif                          /* ifAdminStatus_ENUMS */

    /*
     * TODO:
     * value mapping (see notes at top of file)
     */
#define INTERNAL_IFADMINSTATUS_UP  1
#define INTERNAL_IFADMINSTATUS_DOWN  2
#define INTERNAL_IFADMINSTATUS_TESTING  3

/*************************************************************
 * constants for enums for the MIB node
 * ifOperStatus (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef ifOperStatus_ENUMS
#define ifOperStatus_ENUMS

#define ifOperStatus_UP  1
#define ifOperStatus_DOWN  2
#define ifOperStatus_TESTING  3
#define ifOperStatus_UNKNOWN  4
#define ifOperStatus_DORMANT  5
#define ifOperStatus_NOTPRESENT  6
#define ifOperStatus_LOWERLAYERDOWN  7


#endif                          /* ifOperStatus_ENUMS */

    /*
     * TODO:
     * value mapping (see notes at top of file)
     */
#define INTERNAL_IFOPERSTATUS_UP  1
#define INTERNAL_IFOPERSTATUS_DOWN  2
#define INTERNAL_IFOPERSTATUS_TESTING  3
#define INTERNAL_IFOPERSTATUS_UNKNOWN  4
#define INTERNAL_IFOPERSTATUS_DORMANT  5
#define INTERNAL_IFOPERSTATUS_NOTPRESENT  6
#define INTERNAL_IFOPERSTATUS_LOWERLAYERDOWN  7




#ifdef __cplusplus
};
#endif

#endif                          /* IFTABLE_ENUMS_H */
