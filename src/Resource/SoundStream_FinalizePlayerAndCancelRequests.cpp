#include <globaldefs.h>
// Original data: arm9/main @ 0x21103b0; symbol: data_021103b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110a40; symbol: data_02110a40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Obj { unsigned char pad[0x110]; int active:1; unsigned rest:31; unsigned char pad2[0x54];void (*callback)(Obj *); }; extern "C" unsigned char SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage[]; extern "C" void *NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[]; extern "C" void ResourceJob_DecrementCounterAndCompleteAtZero(Obj *); extern "C" void RemoveMatchingAllocatorNodesWithIRQDisabled(void *,Obj *); extern "C" void SoundStream_ReleasePlayerHandleAndPlaybackState(Obj *);
// Original: arm9/main @ 0x020BF238; symbol: func_020bf238; size: 0x64.
 extern "C" void SoundStream_FinalizePlayerAndCancelRequests(Obj *p) { if(!p->active) return;ResourceJob_DecrementCounterAndCompleteAtZero(p);p->callback(p);RemoveMatchingAllocatorNodesWithIRQDisabled(SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage,p);if(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]) RemoveMatchingAllocatorNodesWithIRQDisabled((unsigned char *)NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]+0x4e0,p);SoundStream_ReleasePlayerHandleAndPlaybackState(p); }
