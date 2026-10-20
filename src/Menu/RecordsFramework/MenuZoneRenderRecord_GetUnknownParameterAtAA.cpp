#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F71A0; symbol: Unclassified_GetHalfwordAtOffsetAA; size: 0x8.
// Returns the halfword stored at object offset 0xaa.
extern "C" unsigned short MenuZoneRenderRecord_GetUnknownParameterAtAA(const void* object) {
    return *(const unsigned short*)((const unsigned char*)object + 0xaa);
}
