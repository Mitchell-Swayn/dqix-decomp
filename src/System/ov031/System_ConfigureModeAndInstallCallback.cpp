#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_022298d0(void);
// Original: arm9/ov031 @ 0x022298A8; symbol: func_ov031_022298a8; size: 0x28.
extern "C" void System_ConfigureModeAndInstallCallback(void) {
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(func_ov031_022298d0);
}
