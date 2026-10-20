#include <globaldefs.h>
#include <System/Memory.h>
ARM
// Original data: arm9/ov031 @ 0x224e69c; symbol: data_ov031_0224e69c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage;
extern "C" char Memory_AllocateAndInitializeGlobalRecord_TextALLOCIntwork[];
extern "C" void OnlineError_SetStatusAndDetail(unsigned int,unsigned int);
typedef void* (*Allocate)(const char*,unsigned int);
// Original: arm9/ov031 @ 0x0221A434; symbol: func_ov031_0221a434; size: 0x98.
extern "C" int Memory_AllocateAndInitializeGlobalRecord(Allocate allocate,void* callback) {
if(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage){OnlineError_SetStatusAndDetail(9,0xffffa1dc);return 0;}
NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage=(unsigned char*)allocate(Memory_AllocateAndInitializeGlobalRecord_TextALLOCIntwork,0x1c20);
if(!NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage){OnlineError_SetStatusAndDetail(9,0xffffa1dc);return 0;}
VectorizedMemset(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage,0,0x1c20);
*(Allocate*)NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage=allocate;
*(void**)(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage+4)=callback;
return 1;
}
