#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"


bool ZoneState2754::Data::LoadSerializedData(void* file, unsigned int size)
{
    if (!file || !size) return false;
    bool alreadyRelocated;
    AttachSerializedData(file, &alreadyRelocated, RelocateSerializedRecordPayload);
    if (alreadyRelocated) return true;
    return RelocateSecondaryRecordLinks();
}

bool ZoneState2754::Data::AttachSerializedData(void* file, bool* alreadyRelocated, bool (*callback)(ZoneState2754::Data*, void*))
{
    *alreadyRelocated = false;
    if (!file) return false;
    memcpy(this, file, 12);
    records = (char*)file + 12;
    payload = (char*)file + (GetRecordStorageSize() + 12);
    if (relocated)
    {
        *alreadyRelocated = true;
        return true;
    }
    VisitPrimaryRecords(callback);
    relocated = 1;
    // Only the serialized 12-byte header prefix is accessed through this view.
    ((Data*)file)->relocated = 1;
    return true;
}
