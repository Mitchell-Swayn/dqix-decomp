#include <globaldefs.h>

extern "C" int DispatchTableEntriesByKindAndMode();

// Original: arm9/main @ 0x020BDC80; symbol: func_020bdc80; size: 0x18.
extern "C" ARM bool TestManagerStatusZero() {
    return DispatchTableEntriesByKindAndMode() == 0;
}
