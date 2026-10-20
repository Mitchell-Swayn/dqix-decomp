#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void System_SetSharedByte18AndRegisterPairedResourceCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02228AE4; symbol: func_ov031_02228ae4; size: 0x28.
extern "C" void InitializeAndRegisterCallbackWhenSharedByteZero(void) {
    if (WfcUtility_GetBottomButtonSelection() == 0) {
        WfcUtility_PlaySequenceArchiveEntry(6);
        WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterPairedResourceCallback);
    }
}
