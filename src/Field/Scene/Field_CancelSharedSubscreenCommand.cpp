#include <globaldefs.h>
ARM
extern "C" void Field_ReleaseSharedSubscreenResources(void *);
// Original: arm9/ov017 @ 0x021A1924; symbol: Overlay_ReleaseObjectResourcesAndSetRecordStateOne; size: 0x18.
// Calls the object resource-release routine, then sets byte +1 to one.
extern "C" void Field_CancelSharedSubscreenCommand(unsigned char *p) {
    Field_ReleaseSharedSubscreenResources(p);
    p[1] = 1;
}
