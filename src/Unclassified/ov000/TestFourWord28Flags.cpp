#include <globaldefs.h>
ARM
extern "C" {
}
static inline int HasFlag(unsigned f,unsigned m) {
    return (f&m)!=0;
}
// Original: arm9/ov000 @ 0x021719F8; symbol: func_ov000_021719f8; size: 0x68.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int TestFourWord28Flags(char* p) {
    unsigned f=*(unsigned*)(p+0x28);
    bool b=false;
    b |= HasFlag(f,1);
    b |= (f&16)!=0;
    b |= (f&0x80000)!=0;
    b |= (f&8)!=0;
    return b;
}
