#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[20];unsigned int flags;char pad2[10];unsigned short mode:2;};
// Original: arm9/main @ 0x020885E0; symbol: func_020885e0; size: 0x44.
int Object_TestStageFlagsAndModeAllowOperation(A *p){unsigned int f=p->flags;if(f&1)return 0;if(f&0x1000000)return 0;if((f&2)&&p->mode==2)return 0;return 1;}
}
