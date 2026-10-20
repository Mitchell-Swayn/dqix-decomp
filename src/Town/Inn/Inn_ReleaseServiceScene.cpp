#include <globaldefs.h>
ARM
extern "C" void Graphics_ReleaseSelectionResourcesAndClearMainBG(void *);
// Original: arm9/ov003 @ 0x0217F260; symbol: Overlay_ReleaseObjectResourcesAndSetFlagByteOne; size: 0x18.
// Calls the object resource-release routine, then sets byte +1 to one.
extern "C" void Inn_ReleaseServiceScene(unsigned char *p) {
    Graphics_ReleaseSelectionResourcesAndClearMainBG(p);
    p[1] = 1;
}
