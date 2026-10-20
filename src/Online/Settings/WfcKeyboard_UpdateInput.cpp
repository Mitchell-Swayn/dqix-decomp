#include <globaldefs.h>
ARM
extern "C" void Input_UpdateSelectionFromRectangleGroups(void);
extern "C" void WfcKeyboard_ConfirmTouchInput(void);
extern "C" void System_UpdateActiveInputRegionAndRepeatCounter(void);
extern "C" void WfcKeyboard_HandleButtonInput(void);
// Original: arm9/ov031 @ 0x022242D4; symbol: func_ov031_022242d4; size: 0x18.
extern "C" void WfcKeyboard_UpdateInput(void) {
    Input_UpdateSelectionFromRectangleGroups();
    WfcKeyboard_ConfirmTouchInput();
    System_UpdateActiveInputRegionAndRepeatCounter();
    WfcKeyboard_HandleButtonInput();
}
