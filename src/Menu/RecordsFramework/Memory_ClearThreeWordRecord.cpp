#include <globaldefs.h>
ARM
extern "C" void __clear(void *, unsigned int);
struct ThreeWords { unsigned int word[3]; };
// Original: arm9/ov023 @ 0x021F735C; symbol: func_ov023_021f735c; size: 0x2C.
extern "C" void Memory_ClearThreeWordRecord(ThreeWords *out) {
    ThreeWords value;
    __clear(&value, 0xc);
    *out = value;
}
