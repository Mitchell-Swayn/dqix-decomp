#include <globaldefs.h>
ARM
extern "C" void *GetIndexedEntryPointerOrNull(void *p, int i);
extern "C" void *data_ov025_021ef994;
// Original: arm9/ov000 @ 0x02181990; symbol: func_ov000_02181990; size: 0x38.
extern "C" int Overlay_CopyIndexedEntryValueIfPresent(int index, unsigned *out) {
    void *entry = GetIndexedEntryPointerOrNull(data_ov025_021ef994, index);
    if (!entry) return 0;
    *out = *(unsigned *)entry;
    return 1;
}
