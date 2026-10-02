#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

extern "C" void func_020de574(ZoneState2754*, void*);
extern "C" bool func_020de5b0(ZoneState2754*);

bool ZoneState2754::LoadSerializedData(void* file, unsigned int size)
{
    if (!file || !size) return false;
    bool alreadyRelocated;
    AttachSerializedData(file, &alreadyRelocated, func_020de574);
    if (alreadyRelocated) return true;
    return func_020de5b0(this);
}

bool ZoneState2754::AttachSerializedData(void* file, bool* alreadyRelocated, void (*callback)(ZoneState2754*, void*))
{
    *alreadyRelocated = false;
    if (!file) return false;
    memcpy(&data, file, 12);
    data.records = (char*)file + 12;
    data.payload = (char*)file + (GetRecordStorageSize() + 12);
    if (data.relocated)
    {
        *alreadyRelocated = true;
        return true;
    }
    VisitPrimaryRecords(callback);
    data.relocated = 1;
    // Only the serialized 12-byte header prefix is accessed through this view.
    ((Data*)file)->relocated = 1;
    return true;
}
