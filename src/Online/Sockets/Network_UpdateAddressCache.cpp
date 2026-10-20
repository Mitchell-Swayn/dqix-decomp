#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned Network_IsAddressWithinConfiguredPrefix(unsigned);
unsigned Network_IsMulticastAddress(unsigned);
unsigned long long _Z19GetCurrentTimestampv();
void MI_CpuCopy8(const void*,void*,unsigned);
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
struct Entry { unsigned address; unsigned char bytes[6]; unsigned short time; };
struct Timestamp { unsigned short value; char pad[10]; };
// Original data: arm9/ov031 @ 0x224ca00; symbol: data_ov031_0224ca00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern Entry NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224ca0a; symbol: data_ov031_0224ca0a.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 86 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern Timestamp NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage_Variant2[];
}
// Original: arm9/ov031 @ 0x02200E38; symbol: func_ov031_02200e38; size: 0x13C.
extern "C" void Network_UpdateAddressCache(const void* bytes,unsigned address,int insert){
if(address==0x7f000001 || address==*(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage+0x50))return;
if(!Network_IsAddressWithinConfiguredPrefix(address))return;
if(Network_IsMulticastAddress(address))return;
unsigned short now=(unsigned short)(_Z19GetCurrentTimestampv()>>16);
unsigned i=0;
Entry* e=NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage;
do {
if(address==e->address){
NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage_Variant2[i].value=now;
MI_CpuCopy8(bytes,NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[i].bytes,6);
return;
}
e++;i++;
}while(i<8);
if(!insert)return;
unsigned index;int oldest=0;index=oldest;
insert=oldest; Entry* second=NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage;
do {
if(!second->address){index=insert;break;}
unsigned age=now-second->time;
if(oldest<(short)age){index=insert;oldest=age&0xffff;}
second++;insert++;
}while((unsigned)insert<8);
NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[index].address=address;
MI_CpuCopy8(bytes,NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[index].bytes,6);
NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage_Variant2[index].value=now;
}
