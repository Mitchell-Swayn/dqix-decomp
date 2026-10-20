#include <globaldefs.h>
#include "Memory/SignedAllocator.h"
// Original data: arm9/main @ 0x210f824; symbol: data_0210f824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node{unsigned first[2];unsigned value;void* owner;};struct Bucket{unsigned pad[3];SignedAllocatorList list;unsigned remaining[3];};extern "C" Bucket AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[];extern "C" void RunReverseCleanupCallbacksAndRemoveGroups(unsigned);
// Original: arm9/main @ 0x020BC5BC; symbol: func_020bc5bc; size: 0x54.
extern "C" ARM unsigned RemoveFirstBucketNodeAndAttachToOwner(int index,void* owner){Bucket* b=&AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[index];Node* n=(Node*)b->list.ElementAfter(0);if(!n)return 0;b->list.Remove((SignedAllocatorHeader*)n);n->owner=owner;*(Node**)((char*)owner+8)=n;RunReverseCleanupCallbacksAndRemoveGroups(n->value);return n->value;}
