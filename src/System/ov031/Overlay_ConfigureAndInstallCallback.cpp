#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallAlternateCallbackIfScreenZeroContextByteIsClear(void);
// Original: arm9/ov031 @ 0x02233C94; symbol: func_ov031_02233c94; size: 0x28.
extern "C" void Overlay_ConfigureAndInstallCallback(void) {
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(System_InstallAlternateCallbackIfScreenZeroContextByteIsClear);
}
