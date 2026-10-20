#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" int WfcUtility_IsConnectionContextAbsent(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateTimedMessageWait(void);
// Original: arm9/ov031 @ 0x0222A244; symbol: func_ov031_0222a244; size: 0x30.
extern "C" void Overlay_SetMainLoopCallbackWhenContextByteZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    if (WfcUtility_IsConnectionContextAbsent() == 0)
        return;
    WfcUtility_SetMainLoopCallback(WfcUtility_UpdateTimedMessageWait);
}
