#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x224e5bc; symbol: data_ov031_0224e5bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern void* NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage;unsigned System_ReadGlobalValueUnderMutex();void NasAuth_DestroySession();void OnlineMemory_FreeTagged(void*,void*);void NasAuth_CopyNormalizedResult(unsigned char*);void OnlineError_SetStatusAndDetail(unsigned,unsigned);}
// Original: arm9/ov031 @ 0x0221268C; symbol: System_ConsumePendingOverlayResult; size: 0xf8.
// Consumes pending callback result and translates current status to completion codes; canonical callback prototype has no unused tag argument.
extern "C" int System_ConsumePendingOverlayResult(){unsigned char record[452];if(!NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage)return 0;switch(System_ReadGlobalValueUnderMutex()){case 0:return 2;case 21:NasAuth_DestroySession();((void(*)(void*,void*,unsigned))OnlineMemory_FreeTagged)((void*)4,NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0x1e20);NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage=0;return 3;case 20:NasAuth_DestroySession();((void(*)(void*,void*,unsigned))OnlineMemory_FreeTagged)((void*)4,NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0x1e20);NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage=0;return 5;default:NasAuth_CopyNormalizedResult(record);NasAuth_DestroySession();((void(*)(void*,void*,unsigned))OnlineMemory_FreeTagged)((void*)4,NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage,0x1e20);NasAuthAllocateWorkspaceAndStart_UnknownRoleZeroInitializedStorage=0;OnlineError_SetStatusAndDetail(2,W(record,0));return 4;}}
