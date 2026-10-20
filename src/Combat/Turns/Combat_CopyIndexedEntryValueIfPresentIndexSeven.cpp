#include <globaldefs.h>
ARM
extern "C" void Overlay_CopyIndexedEntryValueIfPresent(int, int);
// Original: arm9/ov000 @ 0x02181FD8; symbol: func_ov000_02181fd8; size: 0x14.
extern "C" void Combat_CopyIndexedEntryValueIfPresentIndexSeven(int a0, int a1, int a2) {
    Overlay_CopyIndexedEntryValueIfPresent(7, a2);
}
