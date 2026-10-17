#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
struct ResourceHeader { unsigned count:12; unsigned payloadSize:19; unsigned owned:1; };
struct Resource { ResourceHeader header; void* records; void* payload; };
extern "C" unsigned PackedRecord_ComputeEightTimesLowTwelveBits(Resource*);
// Original: arm9/main @ 0x02079BAC; symbol: func_02079bac; size: 0x13C.
extern "C" bool Resource_CopyOwnedPayloadAndVisitRecords(Resource* resource,SafeAllocator* allocator,const char* input,void (*visit)(Resource*,void*),void (*finish)(Resource*),SafeAllocator* payloadAllocator)
{
    if(!allocator || !input) return false;
    if(!payloadAllocator) payloadAllocator=allocator;
    memcpy(resource,input,4);
    unsigned recordSize=PackedRecord_ComputeEightTimesLowTwelveBits(resource);
    unsigned payloadSize=resource->header.payloadSize;
    resource->records=recordSize?allocator->Allocate(recordSize):0;
    resource->payload=payloadSize?payloadAllocator->Allocate(payloadSize):0;
    if(resource->records) memcpy(resource->records,input+4,recordSize);
    if(resource->payload) memcpy(resource->payload,input+(PackedRecord_ComputeEightTimesLowTwelveBits(resource)+4),payloadSize);
    char* record;
    if(visit && (record=(char*)resource->records)) {
        int count=resource->header.count;
        if(count && visit) {
            for(recordSize=0;(int)recordSize<count;recordSize++,record+=8) visit(resource,record);
        }
    }
    if(finish) finish(resource);
    resource->header.owned=1;
    return true;
}
