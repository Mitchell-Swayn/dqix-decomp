#include <std_library_functions.h>

// Original: arm9/main @ 0x020DF80C; symbol: func_020df80c; size: 0x1C.
extern "C" void* ClearObjectPrefix_Clear16Bytes(void* object)
{
    memset(object, 0, 0x10);
    return object;
}
