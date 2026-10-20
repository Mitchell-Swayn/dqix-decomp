#include <globaldefs.h>
THUMB
#pragma optimization_level 4
extern "C" unsigned char System_InvokeWithGlobalBuffer(void*,int);
extern "C" void* Aoss_AllocateBuffer(int);
extern "C" void Aoss_FreeBuffer(void*);
extern "C" unsigned WirelessSetup_GenerateRandomTokenValue();
extern "C" void System_Copy8WithReversedPointers(void*,const void*,unsigned);
extern "C" void WirelessSetup_InitializePermutationCipher(void*,void*,int,int);
extern "C" void System_XorBufferWithObjectByte(void*,unsigned char*,const unsigned char*,unsigned);
// Original data: arm9/ov031 @ 0x224f448; symbol: data_ov031_0224f448.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f44a; symbol: data_ov031_0224f44a.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 118 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage[],WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x0221E0E8; symbol: BuildAndTransformPrefixedPayload; size: 0x7c.
// Builds global prefix and payload bytes, derives a temporary key, then XOR-transforms source into destination.
extern "C" int WirelessSetup_EncodePrefixedPayload(unsigned char* source,unsigned char* destination,int length,unsigned char* flag,void* prefix,void* payload,int size){
 *flag=System_InvokeWithGlobalBuffer(source,length);
 struct Local { unsigned short value; unsigned key[2]; void* temp; unsigned reserved; } local;
 local.temp=Aoss_AllocateBuffer(length);if(!local.temp)return -1;
 local.value=WirelessSetup_GenerateRandomTokenValue();
 System_Copy8WithReversedPointers(prefix,&local.value,2);
 System_Copy8WithReversedPointers(WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage,prefix,2);
 System_Copy8WithReversedPointers(WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage_Variant2,payload,size);
 WirelessSetup_InitializePermutationCipher(local.key,WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage,size+2,length);
 System_XorBufferWithObjectByte(local.key,destination,source,length);
 Aoss_FreeBuffer(local.temp);return 0;
}
