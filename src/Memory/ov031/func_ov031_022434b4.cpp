#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" unsigned char data_ov031_02291e3c[];
// Original: arm9/ov031 @ 0x022434B4; symbol: func_ov031_022434b4; size: 0x34.
extern "C" char *func_ov031_022434b4(void *ignored, unsigned size) {
    int irqState = _Z20DisableIRQInterruptsv();
    char *result = _ZN13SafeAllocator8AllocateEj((unsigned)data_ov031_02291e3c, size);
    _Z20SetIRQInterruptStatei(irqState);
    return result;
}
