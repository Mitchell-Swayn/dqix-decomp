#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
// Original: arm9/ov004 @ 0x02168AD4; symbol: func_ov004_02168ad4; size: 0x34.
extern "C" void *Ov004_FindObjectWithFieldEleven(void *state, unsigned int type) {
    void *object = func_ov023_021f6880(func_ov011_021849c8(state), type);
    if (object != 0 && OV023_ReadHalfwordField04(object) == 0x0b) {
        return object;
    }
    return 0;
}
