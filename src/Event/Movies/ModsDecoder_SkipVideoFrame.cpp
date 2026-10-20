#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned AdvanceBoundedCounters(void *);
// Original: arm9/ov016 @ 0x0218E72C; symbol: Object_IsValidByPredicate; size: 0x24.
// Returns false for null; otherwise returns whether the object predicate returns exactly 1.
extern "C" unsigned ModsDecoder_SkipVideoFrame(void *p) {
    if (p == 0)
        return 0;
    return AdvanceBoundedCounters(p) == 1;
}
