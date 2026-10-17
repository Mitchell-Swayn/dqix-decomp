#include <globaldefs.h>
ARM
extern "C" {
}
// Original: arm9/ov000 @ 0x02153A8C; symbol: func_ov000_02153a8c; size: 0x18.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" int TestNestedRecordFlag200(char* p) {
    return (*(unsigned*)(*(char**)(p+0x138)+0x18)&0x200)!=0;
}
