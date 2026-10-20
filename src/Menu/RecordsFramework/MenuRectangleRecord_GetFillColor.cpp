#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F86F4; symbol: Unclassified_GetByteAtOffset2E; size: 0x8.
// Returns the byte stored at object offset 0x2e.
extern "C" unsigned char MenuRectangleRecord_GetFillColor(const void* object) {
    return *((const unsigned char*)object + 0x2e);
}
