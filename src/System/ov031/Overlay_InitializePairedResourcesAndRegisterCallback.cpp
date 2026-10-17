#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02228b78(void);
// Original: arm9/ov031 @ 0x02228B2C; symbol: func_ov031_02228b2c; size: 0x4C.
extern "C" void Overlay_InitializePairedResourcesAndRegisterCallback(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    func_ov031_0223c078(3, 1, 0x3f, 0x40);
    func_ov031_0223c078(3, 0, 0x3f, 0x40);
    SetMainLoopCallback(func_ov031_02228b78);
}
