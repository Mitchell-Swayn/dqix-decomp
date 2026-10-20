#include <globaldefs.h>
ARM
extern "C" void Overlay_CopyIndexedEntryValueIfPresent(unsigned, unsigned);
// Original: arm9/ov000 @ 0x02181F74; symbol: func_ov000_02181f74; size: 0x14.
extern "C" void Combat_CopyIndexedEntryValueIfPresentIndexTwo(void *, void *, unsigned value) {
    Overlay_CopyIndexedEntryValueIfPresent(2, value);
}
