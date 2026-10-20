#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
// Original data: arm9/main @ 0x210fca4; symbol: data_0210fca4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210fca8; symbol: data_0210fca8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned InitializeGlobalCallbacksAndOwnerFlagFields_UnknownRoleZeroInitializedStorage;extern "C" SignedAllocatorList NNSSndStrmSetup_UnknownRoleZeroInitializedStorage;extern "C" void ResourceEntry_StopRegisteredChannel();extern "C" void DrainPendingOperationsUnderIRQProtection();
struct Node{void(*proc)();void* self;};struct Flags{unsigned first:1,second:1,rest:30;};struct Object{char pad[8];Node a;char pad2[4];Node b;char pad3[8];Flags flags;char pad4[28];unsigned x,y;};
// Original: arm9/main @ 0x020BC8D0; symbol: func_020bc8d0; size: 0x78.
extern "C" ARM void InitializeGlobalCallbacksAndOwnerFlagFields(Object* p){if(!InitializeGlobalCallbacksAndOwnerFlagFields_UnknownRoleZeroInitializedStorage){NNSSndStrmSetup_UnknownRoleZeroInitializedStorage.Initialize(0);InitializeGlobalCallbacksAndOwnerFlagFields_UnknownRoleZeroInitializedStorage=1;}p->a.proc=ResourceEntry_StopRegisteredChannel;p->a.self=p;p->b.proc=DrainPendingOperationsUnderIRQProtection;p->b.self=p;p->x=0;p->y=0;p->flags.first=0;p->flags.second=0;}
