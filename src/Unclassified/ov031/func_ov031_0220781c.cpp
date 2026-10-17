#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220781C; symbol: func_ov031_0220781c; size: 0x20.
extern "C" void func_ov031_0220781c(unsigned value, unsigned char *out) {
    out[0] = (unsigned char)(value >> 24);
    out[1] = (unsigned char)(value >> 16);
    out[2] = (unsigned char)(value >> 8);
    out[3] = (unsigned char)value;
}
