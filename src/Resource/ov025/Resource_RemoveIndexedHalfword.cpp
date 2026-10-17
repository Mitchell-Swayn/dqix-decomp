#include <globaldefs.h>
ARM

// Original: arm9/ov025 @ 0x021EB084; symbol: func_ov025_021eb084; size: 0x70.
extern "C" void Resource_RemoveIndexedHalfword(void *state, int key) {
    unsigned char *base = (unsigned char *)state;
    if (key < 0 || base[0x582] == 0) {
        return;
    }
    int found = 0;
    int output = 0;
    for (int i = 0; i < base[0x582]; i++) {
        unsigned short value = *(unsigned short *)(base + 0x584 + i * 2);
        if (key == value) {
            found = 1;
        } else {
            *(unsigned short *)(base + 0x584 + output * 2) = value;
            output++;
        }
    }
    if (found) {
        base[0x582]--;
    }
}
