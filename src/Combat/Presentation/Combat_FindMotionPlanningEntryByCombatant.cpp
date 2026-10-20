#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E1010; symbol: func_ov025_021e1010; size: 0x38.
extern "C" void *Combat_FindMotionPlanningEntryByCombatant(void *records, int count, unsigned char value) {
    for (int i = 0; i < count; ++i) {
        if (*((unsigned char *)records + i * 12) == value) {
            return (unsigned char *)records + i * 12;
        }
    }
    return 0;
}
