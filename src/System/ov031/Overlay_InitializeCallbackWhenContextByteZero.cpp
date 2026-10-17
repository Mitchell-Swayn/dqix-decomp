#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void ClearDisplayPlaneMask(unsigned, unsigned);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02233a00(void);
// Original: arm9/ov031 @ 0x022342D8; symbol: func_ov031_022342d8; size: 0x3C.
extern "C" void Overlay_InitializeCallbackWhenContextByteZero(void) {
    if (ReadSelectedContextByte9(0) != 0) return;
    ClearDisplayPlaneMask(0, 0x14);
    SetSharedWords10And14(0, 1);
    SetMainLoopCallback(func_ov031_02233a00);
}
