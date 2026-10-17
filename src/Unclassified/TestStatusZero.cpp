#include <globaldefs.h>

extern "C" int Object_TestSelectedFloatWithinSixteen();

// Original: arm9/main @ 0x0203B5E0; symbol: func_0203b5e0; size: 0x18.
extern "C" ARM bool TestStatusZero() {
    return Object_TestSelectedFloatWithinSixteen() == 0;
}
