#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0206EF94; symbol: func_0206ef94; size: 0x30.
extern "C" unsigned char *ResolveRelativeBufferOffsetOrFallback(unsigned char *p, unsigned char *input, unsigned char *fallback) {
    bool useFallback = true;
    int offset = input - (unsigned char *)0;
    if (offset != -1 && *(unsigned char **)(p + 8) != 0) useFallback = false;
    if (!useFallback) fallback = *(unsigned char **)(p + 8) + offset;
    return fallback;
}
