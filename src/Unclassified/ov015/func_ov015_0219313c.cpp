#include <globaldefs.h>
struct RangeState { char opaque[0x5c]; short origin, count, endpoint; };
// Original: arm9/ov015 @ 0x0219313C; symbol: func_ov015_0219313c; size: 0x14.
extern "C" ARM void func_ov015_0219313c(RangeState* p,int origin,int count){p->origin=origin;p->endpoint=p->origin;p->count=count;}
