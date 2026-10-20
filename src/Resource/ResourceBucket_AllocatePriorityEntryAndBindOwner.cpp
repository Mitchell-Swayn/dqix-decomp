#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
struct Bucket {SignedAllocatorList list;char pad[12];unsigned limit;char tail[8];};
// Original data: arm9/main @ 0x210f824; symbol: data_0210f824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Bucket AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[];
extern "C" void ResourceHandle_ClearPointedValueAndOwner(SignedAllocatorHeader**);
extern "C" void ResourceEntry_StopHandleAndRelease(SignedAllocatorHeader*);
extern "C" SignedAllocatorHeader* SoundPlayer_AcquireSequencePlayerByPriority(int);
extern "C" void InsertAllocatorEntryByByteRank(SignedAllocatorList*,SignedAllocatorHeader*);
// Original: arm9/main @ 0x020BC454; symbol: func_020bc454; size: 0x98.
extern "C" SignedAllocatorHeader* ResourceBucket_AllocatePriorityEntryAndBindOwner(SignedAllocatorHeader** owner,int bucket,int priority) {Bucket* b=AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage+bucket;if(*owner)ResourceHandle_ClearPointedValueAndOwner(owner);if(b->list.numElements>=b->limit){SignedAllocatorHeader* p=b->list.ElementAfter(0);if(!p)return 0;if(priority<*((unsigned char*)p+0x3d))return 0;ResourceEntry_StopHandleAndRelease(p);}SignedAllocatorHeader* p=SoundPlayer_AcquireSequencePlayerByPriority(priority);if(!p)return 0;InsertAllocatorEntryByByteRank(&b->list,p);*(SignedAllocatorHeader***)p=owner;*owner=p;return p;}
