#include "System/RuntimeFloatConstants.h"
#pragma optimize_for_size off

extern "C" double func_0200c578(float);
extern "C" void func_0200ab10(void*);

// Convert the runtime's stored binary32 NaN through its existing converter.
extern "C" double func_02001710()
{
    return func_0200c578(data_020eecc8.value);
}
extern "C" void func_02001728(void* pointer)
{
    if (pointer)
        func_0200ab10(pointer);
}
