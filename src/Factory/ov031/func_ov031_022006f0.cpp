#include <globaldefs.h>

struct Overlay031CompareState {
    unsigned char unknown00[0x1c];
    unsigned int mask;
    unsigned char unknown20[0x30];
    unsigned int value;
};

extern "C" {
extern Overlay031CompareState data_ov031_0224c980;

ARM int func_ov031_022006f0(unsigned int value) {
    int result = 1;
    if (value != 0xffffffffu && value != 0x7f000001u) {
        if ((value & data_ov031_0224c980.mask) !=
            (data_ov031_0224c980.value & data_ov031_0224c980.mask))
            result = 0;
    }
    return result;
}
}
