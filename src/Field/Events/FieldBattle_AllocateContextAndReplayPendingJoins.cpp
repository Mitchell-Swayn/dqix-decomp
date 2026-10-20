#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#include <std_library_functions.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" void AllocatorUnion_LeaveUnchanged(void*);extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void GameState_ResetExtendedStateAndRandomSeed(char*);extern "C" void Combat_PushPendingPartyJoin(char*,int);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021B71D8; symbol: AllocateExtendedStateAndReplayQueuedByteKeys; size: 0xac.
extern "C" void FieldBattle_AllocateContextAndReplayPendingJoins(char* self){
_ZN9GameState11GetInstanceEv();unsigned short* global=Zone3D_GetMainInstance();AllocatorUnion_LeaveUnchanged(Main_UnknownRoleZeroInitializedStorage_Variant3);Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x1f7dc);void* memory=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x1f7dc);_ZN13SafeAllocator11CreateTypeAEPvj(self+8,memory,0x1f7dc);*(unsigned short*)(self+28)=*global;char* state=_ZN13SafeAllocator8AllocateEj(self+8,0x8eb4);P(self,0x6b0)=state;GameState_ResetExtendedStateAndRandomSeed(state);for(int i=0;i<B(self,0x6c3);i++)Combat_PushPendingPartyJoin(P(self,0x6b0),B(self+i,0x6c0));memset(self+0x6c0,0,3);B(self,0x6c3)=0;
}
