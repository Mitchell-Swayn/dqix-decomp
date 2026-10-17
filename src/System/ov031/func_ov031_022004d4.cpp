#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void *);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
extern "C" unsigned char data_ov031_0224cb28[];
extern "C" unsigned char data_ov031_0224c980[];
// Original: arm9/ov031 @ 0x022004D4; symbol: func_ov031_022004d4; size: 0x50.
extern "C" int func_ov031_022004d4(void) {
    int irq = _Z20DisableIRQInterruptsv();
    int inactive = _Z17IsContextInactiveP16ProcessorContext(data_ov031_0224cb28);
    if (!inactive && *(unsigned int *)(data_ov031_0224c980 + 0x44) == 0) {
        *(unsigned int *)(data_ov031_0224c980 + 0x44) = 1;
        _Z25MarkContextReadyAndSwitchP16ProcessorContext(data_ov031_0224cb28);
    }
    _Z20SetIRQInterruptStatei(irq);
    return inactive;
}
