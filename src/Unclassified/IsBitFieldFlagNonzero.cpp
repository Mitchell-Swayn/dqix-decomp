#include <globaldefs.h>
ARM
struct Bits { unsigned int padding[2]; unsigned int low:19; unsigned int flag:1; unsigned int high:12; };
// Original: arm9/main @ 0x020DDB20; symbol: func_020ddb20; size: 0x18.
 extern "C" bool IsBitFieldFlagNonzero(Bits* p) { return p->flag!=0; }
