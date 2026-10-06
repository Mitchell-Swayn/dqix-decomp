#include "System/LoadToVRAM.h"

extern "C" void func_020bbb80(const void* data, unsigned int offset, unsigned int length)
{
    LoadToSubBG2ScreenData(data, offset, length);
}
