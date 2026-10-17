#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Flags{signed active:1;unsigned other:31;};struct Entry{unsigned char pad[0x110];Flags flags;unsigned char pad2[0x18];int available;unsigned char pad3[0x1c];void*owner;int priority;unsigned char pad4[0x20];};struct Handle{Entry*entry;};extern "C" Entry data_02110a4c[];extern "C" void ClearLinkedWordField14CAndOwnerPointer(Handle*);extern "C" void ResourceJob_RunCallbacksUnderMutexes(Entry*);
// Original: arm9/main @ 0x020BEE20; symbol: func_020bee20; size: 0x8C.
extern "C" Entry* ResourceManager_ClaimIndexedPriorityEntry(Handle*p,int index,int priority){if(p->entry)ClearLinkedWordField14CAndOwnerPointer(p);Entry*e=data_02110a4c+index;if(!e->available)return 0;if(e->flags.active){if(priority<e->priority)return 0;ResourceJob_RunCallbacksUnderMutexes(e);}e->priority=priority;e->flags.active=-1;e->owner=p;p->entry=e;return e;}
