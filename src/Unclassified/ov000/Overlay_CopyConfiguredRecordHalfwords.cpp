#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0215ED34; symbol: func_ov000_0215ed34; size: 0x58.
extern "C" int Overlay_CopyConfiguredRecordHalfwords(unsigned char* self, unsigned short* output, int count) {
    int i, copied;
    i = copied = 0;
    while (i < (int)(((unsigned int)*(unsigned char*)(self + 0x81b1) << 26) >> 30)) {
        output[copied] = *(unsigned short*)(self + 0x81b4 + i * 0x18);
        ++copied;
        if (copied == count) return copied;
        ++i;
    }
    return copied;
}
