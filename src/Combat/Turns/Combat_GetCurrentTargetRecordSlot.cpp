#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov000 @ 0x0215E938; symbol: func_ov000_0215e938; size: 0x20.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" char* Combat_GetCurrentTargetRecordSlot(char* p) {
    unsigned i=(unsigned char)p[0x8e01];
    if(i>=136)return 0;
    return p+0xec0+i*36;
}
