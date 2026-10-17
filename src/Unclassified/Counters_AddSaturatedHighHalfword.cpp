#include <globaldefs.h>
struct Counters { unsigned pad[6]; unsigned low:16; unsigned high:16; };
// Original: arm9/main @ 0x020A0228; symbol: func_020a0228; size: 0x30.
extern "C" void Counters_AddSaturatedHighHalfword(Counters* p,unsigned increment) { unsigned upper=increment+p->high; if(upper>65535)upper=65535; p->high=upper; }
