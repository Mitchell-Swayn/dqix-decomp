#include <globaldefs.h>
ARM
extern "C" void WfcSettingsList_ProcessButtonAndTouchInput(void);
extern "C" void WfcSettingsList_ProcessScrollbarEvents(void);
// Original: arm9/ov031 @ 0x0222EEF8; symbol: System_HandleInputAndAdvanceState; size: 0x10.
// Handles current input and advances the associated event state.
extern "C" void System_HandleInputAndAdvanceState(void) {
    WfcSettingsList_ProcessButtonAndTouchInput();
    WfcSettingsList_ProcessScrollbarEvents();
}
