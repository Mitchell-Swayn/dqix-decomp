#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F7190; symbol: Unclassified_GetHalfwordAtOffsetA8; size: 0x8.
// Returns the halfword stored at object offset 0xa8.
extern "C" unsigned short MenuZoneRenderRecord_GetUnknownParameterAtA8(const void* object) {
    return *(const unsigned short*)((const unsigned char*)object + 0xa8);
}
