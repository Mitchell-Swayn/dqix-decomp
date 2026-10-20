#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateOverlay8PanelAndReleaseResources(signed char *);
extern "C" void QuestMessagePanel_FinishOptionalOverlayUpdate(void *);

// Original: arm9/ov017 @ 0x021B9904; symbol: func_ov017_021b9904; size: 0x24.
extern "C" void Object_LeaveStateUnchangedAfterOptionalCallback(void *object) {
    signed char *callbackObject = *(signed char **)((unsigned char *)object + 0x118);
    if (callbackObject != 0)
        Graphics_UpdateOverlay8PanelAndReleaseResources(callbackObject);
    QuestMessagePanel_FinishOptionalOverlayUpdate((unsigned char *)object + 0x30);
}
