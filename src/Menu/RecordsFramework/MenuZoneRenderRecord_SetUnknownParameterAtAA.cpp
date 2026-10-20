#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F7198; symbol: Unclassified_SetHalfwordAtOffsetAA; size: 0x8.
// Stores the supplied halfword at object offset 0xaa.
extern "C" void MenuZoneRenderRecord_SetUnknownParameterAtAA(void* object, unsigned short value) {
    *(unsigned short*)((unsigned char*)object + 0xaa) = value;
}
