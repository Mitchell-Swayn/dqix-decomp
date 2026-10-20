#include <globaldefs.h>
ARM
extern "C" void WfcScrollbar_DisableTouchInput(void *);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcSettingsList_BeginExitBrightnessTransition(void);
// Original: arm9/ov031 @ 0x0222F68C; symbol: func_ov031_0222f68c; size: 0x20.
extern "C" void System_SetStateAndCallbackFromMode(void *state) {
    WfcScrollbar_DisableTouchInput(state);
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcSettingsList_BeginExitBrightnessTransition);
}
