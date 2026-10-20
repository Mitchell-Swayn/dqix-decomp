#include <globaldefs.h>
THUMB
#pragma optimization_level 4
extern "C" void* Aoss_AllocateBuffer(int);
extern "C" void Aoss_FreeBuffer(void*);
extern "C" void Aoss_SetLastError(unsigned);
extern "C" void System_Copy8WithReversedPointers(void*,const void*,unsigned);
extern "C" void WirelessSetup_InitializePermutationCipher(void*,void*,int,int);
extern "C" void System_XorBufferWithObjectByte(void*,unsigned char*,const unsigned char*,unsigned);
extern "C" int System_InvokeWithGlobalBuffer(void*,int);
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
// Original: arm9/ov031 @ 0x0221E164; symbol: TransformPrefixedPayloadAndVerifyByte; size: 0x88.
// Builds prefixed key data, XOR-transforms source, validates output byte and records allocation/validation error codes.
extern "C" int WirelessSetup_DecodeAndVerifyPrefixedPayload(const unsigned char* source,unsigned char* destination,int length,int expected,const void* prefix,const void* payload,int size){
 struct Local {unsigned key[2];void* temp;unsigned reserved;} local;
 local.temp=Aoss_AllocateBuffer(length);if(!local.temp){Aoss_SetLastError(2);return -1;}
 System_Copy8WithReversedPointers(WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage,prefix,2);
 System_Copy8WithReversedPointers(WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage_Variant2,payload,size);
 WirelessSetup_InitializePermutationCipher(local.key,WirelessSetupEncodePrefixedPayload_UnknownRoleZeroInitializedStorage,size+2,length);
 System_XorBufferWithObjectByte(local.key,destination,source,length);
 int actual=System_InvokeWithGlobalBuffer(destination,length);if(actual!=expected){Aoss_SetLastError(18);Aoss_FreeBuffer(local.temp);return -1;}
 Aoss_FreeBuffer(local.temp);return 0;
}
