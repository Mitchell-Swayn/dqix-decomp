#include <globaldefs.h>
ARM

extern "C" void func_ov031_02211864(int, int);
extern "C" void *data_ov031_0224e580;

// Original: arm9/ov031 @ 0x0220FFF8; symbol: func_ov031_0220fff8; size: 0x4C.
extern "C" int Unclassified_EnsureD6RecordState(void *record) {
    if (*(unsigned int *)((char *)record + 8) == 0xd6 &&
        *(unsigned int *)((char *)record + 0xc) != 0) {
        unsigned int value = *(unsigned int *)((char *)record + 0x10);
        if (value == 0) {
            func_ov031_02211864(6, -0x14);
        }
        *(unsigned int *)((char *)data_ov031_0224e580 + 0x30) = value;
    }
    return 1;
}
