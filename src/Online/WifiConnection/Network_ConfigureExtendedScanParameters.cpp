#include <globaldefs.h>
ARM
extern "C" {
void Network_UpdateGlobalFlagsAtomically(void*);
int Util_FindNextEnabledBitModuloThirteen(int);
unsigned short WM_GetDispersionScanPeriod();
void MI_CpuCopy8(const void*,void*,unsigned);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2245fb0; symbol: data_ov031_02245fb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2245fb8; symbol: data_ov031_02245fb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes[],NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2[];
}
// Original: arm9/ov031 @ 0x0220D73C; symbol: func_ov031_0220d73c; size: 0x198.
extern "C" void Network_ConfigureExtendedScanParameters(const void* address,const unsigned char* name,void* config){
Network_UpdateGlobalFlagsAtomically(config);
*(char**)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2288)=NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x1500;
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x228c)=0x400;
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x228e)=(1<<Util_FindNextEnabledBitModuloThirteen(0))>>1;
unsigned short checksum=*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2268);
if(!checksum)checksum=WM_GetDispersionScanPeriod();
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2290)=checksum;
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2298)=(*(unsigned*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2264)&0x300000)!=0x300000;
if(!address)MI_CpuCopy8(NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2292,6);
else MI_CpuCopy8(address,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2292,6);
if(!name || name==NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2){
MI_CpuCopy8(NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x229c,32);
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x229a)=0;
}else{
MI_CpuCopy8(name,NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x229c,32);
int len=0;
do{if(!*name)break;len++;name++;}while(len<32);
*(unsigned short*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x229a)=len;
}
*(unsigned*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2284)=0;
}
