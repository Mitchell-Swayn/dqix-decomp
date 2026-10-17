#include <globaldefs.h>
ARM

extern "C" unsigned char data_ov031_02290c88;
extern "C" void System_ConfigureTwoDisplayModes(void);
extern "C" void SetMainLoopCallback(void (*)(void));

// Original: arm9/ov031 @ 0x0222B610; symbol: func_ov031_0222b610; size: 0x34.
extern "C" void Ov031_AdvanceCallbackDelay(void) {
    unsigned int count = data_ov031_02290c88 + 1;
    data_ov031_02290c88 = count;
    count &= 0xff;
    if (count >= 0x78) {
        SetMainLoopCallback(System_ConfigureTwoDisplayModes);
    }
}
