#include <globaldefs.h>

// Original: arm9/main @ 0x02088018; symbol: func_02088018; size: 0x54.
extern "C" int CombatStatus_CanAdjustShieldBlockStage(int *state, int mode) {
    if ((state[5] & 1) != 0) return 0;
    if (mode == 0) {
        int type = (state[0x58 / 4] << 5) >> 29;
        if (type < 2) return 1;
    } else {
        int type = (state[0x58 / 4] << 5) >> 29;
        if (type > -2) return 1;
    }
    return 0;
}
