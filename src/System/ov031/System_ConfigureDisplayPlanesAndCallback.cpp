#include <globaldefs.h>
ARM

extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02227d20(void);

// Original: arm9/ov031 @ 0x02227CE4; symbol: func_ov031_02227ce4; size: 0x3C.
extern "C" void System_ConfigureDisplayPlanesAndCallback(void) {
    func_ov031_0223c078(3, 1, 0x3F, 0x14);
    func_ov031_0223c078(3, 0, 0x3F, 0x14);
    SetMainLoopCallback(func_ov031_02227d20);
}
