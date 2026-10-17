// Original: arm9/main @ 0x0200ED8C; symbol: func_0200ed8c; size: 0x28.
// Compiler runtime support: __end__catch.
// Already matching C retained; excluded from further C reconstruction.
#include "System/RuntimeExceptionRecord.h"
#pragma optimize_for_size off
extern "C" void RuntimeExceptionRecord_DestroyExceptionObject(RuntimeExceptionRecord* record)
{
    if (record->object && record->destroy)
        record->destroy(record->object, -1);
}
extern "C" void Runtime_ReleaseNonNullPointer(void*);
// Original: arm9/main @ 0x0200EDB4; symbol: func_0200edb4; size: 0x14.
extern "C" void Runtime_ReleaseNonNullPointerIndirect(void* pointer)
{
    if (pointer)
        Runtime_ReleaseNonNullPointer(pointer);
}
