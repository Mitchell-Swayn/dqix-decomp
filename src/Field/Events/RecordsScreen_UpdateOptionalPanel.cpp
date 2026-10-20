#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateOverlay8PanelAndReleaseResources(signed char *object);
// Original: arm9/ov017 @ 0x021C11F0; symbol: func_ov017_021c11f0; size: 0x18.
extern "C" void RecordsScreen_UpdateOptionalPanel(void *owner) {
    signed char *object = *(signed char **)((char *)owner + 0x1c);
    if (object)
        Graphics_UpdateOverlay8PanelAndReleaseResources(object);
}
