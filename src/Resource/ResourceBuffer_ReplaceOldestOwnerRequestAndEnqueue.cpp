#pragma optimization_level 4
#pragma optimize_for_size off
#include "Memory/SignedAllocator.h"
#include "System/ProcessorContext.h"
struct ResourceBufferOwner { unsigned char unknown0[0x11c]; int queuedCount; };
struct ResourceBufferRequest {
    void* links[2];
    ResourceBufferOwner* owner;
    int kind;
    int bufferCount;
    void* buffers[6];
    unsigned int bufferSize;
};
struct ResourceBufferQueue {
    unsigned char unknown0[0x4c0];
    BlockedContextList blocked;
    unsigned char unknown4c8[0x18];
    SignedAllocatorList requests;
};
extern "C" {
// Original data: arm9/main @ 0x2110a40; symbol: data_02110a40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SignedAllocatorList SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2110560; symbol: data_02110560.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1224 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ResourceBufferQueue NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant5;
// Original data: arm9/main @ 0x21103b0; symbol: data_021103b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ResourceBufferQueue* NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[];
SignedAllocatorHeader* RemoveFirstGlobalAllocatorEntryUnderIRQProtection();
void SoundStream_RecycleBufferRequestAtomically(SignedAllocatorHeader*);
void VectorizedMemset(void*,int,unsigned);
}
// Original: arm9/main @ 0x020BF520; symbol: func_020bf520; size: 0x138.
// Replaces an older queued buffer request when its owner has two pending, then wakes the queue.
// The fifth incoming argument is ignored; its local slot is reused as a loop counter.
extern "C" void ResourceBuffer_ReplaceOldestOwnerRequestAndEnqueue(int kind, int count, void** buffers, unsigned int size, int i, void* ownerArg)
{
    ResourceBufferOwner* owner=(ResourceBufferOwner*)ownerArg;
    if(owner->queuedCount>=2) {
        ResourceBufferRequest* old;
        old=(ResourceBufferRequest*)SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage.ElementAfter(0);
        if(old) do {
            if(old->owner==owner) break;
            old=(ResourceBufferRequest*)SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage.ElementAfter((SignedAllocatorHeader*)old);
        } while(old);
        i=0;
        if(old->bufferCount>0) {
            do { VectorizedMemset(old->buffers[i],0,old->bufferSize); ++i; } while(i<old->bufferCount);
        }
        SoundStreamFinalizePlayerAndCancelRequests_UnknownRoleZeroInitializedStorage.Remove((SignedAllocatorHeader*)old);
        owner->queuedCount--;
        SoundStream_RecycleBufferRequestAtomically((SignedAllocatorHeader*)old);
    }
    ResourceBufferRequest* request=(ResourceBufferRequest*)RemoveFirstGlobalAllocatorEntryUnderIRQProtection();
    request->owner=owner;
    request->kind=kind;
    request->bufferCount=count;
    i=0;
    if(count>0) do { request->buffers[i]=buffers[i]; ++i; } while(i<count);
    request->bufferSize=size;
    ResourceBufferQueue* queue=&NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant5;
    if(kind==0 && NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]) queue=NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1];
    owner->queuedCount++;
    queue->requests.InsertAtEnd((SignedAllocatorHeader*)request);
    UnblockContexts(&queue->blocked);
}
