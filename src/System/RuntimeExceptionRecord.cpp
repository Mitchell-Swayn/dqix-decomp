#include "System/RuntimeExceptionRecord.h"
#pragma optimize_for_size off
extern "C" void func_0200ec44(RuntimeExceptionState* state, int recordOffset, int objectOffset)
{
    RuntimeExceptionRecord* record = (RuntimeExceptionRecord*)(state->frame + recordOffset);
    record->object = state->object;
    record->type = state->type;
    record->destroy = state->destroy;
    if (state->type[0] == '*') {
        record->adjusted = &record->indirect;
        record->indirect = *(char**)state->object + objectOffset;
    } else {
        record->adjusted = (char*)state->object + objectOffset;
    }
}
