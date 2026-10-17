#include <globaldefs.h>
ARM
extern "C" void Overlay_InstallCallbackAfterCounterThreshold(void);
extern "C" void func_ov031_0223443c(void);

// Original: arm9/ov031 @ 0x0223442C; symbol: func_ov031_0223442c; size: 0x10.
extern "C" void func_ov031_0223442c(void) {
    Overlay_InstallCallbackAfterCounterThreshold();
    func_ov031_0223443c();
}
