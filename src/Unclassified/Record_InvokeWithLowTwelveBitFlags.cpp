#include <globaldefs.h>
extern "C" void Object_SetWordAndEqualHalfwordPair(int, int, unsigned int, unsigned int*);
// Original: arm9/main @ 0x020E03F0; symbol: func_020e03f0; size: 0x34.
extern "C" int Record_InvokeWithLowTwelveBitFlags(unsigned int* record, int arg, int unused, int final_arg) {
    if (arg == 0) return 0;
    unsigned int flags = (unsigned int)((int)(record[0] << 20)) >> 20;
    Object_SetWordAndEqualHalfwordPair(arg, record[1], flags, record);
    return 1;
}
