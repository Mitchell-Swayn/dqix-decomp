#include <globaldefs.h>
ARM
extern unsigned char data_ov004_021707d8[];
struct State;
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215D6F8; symbol: func_ov004_0215d6f8; size: 0x40.
extern "C" int func_ov004_0215d6f8(State *self) {
    void *object = *(void **)(data_ov004_021707d8 + 8);
    if (*((unsigned char *)object + 0x11) == 1) {
        func_ov011_021848a0(self, 0x236A);
    } else {
        func_ov011_021848a0(self, 0x38A);
    }
    return 0;
}
