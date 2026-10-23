#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma opt_common_subs off
extern "C" unsigned Util_CompareThreeHalfwords(const unsigned short*,const unsigned short*);
extern "C" void Network_UpdateAddressCache(const void*,unsigned,int);
extern "C" void Network_BuildAndSendArpReply(char*);
// Original data: arm9/ov031 @ 0x0224C980 and 0x0224CE68; symbols: data_ov031_0224c980, data_ov031_0224ce68.
// Opaque fallback storage, zero-filled BSS. Non-owning object-representation views;
// logical storage type and extent remain unresolved and require owning-type migration.
// Proven accesses: local IPv4 word at C980+0x50, status byte C980+1, six MAC bytes at CE68.
// Values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
inline unsigned short SwapArpHalfword(unsigned short value){return (value>>8)|(value<<8);}
#define HALF(p,o) (*(unsigned short*)((p)+(o)))
// Original: arm9/ov031 @ 0x0220186C; symbol: func_ov031_0220186c; size: 0x144.
// Validates an Ethernet/IPv4 ARP message, updates peer cache and handles local address requests/replies.
extern "C" void Network_ProcessReceivedArpPacket(unsigned char* packet,unsigned size)
{
 if(size<28)return;
 if(!Util_CompareThreeHalfwords((const unsigned short*)(packet+8),(const unsigned short*)NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage)||!*(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage+0x50))return;
 if(HALF(packet,0)!=0x100||HALF(packet,2)!=8||HALF(packet,4)!=0x406)return;
 unsigned short operation=SwapArpHalfword(HALF(packet,6));
 if(operation!=1&&operation!=2)return;
 unsigned short senderLow=HALF(packet,16);
 unsigned short senderHigh=HALF(packet,14);
 unsigned short targetLow=HALF(packet,26);
 unsigned short targetHigh=HALF(packet,24);
 unsigned sender=((unsigned)SwapArpHalfword(senderHigh)<<16)|SwapArpHalfword(senderLow);
 unsigned target=((unsigned)SwapArpHalfword(targetHigh)<<16)|SwapArpHalfword(targetLow);
 unsigned own=*(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage+0x50);
 int fromOwn=sender==own;
 int forOwn=own==target;
 if(!fromOwn)Network_UpdateAddressCache(packet+8,sender,forOwn);
 if(operation==1&&forOwn){Network_BuildAndSendArpReply((char*)packet);return;}
 if(operation==2&&forOwn&&fromOwn)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[1]=1;
}
