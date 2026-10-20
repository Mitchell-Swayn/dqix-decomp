#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x021685CC; symbol: func_ov003_021685cc; size: 0x10.
extern "C" void Bank_RequestDialogShutdown(void *p) {
    *(unsigned char *)((unsigned char *)p + 0x59f) |= 2;
}
