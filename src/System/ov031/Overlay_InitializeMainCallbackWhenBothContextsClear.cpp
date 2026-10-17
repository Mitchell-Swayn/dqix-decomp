#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void ClearDisplayPlaneMask(unsigned, unsigned);
extern "C" void SetSharedWords10And14(unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void Ov031_InitializeSecondaryTransition(void);
// Original: arm9/ov031 @ 0x022310C4; symbol: func_ov031_022310c4; size: 0x5C.
extern "C" void Overlay_InitializeMainCallbackWhenBothContextsClear(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x14);
    SetSharedWords10And14(2, 1);
    SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
}
