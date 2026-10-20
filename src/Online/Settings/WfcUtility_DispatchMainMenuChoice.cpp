#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int mode);
extern "C" void Graphics_ConfigureTransformUsingSelectedByte(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureDisplayPlanesAndCallback(void);
extern "C" void System_SetSharedByte18AndRegisterMainLoopCallback022283f8(void);
// Original: arm9/ov031 @ 0x02228388; symbol: func_ov031_02228388; size: 0x50.
extern "C" void WfcUtility_DispatchMainMenuChoice(void) {
    int state = WfcUtility_GetBottomButtonSelection();
    switch (state) {
    case 0:
        WfcUtility_PlaySequenceArchiveEntry(7);
        WfcUtility_SetMainLoopCallback(System_ConfigureDisplayPlanesAndCallback);
        break;
    case 1:
        WfcUtility_PlaySequenceArchiveEntry(6);
        Graphics_ConfigureTransformUsingSelectedByte();
        WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterMainLoopCallback022283f8);
        break;
    }
}
