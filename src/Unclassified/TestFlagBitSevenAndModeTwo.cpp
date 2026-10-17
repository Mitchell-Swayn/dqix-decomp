#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[24];unsigned int flags;char pad2[6];unsigned short pad3:9;unsigned short mode:3;};
// Original: arm9/main @ 0x020886F8; symbol: func_020886f8; size: 0x2C.
int TestFlagBitSevenAndModeTwo(A *p){if((p->flags&128)&&p->mode==2)return 1;return 0;}
}
