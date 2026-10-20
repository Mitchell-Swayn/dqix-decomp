#include <globaldefs.h>
ARM
extern "C" void ZoneContainerRenderPart_DrawFrameWithObjectTransform(void *, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021F7134; symbol: Object_ApplySubobjectOperationWhenFlagBit3Clear; size: 0x24.
// Applies the two-argument operation to the subobject at +0x20 when flag bit 3 is clear.
extern "C" void MenuZoneRenderRecord_DrawIfVisible(void *object) {
    if ((*((unsigned char *)object + 0x0c) & 8) == 0)
        ZoneContainerRenderPart_DrawFrameWithObjectTransform((char *)object + 0x20, 0, 1);
}
