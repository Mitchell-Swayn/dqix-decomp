#include <globaldefs.h>
ARM
extern "C" void func_ov017_021c1a24(void *);
// Original: arm9/ov017 @ 0x021C1A10; symbol: func_ov017_021c1a10; size: 0x14.
extern "C" void SetByteOneThenCall021C1A24(void *object) {
    *((unsigned char *)object + 1) = 1;
    func_ov017_021c1a24(object);
}
