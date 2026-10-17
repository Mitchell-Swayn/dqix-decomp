#include <globaldefs.h>
ARM

extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void *);

// Original: arm9/ov004 @ 0x02153944; symbol: func_ov004_02153944; size: 0x34.
extern "C" void *HasTypeSixAtResolvedHandle(void *state, unsigned index) {
    void *resolvedState = func_ov011_021849c8(state);
    void *object = func_ov023_021f6880(resolvedState, index);
    if (object == 0) return 0;
    if (OV023_ReadHalfwordField04(object) != 6) object = 0;
    return object;
}
