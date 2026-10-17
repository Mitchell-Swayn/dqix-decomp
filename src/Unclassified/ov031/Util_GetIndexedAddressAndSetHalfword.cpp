#include <globaldefs.h>
ARM
struct OffsetTable { unsigned int *offsets; char *base; };
// Original: arm9/ov031 @ 0x022276CC; symbol: func_ov031_022276cc; size: 0x2C.
extern "C" char *Util_GetIndexedAddressAndSetHalfword(OffsetTable *table, unsigned index, int position, int value) {
    unsigned short index16 = index;
    char *result = table->base + table->offsets[index16];
    if (position >= 0)
        *(unsigned short *)(result + position * 2) = value + 0x30;
    return result;
}
