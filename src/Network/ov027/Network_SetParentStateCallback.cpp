#include <globaldefs.h>
ARM
extern unsigned char *data_ov027_021e33ec;
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov027 @ 0x021D8A40; symbol: func_ov027_021d8a40; size: 0x28.
extern "C" void Network_SetParentStateCallback(void *callback) {
    int irqState = _Z20DisableIRQInterruptsv();
    unsigned char *communication = data_ov027_021e33ec;
    *(void **)(communication + 0x14e4) = callback;
    _Z20SetIRQInterruptStatei(irqState);
}
