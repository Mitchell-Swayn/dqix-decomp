#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E8A40; symbol: func_ov025_021e8a40; size: 0xC.
extern "C" void func_ov025_021e8a40(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 0x10) = arg1;
    *(int *)((char *)arg0 + 0x20) = arg2;
}
