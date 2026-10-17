#include <globaldefs.h>
ARM
struct Bits { unsigned int count:12; unsigned int rest:20; };
// Original: arm9/main @ 0x02079B94; symbol: func_02079b94; size: 0x18.
 extern "C" unsigned int ComputeCountTimes3C(Bits* p) { return p->count*0x3c; }
