#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" char *data_ov031_0224e53c;
// Original: arm9/ov031 @ 0x0220CA88; symbol: func_ov031_0220ca88; size: 0x58.
extern "C" int System_ClearSharedPointerWhenWord2260IsOne(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    char *object = data_ov031_0224e53c;
    if (object == 0) {
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    if (*(unsigned int *)(object + 0x2260) != 1) {
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    data_ov031_0224e53c = 0;
    _Z20SetIRQInterruptStatei(irqState);
    return 0;
}
