#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateTouchSelectionFromThreeButtonGroups(void);
extern "C" void Graphics_ConfirmTouchedEffectChoice(void);
extern "C" void Input_UpdateHeldRectangleSelectionAndRepeat(void);
extern "C" void Graphics_HandleEffectSelectionAndCancelInput(void);
// Original: arm9/ov031 @ 0x02225F14; symbol: func_ov031_02225f14; size: 0x18.
extern "C" void InitializeOverlayInputHandlers(void*,void*) {
    Graphics_UpdateTouchSelectionFromThreeButtonGroups();
    Graphics_ConfirmTouchedEffectChoice();
    Input_UpdateHeldRectangleSelectionAndRepeat();
    Graphics_HandleEffectSelectionAndCancelInput();
}
