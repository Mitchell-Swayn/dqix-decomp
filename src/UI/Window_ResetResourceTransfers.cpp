#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void Graphics_TransferScreenBuffer(void* entry, int mode);
// Original: arm9/main @ 0x0205D2BC; symbol: func_0205d2bc; size: 0x48.
extern "C" void Window_ResetResourceTransfers(unsigned char* state)
{
    if (*reinterpret_cast<void**>(state + 0x98) == 0) return;
    unsigned int index = 0;
    while (index < state[0xb2]) {
        void* records = *reinterpret_cast<void**>(state + 0x98);
        Graphics_TransferScreenBuffer(static_cast<unsigned char*>(records) + index * 0x20, 0);
        index = (index + 1) & 0xff;
    }
}
