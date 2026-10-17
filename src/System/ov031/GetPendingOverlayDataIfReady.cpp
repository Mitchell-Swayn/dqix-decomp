#include <globaldefs.h>
ARM
extern "C" unsigned GetOverlaySharedWord(void);
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" void _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov031 @ 0x0220F040; symbol: func_ov031_0220f040; size: 0x44.
extern "C" void *GetPendingOverlayDataIfReady(void) {
    void *result = 0;
    void *shared = (void *)GetOverlaySharedWord();
    int irqState = _Z20DisableIRQInterruptsv();
    if (shared != 0) {
        if (*(unsigned *)((unsigned char *)shared + 0x2260) == 9) {
            if (*(unsigned char *)((unsigned char *)shared + 0x226b) == 0) {
                char *base = (char *)shared + 0x144;
                result = base + 0x2000;
            }
        }
    }
    _Z20SetIRQInterruptStatei(irqState);
    return result;
}
