#include "globaldefs.h"
#pragma optimize_for_size off
ARM
// Original data: arm9/main @ 0x2110a4c; symbol: data_02110a4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1492 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags{signed active:1;unsigned other:31;};struct Entry{unsigned char pad[0x110];Flags flags;unsigned char pad2[0x18];int available;unsigned char pad3[0x1c];void*owner;int priority;unsigned char pad4[0x20];};struct Handle{Entry*entry;};extern "C" Entry NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6[];extern "C" void NNS_SndStrmHandleRelease(Handle*);extern "C" void ResourceJob_RunCallbacksUnderMutexes(Entry*);
// Original: arm9/main @ 0x020BEE20; symbol: func_020bee20; size: 0x8C.
extern "C" Entry* ResourceManager_ClaimIndexedPriorityEntry(Handle*p,int index,int priority){if(p->entry)NNS_SndStrmHandleRelease(p);Entry*e=NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6+index;if(!e->available)return 0;if(e->flags.active){if(priority<e->priority)return 0;ResourceJob_RunCallbacksUnderMutexes(e);}e->priority=priority;e->flags.active=-1;e->owner=p;p->entry=e;return e;}
