#include <globaldefs.h>
extern "C" int _Z20DisableIRQInterruptsv();
extern int SetIRQInterruptState(int);
extern "C" unsigned int Network_GetWirelessWorkspace();
// Original: arm9/ov031 @ 0x0220EB88; symbol: func_ov031_0220eb88; size: 0x7C.
extern "C" int Overlay_SetSharedFlag(int enable) {
    int irq = _Z20DisableIRQInterruptsv();
    unsigned int shared = Network_GetWirelessWorkspace();
    if (shared == 0) {
        SetIRQInterruptState(irq);
        return 0;
    }
    int previous;
    if (enable != 0) {
        previous = *(unsigned char*)(shared + 0x2000 + 0x26a) != 0;
        *(unsigned char*)(shared + 0x2000 + 0x26a) = 1;
    } else {
        previous = *(unsigned char*)(shared + 0x2000 + 0x26a) != 0;
        *(unsigned char*)(shared + 0x2000 + 0x26a) = 0;
    }
    SetIRQInterruptState(irq);
    return previous;
}
