#include <globaldefs.h>
ARM
extern "C" void *data_ov001_02165958[16];
// Original: arm9/ov001 @ 0x0215A818; symbol: func_ov001_0215a818; size: 0x38.
extern "C" void *Util_FindEmptySlotInTable16(unsigned int *index) {
    for (int i = 0; i < 16; i++) {
        if (data_ov001_02165958[i] == 0) {
            *index = i;
            return &data_ov001_02165958[i];
        }
    }
    return 0;
}
