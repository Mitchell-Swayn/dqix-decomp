#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov001 @ 0x0215AD2C; symbol: func_ov001_0215ad2c; size: 0x10.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int Script_ResolveEventObjectIndex(int i) {
    if(i<0) {
        i=-i;
        i+=159;
    }
    return i;
}
