#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x021599DC; symbol: func_ov001_021599dc; size: 0x24.
extern "C" int Unclassified_AdvanceIndexAndWrapAtLimit(void *limits, void *state) {
    int current = *(int *)((unsigned char *)state + 0x50);
    int limit = *(int *)((unsigned char *)limits + 0x10);
    if (current >= limit) {
        *(int *)((unsigned char *)state + 0x50) = 0;
        return 0;
    }
    *(int *)((unsigned char *)state + 0x50) = current + 1;
    return 1;
}
