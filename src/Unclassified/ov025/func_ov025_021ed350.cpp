#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED350; symbol: func_ov025_021ed350; size: 0xC.
extern "C" void func_ov025_021ed350(void *arg0, int arg1, unsigned short arg2) {
    *(unsigned short *)((char *)arg0 + arg1 * 2 + 0x80) = arg2;
}
