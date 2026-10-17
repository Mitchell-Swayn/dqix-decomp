#include <globaldefs.h>
ARM

extern "C" void * volatile data_ov031_0224e580;
extern "C" void StoreValueAtIndirectOffsetA0C(int value);

// Original: arm9/ov031 @ 0x0220FED8; symbol: func_ov031_0220fed8; size: 0x40.
extern "C" void Unclassified_ResetStateAndSetFlags(void) {
    void *state = data_ov031_0224e580;
    if (state == 0) {
        return;
    }
    StoreValueAtIndirectOffsetA0C(0);
    *(unsigned int *)((char *)data_ov031_0224e580 + 0x28) = 0;
    *(unsigned int *)((char *)data_ov031_0224e580 + 0x2c) = 1;
}
