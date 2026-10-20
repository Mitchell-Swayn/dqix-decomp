#include <globaldefs.h>
struct Interpolation{int start,end,current,duration;};
#pragma optimization_level 4
// Original: arm9/main @ 0x020C022C; symbol: func_020c022c; size: 0x34.
extern "C" ARM int Timer_InterpolateIntegerValue(Interpolation* p){if(p->current>=p->duration)return p->end;int start=p->start;return start+p->current*(p->end-start)/p->duration;}
