#include <globaldefs.h>
ARM
extern "C" void func_ov014_02186dc8(void *);
// Original: arm9/ov017 @ 0x021C0550; symbol: func_ov017_021c0550; size: 0x18.
extern "C" void func_ov017_021c0550(void *p) {
    void *owner = *(void **)((unsigned char *)p + 0x20);
    if (owner) func_ov014_02186dc8(owner);
}
