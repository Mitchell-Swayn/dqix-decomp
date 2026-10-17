#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e230[];
extern "C" void UnlinkNodeFromChain(void *callback, int value);
// Original: arm9/ov031 @ 0x02207168; symbol: func_ov031_02207168; size: 0x18.
extern "C" void System_RegisterPostSleepCallback(int value) {
    UnlinkNodeFromChain(data_ov031_0224e230, value);
}
