#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByte18AndRegisterConditionalLayerCallback(void);
// Original: arm9/ov031 @ 0x02231968; symbol: func_ov031_02231968; size: 0x20.
extern "C" void System_InstallConditionalLayerCallbackWhenObjectAbsent(void) {
    if (!WfcUtility_IsDialogActive()) WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterConditionalLayerCallback);
}
