#include "World/Zone3DEmbeddedState.h"

// Serialized record areas contain two counts of 32-byte records and an
// optional 88-byte block. Their payload semantics remain unresolved.
unsigned int ZoneState2754::Data::GetRecordStorageSize()
{
    unsigned int secondary = this->secondary.count;
    unsigned int primary = primaryCount;
    bool extra = this->secondary.hasExtraBlock;
    unsigned int size = extra ? 88 : 0;
    return size + secondary * 32 + primary * 32;
}

bool ZoneState2754::Data::VisitPrimaryRecords(bool (*callback)(ZoneState2754::Data*, void*))
{
    int count;
    char* record = records;
    if (!record || !(count = primaryCount) || !callback) return false;
    for (int i = 0; i < count; ++i, record += 32)
        callback(this, record);
    return true;
}
