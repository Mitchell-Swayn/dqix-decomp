#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F7128; symbol: Unclassified_GetWordAtOffset1C; size: 0x8.
// Returns the word stored at object offset 0x1c.
extern "C" unsigned MenuZoneRenderRecord_GetLoadState(const void* object) {
    return *(const unsigned*)((const unsigned char*)object + 0x1c);
}
