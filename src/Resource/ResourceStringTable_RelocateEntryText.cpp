#include <globaldefs.h>
struct Slot {unsigned first, value;};
extern "C" unsigned ResourceStringTable_ResolvePayloadOffset(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DFBDC; symbol: func_020dfbdc; size: 0x20.
extern "C" int ResourceStringTable_RelocateEntryText(unsigned a,Slot* p) {p->value=ResourceStringTable_ResolvePayloadOffset(a,p->value,0);return 1;}
