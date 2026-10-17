#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[24];unsigned int flags;char pad2[6];unsigned short pad3:9;unsigned short mode:3;};
// Original: arm9/main @ 0x020887D0; symbol: func_020887d0; size: 0x2C.
int TestFlagBitSevenAndModeFive(A *p){if((p->flags&128)&&p->mode==5)return 1;return 0;}
}
