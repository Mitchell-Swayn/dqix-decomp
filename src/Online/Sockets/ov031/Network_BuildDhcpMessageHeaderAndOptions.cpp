#pragma thumb off
#pragma optimize_for_size off
#include "System/Memory.h"
struct RandomState {char pad[0x50];unsigned address;char pad54[0x14];unsigned long long seed,multiplier,increment;};
extern "C" RandomState NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
extern "C" char Network_BuildDhcpMessageHeaderAndOptions_TextNintendoDS[12];
#pragma inline_depth(8)
static inline unsigned short SwapHalf(unsigned short value) {return (value>>8)|(value<<8);}
// Original: arm9/ov031 @ 0x02203FDC; symbol: Network_BuildDhcpMessageHeaderAndOptions; size: 0x18C.
extern "C" unsigned char* Network_BuildDhcpMessageHeaderAndOptions(unsigned char* packet,int messageType,unsigned* transactionOut) {
 VectorizedMemset(packet,0,0xec);
 *(unsigned short*)packet=0x101;packet[2]=6;
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.multiplier*NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.increment;
 unsigned transaction=(unsigned)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed>>32);
 if(transactionOut)*transactionOut=transaction;
 *(unsigned short*)(packet+4)=SwapHalf(transaction>>16);
 *(unsigned short*)(packet+6)=SwapHalf(transaction);
 *(unsigned short*)(packet+12)=SwapHalf(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address>>16);
 *(unsigned short*)(packet+14)=SwapHalf(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address);
 MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,packet+0x1c,6);
 *(unsigned short*)(packet+0xec)=0x8263;*(unsigned short*)(packet+0xee)=0x6353;
 *(unsigned short*)(packet+0xf0)=0x135;packet[0xf2]=messageType;
 packet[0xf3]=0x3d;packet[0xf4]=7;packet[0xf5]=1;
 MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,packet+0xf6,6);
 packet[0xfc]=12;packet[0xfd]=10;
 MI_CpuCopy8(Network_BuildDhcpMessageHeaderAndOptions_TextNintendoDS,packet+0xfe,10);
 packet[0x108]=0x37;packet[0x109]=3;packet[0x10a]=1;packet[0x10b]=3;packet[0x10c]=6;
 return packet+0x10d;
}
