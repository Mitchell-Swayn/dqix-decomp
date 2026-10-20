#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" ARM unsigned int Network_GetWirelessWorkspace(void);
// Original: arm9/ov031 @ 0x0220EB30; symbol: func_ov031_0220eb30; size: 0x58.
extern "C" unsigned int System_ReadOverlayValueWithIRQsDisabled(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    unsigned int shared = Network_GetWirelessWorkspace();
    unsigned int result = 0;
    if (shared == 0) {
        _Z20SetIRQInterruptStatei(irqState);
        return 0;
    }
    char *state = (char *)shared + 0x2000;
    unsigned int *value = *(unsigned int **)(state + 0x270);
    if (value != 0 && *(unsigned int *)(state + 0x274) > 0xC) result = *value;
    _Z20SetIRQInterruptStatei(irqState);
    return result;
}
