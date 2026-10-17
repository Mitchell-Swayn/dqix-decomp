#include <globaldefs.h>
ARM
extern "C" int func_ov031_02211aec(unsigned int, unsigned int, unsigned int);
extern "C" int func_ov031_0223f528(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02212C84; symbol: func_ov031_02212c84; size: 0x38.
extern "C" int System_ValidateContextAndRunFallback(unsigned int a, unsigned int b, unsigned int c) {
    if (func_ov031_02211aec(a, b, c) != 0) return 0;
    return func_ov031_0223f528(a, b, c, 0);
}
