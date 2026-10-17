#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021e33e0[];
// Original: arm9/ov027 @ 0x021DD0AC; symbol: func_ov027_021dd0ac; size: 0x20.
extern "C" int MBi_IsStarted(void) {
    unsigned char *state = *(unsigned char **)(data_ov027_021e33e0 + 8);
    return state[0x50d] == 1;
}
