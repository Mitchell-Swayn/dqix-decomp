#include <globaldefs.h>

extern "C" {
extern unsigned char data_ov031_0224c980[];

ARM int func_ov031_022006f0(unsigned int value) {
    int result = 1;
    if (value != 0xffffffffu && value != 0x7f000001u) {
        unsigned int mask = *(unsigned int *)(data_ov031_0224c980 + 0x1c);
        unsigned int stateValue = *(unsigned int *)(data_ov031_0224c980 + 0x50);
        if ((value & mask) != (stateValue & mask))
            result = 0;
    }
    return result;
}
}
