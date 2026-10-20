#include <globaldefs.h>
ARM
extern "C" void Overlay_CopyIndexedEntryValueIfPresent(int mode, void *first, void *second);
// Original: arm9/ov000 @ 0x02181F88; symbol: func_ov000_02181f88; size: 0x14.
extern "C" void Combat_CopyIndexedEntryValueIfPresentIndexThree(void *unused0, void *unused1, void *value) {
    Overlay_CopyIndexedEntryValueIfPresent(3, value, value);
}
