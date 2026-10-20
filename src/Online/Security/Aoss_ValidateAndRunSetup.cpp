#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4c0; symbol: data_ov031_0224f4c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f4cc; symbol: data_ov031_0224f4cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *AossAllocateBuffer_UnknownRoleZeroInitializedStorage,*AossFreeBuffer_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224b070; symbol: data_ov031_0224b070.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2;
extern "C" void FreeAndClearTwoGlobalObjects();
extern "C" void *Aoss_AllocateBuffer(int);
extern "C" void Aoss_FreeBuffer(void*);
extern "C" int Aoss_RunSetupNegotiation(void*);
extern "C" int System_SetGlobalValueAndNotifyOnChange(unsigned);
extern "C" int System_ValidateAndRegisterSharedObject(void*);
// Original: arm9/ov031 @ 0x0221C4BC; symbol: ValidateAndProcessSharedRequest; size: 0xf0.
// Validates signed request bounds and terminator, allocates processing state, dispatches and frees it.
extern "C" int Aoss_ValidateAndRunSetup(unsigned char *request){
int valid;
 if(*(short*)(request+0x106)==0||*(short*)(request+0x106)<-1||*(short*)(request+0x108)<-1||*(short*)(request+0x10a)==0||*(short*)(request+0x10a)<-1||*(short*)(request+0x10c)<-1||*(short*)(request+0x10e)<-1||*(unsigned short*)(request+4)==0||*(unsigned short*)(request+4)>256||(request+6)[*(unsigned short*)(request+4)-1]!=0)valid=-1;else valid=0;
 if(!AossAllocateBuffer_UnknownRoleZeroInitializedStorage||!AossFreeBuffer_UnknownRoleZeroInitializedStorage)valid=-1;
 if(valid==-1){request[0x116]=15;FreeAndClearTwoGlobalObjects();return -1;}
 *(void**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+20)=Aoss_AllocateBuffer(0x5f8);
 if(!*(void**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+20)){request[0x116]=15;FreeAndClearTwoGlobalObjects();return -1;}
 System_SetGlobalValueAndNotifyOnChange(-1);
 int result=Aoss_RunSetupNegotiation(request);
 Aoss_FreeBuffer(*(void**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+20));FreeAndClearTwoGlobalObjects();
 if(AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2!=-1)System_ValidateAndRegisterSharedObject((void*)AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2);
 return result;
}
