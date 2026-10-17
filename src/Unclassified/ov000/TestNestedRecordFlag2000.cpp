#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov000 @ 0x02153C0C; symbol: func_ov000_02153c0c; size: 0x18.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int TestNestedRecordFlag2000(char* p) {
    return (*(unsigned*)(*(char**)(p+0x138)+0x18)&0x2000)!=0;
}
