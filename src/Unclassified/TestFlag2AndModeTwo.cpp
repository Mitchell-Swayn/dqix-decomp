#include <globaldefs.h>
extern "C" {
struct A{char pad[0x14];unsigned int flags;char pad2[10];unsigned short mode:2;};
// Original: arm9/main @ 0x02088514; symbol: func_02088514; size: 0x2C.
int TestFlag2AndModeTwo(A *p){if((p->flags&2)&&p->mode==2)return 1;return 0;}
}
