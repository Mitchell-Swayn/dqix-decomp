// Compiler runtime support: __clear.
// Already matching C retained; excluded from further C reconstruction.
#pragma optimize_for_size off

extern "C" void sys_exit();

// Original: arm9/main @ 0x0200F368; symbol: func_0200f368; size: 0xC.
extern "C" void Runtime_InvokeConsoleExitHook()
{
    sys_exit();
}
// Original: arm9/main @ 0x0200F374; symbol: __clear; size: 0x24.
extern "C" void* __clear(void* destination, unsigned int count)
{
    char* cursor = (char*)destination;
    if (!cursor || !count)
        return destination;
    do {
        *cursor++ = 0;
    } while (--count);
    return destination;
}
