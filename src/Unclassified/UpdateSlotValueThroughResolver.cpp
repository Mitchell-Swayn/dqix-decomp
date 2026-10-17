#include <globaldefs.h>
struct Slot {unsigned first, value;};
extern "C" unsigned ResolveOffsetAgainstBaseOrFallback(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DFBDC; symbol: func_020dfbdc; size: 0x20.
extern "C" int UpdateSlotValueThroughResolver(unsigned a,Slot* p) {p->value=ResolveOffsetAgainstBaseOrFallback(a,p->value,0);return 1;}
