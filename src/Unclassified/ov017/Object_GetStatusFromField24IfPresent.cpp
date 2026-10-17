#include <globaldefs.h>
ARM
extern "C" int func_ov031_02245710(void *);
// Original: arm9/ov017 @ 0x021B2074; symbol: func_ov017_021b2074; size: 0x1C.
extern "C" int Object_GetStatusFromField24IfPresent(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x24);
    if (!value)
        return 0;
    return func_ov031_02245710(value);
}
