#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateTouchSelectionFromThreeButtonGroups(void);
extern "C" void func_ov031_02226108(void);
extern "C" void Input_UpdateHeldRectangleSelectionAndRepeat(void);
extern "C" void func_ov031_02226514(void);
// Original: arm9/ov031 @ 0x02225F14; symbol: func_ov031_02225f14; size: 0x18.
extern "C" void InitializeOverlayInputHandlers(void) {
    Graphics_UpdateTouchSelectionFromThreeButtonGroups();
    func_ov031_02226108();
    Input_UpdateHeldRectangleSelectionAndRepeat();
    func_ov031_02226514();
}
