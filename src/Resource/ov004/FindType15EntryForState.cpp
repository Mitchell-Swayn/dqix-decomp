#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void *);
// Original: arm9/ov004 @ 0x02156F38; symbol: func_ov004_02156f38; size: 0x34.
extern "C" void *FindType15EntryForState(void *self, unsigned key) {
    void *state = func_ov011_021849c8(self);
    void *entry = func_ov023_021f6880(state, key);
    if (entry != 0 && OV023_ReadHalfwordField04(entry) == 15) {
        return entry;
    }
    return 0;
}
