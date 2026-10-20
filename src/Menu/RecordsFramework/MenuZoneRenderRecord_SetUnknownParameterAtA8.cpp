#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F7188; symbol: Unclassified_SetHalfwordAtOffsetA8; size: 0x8.
// Stores the supplied halfword at object offset 0xa8.
extern "C" void MenuZoneRenderRecord_SetUnknownParameterAtA8(void* object, unsigned short value) {
    *(unsigned short*)((unsigned char*)object + 0xa8) = value;
}
