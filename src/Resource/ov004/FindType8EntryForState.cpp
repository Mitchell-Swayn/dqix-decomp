#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
// Original: arm9/ov004 @ 0x02168A6C; symbol: func_ov004_02168a6c; size: 0x34.
extern "C" void *FindType8EntryForState(void *self, unsigned key) {
    void *state = func_ov011_021849c8(self);
    void *entry = func_ov023_021f6880(state, key);
    if (entry != 0 && OV023_ReadHalfwordField04(entry) == 8) {
        return entry;
    }
    return 0;
}
