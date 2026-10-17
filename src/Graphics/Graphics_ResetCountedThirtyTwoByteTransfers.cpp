#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void Graphics_CleanConfiguredDestinationCache(void* entry, int mode);
// Original: arm9/main @ 0x0205D274; symbol: func_0205d274; size: 0x48.
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char* state)
{
    if (*reinterpret_cast<void**>(state + 0x98) == 0) return;
    unsigned int index = 0;
    while (index < state[0xb2]) {
        void* records = *reinterpret_cast<void**>(state + 0x98);
        Graphics_CleanConfiguredDestinationCache(static_cast<unsigned char*>(records) + index * 0x20, 0);
        index = (index + 1) & 0xff;
    }
}
