#include <globaldefs.h>
ARM

extern "C" void func_ov031_02239108(unsigned short);
extern "C" int Network_SetParentStartFlagAndInvokeHandler(void *);
extern "C" int func_ov031_0223883c(void *);
extern "C" void DisableInterruptsAndHaltForever(void);

// Original: arm9/ov031 @ 0x022387F4; symbol: func_ov031_022387f4; size: 0x48.
extern "C" void System_RequireContextReadyOrHalt(void *state, void *context) {
    func_ov031_02239108(2);
    if (Network_SetParentStartFlagAndInvokeHandler(context) != 0) {
        func_ov031_02239108(7);
        return;
    }
    if (func_ov031_0223883c(state) == 0) {
        DisableInterruptsAndHaltForever();
    }
}
