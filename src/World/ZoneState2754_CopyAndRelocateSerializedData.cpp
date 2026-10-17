#include <globaldefs.h>
#pragma always_inline on
#include <World/Zone3DEmbeddedState.h>
#include <std_library_functions.h>
static inline bool CopySerializedState(ZoneState2754::Data* state,SafeAllocator* allocator,void* raw,bool(*callback)(ZoneState2754::Data*,void*))
{
    if(!allocator||!raw) return false;
    memcpy(state,raw,12);
    unsigned payloadSize;unsigned recordsSize=state->GetRecordStorageSize();
    payloadSize=state->payloadSize;
    if(recordsSize) state->records=(char*)allocator->Allocate(recordsSize);else state->records=0;
    if(payloadSize) state->payload=allocator->Allocate(payloadSize);else state->payload=0;
    if(state->records) memcpy(state->records,(char*)raw+12,recordsSize);
    if(state->payload) memcpy(state->payload,(char*)raw+(state->GetRecordStorageSize()+12),payloadSize);
    if((unsigned)callback) state->VisitPrimaryRecords(callback);
    state->relocated=1;
    return true;
}
// Original: arm9/main @ 0x020DE888; symbol: func_020de888; size: 0xF8.
// Copies serialized record and payload storage into allocator-owned buffers and relocates links.
extern "C" ARM bool ZoneState2754_CopyAndRelocateSerializedData(ZoneState2754::Data* state,SafeAllocator* allocator,void* raw,unsigned size)
{
    if(!allocator||!raw||!size) return false;
    CopySerializedState(state,allocator,raw,RelocateSerializedRecordPayload);
    return state->RelocateSecondaryRecordLinks();
}
