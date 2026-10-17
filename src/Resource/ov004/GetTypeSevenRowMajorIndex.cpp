#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
extern "C" unsigned ComputeRowMajorIndexFromThreeHalfwords(unsigned short *);
// Original: arm9/ov004 @ 0x02156E2C; symbol: func_ov004_02156e2c; size: 0x3C.
extern "C" int GetTypeSevenRowMajorIndex(void *self, unsigned key) {
    void *state = func_ov011_021849c8(self);
    void *entry = func_ov023_021f6880(state, key);
    if (entry == 0) return -1;
    if (OV023_ReadHalfwordField04(entry) == 7)
        return ComputeRowMajorIndexFromThreeHalfwords((unsigned short *)entry);
    return -1;
}
