#include <globaldefs.h>
ARM
struct Flags { unsigned char padding[0x5ccc]; unsigned int active:1; unsigned int rest:31; };
// Original: arm9/main @ 0x02011544; symbol: func_02011544; size: 0x18.
 extern "C" void WriteActive(Flags* p) { p->active=1; }
