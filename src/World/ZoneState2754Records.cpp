#include "World/Zone3DEmbeddedState.h"

// Serialized record areas contain two counts of 32-byte records and an
// optional 88-byte block. Their payload semantics remain unresolved.
unsigned int ZoneState2754::GetRecordStorageSize()
{
    unsigned int secondary = data.secondary.count;
    unsigned int primary = data.primaryCount;
    bool extra = data.secondary.hasExtraBlock;
    unsigned int size = extra ? 88 : 0;
    return size + secondary * 32 + primary * 32;
}

bool ZoneState2754::VisitPrimaryRecords(void (*callback)(ZoneState2754*, void*))
{
    int count;
    char* record = data.records;
    if (!record || !(count = data.primaryCount) || !callback) return false;
    for (int i = 0; i < count; ++i, record += 32)
        callback(this, record);
    return true;
}
