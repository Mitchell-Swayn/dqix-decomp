#include <globaldefs.h>
ARM
extern "C" int func_ov031_02211aec(void *);
extern "C" int func_ov031_0223f1e8(void *);
// Original: arm9/ov031 @ 0x02212C18; symbol: func_ov031_02212c18; size: 0x24.
extern "C" int Unclassified_UseFallbackHelperWhenPrimaryIsZero(void *object) {
    if (func_ov031_02211aec(object) != 0)
        return 0;
    return func_ov031_0223f1e8(object);
}
