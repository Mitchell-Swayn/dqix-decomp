#include <globaldefs.h>
ARM

extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void *);

// Original: arm9/ov023 @ 0x021F6524; symbol: func_ov023_021f6524; size: 0x34.
extern "C" void *HasTypeSevenAtResolvedHandle(void *state, unsigned index) {
    void *resolvedState = func_ov011_021849c8(state);
    void *object = func_ov023_021f6880(resolvedState, index);
    if (object == 0) return 0;
    if (OV023_ReadHalfwordField04(object) != 7) object = 0;
    return object;
}
