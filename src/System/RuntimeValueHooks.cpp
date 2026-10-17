#include "System/RuntimeFloatConstants.h"
#pragma optimize_for_size off

extern "C" double _f2d(float);
extern "C" void RuntimeFreeDefault_FreeDefaultArenaHeapBlock(void*);

// Convert the runtime's stored binary32 NaN through its existing converter.
// Original: arm9/main @ 0x02001710; symbol: func_02001710; size: 0x18.
extern "C" double RuntimeValueHooks_ConvertStoredValueToDouble()
{
    return _f2d(data_020eecc8.value);
}
// Original: arm9/main @ 0x02001728; symbol: func_02001728; size: 0x14.
extern "C" void Runtime_ReleaseNonNullPointer(void* pointer)
{
    if (pointer)
        RuntimeFreeDefault_FreeDefaultArenaHeapBlock(pointer);
}
