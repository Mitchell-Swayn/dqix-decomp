#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
extern "C" unsigned data_0210fca4;extern "C" SignedAllocatorList data_0210fca8;extern "C" void ResourceEntry_StopRegisteredChannel();extern "C" void DrainPendingOperationsUnderIRQProtection();
struct Node{void(*proc)();void* self;};struct Flags{unsigned first:1,second:1,rest:30;};struct Object{char pad[8];Node a;char pad2[4];Node b;char pad3[8];Flags flags;char pad4[28];unsigned x,y;};
// Original: arm9/main @ 0x020BC8D0; symbol: func_020bc8d0; size: 0x78.
extern "C" ARM void InitializeGlobalCallbacksAndOwnerFlagFields(Object* p){if(!data_0210fca4){data_0210fca8.Initialize(0);data_0210fca4=1;}p->a.proc=ResourceEntry_StopRegisteredChannel;p->a.self=p;p->b.proc=DrainPendingOperationsUnderIRQProtection;p->b.self=p;p->x=0;p->y=0;p->flags.first=0;p->flags.second=0;}
