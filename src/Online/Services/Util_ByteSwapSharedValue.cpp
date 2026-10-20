#include <globaldefs.h>
ARM
extern "C" unsigned System_WaitForOrRegisterSharedContext(void);
// Original: arm9/ov031 @ 0x02207500; symbol: func_ov031_02207500; size: 0x38.
extern "C" unsigned Util_ByteSwapSharedValue(void) {
    unsigned value = System_WaitForOrRegisterSharedContext();
    unsigned a = (value >> 24) & 0xff;
    unsigned b = (value >> 8) & 0xff00;
    unsigned c = (value << 8) & 0xff0000;
    unsigned d = (value << 24) & 0xff000000;
    return ((a | b) | c) | d;
}
