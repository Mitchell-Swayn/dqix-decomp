#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <Memory/HMRFAllocator.h>
struct Owner{HMRFAllocator*arena;SignedAllocatorList list;};struct Callback{unsigned links[2];unsigned a;void(*fn)(void*,unsigned,unsigned,unsigned);unsigned b,c;char pad[8];char payload[1];};
extern "C" {void System_SubmitCommandOneAtomically();void AllocateTwentyByteNodeAndAppendToAllocatorList(Owner*);}
// Original: arm9/main @ 0x020BD99C; symbol: func_020bd99c; size: 0xBC.
extern "C" ARM void RunReverseCleanupCallbacksAndRemoveGroups(Owner*p){SignedAllocatorList*group;bool ran=false;group=(SignedAllocatorList*)p->list.ElementBefore(0);if(group){do{Callback*n=(Callback*)group->ElementBefore(0);if(n){do{if(n->fn){n->fn(n->payload,n->a,n->b,n->c);ran=true;}n=(Callback*)group->ElementBefore((SignedAllocatorHeader*)n);}while(n);}p->list.Remove((SignedAllocatorHeader*)group);group=(SignedAllocatorList*)p->list.ElementBefore(0);}while(group);}p->arena->Free(3);if(ran)System_SubmitCommandOneAtomically();AllocateTwentyByteNodeAndAppendToAllocatorList(p);}
