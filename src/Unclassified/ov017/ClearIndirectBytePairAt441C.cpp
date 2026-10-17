#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov017 @ 0x02195748; symbol: func_ov017_02195748; size: 0x18.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" void ClearIndirectBytePairAt441C(char* p) {
    char* q=*(char**)(p+0x441c);
    q[0]=0;
    q[1]=0;
}
