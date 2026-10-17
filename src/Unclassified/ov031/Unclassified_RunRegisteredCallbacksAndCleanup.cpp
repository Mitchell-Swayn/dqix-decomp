#include <globaldefs.h>
ARM

extern "C" void Unclassified_InvokeAndClearPendingCallbacks(void);
extern "C" void func_ov031_0223fa08(void);
extern "C" void func_ov031_0223fa5c(void);
extern "C" unsigned char data_ov031_02290da0[];

// Original: arm9/ov031 @ 0x0223E868; symbol: func_ov031_0223e868; size: 0x44.
extern "C" void Unclassified_RunRegisteredCallbacksAndCleanup(void) {
    Unclassified_InvokeAndClearPendingCallbacks();
    func_ov031_0223fa08();
    func_ov031_0223fa5c();
    ((void (*)(void *))(*(void **)(data_ov031_02290da0 + 0x20)))(*(void **)(data_ov031_02290da0 + 8));
    ((void (*)(void *))(*(void **)(data_ov031_02290da0 + 0x20)))(*(void **)(data_ov031_02290da0 + 0x10));
    ((void (*)(void))(*(void **)data_ov031_02290da0))();
}
