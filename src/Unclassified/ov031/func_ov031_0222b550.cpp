#include <globaldefs.h>
ARM
extern "C" void Ov031_AdvanceCallbackDelay(void);
extern "C" void func_ov031_0222b560(void);

// Original: arm9/ov031 @ 0x0222B550; symbol: func_ov031_0222b550; size: 0x10.
extern "C" void func_ov031_0222b550(void) {
    Ov031_AdvanceCallbackDelay();
    func_ov031_0222b560();
}
