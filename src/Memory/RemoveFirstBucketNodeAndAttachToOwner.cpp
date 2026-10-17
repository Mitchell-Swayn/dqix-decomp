#include <globaldefs.h>
#include "Memory/SignedAllocator.h"
struct Node{unsigned first[2];unsigned value;void* owner;};struct Bucket{unsigned pad[3];SignedAllocatorList list;unsigned remaining[3];};extern "C" Bucket data_0210f824[];extern "C" void RunReverseCleanupCallbacksAndRemoveGroups(unsigned);
// Original: arm9/main @ 0x020BC5BC; symbol: func_020bc5bc; size: 0x54.
extern "C" ARM unsigned RemoveFirstBucketNodeAndAttachToOwner(int index,void* owner){Bucket* b=&data_0210f824[index];Node* n=(Node*)b->list.ElementAfter(0);if(!n)return 0;b->list.Remove((SignedAllocatorHeader*)n);n->owner=owner;*(Node**)((char*)owner+8)=n;RunReverseCleanupCallbacksAndRemoveGroups(n->value);return n->value;}
