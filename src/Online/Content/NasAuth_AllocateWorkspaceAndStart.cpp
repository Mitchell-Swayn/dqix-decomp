#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned DisableInterruptsAndHaltForever(...);
extern "C" unsigned MI_CpuCopy8(...);
extern "C" unsigned OnlineError_SetStatusAndDetail(...);
extern "C" unsigned VectorizedMemset(...);
extern "C" unsigned OnlineMemory_AllocateAligned(...);
extern "C" unsigned OnlineMemory_FreeTagged(...);
extern "C" unsigned NasAuth_AllocateSessionAndStartWorker(...);
// Original data: arm9/ov031 @ 0x2249a88; symbol: data_ov031_02249a88.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasAuthAllocateWorkspaceAndStart_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x224e5bc; symbol: data_ov031_0224e5bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031:022125c8
extern "C" int NasAuth_AllocateWorkspaceAndStart(){if(U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0))DisableInterruptsAndHaltForever();U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0)=OnlineMemory_AllocateAligned(4,0x1e20);if(!U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0)){OnlineError_SetStatusAndDetail(9,0xffffb17c);return 0;}VectorizedMemset((void*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0),0,0x1e20);MI_CpuCopy8(NasAuthAllocateWorkspaceAndStart_UnknownRoleInitializedBytes,(char*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0)+0x1c48,9);U((char*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0),0x1c54)=(unsigned)OnlineMemory_AllocateAligned;U((char*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0),0x1c58)=(unsigned)OnlineMemory_FreeTagged;NasAuth_AllocateSessionAndStartWorker((char*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0)+0x1c14,(void*)U(NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0));return 1;}
