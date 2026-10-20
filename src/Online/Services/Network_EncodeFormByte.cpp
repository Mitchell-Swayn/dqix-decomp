#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02242BC4; symbol: func_ov031_02242bc4; size: 0x90.
extern "C" int Network_EncodeFormByte(char *out, int value) {
    switch (value) { case 32: *out = '+'; return 1; default: break; }
    if ((value >= '0' && value <= '9') || (value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')) {
        *out = value;
        return 1;
    }
    int high = (value >> 4) & 15;
    out[0] = '%';
    int upper;
    if (high < 10) upper = high + '0'; else upper = high + 'A' - 10;
    int low = value & 15;
    out[1] = upper;
    if (low < 10) out[2] = low + '0'; else out[2] = low + 'A' - 10;
    return 3;
}
