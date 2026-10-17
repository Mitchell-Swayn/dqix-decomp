#include <globaldefs.h>
ARM
extern "C" unsigned int Overlay_CopyIndexedEntryValueIfPresent(unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02181F60; symbol: func_ov000_02181f60; size: 0x14.
extern "C" unsigned int func_ov000_02181f60(unsigned int unused0, unsigned int unused1, unsigned int value) {
    return Overlay_CopyIndexedEntryValueIfPresent(1, value);
}
