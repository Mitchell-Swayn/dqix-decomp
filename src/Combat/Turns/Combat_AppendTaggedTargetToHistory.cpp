#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FF20; symbol: AppendBoundedHalfwordByteEntry; size: 0x30.
// Appends a halfword and byte to parallel arrays while their shared count is below three.
extern "C" void Combat_AppendTaggedTargetToHistory(char* p, unsigned short value, unsigned char tag) {
    if (*(unsigned char*)(p + 0x17) >= 3) return;
    *(unsigned short*)(p + 0x0e + (*(unsigned char*)(p + 0x17) * 2)) = value;
    *(unsigned char*)(p + 0x14 + *(unsigned char*)(p + 0x17)) = tag;
    ++*(unsigned char*)(p + 0x17);
}
