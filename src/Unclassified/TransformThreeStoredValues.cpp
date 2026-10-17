#include <globaldefs.h>
extern "C" {
unsigned int ResolveRelativeBufferOffsetOrFallback(unsigned int, unsigned int, unsigned int);
// Original: arm9/main @ 0x0206EF48; symbol: func_0206ef48; size: 0x4C.
ARM int TransformThreeStoredValues(unsigned int param_1, unsigned int *param_2, unsigned int param_3, unsigned int param_4) {
    *param_2 = ResolveRelativeBufferOffsetOrFallback(param_1, *param_2, 0);
    param_2[5] = ResolveRelativeBufferOffsetOrFallback(param_1, param_2[5], 0);
    param_2[1] = ResolveRelativeBufferOffsetOrFallback(param_1, param_2[1], 0);
    return 1;
}
}
