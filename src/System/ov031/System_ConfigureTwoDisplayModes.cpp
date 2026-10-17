#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void MainLoop_InitializeWhenContextReady();
// Original: arm9/ov031 @ 0x0222B564; symbol: func_ov031_0222b564; size: 0x3C.
extern "C" void System_ConfigureTwoDisplayModes(void) {
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(MainLoop_InitializeWhenContextReady);
}
