#include <globaldefs.h>
ARM
extern "C" void Overlay_CopyIndexedEntryValueIfPresent(int, int);
// Original: arm9/ov000 @ 0x02181F4C; symbol: func_ov000_02181f4c; size: 0x14.
extern "C" void Combat_CopyIndexedEntryValueIfPresentIndexZero(int, int, int third) {
    Overlay_CopyIndexedEntryValueIfPresent(0, third);
}
