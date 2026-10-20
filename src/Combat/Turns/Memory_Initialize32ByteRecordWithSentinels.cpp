#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov000 @ 0x0215FEF0; symbol: func_ov000_0215fef0; size: 0x30.
extern "C" void Memory_Initialize32ByteRecordWithSentinels(void *p) {
    memset(p, 0, 0x20);
    memset((char *)p + 0xe, -1, 6);
    *(short *)((char *)p + 0xc) = -1;
}
