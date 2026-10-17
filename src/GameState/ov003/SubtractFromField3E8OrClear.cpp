#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215E27C; symbol: func_ov003_0215e27c; size: 0x2C.
extern "C" int SubtractFromField3E8OrClear(void *object, int amount) {
    int *field = (int *)((char *)object + 0x3e8);
    int current = *field;
    if (current <= amount) goto cleared;
    *field = current - amount;
    goto success;
cleared:
    *field = 0;
    return 0;
success:
    return 1;
}
