#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov017 @ 0x021D6148; symbol: func_ov017_021d6148; size: 0x14.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" void Script_WriteFloatReferenceOutput(unsigned* p,unsigned v) {
    if(p[0]==3)((unsigned*)p[1])[1]=v;
}
