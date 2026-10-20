#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D468C; symbol: func_020d468c; size: 0x1C.
void System_ClearSharedHalfword96BitZero(){unsigned short v=*(volatile unsigned short *)0x027fff96;if(v&1)*(volatile unsigned short *)0x027fff96=v&~1;}
}
