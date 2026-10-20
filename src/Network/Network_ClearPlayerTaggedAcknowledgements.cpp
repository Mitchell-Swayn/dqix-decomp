#include <globaldefs.h>
#pragma optimization_level 1
#pragma optimize_for_size off
struct Flags { unsigned char pad[5], a,b,tail; };
// Original: arm9/main @ 0x020E3B08; symbol: func_020e3b08; size: 0x3C.
extern "C" void Network_ClearPlayerTaggedAcknowledgements(Flags* p, int bit) { unsigned mask=1u;int i=0;mask<<=bit;mask=~mask; for(;i<4;p++) { unsigned char a=p->a; i++;p->a=a&mask;p->b&=mask; } }
