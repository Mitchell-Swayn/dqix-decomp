#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[52];unsigned int value:24;unsigned int rest:8;};
// Original: arm9/main @ 0x020A0780; symbol: func_020a0780; size: 0x30.
void Statistics_AddEscapeAttemptCount(A *p,unsigned int v){v+=p->value;if(v>0xffffff)v=0xffffff;p->value=v;}
}
