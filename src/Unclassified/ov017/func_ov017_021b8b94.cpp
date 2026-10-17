#include <globaldefs.h>
ARM
extern "C" unsigned GameState_IsFieldEa8ValueSupported(void *p);
// Original: arm9/ov017 @ 0x021B8B94; symbol: func_ov017_021b8b94; size: 0x1C.
extern "C" unsigned func_ov017_021b8b94(void *object) {
    void *p = *(void **)((char *)object + 0x6ac);
    if (!p)
        return 0;
    return GameState_IsFieldEa8ValueSupported(p);
}
