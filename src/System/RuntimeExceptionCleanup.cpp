#include "System/RuntimeExceptionRecord.h"
#pragma optimize_for_size off
extern "C" void func_0200ed8c(RuntimeExceptionRecord* record)
{
    if (record->object && record->destroy)
        record->destroy(record->object, -1);
}
extern "C" void func_02001728(void*);
extern "C" void func_0200edb4(void* pointer)
{
    if (pointer)
        func_02001728(pointer);
}
