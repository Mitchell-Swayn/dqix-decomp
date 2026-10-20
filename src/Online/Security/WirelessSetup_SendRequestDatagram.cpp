#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e700; symbol: data_ov031_0224e700.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void*,unsigned,unsigned); extern "C" int WirelessSetup_EncodeNetworkHalfword(unsigned); extern "C" unsigned int WirelessSetup_EncodeNetworkWord(unsigned); extern "C" void StoreByteAndCallWithPointer(int,int,int,int,unsigned char*,unsigned); extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[]; extern "C" signed char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov031 @ 0x0221E080; symbol: ConfigureAndSubmitContextData. Builds and submits an 8-byte context record.
extern "C" void WirelessSetup_SendRequestDatagram(int a,int b,int mode,int callback) { unsigned char rec[8]; Memory_FillBufferWithLowByteUsingVectorizedMemset(rec,0,8); rec[1]=2; *(unsigned short *)(rec+2)=(unsigned short)WirelessSetup_EncodeNetworkHalfword(0x5790); *(int *)(rec+4)=WirelessSetup_EncodeNetworkWord(*(unsigned int *)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+0x34)); if(mode==0xff || AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[0x1c]==0) *(int *)(rec+4)=-1; StoreByteAndCallWithPointer(callback,a,b,0,rec,8); }
