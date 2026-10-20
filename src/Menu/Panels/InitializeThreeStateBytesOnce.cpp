#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EB414; symbol: func_ov023_021eb414; size: 0x28.
extern "C" void InitializeThreeStateBytesOnce(void *object) {
    unsigned char *bytes = (unsigned char *)object;
    if (bytes[0x44a]) return;
    bytes[0x44a] = 1;
    bytes[0x431] = 2;
    bytes[0x432] = 0;
}
