#include <globaldefs.h>
#include "Resource/GameResources.h"
extern "C" void AllocatorUnion_FreeIfRequested(void*,void*,unsigned),AllocatorUnion_LeaveUnchanged(void*);
// This original overlay cleanup entry has no static caller.
#pragma force_active on
// Original: arm9/ov030 @ 0x021D92F0; symbol: func_ov030_021d92f0; size: 0x50.
extern "C" ARM void func_ov030_021d92f0(GameResources* resources,void* owner,void** arena){if(resources)AllocatorUnion_FreeIfRequested(owner,resources,1);if(*arena){AllocatorUnion_FreeIfRequested(owner,*arena,0x36c0);*arena=0;}AllocatorUnion_LeaveUnchanged(owner);}

#pragma force_active reset
